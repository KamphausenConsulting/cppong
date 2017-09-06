#ifndef CANVAS_H
#define CANVAS_H
using namespace std;

#include <QWidget>
#include <QtGui>
#include <vector>
#include <chrono>
#include <thread>

#include "globals.h"
#include "collider.h"

class Canvas : public QWidget {

    public:
        Canvas(QWidget *parent = 0);
        void sync(void);

    private:
        globals* globals = globals::instance();
        Collider collider = Collider::Collider();
        void paintEvent(QPaintEvent *event);
        vector<GForm> gForms;
        float displayFactor;
        bool  gColorSwitch;
};

#endif // CANVAS_H
