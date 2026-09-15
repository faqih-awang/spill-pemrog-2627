<h1 align="center">04KUIS1. Luas Permukaan</h1>
<p align="center">
<b>Time limit:</b> 1 s<br><b>Memory limit:</b> 256 MB
</p>

### Description
Diketahui 4 bentuk ruang permukaan 2 dimensi, yaitu Lingkaran, Segitiga, Segiempat, dan Persegi. Lingkaran memiliki atribut `radius` (jari-jari), Segitiga memiliki `alas` dan `tinggi`, Segiempat memiliki `panjang` dan `lebar`, sedangkan Persegi yang merupakan bentuk khusus dari Segiempat hanya memiliki `sisi`. Semua bentuk ruang 2 dimensi ini dapat dihitung nilai luas permukaannya masing-masing.

Untuk mengolah data keempat bentuk tersebut, disusun struktur sebagai berikut:
```txt
               Ruang2D
                  |
                  |
    +-------------+-------------+
    |             |             |
    |             |             |
Lingkaran     Segitiga      Segiempat
                                |
                                |
                             Persegi
```

Susunlah program OOP untuk mengolah beberapa objek dan menampilkan total luas permukaan untuk objek pada selang tertentu. Objek dimulai pada posisi ke-1.

### Constraints
- 1 <= N <= 1000
- Gunakan nilai `pi = 3.14` untuk perhitungan luas lingkaran.

### Input Format
[n, banyaknya objek]<br>
[n baris objek dengan nilai atribut masing-masing]<br>
[a b], total luas dari posisi a sampai dengan b<br>
[-9], akhir dari query

### Output Format
Total luas objek pada selang a sampai dengan b, dituliskan dalam 2 digit di belakang tanda desimal.

### Sample Input
```txt
5
Segitiga 3.5 8
Lingkaran 5
Persegi 8.5
Segiempat 3 8
Lingkaran 6
1 5
2 4
-9
```

### Sample Output
```txt
1-5:289.79
2-4:162.75
```

### Explanation of Sample
- Total luas objek ke-1 sampai dengan ke-5 sebesar 289.79
- Total luas objek ke-2 sampai dengan ke-4 sebesar 162.75