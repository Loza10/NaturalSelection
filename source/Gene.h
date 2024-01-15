#ifndef GENE_H
#define GENE_H

class Gene {
private:
	double speed;
public:
	Gene() {
		speed = 0;
	}
	Gene(double s) {
		speed = s;
	}
	double getSpeed() {
		return speed;
	}
	void setSpeed(double s) {
		speed = s;
	}
};

#endif // !GENE_H
#pragma once
