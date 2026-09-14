<center><h1>02B. Class Orang</h1></center>
<center>
<b>Time limit:</b> 500 ms<br><b>Memory limit:</b> 256 MB
</center>

### Description
Diketahui class Orang dalam pemrograman C++ sebagai berikut:
```cpp
class Orang {
  private:
    string nama;
    int usia;
    double tinggi, berat;
  public:
    Orang(....) { .... }  // constructor
    void show() { .....}  // menuliskan nilai semua atribut
};
```

Lengkapi dan gunakan class Orang tersebut untuk mengolah data nama, usia, tinggi, dan berat seseorang. Output program seperti pada contoh. Nilai tinggi dan berat disajikan dalam 2 digit di belakang tanda titik.

### Input Format
```txt
[nama orang]
[usia]
[tinggi, dalam cm]
[berat, dalam kg]
```

### Output Format
```txt
nama orang | usia | tinggi | berat
```

### Sample Input
```txt
Kim Jong Un
63
170.521
69.25
```

### Sample Output
```txt
Kim Jong Un | 63 | 170.52 | 69.25
```