//
// Created by dor on 24/05/2020.
//
#include "doctest.h"
#include <iostream>
#include <stdexcept>

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>

TEST_CASE("FootSoldier VS FootSoldier"){
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{0,1}] = new FootSoldier(1);

    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{7,1}] = new FootSoldier(2);

    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

    std::cout << "\033[1;31m\n\n\tRound 1\n\tPreppier for Battle \033[0m| "<<std::endl;
    board.print_board();
    std::cout << "\033[1;31mGentlemen's Get Ready For WAR!! \033[0m| "<<std::endl;

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    board.move(2,{7,1},WarGame::Board::MoveDIR::Down);//p1 , p2 = 90 hp
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();


    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    board.move(2,{6,1},WarGame::Board::MoveDIR::Down);//p1 , p2 = 80 hp
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{2,1},WarGame::Board::MoveDIR::Left);
    board.move(2,{5,1},WarGame::Board::MoveDIR::Right);//p1 , p2 = 70 hp
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{2,0},WarGame::Board::MoveDIR::Right);
    board.move(2,{5,2},WarGame::Board::MoveDIR::Right);//p1 , p2 = 60 hp
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{2,1},WarGame::Board::MoveDIR::Right);
    board.move(2,{5,3},WarGame::Board::MoveDIR::Right);//p1 , p2 = 50 hp
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{2,2},WarGame::Board::MoveDIR::Right);
    board.move(2,{5,4},WarGame::Board::MoveDIR::Down);//p1 , p2 = 40 hp
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{2,3},WarGame::Board::MoveDIR::Right);
    board.move(2,{4,4},WarGame::Board::MoveDIR::Down);//p1 , p2 = 30 hp
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{2,4},WarGame::Board::MoveDIR::Left);
    board.move(2,{3,4},WarGame::Board::MoveDIR::Right);//p1 , p2 = 20 hp
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{2,3},WarGame::Board::MoveDIR::Left);
    board.move(2,{3,5},WarGame::Board::MoveDIR::Right);//p1 , p2 = 10 hp
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{2,2},WarGame::Board::MoveDIR::Right); //p1=10, p2 = 0!
    board.print_board();

    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    std::cout << "\033[1;31m\nPlayer 1 Win the Battle!!!\n\n \033[0m| "<<std::endl;
};
TEST_CASE("Sniper VS Sniper") {
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{0,1}] = new Sniper(1);

    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{7,1}] = new Sniper(2);

    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

    std::cout << "\033[1;31mPreppier for Battle \033[0m| "<<std::endl;
    board.print_board();
    std::cout << "\033[1;31mGentlemen's Get Ready For WAR!! \033[0m| "<<std::endl;

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    board.move(2,{7,1},WarGame::Board::MoveDIR::Down);//p1 , p2 = 50
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(2,{6,1},WarGame::Board::MoveDIR::Down);//p1 =0
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();
    std::cout << "\033[1;32m\nPlayer 2 Win the Battle!!!\n\n \033[0m| "<<std::endl;
};
TEST_CASE("Foot Commander VS Foot Commander + help FootSoldier") {
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{0,1}] = new FootCommander(1);

    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{7,1}] = new FootCommander(2);

    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

    std::cout << "\033[1;31mPreppier for Battle \033[0m| "<<std::endl;
    board.print_board();
    std::cout << "\033[1;31mGentlemen's Get Ready For WAR!! \033[0m| "<<std::endl;

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    board.move(2,{7,1},WarGame::Board::MoveDIR::Down);//p1 , p2 = 150
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    board.move(2,{6,1},WarGame::Board::MoveDIR::Down);//p1 , p2 = 130
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{2,1},WarGame::Board::MoveDIR::Up);
    board.move(2,{5,1},WarGame::Board::MoveDIR::Down);//p1 , p2 = 110
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{3,1},WarGame::Board::MoveDIR::Right);
    board.move(2,{4,1},WarGame::Board::MoveDIR::Right);//p1 , p2 =90
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();


    board[{7,1}] = new FootSoldier(2); // help for player 2

    board.move(1,{3,2},WarGame::Board::MoveDIR::Right);
    board.move(2,{4,2},WarGame::Board::MoveDIR::Up);//p1 , p2 =90
    CHECK_THROWS(board.move(2,{7,1},WarGame::Board::MoveDIR::Up));
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{3,3},WarGame::Board::MoveDIR::Right);
    board.move(2,{5,2},WarGame::Board::MoveDIR::Up);//p1 , p2 =90
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();


    board.move(2,{7,1},WarGame::Board::MoveDIR::Down);//

    std::cout << "\033[1;32m\nPlayer 2 Win the Battle!!!\n\n \033[0m| "<<std::endl;
};
TEST_CASE("Sniper Commander + Sniper VS Sniper Commander + FootSoldier + Paramedic") {
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{0,0}] = new SniperCommander(1);
    board[{0,1}] = new Sniper(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{7,7}] = new FootCommander(2);
    board[{7,6}] = new FootSoldier(2);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

    std::cout << "\033[1;31mPreppier for Battle \033[0m| "<<std::endl;
    board.print_board();
    std::cout << "\033[1;31mGentlemen's Get Ready For WAR!! \033[0m| "<<std::endl;

    CHECK_THROWS(board.move(1,{0,0},WarGame::Board::MoveDIR::Right));
    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
    CHECK_THROWS(board.move(2,{7,7},WarGame::Board::MoveDIR::Left));
    board.move(2,{7,7},WarGame::Board::MoveDIR::Down);
    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board[{7,7}] = new Paramedic(2);
    std::cout<<"Player 2: Paramedic!!!"<<std::endl;
    board.move(2,{7,7},WarGame::Board::MoveDIR::Down);
    board.print_board();


    board.move(1,{1,0},WarGame::Board::MoveDIR::Up);
    board.move(2,{7,6},WarGame::Board::MoveDIR::Left);
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.print_board();
    std::cout << "\033[1;31m\nPlayer 1 Win the Battle!!!\n\n \033[0m| "<<std::endl;
};
TEST_CASE("Sniper Commander + FootCommander + ParamedicCommander VS Sniper Commander + Sniper + FootSoldier") {
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{0,0}] = new SniperCommander(1);
    board[{0,1}] = new FootSoldier(1);
    board[{0,2}] = new ParamedicCommander(1);

    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{7,7}] = new FootCommander(2);
    board[{7,6}] = new SniperCommander(2);
    board[{7,5}] = new FootSoldier(2);

    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

    std::cout << "\033[1;31mPreppier for Battle \033[0m| "<<std::endl;
    board.print_board();
    std::cout << "\033[1;31mGentlemen's Get Ready For WAR!! \033[0m| "<<std::endl;

    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
    board.move(2,{7,7},WarGame::Board::MoveDIR::Down);
    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    board.move(2,{7,6},WarGame::Board::MoveDIR::Down);
    board.move(1,{0,2},WarGame::Board::MoveDIR::Up);
    board.move(2,{7,5},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    CHECK_THROWS(
            board.move(2,{7,7},WarGame::Board::MoveDIR::Right));
    CHECK_THROWS(
            board.move(2,{7,7},WarGame::Board::MoveDIR::Left));
    CHECK_THROWS(
            board.move(2,{6,7},WarGame::Board::MoveDIR::Right));
    CHECK_THROWS(
            board.move(2,{6,7},WarGame::Board::MoveDIR::Left));
    CHECK_THROWS(
            board.move(2,{5,7},WarGame::Board::MoveDIR::Right));

    CHECK_THROWS(
            board.move(2,{1,0},WarGame::Board::MoveDIR::Left));
    CHECK_THROWS(
            board.move(2,{1,0},WarGame::Board::MoveDIR::Right));
    CHECK_THROWS(
            board.move(2,{1,1},WarGame::Board::MoveDIR::Left));
    CHECK_THROWS(
            board.move(2,{1,1},WarGame::Board::MoveDIR::Right));
    CHECK_THROWS(
            board.move(2,{1,2},WarGame::Board::MoveDIR::Left));

    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    board.move(2,{6,6},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    CHECK_THROWS(
            board.move(2,{1,0},WarGame::Board::MoveDIR::Up));

    board.move(1,{2,1},WarGame::Board::MoveDIR::Right);
    board.move(2,{6,7},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    CHECK_THROWS(
            board.move(1,{1,2},WarGame::Board::MoveDIR::Up));
    CHECK_THROWS(
            board.move(1,{2,2},WarGame::Board::MoveDIR::Down));

    CHECK_THROWS(
            board.move(1,{5,7},WarGame::Board::MoveDIR::Right));
    CHECK_THROWS(
            board.move(1,{5,6},WarGame::Board::MoveDIR::Right));
    CHECK_THROWS(
            board.move(2,{5,7},WarGame::Board::MoveDIR::Right));
    CHECK_THROWS(
            board.move(2,{5,6},WarGame::Board::MoveDIR::Right));

    board.move(1,{1,2},WarGame::Board::MoveDIR::Right);
    board.move(2,{5,6},WarGame::Board::MoveDIR::Down);
    board.move(2,{5,7},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.print_board();

    board.move(1,{1,3},WarGame::Board::MoveDIR::Right);
    board.move(2,{4,6},WarGame::Board::MoveDIR::Down);
    board.print_board();


    std::cout << "\033[1;32m\nPlayer 2 Win the Battle!!!\n\n \033[0m| "<<std::endl;

    std::cout << "\033[1;33m\nThanks for Watching the Simulation!!!\n\n \033[0m| "<<std::endl;
};
