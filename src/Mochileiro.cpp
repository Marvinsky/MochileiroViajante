/*
 * Mochileiro.cpp
 *
 *  Created on: 25/08/2014
 *      Author: Marvin
 */

#include "Mochileiro.h"
#include "Mochila.h"
#include "Caixeiro.h"
#include "SA.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

/***** Métodos da classe Mochileiro *****/
int Mochileiro::getNrocities() {
	return nrocities;
}

void Mochileiro::setNrocities(int c) {
	this->nrocities = c;
}

int Mochileiro::getNroitems() {
	return nroitems;
}

void Mochileiro::setNroitems(int i) {
	this->nroitems = i;
}

double Mochileiro::getVmax() {
	return vmax;
}

void Mochileiro::setVmax(double max) {
	this->vmax = max;
}

double Mochileiro::getVmin() {
	return vmin;
}

void Mochileiro::setVmin(double min) {
	this->vmin = min;
}

int Mochileiro::getCapacity() {
	return capacity;
}

void Mochileiro::setCapacity(int c) {
	this->capacity = c;
}

double Mochileiro::getRenting() {
	return renting;
}

void Mochileiro::setRenting(double r) {
	this->renting = r;
}

int* Mochileiro::getNumeroDeItemsPerCidade() {
	return nIPC;
}

void Mochileiro::setNumeroDeItemsPerCidade(int** matrixitems) {
	nIPC = new int[getNrocities()];
	//no consideramos la ciudad numero 1, i = 2
	for (int i = 0; i < nrocities; i++) {
		int count = 0;
		for (int j = 0; j < nroitems; j++) {
			if (i + 1 == matrixitems[j][3]) {
				count++;
			}
			nIPC[i] = count;
		}
	}
}

int** Mochileiro::getMatrixCidades() {
	return matrixCidades;
}

void Mochileiro::setMatrixCidades(int** mcidades) {
	this->matrixCidades = mcidades;
}

int** Mochileiro::getMatrixItems() {
	return matrixItems;
}

void Mochileiro::setMatrixItems(int** mitems) {
	this->matrixItems = mitems;
}

double Mochileiro::operator1() {
	int count = 0;
	double primeraSuma = 0.0;
	for (int i = 0; i < getNrocities(); i++) {
		int n = nIPC[i];
		int suma = 0;
		for (int k = 0; k < n; k++) {
			if (items.at(count) == 1) {
				suma += this->matrixItems[count][1];
			}
			count++;
		}
		primeraSuma += suma;
	}
	return primeraSuma;
}

double Mochileiro::operator2() {
	double wx = getPesoUltimoItem(), vpromedio = (abs((vmax - vmin))
			/ this->capacity), dxndx1, denominador, op2;

	int xn = cities.at(getNrocities() - 1), x1 = cities.at(0);
	dxndx1 = getDistanceXY(matrixCidades[x1 - 1][1], matrixCidades[x1 - 1][2],
			matrixCidades[xn - 1][1], matrixCidades[xn - 1][2]);

	denominador = 1 - (vpromedio) * wx;

	op2 = dxndx1 / denominador;
	return op2;
}

double Mochileiro::operator3() {
	double* distancia = new double[nrocities - 1];
	for (int i = 0; i < nrocities - 1; i++) {
		distancia[i] = getDistanceXY(matrixCidades[cities.at(i) - 1][1],
				matrixCidades[cities.at(i) - 1][2],
				matrixCidades[cities.at(i + 1) - 1][1],
				matrixCidades[cities.at(i + 1) - 1][2]);
	}
	int count = 0;
	int* countItems = new int[nrocities - 1];
	int wx;
	for (int i = 0; i < nrocities; i++) {
		wx = 0;
		int n = nIPC[i];
		for (int k = 0; k < n; k++) {
			if (items.at(count) == 1) {
				wx += matrixItems[count][2];
			}
			count++;
		}
		countItems[i] = wx;
	}

	double op3 = 0.0, vpromedio = abs((vmax - vmin)) / getCapacity(), weight =
			0.0;

	for (int i = 0; i < getNrocities() - 1; i++) {
		weight += countItems[cities.at(i) - 1];
		double denominador = getVmax() - vpromedio * weight;
		double numerador = distancia[i];
		op3 += numerador / denominador;
	}
	return op3;
}

int Mochileiro::excedeCapacidadMochila() {
	int counter = 0;
	int suma = 0.0;
	for (int i = 0; i < getNrocities(); i++) {
		int n = nIPC[i];
		for (int i = 0; i < n; i++) {
			if (items.at(counter) == 1) {
				suma += matrixItems[counter][2];
			}
			counter++;
		}
	}
	return suma;
}

double Mochileiro::resultadoFinal() {
	double final = 0.0;
	bool test = true;
	if (test) {
		final = operator1() - (getRenting()) * (operator2() + operator3());
	} else {
		if (excedeCapacidadMochila() < getCapacity()) {
			final = operator1() - (getRenting()) * (operator2() + operator3());
		} else {
			cout << "INFEASIBLE" << endl;
		}
	}

	return final;
}

double Mochileiro::resultadoFinal2(std::vector<int> cities) {
	double final = 0.0;
	bool test = true;
	if (test) {
		final = operator1_2(cities)
				- (getRenting()) * (operator2_2(cities) + operator3_2(cities));
	} else {
		if (excedeCapacidadMochila() < getCapacity()) {
			final = operator1_2(cities)
					- (getRenting())
							* (operator2_2(cities) + operator3_2(cities));
		} else {
			cout << "INFEASIBLE" << endl;
		}
	}

	return final;
}

double Mochileiro::operator1_2(std::vector<int> cities) {
	int count = 0;
	double primeraSuma = 0.0;
	for (std::vector<int>::size_type i = 0; i < cities.size(); i++) {
		int n = nIPC[i];
		int suma = 0;
		for (int k = 0; k < n; k++) {
			if (items.at(count) == 1) {
				suma += this->matrixItems[count][1];
			}
			count++;
		}
		primeraSuma += suma;
	}
	return primeraSuma;
}

double Mochileiro::operator2_2(std::vector<int> cities) {
	double wx = getPesoUltimoItem(), vpromedio = (abs((vmax - vmin))
			/ this->capacity), dxndx1, denominador, op2;

	int xn = cities.at(cities.size() - 1), x1 = cities.at(0);
	dxndx1 = getDistanceXY(matrixCidades[x1 - 1][1], matrixCidades[x1 - 1][2],
			matrixCidades[xn - 1][1], matrixCidades[xn - 1][2]);

	denominador = 1 - (vpromedio) * wx;

	op2 = dxndx1 / denominador;
	return op2;
}

double Mochileiro::operator3_2(std::vector<int> cities) {
	int nrocities = cities.size();
	double* distancia = new double[nrocities - 1];
	for (int i = 0; i < nrocities - 1; i++) {
		distancia[i] = getDistanceXY(matrixCidades[cities.at(i) - 1][1],
				matrixCidades[cities.at(i) - 1][2],
				matrixCidades[cities.at(i + 1) - 1][1],
				matrixCidades[cities.at(i + 1) - 1][2]);
	}
	int count = 0;
	int* countItems = new int[nrocities - 1];
	int wx;
	for (int i = 0; i < nrocities; i++) {
		wx = 0;
		int n = nIPC[i];
		for (int k = 0; k < n; k++) {
			if (items.at(count) == 1) {
				wx += matrixItems[count][2];
			}
			count++;
		}
		countItems[i] = wx;
	}

	double op3 = 0.0, vpromedio = abs((vmax - vmin)) / getCapacity(), weight =
			0.0;

	for (int i = 0; i < nrocities - 1; i++) {
		weight += countItems[cities.at(i) - 1];
		double denominador = getVmax() - vpromedio * weight;
		double numerador = distancia[i];
		op3 += numerador / denominador;
	}
	return op3;
}

//Utilitarios
double Mochileiro::getDistanceXY(double x1, double y1, double x2, double y2) {
	double distancex, distancey, calcdistance;
	distancex = pow((x2 - x1), 2);
	distancey = pow((y2 - y1), 2);

	calcdistance = sqrt(distancex + distancey);
	return calcdistance;
}

//Peso del ultimo item siempre va a contener el total de items recolectados
double Mochileiro::getPesoUltimoItem() {
	int count = 0;
	double wx = 0.0;

	for (int i = 0; i < nrocities; i++) {
		int n = nIPC[i];
		for (int k = 0; k < n; k++) {
			if (items.at(count) == 1) {
				wx += matrixItems[count][2];
			}
			count++;
		}
	}
	return wx;
}

double Mochileiro::DoisOpt() {
	double firstSolution = resultadoFinal();
	double bestSolution = -999999;
	int size = TourSize();
	std::vector<int> citiesOriginal = cities;

	std::vector<int> bestRoute = cities;
	do {
		if (bestSolution > firstSolution) {
			citiesOriginal = bestRoute;
			firstSolution = bestSolution;
		}

		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				FazerDoisOpt(i, j, citiesOriginal);
				//assignation(citiesOriginal);
				double newSolution = resultadoFinal();
				if (newSolution > bestSolution) {
					bestRoute = cities;
					bestSolution = newSolution;
				}
			}
		}
		//cout << "El mejor valor para esta iteracion fue = " << bestSolution
		//	<< endl;
	} while (bestSolution > firstSolution);

	if (firstSolution != -999999) {
		return bestSolution;
	} else {
		cout << "no hay valor maximo 2 opt." << endl;
	}
	return 0.0;
}

std::vector<int> Mochileiro::FazerDoisOpt2(int c1, int c2,
		std::vector<int> citiesOriginal) {
	std::vector<int> result;
	int size = citiesOriginal.size();
	int* newRoute = new int[size];
	int temp = c2;
	for (int i = 0; i < c1; i++) {
		//newRoute.insert(newRoute.begin() + i, cities.at(i));
		newRoute[i] = citiesOriginal[i];
	}

	for (int i = c1; i <= c2; i++) {
		if (i == 0) {
			//newRoute.insert(newRoute.begin(), cities.at(i));
			newRoute[i] = citiesOriginal[i];
		} else {
			//newRoute.insert(newRoute.begin() + i, cities.at(temp));
			newRoute[i] = citiesOriginal[temp];
			temp = temp - 1;
		}
	}

	for (int i = c2 + 1; i < size; i++) {
		//newRoute.insert(newRoute.begin() + i, cities.at(i));
		newRoute[i] = citiesOriginal[i];
	}

	for (int i = 0; i < size; i++) {
		result.insert(result.begin() + i, newRoute[i]);
	}
	return result;

}

void Mochileiro::FazerDoisOpt(int c1, int c2, std::vector<int> citiesOriginal) {
	int size = citiesOriginal.size();
	int* newRoute = new int[size];
	int temp = c2;
	for (int i = 0; i < c1; i++) {
		//newRoute.insert(newRoute.begin() + i, cities.at(i));
		newRoute[i] = citiesOriginal[i];
	}

	for (int i = c1; i <= c2; i++) {
		if (i == 0) {
			//newRoute.insert(newRoute.begin(), cities.at(i));
			newRoute[i] = citiesOriginal[i];
		} else {
			//newRoute.insert(newRoute.begin() + i, cities.at(temp));
			newRoute[i] = citiesOriginal[temp];
			temp = temp - 1;
		}
	}

	for (int i = c2 + 1; i < size; i++) {
		//newRoute.insert(newRoute.begin() + i, cities.at(i));
		newRoute[i] = citiesOriginal[i];
	}
	/*
	 for (int i = 0; i < size; i++) {
	 citiesOriginal[i] = newRoute[i];
	 }
	 */
	for (int i = 0; i < size; i++) {
		cities[i] = newRoute[i];
	}

}

void Mochileiro::assignation(std::vector<int> citiesOriginal) {
	int size = citiesOriginal.size();
	for (int i = 0; i < size; i++) {
		cities[i] = citiesOriginal.at(i);
	}
}

double Mochileiro::getMenorAvaliacao(const std::vector<int>& v) {
	double ini = 10000;
	for (int i = 0; i < getNrocities(); i++) {
		if (ini > v.at(i)) {
			ini = v.at(i);
		}
	}
	return ini;
}

int Mochileiro::TourSize() const {
	return (int) cities.size();
}

void Mochileiro::setCities(std::vector<int> v) {
	cities = v;
}

std::vector<int> Mochileiro::getCities() {
	return cities;
}

void Mochileiro::setItems(std::vector<int> i) {
	items = i;
}

std::vector<int> Mochileiro::getItems() {
	return items;
}

void Mochileiro::carregarTodo(char caminhoArq[], char saidaArq[]) {
	std::fstream file(caminhoArq);
	string instancia;
	int totalInstancias;
	file >> totalInstancias;
	std::vector<double> media;
	std::vector<double> media2;
	int counter = 0;
	int counter2 = 0;
	char saida2opt[] =
			"C:\\Users\\Marvin\\Desktop\\Metaheuristica\\resultado\\resultado2.txt";
	ofstream arq(saidaArq);
	ofstream arq2opt(saida2opt);
	std::cout.imbue(
			std::locale(std::cout.getloc(), new punct_facet<char, ','>));
	arq << "Resultados : \n";
	for (int i = 0; i < totalInstancias; i++) {
		file >> instancia;
		string path;

		path = "C:/Users/Marvin/Desktop/Metaheuristica/todasInstancias";
		path += "/" + instancia;
		path += string(".pmv");
		char *c = const_cast<char*>(path.c_str());

		Mochileiro M;
		M.carregar(c);

		Mochila C;
		C.setItems(M.getItems());
		C.setNroitems(M.getNroitems());
		C.setCapacidadMochile(M.getCapacity());
		C.setMatrixItems(M.getMatrixItems());
		C.Init();
		C.escogerItemsValiosos();

		Caixeiro X;
		X.setNroidades(M.getNrocities());
		X.setCidades(M.getCities());
		X.setMatrixCidades(M.getMatrixCidades());
		X.init();
		X.escogerLaMenorDistancia();

		M.setCities(X.getCitiesGreedy());
		M.setItems(C.getX());
		double result = M.resultadoFinal();
		//cout << instancia << " : " << result << "\n";
		//double doisopt = M.DoisOpt(); If it is applied the new solution will be optimal.
		//cout << instancia << " : " << doisopt << "\n";

		arq << "\n";
		arq << result;
		//arq << "\n";
		media.insert(media.begin() + i, M.resultadoFinal());
		counter++;
		if (counter % 10 == 0) {
			double suma = 0.0;
			double m = 0.0;
			int inicio = counter - 10;
			int final = counter;
			for (int i = inicio; i < final; i++) {
				suma += media.at(i);
			}
			m = suma / 10;
			cout << "media = " << m << endl;
			arq << "media = ";
			arq << m;
			//arq << "\n";
		}

		//Simulating Annealing
		SA s;
		s.setNrocidades(M.getNrocities());
		s.setNroIterations(10);
		s.setCities(M.getCities());
		s.setMochileiro(M);

		//double simulatingAnnealing = s.simulatedAnnealing();
		//cout << instancia << " : " << simulatingAnnealing << endl;
		double ILS = s.ILS();
		//cout << instancia << ":" << ILS << endl;
		//std::cout << "My age is " << 3.1415 << " lightyears.\n";
		cout << ILS << endl;
		double max = ILS;
		media2.insert(media2.begin() + i, max);
		counter2++;
		//cout << "Optimum = " << max << endl;
		//arq << "Optimum = ";
		arq2opt << max;
		//arq << "\n";

		if (counter2 % 10 == 0) {
			double suma2 = 0.0;
			double m2 = 0.0;
			int inicio = counter2 - 10;
			int final = counter2;
			for (int i = inicio; i < final; i++) {
				suma2 += media2.at(i);
			}
			m2 = suma2 / 10;
			cout << "La media es = " << m2 << endl;
			arq2opt << "\n";
			arq2opt << "media = ";
			arq2opt << m2;
			//arq << "\n";
		}

	}
	arq.close();
	arq2opt.close();
}
void Mochileiro::carregar(char caminhoArq[]) {
	std::fstream file3(caminhoArq);
	char str[100];
	int nrocities;
	int nroitems;
	int capacity;
	double vmin;
	double vmax;
	double renting;

	file3 >> str;
	file3 >> str;
	file3 >> str;
	file3 >> nrocities;
	file3 >> str;
	file3 >> nroitems;
	file3 >> str;
	file3 >> capacity;
	file3 >> str;
	file3 >> vmin;
	file3 >> str;
	file3 >> vmax;
	file3 >> str;
	file3 >> renting;
	file3 >> str;
	file3 >> str;
	file3 >> str;
	file3 >> str;

	int** matrixcidades = new int*[nrocities];
	int** matrixitems = new int*[nroitems];

	for (int i = 0; i < nrocities; i++) {
		matrixcidades[i] = new int[3];
	}

	for (int i = 0; i < nroitems; i++) {
		matrixitems[i] = new int[4];
	}

	for (int i = 0; i < nrocities; i++) {
		for (int j = 0; j < 3; j++) {
			file3 >> matrixcidades[i][j];
		}
	}

	file3 >> str;
	file3 >> str;
	file3 >> str;
	file3 >> str;
	file3 >> str;

	for (int i = 0; i < nroitems; i++) {
		for (int j = 0; j < 4; j++) {
			file3 >> matrixitems[i][j];
		}
	}

	setNrocities(nrocities);
	setNroitems(nroitems);
	setVmax(vmax);
	setVmin(vmin);
	setCapacity(capacity);
	setRenting(renting);
	int** matrixItemsSorted = SortingMatrix(matrixitems, nroitems);
	setMatrixCidades(matrixcidades);
	setMatrixItems(matrixItemsSorted);
	setNumeroDeItemsPerCidade(matrixitems);

}

void Mochileiro::sort(std::vector<int> items) {
	int temp;
	for (int i = 0; i < getNroitems() - 1; i++) {
		if (items.at(i + 1) < items.at(i)) {
			temp = items.at(i + 1);
			items.at(i + 1) = items.at(i);
			items.at(i) = temp;
		}
	}
}

int** Mochileiro::SortingMatrix(int** items, int itensNumber) {
	int aux1 = 0;
	int aux2 = 0;
	int aux3 = 0;
	int aux4 = 0;

	for (int i = 0; i < itensNumber - 1; i++) {
		for (int j = i + 1; j < itensNumber; j++) {
			if (items[i][3] > items[j][3]) {
				aux1 = items[i][0];
				aux2 = items[i][1];
				aux3 = items[i][2];
				aux4 = items[i][3];
				items[i][0] = items[j][0];
				items[i][1] = items[j][1];
				items[i][2] = items[j][2];
				items[i][3] = items[j][3];
				items[j][0] = aux1;
				items[j][1] = aux2;
				items[j][2] = aux3;
				items[j][3] = aux4;
			}
			if (items[i][3] == items[j][3]) {
				if (items[i][0] > items[j][0]) {
					aux1 = items[i][0];
					aux2 = items[i][1];
					aux3 = items[i][2];
					aux4 = items[i][3];
					items[i][0] = items[j][0];
					items[i][1] = items[j][1];
					items[i][2] = items[j][2];
					items[i][3] = items[j][3];
					items[j][0] = aux1;
					items[j][1] = aux2;
					items[j][2] = aux3;
					items[j][3] = aux4;
				}
			}
		}
	}
	/*
	 for(int i=0;i<itensNumber;i++)
	 {
	 for(int j=0;j<4;j++)
	 {
	 cout<<items[i][j]<<" ";
	 }
	 cout<<endl;
	 }*/
	return items;
}

void Mochileiro::init() {
	matrixIndicePeso = new double*[getNroitems()];
	for (int i = 0; i < getNroitems(); i++) {
		matrixIndicePeso[i] = new double[2];
	}
}

void Mochileiro::imprime() {
}
