/**
* @brief Assignment 4 Inheritance
* @name Randy Randall
*/
#ifndef ARMOR_H
#define ARMOR_H
#include <string>
#include <sstream>
#include<Item.h>
using namespace std;

#include "Item.h"

class Armor: public Item
{
public:
    Armor(string itemName, int protectionValue, int cost);
    int getProtection() const;
    string toString() const;

private:
    int protection;
};



#endif // ARMOR_H
