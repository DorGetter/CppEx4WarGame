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
        for (int i = pos.first-1; i < pos.first+2 ; ++i) {
            for (int j =pos.second-1 ; j < pos.second+2 ; ++j) {

                Soldier*s = NeedHelp({i,j},board,this->player);
                if(s==this){ continue;}
                else if(s != nullptr){ s->Heal(); }
            }
        }
    }

    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> pos) override{
            recoverSoldier(board,pos);
        }
    static Soldier* NeedHelp(std::pair<int,int> pos , std::vector<std::vector<Soldier*>> &board ,int player){
        if(pos_validator(pos,board)){
            Soldier* Injuresoldier= board[pos.first][pos.second];
            if(Injuresoldier!=nullptr && Injuresoldier->player == player){ return Injuresoldier; }
            else  {                return nullptr;  }
        }
        return nullptr;
    }
    static bool pos_validator(std::pair<int,int> pos , std::vector<std::vector<Soldier*>> &board){
        if( pos.first < board.size()  && pos.first >= 0 &&
            pos.second < board.size() && pos.second >= 0) { return true;  }
        else                                              { return false; }
    }
    void Heal () override { this->healthPoints =100; }
};