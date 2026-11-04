#include <iostream> // Included multiple libraries for various functionalities. 
#include <vector> // Subject to change based on the specific requirements of the chess engine implementation.
#include <cstdint> // Included for fixed-width integer types.

using namespace std;

enum Pieces {
    Empty,
    W_pawn, W_rook, W_knight, W_bishop, W_queen, W_king,
    B_pawn, B_rook, B_knight, B_bishop, B_queen, B_king
};

enum Colours {White, Black};

enum MoveType : uint8_t {
    Quiet = 0, DoublePawnPush = 1, KingCastle = 2, QueenCastle = 3, Capture = 4, EnPassant = 5,
    KnightPromotion = 8, BishopPromotion = 9, RookPromotion = 10, QueenPromotion = 11,
    KnightPromotionCapture = 12, BishopPromotionCapture = 13, RookPromotionCapture = 14, QueenPromotionCapture = 15
};

static const int Knight_D[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
static const int King_D[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
static const int Rook_D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
static const int Bishop_D[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
static const int Queen_D[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

class Move {
    public:
        uint16_t data = 0;
        Move() = default;
        Move(int from, int to, MoveType type) : data(from | (to << 6) | (type << 12)) {}
        int from() const { return data & 0x3F; }
        int to() const { return (data >> 6) & 0x3F; }
        int type() const { return (data >> 12) & 0xF; }
        bool isCapture() const { return type() & 4; }
        bool isPromotion() const { return type() & 8; }
};

class Position {
    private:
        Pieces board[64];
        Colours sideToMove = White;
        uint8_t castling = 0b1111;
        int8_t enPassantSquare = -1;
    public:
        Position() {
            const Pieces start[8][8] = {
                B_rook, B_knight, B_bishop, B_queen, B_king, B_bishop, B_knight, B_rook,
                B_pawn, B_pawn, B_pawn, B_pawn, B_pawn, B_pawn, B_pawn, B_pawn,
                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                W_pawn, W_pawn, W_pawn, W_pawn, W_pawn, W_pawn, W_pawn, W_pawn,
                W_rook, W_knight, W_bishop, W_queen, W_king, W_bishop, W_knight, W_rook
            };
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    board[i * 8 + j] = start[i][j];
                }
            }
        };
    void PrintBoard() const {
        const char symbols[] = {'.', 'P', 'R', 'N', 'B', 'Q', 'K', 'p', 'r', 'n', 'b', 'q', 'k'};
        cout << "  a b c d e f g h\n";
        for (int i = 0; i < 8; i++) {
            cout << 8 - i << " ";
            for (int j = 0; j < 8; j++) {
                cout << symbols[board[i * 8 + j]] << " ";
            }
            cout << "\n";
        };
    };
    
    void makeMove(Move m) {};
    void generateLegalMoves(vector<Move>& moves) const {};
    bool inCheck(Colours c) const {return false;};
};

int main() {
    Position game;
    game.PrintBoard();

    return 0;
}