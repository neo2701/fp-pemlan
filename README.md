# Sistem Manajemen Gudang (Warehouse Management System)

Aplikasi berbasis C++ untuk mengelola data barang di gudang menggunakan struktur data Linked List dengan implementasi algoritma sorting, searching, dan analisis rekursif.

## 📋 Deskripsi

Aplikasi ini adalah sistem manajemen gudang sederhana yang dikembangkan menggunakan C++ dengan implementasi struktur data dan algoritma fundamental, termasuk:

- **Linked List** sebagai struktur data utama (pengganti array)
- **Merge Sort** untuk pengurutan data
- **Sequential Search** untuk pencarian data
- **Rekursif** untuk analisis total aset
- **File I/O** untuk persistensi data

## 🎯 Fitur Utama

1. **Tambah Data Barang** - Menambahkan barang baru ke dalam sistem
2. **Tampilkan Data** - Menampilkan seluruh data barang yang tersimpan
3. **Cari Data** - Mencari barang berdasarkan ID atau Nama
4. **Urutkan Data** - Mengurutkan data menggunakan algoritma Merge Sort
5. **Analisis Aset** - Menghitung total nilai aset menggunakan fungsi rekursif
6. **Simpan File** - Menyimpan data ke file teks
7. **Load Data** - Memuat data dari file secara otomatis saat aplikasi dijalankan

## 📁 Struktur Project

```
FP/
├── main.cpp            # Entry point aplikasi
├── App.h               # Header file untuk aplikasi utama
├── App.cpp             # Implementasi fungsi aplikasi dan menu
├── Utility.h           # Header file untuk fungsi utility
├── Utility.cpp         # Implementasi struktur data dan algoritma
├── data_gudang.txt     # File penyimpanan data barang
└── README.md           # Dokumentasi project
```

## 🔧 Teknologi & Konsep

### Struktur Data
- **Linked List**: Struktur data dinamis untuk menyimpan data barang
- **Node**: Setiap node berisi data barang dan pointer ke node berikutnya

### Algoritma
- **Merge Sort**: Algoritma sorting dengan kompleksitas O(n log n)
- **Sequential Search**: Pencarian linear untuk ID dan nama barang
- **Rekursif**: Perhitungan total aset menggunakan pendekatan rekursif

### Operasi String
- Case-insensitive search menggunakan fungsi `toLowerCase()`

## 💾 Format Data

Data disimpan dalam file `data_gudang.txt` dengan format:
```
ID|Nama Barang|Harga|Stok
```

Contoh:
```
1|Gitar Listrik|1250000|5
2|Gitar Akustik|850000|3
3|Monitor 15 Inch|1750000|6
4|Keyboard Mechanical|500000|4
```

## 🚀 Cara Menjalankan

### Kompilasi Manual
```bash
g++ main.cpp App.cpp Utility.cpp -o build.exe
```

### Menjalankan Program
```bash
./build.exe
```

## 📖 Penggunaan

### Menu Utama
```
=== GUDANG ===
1. Tambah Data
2. Tampilkan Data
3. Cari Data
4. Urutkan Data (Merge Sort)
5. Analisis Aset (Rekursif)
6. Simpan File
7. Keluar
```

### Contoh Penggunaan

#### 1. Menambah Data Baru
```
Pilih: 1
Masukkan ID (Angka): 5
Masukkan Nama: Mouse Gaming
Masukkan Harga: 350000
Masukkan Stok: 10
```

#### 2. Mencari Data
```
Pilih: 3
1. Cari ID
2. Cari Nama
Pilih: 2
Nama dicari: Gitar
```

#### 3. Analisis Aset
```
Pilih: 5
Jumlah Node (Data): 4
Total Aset (Rekursif): Rp 18750000
```

## 🧮 Algoritma Implementasi

### Merge Sort (Linked List)
Algoritma divide-and-conquer yang membagi linked list menjadi dua bagian, mengurutkan secara rekursif, kemudian menggabungkan kembali dalam urutan yang benar berdasarkan ID.

### Sequential Search
Melakukan pencarian linear dari awal hingga akhir linked list untuk menemukan data berdasarkan kriteria tertentu (ID atau nama).

### Perhitungan Rekursif
Menghitung total aset dengan rumus: `Total = (Harga × Stok) + Total(sisa_node)`

## 📝 Catatan Pengembangan

- Data otomatis dimuat dari file saat aplikasi dijalankan
- Data otomatis disimpan saat pengguna memilih keluar
- Memori dibersihkan secara otomatis menggunakan fungsi `hapusSemuaNode()`
- Sorting dilakukan in-place pada linked list tanpa menggunakan array tambahan


## 👨‍💻 Penulis

Project ini dikembangkan sebagai Final Project mata kuliah Pemrograman Lanjut (Pemlang) di Universitas Pembangunan Nasional (UPN).

## 📄 Lisensi

Project ini dibuat untuk keperluan pembelajaran dan dapat digunakan secara bebas untuk tujuan edukatif.

---

**Catatan**: Pastikan file `data_gudang.txt` berada di direktori yang sama dengan executable untuk memastikan data dapat dimuat dengan benar.
