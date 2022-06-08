#ifndef KISILER_H
#define KISILER_H

#include "Kisi.h"

struct KISILER{
    Kisi ilk;
    void(*listeYokEt)(struct KISILER*);
    void (*kisiEkle)(struct KISILER*, const Kisi);
    void (*kisileriYazdir)(struct KISILER*);
    Kisi (*enZengin)(struct KISILER*);
    void (*kisiCikar)(struct KISILER*, const Kisi);
};

typedef struct KISILER* Kisiler;

Kisiler kisilerOlustur();
void listeYokEt(const Kisiler);
void kisiEkle(const Kisiler, const Kisi);
void kisileriYazdir(const Kisiler);
void kisiCikar(const Kisiler, const Kisi);
Kisi enZengin(const Kisiler);

#endif