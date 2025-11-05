#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> antrian;   // Queue untuk menyimpan nama pelanggan
    int pilihan;
    string nama;

    do {
        cout << "\n=== SIMULASI ANTRIAN BELANJA DI KASIR ===" << endl;
        cout << "1. Tambah Pelanggan ke Antrian" << endl;
        cout << "2. Layani Pelanggan" << endl;
        cout << "3. Lihat Antrian Sekarang" << endl;
        cout << "4. Kosongkan Semua Antrian" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // membersihkan buffer

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pelanggan: ";
                getline(cin, nama);
                antrian.push(nama);
                cout << nama << " telah masuk ke dalam antrian belanja." << endl;
                break;

            case 2:
                if (antrian.empty()) {
                    cout << "Tidak ada pelanggan dalam antrian." << endl;
                } else {
                    cout << "Pelanggan " << antrian.front() 
                    << " sedang dilayani di kasir." << endl;
                    antrian.pop();
                }
                break;

            case 3:
                if (antrian.empty()) {
                    cout << "Antrian kosong, tidak ada pelanggan yang menunggu." << endl;
                } else {
                    cout << "Daftar pelanggan dalam antrian: ";
                    {
                        queue<string> temp = antrian;
                        while (!temp.empty()) {
                            cout << temp.front();
                            temp.pop();
                            if (!temp.empty()) cout << ", ";
                        }
                    }
                    cout << endl;
                }
                break;

            case 4:
                if (antrian.empty()) {
                    cout << "Antrian sudah kosong." << endl;
                } else {
                    while (!antrian.empty()) {
                        antrian.pop();
                    }
                    cout << "Semua pelanggan telah dihapus dari antrian." << endl;
                }
                break;

            case 0:
                cout << "Program selesai. Terima kasih telah menggunakan sistem antrian kasir!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);

    return 0;
}
