#include <iostream>
#include <string>

using namespace std;

#define MAX_SLOT 10
#define MAX_USER 5

struct waktu {
    int jam;
    int menit;
    string zona_wkt;
};

struct tiket {
    string kode_parkir;
    string jenis_kendaraan;
    waktu masuk;
};

struct member {
    string nama;
    string password;
    float saldo;
    float riwayat = 0;
};

struct parkir {
    string plat = "-";
    int id_pengguna = -1; 
    bool terisi = false;
    bool reserved = false;
    bool maintenance = false;
    tiket data_tiket;
};

int main() {
    member regis_member[MAX_USER];
    parkir slot[MAX_SLOT];
    
    int jml_member = 0;
    int pil_awal;
    int pil_menu;
    int update;
    int slot_parkir;
    int jam_keluar;
    int menit_keluar;
    int durasi;
    int biaya;

    //member yg sudah regis 
    regis_member[jml_member].nama = "Nur";
    regis_member[jml_member].password = "018";
    regis_member[jml_member].saldo = 100000;
    jml_member++;

    for(int i = 0; i < MAX_SLOT; i++) {
        slot[i].data_tiket.kode_parkir = "A";
        slot[i].data_tiket.masuk.zona_wkt = "WITA";
    }

        while (true) {
        cout << "\n=====================================" << endl;
        cout << "|        SMART PARKING MALL         |" << endl;
        cout << "=====================================" << endl;
        cout << "|  1. Admin                         |" << endl;
        cout << "|  2. Login Member                  |" << endl;
        cout << "|  3. Registrasi Member             |" << endl;
        cout << "|  4. Cek Slot                      |" << endl;
        cout << "|  5. Keluar                        |" << endl;
        cout << "=====================================" << endl;
        cout << "Pilihan : ";
        cin >> pil_awal;

        if (pil_awal == 5) break;

        if (pil_awal == 1) {
            int coba_admin = 0;
            bool login_admin = false;
            string user_admin, pw_admin;

            while(coba_admin < 3 && !login_admin) {
                cout << "\n[LOGIN ADMIN]";
                cout << "\nUsername : ";
                cin >> user_admin;
                cout << "Password : ";
                cin >> pw_admin;

                if (user_admin == "admin" && pw_admin == "123")
                login_admin = true;
                else {
                    coba_admin++;
                    cout << ">> Login Gagal, Coba lagi!" << endl; }
            }

            if (login_admin) {
                do {
                    cout << "\n=====================================" << endl;
                    cout << "|            MENU  ADMIN            |" << endl;
                    cout << "=====================================" << endl;
                    cout << "|  1. Input Data Parkir             |" << endl;
                    cout << "|  2. Update Data                   |" << endl;
                    cout << "|  3. Lihat Slot Parkir             |" << endl;
                    cout << "|  4. Hapus Data Parkir             |" << endl;
                    cout << "|  5. Kembali                       |" << endl;
                    cout << "=====================================" << endl;
                    cout << "Pilihan : ";
                    cin >> pil_menu;

                    if (pil_menu == 1) {
                        cout << "Nomor Slot (1-10)   : ";
                        cin >> slot_parkir;
                        int idx = slot_parkir - 1;
                        if (!slot[idx].terisi && !slot[idx].maintenance) {
                            cout << "Plat                : ";
                            cin.ignore();
                            getline(cin, slot[idx].plat);

                            cout << "Jenis Kendaraan     : ";
                            getline(cin, slot[idx].data_tiket.jenis_kendaraan);

                            cout << "Jam                 : ";
                            cin >> slot[idx].data_tiket.masuk.jam;

                            cout << "Menit               : ";
                            cin >> slot[idx].data_tiket.masuk.menit;
                            slot[idx].terisi = true;
                            slot[idx].id_pengguna = -1;

                            cout << "Data Parkir Berhasil Diinput!";
                        } else cout << "Gagal Menginput Data";
                        cin.ignore();
                        cin.get();
                    }
                }
            }
        }
    }

}