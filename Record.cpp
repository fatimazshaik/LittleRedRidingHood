//
// Created by Fatima Shaik on 10/17/22.
//

#include "Record.h"

//Blank Person:
Person blankPerson = Person();

Record::Record(Thing item1, Person person1, GPS loc, JvTime time){
    this->thingOne = item1;
    this->personOne = person1;
    this->location = loc;
    this->time = time;
}


Record::Record(Thing item1, Thing item2, Person person1, Person person2, GPS loc, JvTime time){
    this->thingOne = item1;
    this->thingTwo = item2;
    this->personOne = person1;
    this->personTwo = person2;
    this->location = loc;
    this->time = time;
    }

Record::Record(Person person1, Person person2, GPS loc, JvTime time){
    this->personOne = person1;
    this->personTwo = person2;
    this->location = loc;
    this->time = time;
}

Record::Record( Person person1, GPS loc, JvTime time){
    this->personOne = person1;
    this->location = loc;
    this->time = time;
}



Record::Record(){
    this->thingOne = Thing{};
    this->thingTwo = Thing{};
    this->personOne = Person{};
    this->personTwo = Person{};
    this->location = GPS{};
    this->time = JvTime{};
}


Json::Value Record::dump2JSON() {
    Json::Value result;
    Json::Value jv_result;

    if (!(thingOne.isBlankThing())) {
        jv_result = (this->thingOne).dump2JSON();
        result["thingOne"] = jv_result;
    }

    if (!(thingTwo.isBlankThing())) {
        jv_result = (this->thingTwo).dump2JSON();
        result["thingTwo"] = jv_result;
    }

    if (!(personOne.isBlankPerson())) {
        jv_result = (this->personOne).dump2JSON();
        result["personOne"] = jv_result;
    }

    if (!(personTwo.isBlankPerson())) {
        jv_result = (this->personTwo).dump2JSON();
        result["personTwo"] = jv_result;
    }

    if (location.getName() != " ") {
        jv_result = (this->location).dump2JSON();
        result["location"] = jv_result;
    }

    jv_result = (this->time).dump2JSON();
    result["time"] = jv_result;

    std::cout << jv_result.toStyledString() << std::endl;
    return result;
}
