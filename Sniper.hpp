//
// Created by dor on 08/06/2020.
//

#ifndef WARGAME_A_SNIPER_HPP
#define WARGAME_A_SNIPER_HPP

#endif //WARGAME_A_SNIPER_HPP

#include "Soldier.hpp"
#include <iostream>


class Sniper:public Soldier{ ;
public:
    explicit Sniper(int player) : Soldier(player,100,50,2){}
    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> pos) override{
        int rowFrom=pos.first-1,rowTo=pos.second+1,colFrom=pos.first-1,colTo=pos.second+1,Eplayer;
        if(this->player==1) {Eplayer=2;}
        else                {Eplayer=1;}
        std::pair <int,int>  EnemySoldier; int maxHealth=0;
        for (int i = 0; i < board.size() ; ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if(board[i][j]!=nullptr &&
                board[i][j]->player==Eplayer &&
                board[i][j]->healthPoints > maxHealth){
                    EnemySoldier={i,j};
                }
            }
        }
        board[EnemySoldier.first][EnemySoldier.second]->healthPoints-=this->AttcakDamage;
        if(board[EnemySoldier.first][EnemySoldier.second]->healthPoints <= 0){
            board[EnemySoldier.first][EnemySoldier.second] = nullptr;
        }
    }
    void Heal () override { this->healthPoints =100; }


};