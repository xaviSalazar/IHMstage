#ifndef KEYBOARD_H
#define KEYBOARD_H

/*!
  * \file keyboard.h
  * \brief External numeric keypad
  * \version 1.0
*/

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

/*! \namespace ui
 *  it groupes all variables to control the widgets
 */
namespace Ui {
class Keyboard;
}

/*! \class Keyboard
 * \brief The Keyboard class implements a touch keypad when needed to enter data.
 */
class Keyboard : public QWidget
{

    Q_OBJECT

public:
    /*!
     * \brief Constructor
     * Keyboard Initialize the object with setups needed to run
     * \param parent
     */
    explicit Keyboard(QWidget *parent = nullptr);
        ~Keyboard();

    /*!
     * \brief setLineEdit Identifies which lineLabel its pressed when calling the keyboard
     */
    void setLineEdit(QLineEdit *);

    QPushButton *enterButton; /*! <Creation of a QPushButton to send its signal when pressed */


private slots:
    /*!
     * \brief keyboardHandler Identifies which button its pressed and sends the text to lineEdit
     */
    void keyboardHandler();

    /*!
     * \brief on_enterButton_clicked Changes lineEdit text when pressed
     */
    void on_enterButton_clicked();

    /*!
     * \brief on_lineEdit_textChanged The fonction activates itself when text its changed so it refreshes the text
     * \param arg1 Default argument by Qt creator
     */
    void on_lineEdit_textChanged(const QString &arg1);

    /*!
     * \brief on_lineEdit_returnPressed When a real Keyboard it's used it changes the text when return button its pressed
     */
    void on_lineEdit_returnPressed();

    /*!
     * \brief on_backButton_clicked Fonction to erase the last elements of a lineEdit, in order to edit text
     */
    void on_backButton_clicked();

    /*!
     * \brief on_clear_clicked Fonction to clear all lineEdit text to empty.
     */
    void on_clear_clicked();

private:

    Ui::Keyboard *ui; /*! <ui called by Keyboard class to have acces to the widget elements*/

    QString outputText; /*! < Variable to be changed in order to change the final result to change in lineEdit text*/

    QLineEdit *outputLineEdit;/*! <Variable to store whiche lineEdit its pressed when calling the Keyboard*/

};

#endif //KEYBOARD_H


