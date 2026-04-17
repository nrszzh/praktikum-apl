#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


// // Fungsi binary search yang mengembalikan indeks atau -1 jika tidak ditemukan
// int binarySearch(const vector<int>& arr, int target){
//     int low = 0;
//     int high = arr.size() - 1;

//     while(low <= high){
//         int mid = low + (high - low) / 2; // Menghindari potensi integer overflow

//         if(arr[mid] == target){
//             return mid;
//         } else if(arr[mid] < target){
//             low = mid + 1;
//         } else{
//             high = mid - 1;
//         }
//     }
//     return -1;
// }

// int main(){
//     // Data harus dalam keadaan terurut (sorted)
//     vector<int> kumpulanData = {10, 23, 35, 48, 50, 72, 85, 99};
//     int target;

//     cout << "Cari angka dalam array: ";
//     cin >> target;

//     int hasil = binarySearch(kumpulanData, target);

//     if(hasil != -1){
//         cout << "Angka " << target << " ditemukan pada indeks: " << hasil << endl;
//     } else{
//         cout << "Angka " << target << " tidak ada dalam data." << endl;
//     }

//     return 0;
// }

int main(){
    int data[] = {12, 45, 7, 23, 56, 10, 34};
    int n = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen

    int cari;
    bool found = false;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    // Proses Linear Search
    for(int i = 0; i < n; i++){
        if(data[i] == cari){
            cout << "Data ditemukan pada indeks ke-" << i << endl;
            found = true;
            break; // Berhenti jika sudah ketemu
        }
    }

    if(!found){
        cout << "Data tidak ditemukan dalam array." << endl;
    }

    return 0;
}