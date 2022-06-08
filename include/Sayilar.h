#ifndef SAYILAR_H
#define SAYILAR_H

#include "Sayi.h"

struct SAYILAR{
    
    Sayi ilk;
    void(*sayilarYokEt)(struct SAYILAR*);
    void(*sayiEkle)(struct SAYILAR*, const Sayi);
    void(*sayilariYazdir)(struct SAYILAR*);
};

typedef struct SAYILAR* Sayilar;

Sayilar sayilarOlustur();
void sayilarYokEt(const Sayilar);
void sayiEkle(const Sayilar, const Sayi);
void sayilariYazdir(const Sayilar);

#endif