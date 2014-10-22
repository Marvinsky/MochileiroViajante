/*
 * Caixero.h
 *
 *  Created on: 08/09/2014
 *      Author: Marvin
 */

#ifndef CAIXERO_H_
#define CAIXERO_H_

#include <vector>

class Caixeiro {
private:
	int nrocities;
	int** matrixCidades;
	std::vector<int> cities;

	std::vector<int> citiesGreedy;

public:
	int getNrocidades();
	void setNroidades(int c);
	int** getMatrixCidades();
	void setMatrixCidades(int** mcidades);

	void setCidades(std::vector<int> c);

	//Metodos greddy para el caixeiro viajante
	void init();
	void escogerLaMenorDistancia();
	bool isIndexAsigned(int j, int tam);

	std::vector<int> getCitiesGreedy();
	void setCitiesGreedy(std::vector<int> citiesGreedy);

};

#endif /* CAIXERO_H_ */
