#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "child.h"
#include "parent.h"
#include <iostream>
#include <string>

using namespace std;

struct Parent;
struct Child;



typedef struct Relasi *adrRelasi;

struct Relasi {
    adrParent parent;
    adrChild child;
    adrRelasi next;
};

struct ListRelasi {
    adrRelasi first;
};

void createListRelasi(ListRelasi &L);
adrRelasi alokasiRelasi(adrParent P, adrChild C);
void insertRelasi(ListRelasi &L, ListParent LP, ListChild LC, int idP, string idC);
void deleteRelasi(ListRelasi &L, adrParent P, adrChild C);
adrRelasi findRelasi(ListRelasi L, adrParent P, adrChild C);
void showChildFromParent(ListRelasi LR, int idP);
void showParentFromChild(ListRelasi LR, string idC);
void showParentWithRelations(ListParent LP, ListRelasi LR);
void showChildWithRelations(ListChild LC, ListRelasi LR);
int countChildFromParent(ListRelasi LR, int idP);
int countParentFromChild(ListRelasi LR, string idC);
int countChildWithoutParent(ListChild LC, ListRelasi LR);
int countParentWithoutChild(ListParent LP, ListRelasi LR);
void editRelasi(ListRelasi &LR, adrParent oldP, adrChild oldC, adrParent newP, adrChild newC);
#endif // RELASI_H_INCLUDED
