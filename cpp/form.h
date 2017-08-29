#ifndef FORM_H
#define FORM_H
using namespace std;

#include <QtGui>
#include <vector>
#include "global.h"

class Form {
    public:
        Form();
        ~Form();
        //char title[10]  = "";
        int position[2] = { 25, 25 };                   //position x, y
        int movement[2] = { 0, 0 };                     //movement as vector x, y
        int size[2]     = { 25, 25 };                   //width, height
        int color[6]    = {0, 0, 0, 255, 255, 255 };    //RGB colors
        int type        = 0;                            //border -1, rectangle = 0 or circle = 1
        int border      = 0;                            //border thickness
        char coll[2]    = "x";                          //collision direction
        vector<int> location = {                     //coordinates to locate the forms extend
                                    0, 0,               //Ax, Ay - same as position!
                                    0, 0,               //Bx, By
                                    0, 0,               //Cx, Cy
                                    0, 0,               //Dx, Dy
                                  };

        void draw(QPainter &painter);                   //draws form by given painter
        void drawSmall(QPainter &painter);              //draws form by given painter & divides all values by 4
        void move();                                    //calculates movement
        void setPosition(int x, int y);                 //
        void setMovement(int x, int y);                 //
        void setSize(int w, int h);                     //
        void setType(char type[10]);                    //
        void setColor(int num, int r, int g, int b);    //

        void calcFormLocationCoordinates();             //calculates the forms extend and updates location[]
    private:
         QBrush brush;
};

#endif // FORM_H
