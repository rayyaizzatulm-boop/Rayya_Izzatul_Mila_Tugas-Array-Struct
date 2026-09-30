#include <iostream>
using namespace std;

int main() {
    string nim[40], nama[40], hadir[40];

    for (int i = 0; i < 40; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        cout << "NIM: ";
        getline(cin, nim[i]);

        cout << "Nama: ";
        getline(cin, nama[i]);

        cout << "Kehadiran: ";
        getline(cin, hadir[i]);
    }

    cout << "\n=== DAFTAR MAHASISWA ===\n";

    for (int i = 0; i < 40; i++) {
        cout << i + 1 << " | "
             << nim[i] << " | "
             << nama[i] << " | "
             << hadir[i] << "%\n";
    }

    cout << "\nTotal Mahasiswa: 40\n";

    string cari;
    cout << "\nMasukkan NIM yang dicari: ";
    getline(cin, cari);

    for (int i = 0; i < 40; i++) {
        if (nim[i] == cari) {
            cout << "Data ditemukan: "
                 << nama[i] << " | "
                 << hadir[i] << "%\n";

            cout << "Kehadiran baru: ";
            getline(cin, hadir[i]);

            cout << "Setelah update: "
                 << nama[i] << " | "
                 << hadir[i] << "%\n";

            break;
        }
    }

    return 0;
}