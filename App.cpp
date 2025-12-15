#include "App.h"
#include "Utility.h"
#include <iostream>
#include <fstream>

// --- VARIABEL GLOBAL LINKED LIST ---
Node* head = nullptr; // Pointer kepala Linked List (Awalnya kosong)
string namaFile = "data_gudang.txt";

void jalankanAplikasi() {
    bacaFile(); // Load data ke Linked List

    int pilihan;
    do {
        cout << "\n=== GUDANG ===" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Cari Data" << endl;
        cout << "4. Urutkan Data (Merge Sort)" << endl;
        cout << "5. Analisis Aset (Rekursif)" << endl;
        cout << "6. Simpan File" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: menuTambah(); break;
            case 2: menuTampil(); break;
            case 3: menuCari(); break;
            case 4: menuUrut(); break;
            case 5: menuAnalisis(); break;
            case 6: simpanFile(); break;
            case 7:
                simpanFile(); // Auto save saat keluar
                hapusSemuaNode(head); // Bersihkan memori
                cout << "Memori dibersihkan. Keluar..." << endl;
                break;
            default: cout << "Salah input!" << endl;
        }
    } while (pilihan != 7);
}

void menuTambah() {
    Barang b;
    cout << "Masukkan ID (Angka): "; cin >> b.id;
    cin.ignore();
    cout << "Masukkan Nama: "; getline(cin, b.nama);
    cout << "Masukkan Harga: "; cin >> b.harga;
    cout << "Masukkan Stok: "; cin >> b.stok;

    // Masukkan ke Linked List
    tambahNodeBelakang(head, b);
    cout << "Data berhasil ditambahkan" << endl;
}

void menuTampil() {
    if (head == nullptr) {
        cout << "Data Kosong." << endl; return;
    }
    tampilkanHeader();
    Node* temp = head;
    while (temp != nullptr) {
        tampilkanBaris(temp->data);
        temp = temp->next;
    }
}

void menuCari() {
    if (head == nullptr) {
        cout << "Data Kosong." << endl; return;
    }

    cout << "1. Cari ID\n2. Cari Nama\nPilih: ";
    int mode; cin >> mode;
    Node* hasil = nullptr;

    if (mode == 1) {
        int idCari;
        cout << "ID dicari: "; cin >> idCari;
        hasil = cariBerdasarkanID(head, idCari);
    } else {
        string nm;
        cout << "Nama dicari: "; cin.ignore(); getline(cin, nm);
        hasil = cariBerdasarkanNama(head, nm);
    }

    if (hasil != nullptr) {
        cout << "DITEMUKAN:" << endl;
        tampilkanHeader();
        tampilkanBaris(hasil->data);
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

void menuUrut() {
    if (head == nullptr || head->next == nullptr) {
        cout << "Data terlalu sedikit." << endl; return;
    }
    cout << "Melakukan Merge Sort" << endl;
    mergeSort(head);
    cout << "Sorting Selesai!" << endl;
    menuTampil();
}

void menuAnalisis() {
    int jum = hitungJumlahNode(head);
    cout << "Jumlah Node (Data): " << jum << endl;
    cout << "Total Aset (Rekursif): Rp " << hitungTotalAset(head) << endl;
}

void simpanFile() {
    ofstream file(namaFile);
    if (file.is_open()) {
        Node* temp = head;
        // Tidak perlu simpan jumlah data di awal, cukup loop sampai habis
        while (temp != nullptr) {
            file << temp->data.id << "|" << temp->data.nama << "|"
                 << temp->data.harga << "|" << temp->data.stok << endl;
            temp = temp->next;
        }
        file.close();
        cout << "File berhasil disimpan." << endl;
    } else cout << "Gagal akses file." << endl;
}

void bacaFile() {
    ifstream file(namaFile);
    if (file.is_open()) {
        // Hapus list lama jika ada (reload)
        hapusSemuaNode(head);

        string buff;
        // Loop membaca baris per baris
        while (getline(file, buff, '|')) { // Baca ID
            Barang b;
            b.id = stoi(buff);

            getline(file, buff, '|'); b.nama = buff;
            getline(file, buff, '|'); b.harga = stoi(buff);
            getline(file, buff);      b.stok = stoi(buff);

            tambahNodeBelakang(head, b);
        }
        file.close();
    }
}
