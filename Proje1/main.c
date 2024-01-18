
/*
 * @file main.c
 * @description fonksiyonlarımı test ettiğim dosyam
 * @assignment Proje1
 * @date 03.12.23
 * @author Harun Kaya harun.kaya@stu.fsm.edu.tr
 */

#include "proje1.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        // Komut satırı argümanlarını kontrol etme
        fprintf(stderr, "Kullanim: %s <dosya_adi>\n", argv[0]);
        return 1;
    }

    printf("\n----------------------------------------------BP3-PROJE1----------------------------------------------------\n");

    // Derslerin oluşturulması

    Ders bp1 = drsOlustur(4, 40, "BP");
    Ders sistemler1 = drsOlustur(3, 50, "Sistemler");
    Ders elektrik1 = drsOlustur(4, 60, "Elektrik");
    Ders bp2 = drsOlustur(6, 55, "BP");
    Ders sistemler2 = drsOlustur(4, 60, "Sistemler");
    Ders bp3 = drsOlustur(5, 40, "BP");
    Ders sistemler3 = drsOlustur(3, 55, "Sistemler");

    // Öğrencilere ders ataması

    Ders aldigiDersler[10] = {bp1, sistemler1};
    Ders aldigiDersler2[10] = {bp2, elektrik1};
    Ders aldigiDersler3[10] = {sistemler3};

    // Öğrenci oluşturms
    Ogrenci hayrettin = ogrOlustur("Hayrettin", "Yildirim", "Elektrik Elektronik Muhendisligi", 50, aldigiDersler);
    hayrettin.aldigiDersler[2] = elektrik1;
    Ogrenci muhuttin = ogrOlustur("Muhuttin", "Kaya", "Bilgisayar Muhendisligi", 45, aldigiDersler2);
    muhuttin.aldigiDersler[2] = sistemler3;
    Ogrenci kemalettin = ogrOlustur("Kemallettin ", "Gokten", "Insaat Muhendisligi", 46, aldigiDersler3);
    kemalettin.aldigiDersler[1] = bp1;
    kemalettin.aldigiDersler[2] = elektrik1;

    // Öğrenci dizisinin oluşturulması ve boyutlandırılması

    int ogrenciSayisi;
    Ogrenci *ogrenciler = malloc(sizeof(Ogrenci) * 3);
    ogrenciler[0] = hayrettin;
    ogrenciler[1] = muhuttin;
    ogrenciler[2] = kemalettin;
    ogrenciSayisi = 3;
    ogrenciler = realloc(ogrenciler, sizeof(Ogrenci) * ogrenciSayisi);
    printf("\n---------------------------------------------------------------------------------------------------------\n\n");

    printf("\nOgrenci dizisine sahip fonksiyonun kontrolu ;\n");
    ogrDizisiYazdir(ogrenciler, ogrenciSayisi);

    printf("\n---------------------------------------------------------------------------------------------------------\n\n");

    // Öğrenci bilgilerinin yazdırılması
    printf("%s isimli ogrencinin bilgileri\n", ogrenciler[0].ogrAdi);
    ogrYazdir(hayrettin);
    printf("%s isimli ogrencinin bilgileri\n", ogrenciler[1].ogrAdi);
    ogrYazdir(muhuttin);
    printf("%s isimli ogrencinin bilgileri\n", ogrenciler[2].ogrAdi);
    ogrYazdir(kemalettin);

    //  standart sapma ve ortalama hesaplamaları

    printf("\n---------------------------------------------------------------------------------------------------------\n\n");
    double bpOrtalama = ortlamaDersNotu(ogrenciler, ogrenciSayisi, "BP");
    double sistemlerOrtalama = ortlamaDersNotu(ogrenciler, ogrenciSayisi, "Sistemler");
    double elektrOrtalama = ortlamaDersNotu(ogrenciler, ogrenciSayisi, "Elektrik");
    if (elektrOrtalama != -1)
    {
        printf("\n%s dersinin ortalamasi: %.2f\n", "BP", elektrOrtalama);
    }
    if (bpOrtalama != -1)
    {
        printf("\n%s dersinin ortalamasi: %.2f\n", "BP", bpOrtalama);
    }
    if (sistemlerOrtalama != -1)
    {
        printf("\n%s dersinin ortalamasi: %.2f\n", "Sistemler", sistemlerOrtalama);
    }

    printf("\n---------------------------------------------------------------------------------------------------------\n\n");

    float dersStandartSapmaSistemler = drsStdHesapla(ogrenciler, ogrenciSayisi, "Sistemler");
    float dersStandartSapmaBp = drsStdHesapla(ogrenciler, ogrenciSayisi, "BP");
    if (dersStandartSapmaBp != -1)
    {
        printf("%s dersinin standart sapmasi: %.2f\n", "Sistemler", dersStandartSapmaBp);
    }
    else
    {
        printf("\nStandart sapma hesaplanirken bir hata olustu.\n");
        return 2;
    }
    if (dersStandartSapmaSistemler != -1)
    {
        printf("%s dersinin standart sapmasi: %.2f\n", "Sistemler", dersStandartSapmaSistemler);
    }
    else
    {
        printf("\nStandart sapma hesaplanirken bir hata olustu.\n");
        return 2;
    }
    printf("\n---------------------------------------------------------------------------------------------------------\n\n");

    // kovaryans hesabı
    float kovaryans = drsKovaryansHesapla(ogrenciler, ogrenciSayisi, bp2, sistemler2);
    printf("BP ve Sistemler derslerinin kovaryansi: %.2f\n", kovaryans);

    printf("\n---------------------------------------------------------------------------------------------------------\n\n");

    double ortalamaPuanBp = ortlamaDersNotu(ogrenciler, ogrenciSayisi, "BP");
    double ortalamaPuanSistemler = ortlamaDersNotu(ogrenciler, ogrenciSayisi, "Sistemler");

    ykskNotAlanOgrenciler(ogrenciler, ogrenciSayisi, "BP", ortalamaPuanBp);
    ykskNotAlanOgrenciler(ogrenciler, ogrenciSayisi, "Sistemler", ortalamaPuanSistemler);

    printf("\n---------------------------------------------------------------------------------------------------------\n\n");
    // Öğrenci bilgilerini dosyaya yaz
    ogrencileriDosyayaYaz(ogrenciler, ogrenciSayisi, argv[1]);

    printf("\n---------------------------------------------------------------------------------------------------------\n\n");
    ogrenciyiDosyadanOku(argv[1], ogrenciSayisi);

    free(bp1.dersAdi);
    free(sistemler1.dersAdi);
    free(elektrik1.dersAdi);

    for (int i = 0; i < ogrenciSayisi; i++)
    {
        free(ogrenciler[i].bolumu);
        free(ogrenciler[i].ogrSoyAdi);
        free(ogrenciler[i].ogrAdi);
        free(ogrenciler[i].aldigiDersler);
    }
    free(ogrenciler);

    return 0; // Başarıyla tamamlandı
}
