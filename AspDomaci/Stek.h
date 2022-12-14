#ifndef _STEK_H_
#define _STEK_H_

#include "UlancanaReprezentacija.h"

class Stek {
public:
	Stek() {
		vrh = nullptr;
	}
	~Stek();

	void push(string cvor);

	string pop();

	bool prazanStek() const;

private:
	struct Elem {
		string ime;
		Elem* sled;
		Elem(string i, Elem* s = nullptr) : ime(i), sled(s) {}
	};
	Elem* vrh;
};

#endif

