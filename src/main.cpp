#include <iostream> // Included multiple libraries for various functionalities. 
#include <string> // Of which some may not be used in this code snippet but could be useful for future extensions of the chess game.
#include <vector> // Subject to change based on the specific requirements of the chess engine implementation.
#include <algorithm>
#include <numeric>
#include <cmath>
#include <random>

using namespace std;

enum Pieces {
    Empty,
    W_pawn, W_rook, W_knight, W_bishop, W_queen, W_king,
    B_pawn, B_rook, B_knight, B_bishop, B_queen, B_king
};

struct Move {
    int fromrow, fromcol;
    int torow, tocol;
};

class ChessGame {
    private:
        Pieces _board[8][8];
    public:
        ChessGame() {
            Pieces initial_board[8][8] = {
                {B_rook, B_knight, B_bishop, B_queen, B_king, B_bishop, B_knight, B_rook},
                {B_pawn, B_pawn, B_pawn, B_pawn, B_pawn, B_pawn, B_pawn, B_pawn},
                {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
                {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
                {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
                {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
                {W_pawn, W_pawn, W_pawn, W_pawn, W_pawn, W_pawn, W_pawn, W_pawn},
                {W_rook, W_knight, W_bishop, W_queen, W_king, W_bishop, W_knight, W_rook}
            };

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    _board[i][j] = initial_board[i][j];
                };
            };
        };

        void MakeMove (Move m) {
            Pieces movingpiece = _board[m.fromrow][m.fromcol];
            _board[m.fromrow][m.fromcol] = Empty;
            _board[m.torow][m.tocol] = movingpiece;
        };

        bool BoardBounds(int Row, int Col) {
            return Row >= 0 && Row < 8 && Col >= 0 && Col < 8;
        };

        void PrintBoard() {
            char symbols[] = {'.', 'P', 'R', 'N', 'B', 'Q', 'K', 'p', 'r', 'n', 'b', 'q', 'k'};
            
            cout << "  a b c d e f g h\n";
            for (int i = 0; i < 8; i++) {
                cout << 8 - i << " ";
                for (int j = 0; j < 8; j++) {
                    cout << symbols[_board[i][j]] << " ";
                }
                cout << endl;
            };
        };
};

class CMove {
    public:
        int Quiet_Moves;
        int Capture_Moves;
        int King_Castles;
        int Queen_Castles;
        int En_Passant;
        int N_Promotion;
        int B_Promotion;
        int R_Promotion;
        int Q_Promotion;
        int N_Promotion_Capture;
        int B_Promotion_Capture;
        int R_Promotion_Capture;
        int Q_Promotion_Capture;
        int Double_Pawn_Push;
        
}

int main() {
    ChessGame game;
    game.PrintBoard();

    return 0;
}