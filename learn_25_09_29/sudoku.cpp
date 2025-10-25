#include <bits/stdc++.h>

using namespace std;

void printSudoku(int sudoku[9][9]) {
    cout << "-------------------------------\n";
    for(int i = 0; i < 9; i++){
        cout << "|";
        for(int j = 0; j < 9; j++){
            if(sudoku[i][j] == 0)
                cout << " . " ;
            else
                cout << " " << sudoku[i][j] << " ";

            if((j + 1) % 3 == 0)
                cout << "|";
        }
        if(i % 3 == 2) cout << "\n-------------------------------\n";
        else cout << "\n";
    }
}

void removeDigits(int (&sudoku)[9][9]) {
    int removeCount = 10;
    while (removeCount > 0) {
        int row = rand() % 9;
        int col = rand() % 9;
        
        if(sudoku[row][col] != 0){
            sudoku[row][col] = 0;
            removeCount--;
        }
    }
}

int main() {
    srand(time(0));

    int sudoku[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9},
    };

    int puzzleSudoku[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            puzzleSudoku[i][j] = sudoku[i][j];

    removeDigits(puzzleSudoku);

    const int chances = 5;
    int remaining = chances;

    while (remaining > 0) {
        printSudoku(puzzleSudoku);
        cout << "You have " << remaining << " chances left.\n";
        cout << "Enter row(1-9) col(1-9) number(1-9): ";

        int row, col, num;
        cin >> row >> col >> num;

        row--; col--;

        if (row < 0 || row >= 9 || col < 0 || col >= 9 || num < 1 || num > 9) {
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if (puzzleSudoku[row][col] != 0) {
            cout << "Cell already filled! Try another.\n";
            continue;
        }

        if (sudoku[row][col] == num) {
            puzzleSudoku[row][col] = num;
            cout << "Correct!\n";
        } else {
            remaining--;
            cout << "Wrong! Remaining chances: " << remaining << "\n";
        }

        bool solved = true;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (puzzleSudoku[i][j] == 0)
                    solved = false;

        if (solved) {
            cout << "Congratulations! You solved the Sudoku!\n";
            break;
        }
    }

    if (remaining == 0)
        cout << "Game over! You ran out of chances.\n";


    return 0;
}