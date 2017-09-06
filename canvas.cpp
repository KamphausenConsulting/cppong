#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent){
    setPalette(QPalette(QColor(155, 155, 155))); //180, 180, 180
    setAutoFillBackground(true);
    setMouseTracking(false);

    connect(globals->gTimer, SIGNAL(timeout()), this, SLOT(update()));

    /*
    QTimer *timer;
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);
    */
}

void Canvas::paintEvent(QPaintEvent * ){
    QPainter painter;
    painter.begin( this );

    this->sync();

//    for(vector<GForm>::iterator it = this->gForms.begin(); it != this->gForms.end(); ++it){
//        if(globals->get_gRunning() == true){
//            it->move();
//            if(it->getType() != -1) this->collider.collide(it);
//        }
//        it->draw(painter, this->displayFactor, this->gColorSwitch);
//        it->drawCollBox(painter, this->displayFactor, this->gColorSwitch);
//        it->drawApproximationBox(painter, globals->get_gApproximation(), this->displayFactor, this->gColorSwitch);
//    }

    for (unsigned i=0; i < this->gForms.size(); i++) {
        if(globals->get_gRunning() == true){
            gForms[i].move();
            if(gForms[i].getType() != -1) this->collider.collide(this->gForms[i], this->gForms);
        }
        gForms[i].draw(painter, this->displayFactor, this->gColorSwitch);
        if(globals->get_gDebug()==true){
            gForms[i].drawCollBox(painter, this->displayFactor, this->gColorSwitch);
            gForms[i].drawApproximationBox(painter, globals->get_gApproximation(), this->displayFactor, this->gColorSwitch);
        }
    }

    globals->set_gForms(this->gForms);

    update();
    painter.end();
}

void Canvas::sync(void){
    this->gForms          = globals->get_gForms();
    this->displayFactor   = globals->get_gDisplayFactor();
    this->gColorSwitch    = globals->get_gColorSwitch();
    update();
}
