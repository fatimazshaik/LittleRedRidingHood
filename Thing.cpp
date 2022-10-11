//
// Created by Teni on 10/9/2022.
//
#include "Thing.h"

Thing::Thing() {
    this->name = "";
    this->description = "";
}

Thing::Thing(Person arg_owner) {
    this->name = "";
    this->description = "";
    this->owner = arg_owner;
}

Json::Value Thing::dump2JSON() {
    Json::Value result { };

    if (this->model != "")
    {
        result["name"] = this->name;
    }

    if (this->description != "")
    {
        result["description"] = this->description;
    }

    Json::Value jv_result;

    //jv_result = (this->owner).dump2JSON();
    //result["owner"] = jv_result;

    //jv_result = (this->location).dump2JSON();
    //result["location"] = jv_result;

    return result;
}