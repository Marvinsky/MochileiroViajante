/*
 * SimulatedAnnealing.h
 *
 *  Created on: 24/09/2014
 *      Author: Marvin
 */

#ifndef SA_H_
#define SA_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <fstream>

#include "Mochileiro.h"

#include <vector>

class SA {
private:
	int nrocities;
	int nroitems;
	int nroIterations;
	int** matrixCidades;
	int** matrixItems;
	std::vector<int> cities;
	std::vector<int> items;
	int capacidadeMochila;

	Mochileiro mochileiro;

	std::vector<double> vectorOpt;

public:

	Mochileiro getMochileiro();
	void setMochileiro(Mochileiro m);

	int getNroIterations();
	void setNroIterations(int iterations);
	int getNrocidades();
	void setNrocidades(int c);
	int getNroitems();
	void setNroitems(int i);
	int** getMatrixCidades();
	void setMatrixCidades(int** mcidades);
	int** getMatrixItems();
	void setMatrixItems(int** mitems);
	std::vector<int> getCidades();
	void setCidades(std::vector<int> c);
	int getCapacidadeMochila();
	void setCapacidadeMochila(int capacidade);
	//opt2
	void setCities(std::vector<int> v);
	std::vector<int> getCities();
	void setItems(std::vector<int> i);
	std::vector<int> getItems();

	double simulatedAnnealing();
	std::vector<std::vector<int> > SA2opt(double Temp, std::vector<int> S,
			std::vector<int> Basterisk, std::vector<int> Bprima, Mochileiro M);
	//double resultadoFinalByRoute(Mochileiro M);
	Mochileiro createNewMochileiro(Mochileiro M);

	//Implement ILS
	double ILS();
	std::vector<int> BL2optILS(std::vector<int> Sinicial, Mochileiro M);
	std::vector<int> pertubation(Mochileiro M, std::vector<int> S,
			int numPerturbations);

};

#endif /* SIMULATEDANNEALING_H_ */
