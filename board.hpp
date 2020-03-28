#include <iostream>
#include <vector>
#include <string>

class Board {

  std::vector<std::string> positions;
  std::vector<std::string> players;
  int playing;
  int played;
  bool winner;

  public:
    Board();

    void intro();
    void startPlaying();
    void setPosition(int num);
    void display();
    bool hasWinner();
};