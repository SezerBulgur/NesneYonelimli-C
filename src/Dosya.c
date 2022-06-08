/**
*
* @author Sezer Bulgur ve sezerbulgur2@gmail.com
* @since 3.05.2022
* <p>
* Dosyadan okuma işlemlerini yapmak için gerekli metotları tanımlar.
* </p>
*/

#include "Dosya.h"

/*
Dosya dosyaOlustur(){
    Dosya this;
    this->kisileriOku=&kisileriOku;
    this->sayilariOku=&sayilariOku;
}
*/

void kisileriOku(Kisiler kisiler){

    FILE* dosya;
    dosya = fopen("Kisiler.txt", "r");
    if(dosya==NULL){
        printf("dosya acilamadi\n");
        return;
    }

    char* token;
    const char ayrac[2] = "#";

    char* line = NULL;
    size_t len = 0;
    int read;


    while((read = getline(&line, &len, dosya)) != -1){ 
        //özelliklerin atacagı kisi nesnesi olusturuldu
        Kisi kisi = kisiOlustur();
        char* isim;
        char* strPara;
        char* strOran;
        char* strSayi;
        double para;
        double oran;
        int sayi;

        //isim atandi
        token = strtok(line, ayrac);
        isim = token;
        kisi->setIsim(kisi, isim);
        
        //para atandi
        token = strtok(NULL, ayrac);
        strPara = token;
        sscanf(strPara,"%lf",&para);
        kisi->setPara(kisi, para);

        //oran atandi
        token = strtok(NULL, ayrac);
        strOran = token;
        sscanf(strOran,"%lf",&oran);
        kisi->setOran(kisi, oran);

        //ugurlu sayi atandi
        token = strtok(NULL, ayrac);
        strSayi = token;
        sscanf(strSayi,"%d",&sayi);
        kisi->setSayi(kisi, sayi);


        //olusturulan kisi kisiler listesine eklendi
        kisiler->kisiEkle(kisiler, kisi);
        
    }
}

void sayilariOku(Sayilar sayilar){
    FILE* dosya;
    dosya = fopen("Sayilar.txt", "r");
    if(dosya==NULL){
        printf("dosya acilamadi\n");
        return;
    }

    char* line = NULL;
    size_t len = 0;
    int read;

    while((read = getline(&line, &len, dosya)) != -1){ 
        //özelliklerin atacagı sayi nesnesi olusturuldu
        Sayi sayi = sayiOlustur();
        char* strDeger;
        int deger;

        //sayinin degeri atandi
        strDeger = line;
        sscanf(strDeger,"%d",&deger);
        sayi->degerAta(sayi, deger);

        //olusturulan sayi sayilar listesine eklendi
        sayilar->sayiEkle(sayilar, sayi);
    }
}