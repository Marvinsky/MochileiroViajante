/*
 * Mochileiro.h
 *
 *  Created on: 25/08/2014
 *      Author: Marvin
 */

#ifndef MOCHILEIRO_H_
#define MOCHILEIRO_H_

#include <vector>
#include <locale>

template<class charT, charT sep>
class punct_facet: public std::numpunct<charT> {
protected:
	charT do_decimal_point() const {
		return sep;
	}
};

class Mochileiro {
private:
	int nrocities;
	int nroitems;
	double vmax;
	double vmin;
	int capacity;
	double renting;
	int* nIPC;
	int** matrixCidades;
	int** matrixItems;

	double** matrixIndicePeso;

	std::vector<int> cities;
	std::vector<int> items;

public:
	void init();
	int getNrocities();
	void setNrocities(int c);
	int getNroitems();
	void setNroitems(int i);
	double getVmax();
	void setVmax(double max);
	double getVmin();
	void setVmin(double min);
	int getCapacity();
	void setCapacity(int c);
	double getRenting();
	void setRenting(double r);
	int** getMatrixCidades();
	void setMatrixCidades(int** mcidades);
	int** getMatrixItems();
	void setMatrixItems(int** mitems);
	int* getArrayCidades();
	void setArrayCidades(int* ordencidades);
	int* getArrayItems();
	void setArrayItems(int* ordenitems);

	void carregar(char caminhoArq[]);
	void carregarTodo(char caminhoArq[], char saidaArq[]);
	void setNumeroDeItemsPerCidade(int** matrixItems);
	int* getNumeroDeItemsPerCidade();
	double operator1();
	double operator2();
	double operator3();
	double getDistanceXY(double x1, double y1, double x2, double y2);
	double getPesoUltimoItem();
	double resultadoFinal();
	void imprime();

	//opt2
	void setCities(std::vector<int> v);
	std::vector<int> getCities();
	void setItems(std::vector<int> i);
	std::vector<int> getItems();
	int TourSize() const;
	double getMenorAvaliacao(const std::vector<int>& v);
	//wikipedia
	double DoisOpt();
	void FazerDoisOpt(int i, int j, std::vector<int> citiesOriginal);
	void assignation(std::vector<int> citiesOriginal);
	void sort(std::vector<int> items);
	int** SortingMatrix(int** items, int itemsNumber);
	int excedeCapacidadMochila();

	//For simulating annealing
	std::vector<int> FazerDoisOpt2(int c1, int c2,
			std::vector<int> citiesOriginal);
	double resultadoFinal2(std::vector<int> cities);
	double operator1_2(std::vector<int> cities);
	double operator2_2(std::vector<int> cities);
	double operator3_2(std::vector<int> cities);
};

#endif /* MOCHILEIRO_H_ */
