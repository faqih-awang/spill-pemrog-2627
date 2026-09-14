#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; double min;
    cin >> N >> min;

    vector<double> weights;
    double total = 0, weight;
    while (N--) {
        cin >> weight;
        weights.push_back(weight);
        total += weight;
    }

    if (total < min) {
        cout << -1 << endl;
        return 0;
    }

    sort(weights.begin(), weights.end());
    reverse(weights.begin(), weights.end());

    double tw = 0;
    int count = 0;
    for (auto w : weights) {
        tw += w;
        count++;
        if (tw >= min) {
            break;
        }
    }

    cout << count << endl;
    return 0;
}