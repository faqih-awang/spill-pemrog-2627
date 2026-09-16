<h1 align="center">04B. Sistem Pencatatan Perparkiran Kampus</h1>
<p align="center">
<b>Time limit:</b> 1 s<br><b>Memory limit:</b> 65138 KB
</p>

### Deskripsi
Setiap hari, ribuan kendaraan masuk dan keluar dari area parkir kampus. Untuk mengelola parkir secara efisien, pihak pengelola kampus ingin membangun sistem pencatatan otomatis.

Setiap kendaraan yang masuk ke area parkir memiliki data umum seperti nomor plat, jenis kendaraan ("Listrik", "BBM", atau "Hybrid"), jam masuk, dan jam keluar. Namun, perhitungan tarif parkir berbeda-beda tergantung pada jenis kendaraannya:

- **Mobil**: Memiliki atribut tambahan kapasitas penumpang dan dikenakan tarif flat Rp 5.000 untuk jam pertama, lalu Rp 3.000/jam berikutnya.
- **Motor**: Memiliki atribut tambahan jenis motor (Biasa atau Moge) dan dikenakan tarif flat Rp 2.000 untuk jam pertama, lalu Rp 1.000/jam berikutnya.

Buatlah program C++ lengkap yang mengimplementasikan **Single Inheritance** dan **Polymorphism/Function Overriding** sesuai spesifikasi struktur kelas di bawah ini.

### Struktur Class
#### ***Class Induk (Base Class): Kendaraan***

Atribut (`protected`):
- `string` nomorPlat: Menyimpan nomor plat kendaraan.
- `string` jenisKendaraan: Menyimpan jenis kendaraan ("Listrik"/"BBM"/"Hybrid").
- `int` jamMasuk: Menyimpan jam masuk (dalam format 24 jam, misal: 8).
- `int` jamKeluar: Menyimpan jam keluar (dalam format 24 jam, misal: 11).


Method (`public`):
- Constructor: Memilik parameter untuk menginisialisasi nomorPlat, jenisKendaraan, jamMasuk, dan jamKeluar.
- fungsi hitungDurasi(): Mengembalikan selisih antara jamKeluar dan jamMasuk dalam satuan jam.
- fungsi hitungTarif(): Method virtual untuk menghitung total biaya parkir (default return 0.0).
- fungsi tampilkanInfo(): Method virtual untuk menampilkan informasi dasar kendaraan.


#### ***Class Turunan (Derived Class) #1: Mobil (Mewarisi Kendaraan)***

Atribut Tambahan (`private`):
- `int` kapasitasPenumpang: Menyimpan jumlah kapasitas penumpang.


Method (`public`):
- Constructor: Memanggil constructor Kendaraan dan menginisialisasi kapasitasPenumpang.
- fungsi hitungTarif() (Override): durasi 1 jam pertama = Rp 5.000, setiap jam berikutnya = Rp 3.000/jam.
- fungsi tampilkanInfo() (Override): Menampilkan seluruh atribut mobil beserta total durasi dan total biaya parkir.


#### ***Class Turunan (Derived Class) #2: Motor (Mewarisi Kendaraan)***

Atribut Tambahan (`private`):
- `string` jenisMotor: Menyimpan jenis motor ("Biasa" / "Moge").


Method (`public`):
- Constructor: Memanggil constructor Kendaraan dan menginisialisasi jenisMotor.
- fungsi hitungTarif() (Override): durasi 1 jam pertama = Rp 2.000, setiap jam berikutnya = Rp 1.000/jam.
- fungsi tampilkanInfo() (Override): Menampilkan seluruh atribut motor beserta total durasi dan total biaya parkir.

### Fungsi Utama (`main`)
Baca N objek Mobil dan Motor dengan format input sebagai berikut:
```txt
N
<"Mobil|Motor"> <nomorPlat> <jenis> <kapasitasPenumpang|jenisMotor> <jamMasuk> <jamKeluar>
```

Contoh input data:
```txt
2
Mobil F1234SKI Listrik 7 8 11
Motor F5678ABC BBM Biasa 10 14
```

Terapkan Polimorfisme untuk menyimpan setiap objek ke dalam struktur Vector. Tampilkan data seluruh kendaraan dengan format output seperti contoh berikut:
```txt
--- DATA PARKIR KENDARAAN 1 ---
Kendaraan       : Mobil
Nomor Plat      : F1234SKI
Jenis Kendaraan : Listrik
Durasi Parkir   : 3 Jam (08:00 - 11:00)
Kapasitas       : 7 Penumpang
Total Tarif     : Rp 11000

--- DATA PARKIR KENDARAAN 2 ---
Kendaraan       : Motor
Nomor Plat      : F5678ABC
Jenis Kendaraan : BBM
Durasi Parkir   : 4 Jam (10:00 - 14:00)
Tipe Motor      : Biasa
Total Tarif     : Rp 5000
```
