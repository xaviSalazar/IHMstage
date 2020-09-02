#ifndef SAVELOADFILE_H
#define SAVELOADFILE_H

#include <QFile>
#include <QTextStream>
#include <QObject>
#include <QVector>
#include <QString>
#include <QDebug>


/*! \class saveLoadFile
*  \brief this class allows to save, load and load from a file all data
*/
class saveLoadFile: public QObject
{
    Q_OBJECT
public:

    /*! \brief Constructor
      */
    saveLoadFile();

    /*!
     * \brief saveData: This function allows to save the data from a current session
     * \param QVector<QString> &Current: To pass currentVal vector created in mainwindow class.
     * \param QString &Sampling : To pass String S created in mainwindow class.
     * \param QString &Period: To pass String P created in mainwindow class.
     * \param QString &Cycles: To pass String C created in mainwindow class.
     * \param QString &Amplitude: To pass String A created in mainwindow class.
     */
    void saveData(QVector<QString> &Current, QString Sampling, QString Period, QString Cycles, QString Amplitude);

    /*! \brief loadData This function allows to load data from a saved session.
     * \param QVector<QString> &Current: To pass currentVal vector created in mainwindow class.
     * \param QString &Sampling : To pass String S created in mainwindow class.
     * \param QString &Period: To pass String P created in mainwindow class.
     * \param QString &Cycles: To pass String C created in mainwindow class.
     * \param QString &Amplitude: To pass String A created in mainwindow class.
    */
    void loadData(QVector<QString> &Current,QString &Sampling, QString &Period, QString &Cycles, QString &Amplitude);

    /*! \brief loadData: This function allows to load data from a csv file.
     * \param QString fileName: To pass the directory location when a file is selected.
     * \param QVector<QString> &Current: To pass currentVal vector created in mainwindow class.
     * \param QString &Sampling : To pass String S created in mainwindow class.
     * \param QString &Period: To pass String P created in mainwindow class.
     * \param QString &Cycles: To pass String C created in mainwindow class.
     * \param QString &Amplitude: To pass String A created in mainwindow class.
    */
    void loadData(QString fileName, QVector<QString> &Current,QString &Sampling, QString &Period,QString &Cycles, QString &Amplitude);
};

#endif // SAVELOADFILE_H
