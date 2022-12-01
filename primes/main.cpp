#include <cmath>
#include <fstream>

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		};
	}
	return n != 1;
}

int main() {
	ifstream inf("in.txt");
	ofstream outf("out.txt");

	int start, end;
	inf >> start >> end;
	for (int n = start; n <= end; n++) {
		if (isPrime(n)) {
			outf << n << " ";
		}
	}
	return 0;
}
