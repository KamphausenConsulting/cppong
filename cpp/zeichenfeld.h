#include <QtGui>
#include <QPainterPath>
#include <QPen>

#include "zeichenFeld.h"

zeichenFeld::zeichenFeld(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(99, 99, 99)));
    setAutoFillBackground(true);
    setMouseTracking(false);

    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    lastX=100;
    lastY=100;
    increment=0;
    //phase=0;
}

zeichenFeld::~zeichenFeld()
{
}

void zeichenFeld::paintEvent(QPaintEvent * )
{
    QPainter painter;
    painter.setRenderHint(QPainter::Antialiasing);
    //int x,y,width,height;
    vector<struct meinKreis *>::iterator pos, start;
    start = kreise.begin();

    painter.begin( this );
    //linke obere Ecke: Breite == Hoehe == 50
    //x=lastX-25;
    //y=lastY-25;

    QPainterPath path;
    path.addRoundedRect(QRectF(10, 10, 100, 50), 10, 10);
    QPen pen(Qt::black, 10);
    painter.setPen(pen);
    painter.fillPath(path, Qt::red);
    painter.drawPath(path);

    for(pos=start; pos!=kreise.end();pos++) {
        painter.drawEllipse((*pos)->x,(*pos)->y,50,50);

        if (increment)
            switch((*pos)->phase)
            {
            case 0: //nach rechts
                if ((*pos)->x<300) (*pos)->x++;
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
    painter.end();
}

//newObject implementieren
void zeichenFeld::newObject() {
    //Kreis muss als "Container" definiert werden
    struct meinKreis *object;
    object = new meinKreis; //Objekt wurde erzeugt
    if(!kreise.empty()) { //"Liste" kreise nicht leer
        object->x = kreise.back()-> x + 10;
        object->y = kreise.back()-> y + 10;
    } else {//Kreise empty
        object-> x = lastX - 25;
        object-> y = lastY - 25;
    }
    //Richtung muss gesetzt werden (durch Phase)
    object->phase = 0;
    //object->verschiebung = 0;
    kreise.push_back(object);
    update(); //oberfläche aktualisiert
}
