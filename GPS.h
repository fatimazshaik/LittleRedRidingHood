//
// Created by Fatima Shaik on 10/9/22.
//

#ifndef UHW_2_GPS_H
#define UHW_2_GPS_H

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>

// for Json::value
//#include <json/json.h>
//#include <json/reader.h>
//#include <json/writer.h>
//#include <json/value.h>


class GPS {
private:
    std::string name;
    //woods, village
    std::string locatedIn;
    std::string landmarks;
    double leagues;

public:
    explicit GPS();
    explicit GPS(std::string, std::string, std::string, double);
    std::string getName();
    std::string getLocatedIn();
    std::string getLandmarks();
    double getLeagues();
    double distance(GPS);
    Json::Value dump2JSON();
};


#endif //UHW_2_GPS_H
