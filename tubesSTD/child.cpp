#include "child.h"

void createListChild(Child &L){
    first(L) = NULL;
}

address_child alokasiChild(infotype_child x){
    address_child P = new elmChild;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertLastChild(Child &L, address_child P){
    address_child Q;
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

address_child deleteLastChild(Child &L){
    address_child Q = first(L);
    if(next(first((L))) == first(L))
    {
        first(L) = NULL;
        return Q;
    }
    else
    {
        address_child P = next(first(L));
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

void printInfoChild(Child L){
    address_child P = first(L);
    int x = 1;
    if(first(L)!=NULL) {
        do {
            cout << info(P).namaPeng << " " << info(P).Almt << " " << info(P).Berat << endl;
            x += 1;
            P = next(P);
        } while(P != first(L));
    }
}

address_child findElmChild(Child L, string x){
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).Almt == x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

infotype_child inputChild(){
    infotype_child IC;
    string namaPeng, Almt, Berat;
    cout<<"Masukan Nama Pengirim : ";cin>>namaPeng;cout << endl;
    cout<<"Masukan Alamat : ";cin>>Almt;cout << endl;
    cout<<"Masukan Berat : ";cin>>Berat;cout << endl;
    IC.namaPeng = namaPeng;
    IC.Almt = Almt;
    IC.Berat = Berat;

    return IC;
}
