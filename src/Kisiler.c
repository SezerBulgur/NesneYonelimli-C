/**
*
* @author Sezer Bulgur ve sezerbulgur2@gmail.com
* @since 2.05.2022
* <p>
* Kisiler yapısını tanımlar Kisi yapısından olusturulan nesnelerin liste halinde saklanmasını sağlar.
* </p>
*/


#include "Kisiler.h"

Kisiler kisilerOlustur(){
    Kisiler this;
    this = (Kisiler)malloc(sizeof(struct KISILER));
    this->ilk=0;
    this->listeYokEt = &listeYokEt;
    this->kisiEkle = &kisiEkle;
    this->kisileriYazdir = &kisileriYazdir;
    this->enZengin = &enZengin;
    return this;
}

void listeYokEt(const Kisiler this){
    if(this==NULL) return;
    Kisi gec = this->ilk;

    while(gec!=NULL){        
        Kisi sil = gec;
        gec = gec->sonraki;
        sil->kisiyiYokEt(sil);
    }

    free(gec);
    free(this);
}

void kisiEkle(const Kisiler this, const Kisi k1){
    if(this->ilk == NULL){
        this->ilk = k1;
    }
    else{
        Kisi gec = this->ilk;

        while(gec->sonraki != NULL){
            gec = gec->sonraki;
        }

        gec->sonraki = k1;
    }
}

void kisileriYazdir(const Kisiler this){
    if(this==NULL) return;
    if(this->ilk==NULL){
        printf("liste bos\n");
        return;
    }

    Kisi gec = this->ilk;

    while(gec!=NULL){       
        gec->kisiYazdir(gec);
        gec=gec->sonraki;
    }
    
}

Kisi enZengin(const Kisiler this){
    Kisi zengin;
    zengin = this->ilk;
    Kisi gec = this->ilk;
    while (gec!=NULL){
        if(gec->para>zengin->para){
            zengin = gec;
        }
        gec = gec->sonraki;
    }
    return zengin;
}

void kisiCikar(const Kisiler this, const Kisi silinecek){
    if(this->ilk==silinecek){
        this->ilk = this->ilk->sonraki;
        free(silinecek);
        return;
    }

    Kisi gec = this->ilk;

    while(gec!=NULL){
        if(gec->sonraki==silinecek){
            break;
        }
        gec = gec->sonraki;
    }

    if(gec->sonraki->sonraki!=NULL){
        gec->sonraki = gec->sonraki->sonraki;
    }
    free(silinecek);
}