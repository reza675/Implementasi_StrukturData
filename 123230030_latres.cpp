#include <iostream>

using namespace std;

struct siswa {
    string nama;
    int absen;
    siswa *next;
    siswa *prev;
};

siswa *top, *bottom, *depan,*hapus, *belakang, *bantu;

// Stack
void createStack();
bool isEmptyStack();
void push(string nama, int absen);
void pop();
void pop2();
void edit();
void displayStack();

// Queue
bool isEmptyQueue();
void enqueue(string nama, int absen);
void dequeue();
void displayQueue();

int main() {
    createStack();
    int pilih, jumlahSiswa;
    string nama;
    int absen;
    char pil;
    do {
        system("cls");
        cout << "+=========================================+\n";
        cout << "|                MENU UTAMA               |\n";
        cout << "+=========================================+\n";
        cout << "| [1] Input Data                          |\n";
        cout << "| [2] Lihat Data                          |\n";
        cout << "| [3] Hapus Data                          |\n";
        cout << "| [4] Edit Data                           |\n";
        cout << "| [5] Masukan ke dalam antrian            |\n";
        cout << "| [6] Lihat Antrian                       |\n";
        cout << "| [7] Layani Antrian                      |\n";
        cout << "| [8] Keluar                              |\n";
        cout << "+=========================================+\n";
        cout << "Pilih Menu: ";
        cin >> pilih;

        switch (pilih) {
        case 1: {
            system("cls");
            cout << "======================================================================\n";
            cout << "|                               Input Data                           |\n";
            cout << "======================================================================\n\n";
            cout << "Jumlah Siswa: "; cin >> jumlahSiswa;
            for (int i = 0; i < jumlahSiswa; i++) {
                cout << "Siswa- " << i + 1 << endl; 
                cin.ignore();
                cout << "Masukkan Nama\t: "; getline(cin, nama);
                cout << "Masukkan Absen\t: "; cin >> absen;
                push(nama, absen);
            }
            break;
        }
        case 2: {
            system("cls");
            cout << "======================================================================\n";
            cout << "|                               Lihat Data                           |\n";
            cout << "======================================================================\n\n";
            displayStack();
            break;
        }
        case 3: {
            system("cls");
            cout << "======================================================================\n";
            cout << "|                               Hapus Data                           |\n";
            cout << "======================================================================\n\n";
            pop();
            break;
        }
        case 4: {
            system("cls");
            cout << "======================================================================\n";
            cout << "|                                Edit Data                           |\n";
            cout << "======================================================================\n\n";
            edit();
            break;
        }
        case 5: {
            system("cls");
            cout << "======================================================================\n";
            cout << "|                             Masukkan ke Antrian                    |\n";
            cout << "======================================================================\n\n";
            if(isEmptyStack()) {
                cout << "stack kosong\n";
                break;
            }
            cout << "Masukkan ke dalam Antrian\n";
            while (!isEmptyStack()) {
                siswa *temp = top;
                enqueue(temp->nama, temp->absen);
                pop2();
                
               
            }
            cout << "[Semua Data di Stack Dimasukan ke dalam Antrian]\n";
            break;
        }
        case 6: {
            system("cls");

            cout << "======================================================================\n";
            cout << "|                             Lihat Antrian                          |\n";
            cout << "======================================================================\n\n";
            displayQueue();
            break;
        }
        case 7: {
            system("cls");
            cout << "======================================================================\n";
            cout << "|                             Layani Antrian                         |\n";
            cout << "======================================================================\n\n";
            dequeue();
            break;
        }case 8: {
            cout << "+=========================================+\n";
            cout << "|     Program selesai, selamat tinggal    |\n";
            cout << "+=========================================+\n\n";
            exit(0);
        }
        default:
            cout << "\nInput tidak valid.\n\n";
            break;
        }

        cout << "======================================================================" << endl;
        do {
            cout << "\nIngin mencoba menu lain? (y/n) : ";
            cin >> pil;
            if (pil != 'y' && pil != 'Y' && pil != 'n' && pil != 'N') {
                cout << "Input tidak valid.\n";
            }
        } while (pil != 'y' && pil != 'Y' && pil != 'n' && pil != 'N');
        cout << "\nTerima Kasih telah menggunakan program ini\n";

    } while (pil == 'y' || pil == 'Y');

    return 0;
}


void createStack() {
    top = NULL;
    bottom = NULL;
}

bool isEmptyStack() {
    return top == NULL;
}

void push(string nama, int absen) {
    siswa *NB = new siswa ();
    NB->nama = nama;
    NB->absen = absen;
    NB->next = NULL;
    if (isEmptyStack()) {
        top = bottom = NB;
        NB->prev = NULL;
    } else {
        NB->prev = top;
        top->next = NB;
        top = NB;
    }
}

void pop() {
    if (isEmptyStack()) {
        cout << "Stack masih kosong.\n\n";
    } else {
        hapus = top;
        cout << "Data Siswa :\n";
        cout << "Nama : " << hapus->nama << endl;
        cout << "Absen: " << hapus->absen << endl;
        top = top->prev;
        if (top != NULL) {
            top->next = NULL;
        } else {
            bottom = NULL;
        }
        delete hapus;
        cout << "Dihapus dari data\n";
    }
}

void pop2() {
    if (isEmptyStack()) {
        cout << "Stack masih kosong.\n\n";
    } else {
        hapus = top;
        top = top->prev;
        if (top != NULL) {
            top->next = NULL;
        } else {
            bottom = NULL;
        }
        delete hapus;
    }
}




void displayStack() {
    bantu = top;
    if (isEmptyStack()) {
        cout << "Stack masih kosong.\n\n";
    } else {
        cout << "Data Siswa\n";
        while (bantu != NULL) {
            cout << '[' << bantu->nama << ',' << bantu->absen << "]\n";
            bantu = bantu->prev;
        }
    }
}

void edit() {
    bantu = top;
    bool found = false;
    string cari, namaBaru;
    int absenBaru;
    if (isEmptyStack()) {
        cout << "Stack Masih Kosong.\n\n";
    } else {
        cin.ignore();
        cout << "Cari Nama\t: ";
        getline(cin, cari);
        while (bantu != NULL) {
            if (bantu->nama == cari) {
                cout << "Data Ditemukan!\n";
                cout << "Masukkan Nama\t: ";
                getline(cin, namaBaru);
                cout << "Masukkan Absen\t: ";
                cin >> absenBaru;
                bantu->nama = namaBaru;
                bantu->absen = absenBaru;
                cout << "[Data berhasil diupdate]\n";
                found = true;
                break;
            }
            bantu = bantu->prev;
        }
        if (!found) {
            cout << "Nama " << cari << " Tidak Ditemukan!\n\n";
        }
    }
}

bool isEmptyQueue() {
    return depan == NULL;
}

void enqueue(string nama, int absen) {
    siswa *NB = new siswa;
    NB->nama = nama;
    NB->absen = absen;
    NB->next = NULL;
    if (isEmptyQueue()) {
        depan = belakang= NB;
    } else {
        belakang->next = NB;
        belakang= NB;
    }
}

void dequeue() {
    if (isEmptyQueue()) {
        cout << "Antrian kosong.\n";
    } else {
        siswa *temp = depan;
        cout << "Layani Antrian:\n";
        cout << "[" << temp->nama << ", " << temp->absen << "]\n";
        cout << "Dilayani\n";
        depan = depan->next;
        if (depan == NULL) {
            belakang= NULL;
        }
        delete temp;
    }
}

void displayQueue() {
    if (isEmptyQueue()) {
        cout << "Antrian kosong.\n\n";
    } else {
        bantu = depan;
        int i = 1;
        cout << "Lihat Antrian\n";
        while (bantu != NULL) {
            cout << i << ". [" << bantu->nama << ", " << bantu->absen << "]\n";
            bantu = bantu->next;
            i++;
        }
    }
}
