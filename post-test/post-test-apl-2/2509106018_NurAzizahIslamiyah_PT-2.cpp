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

    //login member tanpa regis
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
                cout << "Gagal Login, Percobaan habis!" << endl;
                cout << "\n<(0) Kembali: ";
                cin >> pil_menu;
            } 
        }
    }
}