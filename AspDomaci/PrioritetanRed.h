#ifndef _PRIORITETANRED_H_
#define _PRIORITETANRED_H_

#include "UlancanaReprezentacija.h"

class Prioritetni {
public:
	Prioritetni() {
		prednji = nullptr;
		
	};

	~Prioritetni();

	void ubaciP(string cvor, double tez);

	string izbaciP();

private:
	struct Elem {
		string ime;
		double tezina;
		Elem* sled;
	};
	Elem* prednji;
	
};

#endif
