#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QMessageBox>
#include <QStandardPaths>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <JlCompress.h>
#include <QDebug>

void Install(QString typ);

bool fileExists(QString path) {
    QFileInfo checkFile(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (checkFile.exists() && checkFile.isFile()) {
        return true;
    } else {
        return false;
    }
}


bool CheckInstalled(QString typ){
    QString PathToMap("C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/garrysmod/maps/rp_evocity_v2d.bsp");
    QString PathToCSS("C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/garrysmod/addons/CSS/addon.txt");
    QString PathToCityRp("C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/garrysmod/addons/CITYRP/addon.txt");
    QString PathToHl2EP2("C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/garrysmod/addons/HL2EP2/addon.txt");

    if(typ == "Map"){
        if(fileExists(PathToMap)){
            return true;
        }
        else{
            return false;
        }
    }
    if(typ == "HL2EP2"){
        if(fileExists(PathToHl2EP2)){
            return true;
        }
        else{
            return false;
        }
    }
    if(typ == "CSS"){
        if(fileExists(PathToCSS)){
            return true;
        }
        else{
            return false;
        }
    }
    if(typ == "CityRp"){
        if(fileExists(PathToCityRp)){
            return true;
        }
        else{
            return false;
        }
    }
}

void MainWindow::CheckExitsVoid(){
    ui->label_5->setText("");


    QString CssPath;
    QString HL2Path;
    QString CityRpPath;
    QString CityMapPath;
    QString MainPath;
    MainPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    MainPath += "/GmodContents";
    QDir dir(MainPath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    CssPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    CssPath += "/GmodContents/CSS.zip";
    HL2Path = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    HL2Path += "/GmodContents/HL2EP2.zip";
    CityRpPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    CityRpPath += "/GmodContents/CityRp.zip";
    CityMapPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    CityMapPath += "/GmodContents/CityRpMap.zip";


    if(CheckInstalled("HL2EP2") == false){
        if(!fileExists(HL2Path)){
            ui->HL2_Button->setText("Download");
            }
        else{
            ui->HL2_Button->setText("Install");
        }
    }
    if(CheckInstalled("HL2EP2") == true){
        ui->HL2_Button->setText("Installed");
        ui->HL2_Button->setEnabled(false);
        qDebug() << "HL2 Zainstalowane";
    }

   if(CheckInstalled("CSS") == false){
        if(!fileExists(CssPath)){
            ui->CSS_Button->setText("Download");
            }
        else{
            ui->CSS_Button->setText("Install");
        }
    }
    else{
        ui->CSS_Button->setText("Installed");
        ui->CSS_Button->setEnabled(false);
        qDebug() << "CSS Zainstalowane";
    }
   if(CheckInstalled("CityRp") == false || CheckInstalled("Map") == false){
        if(!fileExists(CityRpPath) || !fileExists(CityMapPath)){
            ui->CityRp_Button->setText("Download");
            }
        else{
            ui->CityRp_Button->setText("Install");
        }
    }
    if(CheckInstalled("CityRp") == true && CheckInstalled("Map") == true){{
        ui->CityRp_Button->setText("Installed");
        ui->CityRp_Button->setEnabled(false);
        qDebug() << "CityRp Zainstalowane";
        }
    }
}

bool MainWindow::CheckExits(QString tof){
    QString CssPath;
    QString HL2Path;
    QString CityRpPath;
    QString CityMapPath;
    QString MainPath;
    MainPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    MainPath += "/GmodContents";
    CssPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    CssPath += "/GmodContents/CSS.zip";
    HL2Path = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    HL2Path += "/GmodContents/HL2EP2.zip";
    CityRpPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    CityRpPath += "/GmodContents/CityRp.zip";
    CityMapPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    CityMapPath += "/GmodContents/CityRpMap.zip";
    if(tof == "CSS"){
        if(fileExists(CssPath)){
            return true;
        }
        else{
            return false;
        }
    }
    if(tof == "HL2EP2"){
        if(fileExists(HL2Path)){
            return true;
        }
        else{
            return false;
        }
    }
    if(tof == "CITYCONTENT"){
        if(fileExists(CityRpPath)){
            return true;
        }
        else{
            return false;
        }
    }
    if(tof == "CITYMAP"){
        if(fileExists(CityMapPath)){
            return true;
        }
        else{
            return false;
        }
    }
}

void Install(QString typ){
    if(typ == "CSS"){
        QString cacheFolder;
        cacheFolder = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        cacheFolder += "/GmodContents/CSS.zip";
        JlCompress::extractDir(cacheFolder, "C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/garrysmod/addons");

    }
    if(typ == "HL2EP2"){
        QString cacheFolder;
        cacheFolder = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        cacheFolder += "/GmodContents/HL2EP2.zip";
        JlCompress::extractDir(cacheFolder, "C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/garrysmod/addons");

    }
    if(typ == "CityRp"){
        QString cacheFolder;
        cacheFolder = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        cacheFolder += "/GmodContents/CityRp.zip";
        JlCompress::extractDir(cacheFolder, "C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/garrysmod/addons");

    }
    if(typ == "CityRpMap"){
        QString cacheFolder;
        cacheFolder = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        cacheFolder += "/GmodContents/CityRpMap.zip";
        JlCompress::extractDir(cacheFolder, "C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/garrysmod/maps");

    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_5->setText("");
    CheckExitsVoid();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::downloadFile(const QString &url, const QString &aPathInClient){
    QNetworkAccessManager m_NetworkMngr;
    QNetworkReply *reply= m_NetworkMngr.get(QNetworkRequest(url));
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()),&loop, SLOT(quit()));
    loop.exec();
    QUrl aUrl(url);
    QFileInfo fileInfo=aUrl.path();

    QFile file(aPathInClient+"\\"+fileInfo.fileName());
    file.open(QIODevice::WriteOnly);
    file.write(reply->readAll());
    delete reply;
    CheckExitsVoid();

}

void MainWindow::DownloadContent(QString typ){
    ui->label_5->setText("Please be patient");
    QString cachePath;
    cachePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    cachePath += "/GmodContents/";
    if(typ == "CSS"){
        downloadFile("https://dl.dropboxusercontent.com/s/u8ue2k755cri7rv/CSS.zip", cachePath);
    }
    if(typ == "HL2EP2"){
        downloadFile("https://dl.dropboxusercontent.com/s/64xkf6h3872emjg/HL2EP2.zip", cachePath);
    }
    if(typ == "CityRpContent"){
        downloadFile("https://dl.dropboxusercontent.com/s/c8akpjb9b1v1lrj/CityRp.zip", cachePath);
    }
    if(typ == "CityRpMap"){
        downloadFile("https://dl.dropboxusercontent.com/s/eync53snmkjg7bx/CityRpMap.zip", cachePath);
    }
}

void MainWindow::on_CSS_Button_clicked(){
    if(CheckExits("CSS") == true){
        Install("CSS");
    }
    else{
        DownloadContent("CSS");
    }
}


void MainWindow::on_HL2_Button_clicked()
{
    if(CheckExits("HL2EP2") == true){
        Install("HL2EP2");
    }
    else{
        DownloadContent("HL2EP2");
    }
}

void MainWindow::on_CityRp_Button_clicked(){
    if(CheckExits("CITYMAP") == true && CheckExits("CITYCONTENT") == true){
        Install("CityRp");
        Install("CityRpMap");
    }
    if(CheckExits("CITYMAP") == false){
        DownloadContent("CityRpMap");
    }
    if(CheckExits("CITYCONTENT") == false){
        DownloadContent("CityRpContent");
    }
}
