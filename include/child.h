#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Parent;
struct Relasi;

typedef struct Child *adrChild;

struct Child {
    string idSepatu;
    string namaSepatu;
    string jenis;
    int harga;
    int ukuran;

    adrChild next;
};

struct ListChild {
    adrChild first;
};

void createListChild(ListChild &L);
adrChild alokasiChild(string id, string nama, string jenis, int harga, int ukuran);
void insertChild(ListChild &L, adrChild P);
void deleteChild(ListChild &L, string id);
adrChild findChild(ListChild L, string id);
void showAllChild(ListChild L);


#endif // CHILD_H_INCLUDED