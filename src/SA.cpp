/*
 * SA.cpp
 *
 *  Created on: 24/09/2014
 *      Author: Marvin
 */

#include "SA.h"

#include <iostream>
#include <cmath>
#include <fstream>
#include <limits>

using namespace std;

Mochileiro SA::getMochileiro() {
	return this->mochileiro;
}

void SA::setMochileiro(Mochileiro m) {
	this->mochileiro = m;
}

int SA::getNroIterations() {
	return this->nroIterations;
}

void SA::setNroIterations(int iterations) {
	this->nroIterations = iterations;
}

int SA::getNrocidades() {
	return nrocities;
}

void SA::setNrocidades(int nrocidades) {
	this->nrocities = nrocidades;
}

int SA::getNroitems() {
	return nroitems;
}

void SA::setNroitems(int i) {
	this->nroitems = i;
}

int** SA::getMatrixCidades() {
	return this->matrixCidades;
}

void SA::setMatrixCidades(int** matrixCidades) {
	this->matrixCidades = matrixCidades;
}

int** SA::getMatrixItems() {
	return matrixItems;
}

void SA::setMatrixItems(int** mitems) {
	this->matrixItems = mitems;
}

std::vector<int> SA::getCidades() {
	return this->cities;
}

void SA::setCidades(std::vector<int> c) {
	cities = c;
}

int SA::getCapacidadeMochila() {
	return this->capacidadeMochila;
}

void SA::setCapacidadeMochila(int capacidade) {
	this->capacidadeMochila = capacidade;
}

void SA::setCities(std::vector<int> v) {
	cities = v;
}

std::vector<int> SA::getCities() {
	return cities;
}

void SA::setItems(std::vector<int> i) {
	items = i;
}

std::vector<int> SA::getItems() {
	return items;
}

Mochileiro SA::createNewMochileiro(Mochileiro M) {
	Mochileiro novo;
	novo.setNrocities(M.getNrocities());
	novo.setNroitems(M.getNroitems());
	novo.setVmax(M.getVmax());
	novo.setVmin(M.getVmin());
	novo.setCapacity(M.getCapacity());
	novo.setRenting(M.getRenting());
	novo.setNumeroDeItemsPerCidade(M.getMatrixItems());
	novo.setMatrixCidades(M.getMatrixCidades());
	novo.setMatrixItems(M.getMatrixItems());
	novo.setCities(M.getCities());
	novo.setItems(M.getItems());

	return novo;
}

double SA::simulatedAnnealing() {
	Mochileiro M = createNewMochileiro(getMochileiro());

	std::vector<int> S = M.getCities();
	std::vector<int> SBest = S;
	double Y = 0;
	int Q = 20;
	double W = 0.9;
	std::vector<int> Basterisk;
	std::vector<int> Bprima;
	double Bprima2 = 0;
	double SBest2 = 0;
	double infinity = std::numeric_limits<double>::max();
	while (Y < 10) {
		Basterisk = S;
		Bprima2 = infinity;
		std::vector<std::vector<int> > output = SA2opt(Q, S, Basterisk, Bprima,
				M);

		Basterisk = output.at(0);
		Bprima = output.at(1);

		double Basterisk2 = M.resultadoFinal2(Basterisk);

		double S2 = M.resultadoFinal2(S);
		double SBest2 = M.resultadoFinal2(SBest);
		if ((Basterisk2 > S2) && (Basterisk2 > SBest2)) {
			SBest = Basterisk;
		}
		if (Basterisk2 > S2) {
			S = Basterisk;
			Y = 0;
			Q = 4;
		} else {
			if (Bprima2 != infinity) {
				S = Bprima;
			}
			Y++;
			Q = Q * W;
		}
	}
	SBest2 = M.resultadoFinal2(SBest);
	return SBest2;
}

std::vector<std::vector<int> > SA::SA2opt(double Temp, std::vector<int> S,
		std::vector<int> Basterisk, std::vector<int> Bprima, Mochileiro M) {

	std::vector<std::vector<int> > result;

	std::vector<int> citiesOriginal = S;
	double RMIN = 1.0;
	double Basterisk2 = M.resultadoFinal2(Basterisk);
	double FDS = M.resultadoFinal2(S);
	int size = M.TourSize();

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			std::vector<int> B = M.FazerDoisOpt2(i, j, citiesOriginal);

			double newSolution = M.resultadoFinal2(B);
			if (newSolution > Basterisk2) {
				Basterisk = B;
				Basterisk2 = newSolution;
			} else {
				double r = (double) rand() / (1.0 * RAND_MAX);
				const double e = 2.718281828;
				if ((r < pow(e, -(FDS - newSolution) / Temp)) && r < RMIN) {
					Bprima = B;
					RMIN = r;
				}
			}
		}
	}

	result.insert(result.begin() + 0, Basterisk);
	result.insert(result.begin() + 1, Bprima);

	return result;
}

std::vector<int> SA::BL2optILS(std::vector<int> SInicial, Mochileiro M) {

	double firstSolution = M.resultadoFinal2(SInicial);
	double bestSolution = -999999;
	int size = M.TourSize();
	std::vector<int> citiesOriginal = SInicial;

	std::vector<int> bestRoute = cities;
	do {
		if (bestSolution > firstSolution) {
			citiesOriginal = bestRoute;
			firstSolution = bestSolution;
		}

		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				std::vector<int> B = M.FazerDoisOpt2(i, j, citiesOriginal);
				//assignation(citiesOriginal);
				double newSolution = M.resultadoFinal2(B);
				if (newSolution > bestSolution) {
					bestRoute = B;
					bestSolution = newSolution;
				}
			}
		}
	} while (bestSolution > firstSolution);
	//cout << "El mejor valor para esta iteracion fue = " << bestSolution << endl;

	return bestRoute;
}


double SA::ILS() {
	Mochileiro mochileiro = getMochileiro();
	Mochileiro M = createNewMochileiro(mochileiro);
	int maxIter = 20;
	std::vector<int> SCero = M.getCities();
	std::vector<int> S = BL2optILS(SCero, M);
	double S2 = M.resultadoFinal2(S);
	int iter = 0;
	int numeroPerturbations = 3;
	do {
		iter = iter + 1;
		//perturbacao
		std::vector<int> SPrima = pertubation(M, S, numeroPerturbations);
		std::vector<int> SDoisPrima = BL2optILS(SPrima, M);
		double SDoisPrima2 = M.resultadoFinal2(SDoisPrima);
		if (SDoisPrima2 > S2) {
			S2 = SDoisPrima2;
		}
	} while (iter < maxIter);

	return S2;
}

std::vector<int> SA::pertubation(Mochileiro M, std::vector<int> S, int n) {
	std::vector<int> result;
	std::vector<int> result1;
	std::vector<int> result2;
	int size = M.TourSize();
	int r1 = 0;
	int r2 = 0;
	int r3 = 0;
	int r4 = 0;
	int r5 = 0;
	int r6 = 0;

	r1 = rand() % size;
	r2 = rand() % size;
	while (r1 == r2) {
		r1 = rand() % size;
		r2 = rand() % size;
	};
	result = M.FazerDoisOpt2(r1, r2, S);
	r3 = rand() % size;
	r4 = rand() % size;
	while (r3 == r4) {
		r3 = rand() % size;
		r4 = rand() % size;
	};
	result1 = M.FazerDoisOpt2(r3, r4, result);

	r5 = rand() % size;
	r6 = rand() % size;
	while (r5 == r6) {
		r5 = rand() % size;
		r6 = rand() % size;
	};
	result2 = M.FazerDoisOpt2(r5, r6, result1);

	return result2;
}

