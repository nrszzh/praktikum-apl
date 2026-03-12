#include <iostream>
using namespace std;

//prosedur gabilikin nilai, ga wajib parameter, void
// fungsi return value, wajib parameter, tipe data

//contoh sebelum main
int kuadrat(int x) {
    return x * x;
}

void sapa(string nama) {
    cout << "Halo, " << nama << "!" << endl;
}

int main() {
    sapa("Budi");
    cout << "Hasil 5 kuadrat: " << kuadrat(5) << endl;
    return 0;
}

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


