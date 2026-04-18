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
    int id;
    string nama;
    string pw;
    int saldo = 0;
    bool aktif = false;
};

void tampil_output(string output) {
    cout << "\n >> " << output << endl;
}

void tampil_output(string output, int nilai) {
    cout << "\n >> " << output << " : " << nilai << endl;
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
    cout << "\n >> Input harus berupa angka (Enter)" << endl;
    getch();
} 

void top_up_saldo(data_member *member) { 
    int nominal;
    cout << " Masukkan Nominal: Rp"; 
    while (!(cin >> nominal)) {
        ehr_input();
        system("cls");
        cout << " === TOP UP SALDO ===\n";
        cout << " Masukkan Nominal: Rp";
    }

    if (nominal <= 0) {
        tampil_output("Nominal tidak valid!");
    } else {
        member->saldo += nominal;
        tampil_output("Saldo Berhasil Ditambahkan");
    }
}

void hitung_biaya(int *saldo_user, int masuk, int keluar, int lantai) {
    int durasi = keluar - masuk;
    if (durasi <= 0) durasi = 1;
    int biaya = durasi * (lantai == 0 ? 2000 : 5000);
    
    cout << "Total Biaya : Rp " << biaya << endl;
    
    if (*saldo_user >= biaya) {
        *saldo_user -= biaya;
        tampil_output("Pembayaran Berhasil");
    } else {
        tampil_output("Saldo Kurang!");
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
    data_member temp[10];
    copy(list, temp, n);
    for (int i = 1; i < n; i++) {
        data_member key = temp[i];
        int j = i - 1;
        while (j >= 0 && temp[j].id > key.id) {
            temp[j + 1] = temp[j];
            j--;
        }
        temp[j + 1] = key;
    }
    cout << ">>> URUT ID REGISTRASI <<<" << endl;
    tabel_sort(temp, n, list);
}

void menu_admin(data_parkir denah[2][20], data_member list[], int &jml_member) {
    int pilihan;
    while (true) {
        header_pjg("MENU ADMIN");
        cout << "| 1. | Input Data Parkir                                     |" << endl;
        cout << "| 2. | Lihat Slot Parkir                                     |" << endl;
        cout << "| 3. | Update Slot Parkir                                    |" << endl;
        cout << "| 4. | Kosongkan Slot Parkir                                 |" << endl;
        cout << "| 5. | Sorting Data Member                                   |" << endl;
        cout << "| 6. | Pencarian Data Member                                 |" << endl;
        cout << "| 0. | Logout                                                |" << endl;
        cout << "==============================================================" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilihan)) {
            ehr_input();
            continue;
        }

        if (pilihan == 1) {
            header_pendek("INPUT DATA PARKIR");
            int lantai;
            int slot_parkir;
            cout << "Lantai               : ";
            cin >> lantai;
            cout << "Slot                 : ";
            cin >> slot_parkir;
            data_parkir *dslot = &denah[lantai-1][slot_parkir-1];
            if (dslot->terisi || dslot->booking)
            tampil_output("Slot Tidak Tersedia (Terisi/Booking)");
            else {
                cout << "Plat                 : "; 
                cin.ignore();
                getline(cin, dslot->plat);
                cout << "Jam                  : ";
                cin >> dslot->jam_masuk;
                cout << "ID Member (Umum -1)  : ";
                cin >> dslot->id_member;
                dslot->terisi = true;
                tampil_output("Data Berhasil Diinput");
            }
            kembali();
        }

        else if (pilihan == 2) {
            read_admin(denah, list);
        }

        else if (pilihan == 3) {
            while (true) {
                int pil_update;
                header_pendek("UPDATE SLOT PARKIR");
                cout << "| 1. | Ubah Data Parkir                  |" << endl;
                cout << "| 2. | Ubah Status Slot                  |" << endl;
                cout << "| 0. | Kembali                           |" << endl;
                cout << "==========================================" << endl;
                cout << "Pilihan  : ";
                if (!(cin >> pil_update)) {
                    ehr_input();
                    continue; 
                }

                if (pil_update == 0)
                break;

                if (pil_update == 1) {
                    int lantai;
                    int slot_parkir;
                    cout << "Lantai   : ";
                    cin >> lantai;
                    cout << "Slot     : ";
                    cin >> slot_parkir;
                    data_parkir *ptr_slot = &denah[lantai-1][slot_parkir-1];
                    if (ptr_slot->terisi) {
                        cout << "Plat Baru: ";
                        cin.ignore();
                        getline(cin, ptr_slot->plat);
                        cout << "Jam Baru : ";
                        cin >> ptr_slot->jam_masuk;
                        tampil_output("Data Diperbarui");
                    } else tampil_output("Slot Kosong");
                } 

                else if (pil_update == 2) {
                    int lantai;
                    int slot_parkir;
                    cout << "Lantai   : ";
                    cin >> lantai;
                    cout << "Slot     : ";
                    cin >> slot_parkir;
                    data_parkir *ptr_slot = &denah[lantai-1][slot_parkir-1];
                    int status;
                    cout << "1. Repair | 2. Normal: ";
                    cin >> status;
                    if (status == 1) {
                        ptr_slot->id_member = -2;
                        ptr_slot->terisi = true;
                        ptr_slot->plat = "PERBAIKAN";
                    } else { 
                        ptr_slot->id_member = -1;
                        ptr_slot->terisi = false;
                        ptr_slot->plat = "-";
                    }
                    tampil_output("Status Berhasil Diubah");
                }

                else if (pil_update !=0 ){
                    tampil_output("Pilihan tidak tersedia");
                    getch();
                    break;
                }
                kembali();
            }
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

        } else if (pilihan == 5) {
            int pil_sort;
            while(true) {
                system("cls");
                header_pendek("SORTING DATA MEMBER");
                cout << "| 1. | Urut Nama Member                  |" << endl;
                cout << "| 2. | Urut Saldo Member                 |" << endl;
                cout << "| 3. | Urut ID Registrasi                |" << endl;
                cout << "| 0. | Kembali                           |" << endl;
                cout << "==========================================" << endl;
                cout << "Pilihan  : ";
                if (!(cin >> pil_sort)) {
                    ehr_input(); 
                    continue; }

                if (pil_sort == 0) 
                break;

                if (pil_sort == 1) {
                    system("cls");
                    bubble_sort_desc(list, jml_member);

                } else if (pil_sort == 2) {
                    system("cls");
                    select_sort_asc(list, jml_member);

                } else if (pil_sort == 3) {
                    system("cls");
                    insert_sort_asc(list, jml_member);

                } else {
                    cout << "\n >> Pilihan tidak valid";
                    getch();
                    continue;
                } 
                kembali();
            }

        }else if (pilihan == 6) {
            int pil_cari;
            while(true) {
                header_pendek("PENCARIAN DATA MEMBER");
                cout << "| 1. | Cari Nama                         |" << endl;
                cout << "| 2. | Cari ID                           |" << endl;
                cout << "| 0. | Kembali                           |" << endl;
                cout << "==========================================" << endl;
                cout << "Pilihan : ";
                if (!(cin >> pil_cari)) {
                    ehr_input();
                    continue;
                }

                if (pil_cari == 0)
                break;

                if(pil_cari == 1) {

                } else if (pil_cari ==2) {

                } else {
                    cout << "\n >> Pilihan tidak valid";
                    getch();
                    continue;
                }

            }

        } else if (pilihan == 0) {
            break;

        } else {
            tampil_output("Pilihan tidak tersedia");
            getch();
        }
    }
}

void menu_member(int id, data_member list[], data_parkir denah[2][20]) {
    int pilihan;
    while (true) {
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
        if (!(cin >> pilihan)) {
            ehr_input();
            continue;
        }

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
            tampil_output("Berhasil Booking!", slot_parkir);
            } else tampil_output("Slot Tidak Tersedia");
            kembali();

        } else if (pilihan == 2) {
            header_pendek("BAYAR PARKIR");
            bool ketemu = false;
            for(int i=0; i<tingkat; i++) {
                for(int j=0; j<slot; j++) {
                    if(denah[i][j].id_member == id && denah[i][j].terisi) {
                        int jam_keluar;
                        cout << "Lokasi     : LT " << i+1 << " Slot " << j+1 << endl;
                        cout << "Jam Keluar : ";
                        cin >> jam_keluar;
                        hitung_biaya(&list[id].saldo, denah[i][j].jam_masuk, jam_keluar, i);
                        
                        denah[i][j].terisi = false;
                        denah[i][j].id_member = -1;
                        denah[i][j].plat = "-";
                        ketemu = true;
                        break;
                    }
                }
            }
            if(!ketemu) tampil_output("Tidak ada kendaraan terparkir");
            kembali();

        } else if (pilihan == 3) {
            header_pendek("TOP UP SALDO");
            top_up_saldo(&list[id]);
            kembali();

        } else if (pilihan == 4) {
        read_user(denah);

        } else if (pilihan == 0) {
            break;

        } else {
            tampil_output("Pilihan tidak tersedia");
            getch();
        }
    }
}

int main() {
    data_parkir denah_parkir[2][20];
    data_member list_member[10];
    list_member[0] = {0, "Nur", "018", 100000, true};
    list_member[1] = {1, "Azizah", "111", 50000, true};
    list_member[2] = {2, "Miyah", "222", 75000, true};
    list_member[3] = {3, "Budi", "333", 150000, true};
    list_member[4] = {4, "Udin", "123", 125000, true};
    int jml_member = 5;

    int pilihan;
    while (true) {
        header_pjg("SMART PARKING MALL");
        cout << "| 1. | Login                                                 |" << endl;
        cout << "| 2. | Registrasi                                            |" << endl;
        cout << "| 3. | Lihat Slot Parkir                                     |" << endl;
        cout << "| 0. | Keluar                                                |" << endl;
        cout << "==============================================================" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilihan)) {
            ehr_input();
            continue;
        }

        if (pilihan == 0) {
        system("cls");
        cout << "Program Berhenti :)" << endl;
        break;
        }

        if (pilihan == 1) {
            string usname, pw;
            int percobaan = 0;
            while (percobaan < 3) {
                header_pendek("LOGIN");
                cout << "Username: ";
                cin.ignore();
                getline(cin, usname);
                cout << "Password: ";
                cin >> pw;

                if (usname == "admin" && pw == "123") {
                    menu_admin(denah_parkir, list_member, jml_member);
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
            list_member[jml_member].id = jml_member;
            cout << "Nama     : ";
            cin.ignore();
            getline(cin, list_member[jml_member].nama);
            cout << "Password : ";
            cin >> list_member[jml_member].pw;
            tampil_output("Registrasi Berhasil, ID", jml_member++);
            kembali();

        } else if (pilihan == 3) {
            read_user(denah_parkir);
        }
    }
    return 0;
}