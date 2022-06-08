/**
*
* @author Sezer Bulgur ve sezerbulgur2@gmail.com
* @since 1.05.2022
* <p>
* Kisi yapısını tanımlar ve gerekli metotları tanımlar.
* </p>
*/

#include "Kisi.h"

Kisi kisiOlustur(){
    Kisi this;
    this = (Kisi)malloc(sizeof(struct KISI));
    this->sonraki = NULL; 
    this->setIsim = &setIsim;
    this->setPara = &setPara;
    this->setOran = &setOran;
    this->setSayi = &setSayi;
    this->kisiyiYokEt = &kisiyiYokEt;
    this->kisiYazdir = &kisiYazdir;
    return this;
}

void setIsim(const Kisi this, char* isim){
    //this->isim = isim;
    strcpy(this->isim,isim);
}

void setPara(const Kisi this, double para){
    this->para = para;
}
void setOran(const Kisi this, double oran){
    this->oran = oran;
}
void setSayi(const Kisi this, int sayi){
    this->sayi = sayi;
}
void kisiyiYokEt(const Kisi this){
    if(this == NULL) return;
    free(this);
}

void kisiYazdir(const Kisi this){
    if(this == NULL) return;
    printf("kisinin ismi: %s\nkisinin parasi: %lf\nkisinin orani: %lf\nkisinin sayisi: %d\n",this->isim, this->para, this->oran, this->sayi);
}