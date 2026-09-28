#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <limits>

// NB: Dalam lingkungan produksi, adalah praktik terbaik untuk menulis dokumentasi dengan comment.

// Class abstrak untuk dijadikan dasar bagi semua jenis karyawan
class Karyawan {
protected:
    std::string id;     // tanda pengenal unik untuk karyawan
    std::string nama;   // nama untuk ditampilkan

public:
    Karyawan(std::string nomorId, std::string namaKaryawan)
        : id(nomorId), nama(namaKaryawan) {}
    virtual ~Karyawan() = default;

    std::string getId() const {return id;}
    std::string getNama() const {return nama;}

    virtual double hitungTotalGaji() = 0;

    void showData()
    {
        double totalGaji = std::round(hitungTotalGaji());
        // ubah ke bentuk Rupiah untuk penampilan
        std::string angka = std::to_string(static_cast<long long>(totalGaji));
        int idx = static_cast<int>(angka.size()) - 3;
        
        while (idx > 0) {
            angka.insert(idx, ",");
            idx -= 3;
        }

        std::cout << "[" << getId() << "] " << getNama() << ": Rp" << angka << '\n';
    }
};

// Implementasi class untuk Karyawan Tetap
class KaryawanTetap : public Karyawan {
private:
    double gajiPokok;   // gaji pokok bulanan
    double tunjangan;   // tunjangan kerja tetap
    double bonus;       // bonus kinerja per bulan

public:
    KaryawanTetap(std::string nomorId, std::string namaKaryawan, double gajiPokokBulanan, double tunjanganKerja, double bonusKinerjaBulanan)
        : Karyawan(nomorId, namaKaryawan) 
    {
        setGajiPokok(gajiPokokBulanan);
        setTunjangan(tunjanganKerja);
        setBonus(bonusKinerjaBulanan);
    }
    ~KaryawanTetap() = default;

    void setGajiPokok(double newGaji) {gajiPokok = newGaji;}
    void setTunjangan(double newTunjangan) {tunjangan = newTunjangan;}
    void setBonus(double newBonus) {bonus = newBonus;}

    double hitungTotalGaji() override
    {
        return gajiPokok + tunjangan + bonus;
    }
};

// Implementasi class untuk Karyawan Kontrak
class KaryawanKontrak : public Karyawan {
private:
    double nilaiKtr;    // nilai kontrak tahunan
    double tunjangan;   // tunjangan penyelesaian

public:
    KaryawanKontrak(std::string nomorId, std::string namaKaryawan, double nilaiKontrakTahunan, double tunjanganKerja)
        : Karyawan(nomorId, namaKaryawan) 
    {
        setNilaiKontrak(nilaiKontrakTahunan);
        setTunjangan(tunjanganKerja);
    }
    ~KaryawanKontrak() = default;

    void setNilaiKontrak(double newNilai) {nilaiKtr = newNilai;}
    void setTunjangan(double newTunjangan) {tunjangan = newTunjangan;}

    double hitungTotalGaji() override
    {
        return nilaiKtr/12.0 + tunjangan;
    }
};

// Implementasi class untuk Karyawan Harian
class KaryawanHarian : public Karyawan {
private:
    int hariHadir;      // total hari hadir
    double upah;        // upah harian
    double insentif;    // insentif jam lembur harian

public:
    KaryawanHarian(std::string nomorId, std::string namaKaryawan, int totalHariHadir, double upahHarian, double insentifLembur)
        : Karyawan(nomorId, namaKaryawan) 
    {
        setHariHadir(totalHariHadir);
        setUpahHarian(upahHarian);
        setInsentif(insentifLembur);
    }
    ~KaryawanHarian() = default;

    void setHariHadir(int hari) {hariHadir = hari;}
    void setUpahHarian(double _upah) {upah = _upah;}
    void setInsentif(double _insentif) {insentif = _insentif;}

    double hitungTotalGaji() override
    {
        return (upah + insentif) * hariHadir;
    }
};


int main()
{
    std::vector<Karyawan *> daftarKaryawan;

    // Banyaknya karyawan
    int N = -1;

    std::cout << "Banyaknya karyawan (angka): ";
    if (!(std::cin >> N)) return 0;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (N <= 0)
    {
        std::cout << "Jumlah karyawan harus 1 atau lebih.\n"
            << "Program akan berhenti." << '\n';
        return 0;
    }

    // Menerima input dari data gaji karyawan
    for (int i=1; i<=N; i++)
    {
        std::string lineInput;

        std::cout << "\nData karyawan " << i << " (format: tipe,nid,nama,...): \n> ";
        std::getline(std::cin, lineInput);

        std::stringstream ss(lineInput);
        std::string tipe, nid, nama;

        std::getline(ss, tipe, ','); // cara tokenisasi di cpp
        std::getline(ss, nid, ',');
        std::getline(ss, nama, ',');

        Karyawan *karyawan = nullptr; // hati hati dengan pointer

        if (tipe == "1")
        {
            std::string a, b, c;
            std::getline(ss, a, ','); std::getline(ss, b, ','); std::getline(ss, c);

            karyawan = new KaryawanTetap(nid, nama, std::stod(a), std::stod(b), std::stod(c));
        }
        else if (tipe == "2")
        {
            std::string a, b;
            std::getline(ss, a, ','); std::getline(ss, b);

            karyawan = new KaryawanKontrak(nid, nama, std::stod(a), std::stod(b));
        }
        else if (tipe == "3")
        {
            std::string a, b, c;
            std::getline(ss, a, ','); std::getline(ss, b, ','); std::getline(ss, c);

            karyawan = new KaryawanHarian(nid, nama, std::stod(a), std::stod(b), std::stod(c));
        }

        if (karyawan != nullptr) daftarKaryawan.push_back(karyawan);
    }

    if (daftarKaryawan.size() < 1)
    {
        std::cout << "\nTidak ada data karyawan yang ditemukan dalam daftar. Mohon mengikuti format input.\n"
            << "Program akan berhenti." << '\n';
        return 0;
    }
    std::cout << "\nMenampilkan data gaji dari semua karyawan dalam daftar..." << '\n';

    for (Karyawan *k : daftarKaryawan)
    {
        k->showData();
        delete k;
    }
    daftarKaryawan.clear();
    return 0;
}