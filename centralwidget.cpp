#include "centralwidget.h"
#include "ui_centralwidget.h"


CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent),
                                                ui(new Ui::CentralWidget){
    globals->set_gDebug(true);
    globals->set_gSystemTimer(new QTimer(this));
    globals->set_gTimer(new QTimer(this));
    globals->start_gSystemTimer(5);
    connect(globals->gSystemTimer, SIGNAL(timeout()), this, SLOT(test()));

    QPushButton *quit = new QPushButton(tr("EXIT"));
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
    connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));

    QPushButton *loadButton = new QPushButton(tr("LOAD"));
    loadButton->setFont(QFont(font, 12, QFont::Bold));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(load()));

    QPushButton *minusButton = new QPushButton(tr("+"));
    minusButton->setFont(QFont(font, 16, QFont::Bold));
    connect(minusButton, SIGNAL(clicked()), this, SLOT(plus()));

    QPushButton *plusButton = new QPushButton(tr("-"));
    plusButton->setFont(QFont(font, 16, QFont::Bold));
    connect(plusButton, SIGNAL(clicked()), this, SLOT(minus()));

    debugButton = new QPushButton(tr("DEBUG"));
    debugButton->setFont(QFont(font, 12, QFont::Bold));
    connect(debugButton, SIGNAL(clicked()), this, SLOT(debugSwitch()));

    QLabel *label = new QLabel(tr("TEST"));
    label->setFont(QFont(font, 12, QFont::Bold));

    labelDisplayFactor= new QLabel(QString::number(globals->get_gDisplayFactor()));
    labelDisplayFactor->setFont(QFont(font, 12, QFont::Bold));
    labelDisplayFactor->setFixedWidth(20);
    labelDisplayFactor->setAlignment(Qt::AlignCenter);

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
    gridLayout->addWidget(labelDisplayFactor,   0,  6);
    gridLayout->addWidget(plusButton,   0,  7);
    gridLayout->addWidget(debugButton,   0,  8);
    //gridLayout->setColumnStretch(1,0);
    gridLayout->setRowStretch(1,3);
    gridLayout->addWidget(MainCanvas, 1, 0, 3, 0);
    gridLayout->setRowStretch(4,1);
    gridLayout->addWidget(textbox, 4, 0, 2, 0);

}

void CentralWidget::start(void){
    globals->set_gRunning(true);
    globals->start_gTimer(10);
    globals->push_gMessage("cppong: the fun has started!");
}

void CentralWidget::stop(void){
    globals->set_gRunning(false);
    globals->stop_gTimer();
    globals->push_gMessage("cppong: oh nooo - its over!");
}

void CentralWidget::minus() {
    globals->decrease_gDisplayFactor();
}

void CentralWidget::plus() {
    globals->increase_gDisplayFactor();
}

void CentralWidget::test(){
    queue<string> gMassages = globals->get_gMessages();
    while (!gMassages.empty()){
      string strg = globals->pop_gMessage();
      this->textbox->append(strg.c_str());
      gMassages.pop();
    }
    QTextCursor c =  this->textbox->textCursor();
    c.movePosition(QTextCursor::End);
    this->textbox->setTextCursor(c);

    this->labelDisplayFactor->setText(QString::number(globals->get_gDisplayFactor()));


    QString windowTitle;
    if(globals->get_gDebug()){
        windowTitle += "[DEBUG MODE] ";
        this->debugButton->setStyleSheet("color: rgb(0, 255, 0)");
    } else {
        this->debugButton->setStyleSheet("color: rgb(255, 0, 0)");
    }
    windowTitle += globals->gName + " :: " + globals->gClaim + " :: ";
    if(globals->get_gRunning()) windowTitle += "Running";
    if(!globals->get_gRunning()) windowTitle += "Stopped";
    this->setWindowTitle(windowTitle);
}

void CentralWidget::sync(void){
    MainCanvas->sync();
}

void CentralWidget::debugSwitch(void){
    bool d = globals->get_gDebug();
    globals->set_gDebug(!d);
}

/*
CentralWidget::~CentralWidget(){
    //delete ui;
}
*/
