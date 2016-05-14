#include<iostream>
#include<time.h>
#include<vector>
#include"RSAset.h"
#include"RSAcount.h"

#define N 20

int lot1(int i, int n) {
	return(rand() % n) + i;
}

int lot2(int i, int n) {
	return(rand() % n) + i;
}

int lot3(int i, int n) {
	return(rand() % n) + i;
}

using namespace std;

int main() {

	int m = 10;

	srand(time(NULL));
	RSAsetting rsas;
	RSAcount rsac;
	vector<int>vec;

	rsas.setSit(N);

	cout << "Sito: " << endl;
	for (int i = 0; i < rsas.getSit(); i++) {
		cout << rsas.getTab(i) << " ";
	}

	cout << endl;
	cout << endl;

	for (int i = 0; i < rsas.getSit(); i++) {
		if (rsas.getTab(i) % 2 != 0 && rsas.getTab(i) % 3 != 0 && 
			rsas.getTab(i) % 5 != 0 && rsas.getTab(i) % 7 != 0) {
				vec.push_back(rsas.getTab(i));
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	cout << endl;
	cout << endl;

	rsas.setP(lot1(1, vec.size()));
	rsas.setQ(lot2(1, vec.size()));

	start:
	if (rsas.getP() != rsas.getQ()) {
		rsas.setP(vec[rsas.getP()]);
		rsas.setQ(vec[rsas.getQ()]);
	}
	else {
		rsas.setP(lot1(1, vec.size()));
		rsas.setQ(lot2(1, vec.size()));
		goto start;
	}


	cout << "P = " << rsas.getP() << endl;
	cout << "Q = " << rsas.getQ() << endl;

	rsac.setFi(rsas.getP(), rsas.getQ());
	rsac.setN(rsas.getP(), rsas.getQ());

	cout << endl;
	cout << endl;

	cout << "Fi = " << rsac.getFi() << endl;
	cout << "N = " << rsac.getN() << endl;

	cout << endl;
	cout << endl;

	rsas.setE(lot3(1, rsac.getFi()));

	start2:
	if (rsac.NWD(rsas.getE(), rsac.getFi()) == 1) {
		cout << "E = " << rsas.getE() << endl;
	}
	else {
		rsas.setE(lot3(1, rsac.getFi()));
		goto start2;
	}

	rsac.setD(rsac.NWD2(rsac.getFi(), rsas.getE()));

	if (rsac.getD() < 0) {
		rsac.setD(rsac.getD() + rsac.getFi());
	}

	cout << "D = " << rsac.getD();

	cout << endl;
	cout << endl;

	cout << "Liczba szyfrowana = " << m << endl;


	cout << "Po zaszyfrowaniu = " << rsac.power_modulo_fast(m, rsas.getE(), rsac.getN()) << endl;


	cout << "Po rozszyfrowaniu = " << 
		rsac.power_modulo_fast(rsac.power_modulo_fast(m, rsas.getE(), rsac.getN()), rsac.getD(), rsac.getN()) << endl;

	cout << endl;
	cout << endl;

	system("pause");
	return 0;
}