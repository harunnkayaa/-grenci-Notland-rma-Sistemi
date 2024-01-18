/*  
* @file Proje1.c  
* @description fonksiyonların içeriklerini dolduran dosyam  
* @assignment Proje1
* @date 06.12.23
* @author Harun Kaya harun.kaya@stu.fsm.edu.tr 
*/
#include "proje1.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
    

// Belirli bir dersin tüm öğrenciler arasındaki ortalama notunu hesaplar
double ortlamaDersNotu(Ogrenci *ogrclr, int ogrnciSysi, char *drsAdi)
{
    float toplamPuan = 0;


    for (int i = 0; i < ogrnciSysi; ++i){
        for (int j = 0; j < 10; ++j){
            //ogrenci dizisi içinde dönüp, o öğrencinin aldığı derslerde parametre olarak verilen derisn adı varsa, 
            //o dersin puanını ortalama hesabının içiene katar
            if (stringlerEsitMi(ogrclr[i].aldigiDersler[j].dersAdi, drsAdi)){
                toplamPuan += ogrclr[i].aldigiDersler[j].puan;
               
                break;
            }
        }
    }
    if (ogrnciSysi == 0){
        // Hata durumu için -1 döndürülebilir.
        printf("Bu dersi hiçbir ögrenci almiyor\n");
        return -1; 
    }
     return toplamPuan / ogrnciSysi;
}

// İki stringin eşit olup olmadığını kontrol eder, strcmp hazır fonksiyonu yerine yaptım 
bool stringlerEsitMi( char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
            return false;
        
        str1++;
        str2++;
    }
    
    return (*str1 == *str2);
}

//bilgisi yazırılmak istenen öğrencinin bilgilerini yazdirir
void ogrYazdir( Ogrenci ogrenci){
    printf("**************************************************************");
    printf("\nOgrencinin Adi: %s %s\n", ogrenci.ogrAdi, ogrenci.ogrSoyAdi);
    printf("\nOgrencinin Bolumu: %s\n", ogrenci.bolumu);
    printf("\nOgrencinin Ortalamasi: %.2f\n", ogrenci.ortalama);

    // Dersleri yazdırma
    printf("\n %s ogrencisinin aldigi dersler:\n",ogrenci.ogrAdi);
    for (int i = 0; i < 10; i++)
    {
        if (ogrenci.aldigiDersler[i].dersAdi != NULL){
            //ogrencinin aldigi derslerin null olması durumunda yazdırmaya çalışmaz
            
            printf("Ders Adi: %s, Kredi: %hu, Puan: %hu\n", ogrenci.aldigiDersler[i].dersAdi, ogrenci.aldigiDersler[i].kredi, ogrenci.aldigiDersler[i].puan);
        }
    }
    printf("\n");
}


Ogrenci ogrOlustur(char *ogrAdi, char *ogrSoyAdi, char *bolumu, float ortalama,  Ders *aldigiDersler){
     Ogrenci ogrencim;
    ogrencim.ortalama = ortalama;
    // dinamik olarak yer ayırma işlemi yapar
    ogrencim.bolumu = (char *)malloc(256 * sizeof(char));
    ogrencim.ogrSoyAdi = (char *)malloc(256 * sizeof(char));
    ogrencim.ogrAdi =  (char *)malloc(256 * sizeof(char));
    ogrencim.aldigiDersler = (Ders *)malloc(10 * sizeof(Ders));
    // parametreyle gelen bilgileri ogrenci yapıma atama işlemleri
    strcpy(ogrencim.ogrAdi,ogrAdi);
    strcpy(ogrencim.ogrSoyAdi,ogrSoyAdi);
    strcpy(ogrencim.bolumu,bolumu);
    for (int i = 0; i < 10; i++){
        if (aldigiDersler[i].dersAdi != NULL){
            ogrencim.aldigiDersler[i] = aldigiDersler[i];
        }else{
            ogrencim.aldigiDersler[i].puan = 0;
            ogrencim.aldigiDersler[i].dersAdi = NULL;
            ogrencim.aldigiDersler[i].kredi = 0;    
            //Ders adim null ise diger alanlarida sifirladim.
        }
    }
    return ogrencim;
}


Ders drsOlustur(unsigned short int kredi, unsigned short int puan, char *dersAdi)
{
     Ders dersim;
    dersim.kredi = kredi;
    dersim.puan = puan;
    //dinamik olarak ders adi için yer ayirir
    dersim.dersAdi = (char *)malloc(256 * sizeof(char));
    strcpy(dersim.dersAdi,dersAdi);
    return dersim;
}






void ogrDizisiYazdir( Ogrenci *ogrenciler, int ogrenciSayisi){
    int i;
    for ( i= 0; i < ogrenciSayisi; i++){
        printf("Ogrencinin Adi Soyadi: %s %s\n", ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi);
        printf("Ogrencinin Bolumu: %s\n", ogrenciler[i].bolumu);
        printf("Ogrencinin Ortalamasi: %.2f\n", ogrenciler[i].ortalama);
        int j;
        for ( j = 0; j < 10; j++){
            if (ogrenciler[i].aldigiDersler[j].dersAdi != NULL){
                printf("Ders Adi: %s, Kredi: %hu, Puan: %hu\n", ogrenciler[i].aldigiDersler[j].dersAdi, ogrenciler[i].aldigiDersler[j].kredi, ogrenciler[i].aldigiDersler[j].puan);
            }
        }
        printf("\n");
    }
}

double drsKovaryansHesapla(Ogrenci *ogrenciler, int ogrenciSayisi, Ders ders1, Ders ders2)
{
    // İlk olarak derslerin ortalamasını hesapla
    double ders1Ortalamasi = ortlamaDersNotu(ogrenciler, ogrenciSayisi, ders1.dersAdi);
    double ders2Ortalamasi = ortlamaDersNotu(ogrenciler, ogrenciSayisi, ders2.dersAdi);


    int ders2AlanOgrenciSayisi = 0;
    int ders1AlanOgrenciSayisi = 0;
    double tplmKovaryans = 0;

    // Her öğrenci için döngü
    for (int i = 0; i < ogrenciSayisi; i++){
        // Birinci ve ikinci dersin bulunup bulunmadığını kontrol etmek için değişkenler
        int ders1Bulundu = 0;
        int ders2Bulundu = 0;

        // Öğrencinin aldığı dersleri içinde gezer ve kontrol sağlayar 
        for (int j = 0; ogrenciler[i].aldigiDersler[j].dersAdi != NULL;j++) {
            
            if (stringlerEsitMi(ogrenciler[i].aldigiDersler[j].dersAdi, ders1.dersAdi)) {
                // Eğer birinci ders bulunduysa
                // Birinci dersin not farkını hesapla
                float ders1Fark = ogrenciler[i].aldigiDersler[j].puan - ders1Ortalamasi;
                ders1Bulundu = 1;

                // Öğrencinin aldığı diğer dersleri gezen döngü
                for (int k = 0; ogrenciler[i].aldigiDersler[k].dersAdi != NULL; k++) {
                    // Eğer ikinci ders bulunduysa
                    if (stringlerEsitMi(ogrenciler[i].aldigiDersler[k].dersAdi, ders2.dersAdi)) {
                        // İkinci dersin not farkını hesapla
                        float ders2Fark = ogrenciler[i].aldigiDersler[k].puan - ders2Ortalamasi;
                        // Kovaryansı toplam kovaryans değişkenine ekle
                        tplmKovaryans += ders1Fark * ders2Fark;
                        ders2Bulundu = 1;
                        break;
                    }
                }
                break;
            }
        }

        // Eğer birinci ders bulunduysa, birinci dersi alan öğrenci sayısını artır
        if (ders1Bulundu)
            ders1AlanOgrenciSayisi++;
        // Eğer ikinci ders bulunduysa, ikinci dersi alan öğrenci sayısını artır
        if (ders2Bulundu)
            ders2AlanOgrenciSayisi++;
    }

    // Eğer birinci dersi alan öğrenci sayısı veya ikinci dersi alan öğrenci sayısı 0 ise hata mesajı yazdır ve -1 döndür
    if (ders1AlanOgrenciSayisi == 0 || ders2AlanOgrenciSayisi == 0) {
        printf("derslerden en azindan birini alan ogrenci bulunamadi.\n");
        return -1;
    }

    // Kovaryansı birinci dersi alan öğrenci sayısının bir eksiğiyle böle ve sonucu döndür
    return tplmKovaryans / (ders1AlanOgrenciSayisi - 1);
}

double drsStdHesapla(Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi) {
    float karalerFrkiToplami = 0;
    int ogrenciSayac = 0;
    // Dersin ortalamasını hesapla
    double dersOrtalamasi = ortlamaDersNotu(ogrenciler, ogrenciSayisi, dersAdi);
    

    // Her öğrenci için döngü
    for (int i = 0; i < ogrenciSayisi; i++) {
        // Öğrencinin aldığı dersleri tarayan döngü
        for (int j = 0; ogrenciler[i].aldigiDersler[j].dersAdi != NULL; j++) {
            // Eğer ders bulunduysa
            if (stringlerEsitMi(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi)) {
                // Kareler farkı toplamına yapılan standartsapma islemi ekleniz
                karalerFrkiToplami += pow(ogrenciler[i].aldigiDersler[j].puan - dersOrtalamasi, 2);
                // Öğrenci sayacı artırılır
                ogrenciSayac++;
            }
        }
    }

    return sqrt(karalerFrkiToplami / ogrenciSayac);
}
void ogrencileriDosyayaYaz(Ogrenci *ogrenciler, int ogrenciSayisi, char *dosyaAdi) {
    
    FILE *dosya;
    dosya = fopen(dosyaAdi, "w");
    // Dosya açma hatası kontrolü
    if (dosya == NULL) {
        perror("Dosya açma hatasi");
        return;
    }
    printf("\nOgrenci bilgileri dosyaya yaziliyor\n");
    // Her öğrenci için döngü
    for (int i = 0; i < ogrenciSayisi; i++) {
        // Öğrenci bilgilerini dosyaya yaz
        fprintf(dosya, "Ogrencinin Adi: %s %s\n", ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi);
        fprintf(dosya, "Ogrencinin Bolumu: %s\n", ogrenciler[i].bolumu);
        fprintf(dosya, "Ogrencinin Ortalamasi: %.2f\n", ogrenciler[i].ortalama);

        // Öğrencinin aldığı dersler için döngü
        for (int j = 0; j < 10; j++) {
            // Eğer ders bilgisi varsa, ders bilgilerini dosyaya yaz
            if (ogrenciler[i].aldigiDersler[j].dersAdi != NULL) {
                fprintf(dosya, "Ders Adi: %s, Kredi: %hu, Puan: %hu\n", ogrenciler[i].aldigiDersler[j].dersAdi, ogrenciler[i].aldigiDersler[j].kredi, ogrenciler[i].aldigiDersler[j].puan);
            }
        }
        fprintf(dosya, "\n");
    }

    fclose(dosya);
}
void ykskNotAlanOgrenciler(Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi, float ortalamaPuan) {
  
   
    // Ders adı ve ortalama puanını ekrana yazdır
    printf("%s dersinden %.3f puanin uzerinde not alan ogrenciler:\n", dersAdi, ortalamaPuan);

    for (int i = 0; i < ogrenciSayisi; i++) {
        int dersBulundu = 0;
        int dersSayisi = 0;

        // Öğrencinin aldığı dersler üzerinde gezen döngü
        while (ogrenciler[i].aldigiDersler[dersSayisi].dersAdi != NULL) {
            // Eğer ders bulunduysa bunanın ortalamsaıyla karşılaştırılması yapılır
            if (stringlerEsitMi(ogrenciler[i].aldigiDersler[dersSayisi].dersAdi, dersAdi)) {
                dersBulundu = 1;

                // Eğer öğrencinin aldığı dersin puanı ortalama puanın üzerindeyse
                if (ogrenciler[i].aldigiDersler[dersSayisi].puan > ortalamaPuan) {
                    // Öğrenciyi ekrana yazdır
                    ogrYazdir(ogrenciler[i]);
                    break; // Sadece yüksek not alan dersi yazdır, diğer dersleri kontrol etme
                }
            }

            dersSayisi++;
        }

        // Eğer ders bulunamadıysa
        if (!dersBulundu) {
            printf(" %s dersi bu ogrencinin aldigi dersler arasinda bulunamadi.\n", dersAdi);
        }
    }
}

char* altDiziBul( char* dizi,  char* altDizi) {
    // Ana dizi ve alt dizi uzunluklarını hesapla
    size_t diziUzunlugu = strlen(dizi);
    size_t altDiziUzunlugu = strlen(altDizi);

 
    for (size_t i = 0; i < diziUzunlugu; i++) {
        // Eğer mevcut karakter altDizi'nin ilk karakteriyle eşleşirse
        if (dizi[i] == altDizi[0]) {
            size_t j;
            // altDizi'nin geri kalanını kontrol et
            for (j = 1; j < altDiziUzunlugu; j++) {
                // Eşleşmeyen bir karakter bulunursa döngüden çık
                if (dizi[i + j] != altDizi[j]) {
                    break;
                }
            }
            // Eğer tüm altDizi, ana dizide bulunduysa başlangıç adresini döndür
            if (j == altDiziUzunlugu) {
                return (char*)(dizi + i);
            }
        }
    }

    // Eşleşme bulunamazsa NULL değeri döndür
    return NULL;
}
void ogrenciyiDosyadanOku(char* dosyaAdi, int ogrenciSayim) {
    FILE* dosya;
    dosya = fopen(dosyaAdi, "r");
    // Dosya açma hatası kontrolü
    if (dosya == NULL) {
        perror("Dosya acma hatasi");
        return;
    }

    printf("Ogrenciler Dosyadan Okunuyor\n");

    char satir[100];
    int ogrenciSayisi = 0;
    // Dosyanın sonuna kadar satır satır oku
    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        // Satırda "Ogrencinin Adi:" ifadesi varsa, satırı ekrana yazdır
        if (altDiziBul(satir, "Ogrencinin Adi:") != NULL) {
            printf("%s", satir);
        }
        // Satırda "Ogrencinin Bolumu:" ifadesi varsa, satırı ekrana yazdır
        else if (altDiziBul(satir, "Ogrencinin Bolumu:") != NULL) {
            printf("%s", satir);
        }
        // Satırda "Ogrencinin Ortalamasi:" ifadesi varsa, satırı ekrana yazdır ve öğrenci sayısını artır
        else if (altDiziBul(satir, "Ogrencinin Ortalamasi:") != NULL) {
            printf("%s", satir);
            ogrenciSayisi++;

            // İstenilen öğrenci sayısına ulaşıldığında döngüyü sonlandır
            if (ogrenciSayisi > ogrenciSayim) {
                break;
            }
        }
    }

    fclose(dosya);
}




