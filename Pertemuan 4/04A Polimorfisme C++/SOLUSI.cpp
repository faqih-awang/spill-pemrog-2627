#include <iostream>
#include <iomanip>

#define PI 3.1425

class Bangun {
public:
    virtual double hitungLuas() = 0;
};

class Bangun3D : public Bangun {
public:
    virtual double hitungVolume() = 0;
};

class Persegi : public Bangun {
    double s;
public:
    Persegi(double lf) : s(lf) {}
    double hitungLuas() {
        return s*s;
    }
};

class Lingkaran : public Bangun {
    double r;
public:
    Lingkaran(double lf) : r(lf) {}
    double hitungLuas() {
        return PI * r * r; // double r = d*0.5 kalo ini diameter
    }
};

class Kubus : public Bangun3D {
    double s;
public:
    Kubus(double lf) : s(lf) {}
    double hitungLuas() {
        return 6 * s*s;
    }
    double hitungVolume() {
        return s*s*s;
    }
};

class Bola : public Bangun3D {
    double r;
public:
    Bola(double lf) : r(lf) {}
    double hitungLuas() {
        return 4.0f * PI * r * r; // double r = d*0.5 kalo dikasihnya diameter
    }
    double hitungVolume() {
        return 4.0f/3.0f * PI * r * r * r;
    }
};

int main()
{
    double totalLuas = 0, totalVolume = 0;

    int n;
    std::cin >> n;

    while (n--)
    {
        char shape;
        double lf;
        std::cin >> shape >> lf;

        Bangun *P;

        if (shape == 'P')
        {
            P = new Persegi(lf);
            totalLuas += P->hitungLuas();
        }
        else if (shape == 'L')
        {
            P = new Lingkaran(lf);
            totalLuas += P->hitungLuas();
        }
        else if (shape == 'K')
        {
            Bangun3D *K = new Kubus(lf);
            totalLuas += K->hitungLuas();
            totalVolume += K->hitungVolume();
        }
        else if (shape == 'B')
        {
            Bangun3D *B = new Bola(lf);
            totalLuas += B->hitungLuas();
            totalVolume += B->hitungVolume();
        }
    }

    std::cout << std::fixed << std::setprecision(2) << totalLuas << '\n' << totalVolume << '\n';
    return 0;
}