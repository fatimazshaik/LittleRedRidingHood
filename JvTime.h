//
// Created by Teni on 10/10/2022.
//
#include "GeneralLibraries"

#ifndef HW2_TIME_H
#define HW2_TIME_H
    class JvTime {
    public:
        bool validTimeFormat;
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
        int tail4;
        JvTime(const char *);
        JvTime();
        struct std::tm * getStdTM();
        int setStdTM(struct std::tm *);
        std::string * getTimeString();
        Json::Value dump2JSON();
    };

    JvTime getTime(void);
#endif //HW2_TIME_H
