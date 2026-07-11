#include "warung.h"

// Definisi dan inisialisasi variabel global
string namaMenu[14] = {
    "Mie Pedas Nikmat", "Mie Pedas Sedang", "Mie Pedas Dower",
    "Mie Ayam", "Mie Ayam Bakso", "Tidak Pesan Makanan",
    "Es Teh Lemon", "Es Jeruk Peras", "Susu Murni", "Tidak Pesan Minuman",
    "Udang Keju", "Siomay", "Lumpia Gulung", "Tidak Pesan Snack"
};

int hargaMenu[14] = {
    10000, 15000, 20000,
    10000, 25000, 0,
    8000, 7000, 10000, 0,
    15000, 5000, 5000, 0
};

int pesananID[100];
int jumlahItem = 0;

// Implementasi fungsi
void tampilkanMenu(string kategori, int awal, int akhir) {
    cout << "\n===" << kategori << "===\n";
    for (int i = awal; i <= akhir; i++) {
        cout << (i + 1) << ". " << namaMenu[i] << " - Rp" << hargaMenu[i] << endl;
    }
}

void prosesPemesanan(int awalMenu, int akhirMenu) {
    char tambahLagi;
    do {
        int pilihan;
        cout << "Pilih nomor menu: ";
        cin >> pilihan;
        
        if (pilihan >= (awalMenu + 1) && pilihan <= (akhirMenu + 1)) {
            if (pilihan == (akhirMenu + 1)) {
                cout << "Oke, tidak jadi pesan di kategori ini.\n";
                break;
            }
            pesananID[jumlahItem] = pilihan - 1;
            jumlahItem++;
            cout << "Pesanan ditambahkan!\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
        
        cout << "Apakah Anda ingin menambah lagi? (y/n): ";
        cin >> tambahLagi;
    } while (tambahLagi == 'y' || tambahLagi == 'Y');
}

int hitungTotal() {
    int total = 0;
    for (int i = 0; i < jumlahItem; i++) {
        total += hargaMenu[pesananID[i]];
    }
    return total;
}

void tampilkanStruk(string nama, string catatan, int nomor_meja, char pilihan) {
    cout << "\n===Struk Pembelian===\n";
    cout << "Nama: " << nama << endl;
    
    if (pilihan == 'd' || pilihan == 'D') {
        cout << "Meja: " << nomor_meja << endl;
    } else {
        cout << "Tipe: Takeaway" << endl;
    }
    
    cout << "\nNama Pesanan | Harga\n";
    cout << "------------------------\n";
    for (int i = 0; i < jumlahItem; i++) {
        cout << namaMenu[pesananID[i]] << " | Rp" << hargaMenu[pesananID[i]] << endl;
    }
    cout << "------------------------\n";
    cout << "Total: Rp" << hitungTotal() << endl;
    
    if (!catatan.empty()) {
        cout << "\nCatatan: " << catatan << endl;
    }
    cout << "===================\n";
}
