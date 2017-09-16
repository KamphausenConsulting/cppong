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

namespace Ui {
    class CentralWidget;
}

class CentralWidget : public QWidget {
    Q_OBJECT

    public:
        explicit CentralWidget(QWidget *parent = 0);
        //~CentralWidget();

    private:
        Ui::CentralWidget *ui;
        Canvas *MainCanvas;
        QTextEdit *textbox;
        globals* globals = globals->instance();
        char font[10] = "Helvetica";
        QPushButton *debugButton;
        QLabel *labelDisplayFactor;

    private slots:
        void start(void);
        void stop(void);
        void minus(void);
        void plus(void);
        void test();
        void sync(void);
        void debugSwitch(void);
        void save(void) { this->globals->gSaveCppong(); }
        void load(void) { this->globals->gLoadCppong(); }
};

#endif // CENTRALWIDGET_H
