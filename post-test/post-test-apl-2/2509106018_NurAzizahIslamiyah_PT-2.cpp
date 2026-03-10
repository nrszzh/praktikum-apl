#include <iostream>
#include <string>
using namespace std;

int tingkat_parkir = 2; 
int slot_pertingkat = 20;
int member = 10;

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

int main() {
    data_parkir denah_parkir[tingkat_parkir][slot_pertingkat];
    data_member list_member[member];
    int jml_member = 0;

    //member (ID 0)
    list_member[0] = {"Nur", "018", 100000, true};
    jml_member = 1;

    int pil_utama;
    int pil_menu;
    string usn_login;
    string pw_login;

    while (true) {
        system("cls");
        cout << "=================================================" << endl;
        cout << "|             SMART PARKING MALL                |" << endl;
        cout << "=================================================" << endl;
        cout << "| 1. | Login                                    |" << endl;
        cout << "| 2. | Registrasi Member                        |" << endl;
        cout << "| 3. | Lihat Slot Parkir                        |" << endl;
        cout << "| 0. | Keluar                                   |" << endl;
        cout << "=================================================" << endl;
        cout << "Pilihan Anda: ";
        cin >> pil_utama;

        if (pil_utama == 0) {
            system("cls");
            cout << "Program Berhenti :)" << endl;
            break;
        }

        if (pil_utama == 1) {
            int percobaan = 0;
            int id = -1;
            bool admin = false;

            while (percobaan < 3) {
                system("cls");
                cout << "=== FORM LOGIN ===" << endl;
                cout << "Username : ";
                if (percobaan == 0) cin.ignore(); 
                getline(cin, usn_login);
                cout << "Password : ";
                cin >> pw_login;

                if (usn_login == "admin" && pw_login == "123") {
                    admin = true;
                    break;
                }

                for (int i = 0; i < jml_member; i++) {
                    if (list_member[i].nama == usn_login && list_member[i].pw == pw_login) {
                        id = i;
                        break;
                    }
                }

                if (id != -1) break; 

                percobaan++;
                if (percobaan < 3) {
                    cout << "\n >> Gagal Login, Coba Lagi";
                    cin.ignore();
                    cin.get(); 
                }
            }

            if (!admin && id == -1) {
                system("cls");
                cout << "Percobaan Login Habis, Program Berhenti." << endl;
                break;
            } 
            

            else if (admin) {
                do {
                    system("cls");
                    cout << "=================================================" << endl;
                    cout << "|                   MENU ADMIN                  |" << endl;
                    cout << "=================================================" << endl;
                    cout << "| 1. | Input Data Parkir                        |" << endl;
                    cout << "| 2. | Lihat Slot Parkir                        |" << endl;
                    cout << "| 3. | Update Data Parkir                       |" << endl;
                    cout << "| 4. | Kosongkan Slot Parkir                    |" << endl;
                    cout << "| 0. | Logout                                   |" << endl;
                    cout << "=================================================" << endl;
                    cout << "Pilihan: ";
                    cin >> pil_menu;

                    if (pil_menu == 1) {
                    system("cls");
                    int jenis;
                    int slot;
                    cout << "Jenis Kendaraan" << endl;
                    cout << "1.Motor" << endl;
                    cout << "2.Mobil" << endl;
                    cout << "Pilihan (1/2) : "; 
                    cin >> jenis;
                    cout << "No Slot (1-20): ";
                    cin >> slot;
                    
                    int idx_lantai = jenis - 1;
                    int idx_slot = slot - 1;

                    if (denah_parkir[idx_lantai][idx_slot].booking) {
                        cout << "Slot ini di-booking oleh: " << list_member[denah_parkir[idx_lantai][idx_slot].id_member].nama << endl;
                        cout << "Input Plat Nomor: ";
                        cin.ignore();
                        getline(cin, denah_parkir[idx_lantai][idx_slot].plat);
                        cout << "Jam Masuk: "; cin >> denah_parkir[idx_lantai][idx_slot].jam_masuk;
                        
                        denah_parkir[idx_lantai][idx_slot].terisi = true;
                        denah_parkir[idx_lantai][idx_slot].booking = false;
                        cout << "\nData Booking Berhasil Diaktifkan!";
                    }

                    else if (!denah_parkir[idx_lantai][idx_slot].terisi) {
                        cout << "Plat Nomor: ";
                        cin.ignore();
                        getline(cin, denah_parkir[idx_lantai][idx_slot].plat);
                        cout << "Jam Masuk: ";
                        cin >> denah_parkir[idx_lantai][idx_slot].jam_masuk;
                        cout << "ID Member (-1 untuk Umum): ";
                        cin >> denah_parkir[idx_lantai][idx_slot].id_member;
                        
                        denah_parkir[idx_lantai][idx_slot].terisi = true;
                        cout << "\nData Parkir Berhasil Diinput!";
                    } 
                    else {
                        cout << "Slot Penuh atau sedang Maintenance!";
                    }
                    cout << "\n<(0) Kembali ";
                    cin >> pil_menu;
                    pil_menu = 1;
                }

                    else if (pil_menu == 2) {
                        system("cls");
                        cout << "=========================================================================" << endl;
                        cout << "| LT\t| SLOT\t| STATUS\t| PLAT\t\t\t| PEMILIK\t|" << endl;
                        cout << "=========================================================================" << endl;
                        for (int i = 0; i < tingkat_parkir; i++) {
                            for (int j = 0; j < slot_pertingkat; j++) {
                                if (denah_parkir[i][j].terisi || denah_parkir[i][j].booking) {
                                    cout << "| " << i + 1 << "\t| " << j + 1 << "\t| ";
                                    cout << (denah_parkir[i][j].id_member == -2 ? "PERBAIKAN" : (denah_parkir[i][j].terisi ? "TERISI" : "BOOKED")) << "\t| ";
                                    cout << denah_parkir[i][j].plat << "\t\t| ";
                                    if (denah_parkir[i][j].id_member >= 0)
                                        cout << list_member[denah_parkir[i][j].id_member].nama << "\t\t|" << endl;
                                    else cout << "Umum\t\t|" << endl;
                                }
                            }
                        }
                        cout << "=========================================================================" << endl;
                        cout << "\n<(0) Kembali "; 
                        cin >> pil_menu;
                        pil_menu = 2;
                    }

                    else if (pil_menu == 3) {
                        system("cls");
                        int pil_update;
                        cout << "=================================================" << endl;
                        cout << "|                UPDATE  PARKIR                 |" << endl;
                        cout << "=================================================" << endl;
                        cout << "| 1. | Ubah Data Parkir                         |" << endl;
                        cout << "| 2. | Update Status Slot                       |" << endl;
                        cout << "| 0. | Kembali                                  |" << endl;
                        cout << "=================================================" << endl;
                        cout << "Pilihan: ";
                        cin >> pil_update;

                        if (pil_update == 1) {
                            system("cls");
                            int lantai;
                            int slot;
                            cout << "=== EDIT DATA PARKIR ===" << endl;
                            cout << "Lantai (1/2)     : ";
                            cin >> lantai;
                            cout << "Nomor Slot (1-20): ";
                            cin >> slot;
                            int idx_lantai = lantai - 1, idx_slot = slot - 1;
                            if (denah_parkir[idx_lantai][idx_slot].terisi) {
                                cout << "\nData Saat Ini: " << denah_parkir[idx_lantai][idx_slot].plat << endl;
                                cout << "Plat Baru       : ";
                                cin.ignore();
                                getline(cin, denah_parkir[idx_lantai][idx_slot].plat);
                                cout << "Jam Masuk Baru  : "; cin >> denah_parkir[idx_lantai][idx_slot].jam_masuk;
                                cout << "\nBerhasil Update Data!";

                            } else cout << "\nBelum ada data parkir";
                            cout << "\n<(0) Kembali "; cin >> pil_menu; pil_menu = 3;

                        } else if (pil_update == 2) {
                            system("cls");
                            int lantai;
                            int slot;
                            int status;
                            cout << "=== UPDATE STATUS MAINTENANCE ===" << endl;
                            cout << "Lantai (1/2)     : ";
                            cin >> lantai;
                            cout << "Nomor Slot (1-20): ";
                            cin >> slot;
                            int idx_lantai = lantai - 1;
                            int idx_slot = slot - 1;
                            cout << "1. Set ke MAINTENANCE" << endl;
                            cout << "2. Set ke NORMAL" << endl;
                            cout << "Pilihan: ";
                            cin >> status;
                            if (status == 1) {
                                denah_parkir[idx_lantai][idx_slot].terisi = true;
                                denah_parkir[idx_lantai][idx_slot].plat = "PERBAIKAN";
                                denah_parkir[idx_lantai][idx_slot].id_member = -2;
                            } else {
                                denah_parkir[idx_lantai][idx_slot].terisi = false;
                                denah_parkir[idx_lantai][idx_slot].plat = "-";
                                denah_parkir[idx_lantai][idx_slot].id_member = -1;
                            }
                            cout << "\nStatus Berhasil Diubah!";
                            cout << "\n<(0) Kembali ";
                            cin >> pil_menu;
                            pil_menu = 3;

                        } else if (pil_update != 0) {
                            cout << "\nPilihan tidak valid!" << endl;
                            cout << "<(0) Kembali ";
                            cin >> pil_menu;
                        }
                    }

                    else if (pil_menu == 4) {
                        system("cls");
                        int lantai, slot;
                        cout << "=== HAPUS PARKIR ===" << endl;
                        cout << "Lantai: ";
                        cin >> lantai;
                        cout << "Slot: ";
                        cin >> slot;
                        denah_parkir[lantai-1][slot-1].terisi = false;
                        denah_parkir[lantai-1][slot-1].plat = "-";
                        denah_parkir[lantai-1][slot-1].id_member = -1;
                        cout << "Slot Dikosongkan";
                        cout << "\n<(0) Kembali ";
                        cin >> pil_menu; 
                        pil_menu = 4;
                    } else if (pil_menu != 0) {
                    system("cls");
                    cout << "Pilihan tidak valid!" << endl;
                    cout << "\n<(0) Kembali ";
                    cin >> pil_menu;
                    pil_menu = -1;
                }
                } while (pil_menu != 0);
            }
        }
    }
}