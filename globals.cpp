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

    this->gRandom             =   0;
    this->gRandomMin          =   0;
    this->gRandomMax          =   0;
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

QTimer* globals::get_gSystemTimer(){
    return this->gSystemTimer;
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
            if(this->get_gDebug()){
                this->push_gMessage("cppong: display factor increased by 0.1! (" + to_string(this->gDisplayFactor) + ")" );
            }

        }
    } else {
        //just do nothing
        if(this->get_gDebug()){
            this->push_gMessage("cppong: maximum display factor reached! (" + to_string(this->gDisplayFactor) + ")" );
        }
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

void globals::start_gSystemTimer(int val){
    this->gSystemTimer->start(val);
}

void globals::stop_gSystemTimer(){
    this->gSystemTimer->stop();
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
}

void globals::set_gSystemTimer(QTimer* timer){
    this->gSystemTimer = timer;
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
    this->gMessages.push(strg);
}

queue<string> globals::get_gMessages(){
    return this->gMessages;
}

string globals::pop_gMessage(){
    string msg = this->gMessages.front();
    this->gMessages.pop();
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

int globals::random(int min, int max){
   static bool first = true;
   if ( first ) {
      srand(time(NULL)); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (max - min);
}

void globals::gSaveCppong(){

    if(std::ofstream(this->getFilePath())){
        int debugVal = 0;
        if(this->get_gDebug()) debugVal = 1;

        string colorVal = "0";
        if(this->get_gColorSwitch()) colorVal = "1";

        string approxVal = "0";
        if(this->get_gApproximation() != 0) approxVal = to_string(this->get_gApproximation());

        string displayVal = "1";
        if(this->get_gDisplayFactor() != 1) displayVal = to_string(this->get_gDisplayFactor());


        std::ofstream vault;
        vault.open (this->getFilePath());
        vault << "g,";                                  //0
        vault << to_string(debugVal)+ ',';              //1
        vault << colorVal + ',';                        //2
        vault << approxVal + ',';                       //3
        vault << to_string(this->gRandom) + ',';        //4
        vault << to_string(this->gRandomMin) + ',';     //5
        vault << to_string(this->gRandomMax) + ',';     //6
        vault << displayVal << endl;                    //7
        vault << ",,,,,,,"<< endl;

        for (unsigned i=0; i < this->gForms.size(); i++) {
            vault << "f,";                                          //0
            vault << to_string(gForms[i].getId()) + ',';            //1
            vault << to_string(gForms[i].getType()) + ',';          //2
            vault << to_string(gForms[i].getPosition()[0]) + ',';   //3
            vault << to_string(gForms[i].getPosition()[1]) + ',';   //4
            vault << to_string(gForms[i].getSize()[0]) + ',';       //5
            vault << to_string(gForms[i].getSize()[1]) + ',';       //6
            vault << ',';                                           //7
            vault << endl;
        }

        vault.close();
        this->push_gMessage("cppong: everything is saved!");
    }


}

void globals::gLoadCppong(){
    string line;
    string x, a, b, c, d, e, f, g;
    if (!std::ifstream(this->getFilePath())){
        this->push_gMessage("cppong: vault.txt does not exist or is not readable!" );
        this->push_gMessage("cppong: maybe you have not saved yet?" );
    } else {
        ifstream infile(this->getFilePath());
        int count = 1;
        while (getline(infile, line)){
            std::stringstream linestream(line);

            getline(linestream, x, ',');// 0
            getline(linestream, a, ',');// 1
            getline(linestream, b, ',');// 2
            getline(linestream, c, ',');// 3
            getline(linestream, d, ',');// 4
            getline(linestream, e, ',');// 5
            getline(linestream, f, ',');// 6
            getline(linestream, g, ',');// 7
            /*
            if(this->get_gDebug()){
                this->push_gMessage(a + ' ' + b + ' ' + c + ' ' + d + ' ' + e + ' ' + f + ' ' + g);
            }
            */
            if(x == "g"){
                this->push_gMessage("cppong: loading the globals ...");
                this->set_gDebug(stoi(a));
                this->gColorSwitch = stoi(b);
                this->set_gApproximation(stoi(c));
                this->gRandom = stoi(d);
                this->gRandomMin = stoi(e);
                this->gRandomMax = stoi(f);
                this->gDisplayFactor = stof(g);
                this->push_gMessage("cppong: globals loaded!");
            } else if (x == "f"){
                this->push_gMessage("cppong: loading the forms ...");

                this->push_gMessage("cppong: forms loaded!");
            } else if (x == ""){
                this->push_gMessage("cppong: line " + to_string(count) + " is empty!");
            } else {
                this->push_gMessage("cppong: something is wrong in line " + to_string(count));
            }
            count++;
        }

        /*
        std::ifstream infile(this->getFilePath());
        string a, b, c, d;

        while (infile >> a >> b >> c >> d){
            this->push_gMessage(a + ' ' + b + ' ' + c + ' ' + d);
        }
        */
        this->push_gMessage("cppong: data loaded from vault!" );
    }
}

string globals::getCurrentPath(){
    return QDir::currentPath().toUtf8().constData();
}

string globals::getFilePath(){
    return this->getCurrentPath() + "/savegame.vault";
}
