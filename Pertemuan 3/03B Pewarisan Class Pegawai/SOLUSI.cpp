#include <iostream>
#include <vector>

/* gaboleh nyentuh ini */
class Pegawai {
 protected:
    std::string id;
    int usia;
    int tipe;
    int income;
 public:
    Pegawai() { id=""; usia=income=0; tipe=1; }
    void set(std::string pid, int u, int t ) {id=pid; usia=u; tipe=t; }
    std::string getID() { return id; }
    void show() { printf("%s %d %d\n", id, tipe, income); }
};
/* gaboleh nyentuh ini */

class Tetap : public Pegawai {
public:
    Tetap() : Pegawai() {}
    void setTetap(std::string pid, int u, int t, int gp) {set(pid, u, t); income=gp;}
    void tambahIncome(int i) {income += i;}
    void show() {std::cout << id << ' ' << tipe << ' ' << income << '\n';}
};

class Harian : public Pegawai {
public:
    Harian() : Pegawai() {}
    void tambahIncome(int i) {income += i;}
    void show() {std::cout << id << ' ' << tipe << ' ' << income << '\n';}
};

int main()
{
    std::vector<Tetap> vecTetap;
    std::vector<Harian> vecHarian;

    int N;
    std::cin >> N;

    while (N--)
    {
        std::string id;
        int usia, tipe;
        std::cin >> id >> usia >> tipe;

        if (tipe == 1) // Tetap
        {
            int baseI; std::cin >> baseI;
            Tetap pgTetap;
            pgTetap.setTetap(id, usia, tipe, baseI);
            vecTetap.push_back(pgTetap);
        }
        else if (tipe == 2) // Harian
        {
            Harian pgHarian;
            pgHarian.set(id, usia, tipe);
            vecHarian.push_back(pgHarian);
        }
    }

    std::string targetId;
    std::cin >> targetId;

    while (targetId != "END")
    {
        int tambah; std::cin >> tambah;
        bool found = false;

        for (Tetap &pg : vecTetap)
        {
            if (pg.getID() == targetId) {
                found = true;
                pg.tambahIncome(tambah);
                break;
            }
        }

        if (!found) {
            for (Harian &pg : vecHarian)
            {
                if (pg.getID() == targetId) {
                    found = true;
                    pg.tambahIncome(tambah);
                    break;
                }
            }
        }

        std::cin >> targetId;
    }

    for (Tetap &t : vecTetap) t.show();
    for (Harian &h : vecHarian) h.show();

    return 0;
}