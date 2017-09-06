#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H
//using namespace std;

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QtGui>

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

    private slots:
        void start(void);
        void stop(void);
        void minus(void);
        void plus(void);
        void test();
        void sync(void);
};

#endif // CENTRALWIDGET_H
