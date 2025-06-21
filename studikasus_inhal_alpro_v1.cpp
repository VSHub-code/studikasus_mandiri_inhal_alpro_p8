#include <iostream>
#include <iomanip>
using namespace std;

const int HARI = 7;
const int BARANG = 4;
string namaBarang[BARANG] = {"Beras", "Gula", "Minyak", "Telur"};

void tampilTabel(int penjualan[BARANG][HARI]) {
    cout << "\nTABEL PENJUALAN (unit per hari):\n";
    cout << setw(10) << "Barang";
    for (int i = 1; i <= HARI; i++)
        cout << setw(8) << "Hari" << i;
    cout << endl;

    for (int i = 0; i < BARANG; i++) {
        cout << setw(10) << namaBarang[i];
        for (int j = 0; j < HARI; j++) {
            cout << setw(8) << penjualan[i][j];
        }
        cout << endl;
    }
}

void tambahData(int penjualan[BARANG][HARI]) {
    cout << "\nTAMBAH DATA PENJUALAN:\n";
    for (int i = 0; i < BARANG; i++) {
        cout << "Masukkan penjualan " << namaBarang[i] << " selama 7 hari:\n";
        for (int j = 0; j < HARI; j++) {
            cout << "Hari " << j + 1 << ": ";
            cin >> penjualan[i][j];
        }
    }
}

void hitungTotal(int penjualan[BARANG][HARI]) {
    cout << "\nTOTAL PENJUALAN PER BARANG:\n";
    for (int i = 0; i < BARANG; i++) {
        int total = 0;
        for (int j = 0; j < HARI; j++) {
            total += penjualan[i][j];
        }
        cout << namaBarang[i] << ": " << total << " unit\n";
    }
}

void tampilTerbanyak(int penjualan[BARANG][HARI]) {
    int total[BARANG] = {0};
    for (int i = 0; i < BARANG; i++)
        for (int j = 0; j < HARI; j++)
            total[i] += penjualan[i][j];

    int maxIndex = 0;
    for (int i = 1; i < BARANG; i++) {
        if (total[i] > total[maxIndex])
            maxIndex = i;
    }

    cout << "\nBARANG DENGAN PENJUALAN TERTINGGI: " << namaBarang[maxIndex]
         << " (" << total[maxIndex] << " unit)\n";
}

int main() {
    int penjualan[BARANG][HARI] = {0};
    int pilihan;

    do {
        cout << "\n=== MENU TOKO KELONTONG ===\n";
        cout << "1. Tampilkan Tabel Penjualan\n";
        cout << "2. Tambah Data Penjualan\n";
        cout << "3. Hitung Total Penjualan per Barang\n";
        cout << "4. Tampilkan Barang Penjualan Tertinggi\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tampilTabel(penjualan); break;
            case 2: tambahData(penjualan); break;
            case 3: hitungTotal(penjualan); break;
            case 4: tampilTerbanyak(penjualan); break;
            case 5: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid.\n"; break;
        }
    } while (pilihan != 5);

    return 0;
}

