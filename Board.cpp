//
// Created by dor on 07/06/2020.
//

#include "Board.hpp"
#include <iostream>
#include "Soldier.hpp"

namespace WarGame {

using namespace std;
    Soldier *&Board::operator[](std::pair<int, int> location) {
        return board[location.first][location.second];
    }

    Soldier *Board::operator[](std::pair<int, int> location) const {
       if(location.first >= board.size() ||
       location.second>= board.size() ||
       location.first < 0 ||
       location.second < 0) {
           throw invalid_argument("location is not in the play board");
       }
        return board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int, int> source, Board::MoveDIR direction) {
        int i = source.first; int j = source.second;
        MoveValidator({source.first,source.second});

        Soldier* SoldierSource = board[source.first][source.second];
        if (SoldierSource!=NULL && SoldierSource->player == player_number){

            if(direction==Up){
                if(MoveValidator({source.first+1,source.second})){
                    board[source.first][source.second]= nullptr;
                    SoldierSource->attack( board, {source.first+1,source.second});
                //    attack({source.first+1,source.second}, SoldierSource);
                    board[source.first+1][source.second]= SoldierSource;
                }else{throw invalid_argument("Soldier Can't move to this location");}
            }

            else if(direction==Down){
                if(MoveValidator({source.first-1,source.second})){
                    board[source.first][source.second]= nullptr;
                    SoldierSource->attack( board, {source.first-1,source.second});
                //    attack({source.first+1,source.second}, SoldierSource);
                    board[source.first-1][source.second]= SoldierSource;
                }else{throw invalid_argument("Soldier Can't move to this location");}
            }

            else if(direction==Left){
                if(MoveValidator({source.first,source.second-1})){
                    board[source.first][source.second]= nullptr;
                    SoldierSource->attack( board, {source.first,source.second-1});

                 //   attack({source.first,source.second-1}, SoldierSource);
                    board[source.first][source.second-1]= SoldierSource;
                }else{throw invalid_argument("Soldier Can't move to this location");}
            }

            else if(direction==Right) {
                if (MoveValidator({source.first, source.second + 1})) {
                    board[source.first][source.second] = nullptr;
                    SoldierSource->attack( board, {source.first,source.second+1});

//                    attack({source.first,source.second+1}, SoldierSource);
                    board[source.first][source.second+1] = SoldierSource;
                } else { throw invalid_argument("Soldier Can't move to this location"); }
            }


        }else { throw std::invalid_argument("place is empty"); }
    }

    bool Board::has_soldiers(uint player_number) const {
        for (int i = 0; i < board.size() ; ++i) {
            for (int j = 0; j < board.size(); ++j) {
                Soldier* SoldierLocation = board[i][j];
                if(SoldierLocation != nullptr){
                    if(SoldierLocation->player == player_number) return true;
                }
            }
        }
        return false;
    }

    bool Board::MoveValidator(std::pair<int, int> valid) {
        if(valid.first < board.size() && valid.first >= 0 &&
                valid.second < board.size() && valid.second >= 0 ){
            Soldier *tSoldier = board[valid.first][valid.second];
            if(tSoldier == nullptr){ return true; }
            else{                    return false;}
        }throw invalid_argument("location is not in the play board or place is taken");
    }

    //void Board::attack(std::pair<int, int> source, Soldier *soldier) {}
}