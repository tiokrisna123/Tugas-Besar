#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Child;
struct Relasi;

typedef struct Parent *adrParent;

struct Parent {
    int idMerk;
    string namaMerk;
    string negaraAsal;

    adrParent next;
};

struct ListParent {
    adrParent first;
};

void createListParent(ListParent &L);
adrParent alokasiParent(int id, string nama, string negara);
void insertParent(ListParent &L, adrParent P);
void deleteParent(ListParent &L, int id);
adrParent findParent(ListParent L, int id);
void showAllParent(ListParent L);
#endif // PARENT_H_INCLUDED