#include <iostream>
#include <string>
#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;

void menu() {
    cout << "\n=================================================" << endl;
    cout << "          APLIKASI MANAJEMEN MERK DAN SEPATU" << endl;
    cout << "            (Multi-Level Linked List)" << endl;
    cout << "=================================================" << endl;
    cout << "1. Tambah Merk (Parent)" << endl;
    cout << "2. Tambah Sepatu (Child)" << endl;
    cout << "3. Hubungkan Sepatu ke Merk (Relasi)" << endl;
    cout << "4. Tampilkan Semua Merk" << endl;
    cout << "5. Tampilkan Semua Sepatu" << endl;
    cout << "6. Tampilkan Sepatu dari Merk Tertentu" << endl;
    cout << "7. Tampilkan Semua Merk dengan Sepatu Terkait" << endl;
    cout << "8. Hapus Merk (Parent) dan Relasinya" << endl;
    cout << "9. Hapus Sepatu (Child) dan Relasinya" << endl;
    cout << "10. Hapus Relasi Tertentu" << endl;
    cout << "11. Hitung Sepatu Tanpa Merk (Unrelated Child)" << endl;
    cout << "0. Keluar" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Pilihan Anda: ";
}

int main() {
    ListParent LP;
    ListChild LC;
    ListRelasi LR;

    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);

    insertParent(LP, alokasiParent(101, "Nike", "USA"));
    insertParent(LP, alokasiParent(202, "Adidas", "Jerman"));
    insertParent(LP, alokasiParent(303, "Ventela", "Indonesia"));

    insertChild(LC, alokasiChild("SNK01", "Air Force 1", "Lifestyle", 1200000, 42));
    insertChild(LC, alokasiChild("SNK02", "Air Jordan 1", "Basket", 2500000, 43));
    insertChild(LC, alokasiChild("AD01", "Ultraboost 22", "Running", 2100000, 41));
    insertChild(LC, alokasiChild("AD02", "Samba OG", "Lifestyle", 1100000, 42));
    insertChild(LC, alokasiChild("VNT01", "Back to 70s", "Casual", 300000, 40));

    insertRelasi(LR, LP, LC, 101, "SNK01"); 
    insertRelasi(LR, LP, LC, 101, "SNK02"); 
    insertRelasi(LR, LP, LC, 202, "AD01");  
    insertRelasi(LR, LP, LC, 202, "AD02");  
    insertRelasi(LR, LP, LC, 303, "VNT01"); 
    insertChild(LC, alokasiChild("UNR01", "Sepatu Polos", "Casual", 100000, 39));

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
    
    int pilihan;
    do {
        system("cls || clear"); 

        menu();
        cin >> pilihan;
        system("cls || clear"); 

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
                        cout << "\nMerk berhasil ditambahkan." << endl;
                    } else {
                        cout << "\nError: ID Merk sudah ada." << endl;
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
                        cout << "\nSepatu berhasil ditambahkan." << endl;
                    } else {
                        cout << "\nError: ID Sepatu sudah ada." << endl;
                    }
                }
                break;
            case 3:
                cout << "--- Hubungkan Relasi ---" << endl;
                cout << "ID Merk (Parent): "; cin >> idP;
                cout << "ID Sepatu (Child): "; cin >> idC;
                insertRelasi(LR, LP, LC, idP, idC);
                break;
            case 4:
                showAllParent(LP);
                break;
            case 5:
                showAllChild(LC);
                break;
            case 6:
                cout << "--- Tampilkan Sepatu dari Merk ---" << endl;
                cout << "Masukkan ID Merk: "; cin >> idP;
                cout << endl;
                showChildFromParent(LR, idP);
                break;
            case 7:
                showParentWithRelations(LP, LR);
                break;
            case 8:
                cout << "--- Hapus Merk (Parent) ---" << endl;
                cout << "Masukkan ID Merk yang akan dihapus: "; cin >> idP;
                P = findParent(LP, idP);
                if (P != NULL) {
                    R = LR.first;
                    while (R != NULL) {
                        adrRelasi temp = R;
                        R = R->next;
                        if (temp->parent == P) {
                            deleteRelasi(LR, P, temp->child);
                        }
                    }
                    deleteParent(LP, idP);
                    cout << "\nMerk berhasil dihapus." << endl;
                } else {
                    cout << "\nMerk tidak ditemukan." << endl;
                }
                break;
            case 9:
                cout << "--- Hapus Sepatu (Child) ---" << endl;
                cout << "Masukkan ID Sepatu yang akan dihapus: "; cin >> idC;
                C = findChild(LC, idC);
                if (C != NULL) {
                    R = LR.first;
                    while (R != NULL) {
                        adrRelasi temp = R;
                        R = R->next;
                        if (temp->child == C) {
                            deleteRelasi(LR, temp->parent, C);
                        }
                    }
                    deleteChild(LC, idC);
                    cout << "\nSepatu berhasil dihapus." << endl;
                } else {
                    cout << "\nSepatu tidak ditemukan." << endl;
                }
                break;
            case 10:
                cout << "--- Hapus Relasi ---" << endl;
                cout << "ID Merk (Parent): "; cin >> idP;
                cout << "ID Sepatu (Child): "; cin >> idC;
                P = findParent(LP, idP);
                C = findChild(LC, idC);
                if (P != NULL && C != NULL) {
                    deleteRelasi(LR, P, C);
                    cout << "\nRelasi berhasil dihapus." << endl;
                } else {
                    cout << "\nGagal: Merk atau Sepatu tidak ditemukan." << endl;
                }
                break;
            case 11:
                cout << "Jumlah Sepatu Tanpa Merk: "
                     << countChildWithoutParent(LC, LR) << endl;
                break;
            case 0:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        if (pilihan != 0) {
            cout << "\nTekan ENTER untuk kembali ke menu...";
            cin.ignore(1000, '\n'); 
            if (cin.peek() == '\n') cin.ignore(); 
            cin.get(); 
        }

    } while (pilihan != 0);

    return 0;
}