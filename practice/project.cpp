#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <stdexcept>
using namespace std;
// Base class representing a player
class Player {
public:
    virtual string getName() const = 0;
    virtual string getMove() const = 0;
};

// Derived class representing a human player
class HumanPlayer : public Player {
public:
    HumanPlayer(string name) {this->name_ = name;}
    string getName() const override {
        return name_;
    }
    std::string getMove() const override {
        cout << "Enter your move (rock, paper, or scissors): ";
        string move;
        cin >> move;
        if (move != "rock" && move != "paper" && move != "scissors") {
            throw invalid_argument("Invalid move entered.");
        }
        return move;
    }
private:
    string name_;
};

// Derived class representing a computer player
class ComputerPlayer : public Player {
public:
    ComputerPlayer(string name) {this->name_ = name;}
    string getName() const override {
        return name_;
    }
    string getMove() const override {
        std::default_random_engine rng(std::time(nullptr));
        std::uniform_int_distribution<int> dist(1, 3);
        int moveNum = dist(rng);
        string move;
        switch (moveNum) {
            case 1:
                move = "rock";
                break;
            case 2:
                move = "paper";
                break;
            case 3:
                move = "scissors";
                break;
        }
        return move;
    }
private:
    string name_;
};

// Function to determine the winner of the game
string determineWinner(const Player& player1, const Player& player2) {
    string move1 = player1.getMove();
    string move2 = player2.getMove();
    if (move1 == move2) {
        return "Tie";
    }
    if (move1 == "rock" && move2 == "scissors" ||
        move1 == "paper" && move2 == "rock" ||
        move1 == "scissors" && move2 == "paper") {
        return player1.getName();
    } else {
        return player2.getName();
    }
}

int main() {
  cout<<"\t\twelcome to the game of rock paper and scissor"<<endl;
      cout<<"Rule of the game:"<<endl;
      cout<<"1.Rock beats scissors,\n2.scissor beat paper, \n3.paper beats rock"<<endl; 
      cout<<"4.you will get one chance in each of your turn"<<endl;
      cout<<"5.you have to choose either of rock,paper or scissor"<<endl<<endl;
    start:
    try {
              
        string name;
        cout << "Enter your name: ";
        cin >> name;
        HumanPlayer humanPlayer(name);
        ComputerPlayer computerPlayer("Computer");

        cout << "Welcome to rock-paper-scissors, " << humanPlayer.getName() << "!\n";
        string playAgain = "yes";
        while (playAgain == "yes") {
            cout << humanPlayer.getName() << ", it's your turn:\n";
            string winner = determineWinner(humanPlayer, computerPlayer);
            cout << "The winner is " << winner << "!\n";
            cout << "Play again? (yes or no): ";
            cin >> playAgain;
            if (playAgain != "yes") {
                throw (playAgain);
            }
        }
    } catch (string s) {
    
      if(s=="no"){
        cout<<"Hope You enjoyed Our game"<<endl;
        exit(1);
      }
      else{
        cout<<"invalid option"<<endl;
    goto start;
    }
      }
    return 0;
}