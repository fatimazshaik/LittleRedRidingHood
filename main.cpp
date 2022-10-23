//
// Created by Fatima Shaik on 10/9/22.
// main file which creates/prints all the Records

#include <iostream>
#include "Person.h"
#include "GPS.h"
#include "JvTime.h"
#include "Thing.h"
#include "Record.h"

int main() {
    GPS LittleRedHouse = GPS ("Red's and her Mother's House", "Village", 0.0);
    Person LittleRedRidingHood = Person("Little Red Riding Hood", LittleRedHouse);
    LittleRedRidingHood.setLocation(LittleRedHouse, *getNowJvTime());
    Thing Cap = Thing("Cap", "a head covering");
    Cap.setOwner(LittleRedRidingHood);
    //First Record: Little Red Ridding Hood wore the Cap.
    Record First = Record(Cap, LittleRedRidingHood, LittleRedHouse, *getNowJvTime());
    std::cout << (First.dump2JSON()).toStyledString() << std::endl;

    Thing Cake = Thing("Cake", "a sweet desert");
    Thing Wine = Thing("Wine", "a drink");
    Person Mother = Person("Mother", LittleRedHouse);
    LittleRedRidingHood.setLocation(LittleRedHouse, *getNowJvTime());
    Cake.setOwner(LittleRedRidingHood);
    Wine.setOwner(LittleRedRidingHood);
    //Second Record: Her mom gave her the cake and wine.
    Record Second = Record(Cake, Wine, LittleRedRidingHood, Mother, LittleRedHouse, *getNowJvTime());
//    std::cout << (Second.dump2JSON()).toStyledString() << std::endl;

    GPS meetingSpot = GPS ("entrance of the woods", "Woods");
    GPS wolfHome = GPS("Somewhere in woods", "Woods");
    Person Wolf = Person("Wolf", wolfHome);
    LittleRedRidingHood.setLocation(meetingSpot, *getNowJvTime());
    Wolf.setLocation(meetingSpot, *getNowJvTime());
    //Third Record: Little Red met the wolf at a particular spot in the wood
    Record Third = Record (LittleRedRidingHood, Wolf, meetingSpot, *getNowJvTime());
//    std::cout << (Third.dump2JSON()).toStyledString() << std::endl;

    GPS grandmotherHouse = GPS("Grandma's house", "end of Woods", "three large oak", 0.5);
    Person Grandma = Person("Grandma", grandmotherHouse);
    Grandma.setLocation(grandmotherHouse, *getNowJvTime());
    //Fourth Record: Grandma was at her own home right outside of the wood and there were three large oak trees nearby
    Record Fourth = Record(Grandma, grandmotherHouse, *getNowJvTime());
//    std::cout << (Fourth.dump2JSON()).toStyledString() << std::endl;


}
