#include <iostream>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float kehadiran;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;

void insertData(string nim, string nama, float kehadiran) {
    Mahasiswa* baru = new Mahasiswa;

    baru->nim = nim;
    baru->nama = nama;
    baru->kehadiran = kehadiran;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Mahasiswa* bantu = head;

        while (bantu->next != NULL) {
            bantu = bantu->next;
        }

        bantu->next = baru;
    }
}

void tampilkan() {
    Mahasiswa* bantu = head;
    int no = 1;

    while (bantu != NULL) {
        cout << no << ". "
             << bantu->nim << " | "
             << bantu->nama << " | "
             << bantu->kehadiran << "%" << endl;

        bantu = bantu->next;
        no++;
    }
}

void searching(string nim) {
    Mahasiswa* bantu = head;

    while (bantu != NULL) {
        if (bantu->nim == nim) {
            cout << "\nData ditemukan!" << endl;
            cout << "NIM       : " << bantu->nim << endl;
            cout << "Nama      : " << bantu->nama << endl;
            cout << "Kehadiran : " << bantu->kehadiran << "%" << endl;
            return;
        }

        bantu = bantu->next;
    }

    cout << "\nData tidak ditemukan." << endl;
}

void deleteData(string nim) {
    Mahasiswa* bantu = head;
    Mahasiswa* sebelum = NULL;

    while (bantu != NULL && bantu->nim != nim) {
        sebelum = bantu;
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Data tidak ditemukan." << endl;
        return;
    }

    if (sebelum == NULL) {
        head = bantu->next;
    } else {
        sebelum->next = bantu->next;
    }

    delete bantu;

    cout << "Data berhasil dihapus." << endl;
}

int main() {

    insertData("103012400196", "ZHAFRAN LINKY SISWARA", 100);
    insertData("103012400278", "GANDA SETYA RAMADHANA", 50);
    insertData("103012400406", "MUHAMMAD ABRAR SINURAT", 100);

    cout << "=== DATA MAHASISWA ===" << endl;
    tampilkan();

    cout << "\n=== SEARCHING ===";
    searching("103012400278");

    cout << "\n=== DELETE ===" << endl;
    deleteData("103012400278");

    cout << "\n=== DATA SETELAH DELETE ===" << endl;
    tampilkan();

    return 0;
}
