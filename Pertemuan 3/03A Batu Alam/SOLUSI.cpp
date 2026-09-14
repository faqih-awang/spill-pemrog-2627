#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Persegi
{
private:
    int luas;
public:
    Persegi(int p, int l) : luas(p*l) {};
    int getLuas();
};

int Persegi::getLuas()
{
    return luas;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> luasVec;

    while (N--)
    {
        int p, l;
        cin >> p >> l;
        Persegi persegi(p, l);
        luasVec.push_back(persegi.getLuas());
    }

    sort(luasVec.begin(), luasVec.end());
    for (int i=0; i<K; i++)
    {
        cout << luasVec[i] << '\n';
    }

    return 0;
}