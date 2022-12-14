#ifndef _ULANCANAREPREZENTACIJA_H_
#define _ULANCANAREPREZENTACIJA_H_

#include "Stek.h"

#include <string>
#include <iostream>
using namespace std;

class Ulancana {
public:
	Ulancana(int brCvorova) : brojCvorova(brCvorova) {
		niz = new Elem*[brCvorova];
		for(int i = 0; i < brCvorova; i++)
		{
			niz[i] = nullptr;
		}
	};
	~Ulancana();

	int nadjiCvor(string cvor) const;

	void dodajCvor(string imeCvora);

	void ukloniCvor(string imeCvora);

	void dodajGranu(string cvor1, string cvor2, double tezina);

	void ukloniGranu(string cvor1, string cvor2);

	void ispis() const;

	void ispisiNiz() const;

	int* dfs(string cvor);

	void invertuj();



private:
	int brojCvorova;
	struct Elem {
		string ime;
		double tezina;
		Elem* sled;
		int id;
		Elem(string i, double t = 0, Elem* s = nullptr, int id = -1) : ime(i), tezina(t), sled(s), id(id) {}
	};
	Elem** niz;
	
};



#endif
