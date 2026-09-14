#include <iostream>
#include <iomanip>

/* def class Orang */
class Orang {
  private:
    std::string nama;
    int usia;
    double tinggi, berat;
  public:
    Orang(std::string nm, int u, double tb, double bb) {
        nama = nm;
        usia = u;
        tinggi = tb;
        berat = bb;
    }  // constructor
    void show() {
        std::cout << std::fixed << std::setprecision(2) << nama << " | " << usia << " | " << tinggi << " | " << berat << "\n";
    }  // menuliskan nilai semua atribut
};

/* def class Orang */

int main()
{
    std::string nm;
    int u;
    double tb, bb;

    // gimana caranya ambil line??
    std::getline(std::cin, nm, '\n');
    std::cin >> u >> tb >> bb;
    Orang orang(nm, u, tb, bb);

    orang.show();

    return 0;
}