#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <stdio.h>
#include <math.h>
#include "Animal.cpp"
#include "Gene.h"

using namespace std;

void simulateDay();
void breedDeer(Animal mom, Animal dad);

vector<Animal> lion;
vector<Animal> deer;

int main() {
	srand(time(NULL));
	int day = 0;
	double deerSpeed = 0;
	double lionSpeed = 0;
	for (int i = 0; i < 20; i++) {
		lion.push_back(Animal(Gene(0), 'l'));
	}
	for (int i = 0; i < 40; i++) {
		deer.push_back(Animal(Gene(1), 'd'));
	}
	while (deer.size() > 0 && lion.size() > 2) {
		simulateDay();
		day++;
		if (deer.size() > 1) {
			int size = deer.size();
			for (int i = 0; i < size / 3; i++) {
				int mom = rand() % deer.size();
				int dad = rand() % deer.size();
				breedDeer(deer.at(mom), deer.at(dad));
			}
		}
		if (lion.size() > 1) {
			int size = lion.size();
			for (int i = 0; i < size / 3; i++) {
				int mom = rand() % lion.size();
				int dad = rand() % lion.size();
				breedDeer(lion.at(mom), lion.at(dad));
			}
		}
		cout << "Day: " << day << endl;
		cout << "Lion AMT: " << lion.size() << endl;
		cout << "Deer AMT: " << deer.size() << endl;
		for (int i = 0; i < deer.size(); i++) {
			if (i == 0) {
				deerSpeed = deer.at(i).getGenes().getSpeed();
			}
			else {
				if (deerSpeed < deer.at(i).getGenes().getSpeed()) {
					deerSpeed = deer.at(i).getGenes().getSpeed();
				}
			}
		}
		for (int i = 0; i < lion.size(); i++) {
			if (i == 0) {
				lionSpeed = lion.at(i).getGenes().getSpeed();
			}
			else {
				if (lionSpeed < lion.at(i).getGenes().getSpeed()) {
					lionSpeed = lion.at(i).getGenes().getSpeed();
				}
			}
		}
		cout << "Highest Lion Speed: " << lionSpeed << endl;
		cout << "Highest Deer Speed: " << deerSpeed << endl << endl;

	}
	cout << "Made it to day: " << day;
	return 0;
}
void simulateDay() {
	for (int i = 0; i < lion.size(); i++) {
		if (deer.size() > 0 && lion.size() > 0) {
			int pos = rand() % deer.size();
			int multiplier = deer.at(pos).getGenes().getSpeed() - lion.at(i).getGenes().getSpeed();
			if ((multiplier * ((rand() % 10 + 1) * 0.1)) < 0.5) {
				deer.erase(deer.begin() + pos);
			}
			else {
				lion.erase(lion.begin() + i);
				i--;
			}
		}
		else {
			break;
		}
	}
}
void breedDeer(Animal mom, Animal dad) {
	int parent = rand() % 2 + 1;
	if (parent == 1) {
		if ((((rand() % 10 + 1) * 0.1) * lion.size() / deer.size() > 0.05) && mom.getType() == 'd') {
			double updatedSpeed = mom.getGenes().getSpeed() + 0.2;
			deer.push_back(Animal(Gene(updatedSpeed), 'd'));
		}
		else if ((((rand() % 10 + 1) * 0.1) * lion.size() / deer.size() < 1.0) && mom.getType() == 'l') {
			double updatedSpeed = mom.getGenes().getSpeed() + 0.1;
			lion.push_back(Animal(Gene(updatedSpeed), 'l'));
		}
		else {
			if (mom.getType() == 'd') {
				deer.push_back(Animal(Gene(mom.getGenes().getSpeed()), 'd'));
			}
			else {
				lion.push_back(Animal(Gene(mom.getGenes().getSpeed()), 'l'));
			}
		}
	}
	else {
		if ((((rand() % 10 + 1) * 0.1) * lion.size() / deer.size() > 0.5) && dad.getType() == 'd') {
			double updatedSpeed = dad.getGenes().getSpeed() + 0.2;
			deer.push_back(Animal(Gene(updatedSpeed), 'd'));
		} else if((((rand() % 10 + 1) * 0.1) * lion.size() / deer.size() < 1.0) && dad.getType() == 'l') {
			double updatedSpeed = dad.getGenes().getSpeed() + 0.1;
			lion.push_back(Animal(Gene(updatedSpeed), 'l'));
		}
		else {
			if (dad.getType() == 'd') {
				deer.push_back(Animal(Gene(dad.getGenes().getSpeed()), 'd'));
			}
			else {
				lion.push_back(Animal(Gene(dad.getGenes().getSpeed()), 'l'));
			}
		}
	}
}
