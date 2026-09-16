<h1 align="center">02A. Botol Kemasan</h1>
<p align="center">
<b>Time limit:</b> 500 ms<br><b>Memory limit:</b> 256 MB
</p>

### Description
Dalam kehidupan sehari-hari, kita sering membeli minuman kemasan botol (misalnya jus atau air mineral). Mari kita perhatikan beberapa fakta tentang minuman botol tersebut:
- Setiap minuman botol memiliki nama produk, kapasitas maksimum botol (dalam ml), dan sisa isi cairan saat ini (dalam ml).
- Ketika baru dibeli, botol biasanya terisi penuh.
- Botol berisi minuman bisa diminum (isi berkurang).
- Botol juga bisa diisi ulang (refill) jika belum penuh.
- Sisa cairan dalam botol tidak boleh bernilai negatif (kurang dari 0 ml) dan tidak boleh melebihi kapasitas maksimumnya.

Buatlah program berorientasi objek menggunakan bahasa C++ dengan ketentuan di bawah ini.

### Ketentuan Kelas
**Nama kelas** : MinumanKemasan

#### **Atribut (*State*):**
- namaProduk (string)
- kapasitas (integer, dalam ml)
- isiSekarang (integer, dalam ml)

#### **Konstruktor (*Constructor*):**
- Buat konstruktor yang menerima parameter namaProduk dan kapasitas.
- Saat objek pertama kali dibuat melalui konstruktor ini, nilai isiSekarang secara otomatis diset sama dengan kapasitas (botol masih penuh).

#### **Prosedur (*Method/Behaviour*):**
- minum(jumlah): Mengurangi isiSekarang sebanyak jumlah (dalam ml).
- isiUlang(jumlah): Menambah isiSekarang sebanyak jumlah (dalam ml).
- show(): Menampilkan status botol saat ini (nama produk, kapasitas, dan sisa isi dalam ml).

### Program Utama (*driver*)
Buat instruksi untuk membaca data dengan format:
```txt
<nama produk> <kapasitas>
<minum|isiulang> <jumlah>
...
...
show
```

Instruksi "show" sebagai akhir dari data dan bertujuan untuk menampilkan status terakhir dari botol dengan format:
```txt
Nama Produk : <nama produk>
Kapasitas   : <kapasitas>
Isi Sekarang: <volume terakhir>
```

### Sample Input
```txt
yourTea 1000
minum 300
minum 500
isi 600
minum 200
show
```

### Sample Output
```txt
Nama Produk : yourTea
Kapasitas   : 1000 ml
Isi Sekarang: 600 ml
```
