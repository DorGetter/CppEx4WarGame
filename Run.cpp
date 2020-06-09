//
// Created by dor on 08/06/2020.
//
#include "Board.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>

using namespace std;
int main(){
    WarGame::Board board(8,8);
    board.has_soldiers(1);
    board[{0,1}] = new FootSoldier(1); //soldier 1 - 100
    board.has_soldiers(1);

    board.has_soldiers(2);
    board[{7,1}] = new FootSoldier(2); //soldier 2 - 100
    board.has_soldiers(2);

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up); //soldier 2 - 90
    board.has_soldiers(2);
    board.has_soldiers(1);

//  //  board.move(1,{0,1},WarGame::Board::MoveDIR::Up)); //no soldier thehre
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up); //soldier 2 - 80
    board.has_soldiers(2);
    board.has_soldiers(1);

//    board.move(1,{7,1},WarGame::Board::MoveDIR::Up);
//    board.move(2,{7,1},WarGame::Board::MoveDIR::Up));
    board.move(2,{7,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 90
    board.has_soldiers(2);
    board.has_soldiers(1);
    board.move(2,{6,1},WarGame::Board::MoveDIR::Down); //sodier 1 - 80
    board.has_soldiers(2);
    board.has_soldiers(1);
    board.move(2,{5,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 70
    board.has_soldiers(2);
    board.has_soldiers(1);

    board.move(1,{2,1},WarGame::Board::MoveDIR::Up); //soldier 2 - 70
    board.has_soldiers(2);
    board.has_soldiers(1);

//    board.move(1,{3,1},WarGame::Board::MoveDIR::Up);//there is another soldier in the destenation
//    board.move(2,{4,1},WarGame::Board::MoveDIR::Down); //gam ze
    board.has_soldiers(2);
    board.has_soldiers(1);

    board.move(1,{3,1},WarGame::Board::MoveDIR::Down); //soldier 2 - 60
    board.has_soldiers(2);
    board.has_soldiers(1);
    board.move(2,{4,1},WarGame::Board::MoveDIR::Up); //soldier 1 - 60
    board.has_soldiers(2);
    board.has_soldiers(1);
    board.move(2,{5,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 50
    board.has_soldiers(2);
    board.has_soldiers(1);
    board.move(2,{4,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 40
    board.has_soldiers(2);
    board.has_soldiers(1);
    board.move(2,{3,1},WarGame::Board::MoveDIR::Up); //soldier 1 - 30
    board.has_soldiers(2);
    board.has_soldiers(1);
    board.move(2,{4,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 20
    board.has_soldiers(2);
    board.has_soldiers(1);
    board.move(2,{3,1},WarGame::Board::MoveDIR::Up); //soldier 1 - 10
    board.has_soldiers(2);
    board.has_soldiers(1);
    board.move(2,{4,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 0
    board.has_soldiers(2);
    board.has_soldiers(1);

//// test case 3X3
//    WarGame::Board board(8,8);
//    board.has_soldiers(1);
//    board[{0,1}] = new FootSoldier(1);//player 1 footSoldier1 {0,1}
//    //(board[{0,1}] = new FootSoldier(1))); //there is already soldier there
//    board[{0,0}] = new FootCommander(1); //player 1 commanderSoldier {0,0}
//    board[{0,2}] = new FootSoldier(1);//player 1 footSoldier2 {0,2}
//    board.has_soldiers(1); //there is no need to write this any time
//board.print_board();

//    board.has_soldiers(2);
//    board[{7,0}] = new FootCommander(2);//player 2 commanderSoldier {7,0}
//    board[{7,1}] = new FootSoldier(2);//player 2 footSoldier1 {7,1}
//    board[{7,2}] = new FootSoldier(2);//player 2 footSoldier2 {7,2}

//    board.has_soldiers(2);
//    board.print_board();

//    board.move(1,{0,1},WarGame::Board::MoveDIR::Up); //player 2 footsoldier1 - 90
//    board.has_soldiers(2);
//    board.has_soldiers(1);
//    //board.move(1,{0,1},WarGame::Board::MoveDIR::Up)); //no soldier there
//    board.move(1,{1,1},WarGame::Board::MoveDIR::Up); //player 2 footsoldier1 - 80
//    board.has_soldiers(2);
//    board.has_soldiers(1);
//
//    //board.move(2,{7,0},WarGame::Board::MoveDIR::Left)); // cant move left
//    board.move(2,{7,0},WarGame::Board::MoveDIR::Down); //player 1 commanderSoldier - 130, player 1 footsoldier1 - 70,   player 1 footsoldier2 - 90,
//    board.has_soldiers(2);
//    board.has_soldiers(1);
//
//    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);//player 2 commanderSoldier - 130, player 2 footsoldier1 - 70,   player 2 footsoldier2 - 90,
//    board.has_soldiers(2);
//    board.has_soldiers(1);
//    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
//    board.has_soldiers(2);
//    board.has_soldiers(1);
//    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
//    board.has_soldiers(2);
//    board.has_soldiers(1);
//    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
//    board.has_soldiers(2);
//    board.has_soldiers(1);
//
//    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
//    board.has_soldiers(2);
//    board.has_soldiers(1);
//    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
//    board.has_soldiers(2);
//    board.has_soldiers(1);
//    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
//    board.has_soldiers(2);
//    board.has_soldiers(1);
//    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
//    board.has_soldiers(2);
//    board.has_soldiers(1);
//
//    board.move(1,{0,2},WarGame::Board::MoveDIR::Up);
//    board.move(1,{1,2},WarGame::Board::MoveDIR::Up);
//    board.has_soldiers(2);
//    board.has_soldiers(1);


    return 0;
}