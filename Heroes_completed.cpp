//This file implement the output function and constructor in Heroes.h.
//You cannot modify this file.
#include <iostream>
#include "Heroes.h"
#include <math.h>
using namespace std;

Hero::Hero(int location_, int direction_)
    : hp(100)
    , mp(100)
    , atk(20)
    , def(10)
    , spd(5)
    , remain_exp(100)
    , location(location_)
    , direction(direction_)
{
}

Hero::Hero(const Hero& hero)
    : hp(hero.hp)
    , mp(hero.mp)
    , atk(hero.atk)
    , def(hero.def)
    , spd(hero.spd)
    , remain_exp(hero.remain_exp)
    , location(hero.location)
    , direction(hero.direction)
{
}

int Hero::get_location() const
{
    return location;
}

bool Hero::is_dead()
{
    return hp <= 0;
}

void Hero::action(Hero* hero)
{
    move(hero);
    attack(hero);
}

void Hero::print()
{
    cout << "I am a fresh hero!" << endl
         << "hp: " << hp << ", mp: " << mp << ", atk: " << atk << ", def: " << def
         << ", spd: " << spd << ", location: " << location << ", remain_exp: " << remain_exp
         << endl;
}

Warrior::Warrior(const Warrior& hero)
    : Hero(hero)
    , armor(hero.armor)
{
}

Warrior::Warrior(const Hero& hero)
    : Hero(hero)
    , armor(30)
{
    def += 10;
    remain_exp = 100;
}

void Warrior::print()
{
    cout << "I am a warrior!" << endl
         << "hp: " << hp << ", mp: " << mp << ", atk: " << atk << ", def: " << def
         << ", spd: " << spd << ", armor: " << armor << ", location: " << location
         << ", remain_exp: " << remain_exp << endl;
}

Knight::Knight(const Warrior& hero)
    : Warrior(hero)
{
    armor = 40;
    spd += 5;
    atk += 10;
}

void Knight::print()
{
    cout << "I am a knight!" << endl
         << "hp: " << hp << ", mp: " << mp << ", atk: " << atk << ", def: " << def
         << ", spd: " << spd << ", armor: " << armor << ", location: " << location
         << ", remain_exp: " << remain_exp << endl;
}

Berserker::Berserker(const Warrior& hero)
    : Warrior(hero)
{
    armor = 20;
    atk += 5;
}

void Berserker::print()
{
    cout << "I am a berserker!" << endl
         << "hp: " << hp << ", mp: " << mp << ", atk: " << atk << ", def: " << def
         << ", spd: " << spd << ", armor: " << armor << ", location: " << location
         << ", remain_exp: " << remain_exp << endl;
}

Mage::Mage(const Mage& hero)
    : Hero(hero)
    , wand(hero.wand)
{
}

Mage::Mage(const Hero& hero)
    : Hero(hero)
    , wand(30)
{
    atk += 10;
    remain_exp = 100;
}

void Mage::print()
{
    cout << "I am a mage!" << endl
         << "hp: " << hp << ", mp: " << mp << ", atk: " << atk << ", def: " << def
         << ", spd: " << spd << ", wand: " << wand << ", location: " << location
         << ", remain_exp: " << remain_exp << endl;
}

Magician::Magician(const Mage& hero)
    : Mage(hero)
{
    wand = 40;
    atk += 10;
}

void Magician::print()
{
    cout << "I am a magician!" << endl
         << "hp: " << hp << ", mp: " << mp << ", atk: " << atk << ", def: " << def
         << ", spd: " << spd << ", wand: " << wand << ", location: " << location
         << ", remain_exp: " << remain_exp << endl;
}

Healer::Healer(const Mage& hero)
    : Mage(hero)
{
    wand = 60;
    mp += 20;
    atk -= 10;
}

void Healer::print()
{
    cout << "I am a healer!" << endl
         << "hp: " << hp << ", mp: " << mp << ", atk: " << atk << ", def: " << def
         << ", spd: " << spd << ", wand: " << wand << ", location: " << location
         << ", remain_exp: " << remain_exp << endl;
}
