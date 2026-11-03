#include <iostream> // Included multiple libraries for various functionalities. 
#include <string> // Of which some may not be used in this code snippet but could be useful for future extensions of the chess game.
#include <vector> // Subject to change based on the specific requirements of the chess engine implementation.
#include <algorithm>
#include <numeric>
#include <cmath>
#include <random>

using namespace std;

class ChessGame {
    private:
        string _board[8][8];
    public:
        ChessGame() {
            _board[0][0] = "R"; // Black pieces are capitalised
            _board[0][1] = "N";
            _board[0][2] = "B";
            _board[0][3] = "Q";
            _board[0][4] = "K";
            _board[0][5] = "B";
            _board[0][6] = "N";
            _board[0][7] = "R";

            _board[7][0] = "r"; // White pieces are lower case
            _board[7][1] = "n";
            _board[7][2] = "b";
            _board[7][3] = "q";
            _board[7][4] = "k";
            _board[7][5] = "b";
            _board[7][6] = "n";
            _board[7][7] = "r";
            
            for (int i = 0; i < 8; i++) {
                _board[1][i] = "P"; // White pawns
                _board[6][i] = "p"; // Black pawns
            }
            
            for (int i = 2; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    _board[i][j] = "."; // Empty squares
                }
            }
        }

        void printBoard() {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    cout << _board[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    ChessGame game;
    game.printBoard();

    return 0;
}