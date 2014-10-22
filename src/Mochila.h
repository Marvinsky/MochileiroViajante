/*
 * Mochila.h
 *
 *  Created on: 07/09/2014
 *      Author: Marvin
 */

#ifndef MOCHILA_H_
#define MOCHILA_H_

#include <vector>

class Mochila {
private:
	int nroitems;
	int capacidadMochila;
	int** matrixItems;

	std::vector<int> items;

	std::vector<int> values;
	std::vector<int> pesos;
	std::vector<int> x;
	double** matrix;

public:
	void Init();
	int getNroitems();
	void setNroitems(int i);
	int getCapacidadMochile();
	void setCapacidadMochile(int c);
	int** getMatrixItems();
	void setMatrixItems(int** mitems);

	void setItems(std::vector<int> i);

	//Metodos greddy para La mochila - escoger los items mas valiosos
	void escogerItemsValiosos();
	void computeWeigthRatios();
	void sortMatrix(double** matrix);

	std::vector<int> getX();
	void setX(std::vector<int> x);
	void removeandaddthemochila();

};

#endif /* MOCHILA_H_ */
