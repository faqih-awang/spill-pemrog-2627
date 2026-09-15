<h1 align="center">01A. Input dan Output pada C++</h1>
<p align="center">
<b>Time limit:</b> 1 s<br><b>Memory limit:</b> 256 MB
</p>

### Description
Bahasa Pemrograman C++, meskipun dikembangkan dari Bahasa C, memiliki pustaka dan fungsi-fungsi tersendiri yang berbeda dengan Bahasa C dalam melakukan operasi dasar untuk membantu proses input dan output (membaca masukan dan mencetak keluaran). Dalam Bahasa C, kita biasa menggunakan pustaka `<stdio.h>` yang memiliki fungsi `scanf()` untuk membaca masukan (input) dan printf() untuk mencetak keluaran (output). Kedua fungsi tersebut menggunakan penanda format yang disesuaikan dengan tipe data dan format yang diinginkan pada proses input/output, misalnya %d untuk menyatakan bilangan bulat dalam desimal, %f untuk bilangan pecahan (float) dan sebagainya. 

Bahasa C++ menggantikan pustaka untuk input/output dengan menggunakan `<iostream>`, yang mengandung obyek bernama **cin** dan **cout** yang masing-masing digunakan untuk input dan output. Untuk menggunakan keduanya, cukup kita berikan simbol **stream** yang menunjukkan aliran data ( simbol '>>' untuk masukan dan '<<' untuk keluaran). Misalnya

```cpp
#include <iostream> 
using namespace std;
// .... 
int x;
cin >> x;
cout << x << endl;
```

Potongan program di atas akan membaca masukan untuk diisikan ke variabel x, lalu kemudian menampilkannya kembali dan diakhiri dengan **newline** ( ditunjukkan dengan **endl**).

Anda dapat membaca lebih lanjut mengenai **input dan output** pada C++ melalui tautan berikut:
- https://en.cppreference.com/w/cpp/io 
- https://en.cppreference.com/w/cpp/io/cin 
- https://en.cppreference.com/w/cpp/io/cout

Untuk dapat melakukan format banyaknya digit pada desimal, dapat digunakan operasi **setprecision** (dari `<iomanip>`) yang digabungkan dengan penanda **fixed**, misalnya

```cpp
#include <iostream>
#include <iomanip>
// ...
float y;
cin >> y;
cout << fixed << setprecision(2) << y << endl;
```

Kode di atas memiliki efek yang sama dengan melakukan perintah ```printf("%.2f\n", y)``` pada Bahasa C.

Pada soal ini, Anda diminta untuk mencoba **input** dan **output** pada C++ dengan membaca **empat buah variabel** a, b, c, dan d yang bertipe `integer`, lalu menghitung **rataan** dari keempat bilangan tersebut dan menampilkannya dengan **dua angka** di belakang desimal.

### Batasan
- -100 juta <= a, b, c, d <= 100 juta

### Input Format
Masukan adalah sebuah baris berisi empat buah bilangan bulat
```txt
a b c d
```

### Output Format
Keluaran adalah sebuah baris berisi rataan dari keempat bilangan masukan yang dituliskan dengan dua angka di belakang tanda desimal.

### Sample Input
```txt
1 3 4 5
```

### Sample Output
```txt
3.25
```
