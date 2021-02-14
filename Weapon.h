/**
* @brief Assignment 4 Inheritance
* @name Randy Randall
*/
#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <sstream>
#include<Item.h>
using namespace std;

class Weapon : public Item
{
public:
    Weapon(string itemName, int damageValue, int cost);
    int getDamage() const;
    virtual int getRange() const;
    string toString() const;
    virtual int use(int rangeToTarget);

protected:
    int damage;
};



#endif // WEAPON_H
