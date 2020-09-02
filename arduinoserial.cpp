#include "arduinoserial.h"
#include <unistd.h>
arduinoSerial::arduinoSerial()
{
    arduino = new QSerialPort;  //Creates new QSerialPort
}

bool arduinoSerial::findBoard()
{
    //initialize to false
    arduino_esta_disponible = false;
    //initialize to empty
    arduino_puerto = "";
    //creates string to hold number of devices in serial port
    QString nombreDispositivoSerial="";
    // initialize to 0
    int nombreProductoID=0;

    //prints the number available of ports
    qDebug()<<"Available Ports "<<QSerialPortInfo::availablePorts().length();

    //for loop for every port available
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        qDebug()<<"Identificador del fabricante (VENDOR ID): "<<serialPortInfo.hasVendorIdentifier();

        //if we find ports with a vendor identifier we print the numbers.
        if(serialPortInfo.hasVendorIdentifier())
        {
        //print vendor and product
        qDebug()<<"ID Vendor "<<serialPortInfo.vendorIdentifier();
        qDebug()<<"ID Product: "<<serialPortInfo.productIdentifier();

            //identify if we use a Arduino UNO or MEGA board, important to add other board vendors to the .h file if a differente board is used. In this case we only use UNO and MEGA
            if(serialPortInfo.productIdentifier() == arduino_UNO || serialPortInfo.productIdentifier() == arduino_MEGA )
            {//set variable to true
            arduino_esta_disponible=true;
            //save the name of the port
            nombreDispositivoSerial= serialPortInfo.portName();
            //save the product identifier
            nombreProductoID=serialPortInfo.productIdentifier();
            }
        }
    }

     //if arduino is available
    if(arduino_esta_disponible)
    {
        //copy into this variable the name of the port
        arduino_puerto=nombreDispositivoSerial;
        //set the name of port to open that was already saved before
        arduino->setPortName(arduino_puerto);
        //set the port to read and write for our case
        arduino->open(QIODevice::ReadWrite);
        // set 8 bits
        arduino->setDataBits(QSerialPort::Data8);
        // set the baudrate to 115200
        arduino->setBaudRate(QSerialPort::Baud115200);
        // set no parity
        arduino->setParity(QSerialPort::NoParity);
        // set to one stop bit
        arduino->setStopBits(QSerialPort::OneStop);
        // set to not use flow control
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        // print the product name
        qDebug()<<"Producto: "<<nombreProductoID;

        //checks if it is possible to write to arduino IMPORTANT TO USE IT!!!
                 if(arduino->flush())
                 {
                     //return true value it is connected and writtable
                       return true;
                 } else{
                     //is connected but not writtable return false
                     return false;


                 }

    }   else {
        //if arduino is not connected at all return false
            return false;


    }
}

void arduinoSerial::writeToBoard(char *pipeta)
{
    //checks if it is possible to write to arduino IMPORTANT TO USE IT!!!
    if(arduino->flush())
    {
        //writes to arduino board, we send the size + 1 to send also the last \0 character
    arduino->write(pipeta,strlen(pipeta)+1);
    qDebug()<<"envueeee";
     usleep(10000);
    }
    else { qDebug()<<"could not write"; }

}

QString arduinoSerial::receiveFromBoard()
{
    QString data=""; //creation of a String data
    data.clear();   //clear data
    data = arduino->readLine(); //read a line coming from a serial port
     return data; // returns the string data
}


