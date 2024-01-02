#include <iostream>

using namespace std;

// Custom rounding function
int custom_round(double value) {
    return static_cast<int>(value + 0.5);
}

void undoom_dice(int die_a[], int die_b[], int size) {
    double sum_a = 0, sum_b = 0;

    for (int i = 0; i < size; ++i) {
        sum_a += die_a[i];
        sum_b += die_b[i];
    }

    double scaling_factor = sum_a / sum_b;

    cout << "\nModified Values of the dice\n";
    cout << "New Die A:";
    for (int i = 0; i < size; ++i) {
        int value = min(4, die_a[i]);
        cout << " " << value;
    }

    cout << "\nNew Die B:";
    for (int i = 0; i < size; ++i) {
        int value = min(6, custom_round(die_b[i] * scaling_factor));
        cout << " " << value;
    }
}

int main() {
    const int size = 6;
    int die_a[size] = {1, 2, 3, 4, 5, 6};
    int die_b[size];

    // Copy values of die_a to die_b
    for (int i = 0; i < size; ++i) {
        die_b[i] = die_a[i];
    }

    undoom_dice(die_a, die_b, size);

    return 0;
}
