#include "saveloadfile.h"

saveLoadFile::saveLoadFile()
{
//empty constructor
}

void saveLoadFile::saveData(QVector<QString> &Current, QString Sampling, QString Period, QString Cycles, QString Amplitude)
{
    // file creation
    QFile file("./myfile.csv");

    //open file to write only
    if(file.open(QFile::WriteOnly | QFile::Truncate))
    {
        //allows to write into file
        QTextStream stream(&file);
        //writes sampling title
        stream<<"Sampling (ms)"<<endl;
        //writes sampling value
        stream<<Sampling<<endl;
        //writes cycles title
        stream<<"Nb_cycles"<<endl;
         //writes cycles value
        stream<<Cycles<<endl;
        //writes Amplitude title
        stream<<"Amplitude"<<endl;
        //writes Amplitude value
        stream<<Amplitude<<endl;
        //writes period title
        stream<<"Period (ms)"<<endl;
        //writes period value
        stream<<Period<<endl;
        //writes current title
        stream<<"Values_Current (mA)"<<endl;

        int i=0;
        //writes the values existing in the currentVal vector from mainwindow class
        while(i < Current.size())
        {
            stream<<Current[i]<<endl;
        i++;
        }

        i=0;
        file.close();
    }
}

void saveLoadFile::loadData(QVector<QString> &Current,QString &Sampling, QString &Period,QString &Cycles, QString &Amplitude)
{
    //takes existing file
    QFile file("./myfile.csv");

    //clear all values just in case
    Current.clear();

    int i=0;

    //check whether I can read file
    if(!file.open(QFile::ReadOnly))
    {
        qDebug()<<file.errorString();
    }

    //reach until end of file
    while(!file.atEnd())
    {
        //read current line
        QString line = file.readLine();
        //removes the extra character \n coming from the reading
        line.remove(QChar('\n'),Qt::CaseInsensitive);
        //to copy every value needed and we jump the titles(i=2,4,6,8)
        if(i==1) {Sampling =line;}
        if(i==3) {Cycles=line;}
        if(i==5) {Amplitude=line;}
        if(i==7) {Period=line;}
        if(i>8)
        {
         Current.append(line); // add every value to my currentVal vector
        }
        i++;
    }
    i=0;
}

//same description as before, only change it is to add the fileName directory
void saveLoadFile::loadData(QString fileName, QVector<QString> &Current,QString &Sampling, QString &Period,QString &Cycles, QString &Amplitude)
{
    QFile file(fileName);

    Current.clear();

    int i=0;

    if(!file.open(QFile::ReadOnly))
    {
        qDebug()<<file.errorString();
    }

    while(!file.atEnd())
    {
        QString line = file.readLine();
        line.remove(QChar('\n'),Qt::CaseInsensitive);
        if(i==1) {Sampling =line;}
        if(i==3) {Cycles=line;}
        if(i==5) {Amplitude=line;}
        if(i==7) {Period=line;}

        if(i>8)
        {
         Current.append(line);
        }

        i++;
    }
    i=0;
}
