#include <fstream>

using namespace std;

int main() {
	ifstream inf("in.txt");
	ofstream outf("out.txt");

	int x1, y1, x2, y2, x3, y3, x, y;
	inf >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x >> y;
	int sABC = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
	int sAOB = abs((x1 * (y - y2) + x2 * (y2 - y1) + x2 * (y1 - y)) / 2);
	int sBOC = abs((x2 * (y - y3) + x * (y3 - y2) + x3 * (y2 - y)) / 2);
	int sAOC = abs((x1 * (y - y3) + x * (y3 - y1) + x3 * (y1 - y)) / 2);
	if (sAOB + sBOC + sAOC > sABC) {
        outf << "НЕТ";
    } else {
        outf << "ДА";
    }
	return 0;
}
