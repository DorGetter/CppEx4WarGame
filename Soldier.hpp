//
// Created by dor on 07/06/2020.
//
#pragma 1
#ifndef WARGAME_A_SOLDIER_HPP
#define WARGAME_A_SOLDIER_HPP

#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sys/param.h>

class Soldier {
public:
    uint player;
    int healthPoints;
    int AttcakDamage;
    int SoldierType ;
    /*
     *type|     number          *
     * **************************
     * 0  | FootSoldier         |
     * 1  | FootCommander       |
     * 2  | Sniper              |
     * 3  | SniperCommander     |
     * 4  | Paramedic           |
     * 5  | ParamedicCommander  |
     * **************************
     */

    Soldier(int player, int healthPoints, int AttcakDamage,int SoldierType):
    player(player),
    healthPoints(healthPoints),
    AttcakDamage(AttcakDamage),
    SoldierType(SoldierType)  {}
    virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)=0;
    virtual void Heal() = 0;
    virtual ~Soldier()= default;;
};


#endif //WARGAME_A_SOLDIER_HPP
