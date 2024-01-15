#include "Animal.h"

Animal::Animal() {
	gene = Gene();
	type = 'd';
}
Animal::Animal(Gene g, char t) {
	type = t;
	gene = g;
}
Gene Animal::getGenes() {
	return gene;
}
char Animal::getType() {
	return type;
}