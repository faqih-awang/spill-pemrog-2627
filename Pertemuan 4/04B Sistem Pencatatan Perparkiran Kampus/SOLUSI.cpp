#include <iostream>
#include <vector>

class Kendaraan {
protected:
    std::string nomorPlat, jenisKendaraan;
    int jamMasuk, jamKeluar;
public:
    Kendaraan(std::string np, std::string jkd, int jm, int jk) : nomorPlat(np), jenisKendaraan(jkd), jamMasuk(jm), jamKeluar(jk) {}
    int hitungDurasi() {return jamKeluar - jamMasuk;}
    virtual double hitungTarif() {return 0.0f;}
    virtual void tampilkanInfo() {std::cout << "Nomor Plat      : " << nomorPlat << '\n'
                                            << "Jenis Kendaraan : " << jenisKendaraan << '\n'
                                            << "Jam Masuk       : " << jamMasuk << '\n'
                                            << "Jam Keluar      : " << jamKeluar << '\n';}
};

class Mobil : public Kendaraan {
private:
    int kapasitasPenumpang;
public:
    Mobil(std::string np, std::string jkd, int kp, int jm, int jk) : Kendaraan(np, jkd, jm, jk) {kapasitasPenumpang = kp;}
    double hitungTarif() override {
        int durasi = hitungDurasi();
        if (durasi <= 0) return 0.0f;
        else if (durasi <= 1) return 5000;
        else return 5000 + (durasi-1)*3000;
    }
    void tampilkanInfo() override {std::cout << "Kendaraan       : Mobil\n"
                                             << "Nomor Plat      : " << nomorPlat << '\n'
                                             << "Jenis Kendaraan : " << jenisKendaraan << '\n'
                                             << "Durasi Parkir   : " << hitungDurasi() << " Jam "; std::printf("(%02d:00 - %02d:00)\n", jamMasuk, jamKeluar); // LOL!
                                   std::cout << "Kapasitas       : " << kapasitasPenumpang << " Penumpang" << '\n'
                                             << "Total Tarif     : Rp " << hitungTarif() << '\n';}
};

class Motor : public Kendaraan {
private:
    std::string jenisMotor;
public:
    Motor(std::string np, std::string jkd, std::string jmt, int jm, int jk) : Kendaraan(np, jkd, jm, jk) {jenisMotor = jmt;}
    double hitungTarif() override {
        int durasi = hitungDurasi();
        if (durasi <= 0) return 0.0f;
        else if (durasi <= 1) return 2000;
        else return 2000 + (durasi-1)*1000;
    }
    void tampilkanInfo() override {std::cout << "Kendaraan       : Motor\n"
                                             << "Nomor Plat      : " << nomorPlat << '\n'
                                             << "Jenis Kendaraan : " << jenisKendaraan << '\n'
                                             << "Durasi Parkir   : " << hitungDurasi() << " Jam "; std::printf("(%01d:00 - %01d:00)\n", jamMasuk, jamKeluar); // LOL!
                                   std::cout << "Tipe Motor      : " << jenisMotor << '\n'
                                             << "Total Tarif     : Rp " << hitungTarif() << '\n';}
};

int main()
{
    std::vector<Kendaraan *> vec;

    int n;
    std::cin >> n;

    for (int i=0; i<n; i++)
    {
        std::string kendaraan, plat, jenis;
        std::cin >> kendaraan >> plat >> jenis;

        Kendaraan *K;

        if (kendaraan == "Mobil")
        {
            int kp, jm, jk;
            std::cin >> kp >> jm >> jk;

            K = new Mobil(plat, jenis, kp, jm, jk);
            vec.push_back(K);
        }
        else if (kendaraan == "Motor")
        {
            std::string tm;
            int jm, jk;
            std::cin >> tm >> jm >> jk;

            K = new Motor(plat, jenis, tm, jm, jk);
            vec.push_back(K);
        }
    }

    for (int j=0; j<n; j++)
    {
        std::cout << "--- DATA PARKIR KENDARAAN " << j+1 << " ---\n";
        vec[j]->tampilkanInfo();
        std::cout << '\n';
    }

    return 0;
}