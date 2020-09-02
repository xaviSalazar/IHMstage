#ifndef ARDUINOSERIAL_H
#define ARDUINOSERIAL_H

/*!
  * \file arduinoserial.h
  * \brief serial connection arduino
  * \version 1.0
*/

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

/*! \class arduinoSerial
*  \brief arduinoSerial class opens the serial port to communicate with board
*/

class arduinoSerial: public QObject
{
    Q_OBJECT

public:

    /*! \brief Constructor
     * Initialize the arduinoSereial object with a port creation
     * inside this constructor you will find the port creation
      */
    arduinoSerial();

    /*!
     * \brief findBoard
     * \return true or false depending on arduino connections.
     */
    bool findBoard();
    /*!
     * \brief writeToBoard
     * \param pipeta You will need to pass an array of characters to write to Arduino Board
     */
    void writeToBoard(char *pipeta);

    QSerialPort *arduino; /*! <creation of a port Object using Qt creator serial library */

private:


    static const quint16 arduino_uno_vendor_id = 9025; /*! < vendor identifier of arduino product*/

    static const quint16 arduino_UNO =66; /*! <number used by arduino UNO to identify the board.*/

    static const quint16 arduino_MEGA = 67; /*! <number used to identify Arduino MEGA board*/

    QString arduino_puerto; /*! <string to save the name of the port to open*/

    bool arduino_esta_disponible; /*!  <bool variable to save connection state */

public slots:
    /*!
     * \brief receiveFromBoard: function to read serial connection coming from arduino Board
     * \return the serial buffer is saved to a string then it returns it.
     */
    QString receiveFromBoard();

};


#endif // ARDUINOSERIAL_H
