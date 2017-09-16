#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H
//using namespace std;

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QtGui>
#include <QLabel>

#include "gform.h"
#include "canvas.h"
#include "globals.h"

class CentralWidget : public QWidget {
    Q_OBJECT

    public:
        //FUNCTIONS
        explicit CentralWidget(QWidget *parent = 0);
        ~CentralWidget();

    private:
        //INSTANCES
        globals*    globals             = globals->instance();
        //VARIABLES
        char        font[10]            = "Helvetica";
        Canvas      *MainCanvas;
        QTextEdit   *textbox;
        QPushButton *debugButton;
        QLabel      *labelDisplayFactor;

    private slots:
        //FUNCTIONS
        void start(void);
        void stop(void);
        void minus(void);
        void plus(void);
        void debugSwitch(void);
        void save(void) { this->globals->gSaveCppong(); }
        void load(void) { this->globals->gLoadCppong(); }

        void test();
        void sync(void);
};

#endif // CENTRALWIDGET_H
