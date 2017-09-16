#ifndef GFORM_H
#define GFORM_H
using namespace std;

#include <QtGui>
#include <vector>
#include <string>

class GForm{
    public:
        //FUNCTIONS
        GForm();
        ~GForm();
        void move();
        void updateLocation();
        void draw(QPainter &painter, float displayFactor, bool colorSwitch);
        void drawCollBox(QPainter &painter, float displayFactor, bool colorSwitch);
        void drawApproximationBox(QPainter &painter, int distance, float displayFactor, bool colorSwitch);

        //SETTER-FUNCTIONS
        void setPosition(int x, int y);                 //
        void setMovement(int x, int y);                 //
        void setSize(int w, int h);                     //
        void setType(char type[10]);                    //
        void setColor(int num, int r, int g, int b);    //
        void setId(int id);                             //

        //GETTER-FUNCTIONS
        vector<int> getPosition();                      //
        vector<int> getLocation();                      //
        vector<int> getMovement();                      //
        vector<int> getSize();                          //
        vector<int> getColor();                         //
        int getType();                                  //
        int getId();                                    //

    private:
        int id;
        int type        = 0;                                //border -1, rectangle = 0 or circle = 1
        int border      = 0;                                //border thickness
        char coll[2]    = "x";                              //collision direction
        vector<int> position = { 0, 0 };                    //position x, y
        vector<int> movement = { 0, 0 };                    //movement as vector x, y
        vector<int> size     = { 25, 25 };                  //width, height
        vector<int> color    = {0, 0, 0, 255, 255, 255 };   //RGB colors
        vector<int> location = {                            //coordinates to locate the forms extend
                                0, 0,                       //Ax, Ay - same as position!
                                0, 0,                       //Bx, By
                                0, 0,                       //Cx, Cy
                                0, 0,                       //Dx, Dy
                              };
        QBrush brush;
        QPen pen;
        QColor col;
};

#endif // GFORM_H
