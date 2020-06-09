//
// Created by dor on 08/06/2020.
//

#ifndef WARGAME_A_SNIPERCOMMANDER_HPP
#define WARGAME_A_SNIPERCOMMANDER_HPP

#endif //WARGAME_A_SNIPERCOMMANDER_HPP

#include "Soldier.hpp"
#include <iostream>


class SniperCommander:public Soldier{ ;
public:
    explicit SniperCommander(int player) : Soldier(player,120,100,3){}

    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> pos) override{
        int Eplayer;
        if(this->player==0) {Eplayer=1;}
        else                {Eplayer=0;}
        std::pair <int,int>  EnemySoldier; int maxHealth=0;
        for (int i = 0; i < board.size() ; ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if(board[i][j]!=nullptr &&
                board[i][j]->player==this->player &&
                board[i][j]->SoldierType==2){

                    std::pair <int,int> sniper= {i,j};
                    board[i][j]->attack(board,sniper);
                }

                if(board[i][j]!=nullptr &&
                   board[i][j]->player==Eplayer &&
                   board[i][j]->healthPoints > maxHealth){EnemySoldier={i,j};}
            }
        }
        board[EnemySoldier.first][EnemySoldier.second]->healthPoints-=this->AttcakDamage;
        if(board[EnemySoldier.first][EnemySoldier.second]->healthPoints <= 0){
            board[EnemySoldier.first][EnemySoldier.second] = nullptr;
        }
    }
    void Heal () override { this->healthPoints =120; }

};