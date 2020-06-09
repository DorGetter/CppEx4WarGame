//
// Created by dor on 08/06/2020.
//

#ifndef WARGAME_A_FOOTCOMMANDER_HPP
#define WARGAME_A_FOOTCOMMANDER_HPP

#endif //WARGAME_A_FOOTCOMMANDER_HPP

#include "Soldier.hpp"
#include <iostream>


class FootCommander:public Soldier{ ;
public:
    explicit FootCommander(int player): Soldier(player, 150, 20,1){}

    static void allSoldiersAttack(std::vector<std::vector<Soldier*>> &board,int player,std::pair<int,int> pos) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if(board[i][j]!=nullptr &&
                board[i][j]->player==player &&
                (board[i][j]->SoldierType==0)){
                    std::pair<int, int> locOfS = {i,j};
                    if(locOfS!=pos){
                        board[i][j]->attack(board, locOfS);
                    }
                }
            }
        }
    }

    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> pos) override{

        bool found=false; int rowFrom=pos.first-1,rowTo=pos.first+1,colFrom=pos.second-1,colTo=pos.second+1;
        while(!found){
            //going throw all the matrix pos +1 / -1.
            for (int i=rowFrom; i<rowTo; ++i){
                for (int j=colFrom; j<colTo; ++j) {

                    if (i == pos.first && j == pos.second) { continue; }

                    Soldier *enemy = getEnemies({i, j}, board, this->player);

                    if (enemy == nullptr) { continue; }
                    else if (board[i][j] != this) {
                        found = true;
                        std::cout << "Enemy " << enemy << " spotted at {" << i << "," << j << "} soldier at {"
                                  << pos.first << "," << pos.second << "} engaged the enemy!" << std::endl;
                        enemy->healthPoints -= this->AttcakDamage;
                        if (enemy->healthPoints <= 0) {
                            board[i][j] = nullptr;
                            std::cout << "{"<<i<<","<<j <<"} Enemy Down!" << std::endl;                        }
                    }
                    i=rowTo+1;
                    found=true;
                }
            }
            if(rowFrom>=0){rowFrom-=1;} if(rowTo<=board.size()){rowTo+=1;}
            if(colFrom>=0){colFrom-=1;} if(colTo<=board.size()){colTo+=1;}
            if(rowFrom < 0 && colFrom < 0 && rowTo > board.size() && colTo >board.size()){return;}
        }
        allSoldiersAttack(board,this->player,pos);
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
        else                                              { return false; }
    }
    void Heal () override { this->healthPoints =150; }

};