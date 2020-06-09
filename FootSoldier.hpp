//
// Created by dor on 07/06/2020.
//

#ifndef WARGAME_A_FOOTSOLDIER_HPP
#define WARGAME_A_FOOTSOLDIER_HPP

#endif //WARGAME_A_FOOTSOLDIER_HPP
#include "Soldier.hpp"
#include <iostream>


class FootSoldier:public Soldier{ ;
public:
    explicit FootSoldier(int player) : Soldier(player,100,10,0){}

    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> pos) override{

        bool found=false;
        int rowFrom=pos.first-1,rowTo=pos.first+1,colFrom=pos.second-1,colTo=pos.second+1;

        int player = this->player;

        while(!found){
        //going throw all the matrix pos +1 / -1.
            for (int i=rowFrom; i<rowTo; ++i){
                for (int j=colFrom; j<colTo; ++j) {
                    if (i == pos.first && j == pos.second) { continue; }
                    Soldier *enemy = getEnemies({i, j}, board, this->player);
                    if (enemy == nullptr) { continue; }
                    else if (board[i][j] != this) {
                        found = true;
                        std::cout<<"Enemy "<<enemy<<" spotted at {"<<i<<","<<j<<"} soldier at {"<<pos.first<<","<<pos.second <<"} engaged the enemy!"<<std::endl;
                        enemy->healthPoints -= this->AttcakDamage;
                        if (enemy->healthPoints <= 0) {
                            board[i][j] = nullptr;
                            std::cout << "{"<<i<<","<<j <<"} Enemy Down!" << std::endl;
                        }
                        return;
                    }
                }
            }
            if(rowFrom>=0){rowFrom-=1;} if(rowTo<=board.size()){rowTo+=1;}
            if(colFrom>=0){colFrom-=1;} if(colTo<=board.size()){colTo+=1;}
            if(rowFrom < 0 && colFrom < 0 && rowTo > board.size() && colTo >board.size()){return;}
        }
    }
    static Soldier* getEnemies(std::pair<int,int> pos , std::vector<std::vector<Soldier*>> &board ,int player){
        if(pos_validator(pos,board)){
            Soldier* Esoldier= board[pos.first][pos.second];
            if(Esoldier!=nullptr && Esoldier->player != player){ return Esoldier; }
            else  {                return nullptr;  }
        }
        return nullptr;
    }
    static bool pos_validator(std::pair<int,int> pos , std::vector<std::vector<Soldier*>> &board){
        if( pos.first < board.size()  && pos.first >= 0 &&
               pos.second < board.size() && pos.second >= 0) { return true;  }
        else                                                 { return false; }
    }

    void Heal () override { this->healthPoints =100; }

};