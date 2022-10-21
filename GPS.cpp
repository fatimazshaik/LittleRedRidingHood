//
// Created by Fatima Shaik on 10/9/22.
//

#include "GPS.h"
GPS::GPS(){
    this->name = "";
    this->locatedIn = "";
    this->landmarks = "";
    this->leagues = 0;
}
GPS::GPS(std::string arg_name, std::string arg_locatedIn, std::string arg_landmarks, double arg_leagues){
    this->name = arg_name;
    this->locatedIn = arg_locatedIn;
    this->landmarks = arg_landmarks;
    this->leagues = arg_leagues;
}

GPS::GPS(std::string arg_name, std::string arg_locatedIn){
    this->name = arg_name;
    this->locatedIn = arg_locatedIn;
    this->leagues = 0.0;
}

GPS::GPS(std::string arg_name, std::string arg_landmarks, double arg_leagues){
    this->name = arg_name;
    this->landmarks = arg_landmarks;
    this->leagues = arg_leagues;
}

std::string GPS::getName(){
    return this->name;
}
std::string GPS::getLocatedIn(){
    return this->locatedIn;
}
std::string GPS::getLandmarks(){
    return this->landmarks;
}
double GPS::getLeagues(){
    return this->leagues;
}
double GPS::distance(GPS another){
    return (this->leagues - another.getLeagues());
}
Json::Value GPS::dump2JSON
        () {
    Json::Value result;
    if (this->name  != "") {
        result["name"] = this->name;
    }

    if (this->locatedIn  != "") {
        result["locatedIn"] = this->locatedIn;
    }
    if (this->landmarks  != "") {
        result["landmarks"] = this->landmarks;
    }
    if (this->leagues != 0.0) {
        result["leagues"] = this->leagues;
    }
    return result;
}