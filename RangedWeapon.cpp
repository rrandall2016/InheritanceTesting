/**
* @brief Assignment 4 Inheritance
* @name Randy Randall
*/
#include "RangedWeapon.h"
#include <string>
#include <sstream>
#include <Weapon.h>
using namespace std;

RangedWeapon::RangedWeapon(string itemName, int damageValue, int rangeValue, int ammoValue, int cost)
    :Weapon(itemName, damageValue, cost)
{
    range = rangeValue;
    ammo = ammoValue;

}
int RangedWeapon::getRange() const{
    return range;
}
int RangedWeapon::getAmmo() const{
    return ammo;
}
int RangedWeapon::use(int rangeToTarget){
    if(ammo > 0)
        ammo--;
    if(rangeToTarget > range || ammo <= 0)
        return 0;

    return getDamage();
}

string RangedWeapon::toString() const
{
    stringstream descriptor;
    descriptor << getName()
               << " (value: " << getValue()
               << ") Damage: "
               << getDamage()
               << " Ammo: " << getAmmo()
               << " Range: " << getRange();


    return descriptor.str();
}

