#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream inf("in.txt");
	ofstream outf("out.txt");

	int curr, target = 0;
	vector<int> numbers;
	for (int i = 0; inf; i++) {
		numbers.push_back(0);
		inf >> numbers[i];
	}
	numbers.pop_back();
	curr = numbers[numbers.size() - 1];
	numbers.pop_back();
	vector<int> numbersMask = numbers;
	for (int i = 0; i < numbersMask.size(); i++) {
		for (int j = 2; j < numbersMask.size() - i; j++) {
			if (abs(numbersMask[j - 1]) > abs(numbersMask[j])) {
				int temp = numbersMask[j - 1];
				numbersMask[j - 1] = numbersMask[j];
				numbersMask[j] = temp;
			}
		}
	}
	int* temp = new int[numbersMask.size() - 1];
	temp[0] = numbersMask[0];
	for (int i = 0; i < numbersMask.size() - 1; i++) {
		temp[i] = numbersMask[numbersMask.size() - i - 1];
	}
	for (int i = 1; i < numbersMask.size(); i++) {
		numbersMask[i] = temp[i - 1];
	}
	delete[] temp;

	vector<int> operands;
	for (int i = 0; i < numbersMask.size(); i++)
		operands.push_back(0);
	for (int i = 1; i < numbersMask.size(); i++) {
		if (numbersMask[i] >= 0) {
			if (target <= curr - numbersMask[0]) target += numbersMask[i];
			else {
				target -= numbersMask[i];
				operands[i] = 1;
			}
		}
		else if (target <= curr - numbersMask[0]) {
			target -= numbersMask[i];
			operands[i] = 1;
		}
		else target += numbersMask[i];
	}

	for (int i = 1; i < operands.size(); i++) {
		int tempCount = 0;
		for (int j = i; j < numbersMask.size() && tempCount == 0; j++)
			if (numbers[i] == numbersMask[j]) tempCount = j;
		int temp = operands[i];
		operands[i] = operands[tempCount];
		operands[tempCount] = temp;
		temp = numbersMask[i];
		numbersMask[i] = numbersMask[tempCount];
		numbersMask[tempCount] = temp;
	}

	if (target != curr - numbersMask[0])
		outf << "Такой расстановки нет";
	else {
		outf << numbers[0] << " ";
		for (int i = 1; i < operands.size(); i++) {
			if (operands[i] == 0) {
				if (numbers[i] >= 0) outf << "+ " << numbers[i] << " ";
				else outf << "+ (" << numbers[i] << ") ";
			}
			else {
				if (numbers[i] >= 0) outf << "- " << numbers[i] << " ";
				else outf << "- (" << numbers[i] << ") ";
			}
		}
		outf << "= " << curr;
	}
	return 0;
}
