/**
*
* @author Sezer Bulgur ve sezerbulgur2@gmail.com
* @since 7.05.2022
* <p>
* Oyun yapısını ve oyunu başlatmak için gerekli metotları tanımları
* </p>
*/

#include "Oyun.h"

#include <math.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

Oyun oyunuHazirla(const Kisiler kisiler, const Sayilar sayilar){
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->kisiler = kisiler;
    this->sayilar = sayilar;
    this->enZengin = this->kisiler->enZengin(kisiler);
    this->masaBakiye = 0;
    this->sansliSayi = sayilar->ilk;
    this->turSayisi = 0;
    this->oyunuBaslat = &oyunuBaslat;

    return this;
}

int oyunDevamEdiyorMu(const Oyun this){
    if(this->kisiler->ilk==NULL){
        return 0;
    }

    Kisi gec = this->kisiler->ilk;
    while(gec!=NULL){

        if(gec->para < 1000){
            Kisi silinecek = gec;
            gec = gec->sonraki;
            this->kisiler->kisiCikar(this->kisiler, silinecek);
        }
        else{
            gec = gec->sonraki;
        }
    }

    if(this->kisiler->ilk==NULL){
        return 0;
    }

    return 1;
}


void oyunuBaslat(const Oyun this){
    while(oyunDevamEdiyorMu){
        this->turSayisi++;

        Kisi gec = this->kisiler->ilk;
        while(gec!=NULL){ 
            //bahse yatırdıktan sonra kalan para
            double kalanPara = (gec->para)*(1-gec->oran);   
            double oynananPara = (gec->para)*(gec->oran);
            //eger kisi sansli sayiyi tutturduysa
            if(gec->sayi==this->sansliSayi->deger){
                gec->para = kalanPara + oynananPara*10;
                this->masaBakiye -= oynananPara*10;
            }//kaybettiyse
            else{
                gec->para = kalanPara;
                this->masaBakiye += oynananPara;
            }
            gec = gec->sonraki;          
        }
        this->enZengin = this->kisiler->enZengin(this->kisiler);

        Sleep(75);
        system("cls");
        int gecYaz;

        gotoxy(30,5);
        for(int i=0;i<40;i++){
            printf("#");
        }

        gotoxy(30,6);
        gecYaz = log10(this->sansliSayi->deger)+1;
        printf("##          SANSLI SAYI: %d", this->sansliSayi->deger);
        for(int i=0;i<(40-(gecYaz+27));i++){
            printf(" ");
        }
        printf("##");

        gotoxy(30,7);
        for(int i=0;i<40;i++){
            printf("#");
        }

        gotoxy(30,8);
        for(int i=0;i<40;i++){
            printf("#");
        }

        gotoxy(30,9);
        gecYaz = log10(this->turSayisi)+1;
        printf("##");
        for(int i = 0;i<8;i++){
            printf(" ");
        }
        printf("TUR: %d", this->turSayisi);
        for(int i=0;i<(40-(gecYaz+17));i++){
            printf(" ");
        }
        printf("##");

        gotoxy(30,10);
        gecYaz = log10(this->masaBakiye)+1;       
        printf("##    MASA BAKIYE: %d TL", (int)this->masaBakiye);
        for(int i=0;i<(40-(gecYaz+24));i++){
            printf(" ");
        }
        printf("##");

        gotoxy(30,11);
        printf("##");
        for(int i=0;i<36;i++){
            printf(" ");
        }
        printf("##");

        gotoxy(30,12);
        printf("##");
        for(int i=0;i<36;i++){
            printf("-");
        }
        printf("##");

        gotoxy(30,13);
        printf("##           EN ZENGIN KISI           ##");

        gotoxy(30,14);
        gecYaz=strlen(this->enZengin->isim);
        printf("##   %s", this->enZengin->isim);
        for(int i=0;i<40-(gecYaz+7);i++){
            printf(" ");
        }
        printf("##");

        gotoxy(30,15);
        gecYaz=log10(this->enZengin->para)-1;
        printf("##     BAKIYESI: %d", (int)this->enZengin->para);
        for(int i=0;i<40-(gecYaz+21);i++){
            printf(" ");
        }
        printf("##");

        gotoxy(30,16);
        for(int i=0;i<40;i++){
            printf("#");
        }

        if(this->sansliSayi->sonraki!=NULL){
        this->sansliSayi = this->sansliSayi->sonraki;
        }
        else{
            printf("Oyun Bitti\n");
            break;
        }
        
    }

    Sleep(150);
    system("cls");
    int gecYaz;

    gotoxy(30,5);
    for(int i=0;i<40;i++){
        printf("#");
    }
    
    gotoxy(30,6);
    gecYaz = log10(this->turSayisi)+1;
    printf("##");
    for(int i = 0;i<8;i++){
        printf(" ");
    }   
    printf("TUR: %d", this->turSayisi);
    for(int i=0;i<(40-(gecYaz+17));i++){
        printf(" ");
    }
    printf("##");

    gotoxy(30,7);
    gecYaz = log10(this->masaBakiye)+1;       
    printf("##    MASA BAKIYE: %d TL", (int)this->masaBakiye);
    for(int i=0;i<(40-(gecYaz+24));i++){
        printf(" ");
    }
    printf("##");

    gotoxy(30,8);
    printf("##");
    for(int i=0;i<36;i++){
        printf(" ");
    }
    printf("##");

    gotoxy(30,9);
    printf("##");
    for(int i=0;i<36;i++){
        printf("-");
    }
    printf("##");

    gotoxy(30,10);
    printf("##");
    for(int i=0;i<13;i++){
        printf(" ");
    }
    printf("OYUN BITTI");
    for(int i=0;i<13;i++){
        printf(" ");
    }    
    printf("##");

    gotoxy(30,11);
    printf("##");
    for(int i=0;i<36;i++){
        printf(" ");
    }
    printf("##");

    gotoxy(30,12);
    printf("##");
    for(int i=0;i<36;i++){
        printf(" ");
    }
    printf("##");

    gotoxy(30,13);
    printf("##");
    for(int i=0;i<36;i++){
        printf(" ");
    }
    printf("##");

    gotoxy(30,14);
    for(int i=0;i<40;i++){
        printf("#");
    }
}

