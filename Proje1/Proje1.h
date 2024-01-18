/*  
* @file Proje1.h  
* @description fonksiyonların prototiplerini yazan ve struct yapılarını oluşturan dosyam  
* @assignment Proje1
* @date 03.12.23
* @author Harun Kaya harun.kaya@stu.fsm.edu.tr 
*/
#ifndef Proje1_h
#define Proje1_h
#include <stdbool.h>
typedef struct {
    char *dersAdi;
    unsigned short int kredi;
    unsigned short int puan;
}Ders;

typedef struct {
    char *ogrAdi;
    char *ogrSoyAdi;
    char *bolumu;
    float ortalama;
    Ders *aldigiDersler;
}Ogrenci;

bool stringlerEsitMi(char *str1,char *str2);
Ders drsOlustur( unsigned short int kredi, unsigned short int puan,char *dersAdi);
Ogrenci ogrOlustur(char *ogrAdi, char *ogrSoyAdi, char *bolumu, float ortalama,  Ders *aldigiDersler);
void ogrYazdir( Ogrenci ogrenci);
void ogrDizisiYazdir( Ogrenci *ogrenciler, int ogrenciSayisi);
double ortlamaDersNotu(Ogrenci *ogrclr, int ogrnciSysi, char *drsAdi);
double drsStdHesapla( Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi);
double drsKovaryansHesapla( Ogrenci *ogrenciler, int ogrenciSayisi, Ders ders1,  Ders ders2);
void ykskNotAlanOgrenciler( Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi, float ortalamaPuan);
void ogrencileriDosyayaYaz( Ogrenci *ogrenciler, int ogrenciSayisi, char *dosyaAdi);
char* altDiziBul( char* dizi,  char* altDizi);
void ogrenciyiDosyadanOku(char *dosyaAdi, int ogrenciSayim);

#endif