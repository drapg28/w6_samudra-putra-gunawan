#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struktur Mahasiswa
typedef struct {
    char nama[50];
    int nilaiUTS;
} infotype;

// Struktur Node Linked List
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

// Definisi List sebagai address (pointer ke elemen pertama)
typedef address List;

// *** Fungsi Dasar Linked List ***
// Membuat node baru
void Create_Node(address *p, infotype data);
// Menghapus node
void DeAlokasi(address *p);
// Mengecek apakah list kosong
bool isEmpty(List L);
// Menyisipkan data secara terurut berdasarkan nama
void UrutanNama(List *L, infotype data);
// Mencetak seluruh elemen dalam list
void PrintList(List L);

// *** Operasi Pencarian ***
address Search(List L, infotype X);
bool FSearch(List L, address P);
address SearchPrec(List L, infotype X);

// *** Operasi Penyisipan ***
void InsVFirst(List *L, infotype X);
void InsVLast(List *L, infotype X);
void InsertFirst(List *L, address P);
void InsertAfter(List *L, address P, address Prec);
void InsertLast(List *L, address P);

// *** Operasi Penghapusan ***
void DelVFirst(List *L, infotype *X);
void DelVLast(List *L, infotype *X);
void DelFirst(List *L, address *P);
void DelP(List *L, infotype X);
void DelLast(List *L, address *P);
void DelAfter(List *L, address *Pdel, address Prec);

// *** Fungsi Tambahan ***
void Ascending(List *L, bool byNama);
void Descending(List *L, bool byNama);
int HitungElement(List L);
void CP70(List *dest, List src);
void RemoveDuplikat(List *L);
void DeleteList(List *L);
void TampilkanMenu();
void SubmenuUrutkan(List *L);

#endif