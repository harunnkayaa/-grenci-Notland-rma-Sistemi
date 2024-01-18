/*#include <stdio.h>
#include <stdlib.h>
#include "Proje1.h"

int main() {
    // Dersleri oluştur
    Ders matematik = dersOlustur("Matematik", 3, 90);
    Ders fizik = dersOlustur("Fizik", 4, 85);
    Ders bp3 = dersOlustur("Bp3", 5, 45);

    // Öğrencileri oluştur
    Ogrenci ogrenci1 = ogrenciOlustur("Ali", "Veli", "Bilgisayar Mühendisliği", 0.0, NULL);
    ogrenci1.aldigiDersler[0] = matematik;
    ogrenci1.aldigiDersler[1] = bp3;

    Ogrenci ogrenci2 = ogrenciOlustur("Ayşe", "Fatma", "Elektrik Mühendisliği", 0.0, NULL);
    ogrenci2.aldigiDersler[0] = fizik;

    // Ortalamaları hesapla ve atama yap
    ogrenci1.ortalama = dersAritmetikOrtalamaHesapla(ogrenci1.aldigiDersler, 2);
    ogrenci2.ortalama = dersAritmetikOrtalamaHesapla(ogrenci2.aldigiDersler, 1);

    // Öğrencileri ekrana yazdır
    printf("Öğrenci 1:\n");
    ogrenciYazdir(&ogrenci1);
    printf("\nÖğrenci 2:\n");
    ogrenciYazdir(&ogrenci2);

    // Öğrenci dizisini oluştur ve yazdır
    Ogrenci ogrenciler[2] = {ogrenci1, ogrenci2};
    printf("\nÖğrenci Dizisi:\n");
    ogrenciDizisiYazdir(ogrenciler, 2);

    // Derslerin standart sapmasını hesapla ve yazdır
    printf("\nMatematik Dersinin Standart Sapması: %.2f\n", dersStandartSapmaHesapla(&matematik, 1));
    printf("Fizik Dersinin Standart Sapması: %.2f\n", dersStandartSapmaHesapla(&fizik, 1));

    // Kovaryans hesapla ve yazdır
    printf("\nMatematik ve Fizik Derslerinin Kovaryansı: %.2f\n", kovaryansHesapla(matematik, fizik));

    // Ortalamanın üstünde not alan öğrencileri yazdır
    printf("\nMatematikten yüksek not alan öğrenciler:\n");
    yuksekNotAlanOgrencileriYazdir(ogrenciler, 2, "Matematik");

    // Öğrencileri dosyaya yaz ve oku
    ogrenciDosyayaYaz(ogrenciler, 2, "ogrenci_kayitlari.txt");
    int okunanOgrenciSayisi;
    Ogrenci* okunanOgrenciler = ogrenciDosyadanOku("ogrenci_kayitlari.txt", &okunanOgrenciSayisi);
    printf("\nDosyadan Okunan Öğrenciler:\n");
    ogrenciDizisiYazdir(okunanOgrenciler, okunanOgrenciSayisi);

    // Bellek temizleme
    free(matematik.dersAdi);
    free(fizik.dersAdi);
    free(bp3.dersAdi);
    for (int i = 0; i < 2; ++i) {
        free(ogrenciler[i].ogrAdi);
        free(ogrenciler[i].ogrSoyAdi);
        free(ogrenciler[i].bolumu);
        free(ogrenciler[i].aldigiDersler);
        free(okunanOgrenciler[i].ogrAdi);
        free(okunanOgrenciler[i].ogrSoyAdi);
        free(okunanOgrenciler[i].bolumu);
        free(okunanOgrenciler[i].aldigiDersler);
    }
    free(okunanOgrenciler);

    return 0;
}
*/