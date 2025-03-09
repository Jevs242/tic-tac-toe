//Jose Velazquez
//Tic Tac Toe

#include "tictactoe.h"

int main() {
    ProcessGames();
    return 0;
}

void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Pause() {
#ifdef _WIN32
    system("pause");
#else
    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
#endif
}

void ProcessGames() {
    srand(time(0));
    int points[2] = { 0 };
    while (true) {
        tictactoe game(points);

        bool turn = (rand() % 2) + 1 - 1;

        while (true) {
            game.RefreshTable();
            game.VerificacionPlay(game.playerPosition, true);
            game.VerificacionPlay(game.aiPosition, false);
            if (game.numberUsed.length() == 9 || game.end) {
                break;
            }
            std::cout << "\n\n";

            if (turn)
                game.ConvertPosition('X', true);
            else
                game.ConvertPosition('O', false);
            turn = !turn;
        }

        std::cout << "\n\n\t";

        if (EndGame(game, points[0], points[1]))
            break;
    }

    std::cout << "THE FINAL SCORE IS " << points[0] << " | " << points[1] << std::endl;
    std::cout << "\n\n";
    Pause();
}

bool EndGame(tictactoe currentGame, int& points1, int& points2) {
    if (currentGame.win && currentGame.end) {
        std::cout << "YOU WIN!";
        points1++;
    }
    else if (!currentGame.win && currentGame.end) {
        std::cout << "YOU LOSE!";
        points2++;
    }
    else
        std::cout << "TIE!";

    std::cout << "\n\n";

    char opc;
    std::cout << "Do you want to play again? Y / N : ";
    std::cin >> opc;
    std::cout << "\n\n";

    return std::toupper(opc) == 'N';
}

void tictactoe::RefreshTable() {
    ClearScreen();
    std::cout << "\tTIC TAC TOE \n" << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "\t";
        for (int j = 0; j < 3; j++) {
            std::cout << table[i][j];
            if (j != 2)
                std::cout << " | ";
        }
        if (i != 2)
            std::cout << "\n\t---------";
        std::cout << std::endl;
    }

    std::cout << "\n\tSCORE " << points[0] << " | " << points[1];
}

void tictactoe::ConvertPosition(char letter, bool player) {
    if (player) {
        ClearScreen();
        RefreshTable();
        std::cout << "\n\n";
        std::cout << "    Write the position : ";
        std::cin >> number;
    }
    else {
        number = (rand() % 9) + 1;
    }

    for (int i = 0; i < numberUsed.length(); i++) {
        if (number == numberUsed[i] - '0') {
            if (player) {
                std::cout << "    This number was used \n";
                Pause();
            }
            ConvertPosition(letter, player);
            return;
        }
    }
    numberUsed += std::to_string(number);

    if (player)
        playerPosition += std::to_string(number);
    else
        aiPosition += std::to_string(number);

    switch (number) {
    case 1:
        table[0][0] = letter;
        break;
    case 2:
        table[0][1] = letter;
        break;
    case 3:
        table[0][2] = letter;
        break;
    case 4:
        table[1][0] = letter;
        break;
    case 5:
        table[1][1] = letter;
        break;
    case 6:
        table[1][2] = letter;
        break;
    case 7:
        table[2][0] = letter;
        break;
    case 8:
        table[2][1] = letter;
        break;
    case 9:
        table[2][2] = letter;
        break;
    default:
        if (player) {
            std::cout << "This position does not exist" << std::endl;
            Pause();
        }
        break;
    }
}

void tictactoe::VerificacionPlay(std::string position, bool player) {
    int point{ 0 };
    for (int o = 0; o < 8; o++) {
        point = 0;
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < position.length(); i++) {
                if (position[i] == posibility[o][j]) {
                    point++;
                    if (point == 3) {
                        end = true;
                        win = player;
                    }
                }
            }
        }
    }
}
