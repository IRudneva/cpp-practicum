#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<bool, double> CalcMedian(vector<double> samples) {
    if (samples.empty()) {
        return { false, 0.0 };
    }
    sort(samples.begin(), samples.end());
    int index = samples.size() / 2;
    if (samples.size() % 2 == 0) {
        return { true, (samples[index - 1] + samples[index]) / 2 };
    }

    return { true, samples[index] };
}

int main() {
    int size;
    cin >> size;

    vector<double> samples;
    for (int i = 0; i < size; ++i) {
        double sample;
        cin >> sample;
        samples.push_back(sample);
    }

    const auto [median_exists, median_value] = CalcMedian(samples);
    if (median_exists) {
        cout << median_value << endl;
    }
    else {
        cout << "Empty vector"s << endl;
    }
}
