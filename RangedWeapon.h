/**
* @brief Assignment 4 Inheritance
* @name Randy Randall
*/
#ifndef RANGEDWEAPON_H
#define RANGEDWEAPON_H
#include <string>
#include <sstream>
#include <Weapon.h>
using namespace std;

class RangedWeapon : public Weapon
{
public:
    RangedWeapon(string itemName, int damageValue, int rangeValue, int ammoValue, int cost);
    int getRange() const;
    int getAmmo() const;
    string toString() const;
    int use(int rangeToTarget);

private:
    int range;
    int ammo;
};





#endif // RANGEDWEAPON_H
