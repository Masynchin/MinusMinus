#include <fstream>

using namespace std;

int main() {
    ifstream inf("in.txt");
	ofstream outf("out.txt");

    int n;
    inf >> n;
    int matrix[n][n];
    int stop = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);

    int c = 0;
    for(int i = 0; i < stop; i++){
        for(int j = i; j < n-i; j++)
            matrix[i][j] = ++c;
        for(int j = i+1; j < n-i; j++)
            matrix[j][n-i-1] = ++c;
        for(int j = i+1; j < n-i; j++)
            matrix[n-i-1][n-j-1] = ++c;
        for(int j = i+1; j < n-i-1; j++)
           matrix[n-j-1][i] = ++c;
    }
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            outf << matrix[i][j] << "\t";
        }
        outf << endl;
    }
 
    return 0;
}
