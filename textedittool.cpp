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
    curPath.setCurrent(filePath);
    if(!curFile->exists(filePath))
    {
        QString dlgTitle = "提示";
        QString strInfo = "文件不存在，已创建文件 " + filename;
        QMessageBox::warning(this, dlgTitle, strInfo);
    }
    curFile->setFileName(filePath);
    curFile->open(QIODevice::ReadWrite);
    while(!curFile->atEnd())
    {
        QByteArray line = curFile->readLine();
        QString str(line);
        ui->mainTextout->append(line);
    }
    //ui->mainTextout->setText(filename);
    ui->getFileName->clear();
}
