#include "globals.h"

globals::globals(){
    this->gDebug              =   false;
    this->gRunning            =   false;
    this->gColorSwitch        =   0;
    this->gShowCollisonBoxes  =   0;
    this->gDisplayFactor      =   1.0;
    this->gSaved              =   "unsaved";
    this->gForms              =   { };
    this->gApproximation      =   100;
    this->gField              =   { 0, 0, 1500,550 };
    this->populate_gForms();
}

bool globals::get_gDebug(){
    return this->gDebug;
}

void globals::set_gDebug(bool val){
    this->gDebug = val;
}

bool globals::get_gRunning(){
    return this->gRunning;
}

void globals::set_gRunning(bool val){
    this->gRunning = val;
}

globals* globals::instance(){
    static globals instance;
    return &instance;
}

vector<GForm> globals::get_gForms(){
    return this->gForms;
}

void globals::set_gForms(vector<GForm> forms){
    this->gForms = forms;
}

QTimer* globals::get_gTimer(){
    return this->gTimer;
}

bool globals::get_gColorSwitch(){
    return this->gColorSwitch;
}

float globals::get_gDisplayFactor(){
    return this->gDisplayFactor;
}

void globals::increase_gDisplayFactor(){
    if(this->gDisplayFactor <= 1.9){
        this->gDisplayFactor += 0.1;
        if(this->get_gDebug()){
            this->push_gMessage("cppong: display factor increased by 0.1! (" + to_string(this->gDisplayFactor) + ")" );
        }
    } else {
        //just do nothing
        this->push_gMessage("cppong: maximum display factor reached! (" + to_string(this->gDisplayFactor) + ")" );
    }
}

void globals::decrease_gDisplayFactor(){
    if(this->gDisplayFactor >= 0.3){
        this->gDisplayFactor += -0.1;
        if(this->get_gDebug()){
            this->push_gMessage("cppong: display factor decreased by 0.1! (" + to_string(this->gDisplayFactor) + ")" );
        }
    } else {
        //just do nothing
        this->push_gMessage("cppong: minimum display factor reached! (" + to_string(this->gDisplayFactor) + ")" );
    }
}

void globals::start_gTimer(int val){
    this->gTimer->start(val);
}

void globals::stop_gTimer(){
    this->gTimer->stop();
}

void globals::addForm_gForms(GForm form){
    form.setId(this->assignId());
    this->gForms.push_back(form);
    if(this->get_gDebug()){
        this->push_gMessage("cppong: a form was added! ( id:" + to_string(this->gFormCount) + ")" );
    }
}

void globals::populate_gForms(){

    GForm field     = GForm::GForm();
    field.setType("-1");
    field.setPosition(this->gField[0], this->gField[1]);
    field.setSize(this->gField[2], this->gField[3]);
    field.setColor(0, 200, 200, 200);
    field.setColor(1, 200, 200, 200);
    /*
    GForm borderLeft     = GForm::GForm();
    borderLeft.setType("-1");
    borderLeft.setPosition(10,0);
    borderLeft.setSize(-50,720);
    borderLeft.setColor(0, 255, 255, 255);
    borderLeft.setColor(1, 255, 255, 255);

    GForm borderTop      = GForm::GForm();
    borderTop.setType("-1");
    borderTop.setPosition(0,10);
    borderTop.setSize(1540,-50);
    borderTop.setColor(0, 255, 255, 255);
    borderTop.setColor(1, 255, 255, 255);

    GForm borderRight    = GForm::GForm();
    borderRight.setType("-1");
    borderRight.setPosition(1490,0);
    borderRight.setSize(50,720);
    borderRight.setColor(0, 255, 255, 255);
    borderRight.setColor(1, 255, 255, 255);

    GForm borderBottom   = GForm::GForm();
    borderBottom.setType("-1");
    borderBottom.setPosition(0,720);
    borderBottom.setSize(1540,-50);
    borderBottom.setColor(0, 255, 255, 255);
    borderBottom.setColor(1, 255, 255, 255);
    */

    GForm s1             = GForm::GForm();
    s1.setPosition(25,25);
    s1.setSize(25,200);
    s1.setType("rect");
    s1.setColor(0, 255, 0, 0);
    s1.setColor(1, 0, 255, 0);
    s1.setMovement(0,1);

    GForm s2             = GForm::GForm();
    s2.setPosition(1450,325);
    s2.setSize(25,200);
    s2.setType("rect");
    s2.setColor(0, 0, 0, 255);
    s2.setColor(1, 255, 0, 0);
    s2.setMovement(0,-1);

    GForm ball           = GForm::GForm();
    ball.setPosition(735,212);
    ball.setSize(25,25);
    ball.setType("ball");
    ball.setColor(0, 0, 255, 0);
    ball.setColor(1, 0, 0, 255);
    ball.setMovement(-1, 3);

    //forms.push_back(form);
    this->addForm_gForms(field);
    this->addForm_gForms(s1);
    this->addForm_gForms(s2);
    this->addForm_gForms(ball);
    /*
    this->addForm_gForms(borderLeft);
    this->addForm_gForms(borderTop);
    this->addForm_gForms(borderRight);
    this->addForm_gForms(borderBottom);
    */
}

void globals::set_gTimer(QTimer* timer){
    this->gTimer = timer;
}

void globals::set_gApproximation(int val){
    this->gApproximation = val;
}

int globals::get_gApproximation(){
    return this->gApproximation;
}

void globals::push_gMessage(string strg){
    this->gMessages.push_back(strg);
}

vector<string> globals::get_gMessages(){
    return this->gMessages;
}

string globals::pop_gMessage(){
    string msg = this->gMessages.back();
    this->gMessages.pop_back();
    return msg;
}

int globals::assignId(){
    this->gFormCount += 1;
    return this->gFormCount;
}

void globals::switchColor(){
    if(this->gColorSwitch == true) this->gColorSwitch = false;
    else this->gColorSwitch = true;
}