#include <stdio.h>
#include <stdlib.h>

#define MAX_BUKU 100
#define MAX_PENGUNJUNG 100

typedef struct {
    char judul[100];
    char pengarang[100];
    char kode[20];
    int tahun_terbit;
    int status;
} Buku;

typedef struct {
    char nama[100];
    Buku buku_pinjam;
} Peminjaman;

Buku buku[MAX_BUKU];
Peminjaman peminjaman[MAX_PENGUNJUNG];
int jumlahBuku = 0;
int jumlahPeminjaman = 0;

const char username[] = "admin";
const char password[] = "12345";
void input_buku();
void lihat_buku();
void data_peminjaman();
void pinjam_buku();
int login_staff();

int main() {
    system("color F0");
    int pilihan;
        printf("\t\t\t\t+------------------------------------------------------------+\n");
        printf("\t\t\t\t|                         WELCOME                            |\n");
        printf("\t\t\t\t|                  PROGRAM PERPUSTAKAAN                      |\n");
        printf("\t\t\t\t|------------------------------------------------------------|\n");
        printf("\t\t\t\t|                       DIBUAT OLEH:                         |\n");
        printf("\t\t\t\t| NAMA  : MICHAEL CHRISTIAN WITANTO                          |\n");
        printf("\t\t\t\t| NIM   : 202402011014                                       |\n");
        printf("\t\t\t\t+------------------------------------------------------------+\n");
        printf("\t\t\t\t Tekan tombol apa saja untuk melanjutkan.....\n");
        getch();
        system("cls");

    while (1) {
        printf("\n");
        printf("\t\t\t\t========================= CW LIBRARY =========================\n\n");
        printf("\t\t\t\t+------------------------------------------------------------+\n");
        printf("\t\t\t\t|                        MENU UTAMA                          |\n");
        printf("\t\t\t\t|                  PROGRAM PERPUSTAKAAN                      |\n");
        printf("\t\t\t\t|------------------------------------------------------------|\n");
        printf("\t\t\t\t| 1. Staff Perpustakaan                                      |\n");
        printf("\t\t\t\t| 2. Pengunjung                                              |\n");
        printf("\t\t\t\t| 3. Exit                                                    |\n");
        printf("\t\t\t\t+------------------------------------------------------------+\n");
        printf("\t\t\t\t Pilih menu: ");
        scanf("%d", &pilihan);
        system("cls");

        if (pilihan == 1) {
            if (login_staff()) {
                int pilihanstaff;
                while (1) {
                    printf("\t\t\t\t+-----------------------------------------------------------+\n");
                    printf("\t\t\t\t|                MENU STAFF PERPUSTAKAAN                    |\n");
                    printf("\t\t\t\t|-----------------------------------------------------------|\n");
                    printf("\t\t\t\t| 1. Input data buku                                        |\n");
                    printf("\t\t\t\t| 2. Lihat data buku                                        |\n");
                    printf("\t\t\t\t| 3. Peminjaman buku                                        |\n");
                    printf("\t\t\t\t| 4. Data peminjaman buku                                   |\n");
                    printf("\t\t\t\t| 5. Kembali ke menu utama                                  |\n");
                    printf("\t\t\t\t+-----------------------------------------------------------+\n");
                    printf("\t\t\t\t Pilih menu: ");
                    scanf("%d", &pilihanstaff);
                    system("cls");

                    if (pilihanstaff == 1) {
                        input_buku();
                    } else if (pilihanstaff == 2) {
                        lihat_buku();
                    } else if (pilihanstaff == 3) {
                        pinjam_buku();
                    } else if (pilihanstaff == 4) {
                        data_peminjaman();
                    } else if (pilihanstaff == 5) {
                        break;
                    } else {
                        printf("Pilihan tidak valid.\n");
                    }
                }
            }
        } else if (pilihan == 2) {
            int pilpengunjung;
            while (1) {
                printf("\t\t\t\t+-----------------------------------------------------------+\n");
                printf("\t\t\t\t|                MENU PENGUNJUNG PERPUSTAKAAN               |\n");
                printf("\t\t\t\t|-----------------------------------------------------------|\n");
                printf("\t\t\t\t| 1. Lihat data buku                                        |\n");
                printf("\t\t\t\t| 2. Data peminjaman buku                                   |\n");
                printf("\t\t\t\t| 3. Kembali ke menu utama                                  |\n");
                printf("\t\t\t\t+-----------------------------------------------------------+\n");
                printf("\t\t\t\t Pilih menu: ");
                scanf("%d", &pilpengunjung);
                system("cls");

                if (pilpengunjung == 1) {
                    lihat_buku();
                } else if (pilpengunjung == 2) {
                    data_peminjaman();
                } else if (pilpengunjung == 3) {
                        break;
                } else {
                    printf("\t\t\t\t Pilihan tidak valid.\n");
                }
            }
        } else if (pilihan == 3) {
            printf("\t\t\t\t Terimakasih telah mengunjungi perpustakaan kami.\n");
            break;
        } else {
            printf("\t\t\t\t Pilihan tidak valid.\n");
        }
    }

    return 0;
}


void input_buku() {
    if (jumlahBuku < MAX_BUKU) {
        printf("\t\t\t\t ------------------------------------------------------------\n");
        printf("\t\t\t\t|                        INPUT BUKU                          |\n");
        printf("\t\t\t\t ------------------------------------------------------------\n");
        printf("\t\t\t\t Masukkan judul buku: ");
        scanf(" %[^\n]", buku[jumlahBuku].judul);
        printf("\t\t\t\t Masukkan pengarang buku: ");
        scanf(" %[^\n]", buku[jumlahBuku].pengarang);
        printf("\t\t\t\t Masukkan tahun terbit buku: ");
        scanf("%d", &buku[jumlahBuku].tahun_terbit);
        printf("\t\t\t\t Masukkan kode buku: ");
        scanf(" %[^\n]", buku[jumlahBuku].kode);
        buku[jumlahBuku].status = 1;
        jumlahBuku++;
        system ("cls");
        printf("\t\t\t\t Buku berhasil ditambahkan.\n\n");
        printf("\t\t\t\t Tekan tombol apa saja untuk balik ke menu.....\n");
        getch();
        system("cls");
    } else {
        printf("\t\t\t\t Data buku penuh!\n\n");
        printf("\t\t\t\t Tekan tombol apa saja untuk balik ke menu.....\n");
        getch();
        system("cls");
    }
}

void lihat_buku() {
    if (jumlahBuku == 0) {
        printf("\t\t\t\t Tidak ada data buku.\n\n");
        printf("\t\t\t\t Tekan tombol apa saja untuk balik ke menu staff.....\n");
        getch();
        system("cls");
    } else {
        printf("\t\t\t\t ------------------------------------------------------------\n");
        printf("\t\t\t\t|                        Daftar Buku                         |\n");
        printf("\t\t\t\t ------------------------------------------------------------\n");
        for (int i = 0; i < jumlahBuku; i++) {
            printf("\t\t\t\t %d. %s - %s (%d)(%s)\n\n", i + 1, buku[i].judul, buku[i].pengarang, buku[i].tahun_terbit, buku[i].kode);
        }
        printf("\t\t\t\t Tekan tombol apa saja untuk balik ke menu.....\n");
        getch();
        system("cls");
    }
}

void data_peminjaman() {
    if (jumlahPeminjaman == 0) {
        printf("\t\t\t\t Tidak ada data peminjaman.\n\n");
        printf("\t\t\t\t Tekan tombol apa saja untuk balik ke menu.....\n");
        getch();
        system("cls");
    } else {
        printf("\t\t\t\t ------------------------------------------------------------\n");
        printf("\t\t\t\t|                     Data Peminjaman Buku                   |\n");
        printf("\t\t\t\t ------------------------------------------------------------\n");
        for (int i = 0; i < jumlahPeminjaman; i++) {
            printf("\t\t\t\t %d. %s meminjam buku: %s\n\n", i+1, peminjaman[i].nama, peminjaman[i].buku_pinjam.judul);
        }
        printf("\t\t\t\t Tekan tombol apa saja untuk balik ke menu.....\n");
        getch();
        system("cls");
    }
}

void pinjam_buku() {
    char nama[100];
    int pilihan, tersedia = 0;
    for (int i = 0; i < jumlahBuku; i++) {
        if (buku[i].status == 1) {
            tersedia = 1;
            break;
        }
    }
    if (!tersedia) {
        printf("\t\t\t\t Semua buku sedang dipinjam atau buku sedang tidak tersedia.\n");
        printf("\t\t\t\t Silakan coba lagi nanti.\n\n");
        printf("\t\t\t\t Tekan tombol apapun untuk kembali ke menu.....");
        getch();
        system("cls");
        return;
    }
    printf("\t\t\t\t ------------------------------------------------------------\n");
    printf("\t\t\t\t|                        Peminjaman Buku                     |\n");
    printf("\t\t\t\t ------------------------------------------------------------\n");
    printf("\t\t\t\t Silahkan isi data diri dan buku yang ingin dipinjam!\n");
    printf("\t\t\t\t Masukkan nama: ");
    scanf(" %[^\n]", nama);
    system("cls");
        printf("\t\t\t\t ------------------------------------------------------------\n");
        printf("\t\t\t\t|                        Daftar Buku                         |\n");
        printf("\t\t\t\t ------------------------------------------------------------\n");
    for (int i=0; i < jumlahBuku; i++){
        if (buku[i].status == 1) {
        printf("\t\t\t\t %d. %s - %s (%d)\n", i+1, buku[i].judul, buku[i].pengarang, buku[i].tahun_terbit);
        }
    }
    printf("\t\t\t\t Pilih buku yang ingin dipinjam (nomor buku): ");
    scanf("%d", &pilihan);
    system("cls");

    if (pilihan >= 1 && pilihan <= jumlahBuku && buku[pilihan - 1].status == 1){
        buku[pilihan-1].status = 0;
        strcpy(peminjaman[jumlahPeminjaman].nama, nama);
        peminjaman[jumlahPeminjaman].buku_pinjam = buku[pilihan - 1];
        jumlahPeminjaman++;
        system("cls");
        printf("\t\t\t\t Buku '%s' berhasil dipinjam oleh %s.\n", buku[pilihan - 1].judul, nama);
        printf("\t\t\t\t Mohon kembalikan buku pada 3 hari setelah peminjaman. Terima kasih!\n\n");
        printf("\t\t\t\t Tekan tombol apa saja untuk balik ke menu.....\n");
        getch();
        system("cls");
    } else {
        printf("\t\t\t\t Pilihan tidak valid.\n");
    }
}

int login_staff() {
    char inputUsername[50];
    char inputPassword[50];

    printf("\t\t\t\t ------------------------------------------------------------\n");
    printf("\t\t\t\t|                      SELAMAT DATANG                        |\n");
    printf("\t\t\t\t ------------------------------------------------------------\n");
    printf("\t\t\t\t Masukkan username: ");
    scanf("%s", inputUsername);
    printf("\t\t\t\t Masukkan password: ");
    scanf("%s", inputPassword);
    system("cls");

    if (strcmp(inputUsername, username) == 0 && strcmp(inputPassword, password) == 0) {
        return 1;
    } else {
        printf("\t\t\t\t Username atau password salah.\n\n");
        printf("\t\t\t\t Tekan tombol apa saja untuk balik ke menu utama.....\n");
        getch();
        system("cls");
        return 0;
    }
}


