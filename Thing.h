//
// Created by Teni on 10/9/2022.
//
#include "GeneralLibraries"

#ifndef _THING_H_
#define _THING_H_

    class Thing {
    protected:
    private:
        std::string name;
        std::string description;
    public:
        explicit Thing(std::string);
        explicit Thing();

        //Person owner;

        std::string getName();
        void setName(std::string newName);

        //Person getOwner();
        //void setOwner();

        //GPS_DD location;

        Thing();
        Thing(Person arg_owner);
        Json::Value dump2JSON();
    };
#endif