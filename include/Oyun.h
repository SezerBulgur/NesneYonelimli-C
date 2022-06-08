#ifndef OYUN_H
#define OYUN_H

#include "Kisiler.h"
#include "Sayilar.h"
#include <Windows.h>
#include <stdio.h>


struct OYUN{
    Kisiler kisiler;
    Sayilar sayilar;
    Sayi sansliSayi;
    int turSayisi;
    double masaBakiye;
    Kisi enZengin;
    void(*oyunuBaslat)(struct OYUN*);
};

typedef struct OYUN* Oyun;

Oyun oyunuHazirla(const Kisiler, const Sayilar);
void oyunuBaslat(const Oyun);

#endif