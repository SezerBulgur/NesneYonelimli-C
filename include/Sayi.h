#ifndef SAYI_H
#define SAYI_H

#include <stdlib.h>
#include <stdio.h>

struct SAYI
{
    int deger;
    struct SAYI* sonraki;

    void(*degerAta)(struct SAYI*,int);
    void(*sayiyiYokEt)(struct SAYI*);
    void(*sayiyiYaz)(struct SAYI*);
};

typedef struct SAYI* Sayi;

Sayi sayiOlustur();
void degerAta(const Sayi,int);
void sayiyiYokEt(const Sayi);
void sayiyiYaz(const Sayi);

#endif