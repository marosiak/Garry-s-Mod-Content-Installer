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

bool cssBool;
bool HL2Bool;
bool CityRpBool;
bool EvoMapBool;
bool Downloading = false;

QString isCss;
QString isHL2;
QString isCityRp;
QString isEvoMap;

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
    Downloading = false;

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
    CityRpPath += "/GmodContents/CITYRP.zip";
    CityMapPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    CityMapPath += "/GmodContents/CITYRPMAP.zip";

    if(CheckInstalled("HL2EP2") == false){
        if(!fileExists(HL2Path)){
            isHL2 = "NotDownloaded";
            }
        else{
            isHL2 = "Downloaded";
        }
    }
    else{
        isHL2 = "Installed";
    }
   if(CheckInstalled("CSS") == false){
        if(!fileExists(CssPath)){
            isCss = "NotDownloaded";
            }
        else{
            isCss = "Downloaded";
        }
    }
    else{
       isCss = "Installed";
    }
   if(CheckInstalled("Map") == false){
       if(!fileExists(CityMapPath)){
           isEvoMap = "NotDownloaded";
       }
       else{
           isEvoMap = "Downloaded";
       }
   }
   else{
       isEvoMap = "Installed";
   }
   if(CheckInstalled("CityRp") == false){
        if(!fileExists(CityRpPath)){
            isCityRp = "NotDownloaded";
            }
        else{
            isCityRp = "Downloaded";
        }
    }
   else{
       isCityRp = "Installed";
   }
   /////
   if(isCss == "Installed"){
       ui->cssCheckBox->setText("Counter Strike Source [Installed]");
       ui->cssCheckBox->setEnabled(false);
   }
   else{
       ui->cssCheckBox->setText("Counter Strike Source");
       ui->EvocityMapChecker->setEnabled(true);
   }
   if(isHL2 == "Installed"){
       ui->HL2EP2checkBox->setText("Half Life 2 Epizode 2 [Installed]");
       ui->HL2EP2checkBox->setEnabled(false);
   }
   else{
       ui->HL2EP2checkBox->setText("Half Life 2 Epizode 2");
       ui->EvocityMapChecker->setEnabled(true);
   }
   if(isCityRp == "Installed"){
       ui->CityRpCheckBox->setText("City Rp Content [Installed]");
       ui->CityRpCheckBox->setEnabled(false);
   }
   else{
       ui->CityRpCheckBox->setText("City Rp");
       ui->EvocityMapChecker->setEnabled(true);
   }
   if(isEvoMap == "Installed"){
       ui->EvocityMapChecker->setText("Evocity V2d [Installed]");
       ui->EvocityMapChecker->setEnabled(false);
   }
   else{
       ui->EvocityMapChecker->setText("Evocity V2d");
       ui->EvocityMapChecker->setEnabled(true);
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
        cacheFolder += "/GmodContents/CITYRP.zip";
        JlCompress::extractDir(cacheFolder, "C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/garrysmod/addons");

    }
    if(typ == "CityRpMap"){
        QString cacheFolder;
        cacheFolder = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        cacheFolder += "/GmodContents/CITYRPMAP.zip";
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


void MainWindow::on_cssCheckBox_clicked(bool checked){
    cssBool = checked;
}


void MainWindow::on_HL2EP2checkBox_clicked(bool checked){
    HL2Bool = checked;
}


void MainWindow::on_CityRpCheckBox_clicked(bool checked){
    CityRpBool = checked;
}


void MainWindow::on_EvocityMap_clicked(bool checked){
    EvoMapBool = checked;
}



void MainWindow::on_Button_clicked(){

}
