#include "textedittool.h"
#include "ui_textedittool.h"

#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QInputDialog>

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
    ui->mainTextout->clear();
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
        ui->mainTextout->append("<strong><font color = \"grey\"><I>" + nutoStr + "</I></font></strong> " + line);
    }
    //ui->mainTextout->setText(filename);
    ui->getFileName->clear();
    curFile->close();
}

void TextEditTool::on_btnSwap_clicked()
{
    QString dlgTitle="输入行号对话框";
    QString txtLabel="请输入行号";
    QString defaultInput="0";
    QLineEdit::EchoMode echoMode=QLineEdit::Normal;//正常文字输入
    //QLineEdit::EchoMode echoMode=QLineEdit::Password;//密码输入
    bool ok=false;
    QString text = QInputDialog::getText(this, dlgTitle,txtLabel, echoMode,defaultInput, &ok);
    if (ok && !text.isEmpty())
    {
        QString dlgTitle = "输入字符串对话框";
        QString txtLabel = "请输入要替换成的字符串";
        QLineEdit::EchoMode echoMode = QLineEdit::Normal;
        QString cNumber = QInputDialog::getText(this, dlgTitle, txtLabel, echoMode);
        qDebug()<<cNumber<<endl;
    }
}
