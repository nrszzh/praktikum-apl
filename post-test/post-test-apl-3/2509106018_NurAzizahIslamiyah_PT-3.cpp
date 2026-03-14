#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
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
    cout << "\n >> " << output << " : " << nilai << "!" << endl; //overloading (parameternya keluarin nilai)
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
        cout << "| SLOT |   STATUS   |     PLAT      |        PEMILIK         |" << endl;
        cout << "+------+------------+---------------+------------------------+" << endl;
        bool ada = false;
        for (int j = 0; j < slot; j++) {
            if (denah[i][j].terisi || denah[i][j].booking) {
                string status = (denah[i][j].id_member == -2) ? "PERBAIKAN" : (denah[i][j].terisi ? "TERISI" : "BOOKED");
                string pm = (denah[i][j].id_member >= 0) ? list[denah[i][j].id_member].nama : (denah[i][j].id_member == -2 ? "-" : "Umum");
                cout << "| " << left << setw(4) << j + 1 << "| " << setw(10) << status << "| " << setw(13) << denah[i][j].plat << "| " << setw(22) << pm << " |" << endl;
                ada = true;
            }
        }
        if (!ada) cout << "|                ( Tidak ada data kendaraan )                |" << endl;
        cout << "+------+------------+---------------+------------------------+" << endl;
    }
    kembali();
}