#include <iostream>
#include <cctype>

using namespace std;

// make a rock-paper-scissors game
int rps(string player1, string player2) {
    return player1 == player2 ? 2 : 
            (player1 == "rock" && player2 == "scissors") || 
            (player1 == "scissors" && player2 == "paper") || 
            (player1 == "paper" && player2 == "rock") 
        ? 1 
        : 0
    ;
}

int main() {
    cout << "Enter player 1 choice (rock, paper, scissors): ";
    string player1;
    cin >> player1;

    cout << "Enter player 2 choice (rock, paper, scissors): ";
    string player2;
    cin >> player2;

    switch (rps(player1, player2)) {
        case 0:
            cout << "Player 2 wins!" << endl;
            break;
        case 1:
            cout << "Player 1 wins!" << endl;
            break;
        case 2:
            cout << "It's a tie!" << endl;
            break;
    }

    return 0;
}
