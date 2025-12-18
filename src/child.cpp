#include "child.h"

// Implementasi fungsi-fungsi untuk Child
void createListChild(ListChild &L) {
    L.first = NULL;
}

adrChild alokasiChild(string id, string nama, string jenis, int harga, int ukuran) {
    adrChild C = new Child;
    C->idSepatu = id;
    C->namaSepatu = nama;
    C->jenis = jenis;
    C->harga = harga;
    C->ukuran = ukuran;
    C->next = NULL;
    return C;
}
//adjadjauidau
void insertChild(ListChild &L, adrChild P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adrChild Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteChild(ListChild &L, string id) {
    adrChild C = findChild(L, id);
    if (C != NULL) {
        if (C == L.first) {
            // Kasus 1: Node pertama
            L.first = C->next;
        } else {
            // Kasus 2: Node di tengah atau terakhir
            adrChild prec = L.first;
            while (prec->next != C) {
                prec = prec->next;
            }
            prec->next = C->next;
        }
        delete C;
        cout << "Sepatu dengan ID " << id << " berhasil dihapus." << endl;
    } else {
        cout << "Sepatu dengan ID " << id << " tidak ditemukan." << endl;
    }
}

adrChild findChild(ListChild L, string id) {
    adrChild P = L.first;
    while (P != NULL) {
        if (P->idSepatu == id) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void showAllChild(ListChild L) {
    adrChild P = L.first;
    if (P == NULL) {
        cout << "Tidak ada model sepatu (Child) dalam daftar." << endl;
        return;
    }
    cout << "--- Daftar Semua Model Sepatu (Child) ---" << endl;
    while (P != NULL) {
        cout << "ID Sepatu: " << P->idSepatu << endl;
        cout << "Nama Sepatu: " << P->namaSepatu << endl;
        cout << "Jenis: " << P->jenis << endl;
        cout << "Harga: " << P->harga << endl;
        cout << "Ukuran: " << P->ukuran << endl;
        cout << "-----------------------------------" << endl;
        P = P->next;
    }
}
