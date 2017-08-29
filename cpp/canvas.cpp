#include "canvas.h"

canvas::canvas(QWidget *parent) : QWidget(parent){
    setPalette(QPalette(QColor(155, 155, 155))); //180, 180, 180
    setAutoFillBackground(true);
    setMouseTracking(false);

    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    lastX=100;
    lastY=100;
    increment=0;

    // Initialize forms
    int p = 1;
    if(p == 1){
        //Form form = Form::Form();
        //form.setPosition(35,67);

        Form borderLeft     = Form::Form();
        borderLeft.setType("-1");
        borderLeft.setPosition(10,0);
        borderLeft.setSize(-50,720);
        borderLeft.setColor(0, 255, 255, 255);
        borderLeft.setColor(1, 255, 255, 255);

        Form borderTop      = Form::Form();
        borderTop.setType("-1");
        borderTop.setPosition(0,10);
        borderTop.setSize(1540,-50);
        borderTop.setColor(0, 255, 255, 255);
        borderTop.setColor(1, 255, 255, 255);

        Form borderRight    = Form::Form();
        borderRight.setType("-1");
        borderRight.setPosition(1490,0);
        borderRight.setSize(50,720);
        borderRight.setColor(0, 255, 255, 255);
        borderRight.setColor(1, 255, 255, 255);

        Form borderBottom   = Form::Form();
        borderBottom.setType("-1");
        borderBottom.setPosition(0,720);
        borderBottom.setSize(1540,-50);
        borderBottom.setColor(0, 255, 255, 255);
        borderBottom.setColor(1, 255, 255, 255);


        Form s1             = Form::Form();
        s1.setPosition(25,25);
        s1.setSize(25,200);

        Form s2             = Form::Form();
        s2.setPosition(1450,325);
        s2.setSize(25,200);

        Form ball           = Form::Form();
        ball.setPosition(735,212);
        ball.setSize(25,25);
        ball.setType("ball");
        ball.setMovement(-1, 0);

        //forms.push_back(form);
        gForms.forms.push_back(s1);
        gForms.forms.push_back(s2);
        gForms.forms.push_back(ball);
        gForms.forms.push_back(borderLeft);
        gForms.forms.push_back(borderTop);
        gForms.forms.push_back(borderRight);
        gForms.forms.push_back(borderBottom);
        p = 0;
    }
}

canvas::~canvas(){}

void canvas::paintEvent(QPaintEvent * ){
    QPainter painter;
    painter.begin( this );

    for(vector<Form>::iterator it = gForms.forms.begin(); it != gForms.forms.end(); ++it){
        if(running == 1){
            it->move();
        }
        it->draw(painter);
    }

    /*
    for(pos=start; pos!=kreise.end();pos++) {
        painter.drawEllipse((*pos)->x,(*pos)->y,50,50);

        if (increment)
            switch((*pos)->phase)
            {
            case 0: //nach rechts
                if ((*pos)->x<500) (*pos)->x++;
                else (*pos)->phase=1; //Richtung wechseln
                break;
            case 1: //nach unten
                if ((*pos)->y<300) (*pos)->y++;
                else (*pos)->phase=2; //Richtung wechseln
                break;
            case 2: //nach links
                if ((*pos)->x>100) (*pos)->x--;
                else (*pos)->phase=3; //Richtung wechseln
                break;
            case 3: //nach oben
                if ((*pos)->y>100) (*pos)->y--;
                else (*pos)->phase=0; //Richtung wechseln
                break;
            }
    }
    */
    update();
    painter.end();
}

