#include "textedittool.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextEditTool w;
    w.show();

    return a.exec();
}
