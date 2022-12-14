#include "Red.h"

Red::~Red() {
	while (prednji) {
		Elem* pom = prednji;
		prednji = prednji->sled;
		delete pom;
	}
	zadnji = nullptr;
	prednji = nullptr;
}

void Red::ubaciR(string cvor) {
	Elem* tek = new Elem(cvor);
	if(zadnji = nullptr) {
		prednji = zadnji = tek;
	}
	else {
		zadnji->sled = tek;
	}
	zadnji = tek;
}

string Red::izbaciR() {
	Elem* tek;
	string x;
	if(prednji == nullptr) {
		cout << "underflow" << endl;
	}
	else {
		tek = prednji;
		x = tek->ime;
		prednji = tek->sled;
		if(prednji == nullptr) {
			zadnji = nullptr;
		}
		delete prednji;
		return x;
	}
}

bool Red::prazanRed() const{
	if(prednji == nullptr && zadnji == nullptr) {
		return true;
	}
	return false;
}
