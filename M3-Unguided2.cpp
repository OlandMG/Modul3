#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// Struktur data untuk produk skincare
struct Produk {
    string nama;
    int harga;
};

// Kelas untuk toko skincare
class TokoSkincare {
private:
    vector<Produk> produk;

public:
    // Method untuk menambahkan data produk
    void tambahData() {
        Produk p;
        cout << "Masukkan Nama Produk: ";
        getline(cin >> ws, p.nama);
        cout << "Masukkan Harga Produk: ";
        cin >> p.harga;
        produk.push_back(p);
        cout << "Data produk berhasil ditambahkan." << endl;
    }

    // Method untuk menghapus data produk
    void hapusData() {
        if (produk.empty()) {
            cout << "Data produk kosong." << endl;
            return;
        }
        produk.pop_back();
        cout << "Data produk terakhir berhasil dihapus." << endl;
    }

    // Method untuk mengupdate data produk
    // Method untuk mengupdate data produk
void updateData() {
    if (produk.empty()) {
        cout << "Data produk kosong." << endl;
        return;
    }
    cout << "Masukkan Nama Produk yang Ingin diupdate: ";
    string namaProduk;
    getline(cin >> ws, namaProduk);
    for (int i = 0; i < produk.size(); ++i) {
        if (produk[i].nama == namaProduk) {
            cout << "Masukkan Nama Baru: ";
            getline(cin >> ws, produk[i].nama);
            cout << "Masukkan Harga Baru: ";
            cin >> produk[i].harga;
            cout << "Data produk berhasil diupdate." << endl;
            return;
        }
    }
    cout << "Data produk tidak ditemukan." << endl;
}


    // Method untuk menambahkan data produk di urutan tertentu
    void tambahDataUrutan() {
        Produk p;
        cout << "Masukkan Nama Produk: ";
        getline(cin >> ws, p.nama);
        cout << "Masukkan Harga Produk: ";
        cin >> p.harga;
        cout << "Masukkan Urutan Tempat Penyisipan Data (indeks): ";
        int posisi;
        cin >> posisi;
        if (posisi >= 0 && posisi <= produk.size()) {
            produk.insert(produk.begin() + posisi, p);
            cout << "Data produk berhasil ditambahkan di urutan tertentu." << endl;
        } else {
            cout << "Posisi tidak valid." << endl;
        }
    }

    // Method untuk menghapus data produk di urutan tertentu
    void hapusDataUrutan() {
        if (produk.empty()) {
            cout << "Data produk kosong." << endl;
            return;
        }
        cout << "Masukkan Urutan Tempat Hapus Data (indeks): ";
        int posisi;
        cin >> posisi;
        if (posisi >= 0 && posisi < produk.size()) {
            produk.erase(produk.begin() + posisi);
            cout << "Data produk pada urutan tertentu berhasil dihapus." << endl;
        } else {
            cout << "Posisi tidak valid." << endl;
        }
    }

    // Method untuk menghapus seluruh data produk
    void hapusSeluruhData() {
        produk.clear();
        cout << "Seluruh data produk berhasil dihapus." << endl;
    }

    // Method untuk menampilkan seluruh data produk
    void tampilkanData() {
        if (produk.empty()) {
            cout << "Data produk kosong." << endl;
            return;
        }
        cout << "Nama Produk\tHarga" << endl;
        for (int i = 0; i < produk.size(); ++i) {
            cout << produk[i].nama << "\t\t" << produk[i].harga << endl;
        }
    }
};

int main() {
    TokoSkincare toko;
    int choice;

    do {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore(); // Membersihkan buffer input sebelumnya

        switch (choice) {
            case 1:
                toko.tambahData();
                break;
            case 2:
                toko.hapusData();
                break;
            case 3:
                toko.updateData();
                break;
            case 4:
                toko.tambahDataUrutan();
                break;
            case 5:
                toko.hapusDataUrutan();
                break;
            case 6:
                toko.hapusSeluruhData();
                break;
            case 7:
                toko.tampilkanData();
                break;
            case 8:
                cout << "Terima kasih telah menggunakan layanan toko skincare Purwokerto. Sampai jumpa lagi!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 8);

    return 0;
}
