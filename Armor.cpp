/**
* @brief Assignment 4 Inheritance
* @name Randy Randall
*/
#include "Armor.h"


Armor::Armor(string itemName, int protectionValue, int cost)
    :Item(itemName, cost)
{
    protection = protectionValue;
}
int Armor::getProtection() const{
    return protection;
}
string Armor::toString() const
{
    stringstream descriptor;
    descriptor << getName()
               << " (value: " << getValue()
               << ") Protection: "
               << getProtection();

    return descriptor.str();
}
