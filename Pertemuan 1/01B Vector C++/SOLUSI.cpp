#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int min;
    cin >> min;
      
    vector<int> nums;
    int total = 0;

    int num;
    cin >> num;
    while (num != -1) {
        if (num >= min) {
            nums.push_back(num);
            total += num;
        }
        cin >> num;
    }

    double mean = (double)total / nums.size();

    double total_deviasi = 0;
    for (auto n : nums) {
        double dev = (double)n - mean;
        total_deviasi += (dev*dev);
    }
    double variance = total_deviasi / (nums.size()-1);
                                                              
    cout << fixed << setprecision(2) << mean << " " << variance << endl;
    return 0;
}