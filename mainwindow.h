#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QMainWindow>
#include <QList>
#include <QUrl>
#include <QQueue>
#include <QFile>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QStringList>
#include <QFileInfo>
#include <QTimer>
#include <QUuid>
#include <QDir>
#include <QDebug>

class QNetworkReply;

struct Queue{
  QString key;
  QUrl url;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QByteArray downloadedData() const;
    void Do_Download();
    void downloadFile(const QString &url, const QString &aPathInClient);
    bool CheckExits(QString tof);
    void CheckExitsVoid();
    void DownloadContent(QString typ);
    void Install(QString typ);
    bool CheckInstalled(QString typ);
    void Do();


private slots:

    void on_cssCheckBox_clicked(bool checked);

    void on_HL2EP2checkBox_clicked(bool checked);

    void on_CityRpCheckBox_clicked(bool checked);

    void on_EvocityMap_clicked(bool checked);

    void on_Button_clicked();
    void Disable(QString typ);
    void Enable();

private:
    Ui::MainWindow *ui;

private:
 QNetworkAccessManager m_WebCtrl;
 QByteArray m_DownloadedData;


};

#endif // MAINWINDOW_H

