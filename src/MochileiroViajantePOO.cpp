//============================================================================
// Name        : MoChileiroViajantePOO.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Mochileiro.h"
#include "Mochila.h"
#include "Caixeiro.h"
#include "SA.h"
using namespace std;

int main() {

	Mochileiro M;
	char entrada[] =
			"C:\\Users\\Marvin\\Desktop\\Metaheuristica\\instanciasParte2.txt";
	char saida[] =
			"C:\\Users\\Marvin\\Desktop\\Metaheuristica\\resultado\\resultado2.txt";
	M.carregarTodo(entrada, saida);

	int ct1[4] = { 1, 2, 4, 3 };
	std::vector<int> c1(ct1, ct1 + 4);

	int ct2[4] = { 1, 4, 2, 3 };
	std::vector<int> c2(ct2, ct2 + 4);

	int ct3[4] = { 1, 2, 3, 4 };
	std::vector<int> c3(ct3, ct3 + 4);

	int ct4[4] = { 1, 4, 3, 2 };
	std::vector<int> c4(ct4, ct4 + 4);

	int ct5[4] = { 1, 2, 4, 3 };
	std::vector<int> c5(ct5, ct5 + 4);

	int ct6[4] = { 1, 3, 4, 2 };
	std::vector<int> c6(ct6, ct6 + 4);

	int ct7[4] = { 1, 3, 2, 4 };
	std::vector<int> c7(ct7, ct7 + 4);

	int ct8[4] = { 1, 2, 4, 3 };
	std::vector<int> c8(ct8, ct8 + 4);

	int ct9[4] = { 1, 4, 3, 2 };
	std::vector<int> c9(ct9, ct9 + 4);

	int ci51_1[51] = { 1, 41, 4, 19, 13, 45, 39, 15, 8, 34, 11, 51, 17, 46, 24,
			32, 22, 7, 47, 28, 44, 36, 16, 49, 12, 27, 31, 43, 42, 18, 48, 14,
			50, 29, 9, 20, 40, 35, 30, 5, 25, 6, 38, 26, 33, 21, 10, 3, 37, 2,
			23 };
	std::vector<int> c51_1(ci51_1, ci51_1 + 51);

	int ci51_2[51] =
			{ 1, 6, 5, 49, 41, 29, 16, 30, 10, 11, 21, 40, 17, 28, 26, 24, 27,
					3, 44, 23, 25, 14, 46, 34, 2, 18, 7, 51, 39, 47, 48, 9, 13,
					37, 22, 36, 38, 8, 15, 42, 43, 20, 33, 19, 50, 45, 31, 12,
					35, 4, 32 };
	std::vector<int> c51_2(ci51_2, ci51_2 + 51);

	int ci51_3[51] =
			{ 1, 41, 46, 49, 50, 19, 2, 7, 22, 15, 43, 20, 17, 35, 24, 14, 12,
					44, 27, 32, 38, 5, 25, 9, 16, 33, 10, 36, 23, 39, 11, 4, 40,
					26, 45, 48, 37, 34, 21, 8, 51, 6, 29, 47, 13, 28, 3, 18, 42,
					30, 31 };
	std::vector<int> c51_3(ci51_3, ci51_3 + 51);

	int ci51_4[51] = { 1, 51, 44, 16, 21, 34, 17, 22, 26, 48, 7, 12, 49, 46, 40,
			11, 4, 5, 32, 23, 43, 24, 30, 19, 35, 28, 50, 14, 37, 18, 29, 10,
			42, 39, 8, 20, 36, 2, 31, 33, 41, 47, 6, 15, 9, 25, 3, 13, 27, 38,
			45 };

	std::vector<int> c51_4(ci51_4, ci51_4 + 51);

	int ci51_5[51] = { 1, 3, 7, 37, 29, 23, 32, 10, 25, 5, 36, 8, 16, 33, 13,
			42, 45, 19, 26, 46, 38, 21, 4, 40, 11, 22, 24, 15, 39, 2, 20, 31,
			14, 44, 49, 27, 6, 28, 34, 48, 50, 30, 51, 35, 41, 9, 43, 47, 12,
			17, 18 };

	std::vector<int> c51_5(ci51_5, ci51_5 + 51);

	int ci151_1[51] = { 1, 44, 46, 24, 35, 33, 51, 20, 40, 41, 17, 27, 30, 14,
			22, 50, 48, 10, 3, 9, 11, 19, 26, 28, 39, 18, 23, 25, 2, 38, 34, 15,
			36, 47, 37, 49, 7, 29, 32, 31, 12, 16, 4, 45, 8, 6, 42, 43, 21, 13,
			5 };

	std::vector<int> c151_1(ci151_1, ci151_1 + 51);

	int ci151_2[51] = { 1, 8, 7, 37, 42, 19, 49, 46, 10, 47, 35, 5, 3, 36, 20,
			39, 32, 13, 29, 22, 24, 2, 18, 31, 6, 11, 17, 50, 12, 26, 45, 51,
			15, 48, 4, 9, 14, 21, 28, 27, 41, 43, 40, 30, 25, 44, 34, 38, 23,
			33, 16 };

	std::vector<int> c151_2(ci151_2, ci151_2 + 51);

	int ci151_3[51] =
			{ 1, 47, 20, 32, 4, 18, 50, 43, 13, 30, 48, 41, 3, 16, 51, 22, 36,
					11, 15, 9, 45, 5, 19, 42, 21, 28, 34, 49, 29, 23, 24, 8, 25,
					10, 12, 37, 6, 40, 38, 46, 27, 14, 33, 26, 39, 44, 31, 35,
					2, 7, 17 };

	std::vector<int> c151_3(ci151_3, ci151_3 + 51);

	int ci151_4[51] =
			{ 1, 32, 17, 3, 42, 18, 11, 25, 10, 4, 43, 47, 31, 13, 29, 8, 34, 2,
					14, 21, 24, 28, 33, 19, 30, 40, 37, 6, 12, 23, 7, 36, 50,
					49, 41, 5, 44, 20, 51, 46, 15, 38, 9, 39, 22, 48, 27, 16,
					35, 45, 26 };

	std::vector<int> c151_4(ci151_4, ci151_4 + 51);

	int ci151_5[51] = { 1, 3, 7, 37, 29, 23, 32, 10, 25, 5, 36, 8, 16, 33, 13,
			42, 45, 19, 26, 46, 38, 21, 4, 40, 11, 22, 24, 15, 39, 2, 20, 31,
			14, 44, 49, 27, 6, 28, 34, 48, 50, 30, 51, 35, 41, 9, 43, 47, 12,
			17, 18 };

	std::vector<int> c151_5(ci151_5, ci151_5 + 51);

	//###########################################items############

	int it1[6] = { 0, 0, 0, 1, 1, 0 };
	std::vector<int> i1(it1, it1 + 6);

	int it2[6] = { 1, 0, 0, 0, 1, 0 };
	std::vector<int> i2(it2, it2 + 6);

	int it3[6] = { 0, 0, 0, 1, 0, 0 };
	std::vector<int> i3(it3, it3 + 6);

	int it4[6] = { 1, 0, 0, 1, 0, 0 };
	std::vector<int> i4(it4, it4 + 6);

	int it5[6] = { 1, 0, 0, 1, 0, 0 };
	std::vector<int> i5(it5, it5 + 6);

	int it6[6] = { 1, 0, 0, 0, 0, 0 };
	std::vector<int> i6(it6, it6 + 6);

	int it7[6] = { 0, 0, 0, 0, 0, 0 };
	std::vector<int> i7(it7, it7 + 6);

	int it8[6] = { 0, 0, 1, 0, 1, 0 };
	std::vector<int> i8(it8, it8 + 6);

	int it9[6] = { 0, 0, 0, 1, 1, 1 };
	std::vector<int> i9(it9, it9 + 6);

	int it51_1[50] = { 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
			0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			1, 0, 0, 0, 0, 0, 1, 0 };
	std::vector<int> i51_1(it51_1, it51_1 + 50);

	int it51_2[50] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 1, 0, 0, 0, 1, 0, 0 };

	std::vector<int> i51_2(it51_2, it51_2 + 50);

	int it51_3[50] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
			0, 0, 0, 0, 0, 0, 1, 1 };

	std::vector<int> i51_3(it51_3, it51_3 + 50);

	int it51_4[50] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
			0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 1, 0, 0 };

	std::vector<int> i51_4(it51_4, it51_4 + 50);

	int it51_5[50] = { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1,
			1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 1, 0, 0, 0, 0, 1 };

	std::vector<int> i51_5(it51_5, it51_5 + 50);

	int it151_1[150] = { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	std::vector<int> i151_1(it151_1, it151_1 + 150);

	int it151_2[150] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

	std::vector<int> i151_2(it151_2, it151_2 + 150);

	int it151_3[150] = { 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
			1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	std::vector<int> i151_3(it151_3, it151_3 + 150);

	int it151_4[150] = { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
			0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };

	std::vector<int> i151_4(it151_4, it151_4 + 150);

	int it151_5[150] = { 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
			0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

	std::vector<int> i151_5(it151_5, it151_5 + 150);

	//M.setCities(c7);
	//M.setItems(i7);

	//###########resultado op1+op2+op3########

	//cout << "Resultado final = " << M.resultadoFinal() << endl;

	//###########Dois Opt para ex4_n6############
	Mochileiro M1;
	M1.carregar(
			"C:\\Users\\Marvin\\Desktop\\Metaheuristica\\instanciaexemplo\\ex4_n6.pmv");

	std::vector<vector<int> > v;
	v.insert(v.begin() + 0, c1);
	v.insert(v.begin() + 1, c2);
	v.insert(v.begin() + 2, c3);
	v.insert(v.begin() + 3, c4);
	v.insert(v.begin() + 4, c5);
	v.insert(v.begin() + 5, c6);
	v.insert(v.begin() + 6, c7);
	//v.insert(v.begin() + 7, c8);
	//v.insert(v.begin() + 8, c9);

	std::vector<vector<int> > b;

	b.insert(b.begin() + 0, i1);
	b.insert(b.begin() + 1, i2);
	b.insert(b.begin() + 2, i3);
	b.insert(b.begin() + 3, i4);
	b.insert(b.begin() + 4, i5);
	b.insert(b.begin() + 5, i6);
	b.insert(b.begin() + 6, i7);
	//b.insert(b.begin() + 7, i8);
	//b.insert(b.begin() + 8, i9);

	cout << "Dois Opt para ex4_n6" << endl;
	for (std::vector<int>::size_type i = 0; i != v.size(); i++) {
		double doisOpt = 0.0;
		M1.setCities(v.at(i));
		M1.setItems(b.at(i));
		doisOpt = M1.DoisOpt();
		cout << "Dois opt = " << doisOpt << endl;
	}

	//###########Dois Opt para eil51_n50_b01############
	Mochileiro M2;
	M2.carregar(
			"C:\\Users\\Marvin\\Desktop\\Metaheuristica\\instancia51\\eil51_n50_b01.pmv");

	std::vector<vector<int> > w;
	w.insert(w.begin() + 0, c51_1);
	w.insert(w.begin() + 1, c51_2);
	w.insert(w.begin() + 2, c51_3);
	w.insert(w.begin() + 3, c51_4);
	w.insert(w.begin() + 4, c51_5);

	std::vector<vector<int> > t;

	t.insert(t.begin() + 0, i51_1);
	t.insert(t.begin() + 1, i51_2);
	t.insert(t.begin() + 2, i51_3);
	t.insert(t.begin() + 3, i51_4);
	t.insert(t.begin() + 4, i51_5);

	cout << "Dois Opt para eil51_n50_b01" << endl;
	for (std::vector<int>::size_type i = 0; i != w.size(); i++) {
		double doisOpt = 0.0;
		M2.setCities(w.at(i));
		M2.setItems(t.at(i));
		doisOpt = M2.DoisOpt();
		cout << "Dois opt = " << doisOpt << endl;
	}

	Mochileiro M3;
	M3.carregar(
			"C:\\Users\\Marvin\\Desktop\\Metaheuristica\\instancia51\\eil51_n150_b01.pmv");
	//###########Dois Opt para eil51_n50_b01############
	//Sorting

	std::vector<vector<int> > m;
	m.insert(m.begin() + 0, c151_1);
	m.insert(m.begin() + 1, c151_2);
	m.insert(m.begin() + 2, c151_3);
	m.insert(m.begin() + 3, c151_4);
	m.insert(m.begin() + 4, c151_5);

	std::vector<vector<int> > p;

	p.insert(p.begin() + 0, i151_1);
	p.insert(p.begin() + 1, i151_2);
	p.insert(p.begin() + 2, i151_3);
	p.insert(p.begin() + 3, i151_4);
	p.insert(p.begin() + 4, i151_5);

	cout << "Dois Opt para eil51_n150_b01" << endl;
	for (std::vector<int>::size_type i = 0; i != m.size(); i++) {
		double doisOpt = 0.0;
		M3.setCities(m.at(i));
		M3.setItems(p.at(i));
		doisOpt = M3.DoisOpt();
		cout << "Dois opt = " << doisOpt << endl;
	}

	return 0;
}
