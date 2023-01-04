#include "relasi.h"

void createListRelasi(Relasi &L){
    first(L) = NULL;
}

address_relasi alokasiRelasi(address_parent P, address_child C){
    address_relasi Q = new elmRelasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}

void insertLastRelasi(Relasi& L, address_relasi P){
    address_relasi Q;
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

address_relasi deleteLastRelasi(Relasi &L){
    address_relasi Q = first(L);
    if(next(first((L))) == first(L))
    {
        first(L) = NULL;
        return Q;
    }
    else
    {
        address_relasi P = next(first(L));
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

void printInfoRelasi(Relasi L){
    int i = 1;
    address_relasi P = first(L);
    if(first(L) != NULL) {
        do {
            cout << i << endl;
            cout << "Parent" << endl;
            cout << "Jenis Ekspedisi : " << info(parent(P)).jEks << endl;
            cout << "Jenis Barang : " << info(parent(P)).jBar << endl << endl;
            cout << "Child" << endl;
            cout << "Nama Pengirim : " << info(child(P)).namaPeng << endl;
            cout << "Alamat : " << info(child(P)).Almt << endl;
            cout << "Berat : " << info(child(P)).Berat << endl << endl;
            P = next(P);
            i++;
        } while(P != first(L));
    }else {
        cout << "Relasi Kosong" << endl << endl;
    }
}
