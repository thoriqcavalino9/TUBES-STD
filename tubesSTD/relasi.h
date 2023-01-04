#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "child.h"
#include "parent.h"

using namespace std;

#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmRelasi *address_relasi;

struct elmRelasi{
    address_relasi next;
    address_child child;
    address_parent parent;
};

struct Relasi{
    address_relasi first;
};

void createListRelasi(Relasi &L);
address_relasi alokasiRelasi(address_parent P, address_child C);
void insertLastRelasi(Relasi& L, address_relasi P);
address_relasi deleteLastRelasi(Relasi &L);
void printInfoRelasi(Relasi L);

#endif // RELASI_H_INCLUDED
