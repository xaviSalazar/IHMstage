#include "keyboard.h"
#include "ui_keyboard.h"

Keyboard::Keyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keyboard)
{
    //Initial setup for widget obligatory in qt creator
    ui->setupUi(this);

    //Use of connect qt creator fonction in order to identify when a button is pressed
    //In this case when the button is clicked, it will call to the keyboardHandler fonction
    connect(ui->Button0,SIGNAL(clicked()),this,SLOT(keyboardHandler()) );
    connect(ui->Button1,SIGNAL(clicked()),this,SLOT(keyboardHandler()) );
    connect(ui->Button2,SIGNAL(clicked()),this,SLOT(keyboardHandler()) );
    connect(ui->Button3,SIGNAL(clicked()),this,SLOT(keyboardHandler()) );
    connect(ui->Button4,SIGNAL(clicked()),this,SLOT(keyboardHandler()) );
    connect(ui->Button5,SIGNAL(clicked()),this,SLOT(keyboardHandler()) );
    connect(ui->Button6,SIGNAL(clicked()),this,SLOT(keyboardHandler()) );
    connect(ui->Button7,SIGNAL(clicked()),this,SLOT(keyboardHandler()) );
    connect(ui->Button8,SIGNAL(clicked()),this,SLOT(keyboardHandler()) );
    connect(ui->Button9,SIGNAL(clicked()),this,SLOT(keyboardHandler()) );

     //Initialize text to show to empty
     outputText="";

     //to give focus to this widget when opening from a parent widget
    ui->lineEdit->setFocus();
}

void Keyboard::keyboardHandler()
{
    //creation of QPushbutton that will be sent as a signal
    QPushButton *button = (QPushButton *) sender();
    //string to hold progressively the text entered
    QString inputText = button->text();
    //output text finally holds all data entered before progressively
    outputText += inputText;
    //print text to the lineEdit
    ui->lineEdit->setText(outputText);
}

void Keyboard::setLineEdit(QLineEdit * line)
{
    //holds the id of which lineEdit was pressed to call the keypad
    outputLineEdit = line;
    // clears the lineEdit when opening the keypad
    outputText=""; //agregado
    // shows empty because outputText was cleared
    ui->lineEdit->setText(outputText); //agregdo
}

Keyboard::~Keyboard()
{
    //destructor to clean memory
    delete ui;
}

void Keyboard::on_clear_clicked()
{
    // clears the text to be shown to the lineEdit keypad
    outputText="";
    ui->lineEdit->setText(outputText);
}

void Keyboard::on_enterButton_clicked()
{
    // sets the text of the lineEditKeypad widget
    outputLineEdit->setText(outputText);
    // sets the textLineEdit from the other widget that was called
    ui->lineEdit->setText(outputText);
    // closes the keypad widget
    close();
}

void Keyboard::on_lineEdit_textChanged(const QString &arg1)
{
    //save the text changed
    outputText = arg1;
     // shows the text changed to the textLineEdit from the other widget that was called
    outputLineEdit->setText(outputText);
     // show the text changed to the keypad LineEdit
    ui->lineEdit->setText(outputText);
}

void Keyboard::on_lineEdit_returnPressed()
{
    // shows the text changed to the textLineEdit from the other widget that was called
    outputLineEdit->setText(outputText);
    // clear the text
    outputText="";
    // refreshes the text changed to the keypad LineEdit when an enter button is hit
    ui->lineEdit->setText(outputText);
    //close the keypad
    close();
}

void Keyboard::on_backButton_clicked()
{
    // handles the string to edit it, to delete one element not desired
   outputText.remove(outputText.length()-1, outputText.length());
   // everytime called it shows the correction to the lineEdit keypad
   ui->lineEdit->setText(outputText);
}

