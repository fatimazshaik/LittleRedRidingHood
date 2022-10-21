//
// Created by Teni on 10/9/2022.
//
#include "GeneralLibraries"

#ifndef _THING_H_
#define _THING_H_

    class Thing {
    private:
        std::string name;
        std::string description;
        Person owner;
        GPS location;

    public:
        explicit Thing();
        explicit Thing(std::string);
        explicit Thing(std::string, std::string);
        explicit Thing(Person);

        std::string getName();
        void setName(std::string newName);
        std::string getDescription();
        void setName(std::string newDescription);
        Person getOwner();
        void setOwner(Person newOwner);
        GPS getLocation();
        void setLocation(std::string newLocation);

        bool Thing::isBlankThing()
        Json::Value dump2JSON();
    };
#endif