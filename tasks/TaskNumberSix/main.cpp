#include "coins.h"

int main() {
	coin_placement game("task_info.txt");
	game.calculate();

	system("Pause");
	return 0;
}