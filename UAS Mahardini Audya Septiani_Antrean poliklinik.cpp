#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n=== Sistem Antrean Pasien ===" << endl;
    cout << "1. Tambah Pasien" << endl;
    cout << "2. Panggil Pasien" << endl;
    cout << "3. Lihat Daftar Antrean" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    queue<string> antrean;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore(); // Membersihkan input buffer

        switch (pilihan) {
            case 1: {
                string namaPasien;
                cout << "Masukkan nama pasien: ";
                getline(cin, namaPasien);
                antrean.push(namaPasien);
                cout << "Pasien " << namaPasien << " telah ditambahkan ke dalam antrean.\n";
                break;
            }
            case 2: {
                if (antrean.empty()) {
                    cout << "Antrean kosong. Tidak ada pasien untuk dipanggil.\n";
                } else {
                    cout << "Memanggil pasien: " << antrean.front() << "\n";
                    antrean.pop();
                }
                break;
            }
            case 3: {
                if (antrean.empty()) {
                    cout << "Antrean kosong.\n";
                } else {
                    cout << "Daftar antrean pasien: \n";
                    queue<string> tempAntrean = antrean;
                    int nomor = 1;
                    while (!tempAntrean.empty()) {
                        cout << nomor << ". " << tempAntrean.front() << "\n";
                        tempAntrean.pop();
                        nomor++;
                    }
                }
                break;
            }
            case 4: {
                cout << "Keluar dari program. Terima kasih!\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia.\n";
                break;
            }
        }
    } while (pilihan != 4);

    return 0;
}