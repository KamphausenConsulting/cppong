#ifndef COLLIDER_H
#define COLLIDER_H

#include "gform.h"
#include "globals.h"

class Collider{
    public:
        Collider();
        void collide(GForm &form, vector<GForm> forms);
    private:
        globals* globals = globals->instance();
        bool leaveFieldV(GForm &form);
        bool leaveFieldH(GForm &form);
        bool detectApproximation(GForm &form);
        bool detectCollision(GForm &form, vector<GForm> forms);
};

#endif // COLLIDER_H
