#ifndef UTILITY_H
#define UTILITY_H

#include <string>
using namespace std;

// 1. Data Barang
struct Barang {
    int id;
    string nama;
    int harga;
    int stok;
};

// 2. Node Linked List (Pengganti Array)
struct Node {
    Barang data;
    Node* next;
};

// --- Manipulasi String ---
string toLowerCase(string str);

// --- Manipulasi Linked List ---
void tambahNodeBelakang(Node*& head, Barang dataBaru);
void hapusSemuaNode(Node*& head);
int hitungJumlahNode(Node* head);

// --- Sorting (Merge Sort untuk Linked List) ---
void mergeSort(Node*& head);
// Fungsi bantuan Merge Sort (tidak perlu dipanggil di App)
Node* split(Node* head);
Node* merge(Node* first, Node* second);

// --- Searching (Sequential Search) ---
// Mengembalikan pointer ke Node yang ketemu, atau NULL jika tidak ketemu
Node* cariBerdasarkanID(Node* head, int cariID);
Node* cariBerdasarkanNama(Node* head, string cariNama);

// --- Rekursif Analisis ---
long long hitungTotalAset(Node* head);

// --- Tampilan ---
void tampilkanHeader();
void tampilkanBaris(Barang b);

#endif
