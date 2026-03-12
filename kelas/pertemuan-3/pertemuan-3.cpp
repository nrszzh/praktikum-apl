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

// Pass by Reference (&)
// void tukarsenjata(string &senjata) {
//     senjata = "Sarung Wadimor"; // Langsung ganti isi variabel aslinya
// }

// int main() {
//     string senjatahero = "Kayu Busuk";

//     cout << "Senjata awal: " << senjatahero << endl;

//     tukarsenjata(senjatahero); // Panggil prosedur

//     // Variable dalam main akan ikut terubah
//     cout << "Senjata sekarang: " << senjatahero << endl;

//     return 0;
// }


//Default Value
// 'kadarGula' punya nilai default "Normal"
// Parameter default wajib ditaruh paling kanan!
// void pesankopi(string menu, string kadargula = "Normal") {
//     cout << "Pesanan: " << menu << " | Gula: " << kadargula << endl;
// }

// int main() {
//     // Kasus 1: pengguna mengirim 1 parameter
//     pesankopi("Kopi Susu"); // ga ngisi gula (jdinya nnti otomatis normal)

//     // Kasus 2: pengguna mengirim 2 parameter dan menggantikan
//     // parameter default dari prosedur
//     pesankopi("Americano", "Less Sugar");

//     return 0;
// }


//variabel global (diakses seluruh)
// variabel lokal (diakses dalam fungsi/prosedur itu aja)
//shadowing variabel (nimpa, prioritasin lokal)


//function overloading: nama nya sama tapi tipe dan parameter nya beda
// Fungsi menjumlahkan bilangan bulat
// int tambah(int a, int b) {
//     return a + b;
// }

// // Fungsi 2 menjumlahkan bilangan desimal
// double tambah(double a, double b) {
//     return a + b;
// }

// int main() {
//     cout << "Hasil Int: " << tambah(5, 6) << endl;
//     cout << "Hasil Double: " << tambah(5.5, 6.6) << endl;
//     return 0;
// }


//return: balikin nilai (mtk), hentiin program
//rekursif: if, boros, lambat
//iteratif: loop, hemat, cepat