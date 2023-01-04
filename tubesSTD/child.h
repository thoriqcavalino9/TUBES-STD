#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef struct infotype_child{
    string namaPeng, Almt, Berat;
};

typedef struct elmChild *address_child;

struct elmChild{
    infotype_child info;
    address_child next;
};

struct Child{
    address_child first;
};

void createListChild(Child &L);
address_child alokasiChild(infotype_child x);
void insertLastChild(Child &L, address_child P);
address_child deleteLastChild(Child &L);
void printInfoChild(Child L);
address_child findElmChild(Child L, string x);
infotype_child inputChild();

#endif // CHILD_H_INCLUDED
