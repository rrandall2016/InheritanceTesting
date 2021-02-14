/**
* @brief Assignment 4 Inheritance
* @name Randy Randall
*/
#include "Item.h"
#include <sstream>

Item::Item(string itemName, int cost)
    : name(itemName), value(cost)
{

}
string Item::getName() const{
    return name;

}
int Item::getValue() const{
    return value;

}

string Item::toString() const
{
    stringstream descriptor;
    descriptor << getName()
               << " (value: " << getValue()
               << ")";

    return descriptor.str();
}

