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

// int main(){
//     int data[] = {12, 45, 7, 23, 56, 10, 34};
//     int n = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen

//     int cari;
//     bool found = false;

//     cout << "Masukkan angka yang ingin dicari: ";
//     cin >> cari;

//     // Proses Linear Search
//     for(int i = 0; i < n; i++){
//         if(data[i] == cari){
//             cout << "Data ditemukan pada indeks ke-" << i << endl;
//             found = true;
//             break; // Berhenti jika sudah ketemu
//         }
//     }

//     if(!found){
//         cout << "Data tidak ditemukan dalam array." << endl;
//     }

//     return 0;
// }

int jumpSearch(int arr[], int x, int n){
    // Menentukan ukuran blok lompatan
    int step = sqrt(n);
    int prev = 0;

    // Melompat ke depan selama elemen di indeks lompatan kurang dari target
    while(arr[min(step, n) - 1] < x){
        prev = step;
        step += sqrt(n);
        if(prev >= n) return -1; // Jika sudah di ujung tapi belum ketemu
    }

    // Melakukan Linear Search di dalam blok yang sudah ditemukan
    while(arr[prev] < x){
        prev++;
        // Jika sampai ke blok berikutnya atau ujung array, berarti tidak ada
        if(prev >= min(step, n)) return -1;
    }

    // Jika elemen ditemukan
    if(arr[prev] == x) return prev;

    return -1;
}

int main(){
    int data[] = {2, 5, 8, 12, 19, 22, 26, 29, 35, 40};
    int n = sizeof(data) / sizeof(data[0]);
    int cari = 26;

    int hasil = jumpSearch(data, cari, n);

    if(hasil != -1){
        cout << "Data ditemukan pada indeks ke-" << hasil << endl;
    } else{
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}