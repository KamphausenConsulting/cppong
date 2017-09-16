#include "gform.h"

GForm::GForm(){}

//FUNCTIONS
void GForm::move(){
    this->position[0] += this->movement[0];
    this->position[1] += this->movement[1];
    this->updateLocation();
}

void GForm::updateLocation(){
    int Ax  = this->position[0],
        Ay  = this->position[1],
        w   = this->size[0],
        h   = this->size[1],
        Bx, By, Cx, Cy, Dx, Dy;

    Bx      = Ax + w;
    By      = Ay;

    Cx      = Bx;
    Cy      = By + h;

    Dx      = Ax;
    Dy      = Cy;

    this->location = { Ax, Ay, Bx, By, Cx, Cy, Dx, Dy };
}

void GForm::draw(QPainter &painter, float displayFactor = 1.0, bool colorSwitch = false){
    if(this->type == -1){
        this->brush.setStyle(Qt::BDiagPattern);
    } else {
        this->brush.setStyle(Qt::SolidPattern);
    }

    QPen pen(Qt::white, 1);
    painter.setPen(pen);

    if(colorSwitch == 1){
        this->brush.setColor(QColor(this->color[3],
                                    this->color[4],
                                    this->color[5]));
    } else {
        this->brush.setColor(QColor(this->color[0],
                                    this->color[1],
                                    this->color[2]));
    }
    painter.setBrush(brush);

    if(this->type == 0 || this->type == -1){
        painter.drawRect(this->position[0] * displayFactor,
                         this->position[1] * displayFactor,
                         this->size[0] * displayFactor,
                         this->size[1] * displayFactor);
    } else {
        painter.drawEllipse(this->position[0] * displayFactor,
                            this->position[1] * displayFactor,
                            this->size[0] * displayFactor,
                            this->size[1] * displayFactor);
    }

}

void GForm::drawCollBox(QPainter &painter, float displayFactor = 1.0, bool colorSwitch = false){

    QColor color;
    if(colorSwitch == false){
        color = QColor(this->color[3],
                       this->color[4],
                       this->color[5]);
    } else {
        color = QColor(this->color[0],
                       this->color[1],
                       this->color[2]);
    }

    QPen pen(color, 1);
    painter.setPen(pen);
    this->brush.setColor(Qt::transparent);
    painter.setBrush(this->brush);

    QPolygon poly;
    poly << QPoint(this->location[0] * displayFactor,
                   this->location[1] * displayFactor);
    poly << QPoint(this->location[2] * displayFactor,
                   this->location[3] * displayFactor);
    poly << QPoint(this->location[4] * displayFactor,
                   this->location[5] * displayFactor);
    poly << QPoint(this->location[6] * displayFactor,
                   this->location[7] * displayFactor);

    painter.drawPolygon(poly);
}

void GForm::drawApproximationBox(QPainter &painter, int distance = 0, float displayFactor = 1.0, bool colorSwitch = false){

    QColor color;
    if(colorSwitch == false){
        color = QColor(this->color[3],
                       this->color[4],
                       this->color[5]);
    } else {
        color = QColor(this->color[0],
                       this->color[1],
                       this->color[2]);
    }

    QPen pen(color, 1);
    painter.setPen(pen);
    this->brush.setColor(Qt::transparent);
    painter.setBrush(this->brush);

    QPolygon poly;
    poly << QPoint((this->location[0] - distance) * displayFactor,
                   (this->location[1] - distance) * displayFactor);
    poly << QPoint((this->location[2] + distance) * displayFactor,
                   (this->location[3] - distance) * displayFactor);
    poly << QPoint((this->location[4] + distance) * displayFactor,
                   (this->location[5] + distance) * displayFactor);
    poly << QPoint((this->location[6] - distance) * displayFactor,
                   (this->location[7] + distance) * displayFactor);

    painter.drawPolygon(poly);
}

//SETTER-FUNCTIONS
void GForm::setPosition(int x, int y){
    this->position[0] = x;
    this->position[1] = y;
    this->updateLocation();
}

void GForm::setMovement(int x, int y){
    this->movement[0] = x;
    this->movement[1] = y;
}

void GForm::setSize(int w, int h){
    this->size[0] = w;
    this->size[1] = h;
    this->updateLocation();
}

void GForm::setType(char type[10]) {
    if(type == "rect"||type == "rectangle"||type == "0"){
        this->type = 0;
    } else if(type == "border"||type == "boundry" || type == "-1"){
        this->type = -1;
    } else {
        this->type = 1;
    }
}

void GForm::setColor(int num, int r, int g, int b) {
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

void GForm::setId(int id){
    this->id = id;
}

//GETTER-FUNCTIONS
vector<int> GForm::getPosition(){
    return this->position;
}

vector<int> GForm::getLocation(){
    return this->location;
}

vector<int> GForm::getMovement(){
    return this->movement;
}

vector<int> GForm::getSize(){
    return this->size;
}

vector<int> GForm::getColor() {
    return this->color;
}

int GForm::getType() {
    return this->type;
}

int GForm::getId(){
    return this->id;
}

GForm::~GForm(){}
