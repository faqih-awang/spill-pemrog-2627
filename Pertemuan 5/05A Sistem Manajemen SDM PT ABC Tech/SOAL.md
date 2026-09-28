<h1 align="center">05A. Sistem Manajemen SDM PT ABC Tech</h1>
<p align="center">
<b>Time limit:</b> 500 ms<br><b>Memory limit:</b> 62144 KB
</p>

### Description
PT ABC Tech membutuhkan sistem penggajian otomatis untuk mengelola tiga jenis skema kerja pegawai secara fleksibel dan terstruktur. Sistem harus dikembangkan dengan desain kode program yang aman, mudah diperluas, dan bebas dari duplikasi logic. Tiga jenis skema kerja karyawan meliputi:
1. Karyawan tetap yang memiliki gaji pokok bulanan ditambah tunjangan jabatan tetap dan bonus kinerja bulanan.
2. Karyawan kontrak tahunan memiliki nilai kontrak tahunan dibagi 12 ditambah tunjangan penyelesaian proyek aktif.
3. Karyawan Harian Lepas memiliki penghasilan berupa upah harian dikalikan total hari hadir ditambah insentif jam lembur harian.
4. Semua jenis karyawan memiliki atribut umum berupa nomor identitas dan nama, keduanya bertipe string.

Tuliskan kode program C++ secara detil dan lengkap yang mengimplementasikan 4 pilar pengembangan sistem berbasis objek, yaitu abstraksi, enkapsulasi, perwarisan, dan polimorfisme. Gunakan objek yang ada untuk membaca beberapa data karyawan dan menampilkan gaji masing-masing.

### Constraints
- Program harus mengimplementasikan 4 pilar OOP (abstraksi, enkapsulasi, pewarisan, dan polimorfisme)
- Nilai total gaji setiap pegawai tidak melebihi 2 Milyar.

### Input Format
Input data terdiri atas beberapa karyawan dengan kode awal di kolom pertama adalah 1 (karyawan tetap), 2 (karyawan kontrak tahunan), dan 3 (karyawan harian lepas). Setiap kolom data dipisahkan oleh tanda koma (,).

### Output Format
Output berupa beberapa baris data gaji total setiap pegawai yang terdiri atas identitas pegawai dan nilai gaji total bulan ini. Nilai total gaji dituliskan dengan 0 digit di belakang tanda desimal, dan ada tanda pemisah koma (,) untuk digit ribuan.

### Sample Input
```txt
1,A213,Ben Ardian,5000000,2000000,3000000
2,B761,Sonya Dewangga,100000000,12000000
3,C904,Ardian Hutapea,20,500000,125000
1,A741,Nisa Komariah Afdan,7000000,4000000,2000000
2,B722,Sangra Takolita,150000000,0
```

### Sample Output
```txt
A213 : 10,000,000
B761 : 20,333,333
C904 : 12,500,000
A741 : 13,000,000
B722 : 12,500,000
```