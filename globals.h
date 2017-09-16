#ifndef GLOBALS_H
#define GLOBALS_H
using namespace std;

#include <vector>
#include <string>
#include <QTimer>
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>

#include "gform.h"

class globals{
    public:
        globals();
        ~globals();

        //INSTANCES
        static globals* instance();

        //VARIABLES
        QTimer*         gTimer;
        QString         gName = "CPPong";
        QString         gClaim = "A cutting edge application";
        int             gColorSwitcherId;
        QTimer*         gSystemTimer;


        //FUNCTIONS
        void            increase_gDisplayFactor();
        void            decrease_gDisplayFactor();
        void            start_gTimer(int val);
        void            stop_gTimer();
        void            start_gSystemTimer(int val);
        void            stop_gSystemTimer();
        void            addForm_gForms(GForm form);
        void            populate_gForms();
        void            switchColor();
        void            gSaveCppong();
        void            gLoadCppong();

        //SETTER-FUNCTIONS
        void            set_gDebug(bool val);
        void            set_gRunning(bool val);
        void            set_gSystemTimer(QTimer *timer);
        void            set_gTimer(QTimer *timer);
        void            set_gForms(vector<GForm> forms);
        void            set_gApproximation(int val);
        void            set_gDisplayFactor(float val);

        //GETTER-FUNCTIONS
        bool            get_gDebug();
        bool            get_gRunning();
        vector<GForm>   get_gForms();
        QTimer*         get_gSystemTimer();
        QTimer*         get_gTimer();
        float           get_gDisplayFactor();
        bool            get_gColorSwitch();
        int             get_gApproximation();

        //MESSAGE-FUNCTIONS
        void            push_gMessage(string strg);             //direct use is deprecated, use log() instead!
        void            log(string strg, bool debug = true);
        queue<string>   get_gMessages();
        string          pop_gMessage();

    private:
        //VARIABLES
        bool            gDebug;
        bool            gRunning;
        float           gDisplayFactor;

        int             gFormCount;
        int             gApproximation;
        int             gRandom;
        int             gRandomMin;
        int             gRandomMax;
        bool            gColorSwitch;
        bool            gShowCollisonBoxes;

        string          gSaved;
        vector<GForm>   gForms;
        vector<int>     gField;
        queue<string>   gMessages;

        //FUNCTIONS
        int             assignId();
        int             random(int min, int max);
        string          getCurrentPath();
        string          getFilePath();
};

#endif // GLOBALS_H
