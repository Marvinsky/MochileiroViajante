/*
 * Caixeiro.cpp
 *
 *  Created on: 08/09/2014
 *      Author: Marvin
 */

#include "Caixeiro.h"
#include "Mochileiro.h"
#include <iostream>
#include <cmath>

using namespace std;

int Caixeiro::getNrocidades() {
	return nrocities;
}

void Caixeiro::setNroidades(int c) {
	nrocities = c;
}

int** Caixeiro::getMatrixCidades() {
	return matrixCidades;
}

void Caixeiro::setMatrixCidades(int** mcidades) {
	matrixCidades = mcidades;
}

void Caixeiro::setCidades(std::vector<int> c) {
	cities = c;
}

std::vector<int> Caixeiro::getCitiesGreedy() {
	return citiesGreedy;
}

void Caixeiro::setCitiesGreedy(std::vector<int> cGreedy) {
	citiesGreedy = cGreedy;
}

void Caixeiro::init() {
	for (int i = 0; i < getNrocidades(); i++) {
		citiesGreedy.insert(citiesGreedy.begin() + i, 0);
	}
}

bool Caixeiro::isIndexAsigned(int j, int tam) {
	for (int i = 0; i < tam; i++) {
		if (citiesGreedy[i] == j) {
			return true;
		}
	}
	return false;
}

void Caixeiro::escogerLaMenorDistancia() {
	int indiceMenor = 0;
	double distancia = 0.0;
	citiesGreedy[0] = 0;
	for (int i = 0; i < getNrocidades() - 1; i++) {
		double distanciaCorta = 1000;
		for (int j = 0; j < getNrocidades(); j++) {
			Mochileiro M;
			distancia = M.getDistanceXY(matrixCidades[citiesGreedy[i]][1],
					matrixCidades[citiesGreedy[i]][2], matrixCidades[j][1],
					matrixCidades[j][2]);
			if ((distancia < distanciaCorta) && !isIndexAsigned(j, i + 1)) {
				distanciaCorta = distancia;
				indiceMenor = j;
			}
		}
		citiesGreedy[i + 1] = indiceMenor;
	}

	for (int i = 0; i < getNrocidades(); i++) {
		citiesGreedy[i] = citiesGreedy[i] + 1;
	}
}
