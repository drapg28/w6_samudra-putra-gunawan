#include "header.h"

int main() {
    List L1 = NULL, L2 = NULL;
    infotype data;
    int pilihan;

    do {
        TampilkanMenu();
        scanf("%d", &pilihan);
        getchar();  

        switch (pilihan) {
            case 1:
                printf("Masukan Nama: ");
                fgets(data.nama, sizeof(data.nama), stdin);
                data.nama[strcspn(data.nama, "\n")] = 0;
                
                printf("Masukan Nilai UTS: ");
                scanf("%d", &data.nilaiUTS);
                
                UrutanNama(&L1, data);
                printf("Data berhasil ditambahkan.\n");
                break;

            case 2:
            if (L1 == NULL) {
                printf("Daftar kosong!\n");
            } else{ 
                printf("Jumlah Mahasiswa: %d\n", HitungElement(L1));
            }
                break;

            case 3:
            if (L1 == NULL) {
                printf("Daftar kosong!\n");
            } else {
                SubmenuUrutkan(&L1);
            }
                break;

            case 4:
                CP70(&L2, L1);
                printf("Data dengan Nilai > 70 telah disalin.\n");
                break;

            case 5:
                if (L2 == NULL) {
                    printf("Data tidak ada!\n");
                } else {
                    printf("\n=== Data tersaalin ===\n");
                    PrintList(L2);
                }
                break;

            case 6:
                RemoveDuplikat(&L2);
                printf("Data duplikat terhapus.\n");
                break;

            case 7: {
                char konfirmasi;
                printf("apakah anda ingin menghapus semua data? (y/n): ");
                scanf(" %c", &konfirmasi);
                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    DeleteList(&L1);
                    DeleteList(&L2);
                    printf("Semua data telah dihapus.\n");
                } else {
                    printf("Penghapusan dibatalkan.\n");
                }
                break;
            }

            case 0:
                printf("Keluar dari program.\n");
                DeleteList(&L1);
                DeleteList(&L2);
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}
