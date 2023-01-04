#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

typedef struct infotype_parent{
    string jEks, jBar;
};

typedef struct elmParent *address_parent;

struct elmParent {
    infotype_parent info;
    address_parent next;
};

struct Parent {
    address_parent first;
};

void createListParent(Parent &L);
address_parent alokasiParent(infotype_parent x);
void insertLastParent(Parent &L, address_parent P);
address_parent deleteLastParent(Parent &L);
void printInfoParent(Parent L);
infotype_parent inputParent();

#endif // PARENT_H_INCLUDED
