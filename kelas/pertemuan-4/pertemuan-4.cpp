#include <iostream>
#include <string>
using namespace std;

// int main(){
//     string rumahUcup = "Ucup";

//     cout << rumahUcup << endl;
//     cout << &rumahUcup << endl;

//     return 0;
// }

struct Address{
    string kota;
    string provinsi;
    string negara;
};

int main(){
    Address address1, address2;
    address1.kota = "Samarinda";
    address1.provinsi = "Kalimantan Timur";
    address1.negara = "Indonesia";

    address2 = address1;
    address2.kota = "IKN";

    cout << address1.kota << endl;
    cout << address2.kota << endl;
    return 0;
}