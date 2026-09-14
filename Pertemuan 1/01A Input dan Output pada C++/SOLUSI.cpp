#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  double res = (double)(a+b+c+d)/4.0;
  cout << fixed << setprecision(2) << res << endl;
  return 0;
}