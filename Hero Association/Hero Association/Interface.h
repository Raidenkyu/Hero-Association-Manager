#ifdef _WIN32         //Para o windows reconhecer os caracteres portugueses
#include <windows.h>
#define SetPTchar() SetConsoleCP(1252); SetConsoleOutputCP(1252);
#else 
#define SetPTchar() void
#endif

#ifdef _WIN32 //Para limpar o ecrã quer seja em Windows, quer seja em linux
#define clearScreen() system("cls"); 
#else
#define clearScreen() system("clear");
#endif

#ifdef _WIN32 //Para fazer delay quer seja em Windows, quer seja em linux
#define delay() sleep(int sec);
#else
#define delay() Sleep(sec * 1000);
#endif

#include <map>
#include <string>
#include "Hero_Header.h"

using namespace std;

extern HANDLE console; // used for goto
extern COORD CursorPosition; // used for goto
extern map<string, Hero> association;

void gotoXY(int x, int y);
void ler_herois();
string toUpper(string palavra);
void tabela();
void cria_heroi();
int escolhe_heroi();
void tabela_menu();