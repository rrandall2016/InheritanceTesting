/**
* @brief Assignment 4 Inheritance
* @name Randy Randall
*/
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <sstream>
using namespace std;

class Item
{
public:
    virtual string toString() const;

    Item(string itemName, int cost);
    string getName() const;
    int getValue() const;


private:
    string name;
    int value;
};



#endif // ITEM_H
