/**
*
* @author Sezer Bulgur ve sezerbulgur2@gmail.com
* @since 7.05.2022
* <p>
* Olusturulan uygulamanın çalışmasını sağlayan test programı
* </p>
*/

#include "Sayilar.h"
#include "Kisiler.h"
#include "Dosya.h"
#include "Oyun.h"

int main(){
    Kisiler k1 = kisilerOlustur();

    Sayilar s1 = sayilarOlustur();

    kisileriOku(k1);

    sayilariOku(s1);

    Oyun o1 = oyunuHazirla(k1, s1);

    o1->oyunuBaslat(o1);

}