#include "UlancanaReprezentacija.h"

#include <fstream>

int main() {
	int izbor1, izbor2, izbor3, izbor4;
	int n, e;
	string cvor, cvor1, cvor2;
	string s, s1, s2;
	double tezina;
	fstream ulaz;

	do {
		cout << "Izaberite jednu od ponudjenih opcija" << endl;
		cout << "1. Izaberite graf iz tekstualne datoteke" << endl;
		cout << "2. Napravi prazan graf" << endl;
		cout << "3. Zavrsi" << endl;

		cout << "Unesite broj: ";
		cin >> izbor1;
		switch (izbor1)
		{
		default:
			cout << endl;
			cout << "Pogresan unos!" << endl;
			cout << endl;
			break;

		case 1:{
			cout << "1. Graf 1" << endl;
			cout << "2. Graf 2" << endl;
			cout << "Unesite broj: ";
			cin >> izbor2;
			if (izbor2 == 1) {
				ulaz.open("graf1.txt");
				ulaz >> n;
				ulaz >> e;
			}
			else if (izbor2 == 2) {
				ulaz.open("graf2.txt");
				ulaz >> n;
				ulaz >> e;
			}
			else {
				cout << endl;
				cout << "Pogresan unos!" << endl;
				cout << endl;
				break;
			}

			Ulancana graf(n);
			cout << "Unesite 1 da dodate cvorove: ";
			cin >> izbor3;
			if (izbor3 == 1) {
				for (int i = 0; i < n; i++) {
					ulaz >> cvor;
					graf.dodajCvor(cvor);
				}
			}
			else {
				cout << endl;
				cout << "Pogresan unos!" << endl;
				cout << endl;
				break;
			}

			cout << "Unsetite 2 da dodate grane: ";
			cin >> izbor3;
			if (izbor3 == 2) {
				for (int i = 0; i < e; i++) {
					ulaz >> cvor1;
					ulaz >> cvor2;
					ulaz >> tezina;
					graf.dodajGranu(cvor1, cvor2, tezina);
				}
			}
			else {
				cout << endl;
				cout << "Pogresan unos!" << endl;
				cout << endl;
				break;
			}
			do {
				cout << "Izaberite jednu od ponudjenih opcija" << endl;
				cout << "1. Ispisite graf" << endl;
				cout << "2. Uklonite zadati cvor" << endl;
				cout << "3. Uklonite granu izmedju dva cvora" << endl;
				cout << "4. Vrati se na pocetak" << endl;
				cout << "Unesite broj: ";
				cin >> izbor4;
				switch (izbor4)
				{
				default:
					cout << endl;
					cout << "Pogresan unos!" << endl;
					cout << endl;
					break;

				case 1:
					cout << endl;
					graf.ispis();
					cout << endl;
					break;

				case 2:
					cout << "Unesi ime cvora: ";
					cin >> s;
					cout << endl;
					graf.ukloniCvor(s);
					break;

				case 3:
					cout << "Unesi ime prvog cvora: ";
					cin >> s1;
					cout << "Unesi ime drugog cvora: ";
					cin >> s2;
					cout << endl;
					graf.ukloniGranu(s1, s2);
					break;

				case 4:
					break;
				}
			} while (izbor4 != 4);

		}
		case 2: {
			int br;
			cout << "Unesite koliko cvorova zelite da dodate: ";
			cin >> br;
			Ulancana graf2(br);
		}

		case 3:
			break;
		}
	} while (izbor1 != 3);

	return 0;
}