#include <iostream>

using namespace std;

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int total = size * size;

  cout << "Total Combinations: " << total << endl;

    int combos[total][2];
    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            combos[count][0] = numbers[i];
            combos[count][1] = numbers[j];
            ++count;
        }
    }

    cout << "\nCombinations Distribution:" << endl;
    for (int i = 0; i < total; i += size) {
        for (int j = 0; j < size; ++j) {
            cout << "(" << combos[i + j][0] << ", " << combos[i + j][1] << ") ";
        }
        cout <<endl;
    }

   cout << "\nProbability for every Sum :" <<endl;
    for (int i = 2; i <= 12; ++i) {
        count = 0;
        for (int j = 0; j < total; ++j) {
            if (combos[j][0] + combos[j][1] == i) {
                ++count;
            }
        }
        double probability = static_cast<double>(count) / total;
        cout << "P(Sum = " << i << ")  :   " << count << "/" << total << " = " << probability << endl;
    }

    return 0;
}
