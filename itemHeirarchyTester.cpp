/**
* @brief Assignment 4 Inheritance
* @name Randy Randall
*/
/**
  Runs tests on everything but Character
  */

//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include <iostream>
using namespace std;

#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "RangedWeapon.h"


TEST_CASE( "Item" ) {
    cout << "Running Item Basics..." << endl;
    Item treasure("Diamond", 500);

    CHECK(treasure.getName() == "Diamond");
    CHECK(treasure.getValue() == 500);
    CHECK(treasure.toString() == "Diamond (value: 500)");

    Item treasure2("Lump of coal", 1);

    CHECK(treasure2.getName() == "Lump of coal");
    CHECK(treasure2.getValue() == 1);
    CHECK(treasure2.toString() == "Lump of coal (value: 1)");
}

TEST_CASE( "Armor" ) {
    cout << "Running Armor Basics..." << endl;
    Armor a("Leather pants", 2, 10);


    CHECK(a.getProtection() == 2);
    CHECK(a.getName() == "Leather pants");
    CHECK(a.getValue() == 10);
    CHECK(a.toString() == "Leather pants (value: 10) Protection: 2");

    Armor a2("Tinfoil hat", 1, 5);
    CHECK(a2.getProtection() == 1);
    CHECK(a2.getValue() == 5);
    CHECK(a2.getName() == "Tinfoil hat");
}


TEST_CASE( "Armor as item" ) {
    cout << "Running Armor as Item..." << endl;
    Armor a("Mail vest", 4, 40);
    Item* iptr = &a;



    CHECK(iptr->getName() == "Mail vest");
    CHECK(iptr->getValue() == 40);
    //Make sure we get most appropriate version of toString
    CHECK(iptr->toString() == "Mail vest (value: 40) Protection: 4");
}


TEST_CASE( "Weapon" ) {
    cout << "Running Weapon Basics..." << endl;
    Weapon w("Sword", 5, 10);

    CHECK(w.getRange() == 0);
    CHECK(w.getDamage() == 5);
    CHECK(w.getName() == "Sword");
    CHECK(w.getValue() == 10);
    CHECK(w.toString() == "Sword (value: 10) Damage: 5");

    Weapon w2("Butter knife", 1, 1);
    CHECK(w2.getDamage() == 1);
    CHECK(w2.getValue() == 1);
    CHECK(w2.getName() == "Butter knife");

    //Using w2 at 0 range gives damage of 1
    //Using at longer range results in no damage
    CHECK(w2.use(0) == 1);
    CHECK(w2.use(2) == 0);
}


TEST_CASE( "Weapon as Item" ) {
    cout << "Running Weapon as Item..." << endl;
    Weapon w("Mace", 4, 20);
    Item* iptr = &w;

    CHECK(iptr->getName() == "Mace");
    CHECK(iptr->getValue() == 20);
    CHECK(iptr->toString() == "Mace (value: 20) Damage: 4");
}


TEST_CASE( "RangedWeapon Basics" ) {
    cout << "Running RangedWeapon Basics..." << endl;
    RangedWeapon w("Bow", 3, 10, 20, 30);
    //int new2 = w.use(10);
    string new3 = w.toString();

    CHECK(w.getDamage() == 3);
    CHECK(w.getRange() == 10);
    CHECK(w.getAmmo() == 20);
    CHECK(w.getName() == "Bow");
    CHECK(w.getValue() == 30);
    CHECK(w.toString() == "Bow (value: 30) Damage: 3 Ammo: 20 Range: 10");

    //Using w at 10 or less range gives damage of 3
    //Using at range > 10 gives no damage

    CHECK(w.use(10) == 3);
    CHECK(w.getAmmo() == 19);
    CHECK(w.use(11) == 0);
    CHECK(w.getAmmo() == 18);


    RangedWeapon w2("Throwing knife", 1, 3, 2, 5);
    CHECK(w2.getDamage() == 1);
    CHECK(w2.getRange() == 3);
    CHECK(w2.getAmmo() == 2);
}

TEST_CASE( "RangedWeapon Ammo" ) {
    RangedWeapon w2("Throwing knife", 1, 3, 2, 5);
    CHECK(w2.getAmmo() == 2);

    w2.use(0);
    CHECK(w2.getAmmo() == 1);

    w2.use(0);
    CHECK(w2.getAmmo() == 0);

    //Check that future attacks do no damage and use no ammo
    CHECK(w2.use(0) == 0);
    CHECK(w2.getAmmo() == 0);
}

TEST_CASE( "RangedWeapon as Item" ) {
    cout << "Running RangedWeapon as Item..." << endl;
    RangedWeapon w("Bow", 3, 10, 20, 30);
    Item* iptr = &w;


    CHECK(iptr->getName() == "Bow");
    CHECK(iptr->getValue() == 30);
    CHECK(iptr->toString() == "Bow (value: 30) Damage: 3 Ammo: 20 Range: 10");
}

TEST_CASE( "RangedWeapon as Weapon" ) {
    cout << "Running RangedWeapon as Weapon..." << endl;
    RangedWeapon w("Bow", 3, 10, 20, 30);
    Weapon* wptr = &w;


    CHECK(wptr->getRange() == 10);
    CHECK(wptr->getDamage() == 3);

    //Make sure we access the correct version of use
    CHECK(wptr->use(4) == 3);
}

TEST_CASE( "Character equip weapons" ) {
    cout << "Running Character equip weapons..." << endl;

    Character c("Link");
    Weapon w("Mace", 4, 20);
    c.aquire(&w);
    c.equip(0); //know that the mace is in slot 0

    Weapon* wptr = c.getWeapon();
    CHECK(wptr->getName() == "Mace");


    RangedWeapon w2("Bow", 3, 10, 20, 30);
    c.aquire(&w2);
    c.equip(1); //know that the bow is in slot 1

    Weapon* wptr2 = &w2;
    CHECK(wptr2->getName() == "Bow");
    CHECK(wptr2->getRange() == 10);
}

TEST_CASE( "Character equip armor" ) {
    cout << "Running Character equip armor..." << endl;

    Character c("Link");

    Armor a("Mail vest", 4, 40);
    c.aquire(&a);
    c.equip(0); //know that the mail is in slot 0

    Armor* aptr = c.getArmor();
    CHECK(aptr->getName() == "Mail vest");
}

TEST_CASE( "Character equip invalid" ) {
    cout << "Running Character equip invalid..." << endl;

    Character c("Link");

    Item i("Silver vase", 50);
    c.aquire(&i);
    c.equip(0); //know that the vase is in slot 0, nothing should happen if we try to equip

    c.equip(1); //know that 1 is null, nothing should happen if we try to equip

    //Verify armor and weapon did not change
    Weapon* wptr = c.getWeapon();
    CHECK(wptr->getName() == "Bare Hands");

    Armor* aptr = c.getArmor();
    CHECK(aptr->getName() == "Skin");
}



