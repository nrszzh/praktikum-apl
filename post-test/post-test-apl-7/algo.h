#ifndef algo.h
#define algo.h

#include <iostream>
#include <string>
#include <cstdlib>
#include "bantu.h"
using namespace std;

int tingkat = 2;
int slot = 20;

struct data_parkir {
    string plat = "-";
    int id_member = -1; 
    bool terisi = false;
    bool booking = false;
    int jam_masuk = 0;
};

struct data_member {
    int id;
    string nama;
    string pw;
    int saldo = 0;
    bool aktif = false;
};

void top_up_saldo(data_member *member) { 
    int nominal;
    cout << " Masukkan Nominal: Rp"; 
    while (!(cin >> nominal)) {
        ehr_input();
        system("cls");
        cout << " === TOP UP SALDO ===\n";
        cout << " Masukkan Nominal: Rp";
    }

    try {
        if (nominal <= 0) {
            throw invalid_argument("Nominal tidak valid!");
        }
        member->saldo += nominal;
        cout << ">> Saldo Berhasil ditambahkan" << endl;
    }
    catch (const invalid_argument& e) {
        cout << "\n \033[31m >>  " << e.what() << "\033[0m" << endl;
    }
}

void hitung_biaya(int *saldo_user, int masuk, int keluar, int lantai) {
    try {
        
        if (keluar < masuk) {
            throw logic_error("Jam keluar tidak valid");
        }
        int durasi = keluar - masuk;
        if (durasi <= 0) durasi = 1;
        int biaya = durasi * (lantai == 0 ? 2000 : 5000);
        
        cout << "Total Biaya : Rp " << biaya << endl;
        
        if (*saldo_user < biaya) {
            throw runtime_error("Saldo anda kurang!");
        }
        *saldo_user -= biaya;
        tampil_output("Pembayaran Berhasil");
    }
    catch (const logic_error& e) {
        cout << "\n \033[31m >>  " << e.what() << "\033[0m" << endl;
    }
    catch (const runtime_error& e) {
        cout << "\n \033[31m >>  " << e.what() << "\033[0m" << endl;
    }
}

void read_user(data_parkir denah[2][20]) {
    header_pendek("LIHAT SLOT PARKIR");
    for (int i = 0; i < tingkat; i++) {
        cout << "\n LANTAI " << i + 1 << (i == 0 ? " (MOTOR)" : " (MOBIL)") << endl;
        cout << " ------------------------------------------------" << endl;
        for (int j = 0; j < slot; j++) {
            string status = (denah[i][j].id_member == -2) ? " [R] " : (denah[i][j].terisi ? " [X] " : (denah[i][j].booking ? " [B] " : " [ ] "));
            cout << status;
            if ((j + 1) % 10 == 0) cout << endl;
        }
        cout << " ------------------------------------------------" << endl;
    }   
    cout << " \nKeterangan : " << endl;
    cout << " [X] : Terisi                   [R] : Repair" << endl;
    cout << " [B] : Booking                  [ ] : Kosong" << endl;
    kembali();
}

void read_admin(data_parkir denah[2][20], data_member list[]) {
    header_pjg("LIHAT DATA PARKIR");
    for (int i = 0; i < tingkat; i++) {
        cout << "\nLANTAI " << i + 1 << endl;
        cout << "+------+------------+---------------+------------------------+" << endl;
        cout << "| SLOT |   STATUS   |     PLAT      |         PEMILIK        |" << endl;
        cout << "+------+------------+---------------+------------------------+" << endl;
        bool ada = false;
        for (int j = 0; j < slot; j++) {
            if (denah[i][j].terisi || denah[i][j].booking) {
                string status = (denah[i][j].id_member == -2) ? "PERBAIKAN" : (denah[i][j].terisi ? "TERISI" : "BOOKED");
                string pemilik = (denah[i][j].id_member >= 0) ? list[denah[i][j].id_member].nama : (denah[i][j].id_member == -2 ? "-" : "Umum");
                cout << "| " << left << setw(4) << j + 1 << " | " << setw(10) << status << " | " << setw(13) << denah[i][j].plat << " | " << setw(22) << pemilik << " |" << endl;
                ada = true;
            }
        }
        if (!ada) cout << "|                ( Tidak ada data kendaraan )                |" << endl;
        cout << "+------+------------+---------------+------------------------+" << endl;
    }
    kembali();
}

void tabel_sort(data_member temp[], int n, data_member asli[]) {
    cout << "+------+----------------------+----------------------+" << endl;
    cout << "| ID   | Nama Member          | Saldo                |" << endl;
    cout << "+------+----------------------+----------------------+" << endl;
    
    if (n <= 0) {
        cout << "|        ( Belum ada data member terdaftar )          |" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << "| " << left << setw(4) << temp[i].id 
                << " | " << setw(20) << temp[i].nama 
                << " | Rp " << setw(17) << temp[i].saldo << " |" << endl;
        }
    }
    cout << "+------+----------------------+----------------------+" << endl;
}

void copy(data_member asal[], data_member tujuan[], int n) {
    for(int i=0; i<n; i++) tujuan[i] = asal[i];
}

void bubble_sort_desc(data_member list[], int n) { //urut nama (bubble sort) desc
    data_member temp[10];
    copy(list, temp, n);
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (temp[j].nama < temp[j + 1].nama) {
                data_member swap_var = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap_var;
                swapped = true;
            }
        }
        if (swapped == false)  
        break;
    }
    cout << ">>> URUT NAMA MEMBER <<<" << endl;
    tabel_sort(temp, n, list);
}

void select_sort_asc(data_member list[], int n) { //saldo (selection sort) asc
    data_member temp[10];
    copy(list, temp, n);
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (temp[j].saldo < temp[min_idx].saldo) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            data_member swap_var = temp[min_idx];
            temp[min_idx] = temp[i];
            temp[i] = swap_var;
        }
    }
    cout << ">>> URUT SALDO MEMBER <<<" << endl;
    tabel_sort(temp, n, list);
}

void insert_sort_asc(data_member list[], int n) { //id regis(insertion sort) asc
    for (int i = 1; i < n; i++) {
        data_member key = list[i];
        int j = i - 1;
        while (j >= 0 && list[j].id > key.id) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

void tabel_cari(data_member *list, int indeks) {
    cout << "+------+--------------------------+--------------------------+" << endl;
    cout << "| ID   | Nama Member              | Saldo                    |" << endl;
    cout << "+------+--------------------------+--------------------------+" << endl;

    if(indeks != -1) {
        cout << "| " << left << setw(4) << list[indeks].id 
            << " | " << setw(24) << list[indeks].nama 
            << " | Rp " << setw(21) << list[indeks].saldo << " |" << endl;
    } else {
        cout << "|                  ( Data tidak ditemukan )                  |" << endl;
    }
    
    cout << "+------+--------------------------+--------------------------+" << endl;
}

void linear_nama(data_member *list, int n){ //linear search (nama mem)
    system("cls");
    header_pjg("CARI NAMA MEMBER");
    string target;
    cout << " Masukkan Nama :";
    cin.ignore();
    getline(cin, target);
    int indeks = -1;

    for (int i = 0; i < n; i++){
        if ((list + i)->nama == target) {
            indeks = i;
            break;
        }
    } tabel_cari(list, indeks);
}

void binary_id(data_member *list, int n) { //binary search (id mem)
    system("cls");
    header_pjg("CARI ID MEMBER");
    int target;
    cout  << " Masukkan ID : ";
    if (!(cin >> target)) {
        cin.clear();
        cin.ignore(1000, '\n');
        return;

    } insert_sort_asc(list, n);

    int low = 0;
    int high = n-1;
    int indeks = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if ((list + mid)->id == target) {
            indeks = mid;
            break;
        } if ((list + mid)->id < target) low = mid + 1;
        else high = mid -1;
    } tabel_cari(list, indeks);
}

#endif