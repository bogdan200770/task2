#include <iostream>
#include <vector>
using namespace std;
int main() {
    size_t number_count;
    cin >> number_count;
    vector <double> numbers(number_count);
    for (size_t i = 0; i < number_count; i++)
        cin >> numbers[i];

    size_t bin_count;
    cin >> bin_count;
    vector <size_t> bins(bin_count);

    double min = numbers[0];
    double max = numbers[0];
    for (double x : numbers) {
        if (x < min)
            min = x;
        else if (x > max)
            max = x;
    }
    double bin_size = (max - min) / bin_count;

    for (size_t i = 0; i < number_count; i++) {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++) {
            auto begin_bin = min + j * bin_size;
            auto end_bin = min + (j + 1) * bin_size;
            if ((begin_bin <= numbers[i]) && (numbers[i] < end_bin)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
            bins[bin_count - 1]++;
    }

    int max_count = bins[0];
    for (int x : bins)
        if (x > max_count)
            max_count = x;

    for (size_t bin = 0; bin < bin_count; bin++) {
        if (bins[bin] < 10)
            cout << "  " << bins[bin] << "|";
        else if (bins[bin] > 10 && bins[bin] < 100)
            cout << " " << bins[bin] << "|";
        else
            cout << bins[bin] << "|";
        size_t height = 76 * (static_cast<double>(bins[bin]) / max_count);
        for (size_t i = 0; i < height; i++)
            cout << "*";
        cout << endl;
    }
    return 0;
}