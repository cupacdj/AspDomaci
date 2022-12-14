#include "PrioritetanRed.h"

Prioritetni::~Prioritetni() {
	while (prednji) {
		Elem* pom = prednji;
		prednji = prednji->sled;
		delete pom;
	}
	prednji = nullptr;
}

void Prioritetni::ubaciP(string cvor, double tez) {
	Elem* pom;
	Elem* tek = new Elem;
	tek->ime = cvor;
	tek->tezina = tez;
	if (prednji != nullptr || tez > prednji->tezina) {
		pom = prednji;
		while (pom->sled != nullptr && pom->sled->tezina <= tez) {
			pom = pom->sled;
		}
		tek->sled = pom->sled;
		pom->sled = tek;
	}
	else {
		tek->sled = prednji;
		prednji = tek;
	}


}

string Prioritetni::izbaciP() {
	Elem* tek;
	string x;
	if (prednji == nullptr) {
		cout << "underflow" << endl;
	}
	else {
		tek = prednji;
		x = tek->ime;
		delete tek;
		prednji = prednji->sled;
		return x;
	}
}
