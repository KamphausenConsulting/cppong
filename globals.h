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
        static globals* instance();
        QTimer*         gTimer;

        QString         gName = "CPPong";
        QString         gClaim = "A cutting edge application";
        bool            get_gDebug();
        bool            get_gRunning();
        vector<GForm>   get_gForms();
        QTimer*         get_gSystemTimer();
        QTimer*         get_gTimer();
        float           get_gDisplayFactor();
        bool            get_gColorSwitch();
        int             get_gApproximation();

        void            set_gDebug(bool val);
        void            set_gRunning(bool val);
        void            set_gSystemTimer(QTimer *timer);
        void            set_gTimer(QTimer *timer);
        void            set_gForms(vector<GForm> forms);
        void            set_gApproximation(int val);

        void            increase_gDisplayFactor();
        void            decrease_gDisplayFactor();

        void            start_gTimer(int val);
        void            stop_gTimer();
        void            start_gSystemTimer(int val);
        void            stop_gSystemTimer();

        void            addForm_gForms(GForm form);
        void            populate_gForms();

        void            push_gMessage(string strg);
        queue<string>   get_gMessages();
        string          pop_gMessage();

        int             gColorSwitcherId;
        void            switchColor();
        QTimer*         gSystemTimer;

        void            gSaveCppong();
        void            gLoadCppong();

        void            log(string strg, bool debug = true);

    private:
        bool            gDebug;
        bool            gRunning;
        bool            gColorSwitch;
        bool            gShowCollisonBoxes;
        int             gRandom;
        int             gRandomMin;
        int             gRandomMax;
        float           gDisplayFactor;
        string          gSaved;
        vector<GForm>   gForms;
        int             gFormCount;
        int             gApproximation;
        vector<int>     gField;
        queue<string>   gMessages;
        int             assignId();
        int             random(int min, int max);
        string          getCurrentPath();
        string          getFilePath();
};

#endif // GLOBALS_H
