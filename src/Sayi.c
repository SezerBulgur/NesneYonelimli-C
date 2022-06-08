/**
*
* @author Sezer Bulgur ve sezerbulgur2@gmail.com
* @since 5.05.2022
* <p>
* Sayi yapısını tanımlar ve gerekli metotları tanımlar.
* </p>
*/

#include "Sayi.h"

Sayi sayiOlustur(){
    Sayi this;
    this = (Sayi)malloc(sizeof(struct SAYI));
    this->sonraki = NULL;
    this->degerAta = &degerAta;
    this->sayiyiYokEt = &sayiyiYokEt;
    this->sayiyiYaz = &sayiyiYaz;
    return this;
}

void degerAta(const Sayi this, int deger){
    this->deger = deger;
}

void sayiyiYokEt(const Sayi this){
    if(this==NULL) return;
    free(this);
}

void sayiyiYaz(const Sayi this){
    printf("sayinin degeri: %d\n", this->deger);
}
