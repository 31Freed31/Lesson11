#include <iostream>
#include <string>

using namespace std;

bool isValidCharacter(char c) {
    return c == 'X' || c == 'O' || c == '.';
}

bool isValidField(int countX, int countO, string field) {
    if (countX < countO || countX > countO + 1) return false;
    for (int i = 0; i < field.length(); i++) {
        if (!isValidCharacter(field[i])) return false;
    }
    return true;
}

char checkLine(char a, char b, char c) {
    if (a == b && b == c) return a;
    return '.';
}

char getWinner(string row1, string row2, string row3) {
    char winner = '.';

    winner = checkLine(row1[0], row1[1], row1[2]);
    if (winner == '.') winner = checkLine(row2[0], row2[1], row2[2]);
    if (winner == '.') winner = checkLine(row3[0], row3[1], row3[2]);

    if (winner == '.') winner = checkLine(row1[0], row2[0], row3[0]);
    if (winner == '.') winner = checkLine(row1[1], row2[1], row3[1]);
    if (winner == '.') winner = checkLine(row1[2], row2[2], row3[2]);

    if (winner == '.') winner = checkLine(row1[0], row2[1], row3[2]);
    if (winner == '.') winner = checkLine(row1[2], row2[1], row3[0]);

    return winner;
}

int main() {
    string row1, row2, row3;

    getline(cin, row1);
    getline(cin, row2);
    getline(cin, row3);

    if (row1.length() != 3 || row2.length() != 3 || row3.length() != 3) {
        cout << "Incorrect" << endl;
        return 0;
    }

    int countX = 0, countO = 0;

    for (int i = 0; i < row1.length(); i++) {
        if (row1[i] == 'X') countX++;
        if (row1[i] == 'O') countO++;
    }
    for (int i = 0; i < row2.length(); i++) {
        if (row2[i] == 'X') countX++;
        if (row2[i] == 'O') countO++;
    }
    for (int i = 0; i < row3.length(); i++) {
        if (row3[i] == 'X') countX++;
        if (row3[i] == 'O') countO++;
    }

    string fullField = row1 + row2 + row3;
    if (!isValidField(countX, countO, fullField)) {
        cout << "Incorrect" << endl;
        return 0;
    }

    char winner = getWinner(row1, row2, row3);

    bool xWon = (winner == 'X');
    bool oWon = (winner == 'O');

    if (xWon && countX == countO) {
        cout << "Incorrect" << endl;
    }
    else if (oWon && countX > countO) {
        cout << "Incorrect" << endl;
    }
    else if (xWon || oWon) {
        if (xWon) cout << "Petya won" << endl;
        if (oWon) cout << "Vanya won" << endl;
    }
    else {
        bool hasEmptyCell = row1.find('.') != string::npos ||
            row2.find('.') != string::npos ||
            row3.find('.') != string::npos;
        if (hasEmptyCell) cout << "Nobody" << endl;
        else cout << "Nobody" << endl;
    }
}
