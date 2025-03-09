//Jose Velazquez
//TIC TAC TOE

#pragma once
#include <iostream>
#include <string>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

class tictactoe {
private:
	int number = 0;

	char table[3][3] = {
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
	};
	char posibility[8][8] = {
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
	{'1','4','7'},
	{'2','5','8'},
	{'3','6','9'},
	{'1','5','9'},
	{'3','5','7'}
	};
public:

	tictactoe(int point[2])
	{
		points[0] = point[0];
		points[1] = point[1];
	}

	int points[2] = { 0 };

	bool win = false;
	bool end = false;

	std::string playerPosition{ "" };
	std::string aiPosition{ "" };
	std::string numberUsed{ "" };

	void RefreshTable();
	void ConvertPosition(char lettle, bool player);
	void VerificacionPlay(std::string position, bool player);
};

void ProcessGames();
bool EndGame(tictactoe currentGame, int& points1 , int& points2);
