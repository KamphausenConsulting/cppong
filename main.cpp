#include "centralwidget.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //QApplication::setWindowIcon(QIcon("Resources/app.icns"));
    QApplication::setWindowIcon(QIcon("app.icns"));
    CentralWidget w;
    w.show();
    w.resize(1000, 650);
    return a.exec();
}
