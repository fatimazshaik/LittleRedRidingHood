//
// Created by Fatima Shaik on 10/9/22.
//

#ifndef UHW_2_PERSON_H
#define UHW_2_PERSON_H

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>

// for Json::value
//#include <json/json.h>
//#include <json/reader.h>
//#include <json/writer.h>
//#include <json/value.h>

#include "GPS.h"


class Person {
private:
    bool isHealthy;
    std::string name;
    //is creature, girl, boy, adult, elderly, ect.
    std::string type;
    GPS home;
    GPS location;
    JvTime since_when;
public:
    //Constructors:
    Person(std::string, std::string, GPS, bool);
    Person();

    //Setter Methods (Members)
    void setHome(GPS);
//    void setLocation(GPS, JvTime);
    void setHealth(bool);

    //Getter Methods (Members)
    bool getIsHealthy();
    std::string getName();
    std::string getType();
    GPS getHome();
    GPS getLocation();
    JvTime getLocationTime();
    void setLocation(GPS , JvTime);

    //Dump Method
    Json::Value dump2JSON();
};


#endif //UHW_2_PERSON_H
