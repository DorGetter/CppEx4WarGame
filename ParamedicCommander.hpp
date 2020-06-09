//
// Created by dor on 08/06/2020.
//

#ifndef WARGAME_A_PARAMEDICCOMMANDER_HPP
#define WARGAME_A_PARAMEDICCOMMANDER_HPP

#endif //WARGAME_A_PARAMEDICCOMMANDER_HPP
#include "Soldier.hpp"
#include <iostream>

class ParamedicCommander:public Soldier{ ;
public:
    explicit ParamedicCommander(int player) : Soldier(player,200,0,5){}

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

    void callParamedics(std::vector<std::vector<Soldier *>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if(board[i][j] != nullptr &&
                board[i][j]->player==this->player &&
                board[i][j]->SoldierType==4){
                    Soldier* para = board[i][j];
                    std::pair <int,int> paraloc= {i,j};
                    para->attack(board,paraloc);
                }
            }
        }
    }

    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> pos) override{
        recoverSoldier(board,pos);
        callParamedics(board);
    }

    static bool pos_validator(std::pair<int,int> pos , std::vector<std::vector<Soldier*>> &board){
        return pos.first < board.size()  || pos.first  > 0 ||
               pos.second < board.size() || pos.second > 0 ;
    }
    void Heal () override { this->healthPoints =200; }
};