#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "Interface.h"

using namespace std;

string toUpper(string palavra)
{
	for (unsigned int i = 0; i < palavra.length(); i++)
	{
		if (palavra.at(i) >= 97 && palavra.at(i) <= 122) // todos os caracteres que estão em letra minuscula
		{
			palavra.at(i) = palavra.at(i) - 32; // segundo a tabela ascii a distancia que 'a' esta de 'A' é de 32
		}
	}
	return palavra;
}

void ler_herois() {
	ifstream hero_file("Hero_Data_file.txt");
	Hero h1;
	string nome;
	string power;
	string level;
	string hero;
	string wins;
	string salary;
	stringstream ss;
	try {
		if (hero_file.is_open())
		{
			while (getline(hero_file, hero))
			{
				ss.str(hero);
				getline(ss, nome, ',');
				getline(ss, power, ',');
				getline(ss, level, ',');
				getline(ss, wins, ',');
				getline(ss, salary);
				h1.setStats(nome, (unsigned int)stoi(power), level[1]);
				h1.setSalary((unsigned int)stoi(salary));
				h1.setWin((unsigned int)stoi(wins));
				association[toUpper(nome)] = h1;
				ss.clear();
			}
			hero_file.close();
		}
		else {
			throw runtime_error("Erro: Dados gravados não encontrados");
		}
	}
	catch(runtime_error &e) {
		cerr << e.what() << flush << endl;
		cin.get();
		clearScreen();
	}
}

void cria_heroi() {
	clearScreen();
	Hero h1;
	string nome;
	unsigned int power, wins, salary;
	char level;
	cout << "Nome do heroi: ";
	getline(cin, nome);
	cout << "Força do heroi: ";
	cin >> power;
	cout << "Nível do heroi: ";
	cin >> level;
	h1.setStats(nome, power, level);
	cin.ignore(INT_MAX, '\n');
	clearScreen();
	cout << "Pretende confirmar o seguinte heroi(ENTER/ESC):" << endl;
	cout << "+----------------------+-------+-------+----------+---------+" << endl;
	cout << left << "|" << setw(22) << h1.getName()
		<< "|" << setw(7) << h1.getPower()
		<< "|" << setw(7) << h1.getLevel()
		<< "|" << setw(10) << h1.getWins()
		<< "|" << setw(9) << h1.getSalary() << "|" << endl;
	cout << "+----------------------+-------+-------+----------+---------+";
	while (true) {
		system("pause>nul");
		if (GetAsyncKeyState(VK_RETURN)) {
			association[toUpper(nome)] = h1;
			break;
		}
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
	}
	clearScreen();
}

int modifica_heroi(Hero& h1) {
	int menu_item = 0, x = 10;
	while (true)
	{
		gotoXY(0, 7);  cout << "+------------------------+";
		gotoXY(0, 8);  cout << "| Menu Herói             |";
		gotoXY(0, 9);  cout << "+------------------------+";
		gotoXY(0, 10); cout << "| 1. Treinar heroi       |";
		gotoXY(0, 11); cout << "| 2. Promover heroi      |";
		gotoXY(0, 12); cout << "| 3. Pagar Salário       |";
		gotoXY(0, 13); cout << "| 4. Sair                |";
		gotoXY(0, 14); cout << "+------------------------+";
		gotoXY(0, 15); cout << "                          ";
		gotoXY(21, x); cout << "<-";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 13) //down button pressed
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
		if (GetAsyncKeyState(VK_ESCAPE))
			return 0;

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

			case 0:
				//Cena para treinar o heroi
				break;

			case 1:
				//Cena para mudar o rank do heroi
				break;
			case 2:
				//Pagar Salário
				break;

			case 3:
				return 0;
			}
		}
	}
}

int escolhe_heroi() {
	int menu_item = 0, x = 3;
	map<string, Hero>::iterator it = association.begin();
	while (true)
	{
		tabela_menu();
		gotoXY(100, x); cout << "<-";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x < (association.size()-1)*2 + 2) //down button pressed
		{
			gotoXY(100, x); cout << "  ";
			x+= 2;
			it++;
			gotoXY(100, x); cout << "<-";

		}

		if (GetAsyncKeyState(VK_UP) && x != 3) //up button pressed
		{
			gotoXY(100, x); cout << "  ";
			x-= 2;
			it--;
			gotoXY(100, x); cout << "<-";
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			gotoXY(100, x); cout << "  ";
			return 0;
		}
			

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed
			modifica_heroi(it->second);
			gotoXY(100, x); cout << "  ";
			return 0;
			}
	}
}