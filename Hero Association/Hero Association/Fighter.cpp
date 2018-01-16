#include <iostream>
#include "Interface.h"

using namespace std;

string Fighter::getName(){
	return this->name;
}

unsigned int Fighter::getPower() {
	return this->power;
}

char Fighter::getLevel() {
	return this->level;
}

void Fighter::setPower(unsigned int power) {
	this->power = power;
}

void Fighter::setLevel(char level) {
	this->level = level;
}

void Fighter::setStats(string name, unsigned int power, char level) {
	this->name = name;
	this->power = power;
	this->level = level;
}

unsigned int Hero::getWins() {
	return this->wins;
}

unsigned int Hero::getSalary() {
	return this->salary;
}

void Hero::setWin(unsigned int nWins) {
	this->wins = nWins;
}
void Hero::setSalary(unsigned int salary) {
	this->salary = salary;
}

void Hero::addWin() {
	this->wins++;
}

void Hero::paySalary() {
	this->salary = this->getPower() *(this->getWins() + 1);
}

void fight() {

}