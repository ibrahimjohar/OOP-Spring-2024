/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Scenario 3
*/

#include <iostream>
#include <string>
using namespace std;

class ChessPiece {
private:
    string name;
    char color;
    char symbol;

public:
    ChessPiece() {
        name = "Pawn";
        color = 'W';
        symbol = 'p';
    }

    ChessPiece(string pieceName, char pieceColor, char pieceSymbol)
        : name(pieceName), color(pieceColor), symbol(pieceSymbol) {}

    string getName() {
        return name;
    }

    char getColor() {
        return color;
    }

    char getSymbol() {
        return symbol;
    }
};

class ChessBoard {
private:
    ChessPiece* board[8][8];

public:
    ChessBoard() {
        char initialBoard[8][8] = {
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (initialBoard[i][j] != '.') {
                    char symbol = initialBoard[i][j];
                    board[i][j] = new ChessPiece(getPieceName(symbol), getPieceColor(i), symbol);
                } else {
                    board[i][j] = nullptr;
                }
            }
        }
    }

    void display() {
        char columnLabels[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

        cout << "  ";
        for (int i = 0; i < 8; i++) {
            cout << columnLabels[i] << ' ';
        }
        cout << "\n";

        for (int i = 0; i < 8; i++) {
            cout << 8 - i << ' ';
            for (int j = 0; j < 8; j++) {
                if (board[i][j] != nullptr) {
                    cout << board[i][j]->getSymbol() << ' ';
                } else {
                    cout << ". ";
                }
            }
            cout << 8 - i << "\n";
        }

        cout << "  ";
        for (int i = 0; i < 8; i++) {
            cout << columnLabels[i] << ' ';
        }
        cout << "\n";
    }

    bool movePiece(string source, string destination) {
        int sourceRow = 8 - (source[1] - '0');
        int sourceCol = source[0] - 'a';
        int destRow = 8 - (destination[1] - '0');
        int destCol = destination[0] - 'a';

        if (board[sourceRow][sourceCol] == nullptr || board[destRow][destCol] != nullptr) {
            return false;
        }

        char pieceSymbol = board[sourceRow][sourceCol]->getSymbol();

        if (pieceSymbol == 'N' || pieceSymbol == 'n') {
            int rowDiff = sourceRow - destRow;
            int colDiff = sourceCol - destCol;
            if ((rowDiff == 2 && colDiff == 1) || (rowDiff == -2 && colDiff == 1) ||
                (rowDiff == 1 && colDiff == 2) || (rowDiff == -1 && colDiff == 2)) {
                return true;
            } else {
                return false;
            }
        } else if (pieceSymbol == 'P' || pieceSymbol == 'p') {
            int rowDiff = destRow - sourceRow;
            int colDiff = destCol - sourceCol;

            if (board[sourceRow][sourceCol]->getColor() == 'W' && sourceRow == 6) {
                if ((rowDiff == -1 || rowDiff == -2) && colDiff == 0) {
                    return true;
                } else {
                    return false;
                }
            } else if (board[sourceRow][sourceCol]->getColor() == 'B' && sourceRow == 1) {
                if ((rowDiff == 1 || rowDiff == 2) && colDiff == 0) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        return false;
    }

    char getPieceColor(int row) {
        char color;
        if (row < 4) {
            color = 'W';
        } else {
            color = 'B';
        }
        return color;
    }

    string getPieceName(char symbol) {
        string name;
        switch (symbol) {
            case 'R':
                name = "Rook";
                break;
            case 'N':
                name = "Knight";
                break;
            case 'B':
                name = "Bishop";
                break;
            case 'Q':
                name = "Queen";
                break;
            case 'K':
                name = "King";
                break;
            case 'P':
                name = "Pawn";
                break;
            default:
                name = "";
                break;
        }
        return name;
    }
};

int main()
{
    cout << "Ibrahim Johar Farooqi\n23K-0074\n";
    ChessBoard chessBoard;
    chessBoard.display();

    string source, destination;
    cout << "Enter move (source): ";
    cin >> source;

    cout << "Enter move (destination): ";
    cin >> destination;

    if (chessBoard.movePiece(source, destination))
    {
        cout << "Move successful!\n";
        chessBoard.display();
    }
    else
    {
        cout << "Wrong move!\n";
    }

    return 0;
}
