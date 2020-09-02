#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>

/*Initialise QVector of currents*/
QVector <QString> MainWindow::currentVal;
/*end*/

/*Initilise strings to save SAMPLING, CYCLES, AMPLITUDE, PERIOD*/
QString MainWindow::S="";
QString MainWindow::C="";
QString MainWindow::A="";
QString MainWindow::P="";
/*end*/

/*Initialise vector to save axis x and axis y to plot (currents vs Sampling )*/
QVector<double> MainWindow::qv_x ;
QVector<double> MainWindow::qv_y;
/*end*/

/*Initialise vector to save axis real time */
QVector<double> MainWindow::realTimeX;
QVector<double> MainWindow::realTimeY;
/*end*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); /* initial setup constructor */
    ui->cycleLabel->hide(); /* hide cycleLabel*/
    ui->startProgram->setVisible(false); /* button Start hidden at first open of program*/
    lineEditKeyboard = new Keyboard(); /* keyboard creation*/
    serialBuffer=""; /* clear the string to read from input buffer */
    hideButtonsCurrent(); /*hide all current buttons*/
    stateButton=false; /* initialise to false*/
    ui->sendDataButton->hide(); /*hide SEND button*/

    /*Plot init configuration*/
    ui->plot->addGraph();  /* plot class was promoted to the plot Widget inside the main program */
    QPen blueDotPen;  /* creation of an object to control the line of plot*/
    blueDotPen.setColor(QColor(30,40,255,150));  /*selected colot to blue*/
    blueDotPen.setWidthF(1);  /* selected width line to 4 */
    ui->plot->xAxis->setLabel("time [ms]"); /*set label to x-Axis*/
    ui->plot->yAxis->setLabel("Amplitude [mA]"); /*set label to y-Axis*/
    ui->plot->xAxis->setTickLength(5,5); /*set markers x-axis length size*/
    ui->plot->xAxis->setSubTickLength(2,2);/*set submarkers x-axis length size*/
    ui->plot->yAxis->setTickLength(5,5); /*set markers y-axis length size*/
    ui->plot->yAxis->setSubTickLength(2,2); /*set submarkers y-axis length size*/
    ui->plot->xAxis->setRange(0,10); /* set inital range from 0 to 10  x-axis */
    ui->plot->yAxis->setRange(0,10); /* set inital range from 0 to 10  y-axis */
    ui->plot->graph(0)->setPen(blueDotPen); /* creation of a graph with the line paramaeters already selected*/
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssNone); /*for graph 0 to not draw a point in the plot*/
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsStepLeft); /*type the graph lsStepLeft selected, see documentation for other types */
    /*end*/

    /*second graph creation*/
    QPen redDotPen;
    redDotPen.setColor(QColor(255, 0, 0, 127));
    redDotPen.setWidth(4);
    ui->plot->addGraph();
    ui->plot->graph(1)->setPen(redDotPen);
    ui->plot->graph(1)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->plot->graph(1)->setLineStyle(QCPGraph::lsStepLeft);
    /*end*/

    /*Play-Stop button init configuration*/
    ui->playButton->setIcon(QIcon("/home/pi/IHMRaspberrypi/playbutton.jpg")); /* choose an icon for the button from know directory*/
    ui->playButton->setCheckable(true);     /* Activate to save the state of the PLAY/STOP button*/
    ui->playButton->hide();     /*hide button*/
    /*end*/

    /*---------SIGNAL RECEIVE FROM ARDUINO----------------------*/
    connect(Arduino.arduino,SIGNAL(readyRead()),this,SLOT(receive()));
    /*-------------------------------------------------------------------------------------*/

    /*--------------------------Link beetwen when touching a line edit and opening the keyboard-------------*/
    connect(ui->cyclesLine,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->samplingLine,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->amplitudeLine,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->periodLine,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->currentLine,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    /*end----------------------------------------------------------------------------------------------------------------*/

    /*-------------------------Link between entering data and checking a valid value--------------------------------------*/
    connect(ui->samplingLine,SIGNAL(textChanged(const QString &)),this,SLOT(changeLineFont()));
    connect(ui->cyclesLine,SIGNAL(textChanged(const QString &)),this,SLOT(changeLineFont()));
    connect(ui->amplitudeLine,SIGNAL(textChanged(const QString &)),this,SLOT(changeLineFont()));
    connect(ui->periodLine,SIGNAL(textChanged(const QString &)),this,SLOT(changeLineFont()));
    connect(ui->currentLine,SIGNAL(textChanged(const QString &)),this,SLOT(changeLineFont()));
    /*end-----------------------------------------------------------------------------------------------------------------------*/

    /*-------------------------------show the current buttons everytime I click the list view------------------------------------------*/
    connect(ui->listWidget,SIGNAL(itemSelectionChanged()),this,SLOT(clickedListView()));
     /*end----------------------------------------------------------------------------------------------------------------*/

    /*--------------------------initialize with first 0 values in vector --------------------------------------------*/
   // realTimeY.append(0);
   // realTimeX.append(0);
    /*end-----------------------------------------------------------------------------------------------------------------------------------*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


double MainWindow::realTime()
{
    //variable that holds time elapsed after timer is started
    double key = timeToPlot.elapsed();
    //to hold the last time
    static double lastPointKey=0;
    // hold the last time variable if we see a time difference >0.002
    if(key - lastPointKey >0.002)
    {
        lastPointKey = key;
    }
    //return time elapsed
    return key;
}


void MainWindow::changeLineFont()
{
    //QLineEdit creation that will be sent as a signal
    QLineEdit *line = (QLineEdit *) sender();

    //if line is equal to my samplingLine
    if( ui->samplingLine == line)
    {
        //variable to hold as an integer the value of sampling
        int samp = line->text().toInt();
        //only apply if sampling lineEdit is not empty
        if(line->text() != "")
        {
                if( samp > 65500)
                { // if sampling value is greater than 65500 because integer cannot hold a value more than that.
                    line->setStyleSheet("color: blue; background-color: red"); // Turn into red colored box field to warn user
                }
                else
                    {
                    line->setStyleSheet("color: blue; background-color: cyan"); //turn into cyan color is an acceptable value
                    /* 2 fonctions to plot correctly*/
                    createVectorPlot();
                    plot();
                    /*end*/
                    }
        } else { ui->sendDataButton->hide();ui->playButton->hide();line->setStyleSheet("color: blue; background-color: red");} // if box is empty then it gets red colored
    }
    //if line is equal to my cyclesLine
    else if(ui->cyclesLine == line)
    {
        //only apply if cycles lineEdit is empty
        if(line->text() == "")
        {
           ui->sendDataButton->hide();ui->playButton->hide(); //hide buttons that I dont need.
           line->setStyleSheet("color: blue; background-color: red"); //turn into red color to warn user that is empty
        }  else line->setStyleSheet("color: blue; background-color: cyan");  //else cyan color as acceptable
    }

     //if line is equal to amplitude Line
    else if(ui->amplitudeLine ==line)
    {
        //variable to hold amplitude as integer
        int amp =  line->text().toInt();
        //if line is not empty
        if(line->text() != "")
        {
         if( amp >= 0) line->setStyleSheet("color: blue; background-color: cyan"); //turn cyan color that it is acceptable
        } else { ui->sendDataButton->hide();ui->playButton->hide(); line->setStyleSheet("color: blue; background-color: red");} //turn into red color to warn user that is empty
    }
    //if line is equal to period Line
    else if(ui->periodLine ==line)
    {
        //variable to hold period as integer value
        int per =  line->text().toInt();
        //if line is not empty
        if(line->text() != "")
        {
         if( per > 0) line->setStyleSheet("color: blue; background-color: cyan"); // turn cyan color to show that is an acceptable value
        } else { ui->sendDataButton->hide(); ui->playButton->hide();line->setStyleSheet("color: blue; background-color: red");} // else turn red colored box to warn user
    }

    //if line is equal to current Line
    else if(ui->currentLine ==line)
    {
        //variable current to hold it as an integer
        int current =  line->text().toInt();
        //if line is not empty
        if(line->text() != "")
        {
         if( current >= 0 && current <=500) line->setStyleSheet("color: blue; background-color: cyan"); // values between 0 and 500 are accepted so it turns into cyan color
         else {line->setStyleSheet("color: blue; background-color: red");} // any value outside the accetable range will show in red as warning to the user.
        } else{ui->sendDataButton->hide();ui->playButton->hide();line->setStyleSheet("color: blue; background-color: red");} // if box is empty then turn into red to warn user.
    }
}


void MainWindow::plot()
{
    ui->plot->xAxis->setRange(0,10);
    ui->plot->yAxis->setRange(0,10);
    /*
    ui->plot->yAxis->setTickStep(qv_y.last()/10);
    ui->plot->xAxis->setTickStep(qv_x.last()/10);
    */
    ui->plot->graph(0)->setData(qv_x,qv_y);
    ui->plot->graph(0)->rescaleAxes(true);
    ui->plot->graph(1)->setVisible(false);  // to hide my other graph
    ui->plot->replot();
    ui->plot->update();
}

void MainWindow::plot2()
{
    /*
   // ui->plot->xAxis->setRange(0,10);
    ui->plot->yAxis->setRange(0,10);
    ui->plot->graph(0)->setData(realTimeX,realTimeY);
    //ui->plot->xAxis->scaleRange(2,0); ///se cambia el scale cada vez que la llamo
    ui->plot->graph(0)->rescaleAxes(true);
    //ui->plot->xAxis->setRange(realTimeX.last(),S.toDouble()*qv_y.size(),Qt::AlignRight); //line to move the graph from right to left
    ui->plot->replot();
    ui->plot->update();
    */
    /*
    for(int i=0; i < realTimeX.size() ; i++)
    {
    qDebug()<<" llegada "<<realTimeX.at(i)<<" "<<realTimeY.at(i);
    }
*/


    // ui->plot->yAxis->setRange(0,10);
    ui->plot->graph(1)->setData(realTimeX,realTimeY);
   // ui->plot->graph(1)->setData(realTimeX,realTimeY);
   // ui->plot->graph(1)->setData(realTimeX,realTimeY);
    //realTimeX.clear();
    //realTimeY.clear();
    //ui->plot->xAxis->scaleRange(2,0); ///se cambia el scale cada vez que la llamo
    ui->plot->graph(1)->rescaleAxes(true);
    //ui->plot->xAxis->setRange(realTimeX.last(),S.toDouble()*qv_y.size(),Qt::AlignRight); //line to move the graph from right to left
    ui->plot->replot();
    ui->plot->update();

}

void MainWindow::on_searchArduino_clicked()
{

    if(Arduino.findBoard()) // calls to my findBoard() fonction in Arduino class
    {
        ui->welcomeLabel->hide(); // if board is found hides welcome label
        ui->searchArduino->hide(); // if board is found hides the searchArduino button
        ui->label->setText("Arduino connected"); // sets the label
        ui->startProgram->setVisible(true); // shows up button startProgram to change to the next page
    } else
            { ui->label->setText("Arduino not ready try again"); // if board is not connected set label to not ready
              QMessageBox::warning(this, "Message","Wait Arduino to turn on"  ); // creation of a warning message to the user to wait to arduino to turn on.
            }
}


void MainWindow::receive()
{

   QString datoleido = Arduino.receiveFromBoard(); //calls my reading fonction from arduino class and holds it in dato leidot string
   qDebug()<<"dato"<<datoleido;
   createStringSerial(datoleido); // i pass dato leido to my createStringSerial fonction
   datoleido.clear(); /* clear buffer to save serial data */
   if(Arduino.arduino->bytesAvailable()>0) QMetaObject::invokeMethod(this,"receive",Qt::QueuedConnection);// Important to use it always because some data stays in buffer, this will check that everything is passed.
}


void MainWindow::createStringSerial(const QString & dato)
{

serialBuffer += dato; // adds anything passed to a string

    if(serialBuffer.endsWith("\n"))  // only if the content of buffer ends up with newline
    {
        if(serialBuffer.startsWith("cycle")) //if arduino sends the word cycle
        {
        ui->cycleLabel->setText(serialBuffer); // I change the text in my label that counts the cycles
        realTimeX.clear();
        realTimeY.clear();
        realTimeY.append(currentVal[0].toDouble());
        realTimeX.append(0);
         timeToPlot.start();
        serialBuffer.clear();  // clear my string serialBuffer
        } else {
                 double time = realTime(); // I hold the time that passed when this fonction was called.
                 realTimeX.append(time);  // adds to vector axis X
                // qDebug()<<"bufffer"<<serialBuffer<<"time "<<time;
                // double axisY = serialBuffer.toDouble(); //My complete string with newline is transformed into a double because I know that arduino sent me a number
                 realTimeY.append(serialBuffer.toDouble()); // adds to vector axis Y
                 plot2(); // I use my other plotting fonction to plot  real time GRAPH
                serialBuffer.clear(); // clear the serial Buffer
                 }
    }   else {

             }
}

void MainWindow::on_startProgram_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // when button is clicked it changs to the next page
}

void MainWindow::run_keyboard_lineEdit()
{
    if(stateButton==0) //if STOP button is tapped
    {
    ui->sendDataButton->hide();ui->playButton->hide(); /*everytime i open the keypad I hide the play and send button*/
    QLineEdit *line = (QLineEdit *) sender(); // QLineEdit creation to send which line I swiped
    if(ui->currentLine == line) { showButtonsCurrent();} /*if i press on the currentLine text edit I will show the buttons*/
    lineEditKeyboard->setLineEdit(line); // call to my keyboard class and sets that we are working with this swiped line
    QRect r=lineEditKeyboard->geometry(); // takes the dimensions of my keyboard widget
    r.moveTopRight(QApplication::desktop()->availableGeometry().topRight()); //Object fonction to show the keyboard always to the top right of the screen
    lineEditKeyboard->setGeometry(r); //sets the geometry to my widget
    lineEditKeyboard->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup); // fonction to let close the keyboard when touching outside of it
    lineEditKeyboard->show(); // I call my keyboard to show up
    }
    else {  QMessageBox::warning(this, "Important Message ","Press STOP to add any vale"  );} // warn user to press STOP button before any change in values
}


void MainWindow::clickedListView()
{
    if(stateButton==0) // if STOP button was already pressed
    {
    ui->sendDataButton->hide(); // we hide the SEND button
    ui->playButton->hide();     //we hide the PLAY button
    showButtonsCurrent();      // as we pressed in the list we need to show the buttons to replace, add, clear currents
    } else {}
}

void MainWindow::createVectorPlot()
{
    /*erase all initial values*/
    qv_y.clear();
    qv_x.clear();
    /*end*/

    int i=0; // variable needed to make a while loop

    double sample = ui->samplingLine->text().toDouble(); // transform my samplingLine into a double variable

    //here we are going to copy every element from the currentVal (string) vector to a (double) vector
    //also we are going to create a time scale dependint of the sampling value, already saved as double
    if(currentVal.size()>=1) // this fonction only works if we have elements to copy
    {

        while(i < currentVal.size()) // just do it when the last value is reached
        {
            qv_y.append(currentVal[i].toDouble()); //copies every value of current into a double vector
            qv_x.append((i)*sample); // creates a time scale
            i++;
        }

        qv_x.append((qv_y.size())*sample); // we also add last time value to plot correctly
        qv_y.append(qv_y[qv_y.size()-1]); //  we add the current value that will be executed this time added.

        i=0;
    }
    else {}
}

void MainWindow::on_addCurrentButton_clicked()
{
    /*hide buttons because im still adding some data*/
    ui->sendDataButton->hide();
    ui->playButton->hide();
    /*emd*/

    /*string of sampling and one of current*/
   QString var = ui->currentLine->text();
   QString s= ui->samplingLine->text();
   /*end*/

   if(var != "" && s != "")   /*only add currents if there are no empty box fields*/
   {
       ui->currentLabel->setText("   Enter next\n Current (mA): ");
       showButtonsCurrent(); /*show current boutons to delete replace*/
       currentVal.push_back(var); /*pushes every current to the last position*/

       /* 2 fonctions to be called everytime a value is changed*/
       createVectorPlot();
       plot();
       /*end*/

       ui->listWidget->addItem(var); /*add every current to the ListWidgetView*/
   } else {}
}

void MainWindow::on_clearAllPushButton_clicked()
{

     ui->sendDataButton->hide();    /*hide send data button*/
     ui->playButton->hide();        /*hide play Button*/
    currentVal.clear();             /*clear all currents values from vector*/
    clearListWidget();              /*clear the list widget view*/

  /* 2 fonctions to be called everytime a value is changed*/
    createVectorPlot();
    plot();
    /*end*/
}

void MainWindow::on_replacePushButton_clicked()
{
    int fila=ui->listWidget->currentRow(); // variable to save the row index of the QWidget list clicked

    if(fila>=0 && ui->currentLine->text() != "") // replace button only works if a value is selected and the value to replace exists.
    {
        currentVal.replace(fila,ui->currentLine->text());
        clearListWidget();
    } else{}
    /* 2 fonctions to be called everytime a value is changed*/
    createVectorPlot();
    plot();
    /*end*/
}

void MainWindow::on_deletePushButton_clicked()
{
int fila=ui->listWidget->currentRow(); /* save value of selected row in the ListWidgetView*/

/*removes value from row selected*/
if(fila>=0)
  {
   currentVal.remove(fila); // removes the value from the index number
   clearListWidget(); // call my fonction to refresh listwidget
   } else{}
/*end*/


/* 2 fonctions to plot correctly*/
createVectorPlot();
plot();
/*end*/
}

void MainWindow::clearListWidget()
{
    int i =0;
    ui->listWidget->clear(); /*clear all current values from list view widget*/

    /*loop to add every value that exists in current vector just to check that nothing should appear*/
    while(i < currentVal.size())
    {
      ui->listWidget->addItem(currentVal[i]);
      i++;
    } /*end*/
}

void MainWindow::hideButtonsCurrent()
{
    ui->replacePushButton->hide(); // hide replace button
    ui->clearAllPushButton->hide(); // hide clear all button
    ui->deletePushButton->hide(); //hide delete button
    ui->listWidget->hide(); // hide list widget
}

void MainWindow::showButtonsCurrent()
{
    ui->replacePushButton->show(); //show replace button
    ui->clearAllPushButton->show(); // show clear all button
    ui->deletePushButton->show();  // show delete button
    ui->listWidget->show();  // show list widget
    ui->addCurrentButton->show(); // show add button
}



void MainWindow::on_validatePushButton_clicked()
{
    /* pass line to variables when pressed*/
    S=ui->samplingLine->text();
    C=ui->cyclesLine->text();
    P=ui->periodLine->text();
    A=ui->amplitudeLine->text();
    /*end*/

    if((S == "") || (C=="") || (P=="") || (A=="") || (currentVal.size()==0)) // if all values doesnt exist I cannot validate
    {
    ui->warningDataLabel->setText("ENTER ALL DATA");QMessageBox::warning(this, "Attention","ENTER ALL DATA\nTO VALIDATE");
    } else {ui->sendDataButton->show(); ui->replacePushButton->hide();ui->deletePushButton->hide(); ui->warningDataLabel->setText("");} // i can validate and send button shows up
}


void MainWindow::clearWarningDataLabel()
{
    ui->warningDataLabel->setText("");
}


void MainWindow::on_sendDataButton_clicked()
{
    int i=0;
    char samp[100];
    char cycles[100];
    char ampl[100];
    char per[100];
    char curr[100];
    char play[100];

/*Put together each data to send */
    sprintf(samp,"Sampling %d",S.toInt());
    sprintf(cycles,"cycles %d",C.toInt());
    sprintf(per,"Period %d",P.toInt());
    sprintf(ampl,"Ampl %d",A.toInt());
/*end*/

  /* Writing each data to the arduino via serial port*/
    Arduino.writeToBoard(samp);
    usleep(10000);
    Arduino.writeToBoard(cycles);
    usleep(10000);
    Arduino.writeToBoard(ampl);
     usleep(10000);
     Arduino.writeToBoard(per);
     usleep(10000);

/*send every current element*/
     while(i < currentVal.size())
     {
         sprintf(curr,"Dato %d %d",i,currentVal[i].toInt());
         Arduino.writeToBoard(curr);
         i++;
     }
     i=0;
 /*end*/
     /* change machine d'etat*/
      /*-------------------------------------------------------------------------------------*/
     sprintf(play,"Play %d",1);
     Arduino.writeToBoard(play);
      /*-------------------------------------------------------------------------------------*/
     //usleep(100000);
     /*end*/
     /*show play button*/
     ui->playButton->show();
     ui->addCurrentButton->hide();
     ui->replacePushButton->hide();
     ui->deletePushButton->hide();
     ui->clearAllPushButton->hide();
}

void MainWindow::on_playButton_clicked(bool checked)
{
    stateButton=checked;

    if(checked)
    { //ON
        char start[100];
        ui->cycleLabel->show();

        timeToPlot.start();

        realTimeY.clear();
        realTimeX.clear();
        realTimeY.append(currentVal[0].toDouble());
        realTimeX.append(0);

        ui->plot->graph(1)->setVisible(true); // to show my second added graph.
        ui->playButton->setIcon(QIcon("/home/pi/IHMRaspberrypi/stopbutton.jpg"));
        qDebug() <<"Button checked--ON";
        sprintf(start,"Start %d",1);
         /*-------------------------------------------------------------------------------------*/
        Arduino.writeToBoard(start);
         /*-------------------------------------------------------------------------------------*/
    } else {
            ui->playButton->setIcon(QIcon("/home/pi/IHMRaspberrypi/playbutton.jpg"));
            qDebug() <<"Button Checked--OFF";
            char stop[100];
            /*To clean the vector that makes the real plot*/
            realTimeY.clear();
            realTimeX.clear();
            realTimeY.append(currentVal[0].toDouble());
            realTimeX.append(0);
            /*end*/
             /*-------------------------------------------------------------------------------------*/
             sprintf(stop,"Stop %d",1);
             Arduino.writeToBoard(stop);
             /*-------------------------------------------------------------------------------------*/
            }
}


void MainWindow::on_pushButton_clicked()
{
    int r=QMessageBox::warning(this, "Message ","Do you really want to exit",QMessageBox::Yes | QMessageBox::Default, QMessageBox::No | QMessageBox::Escape);
    if(r==QMessageBox::Yes)
    {
        /* To clean the vector that makes the real plot*/
         /*-------------------------------------------------------------------------------------*/
        char stop[100];
        sprintf(stop,"Stop %d",1);
        Arduino.writeToBoard(stop);
         /*-------------------------------------------------------------------------------------*/
        realTimeY.clear();
        realTimeX.clear();
        realTimeY.append(currentVal[0].toDouble());
        realTimeX.append(0);
        /*end*/
       usleep(1000000);
       close();
    } else {}
}


void MainWindow::on_actionload_last_session_triggered()
{
    // when stop button is pressed
    if(stateButton ==0)
    {
    ui->sendDataButton->hide();ui->playButton->hide(); // hides not needed buttons
    Archivo.loadData(currentVal,S,P,C,A);// calls to function loadData in saveloadfile class
    ui->samplingLine->setText(S); //sets the widget line sampling to the value read
    ui->periodLine->setText(P);//sets the widget line period to the value read
    ui->cyclesLine->setText(C);//sets the widget line cycles to the value read
    ui->amplitudeLine->setText(A);//sets the widget line amplitude to the value read
    clearListWidget(); // refreshes the new values into my widget list view
    ui->listWidget->show(); // show widget list
    createVectorPlot(); // create the vector data to plot
    plot(); // plots the data
    }
else {  QMessageBox::warning(this, "Msg","Press STOP before loading"  );} // warn user to press STOP button before any change in values
}

void MainWindow::on_actionsave_session_triggered()
{
  //i can only save when I validate my data
 if(( S == "") || (C =="") || (P =="") || (A =="") || (currentVal.size()==0))
 {
 ui->warningDataLabel->setText("ENTER ALL DATA");QMessageBox::warning(this, "Msg","    VALIDATE\nTO SAVE SESSION");
 } else { Archivo.saveData(currentVal,S,P,C,A);
 QMessageBox::warning(this, "Msg","SAVED SESSION"  );} // i can SAVE THE SESSION

}

void MainWindow::on_actionLoad_from_FILE_triggered()
{
    // when stop button is pressed
    if(stateButton ==0)
    {
        //filters to show only csv files
    QString filter="CSV file (*.csv)";
        //calls a Qdialog to simulate a window directory to choose a file
    QString fileName = QFileDialog::getOpenFileName(this, "open a file",QDir::homePath(),filter);

    ui->sendDataButton->hide();ui->playButton->hide();// hides not needed buttons
    Archivo.loadData(fileName,currentVal,S,P,C,A);// calls to function loadData in saveloadfile class
    ui->samplingLine->setText(S);
    ui->periodLine->setText(P);
    ui->cyclesLine->setText(C);
    ui->amplitudeLine->setText(A);
    clearListWidget();
    ui->listWidget->show();
    createVectorPlot();
    plot();
    }
else {  QMessageBox::warning(this, "Msg","Press STOP before loading"  );} // warn user to press STOP button before any change in values
}
