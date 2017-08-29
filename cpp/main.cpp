#include "meinwidget.h"
// Qt5 add:
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    meinWidget w;
    w.setGeometry(100, 100, 500, 355);
    w.show();
    w.setWindowTitle(QString::fromUtf8("CPPong :: An cutting edge application by Vera & Julian"));
    w.resize(1000, 650);
    return a.exec();
}
