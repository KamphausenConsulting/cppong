// Qt5 add:
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QtGui>
#include <QTextEdit>

#include "canvas.h"
#include "global.h"

class meinWidget : public QWidget
{
    Q_OBJECT  // notwendig, da Slots enthalten sind

public:
    meinWidget(QWidget *parent = 0);
    QTextEdit *textbox;

private:
    canvas *meinZeichenFeld;
    char font[10] = "Helvetica";

private slots:
    void start(void);
    void stop(void);
    void minus(void);
    void plus(void);
};
