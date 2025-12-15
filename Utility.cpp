#include "Utility.h"
#include <iostream>
#include <iomanip>

string toLowerCase(string str) {
    string hasil = str;
    for (char &c : hasil) c = tolower(c);
    return hasil;
}

// Menambah data baru di akhir list (agar urutan file terjaga)
void tambahNodeBelakang(Node*& head, Barang dataBaru) {
    Node* newNode = new Node;
    newNode->data = dataBaru;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Membersihkan memori saat program keluar
void hapusSemuaNode(Node*& head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int hitungJumlahNode(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// --- LOGIKA MERGE SORT (REKURSIF) ---
// 1. Fungsi Split: Membagi list jadi dua
Node* split(Node* head) {
    Node* fast = head;
    Node* slow = head;

    // Fast jalan 2 langkah, Slow jalan 1 langkah
    while (fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = nullptr; // Putus koneksi
    return temp;
}

// 2. Fungsi Merge: Menggabungkan dua list urut
Node* merge(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

    Node* result = nullptr;
    // Urutkan berdasarkan ID
    if (first->data.id < second->data.id) {
        result = first;
        result->next = merge(first->next, second);
    } else {
        result = second;
        result->next = merge(first, second->next);
    }
    return result;
}

// 3. Fungsi Utama Merge Sort
void mergeSort(Node*& head) {
    if (!head || !head->next) return; // Base case rekursif

    Node* second = split(head);

    // Rekursif sort kedua bagian
    mergeSort(head);
    mergeSort(second);

    // Gabungkan kembali
    head = merge(head, second);
}

// --- SEARCHING ---
Node* cariBerdasarkanID(Node* head, int cariID) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.id == cariID) return temp;
        temp = temp->next;
    }
    return nullptr;
}

Node* cariBerdasarkanNama(Node* head, string cariNama) {
    string target = toLowerCase(cariNama);
    Node* temp = head;
    while (temp != nullptr) {
        if (toLowerCase(temp->data.nama).find(target) != string::npos) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// --- ANALISIS REKURSIF ---
long long hitungTotalAset(Node* head) {
    if (head == nullptr) return 0;
    return (head->data.harga * head->data.stok) + hitungTotalAset(head->next);
}

void tampilkanHeader() {
    cout << "--------------------------------------------------" << endl;
    cout << left << setw(5) << "ID" << setw(20) << "Nama Barang"
         << setw(15) << "Harga" << setw(10) << "Stok" << endl;
    cout << "--------------------------------------------------" << endl;
}

void tampilkanBaris(Barang b) {
    cout << left << setw(5) << b.id << setw(20) << b.nama
         << setw(15) << b.harga << setw(10) << b.stok << endl;
}
