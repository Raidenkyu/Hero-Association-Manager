// Menu example for tjnapster
#include <iostream>
#include <iomanip>
#include "Interface.h"

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

map<string, Hero> association;

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

int first_menu() {
	int x = 17, item = 0;
	cout << "  _    _                                              _       _   _             " << endl;
	cout << " | |  | |                    /\\                      (_)     | | (_)            " << endl;
	cout << " | |__| | ___ _ __ ___      /  \\   ___ ___  ___   ___ _  __ _| |_ _  ___  _ __  " << endl;
	cout << " |  __  |/ _ \\ '__/ _ \\    / /\\ \\ / __/ __|/ _ \\ / __| |/ _` | __| |/ _ \\| '_ \\ " << endl;
	cout << " | |  | |  __/ | | (_) |  / ____ \\\\__ \\__ \\ (_) | (__| | (_| | |_| | (_) | | | |" << endl;
	cout << " |_|  |_|\\___|_|  \\___/  /_/    \\_\\___/___/\\___/ \\___|_|\\__,_|\\__|_|\\___/|_| |_|" << endl;
	cout << "                                                                                " << endl;
	cout << "Lingua/Language:" << endl;
	gotoXY(10, 10); cout << "English";
	gotoXY(25, 10); cout << "Português";
	gotoXY(x, 10); cout << "<-";
	while (true) {
		system("pause>nul");
		if (GetAsyncKeyState(VK_RIGHT) && x != 34) {
			gotoXY(x, 10); cout << "  ";
			x += 17;
			item++;
			gotoXY(x, 10); cout << "<-";
		}
		if (GetAsyncKeyState(VK_LEFT) && x != 17) {
			gotoXY(x, 10); cout << "  ";
			x -= 17;
			item--;
			gotoXY(x, 10); cout << "<-";
		}
		if (GetAsyncKeyState(VK_RETURN)) {
			switch (item) {
			case 0:
				//eng
				clearScreen();
				return 0;
			case 1:
				//port
				clearScreen();
				return 0;
			}
		}
	}

}

void tabela_menu() {
	gotoXY(0, 7);  cout << "+------------------------+";
	gotoXY(0, 8);  cout << "| Menu principal         |";
	gotoXY(0, 9);  cout << "+------------------------+";
	gotoXY(0, 10); cout << "| 1. Adicionar heroi     |";
	gotoXY(0, 11); cout << "| 2. Escolher heroi      |";
	gotoXY(0, 12); cout << "| 3. Remover heroi       |";
	gotoXY(0, 13); cout << "| 4. Combater Vilões     |";
	gotoXY(0, 14); cout << "| 5. Sair                |";
	gotoXY(0, 15); cout << "+------------------------+";
}

void tabela()
{
	int x = 35, y = 0;
	gotoXY(x, y++); cout << "+----------------------+-------+-------+----------+---------+";
	gotoXY(x, y++); cout << "|         Nome         | Força | Nível | Vitórias | Salário |";
	gotoXY(x, y++); cout << "+----------------------+-------+-------+----------+---------+";
		for (auto& it : association) {
			gotoXY(x, y++); cout << left << "|" << setw(22) << it.second.getName()
				<< "|" << setw(7) << it.second.getPower()
				<< "|" << setw(7) << it.second.getLevel()
				<< "|" << setw(10) << it.second.getWins()
				<< "|" << setw(9) << it.second.getSalary() << "|";
			gotoXY(x, y++); cout << "+----------------------+-------+-------+----------+---------+";
		}
}

int menu_principal()
{
	int menu_item = 0, x = 10;
	
		while (true)
		{
			tabela();
			tabela_menu();
			gotoXY(21, x); cout << "<-";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 14) //down button pressed
		{
			gotoXY(21, x); cout << "  ";
			x++;
			gotoXY(21, x); cout << "<-";
			menu_item++;

		}

		if (GetAsyncKeyState(VK_UP) && x != 10) //up button pressed
		{
			gotoXY(21, x); cout << "  ";
			x--;
			gotoXY(21, x); cout << "<-";
			menu_item--;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

			case 0:
				cria_heroi();
				break;

			case 1:
				gotoXY(20, 16);
				cout << "Selecione o heroi";
				escolhe_heroi();
				gotoXY(20, 16);
				cout << "                 ";
				break;

			case 2:
				gotoXY(20, 16);
				cout << "Escolheste 3";
				break;

			case 3:
				gotoXY(20, 16);
				cout << "Escolheste 4";
				break;

			case 4:
				clearScreen();
				cout << "O programa vai encerrar" << endl;
				return 0;
			}
		}
	}
}

int main()
{
	SetPTchar();
	first_menu();
	ler_herois();
    menu_principal();
	cin.get();
	return 0;
}
