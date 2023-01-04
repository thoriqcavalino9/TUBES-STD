#include "menu.h"

int selectMenu(){
    cout << "======MENU======" << endl;
    cout << "1. Insert Data" << endl;
    cout << "2. Show All Data" << endl;
    cout << "3. Menghapus data pengiriman" << endl;
    cout << "4. Mencari alamat pengiriman" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukan Menu : ";

    int input = 0;
    cin >> input;
    cout << endl;
    return input;
}

void running(){
    string pil;
    //Parent
    Parent LP;
    address_parent AP;
    infotype_parent IP;
    createListParent(LP);
    //endParent

    //Child
    Child LC;
    address_child AC;
    infotype_child IC;
    createListChild(LC);
    //endChild

    //Relasi
    Relasi R;
    address_relasi AR;
    createListRelasi(R);
    //endRelasi

    int pilihan = 0;
    pilihan = selectMenu();
    string sChild;
    while (pilihan != 0) {
        switch (pilihan){
        case 1:
            //Insert
            IP = inputParent();
            AP = alokasiParent(IP);
            insertLastParent(LP, AP);
            //

            //Insert
            IC = inputChild();
            AC = alokasiChild(IC);
            insertLastChild(LC, AC);
            //

            //Insert
            AR = alokasiRelasi(AP, AC);
            insertLastRelasi(R, AR);
            //
            break;
        case 2:
            printInfoRelasi(R);
            break;
        case 3:
            deleteLastRelasi(R);
            cout << "Data berhasil dihapus" << endl;
            break;
        case 4:
            cout<<"Masukan alamat pengiriman : ";cin>>sChild;cout << endl;
            AC = findElmChild(LC, sChild);
            if (AC == NULL) {
                cout << "Alamat tidak tersedia" << endl;
                break;
            } else {
                AR = first(R);
                while (info(child(AR)).Almt != info(AC).Almt) {
                    AR = next(AR);
                }
                cout << "Parent" << endl;
                cout << "Jenis Ekspedisi : " << info(parent(AR)).jEks << endl;
                cout << "Jenis Barang : " << info(parent(AR)).jBar << endl << endl;
                cout << "Child" << endl;
                cout << "Nama Pengirim : " << info(child(AR)).namaPeng << endl;
                cout << "Alamat : " << info(child(AR)).Almt << endl;
                cout << "Berat : " << info(child(AR)).Berat << endl << endl;
                break;
            }
        }
        cout<<"Kembali ke menu utama ? (Y/N) : ";cin>>pil;
            if (pil == "Y"){
                pilihan = selectMenu();
            }else if (pil == "N"){
                pilihan = 0;
            }
    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
}
