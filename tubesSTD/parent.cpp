#include "parent.h"

void createListParent(Parent &L){
    first(L) = NULL;
}

address_parent alokasiParent(infotype_parent x){
    address_parent P;
    P = new elmParent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertLastParent(Parent &L, address_parent P){
    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }
}

address_parent deleteLastParent(Parent &L){
    address_parent Q = first(L);
    if(next(first((L))) == first(L))
    {
        first(L) = NULL;
        return Q;
    }
    else
    {
        address_parent P = next(first(L));
        while(next(P) != first(L))
        {
            Q = P;
            P = next(P);
        }
        next(Q) = first(L);
        next(P) = NULL;
        return P;
    }
}

void printInfoParent(Parent L){
    address_parent P = first(L);
    int x = 1;
    if(first(L) != NULL) {
        do {
            cout << info(P).jEks << " " << info(P).jBar << endl;
            x += 1;
            P = next(P);
        } while(P != first(L));
    }
}

infotype_parent inputParent(){
    infotype_parent IP;
    string jEks, jBar;
    cout<<"Masukan Jenis Ekspedisi : ";cin>>jEks;cout << endl;
    cout<<"Masukan Jenis Barang : ";cin>>jBar;cout << endl;
    IP.jEks = jEks;
    IP.jBar = jBar;

    return IP;
}
