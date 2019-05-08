#include "textedittool.h"
#include "ui_textedittool.h"

#include <QDebug>
#include <QMessageBox>

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
