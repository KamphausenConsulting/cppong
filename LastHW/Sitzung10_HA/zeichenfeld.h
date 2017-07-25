#include <vector>
using namespace std;
#include <QWidget>
#include <QTimer>


class zeichenFeld : public QWidget
{
public:
    zeichenFeld(QWidget *parent = 0);
    ~zeichenFeld();

    enum drawType { square, circle };

    void start(void) { timer->start(10); increment=1; };
    void stop(void) { timer->stop(); increment=0; };
    void newObject(); //newObject deklarieren - noch nicht impementieren

    vector<struct meinKreis *> kreise;

   //wir brauchen Initialwert zum Verschieben?

private:
    QTimer *timer;
    int lastX;
    int lastY;
    int increment;
    //int phase;

protected:
    void paintEvent(QPaintEvent *event);
};

//wir brauchen noch "Liste" von allen Kreisen
struct meinKreis { //bezieht sich auf einen Kreis
    int x, y;
    int verschiebung;
    // ?? phase
    int phase;
};
