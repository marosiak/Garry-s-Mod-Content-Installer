#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Do_Download();
    void downloadFile(const QString &url, const QString &aPathInClient);
    void DownloadCSS();
    bool CheckExits(QString tof);
    void CheckExitsVoid();
    void DownloadContent(QString typ);
private slots:
    void on_CSS_Button_clicked();

    void on_MainWindow_windowTitleChanged(const QString &title);

    void on_HL2_Button_clicked();

    void on_CityRp_Button_clicked();

    void on_cssCheckBox_clicked(bool checked);

    void on_HL2EP2checkBox_clicked(bool checked);

    void on_CityRpCheckBox_clicked(bool checked);

    void on_EvocityMap_clicked(bool checked);

    void on_Button_clicked(bool checked);

    void on_Button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

