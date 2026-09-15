#include <iostream>
#include <iomanip>
#include <vector>

const double pi = 3.14;

class Ruang2D {
public:
    virtual double hitungLuas() = 0;
};

class Lingkaran : public Ruang2D {
private:
    double radius;
public:
    Lingkaran(double r) : radius(r) {}
    double hitungLuas() {return pi * radius * radius;}
};

class Segitiga : public Ruang2D {
private:
    double alas, tinggi;
public:
    Segitiga(double a, double t) : alas(a), tinggi(t) {}
    double hitungLuas() {return 0.5 * alas * tinggi;}
};

class Segiempat : public Ruang2D {
private:
    double panjang, lebar;
public:
    Segiempat(double p, double l) : panjang(p), lebar(l) {}
    double hitungLuas() {return panjang * lebar;}
};

class Persegi : public Segiempat {
public:
    Persegi(double s) : Segiempat(s, s) {}
};

int main()
{
    std::vector<double> luasObjek;

    int N; std::cin >> N;

    while (N--)
    {
        std::string shape;
        std::cin >> shape;

        double res;

        if (shape == "Lingkaran") {
            double r; std::cin >> r;
            Lingkaran Obj(r);
            luasObjek.push_back(Obj.hitungLuas());
        }
        else if (shape == "Segitiga") {
            double a, t; std::cin >> a >> t;
            Segitiga Obj(a, t);
            luasObjek.push_back(Obj.hitungLuas());
        }
        else if (shape == "Segiempat") {
            double p, l; std::cin >> p >> l;
            Segitiga Obj(p, l);
            luasObjek.push_back(Obj.hitungLuas());
        }
        else if (shape == "Persegi") {
            double s; std::cin >> s;
            Lingkaran Obj(s);
            luasObjek.push_back(Obj.hitungLuas());
        }
    }

    int numA; std::cin >> numA;

    while (numA != -9)
    {
        int numB; std::cin >> numB;
        double totalLuas = 0;

        for (int i=numA-1; i<numB; i++) {
            totalLuas += luasObjek[i];
        }
        std::cout << numA << '-' << numB << ':' << std::fixed << std::setprecision(2) << totalLuas << '\n';

        std::cin >> numA;
    }

    return 0;
}