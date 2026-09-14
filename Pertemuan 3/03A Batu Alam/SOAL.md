<center><h1>03A. Batu Alam</h1></center>
<center>
<b>Time limit:</b> 2 s<br><b>Memory limit:</b> 256 MB
</center>

### Description
Pak Andi akan memasang keramik batu alam di halaman belakang rumahnya. Beliau sudah membeli sebanyak N buah batu alam. yang semuanya berbentuk persegi panjang. Sayangnya, masing-masing batu memiliki ukuran yang mungkin berbeda-beda. Pak Andi tidak suka dengan ukuran batu yang kecil. Bantulah Pak Andi untuk menentukan K buah batu alam dengan luas terkecil dari tumpukan batu-batu yang dimilikinya. 

Pada soal ini Anda harus mengimplementasikan solusi dengan membuat **minimal satu buah** kelas yaitu **Persegi** dengan satu buah metode: **hitungLuas()**.

### Batasan
- 1≤N≤1000
- 1≤K≤N

### Input Format
Masukan diberikan dalam format berikut: baris pertama berisi N dan K. Setiap baris dari N baris berikutnya berisi panjang dan lebar masing-masing batu alam.
```txt
N K
P1 L1
P2 L2
...
PN KN
```

### Output Format
Keluarkan sebuah K buah baris menunjukkan luas dari batu alam terkecil yang ada, mulai dari yang paling kecil. 

### Sample Input
```txt
8 3
51 10
43 70
35 34
64 26
99 70
60 13
58 63
33 100
```

### Sample Output
```txt
510
780
1190
```