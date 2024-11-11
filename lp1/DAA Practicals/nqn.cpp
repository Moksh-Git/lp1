#include <iostream>
#include <cmath>
using namespace std;

int board[20], countSolutions;

void print(int n) {
    cout << "\n\nSolution " << ++countSolutions << ":\n\n";
    for(int i = 1; i <= n; i++)
    	cout << "\t" << i;
    cout << "\n";
    for(int i = 1; i <= n; i++) {
        cout << "\n\n" << i;
        for(int j = 1; j <= n; j++) {
            if(board[i] == j) cout << "\tQ";
            else cout << "\t-";
        }
    }
    cout << "\n";
}

bool place(int row, int column) {
    for (int i = 1; i <= row - 1; i++) {
        if (board[i] == column || abs(board[i] - column) == abs(i - row))
            return false;
    }
    return true;
}

void queen(int row, int n) {
    for (int column = 1; column <= n; column++) {
        if (place(row, column)) {
            board[row] = column;
            if (row == n)
                print(n);
            else
                queen(row + 1, n);
        }
    }
}

int main() {
    int n;
    cout << "- N Queen problem using backtracking -";
    cout << "\n\nEnter number of queens: ";
    cin >> n;
    queen(1, n);
    return 0;
}

