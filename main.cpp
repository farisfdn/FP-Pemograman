#include <iostream>
#include <string>
#include "warung.h" // Memanggil file header yang sudah kita buat

using namespace std;

int main() {
    string nama;
    char pilihan;
    int nomor_meja = 0;
    
    cout << "===Selamat Datang di Warung Yomie===\n";
    cout << "Pesanan atas nama siapa kak?\n> ";
    getline(cin, nama);

    cout << "Makanannya mau Dine in (d) atau Takeaway (t)? (d/t): ";
    cin >> pilihan;
    
    // Cek validasi pilihan
    if (pilihan != 'd' && pilihan != 'D' && pilihan != 't' && pilihan != 'T') {
        cout << "Maaf, pilihan tidak dikenali. Harap masukkan 'd' atau 't'." << endl;
        return 0;
    }
    
    // Logika jika Dine In
    if (pilihan == 'd' || pilihan == 'D') {
        cout << "Silakan pilih nomor meja (1-50): ";
        cin >> nomor_meja;

        if (nomor_meja >= 1 && nomor_meja <= 50) {
            cout << "Baik kak " << nama << ", silakan duduk di meja nomor " << nomor_meja << "." << endl;
        } else {
            cout << "Mohon maaf, nomor meja tersebut tidak tersedia." << endl;
            return 0;
        }
    }
    
    // === BAGIAN PEMESANAN MENU ===
    tampilkanMenu("Mie Pedas 3 Level & Mie Tidak Pedas", 0, 5);
    prosesPemesanan(0, 5);
    
    tampilkanMenu("Minuman", 6, 9);
    prosesPemesanan(6, 9);
    
    tampilkanMenu("Snack", 10, 13);
    prosesPemesanan(10, 13);
    
    // Catatan khusus
    char adaCatatan;
    string catatan = "";
    cout << "\nApakah Anda memerlukan sesuatu? Silakan catat di bawah ini (y/n): ";
    cin >> adaCatatan;
    cin.ignore(); // Penting: membersihkan buffer sebelum menggunakan getline berikutnya
    
    if (adaCatatan == 'y' || adaCatatan == 'Y') {
        cout << "Masukkan catatan: ";
        getline(cin, catatan);
    }
    
    // Menampilkan struk pesanan
    tampilkanStruk(nama, catatan, nomor_meja, pilihan);
    
    // Konfirmasi akhir
    char konfirmasi;
    cout << "\nApakah Anda ingin memproses pesanan ini? (y/n): ";
    cin >> konfirmasi;
    
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        cout << "\nTerima kasih! Pesanan akan kami proses, mohon ditunggu.\n";
    } else {
        cout << "\nPesanan dibatalkan. Terima kasih sudah berkunjung!\n";
    }
    
    return 0;
}
