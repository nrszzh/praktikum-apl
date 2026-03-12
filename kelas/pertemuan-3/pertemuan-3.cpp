#include <iostream>
using namespace std;

//prosedur gabilikin nilai, ga wajib parameter, void
// fungsi return value, wajib parameter, tipe data

//contoh sebelum main
// int kuadrat(int x) {
//     return x * x;
// }

// void sapa(string nama) {
//     cout << "Halo, " << nama << "!" << endl;
// }

// int main() {
//     sapa("Budi");
//     cout << "Hasil 5 kuadrat: " << kuadrat(5) << endl;
//     return 0;
// }

//setelah main( kerja 2 kali)
// int kuadrat(int x);
// void sapa(string nama);

// int main() {
//     sapa("Andi");
//     cout << "Hasil 3 kuadrat: " << kuadrat(3) << endl;
//     return 0;
// }

// int kuadrat(int x) {
//     return x * x;
// }

// void sapa(string nama) {
//     cout << "Halo, " << nama << "!" << endl;
// }

// void tampilkanStatus(string namaHero, int level, double hp) {
//     cout << " = STATUS HERO =" << endl;
//     cout << "Nama : " << namaHero << endl;
//     cout << "Level : " << level << endl;
//     cout << "Darah : " << hp << "%" << endl;
//     cout << "===================" << endl;

//     cout << endl;
// }

// int main() {
//     // Bagian pengambilan argumen
//     // Kasus 1: Mengirim nilai secara langsung
//     // "Alucard", 15, dan 90.5 adalah argumen.
//     tampilkanStatus("Alucard", 15, 90.5);

//     // Kasus 2: Mengirim menggunakan variabel lain
//     string hero2 = "Miya";
//     int lvl2 = 12;
//     double hp2 = 45.0;

//     // Variabel 'hero2', 'lvl2', dan 'hp2' dikirim sebagai argumen
//     tampilkanStatus(hero2, lvl2, hp2);

//     return 0;
// }


// Pass by Value
// void cobaUbahGaji(int gajiSaya) {
//     gajiSaya = 1000000000; // Gaji di dalam prosedur
//     cout << "Gaji pas di dalam fungsi: " << gajiSaya << endl;
// }

// int main() {
//     int gajiSaya = 5000000; // Gaji di dalam main

//     cout << "Gaji awal: " << gajiSaya << endl;

//     cobaUbahGaji(gajiSaya); // Kirim ke fungsi

//     cout << "Gaji setelah fungsi dipanggil: " << gajiSaya << endl;

//     return 0;
// }

