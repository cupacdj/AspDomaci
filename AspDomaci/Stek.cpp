#include "Stek.h"

Stek::~Stek() {
	while (vrh) {
		Elem* pom = vrh;
		vrh = vrh->sled;
		delete pom;
	}
	vrh = nullptr;
}

void Stek::push(string cvor) {
	Elem* tek = new Elem(cvor);
	tek->ime = cvor;
	tek->sled = vrh;
	vrh = tek;
}

string Stek::pop() {
	string x;
	if(vrh == nullptr) {
		cout << "underflow" << endl;
	}
	else {
		Elem* pom = vrh;
		vrh = pom->sled;
		x = pom->ime;
		delete pom;
		return x;
	}
}

bool Stek::prazanStek() const{
	if(vrh == nullptr) {
		return true;
	}
	return false;
}
