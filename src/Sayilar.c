/**
*
* @author Sezer Bulgur ve sezerbulgur2@gmail.com
* @since 5.05.2022
* <p>
* Sayilar yapısını tanımlar Sayi yapısından olusturulan nesnelerin liste halinde saklanmasını sağlar.
* </p>
*/

#include "Sayilar.h"

Sayilar sayilarOlustur(){
    Sayilar this;
    this = (Sayilar)malloc(sizeof(struct SAYILAR));
    this->ilk = NULL;
    this->sayiEkle = &sayiEkle;
    this->sayilarYokEt = &sayilarYokEt;
    this->sayilariYazdir = &sayilariYazdir;
    return this;
}

void sayiEkle(const Sayilar this, Sayi s1){
    if(this->ilk==NULL){
        this->ilk=s1;
    }
    else{
        Sayi gec = this->ilk;

        while(gec->sonraki != NULL){
            gec = gec->sonraki;
        }

        gec->sonraki = s1;
    }
}

void sayilarYokEt(const Sayilar this){
    Sayi gec = this->ilk;

    while(gec!=NULL){
        Sayi sil = gec;
        gec = gec->sonraki;
        sil->sayiyiYokEt(sil);
    }

    free(gec);
    free(this);
}

void sayilariYazdir(const Sayilar this){
    if(this->ilk==NULL){
        printf("sayilar listesi bos\n");
    }
    Sayi gec = this->ilk;
    while(gec!=NULL){
        gec->sayiyiYaz(gec);
        gec=gec->sonraki;
    }
}