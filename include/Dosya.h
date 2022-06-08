#ifndef DOSYA_H
#define DOSYA_H
#include "Kisiler.h"
#include "Sayilar.h"

/*
struct DOSYA{
    void(*kisileriOku)(struct DOSYA*, Kisiler);
    void(*sayilariOku)(strcut DOSYA*);
};


typedef struct DOSYA* Dosya;
Dosya dosyaOlustur();

void kisileriOku(Dosya, Kisiler);
void sayilariOku(Dosya);
*/

void kisileriOku(Kisiler);
void sayilariOku(Sayilar);


#endif