#ifndef ANIMAL_H
#define ANIMAL_H
#include "Gene.h"

using namespace std;

class Animal {
private:
	Gene gene;
	char type;
public:
	Animal();
	Animal(Gene g, char t);
	Gene getGenes();
	char getType();
};
#endif // !ANIMAL_H
#pragma once
