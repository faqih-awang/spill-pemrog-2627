<h1 align="center">Studi Kasus</h1>
<p align="center">Spesifikasi informasi untuk kebutuhan kode</p>

## Latar Belakang
Perusahaan perlu sistem penggajian otomatis untuk 3 jenis pekerja, yaitu **Karyawan Tetap**, **Karyawan Kontrak Tahunan**, dan **Karyawan Harian**.

Tujuan: Mendesain kode program yang aman, mudah diperluas, dan bebas dari duplikasi logika.

## Entitas
Tiga entitas Karyawan dalam sistem:
- Karyawan Tetap: Gaji pokok bulanan ditambah tunjangan jabatan tetap dan bonus kinerja bulanan.
- Kontrak Tahunan: Nilai kontrak tahunan dibagi 12 ditambah tunjangan penyelesaian proyek aktif.
- Karyawan Harian: Upah harian dikalikan total hari hadir ditambah insentif jam lembur harian.

Dari informasi ini, bisa diasumsikan bahwa ada kelas dasar yaitu Karyawan, dan ada dua atribut publik bersama yaitu `id` dan `nama`.

## Penerapan Konsep (PENTING!)
Kode perlu menerapkan 4 pilar Object Oriented Programming (OOP):
1. Abstraksi.
Mendapatkan struktur dari problem, mendapatkan objek, dan menentukan hubungan antar objek.
2. Enkapsulasi.
Data dan fungsi dibungkus dalam setiap objek untuk menjamin keamanan dan integritas data.
3. Pewarisan.
Setiap class adalah pewaris dari suatu class sebelumnya. Turunkan fungsi
4. Polimorfisme.
Terapkan metode-metode berikut, untuk class turunan:
- **Method Overriding:** Tiap subclass memberikan logika khusus untuk menghitung gaji total: hitungGajiTotal().
- **Pemrosesan Heterogen:** Array/Vector menampung semua tipe objek secara seragam.
- **Ekspansibilitas Fleksibel:** Menambah tipe karyawan baru tanpa mengubah fungsi.