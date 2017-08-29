using namespace std;
#include <vector>
#include <QWidget>
#include <QTimer>
#include <QtGui>

#include "form.h"
#include "globalforms.h"

class canvas : public QWidget {

    public:
        canvas(QWidget *parent = 0);
        ~canvas();

        void start(void) { timer->start(10); running = 1; };
        void stop(void) { timer->stop(); running = 0; };

        //vector<Form> forms;

    private:
        QTimer *timer;
        int lastX;
        int lastY;
        int increment;
        //int phase;
        globalForms gForms;

    protected:
        void paintEvent(QPaintEvent *event);
};
