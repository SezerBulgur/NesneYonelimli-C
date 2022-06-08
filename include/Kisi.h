#ifndef KISI_H
#define KISI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct KISI{
    char isim[30];
    double para;
    double oran;
    int sayi;
    struct KISI* sonraki;

    void(*setIsim)(struct KISI*, char*);
    void(*setPara)(struct KISI*, double);
    void(*setOran)(struct KISI*, double);
    void(*setSayi)(struct KISI*, int);
    void(*kisiyiYokEt)(struct KISI*);
    void(*kisiYazdir)(struct KISI*);
};

typedef struct KISI* Kisi;

Kisi kisiOlustur();
void setIsim(const Kisi, char*);
void setPara(const Kisi, double);
void setOran(const Kisi, double);
void setSayi(const Kisi, int);
void kisiyiYokEt(const Kisi);
void kisiYazdir(const Kisi);

#endif