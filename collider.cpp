#include "collider.h"

Collider::Collider(){}

void Collider::collide(GForm &form, vector<GForm> forms){
    vector<int> m = form.getMovement();
    if(globals->get_gDebug()){
        //globals->push_gMessage("cppong: Collider::collide() called!");
    }
    if(leaveFieldV(form)){
        form.setMovement(m[0], -m[1]);
    }
    if(leaveFieldH(form)){
        switch (form.getType()) {
        case 1:
            form.setPosition(735,212);
            globals->gColorSwitcherId = NULL;
            break;
        default:
            form.setMovement(-m[0], m[1]);
            break;
        }
    }
    if(form.getType() == 1){
        if(detectCollision(form, forms)){
            form.setMovement(-m[0], m[1]);
            vector<int> current = form.getPosition();
            vector<int> mNew    = form.getMovement();

            form.setPosition(current[0]+mNew[0],current[1]+mNew[1]);
        }
        if(detectApproximation(form)){
            globals->switchColor();
        }
    }
    return;
}

bool Collider::leaveFieldV(GForm &form){
    if(form.getLocation()[1] < globals->get_gForms()[0].getLocation()[1] && form.getLocation()[7] < globals->get_gForms()[0].getLocation()[7]){
        if(globals->get_gDebug()){
            globals->push_gMessage("cppong: collision! (top)");
        }
        return true;
    } else if(form.getLocation()[7] > globals->get_gForms()[0].getLocation()[7] && form.getLocation()[1] > globals->get_gForms()[0].getLocation()[1]){
        if(globals->get_gDebug()){
            globals->push_gMessage("cppong: collision! (bot)");
        }
        return true;
    } else {
        return false;
    }
}

bool Collider::leaveFieldH(GForm &form){
    if(form.getLocation()[0] < globals->get_gForms()[0].getLocation()[0] && form.getLocation()[2] < globals->get_gForms()[0].getLocation()[2]){
        if(globals->get_gDebug()){
            globals->push_gMessage("cppong: collision! (left)");
        }
        return true;
    } else if(form.getLocation()[2] > globals->get_gForms()[0].getLocation()[2] && form.getLocation()[0] > globals->get_gForms()[0].getLocation()[0]){
        if(globals->get_gDebug()){
            globals->push_gMessage("cppong: collision! (right)");
        }
        return true;
    } else {
        return false;
    }
}

bool Collider::detectApproximation(GForm &form){
    int ap = globals->get_gApproximation();
    vector<GForm> targets = globals->get_gForms();
    for (unsigned i=0; i < targets.size(); i++) {
        GForm target = targets[i];
        if(target.getType()==-1 || target.getType()==1 || target.getId() == globals->gColorSwitcherId) continue;
        vector<int> formLoction = form.getLocation();
        vector<int> targetLocation   = target.getLocation();

        if (formLoction[0]-ap < targetLocation[4]+ap && formLoction[4]+ap > targetLocation[0]-ap &&
            formLoction[1]-ap < targetLocation[5]+ap && formLoction[5]+ap > targetLocation[1]-ap) {
            globals->gColorSwitcherId = target.getId();
            return true;
        }
    }
}

bool Collider::detectCollision(GForm &form, vector<GForm> forms){
    vector<GForm> targets = forms;
    for (unsigned i=0; i < targets.size(); i++) {
        GForm target = targets[i];
        if(target.getType()==-1 || target.getType()==1) continue;
        vector<int> formLoction = form.getLocation();
        vector<int> targetLocation   = target.getLocation();

        if (formLoction[0] < targetLocation[4] && formLoction[4] > targetLocation[0] &&
            formLoction[1] < targetLocation[5] && formLoction[5] > targetLocation[1]) return true;
    }
}







/*
bool Collider::detectCollision(GForm &form, vector<GForm> forms){
    vector<GForm> targets = forms;
    for (unsigned i=0; i < targets.size(); i++) {
        GForm target = targets[i];
        globals->push_gMessage("id" + to_string(form.getId()) + " check id" + to_string(target.getId()));
        if(form.getId() == target.getId() || target.getType() == -1 || (form.getType() == 0 && target.getType() == 0)){
            if(globals->get_gDebug()){
                //globals->push_gMessage("cppong: coll ignore");
            }
        } else {
            vector<int> formLoction = form.getLocation();
            vector<int> targetLocation   = target.getLocation();
            if((formLoction[6] < targetLocation[2] && formLoction[7] > targetLocation[3] && formLoction[1] < targetLocation[1])){
                if(globals->get_gDebug()){
                    globals->push_gMessage("cppong: 1!! id" + to_string(form.getId()) + " collided with id" + to_string(target.getId()));
                }
                return true;
            } if ((formLoction[0] < targetLocation[2] && formLoction[1] > targetLocation[3] && formLoction[7] < targetLocation[5] && formLoction[6] < targetLocation[4])){
                if(globals->get_gDebug()){
                    globals->push_gMessage("cppong: 2!! id" + to_string(form.getId()) + " collided with id" + to_string(target.getId()));
                }
                return true;
            } if ((formLoction[0] < targetLocation[4] && formLoction[1] < targetLocation[5]) && formLoction[4] > targetLocation[4]){
                if(globals->get_gDebug()){
                    globals->push_gMessage("cppong: 3!! id" + to_string(form.getId()) + " collided with id" + to_string(target.getId()));
                }
                return true;
            }
        }
    }
    return false;
}
*/

