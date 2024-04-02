#include <iostream>
#include <string>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    int usia;
    Node *next;
};

// Deklarasi Linked List
class LinkedList {
private:
    Node *head;

public:
    // Konstruktor
    LinkedList() {
        head = nullptr;
    }

    // Method untuk menambah data di depan
    void insertDepan(string nama, int usia) {
        Node *baru = new Node;
        baru->nama = nama;
        baru->usia = usia;
        baru->next = head;
        head = baru;
    }

    // Method untuk menambah data di belakang
    void insertBelakang(string nama, int usia) {
        Node *baru = new Node;
        baru->nama = nama;
        baru->usia = usia;
        baru->next = nullptr;

        if (head == nullptr) {
            head = baru;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = baru;
        }
    }

    // Method untuk menambah data di tengah
    void insertTengah(string nama, int usia, string posisi) {
        Node *baru = new Node;
        baru->nama = nama;
        baru->usia = usia;

        Node *temp = head;
        while (temp != nullptr && temp->nama != posisi) {
            temp = temp->next;
        }

        if (temp != nullptr) {
            baru->next = temp->next;
            temp->next = baru;
        } else {
            cout << "Data tidak ditemukan." << endl;
        }
    }

    // Method untuk menghapus data
    void hapus(string nama) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        if (head->nama == nama) {
            Node *hapus = head;
            head = head->next;
            delete hapus;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->nama != nama) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            Node *hapus = temp->next;
            temp->next = temp->next->next;
            delete hapus;
        } else {
            cout << "Data tidak ditemukan." << endl;
        }
    }

    // Method untuk mengubah data
    void ubahData(string nama, int usia, string namaBaru, int usiaBaru) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->nama == nama && temp->usia == usia) {
                temp->nama = namaBaru;
                temp->usia = usiaBaru;
                return;
            }
            temp = temp->next;
        }
        cout << "Data tidak ditemukan." << endl;
    }

    // Method untuk menampilkan seluruh data
    void tampilData() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->nama << "\t" << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;

    // Data pertama (nama Anda dan usia Anda)
    string namaAnda;
    int usiaAnda;
    cout << "Masukkan nama Anda: ";
    getline(cin, namaAnda);
    cout << "Masukkan usia Anda: ";
    cin >> usiaAnda;
    cin.ignore(); // Membersihkan buffer input sebelumnya

    // Masukkan data pertama ke dalam linked list
    list.insertDepan(namaAnda, usiaAnda);

    // Data yang dimasukkan sesuai urutan
    list.insertBelakang("John", 19);
    list.insertBelakang("Jane", 20);
    list.insertBelakang("Michael", 18);
    list.insertBelakang("Yusuke", 19);
    list.insertBelakang("Akechi", 20);
    list.insertBelakang("Hoshino", 18);

    // Menampilkan data sebelum operasi
    cout << "Data sebelum operasi: " << endl;
    list.tampilData();
    cout << endl;

    // Hapus data Akechi
    list.hapus("Akechi");

    // Tambahkan data Futaba di antara John dan Jane
    list.insertTengah("Futaba", 18, "John");

    // Tambahkan data Igor di awal
    list.insertDepan("Igor", 20);

    // Ubah data Michael menjadi Reyn
    list.ubahData("Michael", 18, "Reyn", 18);

    // Menampilkan data setelah operasi
    cout << "Data setelah operasi: " << endl;
    list.tampilData();

    return 0;
}