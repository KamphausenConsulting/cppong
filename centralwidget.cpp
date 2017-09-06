#include "centralwidget.h"
#include "ui_centralwidget.h"


CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent),
                                                ui(new Ui::CentralWidget){

    globals->set_gDebug(true);
    globals->set_gTimer(new QTimer(this));

    //ui->setupUi(this);

    QPushButton *quit = new QPushButton(tr("Ende"));
    quit->setFont(QFont(font, 12, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QPushButton *startButton = new QPushButton(tr("START"));
    startButton->setFont(QFont(font, 12, QFont::Bold));
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));

    QPushButton *stopButton = new QPushButton(tr("STOP"));
    stopButton->setFont(QFont(font, 12, QFont::Bold));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));

    QPushButton *saveButton = new QPushButton(tr("SAVE"));
    saveButton->setFont(QFont(font, 12, QFont::Bold));

    QPushButton *loadButton = new QPushButton(tr("LOAD"));
    loadButton->setFont(QFont(font, 12, QFont::Bold));

    QPushButton *minusButton = new QPushButton(tr("+"));
    minusButton->setFont(QFont(font, 16, QFont::Bold));
    connect(minusButton, SIGNAL(clicked()), this, SLOT(plus()));

    QPushButton *plusButton = new QPushButton(tr("-"));
    plusButton->setFont(QFont(font, 16, QFont::Bold));
    connect(plusButton, SIGNAL(clicked()), this, SLOT(minus()));

    MainCanvas = new Canvas;
    this->textbox = new QTextEdit;

    QGridLayout *gridLayout = new QGridLayout;
    setLayout(gridLayout);
    gridLayout->rowStretch(1);
    gridLayout->addWidget(quit,         0,  0);
    gridLayout->addWidget(startButton,  0,  1);
    gridLayout->addWidget(stopButton,   0,  2);
    gridLayout->addWidget(saveButton,   0,  3);
    gridLayout->addWidget(loadButton,   0,  4);
    gridLayout->addWidget(minusButton,  0,  5);
    gridLayout->addWidget(plusButton,   0,  6);
    //gridLayout->setColumnStretch(1,0);
    gridLayout->setRowStretch(1,3);
    gridLayout->addWidget(MainCanvas, 1, 0, 3, 0);
    gridLayout->setRowStretch(4,1);
    gridLayout->addWidget(textbox, 4, 0, 2, 0);

    connect(globals->gTimer, SIGNAL(timeout()), this, SLOT(test()));
}

void CentralWidget::start(void){
    globals->set_gRunning(true);
    globals->start_gTimer(10);
    //globals->gTimer->start(10);
    globals->push_gMessage("cppong: the fun has started!");
}

void CentralWidget::stop(void){
    globals->set_gRunning(false);
    globals->stop_gTimer();
    globals->push_gMessage("cppong: oh nooo - its over!");
    this->test();
}

void CentralWidget::minus() {
    if(globals->get_gRunning() == true || true){
        globals->decrease_gDisplayFactor();
    }
}

void CentralWidget::plus() {
    if(globals->get_gRunning() == true || true){
        globals->increase_gDisplayFactor();
    }
}

void CentralWidget::test(){
    /*
    if(globals->get_gRunning() == true){
        this->textbox->append("true");
    } else {
        this->textbox->append("false");
    }
    */
    vector<string> gMassages = globals->get_gMessages();
    for(vector<string>::iterator msg = gMassages.begin(); msg != gMassages.end(); ++msg){
        string strg = globals->pop_gMessage();
        this->textbox->append(strg.c_str());

    }
    QTextCursor c =  this->textbox->textCursor();
    c.movePosition(QTextCursor::End);
    this->textbox->setTextCursor(c);
}

void CentralWidget::sync(void){
    MainCanvas->sync();
}

/*
CentralWidget::~CentralWidget(){
    //delete ui;
}
*/
