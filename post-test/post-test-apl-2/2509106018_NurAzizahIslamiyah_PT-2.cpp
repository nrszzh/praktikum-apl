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

}