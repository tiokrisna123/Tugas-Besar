#include <iostream>
#include <string>
#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;
void separator();
void menu() {
    separator();
    //cout << "\n=================================================\n";
    cout << "   APLIKASI MANAJEMEN MERK DAN SEPATU\n";
    cout << "      (Multi-Level Linked List)\n";
    //cout << "=================================================\n";

    cout << "\n--- MENU MASTER DATA ---\n";
    cout << "1. Tambah Merk (Parent)\n";
    cout << "2. Tambah Sepatu (Child)\n";
    cout << "3. Tampilkan Semua Merk\n";
    cout << "4. Tampilkan Semua Sepatu\n";

    cout << "\n--- MENU RELASI ---\n";
    cout << "5. Hubungkan Sepatu ke Merk\n";
    cout << "6. Tampilkan Sepatu dari Merk Tertentu\n";
    cout << "7. Tampilkan Semua Merk dengan Sepatu Terkait\n";
    cout << "8. Hapus Relasi Tertentu\n";

    cout << "\n--- MENU PENGHAPUSAN DATA ---\n";
    cout << "9. Hapus Merk (Parent) dan Relasinya\n";
    cout << "10. Hapus Sepatu (Child) dan Relasinya\n";

    cout << "\n--- MENU LAPORAN ---\n";
    cout << "11. Lihat Sepatu Tanpa Merk\n";

    cout << "\n0. Keluar\n";
    separator();
    //cout << "-------------------------------------------------\n";
    cout << "Pilihan Anda: ";
}

void separator() {
    cout << "\n=================================================\n";
}


int main() {
    // Deklarasi List
    ListParent LP;
    ListChild LC;
    ListRelasi LR;

    // Inisialisasi List
    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);

    // --- Data Dummy untuk Pengujian ---
    // Tambah Parent
    insertParent(LP, alokasiParent(101, "Nike", "USA"));
    insertParent(LP, alokasiParent(202, "Adidas", "Jerman"));
    insertParent(LP, alokasiParent(303, "Ventela", "Indonesia"));

    // Tambah Child
    insertChild(LC, alokasiChild("SNK01", "Air Force 1", "Lifestyle", 1200000, 42));
    insertChild(LC, alokasiChild("SNK02", "Air Jordan 1", "Basket", 2500000, 43));
    insertChild(LC, alokasiChild("AD01", "Ultraboost 22", "Running", 2100000, 41));
    insertChild(LC, alokasiChild("AD02", "Samba OG", "Lifestyle", 1100000, 42));
    insertChild(LC, alokasiChild("VNT01", "Back to 70s", "Casual", 300000, 40));

    // Hubungkan Relasi
    insertRelasi(LR, LP, LC, 101, "SNK01"); // Nike -> Air Force 1
    insertRelasi(LR, LP, LC, 101, "SNK02"); // Nike -> Air Jordan 1
    insertRelasi(LR, LP, LC, 202, "AD01");  // Adidas -> Ultraboost 22
    insertRelasi(LR, LP, LC, 202, "AD02");  // Adidas -> Samba OG
    insertRelasi(LR, LP, LC, 303, "VNT01"); // Ventela -> Back to 70s
    // Tambah satu sepatu tanpa merk (Unrelated Child)
    insertChild(LC, alokasiChild("UNR01", "Sepatu Polos", "Casual", 100000, 39));

    // --- Logika Menu ---
    int pilihan;
    do {
        menu();
        cin >> pilihan;


        int idP;
        string idC;
        adrParent P;
        adrChild C;
        adrRelasi R;

        switch (pilihan) {
            case 1:
                cout << "--- Tambah Merk (Parent) ---" << endl;
                cout << "ID Merk (int): "; cin >> idP;
                {
                    string nama, negara;
                    cout << "Nama Merk: "; cin.ignore(); getline(cin, nama);
                    cout << "Negara Asal: "; getline(cin, negara);
                    if (findParent(LP, idP) == NULL) {
                        insertParent(LP, alokasiParent(idP, nama, negara));
                        cout << "Merk berhasil ditambahkan." << endl;
                    } else {
                        cout << "Error: ID Merk sudah ada." << endl;
                    }
                }
                break;
            case 2:
                cout << "--- Tambah Sepatu (Child) ---" << endl;
                cout << "ID Sepatu (string): "; cin >> idC;
                {
                    string nama, jenis;
                    int harga, ukuran;
                    cout << "Nama Sepatu: "; cin.ignore(); getline(cin, nama);
                    cout << "Jenis: "; getline(cin, jenis);
                    cout << "Harga: "; cin >> harga;
                    cout << "Ukuran: "; cin >> ukuran;
                    if (findChild(LC, idC) == NULL) {
                        insertChild(LC, alokasiChild(idC, nama, jenis, harga, ukuran));
                        cout << "Sepatu berhasil ditambahkan." << endl;
                    } else {
                        cout << "Error: ID Sepatu sudah ada." << endl;
                    }
                }
                break;
            case 3:
                separator();
                showAllChild(LC);
                separator();
                break;
            case 4:
                separator();
                showAllParent(LP);
                separator();
                break;
            case 5:
                cout << "--- Hubungkan Sepatu ke Merk ---" << endl;
                cout << "\nDaftar Merk Tersedia: " << endl;
                showAllParent(LP);
                cout << "Masukan ID Merk: ";
                cin >> idP;

                cout << "\nDaftar Sepatu Tersedia: " << endl;
                showAllChild(LC);
                cout << "Masukan ID Sepatu: ";
                cin >> idC;
                insertRelasi(LR, LP, LC, idP, idC);
                break;
            case 6:
                cout << "--- Tampilkan Sepatu dari Merk ---" << endl;
                cout << "\nDaftar Merk Tersedia: " << endl;
                showAllParent(LP);
                cout << "Masukan ID Merk: ";
                cin >> idP;
                showChildFromParent(LR, idP);
                break;
            case 7:
                showParentWithRelations(LP, LR);
                break;
            case 8:
                cout << "--- Hapus Merk (Parent) ---" << endl;
                cout << "\nDaftar Merk Tersedia: " << endl;
                showAllParent(LP);
                cout << "Masukkan ID Merk yang akan dihapus: ";
                cin >> idP;
                P = findParent(LP, idP);
                if (P != NULL) {
                    // Hapus semua relasi yang melibatkan Parent ini terlebih dahulu
                    R = LR.first;
                    while (R != NULL) {
                        adrRelasi temp = R;
                        R = R->next;
                        if (temp->parent == P) {
                            deleteRelasi(LR, P, temp->child);
                        }
                    }
                    deleteParent(LP, idP);
                } else {
                    cout << "Merk dengan ID " << idP << " tidak ditemukan." << endl;
                }
                break;
            case 9:
                cout << "--- Hapus Sepatu (Child) ---" << endl;
                cout << "\nDaftar Sepatu yang Tersedia: " << endl;
                showAllChild(LC);
                cout << "Masukkan ID Sepatu yang akan dihapus: "; cin >> idC;
                C = findChild(LC, idC);
                if (C != NULL) {
                    // Hapus semua relasi yang melibatkan Child ini terlebih dahulu
                    R = LR.first;
                    while (R != NULL) {
                        adrRelasi temp = R;
                        R = R->next;
                        if (temp->child == C) {
                            deleteRelasi(LR, temp->parent, C);
                        }
                    }
                    deleteChild(LC, idC);
                } else {
                    cout << "Sepatu dengan ID " << idC << " tidak ditemukan." << endl;
                }
                break;
            case 10:
                cout << "--- Hapus Relasi ---" << endl;
                cout << "\nDaftar Merk yang Tersedia: " << endl;
                showAllParent(LP);
                cout << "ID Merk (Parent) relasi: ";
                cin >> idP;

                cout << "\nDaftar Sepatu yang Tersedia: " << endl;
                showAllChild(LC);
                cout << "ID Sepatu (Child) relasi: ";
                cin >> idC;

                P = findParent(LP, idP);
                C = findChild(LC, idC);

                if (P != NULL && C != NULL) {
                    deleteRelasi(LR, P, C);
                } else {
                    cout << "Gagal: Merk atau Sepatu tidak ditemukan." << endl;
                }
                break;
            case 11: {
                separator();
                cout << "--- Sepatu Tanpa Merk (Unrelated Child) ---" << endl;

                int jumlah = countChildWithoutParent(LC, LR);
                cout << "Jumlah Sepatu Tanpa Merk: " << jumlah << endl << endl;

                if (jumlah == 0) {
                    cout << "Semua sepatu sudah memiliki merk" << endl;
                } else {
                    adrChild C = LC.first;
                    while (C != nullptr) {
                        bool hasParent = false;
                        adrRelasi R = LR.first;

                        while (R != nullptr) {
                            if (R->child == C) {
                                hasParent = true;
                                break;
                            }
                            R = R->next;
                        }
                        if (!hasParent) {
                            cout << "ID Sepatu  : " << C->idSepatu << endl;
                            cout << "Nama       : " << C->namaSepatu << endl;
                            cout << "Jenis      : " << C->jenis << endl;
                            cout << "Harga      : " << C->harga << endl;
                            cout << "Ukuran     : " << C->ukuran << endl;
                            cout << "-----------------------------" << endl;
                        }
                        C = C->next;
                    }
                }
                separator();
                break;
            }
            case 0:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }

        if (pilihan != 0) {
            cout << "\nTekan ENTER untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

    } while (pilihan != 0);

    return 0;
}
