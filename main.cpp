#include <iostream>
#include "Person.h"
#include "GPS.h"
#include "JvTime.h"
#include "Thing.h"
#include "Record.h"

int main() {
    // Creates a GPS object for Little Red Riding Hood's House
    GPS LittleRedHouse = GPS ("Red's and her Mother's House", "Village");
    
    // Creates a person object for Little Red Riding Hood
    Person LittleRedRidingHood = Person("Little Red Riding Hood", LittleRedHouse);
    
    //Sets the time and location for little red riding hood
    LittleRedRidingHood.setLocation(LittleRedHouse, *getNowJvTime());
    
    //Sets a thing object for a cap
    Thing Cap = Thing("Cap", "a head covering");
    
    //Sets Little Red Riding Hood as the Cap's owner
    Cap.setOwner(LittleRedRidingHood);
    
    //Creates a record of the following situation: Little Red Ridding Hood wore the Cap
    Record First = Record(Cap, LittleRedRidingHood, LittleRedHouse, *getNowJvTime());
    
    //Writes out the record in JSON
    std::cout << (First.dump2JSON()).toStyledString() << std::endl;



}
