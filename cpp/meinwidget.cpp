// Qt5 add:
#include <QPushButton>
#include <QGridLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include <QtGui>
#include "meinWidget.h"
#include <QTextEdit>

meinWidget::meinWidget(QWidget *parent) : QWidget(parent){

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
    connect(minusButton, SIGNAL(clicked()), this, SLOT(minus()));

    QPushButton *plusButton = new QPushButton(tr("-"));
    plusButton->setFont(QFont(font, 16, QFont::Bold));
    connect(plusButton, SIGNAL(clicked()), this, SLOT(plus()));

    meinZeichenFeld = new canvas;
    textbox = new QTextEdit;
    textbox->setText("Hello world!");

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
    gridLayout->addWidget(meinZeichenFeld, 1, 0, 3, 0);
    gridLayout->setRowStretch(4,1);
    gridLayout->addWidget(textbox, 4, 0, 2, 0);
    /*




    meinZeichenFeld = new canvas;

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->rowStretch(1);
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(startButton, 0, 1);
    gridLayout->addWidget(stopButton, 0, 2);
    gridLayout->addWidget(minusButton, 0, 3);
    gridLayout->addWidget(plusButton, 0, 4);
    gridLayout->addWidget(meinZeichenFeld, 1, 0, 1, 0);
    gridLayout->setColumnStretch(1, 0);
    //gridLayout->addWidget(textbox);
    setLayout(gridLayout);
    */
}

void meinWidget::start(void){
    meinZeichenFeld->start();
}

void meinWidget::stop(void){
    meinZeichenFeld->stop();
}

void meinWidget::minus() {
    if(displayDivisor != 1){
        displayDivisor += -1;
    }
}

void meinWidget::plus() {
    if(displayDivisor != 4){
        displayDivisor += 1;
    }
}
