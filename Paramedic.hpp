//
// Created by dor on 08/06/2020.
//

#ifndef WARGAME_A_PARAMEDIC_HPP
#define WARGAME_A_PARAMEDIC_HPP

#endif //WARGAME_A_PARAMEDIC_HPP
#include "Soldier.hpp"
#include <iostream>

class Paramedic:public Soldier{ ;
public:
    explicit Paramedic(int player) : Soldier(player,100,0,4){}

    void recoverSoldier(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> pos) {
       int rowFrom=pos.first-1,rowTo=pos.second+1,colFrom=pos.first-1,colTo=pos.second+1;
        for (int i = rowFrom; i <rowTo ; ++i) {
            for (int j = colFrom; j <colTo ; ++j) {
                std::pair <int,int> check = {i,j};
                if(pos_validator(check,board)){
                    Soldier* Psoldier= board[i][j];
                    if(Psoldier!= nullptr && Psoldier->player==player){
                        Psoldier->Heal();
                    }
                }
            }
        }
    }

    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> pos) override{
            recoverSoldier(board,pos);
        }

    static bool pos_validator(std::pair<int,int> pos , std::vector<std::vector<Soldier*>> &board){
        return pos.first < board.size()  || pos.first  > 0 ||
               pos.second < board.size() || pos.second > 0 ;
    }
    void Heal () override { this->healthPoints =100; }
};