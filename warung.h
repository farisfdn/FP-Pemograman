#ifndef WARUNG_H
#define WARUNG_H

#include <iostream>
#include <string>

using namespace std;

// Deklarasi variabel global
extern string namaMenu[14];
extern int hargaMenu[14];
extern int pesananID[100];
extern int jumlahItem;

// Deklarasi fungsi
void tampilkanMenu(string kategori, int awal, int akhir);
void prosesPemesanan(int awalMenu, int akhirMenu);
int hitungTotal();
void tampilkanStruk(string nama, string catatan, int nomor_meja, char pilihan);

#endif
