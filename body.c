#include "header.h"

// Membuat node baru
void Create_Node(address *p, infotype data) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        (*p)->info = data;
        (*p)->next = NULL;
    }
}

// Menghapus node
void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}

// Mengecek apakah list kosong
bool isEmpty(List L) {
    return L == NULL;
}

// Menyisipkan data secara terurut berdasarkan nama
void UrutanNama(List *L, infotype data) {
    address P, Prec = NULL, Q = *L;
    Create_Node(&P, data);
    if (P == NULL) return;

    while (Q != NULL && strcmp(Q->info.nama, data.nama) < 0) {
        Prec = Q;
        Q = Q->next;
    }

    if (Prec == NULL) {
        P->next = *L;
        *L = P;
    } else {
        P->next = Q;
        Prec->next = P;
    }
}

// Mencetak seluruh elemen dalam list
void PrintList(List L) {
    address P = L;
    while (P != NULL) {
        printf("Nama: %s, Nilai UTS: %d\n", P->info.nama, P->info.nilaiUTS);
        P = P->next;
    }
}

// *** OPERASI PENYISIPAN ***
void InsVFirst(List *L, infotype X) {
    address P;
    Create_Node(&P, X);
    if (P != NULL) {
        P->next = *L;
        *L = P;
    }
}

void InsVLast(List *L, infotype X) {
    address P, Last;
    Create_Node(&P, X);
    if (P != NULL) {
        if (isEmpty(*L)) {
            *L = P;
        } else {
            Last = *L;
            while (Last->next != NULL) {
                Last = Last->next;
            }
            Last->next = P;
        }
    }
}

void InsertFirst(List *L, address P) {
    P->next = *L;
    *L = P;
}

void InsertAfter(List *L, address P, address Prec) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void InsertLast(List *L, address P) {
    address Last;
    if (isEmpty(*L)) {
        *L = P;
    } else {
        Last = *L;
        while (Last->next != NULL) {
            Last = Last->next;
        }
        Last->next = P;
    }
}

// *** OPERASI PENGHAPUSAN ***
void DelVFirst(List *L, infotype *X) {
    address P;
    if (!isEmpty(*L)) {
        P = *L;
        *X = P->info;
        *L = P->next;
        DeAlokasi(&P);
    }
}

void DelVLast(List *L, infotype *X) {
    address P, Prec = NULL;
    if (!isEmpty(*L)) {
        P = *L;
        while (P->next != NULL) {
            Prec = P;
            P = P->next;
        }
        *X = P->info;
        if (Prec == NULL) {
            *L = NULL;
        } else {
            Prec->next = NULL;
        }
        DeAlokasi(&P);
    }
}

void DelFirst(List *L, address *P) {
    if (!isEmpty(*L)) {
        *P = *L;
        *L = (*P)->next;
        DeAlokasi(P);
    }
}

void DelLast(List *L, address *P) {
    address Prec = NULL;
    if (!isEmpty(*L)) {
        *P = *L;
        while ((*P)->next != NULL) {
            Prec = *P;
            *P = (*P)->next;
        }
        if (Prec == NULL) {
            *L = NULL;
        } else {
            Prec->next = NULL;
        }
        DeAlokasi(P);
    }
}

void DelP(List *L, infotype X) {
    address P = *L, Prec = NULL;
    while (P != NULL && strcmp(P->info.nama, X.nama) != 0) {
        Prec = P;
        P = P->next;
    }
    if (P != NULL) {
        if (Prec == NULL) {
            *L = P->next;
        } else {
            Prec->next = P->next;
        }
        DeAlokasi(&P);
    }
}

// *** OPERASI PENCARIAN ***
address Search(List L, infotype X) {
    address P = L;
    while (P != NULL && strcmp(P->info.nama, X.nama) != 0) {
        P = P->next;
    }
    return P;
}

// Mengurutkan List secara Ascending berdasarkan nama atau nilai
void Ascending(List *L, bool byNama) {
    if (isEmpty(*L) || (*L)->next == NULL) return;

    List i, j;
    infotype temp;
    for (i = *L; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if ((byNama && strcmp(i->info.nama, j->info.nama) > 0) || 
                (!byNama && i->info.nilaiUTS > j->info.nilaiUTS)) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

// Mengurutkan List secara Descending berdasarkan nama atau nilai
void Descending(List *L, bool byNama) {
    if (isEmpty(*L) || (*L)->next == NULL) return;

    List i, j;
    infotype temp;
    for (i = *L; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if ((byNama && strcmp(i->info.nama, j->info.nama) < 0) || 
                (!byNama && i->info.nilaiUTS < j->info.nilaiUTS)) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

// Menghitung jumlah elemen dalam list
int HitungElement(List L) {
    int count = 0;
    while (L != NULL) {
        count++;
        L = L->next;
    }
    return count;
}

// Menyalin data mahasiswa dengan nilai >= 70 ke list baru
void CP70(List *dest, List src) {
    infotype data;
    while (src != NULL) {
        if (src->info.nilaiUTS >= 70) {
            data = src->info;
            InsVLast(dest, data);
        }
        src = src->next;
    }
}

// Menghapus elemen dengan data duplikat
void RemoveDuplikat(List *L) {
    if (isEmpty(*L) || (*L)->next == NULL) return;

    List current = *L, temp, prev;
    while (current != NULL && current->next != NULL) {
        prev = current;
        temp = current->next;
        while (temp != NULL) {
            if (strcmp(current->info.nama, temp->info.nama) == 0) {
                prev->next = temp->next;
                DeAlokasi(&temp);
            } else {
                prev = temp;
            }
            temp = prev->next;
        }
        current = current->next;
    }
}

// Menghapus seluruh list
void DeleteList(List *L) {
    address P;
    while (!isEmpty(*L)) {
        P = *L;
        *L = P->next;
        DeAlokasi(&P);
    }
}

// Menampilkan menu
void TampilkanMenu() {
    printf("\n===== MENU Manejemen Mahasiswa =====\n");
    printf("1. Tambah Data\n");
    printf("2. Lihat Jumlah Mahasiswa\n");
    printf("3. Sorting mahasiswa\n");
    printf("4. Menyalin nilai diatas 70\n");
    printf("5. Lihat Data yang Disalin\n");
    printf("6. Hapus Duplikat\n");
    printf("7. Hapus Semua Data\n");
    printf("0. Keluar\n");
    printf("Pilihan: ");
}

// Menampilkan submenu untuk pengurutan
void SubmenuUrutkan(List *L) {
    int pilihan;
    bool byNama;
    printf("\n===== PILIHAN PENGURUTAN =====\n");
    printf("1. Ascending berdasarkan Nama\n");
    printf("2. Descending berdasarkan Nama\n");
    printf("3. Ascending berdasarkan Nilai UTS\n");
    printf("4. Descending berdasarkan Nilai UTS\n");
    printf("Pilihan Anda: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            byNama = true;
            Ascending(L, byNama);
            break;
        case 2:
            byNama = true;
            Descending(L, byNama);
            break;
        case 3:
            byNama = false;
            Ascending(L, byNama);
            break;
        case 4:
            byNama = false;
            Descending(L, byNama);
            break;
        default:
            printf("Pilihan tidak valid!\n");
            return;
    }

    printf("List telah diurutkan!\n");
    PrintList(*L);
}