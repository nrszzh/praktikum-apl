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
    cout << "\n >> " << output << endl;
}

void tampil_output(string output, int nilai) {
    cout << "\n >> " << output << " : " << nilai << endl; //overloading (parameter yg keluarin nilai)
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

void ehr_input() {
    cin.clear(); 
    cin.ignore(1000, '\n');
    cout << "\n >> Input harus berupa angka" << endl;
    cout << " >> Coba Lagi";
    getch();
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
        if (!ada) cout << "|                ( Tidak ada data kendaraan )                 |" << endl;
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
            data_parkir &dslot = denah[lantai-1][slot_parkir-1];

            if (dslot.terisi || dslot.booking) {
                tampil_output("Slot Tidak Tersedia (Terisi/Booking)");
            } 
            else {
                cout << "Plat                 : "; 
                cin.ignore();
                getline(cin, dslot.plat);
                cout << "Jam                  : ";
                cin >> dslot.jam_masuk;
                cout << "ID Member (Umum -1)  : ";
                cin >> dslot.id_member;
                dslot.terisi = true; 
                tampil_output("Data Berhasil Diinput"); 
            }
            kembali();
        }

        else if (pilihan == 2) {
            read_admin(denah, list);
        }

        else if (pilihan == 3) {
            header_pendek("UPDATE SLOT PARKIR");
            int pil_update;
            cout << "| 1. | Ubah Data Parkir                  |" << endl;
            cout << "| 2. | Ubah Status Slot                  |" << endl;
            cout << "| 0. | Kembali                           |" << endl;
            cout << "==========================================" << endl;
            cout << "Pilihan: ";
            cin >> pil_update;

            if (pil_update == 0) {
                continue; 
            }

            int lantai;
            int slot_parkir;
            cout << "Lantai   : ";
            cin >> lantai;
            cout << "Slot     : ";
            cin >> slot_parkir;
            data_parkir &dslot = denah[lantai-1][slot_parkir-1];

            if (pil_update == 1) {
                if (dslot.terisi) {
                    cout << "Plat Baru: ";
                    cin.ignore();
                    getline(cin, dslot.plat);
                    cout << "Jam Baru : ";
                    cin >> dslot.jam_masuk;
                    tampil_output("Data Diperbaharui");
                } else tampil_output("Slot Kosong");

            } else {
                int status;
                cout << "1. Repair | 2. Normal: ";
                cin >> status;
                if (status == 1) { 
                    dslot.id_member = -2;
                    dslot.terisi = true;
                    dslot.plat = "PERBAIKAN";
                } else { 
                    dslot.id_member = -1;
                    dslot.terisi = false;
                    dslot.plat = "-";
                }
                tampil_output("Status Berhasil Diubah");
            }
            kembali();
        }

        else if (pilihan == 4) {
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
        header_pjg("MENU MEMBER");
        cout << "| Halo! " << left << setw(15) << list[id].nama << right << setw(16);
        cout << "| Saldo: Rp " << left << setw(22) << list[id].saldo << "|" << endl;
        cout << string(62, '-') << endl;
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
            cout << "Lantai (1.Mtr/2.Mbl) : "; 
            cin >> lantai;
            cout << "Nomor Slot (1-20)    : "; 
            cin >> slot_parkir;
            if (!denah[lantai-1][slot_parkir-1].terisi && !denah[lantai-1][slot_parkir-1].booking) {
                denah[lantai-1][slot_parkir-1].booking = true;
                denah[lantai-1][slot_parkir-1].id_member = id;
                tampil_output("Berhasil Booking", slot_parkir);
            } else tampil_output("Slot Tidak Tersedia");
            kembali();

        } else if (pilihan == 2) {
            header_pendek("BAYAR PARKIR");
            bool ketemu = false;
            for(int i=0; i<tingkat; i++) {
                for(int j=0; j<slot; j++) {
                    if(denah[i][j].id_member == id && denah[i][j].terisi) {
                        int jam_keluar;
                        cout << "Lokasi    : LT " << i+1 << " Slot " << j+1 << endl;
                        cout << "Jam Keluar: ";
                        cin >> jam_keluar;
                        int biaya = hitung_biaya(denah[i][j].jam_masuk, jam_keluar, i);
                        if(list[id].saldo >= biaya) {
                            list[id].saldo -= biaya;
                            denah[i][j].terisi = false; denah[i][j].id_member = -1; denah[i][j].plat = "-";
                            tampil_output("Bayar Berhasil, Sisa Saldo", list[id].saldo);
                        } else tampil_output("Saldo Kurang");
                        ketemu = true;
                        break;
                    }
                }
            }
            if(!ketemu) tampil_output("Tidak Ada Kendaraan Terparkir");
            kembali();

        } else if (pilihan == 3) {
            header_pendek("TOP UP SALDO");
            top_up_saldo(list[id]);
            kembali();
        } else if (pilihan == 4)
        read_user(denah);
    } while (pilihan != 0);
}

int main() {
    data_parkir denah_parkir[2][20];
    data_member list_member[10];
    int jml_member = 1;
    list_member[0] = {"Nur", "018", 100000, true};

    int pilihan;
    while (true) {
        header_pjg("SMART PARKING MALL");
        cout << "| 1. | Login                                                 |" << endl;
        cout << "| 2. | Registrasi                                            |" << endl;
        cout << "| 3. | Lihat Slot Parkir                                     |" << endl;
        cout << "| 0. | Keluar                                                |" << endl;
        cout << "==============================================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 0) {
        system("cls");
        cout << "Program Berhenti :)" << endl;
        break;
        }

        if (pilihan == 1) {
            int percobaan = 0;
            while (percobaan < 3) {
                header_pendek("LOGIN");
                string usname, pw;
                cout << "Username: ";
                cin.ignore();
                getline(cin, usname);
                cout << "Password: ";
                cin >> pw;

                if (usname == "admin" && pw == "123") {
                    menu_admin(denah_parkir, list_member);
                    break;
                } else {
                    int id = -1;
                    for(int i=0; i<jml_member; i++) {
                        if(list_member[i].nama == usname && list_member[i].pw == pw)
                        id = i;
                    }
                    if (id != -1) {
                        menu_member(id, list_member, denah_parkir);
                        break;
                    } else {
                        percobaan++;
                        if (percobaan < 3) {
                            tampil_output("Login Gagal! Sisa Percobaan", 3 - percobaan);
                            getch();
                        } else {
                            tampil_output("Percobaan Habis, Program Berhenti.");
                            return 0;
                        }
                    }
                }
            }

        } else if (pilihan == 2) {
            header_pendek("REGISTRASI");
            cout << "Nama     : ";
            cin.ignore();
            getline(cin, list_member[jml_member].nama);
            cout << "Password : ";
            cin >> list_member[jml_member].pw;
            tampil_output("Registrasi Berhasil, ID", jml_member++);
            kembali();

        } else if (pilihan == 3)
        read_user(denah_parkir);
    }
    return 0;
}