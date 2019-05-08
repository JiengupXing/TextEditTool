#ifndef TEXTEDITTOOL_H
#define TEXTEDITTOOL_H

#include <QMainWindow>

namespace Ui {
class TextEditTool;
}

class TextEditTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextEditTool(QWidget *parent = nullptr);
    ~TextEditTool();

private slots:
    void on_pushButton_clicked();

    void on_btnOpen_clicked();

private:
    Ui::TextEditTool *ui;
};

#endif // TEXTEDITTOOL_H
