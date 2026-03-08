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