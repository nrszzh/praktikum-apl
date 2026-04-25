#ifndef BANTU_H
#define BANTU_H

#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;

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


#endif