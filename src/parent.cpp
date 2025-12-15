#include "parent.h"

// Implementasi fungsi-fungsi untuk Parent
void createListParent(ListParent &L) {
    L.first = NULL;
}

adrParent alokasiParent(int id, string nama, string negara) {
    adrParent P = new Parent;
    P->idMerk = id;
    P->namaMerk = nama;
    P->negaraAsal = negara;
    P->next = NULL;
    return P;
}

void insertParent(ListParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adrParent Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteParent(ListParent &L, int id) {
    adrParent P = findParent(L, id);
    if (P != NULL) {
        if (P == L.first) {
            // Kasus 1: Node pertama
            L.first = P->next;
        } else {
            // Kasus 2: Node di tengah atau terakhir
            adrParent prec = L.first;
            while (prec->next != P) {
                prec = prec->next;
            }
            prec->next = P->next;
        }
        delete P;
        cout << "Merk dengan ID " << id << " berhasil dihapus." << endl;
    } else {
        cout << "Merk dengan ID " << id << " tidak ditemukan." << endl;
    }
}

adrParent findParent(ListParent L, int id) {
    adrParent P = L.first;
    while (P != NULL) {
        if (P->idMerk == id) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void showAllParent(ListParent L) {
    adrParent P = L.first;
    if (P == NULL) {
        cout << "Tidak ada merk (Parent) dalam daftar." << endl;
        return;
    }
    cout << "--- Daftar Semua Merk (Parent) ---" << endl;
    while (P != NULL) {
        cout << "ID Merk: " << P->idMerk << endl;
        cout << "Nama Merk: " << P->namaMerk << endl;
        cout << "Negara Asal: " << P->negaraAsal << endl;
        cout << "-----------------------------------" << endl;
        P = P->next;
    }
}
