#include "UlancanaReprezentacija.h"

void Ulancana::dodajCvor(string imeCvora) {
	int i;;
	for (i = 0; niz[i] != nullptr; i++);
	niz[i] = new Elem(imeCvora);
}

void Ulancana::ukloniCvor(string imeCvora) {
	int id1 = nadjiCvor(imeCvora);
	delete niz[id1];
	niz[id1] = nullptr;
	
}

void Ulancana::dodajGranu(string cvor1, string cvor2, double tezina) {
	int id1 = nadjiCvor(cvor1);
	int id2 = nadjiCvor(cvor2);
	Elem* pom = niz[id1];
	while (pom->sled) {
		pom = pom->sled;
	}
	pom->sled = new Elem(cvor2, tezina, nullptr, id2);
}

Ulancana::~Ulancana() {
	for (int i = 0; i < brojCvorova; i++) {
		while (niz[i]) {
			Elem* pom = niz[i];
			niz[i] = niz[i]->sled;
			delete pom;
		}
	}
	delete[] niz;
}

int Ulancana::nadjiCvor(string cvor) const{
	int j = 0;
	for (j; j < brojCvorova; j++) {  
		if (niz[j] != nullptr && cvor == niz[j]->ime) {
			return j;
		}
	}
}

void Ulancana::ukloniGranu(string cvor1, string cvor2) {
	int id1 = nadjiCvor(cvor1);
	Elem* pom = niz[id1];
	while (pom->sled && (pom->sled->ime).compare(cvor2)) {
		pom = pom->sled;
	}
	Elem* tek;
	//ako grana ne postoji onda je pom->sled null
	if(pom->sled != nullptr) {
		tek = pom->sled->sled;
		delete pom->sled;
		pom->sled = tek;
	}
	else {
		cout << "GRANA NE POSTOJI" << endl;
	}
}

void Ulancana::ispis() const {
	for(int i = 0; i < brojCvorova; i++) {
		Elem* pom = niz[i];
		while(pom) {
			cout << pom->ime << "{" << pom->tezina << (pom->sled == nullptr ? "}" : "} ---> ");
			pom = pom->sled;
		}
		if (niz[i] == nullptr) {
			continue;
		}
		cout << endl;
		
	}
}

void Ulancana::ispisiNiz() const {
	for(int i = 0; i < brojCvorova; i++)
	{
		cout << niz[i]->ime << endl;
	}
}

int* Ulancana::dfs(string cvor) {
	Stek stek()

}

void Ulancana::invertuj() {
	Elem* p, *q, *r;
	for (int i = 0; i < brojCvorova; i++) {
		p = niz[i];
		q = nullptr;
		while (p) {
			r = p;
			q = p;
			p = p->sled;
			q->sled = r;
		}
		niz[i] = q;
	}
}
