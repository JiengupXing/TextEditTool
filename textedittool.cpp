#include "textedittool.h"
#include "ui_textedittool.h"

#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <QFile>

TextEditTool::TextEditTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEditTool)
{
    ui->setupUi(this);
    QPalette pal = ui->Nuout->palette();
    pal.setColor(QPalette::Base, QColor(200,200,200));
    ui->Nuout->setPalette(pal);
}

TextEditTool::~TextEditTool()
{
    delete ui;
}

void TextEditTool::on_pushButton_clicked()
{
    QString dlgTitle = "错误";
    QString strInfo = "文件不存在";
    QMessageBox::critical(this, dlgTitle, strInfo);
}

void TextEditTool::on_btnOpen_clicked()
{
    ui->mainTextout->clear();
    ui->Nuout->clear();
    QString filename = ui->getFileName->text();
    QDir curPath;
    QString filePath = curPath.currentPath() + "/Documents";
    if(!curPath.exists(filePath))
    {
        //qDebug()<<"success!"<<endl;
        curPath.mkdir(filePath);
    }
    filePath += "/" + filename;
    QFile *curFile = new QFile;
    if(!curFile->exists(filePath))
    {
        QString dlgTitle = "提示";
        QString strInfo = "文件不存在，已创建文件 " + filename;
        QMessageBox::warning(this, dlgTitle, strInfo);
    }
    curFile->setFileName(filePath);
    curFile->open(QIODevice::ReadWrite);
    qint32 nu = 0;
    while(!curFile->atEnd())
    {
        QString line = curFile->readLine();
        QString nutoStr = QString::number(++nu);
        ui->mainTextout->append(line);
        ui->Nuout->append("<strong><font color=\"red\">" + nutoStr + "</font></strong><br></br>");
    }
    //ui->mainTextout->setText(filename);
    ui->getFileName->clear();
    curFile->close();
}
