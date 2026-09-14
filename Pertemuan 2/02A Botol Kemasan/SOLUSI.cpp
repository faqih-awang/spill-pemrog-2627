#include <iostream>
#define END_ARG "show"

/* def class MinumanKemasan */
class MinumanKemasan {
private:
    std::string namaProduk;
    int kapasitas, isiSekarang;
public:
    MinumanKemasan (std::string nama, int isi);
    void minum (int jumlah);
    void isiUlang (int jumlah);
    void show();
};

MinumanKemasan::MinumanKemasan(std::string nama, int isi)
{
    namaProduk = nama;
    kapasitas = isi;
    isiSekarang = isi;
}

void MinumanKemasan::minum(int jumlah)
{
    if (jumlah > isiSekarang) isiSekarang = 0;
    else isiSekarang -= jumlah;
}

void MinumanKemasan::isiUlang(int jumlah)
{
    if (isiSekarang + jumlah > kapasitas) isiSekarang = kapasitas;
    else isiSekarang += jumlah;
}

void MinumanKemasan::show()
{
/*
Nama Produk : yourTea
Kapasitas   : 1000 ml
Isi Sekarang: 600 ml
*/
    std::cout << "Nama Produk : " << namaProduk << "\n";
    std::cout << "Kapasitas   : " << kapasitas << " ml\n";
    std::cout << "Isi Sekarang: " << isiSekarang << " ml\n";
}
/* def class MinumanKemasan */


int main()
{
    std::string nama;
    int isi;

    std::cin >> nama >> isi;
    MinumanKemasan Minuman(nama, isi);

    std::string op;
    std::cin >> op;

    while (op != END_ARG)
    {
        int jumlah;
        std::cin >> jumlah;

        if (op == "minum") Minuman.minum(jumlah);
        else if (op == "isi") Minuman.isiUlang(jumlah);

        std::cin >> op;
    }

    Minuman.show();

    return 0;
}