#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*!
  * \file mainwindow.h
  * \brief file to manage all widgets, buttons, actions in main program with the  user
  * \version 1.0
*/

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <keyboard.h>
#include <QVector>
#include <QString>
#include <QTime>
#include <QMessageBox>
#include <arduinoserial.h>
#include <saveloadfile.h>
#include <QFileDialog>
#include <QDir>

/*! \namespace ui
 * it groupes all variables to control the widgets
*/
namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class is the main Widget which controls every item in the general view
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow Initialize the object by setting up first time showing the Widget
     * \param parent
     */
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*!
     * \brief clearData
     * Clears all currents values from vectors and QWidgetList
     */
    void clearData();

    /*!
     * \brief plot
     * Fonction to plot the desired current curve
     */
    void plot();
    /*!
     * \brief plot2
     * Fonction to plot the Real Time current send by the MOTOR BANC
     */
    void plot2();

private slots:
    /*!
     * \brief on_searchArduino_clicked
     * Uses arduinoSerial Class to open port and verify if it's opened
     * relies to button searchArduino first page.
     */
    void on_searchArduino_clicked();

    /*!
     * \brief receive
     *  Uses arduinoSerial classe to read data that the Motor Banc it's sending
     * it copies all the string when it reads buffer coming from arduino
     */
    void receive();

    /*!
     * \brief on_startProgram_clicked
     *  When button is clicked it transfers to page number 2. (main page)
     * button name startProgram
     */
    void on_startProgram_clicked();

    /*!
     * \brief run_keyboard_lineEdit
     * Calls to the keyboard class to show the numeric keypad
     */
    void run_keyboard_lineEdit();

    /*!
     * \brief clearWarningDataLabel
     * clear label
     */
    void clearWarningDataLabel();

    /*!
     * \brief on_addCurrentButton_clicked
     * When button is pressed adds values to a vector and a QWidgedList
     */
    void on_addCurrentButton_clicked();

    /*!
     * \brief on_clearAllPushButton_clicked
     * Clears all vectors of current data and QwidgetList
     */
    void on_clearAllPushButton_clicked();

    /*!
     * \brief on_replacePushButton_clicked
     * Identifies item index from QWidgetList
     * Replaces the item into the current vector when pressed
     * Calls plot function to replot with new values
     */
    void on_replacePushButton_clicked();


    /*!
     * \brief on_deletePushButton_clicked
     * Identifies item index from QWidgetList
     * Deletes item from selected index from current values vector
     */
    void on_deletePushButton_clicked();

    /*!
     * \brief on_validatePushButton_clicked
     * Checks that all data is entered
     * If all data is entered then it saves values.
     */
    void on_validatePushButton_clicked();

    /*!
     * \brief on_sendDataButton_clicked
     * All data is written to Arduino Board
     * Uses the arduinoserial class to write to the serial port
     */
    void on_sendDataButton_clicked();

    /*!
     * \brief changeLineFont
     * changes color of labelLines when data is entered
     */
    void changeLineFont();

    /*!
     * \brief on_playButton_clicked
     * START/STOP button to control the program
     * Uses serialarduino class to write to the serial port
     * \param checked
     * Special Qt Slot to save the state of the button when pressed
     */
    void on_playButton_clicked(bool checked);

    /*!
     * \brief on_pushButton_clicked
     * Button implemented to close the program.
     */
    void on_pushButton_clicked();

    /*!
     * \brief clickedListView
     * Special connection made in constructor to detect when QWidgetList is clicked
     */
    void clickedListView();

    void on_actionload_last_session_triggered();

    void on_actionsave_session_triggered();

    void on_actionLoad_from_FILE_triggered();

private:
    Ui::MainWindow *ui; /*! <ui called by MainWindow class to have acces to the widget elements*/
    arduinoSerial Arduino; /*! <Instantiation of class arduinoSerial*/
    Keyboard *lineEditKeyboard; /*! <Instantiation of class Keyboard*/
    static QVector <QString> currentVal; /*! <list to hold current values*/
    bool stateButton; /*! <bool variable to save state of PLAY/STOP button*/
    static QString S; /*! <String to save samplingLine */
    static QString C; /*! <String to save cyclesLine*/
    static QString A; /*! <String to save amplitudeLine*/
    static QString P; /*! <String to save periodLine*/
    static QVector<double> qv_x, qv_y; /*! <vectors to hold list of time sampling and current values entered*/
    static QVector<double> realTimeX, realTimeY; /*! <vectors to hold real time coming data from serial port*/
    QTime   timeToPlot; /*! <creation of time object from qt creator*/
    QString serialBuffer; /*! < to hold incoming data from serial port*/
    saveLoadFile Archivo;

    /*!
     * \brief clearListWidget
     * Clear all values from QWidgetList
     */
    void clearListWidget();

    /*!
     * \brief hideButtonsCurrent
     * hides the buttons to replace, clear, delete current values.
     * hides QWidgetList
     */
    void hideButtonsCurrent();

    /*!
     * \brief showButtonsCurrent
     * shows buttons replace, clear, delete, add to manage current values
     * shows QWidgetList
     */
    void showButtonsCurrent();

    /*!
     * \brief createVectorPlot
     * creates x-axis to hold values sampled in time
     * Takes current values from currentVal to qv_y to hold currents in double format.
     */
    void createVectorPlot();

    /*!
     * \brief createStringSerial
     * Copies data sent from arduino
     * Verifies that string is complete if it ends with newline
     * If it is verified then it checks whether is a number or a cycle change sent by the arduino board
     * If it is a number it creats a realX and realY axis vector to be plotted
     * \param dato
     * String comming from reading port in arduinoserial class
     */
    void createStringSerial(const QString &dato);

    /*!
     * \brief realTime
     * timer implementation to count time elapsed after hitting PLAY button to start program
     * \return
     * returns the time when the fonction its called
     */
    double realTime();
};

#endif // MAINWINDOW_H
