#include <iostream>
using namespace std;

string nama = "Nur";
string pw = "018";
string namaInput;
string pwInput;
bool login = false;
char tombol;
int pilihan;
double nilai;

int main() {
    for (int i = 1; i <= 3; i++) {
        system("cls"); //gaada di modul bang tapi saya tau saat apd (python), dan searching untuk di c++ clear nya gimana #izin
        cout << "============================" << endl;
        cout << "           LOGIN            " << endl;
        cout << "============================" << endl;
        cout << "Nama     : ";
        cin >> namaInput;
        cout << "Password : ";
        cin >> pwInput;

        if (namaInput == nama && pwInput == pw) {
            login = true;
            break;
        } else {
            if (i < 3) {
                cout << endl;
                cout << "Login Gagal! coba lagi." << endl;
                cout << ">> (0) Coba Lagi ";
                cin >> tombol;
            }
        }
    }

    if (login == false) {
        system("cls");
        cout << "Percobaan 3 kali habis, program berhenti" << endl;
        return 0;
    }

do {
        system("cls");
        cout << "============================" << endl;
        cout << "       KONVERSI WAKTU     " << endl;
        cout << "============================" << endl;
        cout << "1. Jam   -> Menit dan Detik " << endl;
        cout << "2. Menit -> Jam dan Detik   " << endl;
        cout << "3. Detik -> Jam dan Menit   " << endl;
        cout << "4. Keluar                   " << endl;
        cout << "----------------------------" << endl;
        cout << "Pilihan Anda (1/2/3/4): ";
        cin >> pilihan;

        if (pilihan == 4) break;

        if (pilihan >= 1 && pilihan <= 3) {
            cout << "Masukkan nilai waktu: ";
            cin >> nilai;
            cout << endl;
            switch (pilihan) {
                case 1:
                    cout << nilai << " Jam = " << nilai * 60 << " Menit dan " << nilai * 3600 << " Detik" << endl;
                    break;
                case 2:
                    cout << nilai << " Menit = " << nilai / 60 << " Jam dan " << nilai * 60 << " Detik" << endl;
                    break;
                case 3:
                    cout << nilai << " Detik = " << nilai / 3600 << " Jam dan " << (int)nilai % 3600 / 60 << " Menit" << endl;
                    break;
            }
        } else {
            cout << "Pilihan tidak tersedia!" << endl;
        }
        cout << "<< (0) Kembali ";
        cin >> tombol;
    } while (pilihan != 4);

    system("cls");
    cout << "Program selesai :)" << endl;
    return 0;
}

