#include <string>

using namespace std;

#pragma once

class Fighter {
public:
	string getName();
	unsigned int getPower();
	char getLevel();
	void setPower(unsigned int power);
	void setLevel(char level);
	void setStats(string name, unsigned int power, char level);
private:
	string name;
	unsigned int power;
	char level;
};

class Hero:public Fighter {
public:
	unsigned int getWins();
	unsigned int getSalary();
	void setWin(unsigned int nWins);
	void setSalary(unsigned int salary);
	void addWin();
	void paySalary();
private:
	unsigned int wins = 0;
	unsigned int salary = 0;
};

class Villain :public Fighter {};



