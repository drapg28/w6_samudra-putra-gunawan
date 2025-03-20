#include "header.h"

int main() {
    List L = NULL;  // Inisialisasi list kosong
    infotype data;
    int pilihan;
    char cariNama[50];
    address P;

    do {
        TampilkanMenu();
        scanf("%d", &pilihan);
        getchar();  // Menghindari buffer input error

        switch (pilihan) {
            case 1:
                printf("Masukkan Nama: ");
                fgets(data.nama, sizeof(data.nama), stdin);
                data.nama[strcspn(data.nama, "\n")] = 0;  // Hapus newline
                printf("Masukkan Nilai UTS: ");
                scanf("%d", &data.nilaiUTS);
                InsVFirst(&L, data);
                break;

            case 2:
                printf("Masukkan Nama: ");
                fgets(data.nama, sizeof(data.nama), stdin);
                data.nama[strcspn(data.nama, "\n")] = 0;
                printf("Masukkan Nilai UTS: ");
                scanf("%d", &data.nilaiUTS);
                InsVLast(&L, data);
                break;

            case 3:
                if (!isEmpty(L)) {
                    DelVFirst(&L, &data);
                    printf("Data Mahasiswa %s dihapus dari awal.\n", data.nama);
                } else {
                    printf("List kosong!\n");
                }
                break;

            case 4:
                if (!isEmpty(L)) {
                    DelVLast(&L, &data);
                    printf("Data Mahasiswa %s dihapus dari akhir.\n", data.nama);
                } else {
                    printf("List kosong!\n");
                }
                break;

            case 5:
                printf("Masukkan Nama yang Dicari: ");
                fgets(cariNama, sizeof(cariNama), stdin);
                cariNama[strcspn(cariNama, "\n")] = 0;
                data.nilaiUTS = 0;  // Tidak digunakan untuk pencarian nama
                strcpy(data.nama, cariNama);

                P = Search(L, data);
                if (P) {
                    printf("Mahasiswa ditemukan: %s, Nilai UTS: %d\n", P->info.nama, P->info.nilaiUTS);
                } else {
                    printf("Mahasiswa tidak ditemukan.\n");
                }
                break;

            case 6:
                PrintList(L);
                break;

            case 7:
                SubmenuUrutkan(&L);  // Pemanggilan submenu pengurutan
                break;

            case 8:
                DeleteList(&L);
                printf("Semua data dihapus!\n");
                break;

            case 9:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
                break;
        }
    } while (pilihan != 9);

    return 0;
}