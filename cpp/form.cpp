#include "form.h"

Form::Form(){
    calcFormLocationCoordinates();
}

Form::~Form(){}

void Form::draw(QPainter &painter){
    if(this->type == -1){
        brush.setStyle(Qt::BDiagPattern);
    } else {
        brush.setStyle(Qt::SolidPattern);
    }

    QPen pen(Qt::white, 1);
    painter.setPen(pen);

    if(colorSwitch == 1){
        this->brush.setColor(QColor(this->color[3],this->color[4],this->color[5]));//60,80,100
    } else {
        this->brush.setColor(QColor(this->color[0],this->color[1],this->color[2]));
    }
    painter.setBrush(brush);

    if(this->type == 0 || this->type == -1){
        painter.drawRect(this->position[0]/displayDivisor,this->position[1]/displayDivisor, this->size[0]/displayDivisor, this->size[1]/displayDivisor);
    } else {
        painter.drawEllipse(this->position[0]/displayDivisor,this->position[1]/displayDivisor, this->size[0]/displayDivisor, this->size[1]/displayDivisor);
    }
    calcFormLocationCoordinates();
}

void Form::move(){
    this->position[0] += this->movement[0];
    this->position[1] += this->movement[1];
}

void Form::setPosition(int x, int y){
    this->position[0] = x;
    this->position[1] = y;
}

void Form::setMovement(int x, int y){
    this->movement[0] = x;
    this->movement[1] = y;
}

void Form::setSize(int w, int h){
    this->size[0] = w;
    this->size[1] = h;
}

void Form::setType(char type[10]) {
    if(type == "rect"||type == "rectangle"||type == "0"){
        this->type = 0;
    } else if(type == "border"||type == "boundry" || type == "-1"){
        this->type = -1;
    } else {
        this->type = 1;
    }
}

void Form::setColor(int num, int r, int g, int b) {
    if(num == 0){
        this->color[0] = r;
        this->color[1] = g;
        this->color[2] = b;
    } else {
        this->color[3] = r;
        this->color[4] = g;
        this->color[5] = b;
    }
}


void Form::calcFormLocationCoordinates(){
    int Ax  = this->position[0],
        Ay  = this->position[1],
        w   = this->size[0],
        h   = this->size[1],
        Bx, By, Cx, Cy, Dx, Dy;

    Bx      = Ax + w;
    By      = By;

    Cx      = Bx;
    Cy      = By - h;

    Dx      = Ax;
    Dy      = Cy;

    location = { Ax, Ay, Bx, By, Cx, Cy, Dx, Dy };


}







