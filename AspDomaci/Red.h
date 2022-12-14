#ifndef _RED_H_
#define _RED_H_

#include "UlancanaReprezentacija.h"

class Red {
public:
	Red() {
		zadnji = nullptr;
		prednji = nullptr;
	}
	~Red();

	void ubaciR(string cvor);

	string izbaciR();

	bool prazanRed() const;

private:
	struct Elem {
		string ime;
		Elem* sled;
		Elem(string i, Elem* s = nullptr) : ime(i), sled(s) {}
	};
	Elem* prednji;
	Elem* zadnji;

};

#endif