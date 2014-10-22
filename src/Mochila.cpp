/*
 * Mochila.cpp
 *
 *  Created on: 07/09/2014
 *      Author: Marvin
 */

#include "Mochila.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

/**metodos da clase Mochile**/

int Mochila::getNroitems() {
	return nroitems;
}

void Mochila::setNroitems(int i) {
	this->nroitems = i;
}

int Mochila::getCapacidadMochile() {
	return capacidadMochila;
}

void Mochila::setCapacidadMochile(int c) {
	this->capacidadMochila = c;
}

void Mochila::setItems(std::vector<int> i) {
	this->items = i;
}

int** Mochila::getMatrixItems() {
	return matrixItems;
}

void Mochila::setMatrixItems(int** mitems) {
	this->matrixItems = mitems;
}

std::vector<int> Mochila::getX() {
	return x;
}

void Mochila::setX(std::vector<int> xmochila) {
	this->x = xmochila;
}

void Mochila::Init() {
	matrix = new double*[getNroitems()];
	for (int i = 0; i < getNroitems(); i++) {
		x.insert(x.begin() + i, 0);
		values.insert(values.begin() + i, matrixItems[i][1]);
		pesos.insert(pesos.begin() + i, matrixItems[i][2]);
		matrix[i] = new double[2];
	}
}

void Mochila::computeWeigthRatios() {
	double ratio;
	for (int i = 0; i < getNroitems(); i++) {
		ratio = (double) values.at(i) / pesos.at(i);
		matrix[i][0] = i;
		matrix[i][1] = ratio;
	}
	sortMatrix(matrix);
}

void Mochila::sortMatrix(double** matrix) {
	double temp1, temp2;
	for (int i = 0; i < getNroitems() - 1; i++) {
		for (int j = i + 1; j < getNroitems(); j++) {
			if (matrix[i][1] < matrix[j][1]) {
				temp1 = matrix[j][1];
				matrix[j][1] = matrix[i][1];
				matrix[i][1] = temp1;

				temp2 = matrix[j][0];
				matrix[j][0] = matrix[i][0];
				matrix[i][0] = temp2;
			}
		}
	}
}

void Mochila::escogerItemsValiosos() {
	double suma = 0.0;
	computeWeigthRatios();
	int index = 0;
	for (int i = 0; i < getNroitems(); i++) {
		index = matrix[i][0];
		if (suma + pesos.at(index) < getCapacidadMochile()) {
			suma += pesos.at(index);
			x.at(index) = 1;
		}
	}
}

void Mochila::removeandaddthemochila() {
	for (int i = 0; i < getNroitems(); i++) {
		cout << x.at(i) << endl;
	}
}

