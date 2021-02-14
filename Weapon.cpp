/**
* @brief Assignment 4 Inheritance
* @name Randy Randall
*/
#include "Weapon.h"
#include <string>
#include <sstream>
#include<Item.h>
using namespace std;

Weapon::Weapon(string itemName, int damageValue, int cost)
    :Item(itemName, cost)
{
    damage = damageValue;
}
int Weapon::getDamage() const{
    return damage;
}
int Weapon::getRange() const{
    return 0;
}
int Weapon::use(int rangeToTarget){
    if(rangeToTarget > 0)
        damage = 0;

    return damage;
}
string Weapon::toString() const
{
    stringstream descriptor;
    descriptor << getName()
               << " (value: " << getValue()
               << ") Damage: "
               << getDamage();

    return descriptor.str();
}



