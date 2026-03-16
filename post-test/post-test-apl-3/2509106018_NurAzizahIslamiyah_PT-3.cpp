#include <iostream>
#include <iomanip> //untuk tampilan output (setw)
#include <conio.h> //getch
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
    string nama;
    string pw;
    int saldo = 0;
    bool aktif = false;
};

void tampil_output(string output) {
    cout << "\n >> " << output << "!" << endl;
}

void tampil_output(string output, int nilai) {
    cout << "\n >> " << output << " : " << nilai << "!" << endl; //overloading (parameter yg keluarin nilai)
}

void kembali() {
    cout << "\n<(0) Kembali";
    getch();
}

void rata_tengah(string teks, int lebar) {
    int jarak = (lebar - 2 - teks.length()) / 2;
    cout << "|";
    cout << setw(jarak + teks.length()) << right << teks;
    int sisa = lebar - 2 - jarak - teks.length();
    cout << setw(sisa + 1) << right << "|" << endl;
}

void header_pjg(string judul) {
    system("cls");
    int lebar = 62;
    cout << string(lebar, '=') << endl;
    rata_tengah(judul, lebar);
    cout << string(lebar, '=') << endl;
}

void header_pendek(string judul) {
    system("cls");
    int lebar = 42;
    cout << string(lebar, '=') << endl;
    rata_tengah(judul, lebar);
    cout << string(lebar, '=') << endl;
}

void top_up_saldo(data_member &member) {
    int nominal;
    cout << "Masukkan Nominal: Rp"; 
    cin >> nominal;
    if (nominal <= 0) {
        tampil_output("Nominal tidak valid!");
        top_up_saldo(member); 
    } else {
        member.saldo += nominal;
        tampil_output("Saldo Berhasil Ditambahkan");
    }
}

int hitung_biaya(int masuk, int keluar, int lantai) {
    int durasi = keluar - masuk;
    if (durasi <= 0) durasi = 1;
    return durasi * (lantai == 0 ? 2000 : 5000);
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
    kembali();
}

void read_admin(data_parkir denah[2][20], data_member list[]) {
    header_pjg("LIHAT DATA PARKIR");
    for (int i = 0; i < tingkat; i++) {
        cout << "\nLANTAI " << i + 1 << endl;
        cout << "+------+------------+---------------+------------------------+" << endl;
        cout << "| SLOT |   STATUS   |     PLAT      |         PEMILIK         |" << endl;
        cout << "+------+------------+---------------+------------------------+" << endl;
        bool ada = false;
        for (int j = 0; j < slot; j++) {
            if (denah[i][j].terisi || denah[i][j].booking) {
                string status = (denah[i][j].id_member == -2) ? "PERBAIKAN" : (denah[i][j].terisi ? "TERISI" : "BOOKED");
                string pm = (denah[i][j].id_member >= 0) ? list[denah[i][j].id_member].nama : (denah[i][j].id_member == -2 ? "-" : "Umum");
                cout << " | " << left << setw(4) << j + 1 << " | " << setw(10) << status << " | " << setw(13) << denah[i][j].plat << "| " << setw(22) << pm << " |" << endl;
                ada = true;
            }
        }
        if (!ada) cout << "|                 ( Tidak ada data kendaraan )                 |" << endl;
        cout << "+------+------------+---------------+------------------------+" << endl;
    }
    kembali();
}

void menu_admin(data_parkir denah[2][20], data_member list[]) {
    int pilihan;
    do {
        header_pjg("MENU ADMIN");
        cout << "| 1. | Input Data Parkir                                     |" << endl;
        cout << "| 2. | Lihat Slot Parkir                                     |" << endl;
        cout << "| 3. | Update Slot Parkir                                    |" << endl;
        cout << "| 4. | Kosongkan Slot Parkir                                 |" << endl;
        cout << "| 0. | Logout                                                |" << endl;
        cout << "==============================================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            header_pendek("INPUT DATA PARKIR");
            int lantai;
            int slot_parkir;
            cout << "Lantai               : "; 
            cin >> lantai;
            cout << "Slot                 : "; 
            cin >> slot_parkir;
            data_parkir &idx = denah[lantai-1][slot_parkir-1];
            if (idx.booking) {
                cout << ">> Booking oleh: " << list[idx.id_member].nama << endl;
                idx.booking = false;
            }
            cout << "Plat                 : "; 
            cin.ignore(); getline(cin, idx.plat);
            cout << "Jam                  : "; 
            cin >> idx.jam_masuk;
            if (idx.id_member < 0) { cout << "ID Member (Umum -1)  : ";
                cin >> idx.id_member; }
            idx.terisi = true; 
            tampil_output("Data Berhasil Diinput"); 
            kembali();

        } else if (pilihan == 2){
            read_admin(denah, list);

        } else if (pilihan == 3) {
            header_pendek("UPDATE SLOT PARKIR");
            int pil_update;
            cout << "| 1. | Ubah Data Parkir                      |" << endl;
            cout << "| 2. | Ubah Status (Maintenance)             |" << endl;
            cout << "==============================================" << endl;
            cout << "Pilihan: "; 
            cin >> pil_update;
            int lantai;
            int slot_parkir;
            cout << "Lantai   : "; 
            cin >> lantai;
            cout << "Slot     : "; 
            cin >> slot_parkir;
            data_parkir &idx = denah[lantai-1][slot_parkir-1];
            if (pil_update == 1) {
                if (idx.terisi) {
                    cout << "Plat Baru: "; 
                    cin.ignore();
                    getline(cin, idx.plat);
                    cout << "Jam Baru : ";
                    cin >> idx.jam_masuk;
                    tampil_output("Data Diperbaharui");
                } else tampil_output("Slot Kosong");

            } else {
                int status;
                cout << "1. Repair | 2. Normal: "; 
                cin >> status;
                if (status == 1) { idx.id_member = -2;
                    idx.terisi = true; idx.plat = "PERBAIKAN";
                }
                else { idx.id_member = -1;
                    idx.terisi = false;
                    idx.plat = "-";
                }
                tampil_output("Status Berhasil Diubah");
            }
            kembali();

        } else if (pilihan == 4) {
            header_pendek("KOSONGKAN SLOT");
            int lantai;
            int slot_parkir;
            cout << "Lantai   : ";
            cin >> lantai;
            cout << "Slot     : ";
            cin >> slot_parkir;
            denah[lantai-1][slot_parkir-1].terisi = false;
            denah[lantai-1][slot_parkir-1].plat = "-";
            denah[lantai-1][slot_parkir-1].id_member = -1;
            tampil_output("Slot Berhasil Dikosongkan");
            kembali();

        }
    } while (pilihan != 0);
}

void menu_member(int id, data_member list[], data_parkir denah[2][20]) {
    int pilihan;
    do {
        system("cls");
        cout << "Halo " + list[id].nama;
        cout << "Saldo: Rp " << left << setw(11) << list[id].saldo << endl;
        header_pjg("MENU MEMBER");
        cout << "| 1. | Booking Slot Parkir                                   |" << endl;
        cout << "| 2. | Bayar Parkir                                          |" << endl;
        cout << "| 3. | Top Up Saldo                                          |" << endl;
        cout << "| 4. | Lihat Slot Parkir                                     |" << endl;
        cout << "| 0. | Logout                                                |" << endl;
        cout << "==============================================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            header_pendek("BOOKING SLOT");
            int lantai;
            int slot_parkir;
            cout << "Lantai (1.Motor/2.Mobil) : "; 
            cin >> lantai;
            cout << "Nomor Slot (1-20)        : "; 
            cin >> slot_parkir;
            if (!denah[lantai-1][slot_parkir-1].terisi && !denah[lantai-1][slot_parkir-1].booking) {
                denah[lantai-1][slot_parkir-1].booking = true;
                denah[lantai-1][slot_parkir-1].id_member = id;
                tampil_output("Berhasil Booking", slot_parkir);
            } else tampil_output("Slot Tidak Tersedia");
            kembali();
        }
    }