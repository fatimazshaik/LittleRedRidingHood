//
// Created by Fatima Shaik on 10/9/22.
//

#include "Person.h"
//Constructors:
Person::Person(std::string arg_name, std::string arg_type, GPS arg_home, bool arg_health){
    this->name =arg_name;
    this->home = arg_home;
    this->type = arg_type;
    this->isHealthy = arg_health;
}
Person::Person(){
    this->name = "";
    this->home = GPS{};
    this->type = "";
    this->isHealthy = false;
}

//Setter Methods (Members)
void Person::setHome(GPS arg_home){
    this->home = arg_home;
}
//void Person::setLocation(GPS arg_location, JvTime arg_time){
//    this->location = arg_location;
//    this->since_when = arg_time;
//}
void Person::setHealth(bool arg_health){
    this->isHealthy = arg_health;
}
//Getter Methods (Members)
bool Person::getIsHealthy(){
    return this->isHealthy;
}
std::string Person::getName(){
    return this->name;
}
std::string Person::getType(){
    return this->type;
}
GPS Person::getHome(){
    return this->home;
}
GPS Person::getLocation(){
    return this->location;
}
//Do later:
//JvTime Person::getLocationTime(){
//    return this-> since_when;
//}
//Dump Method
//Json::Value Person::dump2JSON(){
//
//}