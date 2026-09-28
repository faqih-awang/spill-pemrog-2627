#include <iostream>
#include <vector>
#include <cmath>

// 4. Semua jenis karyawan memiliki atribut umum berupa nomor identitas dan nama, keduanya bertipe string.
class Karyawan {
protected:
    std::string nid, nama;
public:
    Karyawan(std::string nomorId, std::string namaKaryawan)
        : nid(nomorId), nama(namaKaryawan) {}
    virtual ~Karyawan() {}
    virtual double hitungGajiTotal() = 0;

    std::string getId() const {return nid;}
    std::string getNama() const {return nama;}
};

// tiga kelas turunan
// 1. Karyawan tetap yang memiliki gaji pokok bulanan ditambah tunjangan jabatan tetap dan bonus kinerja bulanan.
class KaryawanTetap : public Karyawan {
private:
    double gp, tjn, bns;
public:
    KaryawanTetap(std::string nomorId, std::string namaKaryawan, double gajiPokok, double tunjangan, double bonus)
        : Karyawan(nomorId, namaKaryawan)
    {
        setGajiPokok(gajiPokok);
        setTunjangan(tunjangan);
        setBonus(bonus);
    }
    ~KaryawanTetap() {}

    void setGajiPokok(double gajiPokok) {gp = gajiPokok;}
    void setTunjangan(double tunjangan) {tjn = tunjangan;}
    void setBonus(double bonus) {bns = bonus;}

    double hitungGajiTotal() override {
        return gp + tjn + bns;
    }
};

// 2. Karyawan kontrak tahunan memiliki nilai kontrak tahunan dibagi 12 ditambah tunjangan penyelesaian proyek aktif.
class KaryawanKontrak : public Karyawan {
private:
    double nk, tjn;
public:
    KaryawanKontrak(std::string nomorId, std::string namaKaryawan, double nilaiKontrak, double tunjangan)
        : Karyawan(nomorId, namaKaryawan)
    {
        setNilaiKontrak(nilaiKontrak);
        setTunjangan(tunjangan);
    }
    ~KaryawanKontrak() {}

    void setNilaiKontrak(double nilaiKontrak) {nk = nilaiKontrak;}
    void setTunjangan(double tunjangan) {tjn = tunjangan;}

    double hitungGajiTotal() override {
        return nk/12.0 + tjn;
    }
};

// 3. Karyawan Harian Lepas memiliki penghasilan berupa upah harian dikalikan total hari hadir ditambah insentif jam lembur harian.
class KaryawanHarian : public Karyawan {
private:
    int hdr;
    double uph, inh;
public:
    KaryawanHarian(std::string nomorId, std::string namaKaryawan, int hariHadir, double upahHarian, double insentifHarian)
        : Karyawan(nomorId, namaKaryawan)
    {
        setHariHadir(hariHadir);
        setUpahHarian(upahHarian);
        setInsentifHarian(insentifHarian);
    }
    ~KaryawanHarian() {}

    void setHariHadir(int hariHadir) {hdr = hariHadir;}
    void setUpahHarian(double upahHarian) {uph = upahHarian;}
    void setInsentifHarian(double insentifHarian) {inh = insentifHarian;}

    double hitungGajiTotal() override {
        return (uph + inh) * hdr;
    }
};


std::string formatRupiah(long long nilai) // makasih kak asprak
{
    std::string angka = std::to_string(nilai);
    int idx = static_cast<int>(angka.size()) - 3;

    while (idx > 0) {
        angka.insert(idx, ",");
        idx -= 3;
    }
    return angka;
}

int main()
{
    std::vector<Karyawan *> daftarKaryawan;
    std::string tipe, nid, nama;

    while (std::getline(std::cin, tipe, ','))
    {
        std::getline(std::cin, nid, ',');
        std::getline(std::cin, nama, ',');

        Karyawan *karyawan = nullptr; // hati hati dgn pointer

        if (tipe == "1")
        {
            std::string a, b, c;
            std::getline(std::cin, a, ','); std::getline(std::cin, b, ','); std::getline(std::cin, c);

            karyawan = new KaryawanTetap(nid, nama, std::stod(a), std::stod(b), std::stod(c));
        }
        else if (tipe == "2")
        {
            std::string a, b;
            std::getline(std::cin, a, ','); std::getline(std::cin, b);

            karyawan = new KaryawanKontrak(nid, nama, std::stod(a), std::stod(b));
        }
        else if (tipe == "3")
        {
            std::string a, b, c;
            std::getline(std::cin, a, ','); std::getline(std::cin, b, ','); std::getline(std::cin, c);

            karyawan = new KaryawanHarian(nid, nama, std::stod(a), std::stod(b), std::stod(c));
        }

        if (karyawan != nullptr) daftarKaryawan.push_back(karyawan);
    }

    for (Karyawan *karyawan : daftarKaryawan)
    {
        double totalGaji = karyawan->hitungGajiTotal();
        std::string hasil = formatRupiah(static_cast<long long>(std::round(totalGaji)));
        std::cout << karyawan->getId() << " : " << hasil << '\n';
        delete karyawan;
    }

    daftarKaryawan.clear();
    return 0;
}