#include <iostream>
#include <vector>
#include "board.hpp"

Board::Board():positions(9, "*") {
	players.push_back("X");
	players.push_back("O");
	played = 0;
	playing = 0;
	winner = false;
}

void Board::intro() {

   std::cout << "-----------------------------------------\n";
   std::cout << "Welcome to TicTacToe game of 2 Players\n";
   std::cout << "-----------------------------------------\n";
   std::cout << "Player 1 X\n";
   std::cout << "Player 2 O\n\n";

}

void Board::startPlaying(){
   while(played <= 9){
	   int position;
	   std::cout << "Player " << playing <<" Play(1-9): ";
	   std::cin >> position;
	   setPosition(position);
	   if(winner){
		   break;
	   }
   }
}

void Board::setPosition(int num){
	if(positions[num - 1] != "*"){
		 std::cout << "Player " << playing <<" Choose another: \n";
	}
   positions[num - 1] = players[playing];
   playing = (playing + 1) % 2;
   display();
   if(hasWinner()){
	   std::cout << "Winner\n";
	   winner = true;
   }
   played++;
   if(played > 9){
	   std::cout << "No winner\n";
   }
}

bool Board::hasWinner(){
   if(((positions[0] == positions[1]) && (positions[1] == positions[2]) && (positions[0] != "*")) ||
      ((positions[3] == positions[4]) && (positions[4] == positions[5]) && (positions[3] != "*")) ||
      ((positions[6] == positions[7]) && (positions[7] == positions[8]) && (positions[6] != "*")) ||
      ((positions[0] == positions[3]) && (positions[3] == positions[6]) && (positions[0] != "*")) ||
      ((positions[1] == positions[4]) && (positions[4] == positions[7]) && (positions[1] != "*")) ||
      ((positions[2] == positions[5]) && (positions[5] == positions[8]) && (positions[2] != "*")) ||
      ((positions[0] == positions[4]) && (positions[4] == positions[8]) && (positions[0] != "*")) ||
      ((positions[2] == positions[4]) && (positions[4] == positions[6]) && (positions[2] != "*"))) {
		  return true;
	  }
	  return false;
}

void Board::display(){
	std::cout << "--------------------------------------------------\n";
	std::cout << "|                                                |\n";
	std::cout << "|                                                |\n";
	for(int x = 0; x < positions.size(); x++){
      std::cout << "        " << positions[x] << "        ";
      if(x != 0 && (x + 1) % 3 == 0){
		  std::cout << "\n";
	      std::cout << "|                                                |\n";
	      std::cout << "|                                                |\n";
	  }else{
		  std::cout << "|";
	  }
    }
	std::cout << "|                                                |\n";
    std::cout << "--------------------------------------------------\n";
}