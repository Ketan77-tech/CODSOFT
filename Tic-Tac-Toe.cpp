#include <iostream>
#include <string>

class Game
{
    typedef enum {
        PLAYER_X,
        PLAYER_O,
        NONE
    } Player;

    Player board[3][3];
    Player now;
    Player winner;
public:
    static Player inputPlayer(std::string prompt)
    {
        std::cout << prompt;
        char ch; std::cin >> ch;
        switch (ch) {
            case 'x': case 'X': return PLAYER_X;
            case 'o': case 'O': return PLAYER_O;
            default:
               std::cout << "Invalid player value: '" << ch << "'\n";
               exit(1);
        }
        return PLAYER_X;
    }

    Game(Player p1, Player p2) : winner(NONE)
    {
        if (p1 == p2) {
            std::cout << "Invalid game, both players are same\n";
            exit(1);
        }
        if (p1 == PLAYER_X) now = p1;
        else now = p2;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = NONE;
            }
        }
    }

    void displayBoard()
    {
        std::cout << "Current board:\n";
        std::cout << "   - 1 - 2 - 3 -\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << " " << (i+1) << " | ";
            for (int j = 0; j < 3; ++j) {
                char symbol = (board[i][j] == PLAYER_X) ?
                    'X' : (board[i][j] == NONE) ?
                        ' ' : 'O';
                std::cout << symbol << " | ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    std::pair<int, int> inputCell()
    {
        int row, col;
        while (true) {
            std::cout << "Enter row (1-3) and column (1-3) for Player " << (now == PLAYER_X ? 'X' : 'O') << ": ";
            std::cin >> row >> col;
            if ((row < 1 || row > 3) ||
                (col < 1 || col > 3)) {
                    std::cout << "Invalid row or column value\n";
                    continue;
            } else if (board[row-1][col-1] != NONE) {
                std::cout << "Cell (" << row << ", " << col << ") is already occupied\n";
                continue;
            } else break;
        }
        board[row-1][col-1] = now;
        return { row-1, col-1 };
    }

    void calcWinner(std::pair<int, int> p)
    {
        int i = p.first,
            j = p.second;
        if (checkRow(i, j, now) || checkColumn(i, j, now)) {
            winner = now;
            now = NONE;
            return;
        }
        if (checkDiagonals(now)) {
            winner = now;
            now = NONE;
            return;
        }
        /* count for draw */
        int cnt = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cnt += (board[i][j] != NONE);
        if (cnt == 9)
            winner = now = NONE;
    }

    bool hasEnded()
    {
        return now == NONE;
    }

    void switchPlayer()
    {
        now = (now == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    void displayWinner()
    {
        std::cout << "GAME OVER!\n";
        if (winner == now && now == NONE) {
            std::cout << "It's a draw\n";
            return;
        }
        std::cout << "The winner is Player " << (winner == PLAYER_X ? 'X' : 'O') << std::endl;
    }

private:
    bool checkRow(int row, int col, Player player)
    {
        for (int j = 0; j < 3; ++j) {
            if (board[row][j] != player) {
                return false;
            }
        }
        return true;
    }

    bool checkColumn(int row, int col, Player player)
    {
        for (int i = 0; i < 3; ++i) {
            if (board[i][col] != player) {
                return false;
            }
        }
        return true;
    }

    bool checkDiagonals(Player player)
    {
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
                return true;
        }
        return false;
    }
};

int main()
{
    while (true) {
        Game game(
            Game::inputPlayer("Enter player 1 (X/O): "),
            Game::inputPlayer("Enter player 2 (X/O): "));
        game.displayBoard();
        while (true) {
            auto p = game.inputCell();
            game.displayBoard();
            game.calcWinner(p);
            if (game.hasEnded()) break;
            game.switchPlayer();
        }
        game.displayWinner();
        std::cout << "\nEnter Y to replay, quit otherwise: ";
        char ch; std::cin >> ch;
        switch (ch) {
            case 'y': case 'Y': continue;
            default: exit(0);
        }
    }
    return 0;
}
