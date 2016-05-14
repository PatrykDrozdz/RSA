#pragma once

#include<vector>

using namespace std;


class RSAsetting {

protected:
	int P;
	int Q;
private:
	int E;
	int sit;
	int *tab;

public:

	void setP(int P) {
		this->P = P;
	}

	void setQ(int Q) {
		this->Q = Q;
	}

	void setE(int E) {
		this->E = E;
	}

	void setSit(int sit) {
		this->sit = sit;
		setTabSize();
	}

	void setTabSize() {
		this->tab = new int[this->sit];

		for (int i = 0; i < this->sit; i++) {
			tab[i] = i + 2;
		}

	}

	int getTab(int i) {
			return this->tab[i];
	}

	int getE() {
		return this->E;
	}

	int getSit() {
		return this->sit;
	}

	int getP() {
		return this->P;
	}

	int getQ() {
		return this->Q;
	}

};