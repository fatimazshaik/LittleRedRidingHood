#include <iostream>
#include "Person.h"
#include "GPS.h"
#include "JvTime.h"
#include "Thing.h"
#include "Record.h"

int main() {
    GPS LittleRedHouse = GPS ("Red's and her Mother's House", "Village");
    Person LittleRedRidingHood = Person("Little Red Riding Hood", LittleRedHouse);
    LittleRedRidingHood.setLocation(LittleRedHouse, *getNowJvTime());
    Thing Cap = Thing("Cap", "a head covering");
    Cap.setOwner(LittleRedRidingHood);
    Record First = Record(Cap, LittleRedRidingHood, LittleRedHouse, *getNowJvTime());
    std::cout << (First.dump2JSON()).toStyledString() << std::endl;



}
