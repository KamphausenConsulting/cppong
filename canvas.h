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
        //INSTANCES
        Canvas(QWidget *parent = 0);
        ~Canvas();
        //FUNCTIONS
        void sync(void);

    private:
        //INSTANCES
        globals* globals                    = globals::instance();
        Collider collider                   = Collider::Collider();

        //VARIABLES
        vector<GForm> gForms;
        float displayFactor;
        bool  gColorSwitch;

        //FUNCTIONS
        void paintEvent(QPaintEvent *event);      
};

#endif // CANVAS_H
