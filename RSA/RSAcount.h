#pragma once

#include<cmath>

class RSAcount {
private:
	int fi;
	int N;
	int D;
public:

	void setN(int P, int Q) {
		this->N = Q*P;
	}

	void setFi(int P, int Q) {
		this->fi = (P - 1)*(Q - 1);
	}

	void setD(int D) {
		this->D = D;
	}

	int getN() {
		return this->N;
	}

	int getFi() {
		return this->fi;
	}

	int getD() {
		return this->D;
	}

	long long int NWD(long long a, long long b)
	{
		long long temp_a, temp_b, x = 1, y = 0, i = 0, j = 1, change, raound = 0, i2, j2;


		temp_a = a;
		temp_b = b;

		while (b != 0)
		{
			change = a % b;
			raound = lrint(floor(a / b));   // funkcja zaokr¹gla i zwraca typ ca³kowity long int
			a = b;
			b = change;
			i2 = x - (raound * i);
			j2 = y - (raound * j);
			x = i;
			y = j;
			i = i2;
			j = j2;
		}

		return ((x*temp_a) + (y*temp_b));
	}

	long long NWD2(long long a, long long b)
	{
		long long temp_a, temp_b, x = 1, y = 0, i = 0, j = 1, change, rounde = 0, i2, j2;


		temp_a = a;
		temp_b = b;

		while (b != 0)
		{
			change = a % b;
			rounde = lrint(floor(a / b));   // funkcja zaokr¹gla i zwraca typ ca³kowity long int
			a = b;
			b = change;
			i2 = x - (rounde * i);
			j2 = y - (rounde * j);
			x = i;
			y = j;
			i = i2;
			j = j2;

		}
		return y;
	}

	long long int power_modulo_fast(int a, int b, int m)  //  funkcja obliczaj¹ca resztê z dzielenia du¿ej potêgi przez modulo m.
	{
		int i;
		int result = 1;
		while (b > 0)
		{
			if (b % 2 == 1)
				result = (result * a) % m;
			b = b >> 1;
			a = (a*a) % m;

		}

		return result;
	}

};