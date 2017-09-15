#include "centralwidget.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    CentralWidget w;
    w.show();
    w.resize(1000, 650);
    return a.exec();
}
