/**
 * Header file for the board of the war game.
 * 
 * You can copy this file to a new file called Board.hpp, and extend it as you like.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"


namespace WarGame {

class Board {
  private:
    std::vector<std::vector<Soldier*>> board;
  public:
    enum MoveDIR { Up, Down, Right, Left };

    Board(uint numRows, uint numCols) :
      board(numRows, std::vector<Soldier*>(numCols, nullptr)) {std::cout << "\tGet Ready for War!\nChoose your'e soldiers!"<<std::endl;}

    // operator for putting soldiers on the game-board during initialization.
    Soldier*& operator[](std::pair<int,int> location);

    // operator for reading which soldiers are on the game-board.
    Soldier* operator[](std::pair<int,int> location) const;

    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument".
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers
    //      must be handled by polymorphism.
    void move(uint player_number, std::pair<int,int> source, MoveDIR direction);

    // returns true iff the board contains one or more soldiers of the given player.
    bool has_soldiers(uint player_number) const;
    bool MoveValidator(std::pair<int,int> valid);
    //virtual void attack(std::pair<int,int> source, Soldier* soldier)=0;
    void print_board(){
        for (int k = 0; k <board.size()*25; ++k) {
            std::cout<<"-";
        }

        for (auto & i : board) {
            std::cout<<std::endl;
            std::cout<<"|";
            for (int j = 0; j < board.size(); ++j) {
                if(i[j] == nullptr){std::cout<<"player:0,Type:X,hp:X  "<<" | ";}
                else{
                    Soldier* s= i[j];
                    if(s->player==1){   std::cout<<"\033[1;31mplayer:"<<s->player<<",Type:"<<s->SoldierType<<",hp:"<<s->healthPoints<<" \033[0m| "; }
                    else{               std::cout<<"\033[1;32mplayer:"<<s->player<<",Type:"<<s->SoldierType<<",hp:"<<s->healthPoints<<" \033[0m| "; }
                }
            }
            std::cout<<std::endl;
            for (int k = 0; k <board.size()*25 ; ++k) {
                std::cout<<"-";
            }
        }std::cout<<std::endl;
    }
    //~Board()
    //{
    //  board.clear();
    //}
};


}
