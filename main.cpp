#include "centralwidget.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    CentralWidget w;
    w.show();
    w.setWindowTitle(QString::fromUtf8("CPPong :: An cutting edge application by Vera & Julian"));
    w.resize(1000, 650);
    return a.exec();
}
