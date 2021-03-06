#include <iostream>

bool isPrime(int);

int main(int argc, char* argv[]) {

	//Generate p and q, both have to be prime
	int p , q;
	std::cout << "Please enter number p: ";
	std::cin >> p;
	std::cout << "\nPlease enter number q: ";
	std::cin >> q;
	if ( !( (isPrime(p) && isPrime(q)) && (p != q) ) ) {
		std::cout << "\np and q have to be different numbers and prime!\n" << std::endl;
	}
	else {
		//Generate N, M (Euler function phi) and A (which represents the public key with N and has to be prime to M and A < M) 
		int const N = p * q;
		const int M = (p - 1) * (q - 1);
		
		int a_in;
		std::cout << "\nN: " << N << "\nPhi(N): " << M << "\n\nPlease enter a: ";
		std::cin >> a_in;
		const int A = a_in;

		if (!((A >= M) || (M % A == 0))) {
			//Solution found on this side (german)
			//https://www.inf.hs-flensburg.de/lang/krypto/algo/euklid.htm#:~:text=Der%20erweiterte%20euklidische%20Algorithmus%20setzt,von%20g%20als%20ganzzahlige%20Linearkombination.
			int m = M;
			int m_ = M;

			int a = A;
			int a_ = A;

			int u = 1;
			int v = 0;

			int s = 0;
			int s_ = s;

			int t = 1;
			int t_ = t;

			int l = 1;

			while (a != 0) {
				l = m / a;

				a = m - l * a;
				m = a_;
				a_ = a;

				s = u - l * s;
				u = s_;
				s_ = s;

				t = v - l * t;
				v = t_;
				t_ = t;
			}

			std::cout << "\nPublic key: (" << N << ", " << A << ")" << std::endl;
			std::cout << "Private key: (" << N << ", " << v << ")\n" << std::endl;
		}
		else
			std::cout << "\nA has to be smaller than M  and  prime to M !\n" << std::endl;
	}
	system("pause");
	return 0;
}

bool isPrime(int a) {
	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}