#include "relasi.h"

void createListRelasi(ListRelasi &L) {
    L.first = NULL;
}

adrRelasi alokasiRelasi(adrParent P, adrChild C) {
    adrRelasi R = new Relasi;
    R->parent = P;
    R->child = C;
    R->next = NULL;
    return R;
}

void insertRelasi(ListRelasi &L, ListParent LP, ListChild LC, int idP, string idC) {
    adrParent P = findParent(LP, idP);
    adrChild C = findChild(LC, idC);

    if (P != NULL && C != NULL) {
        if (findRelasi(L, P, C) == NULL) {
            adrRelasi R = alokasiRelasi(P, C);
            if (L.first == NULL) {
                L.first = R;
            } else {
                adrRelasi Q = L.first;
                while (Q->next != NULL) {
                    Q = Q->next;
                }
                Q->next = R;
            }
            cout << "Relasi antara Merk ID " << idP << " dan Sepatu ID " << idC << " berhasil ditambahkan." << endl;
        } else {
            cout << "Relasi antara Merk ID " << idP << " dan Sepatu ID " << idC << " sudah ada." << endl;
        }
    } else {
        if (P == NULL) {
            cout << "Merk (Parent) dengan ID " << idP << " tidak ditemukan." << endl;
        }
        if (C == NULL) {
            cout << "Sepatu (Child) dengan ID " << idC << " tidak ditemukan." << endl;
        }
    }
}

void deleteRelasi(ListRelasi &L, adrParent P, adrChild C) {
    adrRelasi R = L.first;
    adrRelasi prec = NULL;

    while (R != NULL) {
        if (R->parent == P && R->child == C) {
            break;
        }
        prec = R;
        R = R->next;
    }

    if (R != NULL) {
        if (R == L.first) {
            L.first = R->next;
        } else {
            prec->next = R->next;
        }
        string idP = to_string(P->idMerk);
        string idC = C->idSepatu;
        delete R;
        cout << "Relasi antara Merk ID " << idP << " dan Sepatu ID " << idC << " berhasil dihapus." << endl;
    } else {
        cout << "Relasi tidak ditemukan." << endl;
    }
}

adrRelasi findRelasi(ListRelasi L, adrParent P, adrChild C) {
    adrRelasi R = L.first;
    while (R != NULL) {
        if (R->parent == P && R->child == C) {
            return R;
        }
        R = R->next;
    }
    return NULL;
}

void showChildFromParent(ListRelasi LR, int idP) {
    adrRelasi R = LR.first;
    bool found = false;
    cout << "--- Daftar Sepatu (Child) untuk Merk ID " << idP << " ---" << endl;
    while (R != NULL) {
        if (R->parent->idMerk == idP) {
            cout << "ID Sepatu: " << R->child->idSepatu << endl;
            cout << "Nama Sepatu: " << R->child->namaSepatu << endl;
            cout << "Jenis: " << R->child->jenis << endl;
            cout << "-----------------------------------" << endl;
            found = true;
        }
        R = R->next;
    }
    if (!found) {
        cout << "Tidak ada sepatu yang terhubung dengan Merk ID " << idP << "." << endl;
    }
}

void showParentFromChild(ListRelasi LR, string idC) {
    adrRelasi R = LR.first;
    bool found = false;
    cout << "--- Daftar Merk (Parent) untuk Sepatu ID " << idC << " ---" << endl;
    while (R != NULL) {
        if (R->child->idSepatu == idC) {
            cout << "ID Merk: " << R->parent->idMerk << endl;
            cout << "Nama Merk: " << R->parent->namaMerk << endl;
            cout << "Negara Asal: " << R->parent->negaraAsal << endl;
            cout << "-----------------------------------" << endl;
            found = true;
        }
        R = R->next;
    }
    if (!found) {
        cout << "Tidak ada merk yang terhubung dengan Sepatu ID " << idC << "." << endl;
    }
}

void showParentWithRelations(ListParent LP, ListRelasi LR) {
    adrParent P = LP.first;
    if (P == NULL) {
        cout << "Daftar Parent kosong." << endl;
        return;
    }

    cout << "--- Daftar Merk (Parent) dan Sepatu Terkait ---" << endl;
    while (P != NULL) {
        cout << "Merk ID: " << P->idMerk << " | Nama: " << P->namaMerk << endl;
        cout << "  -> Sepatu Terkait:" << endl;
        adrRelasi R = LR.first;
        bool found = false;
        while (R != NULL) {
            if (R->parent == P) {
                cout << "     - ID: " << R->child->idSepatu << ", Nama: " << R->child->namaSepatu << endl;
                found = true;
            }
            R = R->next;
        }
        if (!found) {
            cout << "     (Tidak ada sepatu terkait)" << endl;
        }
        cout << "---------------------------------------------" << endl;
        P = P->next;
    }
}

void showChildWithRelations(ListChild LC, ListRelasi LR) {
    adrChild C = LC.first;
    if (C == NULL) {
        cout << "Daftar Child kosong." << endl;
        return;
    }

    cout << "--- Daftar Sepatu (Child) dan Merk Terkait ---" << endl;
    while (C != NULL) {
        cout << "Sepatu ID: " << C->idSepatu << " | Nama: " << C->namaSepatu << endl;
        cout << "  -> Merk Terkait:" << endl;
        adrRelasi R = LR.first;
        bool found = false;
        while (R != NULL) {
            if (R->child == C) {
                cout << "     - ID: " << R->parent->idMerk << ", Nama: " << R->parent->namaMerk << endl;
                found = true;
            }
            R = R->next;
        }
        if (!found) {
            cout << "     (Tidak ada merk terkait)" << endl;
        }
        cout << "---------------------------------------------" << endl;
        C = C->next;
    }
}

int countChildFromParent(ListRelasi LR, int idP) {
    int count = 0;
    adrRelasi R = LR.first;
    while (R != NULL) {
        if (R->parent->idMerk == idP) {
            count++;
        }
        R = R->next;
    }
    return count;
}

int countParentFromChild(ListRelasi LR, string idC) {
    int count = 0;
    adrRelasi R = LR.first;
    while (R != NULL) {
        if (R->child->idSepatu == idC) {
            count++;
        }
        R = R->next;
    }
    return count;
}

int countChildWithoutParent(ListChild LC, ListRelasi LR) {
    int count = 0;
    adrChild C = LC.first;
    while (C != NULL) {
        bool hasParent = false;
        adrRelasi R = LR.first;
        while (R != NULL) {
            if (R->child == C) {
                hasParent = true;
                break;
            }
            R = R->next;
        }
        if (!hasParent) {
            count++;
        }
        C = C->next;
    }
    return count;
}

int countParentWithoutChild(ListParent LP, ListRelasi LR) {
    int count = 0;
    adrParent P = LP.first;
    while (P != NULL) {
        bool hasChild = false;
        adrRelasi R = LR.first;
        while (R != NULL) {
            if (R->parent == P) {
                hasChild = true;
                break;
            }
            R = R->next;
        }
        if (!hasChild) {
            count++;
        }
        P = P->next;
    }
    return count;
}

void editRelasi(ListRelasi &LR, adrParent oldP, adrChild oldC, adrParent newP, adrChild newC) {
    adrRelasi R = findRelasi(LR, oldP, oldC);
    if (R != NULL) {
        R->parent = newP;
        R->child = newC;
        cout << "Relasi berhasil diubah dari (" << oldP->idMerk << ", " << oldC->idSepatu
             << ") menjadi (" << newP->idMerk << ", " << newC->idSepatu << ")." << endl;
    } else {
        cout << "Relasi lama tidak ditemukan." << endl;
    }
}
