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
void Person::setLocation(GPS arg_location, JvTime arg_time){
    this->location = arg_location;
    this->since_when = arg_time;
}
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
JvTime Person::getLocationTime(){
    return this-> since_when;
}

//Dump Method
Json::Value //created empty lang
Person::dump2JSON
        (void)
{
    Json::Value result { }; //trigger constructor
    //empty json result

    if (this->name != "")
    {
        result["name"] = this->name;
    }

    if (this->type != "")
    {
        result["type"] = this->type;
    }

    if (this->isHealthy != null)
    {
        result["isHealthy"] = this->isHealthy;
    }

    Json::Value jv_result;  //empty JSON::Value

    jv_result = (this->home).dump2JSON();
    result["home"] = jv_result;

    jv_result = (this->location).dump2JSON();
    result["location"] = jv_result;

    jv_result = (this->since_when).dump2JSON();
    result["since_when"] = jv_result;

    std::cout << jv_result.toStyledString() << std::endl;

    return result;
}
//}