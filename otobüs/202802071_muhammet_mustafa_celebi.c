#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

char seferno(void);
char sefernono[50][6]={0};
char sefernodizi[6];
int seferseh=0;
int hadibakali=0;
int numara=0;
int decimal;
int otobusbilgidizi[20][20];
int e=0;
int t=0;
int a=0;
int r=0;
int sayac[50];
char merhaba[20][50][50];
int i,j,m=0;
float toplananhasilat[50];
int boskoltuk[50][1];
float musteribasiucret[50][50];
char seferbilgileri[20][50];
char ad_soyad[50][20];
int ad_soyadi[50][20];

char rezervasyonno(void){
   const char *hex = "0123456789ABCDEF";
   int i;
   srand(time(0));
   for( i =0; i<8; i++){
      ad_soyad[a][i] = hex[ ( rand() % 16 ) ];
   }
   // a 2 idi yani her 3 te bir kisi degisiyor
   return ad_soyad;
}

char adfalan(void){
int girilensayi;
printf("Lutfen adinizi giriniz.\n");
scanf("%s",&ad_soyad[a]); //a=0
a++;
printf("Lutfen soyadinizi giriniz.\n");
scanf("%s",&ad_soyad[a]); //a=1
a++; //a=2
printf("Lutfen istediginiz koltuk icin sira giriniz.\n");
scanf("%d",&ad_soyadi[r][0]); // sırayı r=0 kaydetti
r++;
sutungir:
printf("Lutfen istediginiz koltuk icin sutun numarasi giriniz.\n");
scanf("%d",&ad_soyadi[r][0]); // sutunu r=1 e kaydetti
if(ad_soyadi[r][0]>4)
goto sutungir;
r++;
printf("Sectiginiz koltugu rezerve etmek istediginizden emin misiniz?\nEminseniz 1 degilseniz 0  tuslayiniz.");
scanf("%d",&girilensayi);
if(girilensayi==1){
    rezervasyonno();
    printf("Rezervasyon numaraniz %s dir.\n",ad_soyad[a]);
    a++; // ayı 3 yaptı
    r++; // r yi de 3 yaptım aynı yere gelsin diye bilgiler.
    return ad_soyad;
    return ad_soyadi;
}
if(girilensayi==0){
    a=0;
    r=0;
    musteri_girisi();
}

}

char matris(int kapasite,int m){

    for (i=0;i<(kapasite/4);i++){
     for(j=2;j<15;j+=2){
            merhaba[m][i][j]=' '; //[ ] [ ] [ ] [ ]
     }
     for(j=1;j<14;j+=4){
        merhaba[m][i][j]='[';
    }
    for(j=3;j<16;j+=4){
        merhaba[m][i][j]=']'; // j 7 ise bir tab koy kanks
    }

    }
    return 0;
}
char matris_yazdir(int kapasite,int m){
    printf("\t");
    for(i=1;i<5;i++){
       if (i==3){
        printf("\t ");          // [ ] [ ] [ ] [ ] 16 okey 1 5 9 13 2 4 6 14 3 7 11 15
       }
       printf(" %d  ",i);

    }
    printf("\n");

for (i=0;i<(kapasite/4);i++){
        printf("%d",i+1);
        printf("\t");
     for(j=1;j<16;j++){
        if (j==8){
            printf("\t\t");
        }
        printf("%c",merhaba[m][i][j]);
     }
     printf("\n\n");
    }
}



int toplam_hasilat(void){
int toplamhasilat;
printf("Toplam istenilen hasilati giriniz.\n");
/* hocam normalde asagıya yazıyordum ama asagıya yazınca indefined reference to "fonksiyon adi" yazmaya basladi. prototip tanimlasam da cozulmedi.
ben de buraya yazmazaya basladim o yuzden. */
scanf("%d",&toplamhasilat);
return toplamhasilat;
}
char dec_hex(int decinum ){
 int decimalnum, bolum, kalan;
    int o;
    int i, j = 0;
    char hexadecimalnum[6];
    decimalnum=decinum;
    bolum = decimalnum;

    while (bolum != 0)
    {
        kalan = bolum % 16;
        if (kalan < 10)
            hexadecimalnum[j++] = 48 + kalan;
        else
            hexadecimalnum[j++] = 55 + kalan;
        bolum = bolum / 16;
    }
    for (i = j; i >= 0; i--){
            printf("%c", hexadecimalnum[i]);
    }
    printf("\n");


    return hexadecimalnum;
}
int hex_dec(void){
char hex[17];
    int decimal;
    int i = 0, deger, uzunluk;

    decimal = 0;
    uzunluk = 6;
    uzunluk--;

    for(i=0; sefernodizi[i]!='\0'; i++)
    {
        if(sefernodizi[i]>='0' && sefernodizi[i]<='9')
        {
            deger = sefernodizi[i] - 48;
        }
        else if(sefernodizi[i]>='a' && sefernodizi[i]<='f')
        {
            deger = sefernodizi[i] - 97 + 10;
        }
        else if(sefernodizi[i]>='A' && sefernodizi[i]<='F')
        {
            deger= sefernodizi[i] - 65 + 10;
        }

        decimal += deger* pow(16, uzunluk);
        uzunluk--;
    }
    return decimal;
}

int siralama(void){
int i,j,max;
int sehiricin;
int dizi[20];
for(i=0;i<numara;i++){
  dizi[i]=otobusbilgidizi[i][3];
}

for(i=0;i<numara;i++){
 for(j=0;j<numara;j++){
if(dizi[j]<=dizi[i]){
max=dizi[i];
dizi[i]=dizi[j];
dizi[j]=max;
}
}
}
for(i=0;i<numara;i++){
printf("%d-",i+1);
dec_hex(dizi[i]);
 for(j=0;j<numara;j++){
  if(dizi[i]==otobusbilgidizi[j][3]){
    printf("oto. num. %d, ",otobusbilgidizi[j][0]);
    printf("bas. saat. %d, ",otobusbilgidizi[j][4]);
    printf("bit. saat. %d, ",otobusbilgidizi[j][5]);
    sehiricin=(otobusbilgidizi[j][0])*2;
    printf("%s - ",seferbilgileri[sehiricin-2]);
    printf("%s, ",seferbilgileri[sehiricin-1]);
    printf("ucret %.2f, \n",musteribasiucret[j][0]);
  }
}
}
printf("\n");
}




int main(){

anamenu();


return 0;
}
void anamenu(){
 int girilensayi;
 int i;

 printf("\t\tANA MENU\n");
 printf("1-Firma Girisi  \t(Secmek icin 1 tuslayiniz)\n");
 printf("2-Musteri Girisi\t(Secmek icin 2 tuslayiniz)\n");
 printf("3-Cikis         \t(Secmek icin 3 tuslayiniz)\n");



 printf("Lutfen girmek istediginiz menunun numarasini seciniz.=>");
 git:
 scanf("%d",&girilensayi);
 printf("\n");
 for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");
 if(girilensayi==1){

   firma_girisi();
 }
 else if(girilensayi==2){
    musteri_girisi();
 }
 else if(girilensayi==3){
    printf("Bizi tercih ettiginiz icin tesekkurler iyi gunler dileriz.\n");
    return 0;
 }
 else{
     printf("Var olmayan bir menu sectiniz.");
     printf("Lutfen var olan bir menuyu secmek icin tekrar giris yapiniz.=>");
    goto git;
 }


    return 0;
}
void firma_girisi(){
int  o=0, k=0,s=0;
char model[50];
char yol[50];
int girilen_sayi, i;
int kontrol;
int varissaati;
char SeferBasSehir[50];
char SefBitSehir[50];
int x;
float bitecekmiacaba;
firmayadonus:
k=0;
printf("1-Otobus Ekle         \t(Secmek icin 1 tuslayiniz)\n");
printf("2-Sefer Bilgisi Ekle  \t(Secmek icin 2 tuslayiniz)\n");
printf("3-Sefer/Koltuk Bilgisi\t(Secmek icin 3 tuslayiniz)\n");
printf("4-Bir Ust Menuye Don  \t(Secmek icin 4 tuslayiniz)\n\n");
printf("Lutfen yapmak istediginiz islemin numarasini seciniz.=>");
git:
scanf("%d",&girilen_sayi);
printf("\n");
 for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");

switch(girilen_sayi){//otobusun numarası o olacak diger bilgiler k. sütuna kaydedilecek en son numarayı arttıracagım.
case 1:
    otobusbilgidizi[o][k]=otobus_no(); //otobus numarasını dizinin bu indisine kaydettim k=0
    printf("Otobus numarasi %d dir\n",otobusbilgidizi[o][k]);
    k++;
    otobusbilgidizi[o][k]=otobus_kapasite(); //otobus kapasitesini bu diziye kaydettim k=1
    sayac[o]=otobusbilgidizi[o][k];
    if(otobusbilgidizi[o][k]>30){
        k++;
        printf("Otobus uzun yol otobusu olarak kaydedilmistir.\n");
        yol[50]="Uzun yol otobusudur.3 personel çalışmalıdır";
        otobusbilgidizi[o][k]=3; //personel sayisi kayit etti k=2
    }
    else{
        k++;
        printf("Otobus kisa yol otobusu olarak kaydedilmistir.\n");
        yol[50]="Kisa yol otobusudur.2 personel çalışmalıdır";
        otobusbilgidizi[o][k]=2; //personel sayisi kayit etti k=2
    }
    printf("Lutfen eklemek istediginiz otobus modelini giriniz.");
    scanf("%s",model);
    for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");
    printf("Eklediginiz otobus icin kaydedilen bilgiler bunlardir.\n");
    printf("otobus numarasi %d dir\n",otobusbilgidizi[o][k-2]);
    printf("otobus kapasitesi %d dir\n",otobusbilgidizi[o][k-1]);
    printf("otobus modeli %s dir\n",model);
    switch(otobusbilgidizi[o][k]){
    case 2:
    printf("otobuste calisan personel sayisi %d dir\n",otobusbilgidizi[o][k]);
    break;
    case 3:
    printf("otobuste calisan personel sayisi %d tur\n",otobusbilgidizi[o][k]);
    break;
    }
    o++;
    k=0;
    for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");
    goto firmayadonus;
    break;
case 2:
   seferno();
   printf("%s\n",sefernodizi);
   printf("Bir otobus numarasi giriniz.");
   scanf("%d",&x);
   printf("otobus numarasi %d dir\n",x);
   otobusbilgidizi[x-1][3]=hex_dec(); // string bir ifadeyi int dizisine kaydedemeyeceğim icin sefer noyu inte dönüstürüp buraya kaydettim
   matris(otobusbilgidizi[x-1][1],x-1);
   saatistirem:
   otobusbilgidizi[x-1][4]=sefer_baslangic_saat(); // sefer baslangic saati buraya kaydedildi k=4
   printf("Lutfen seferin bitis saatini giriniz.\n");
   varisadon:
   scanf("%d",&varissaati);
   if (varissaati/100>24 || varissaati%100>60){
    printf("Boyle bir saat girisi olamaz. Lutfen tekrar giris yapiniz");
    goto varisadon;
   }
   otobusbilgidizi[x-1][5]=varissaati; // sefer varis saati buraya kaydedildi k=5
   kontrol=(otobusbilgidizi[x-1][5] / 100) - (otobusbilgidizi[x-1][4] / 100);
   if(kontrol==0){
    kontrol=24;
   }
   else if(kontrol<=0){
    kontrol=(24-(otobusbilgidizi[x-1][4] / 100))+(otobusbilgidizi[x-1][5] / 100);
   }
   if(kontrol>4 && otobusbilgidizi[x-1][2]==2){
    printf("Maalesef kisa yol otobusunu uzun yol icin kullanamazsiniz.\n");
    goto saatistirem;
   }
   printf("Yolculuk tahmini olarak %d saat surecektir\n",kontrol);
   printf("Lutfen seferin baslayacagi sehiri giriniz.");
   scanf("%s",&seferbilgileri[s]); //
   s++;
   printf("Lutfen seferin bitecegi sehiri giriniz.");
   scanf("%s",&seferbilgileri[s]);
   s++;
   printf("Yolculuk %s",seferbilgileri[s-2]);
   printf("-");
   printf("%s sehirleri arasinda olacaktir.\n",seferbilgileri[s-1]);
   otobusbilgidizi[x-1][6]=toplam_hasilat(); // toplam hasilat burada kayıtlı yani k=6
   musteribasiucret[x-1][0]=(otobusbilgidizi[x-1][6] / 1.00) / (otobusbilgidizi[x-1][1] / 1.00);
   printf("Musteri basi gereken ucret %.2f dir\n",musteribasiucret[x-1][0]);
for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");
   printf("%d. otobus icin kaydedilen bilgiler bunlardir\n",x);
   printf("Otobusun yola cikma saati %d varis saati %d dir\n",otobusbilgidizi[x-1][3],otobusbilgidizi[x-1][4]);
   printf("Yolculuk tahmini olarak %d saat surecektir\n",kontrol);
   printf("Yolculuk %s-%s sehirleri arasinda olacaktir.\n",seferbilgileri[s-2],seferbilgileri[s-1]);
   printf("Sefer icin istenen toplam hasilat %d dir\n",otobusbilgidizi[x-1][6]);
   printf("Musteri basi gereken ucret %.2f dir\n",musteribasiucret[x-1][0]);
   for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");
   goto firmayadonus;
   break;
case 3:
    for(e=0;e<numara;e++){
   printf("%d-",e+1);
   dec_hex(otobusbilgidizi[e][3]);
   printf("\n");
    }
    printf("Lutfen girmek istediginiz seferin basindaki numarayi seciniz.");
    scanf("%d",&x);
    matris_yazdir(otobusbilgidizi[x-1][1],x-1);
    for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");
    seferseh=x*2;
    printf("Otobuse ait bilgiler bunlardir.\n");
    printf("otobus numarasi %d dir.\n",otobusbilgidizi[x-1][0]);
    printf("otobus kapasitesi %d dir.\n",otobusbilgidizi[x-1][1]);
    printf("Bos koltuk sayisi %d dir.\n",sayac[x-1]);
    printf("Otobusun kalkis saati %d dir.\n",otobusbilgidizi[x-1][4]);
    printf("Otobusun varis saati %d dir.\n",otobusbilgidizi[x-1][5]);
    printf("Yolculuk %s sehri ile %s sehri arasinda olacaktir.\n",seferbilgileri[seferseh-2],seferbilgileri[seferseh-1]);
    dec_hex(otobusbilgidizi[x-1][3]);
    for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");
    goto firmayadonus;
   break;
case 4:
    anamenu();
    break;
default:
     printf("Var olmayan bir islem sectiniz.");
     printf("Lutfen var olan bir islem secmek icin tekrar giris yapiniz.=>\n");
    goto git;
    break;
    }
}
void musteri_girisi(){
int girilen_sayi, i;
int x;
char sefernnn;
char girilenrez[8];
int kontrol;
int karsilastirma;
int sira[50];
int sutun[50];
musteridon:
printf("1-Seferleri Listele      (Secmek icin 1 tuslayiniz)\n");
printf("2-Sefer Rezervasyon Yap  (Secmek icin 2 tuslayiniz)\n");
printf("3-Rezervasyon Goster     (Secmek icin 3 tuslayiniz)\n");
printf("4-Bir Ust Menuye Don     (Secmek icin 4 tuslayiniz)\n\n");
printf("Lutfen yapmak istediginiz islemin numarasini seciniz.=>");
git:
scanf("%d",&girilen_sayi);
printf("\n");
 for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");

switch(girilen_sayi){
case 1:
    siralama();
    printf("Bir ust menuye donmek icin herhangi bir tusa basiniz.\n");
    getch();
    for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");
    goto musteridon;
    break;
case 2:
    for(e=0;e<numara;e++){
   printf("%d-",e+1);
   dec_hex(otobusbilgidizi[e][3]);
   printf("\n");
    }
    printf("Lutfen Rezervasyon yaptirmak istediginiz seferin basindaki numarayi giriniz.");
    scanf("%d",&x);
    matris_yazdir(otobusbilgidizi[x-1][1],x-1);
    adfalan();
    sirasutuna:
    sira[t]=ad_soyadi[r-3][0];
    sutun[t]=ad_soyadi[r-2][0];
    if(sutun[t]==1){
        sutun[t]=2;
        sayac[x-1]--;
    }
    if(sutun[t]==2){
        sutun[t]=6;
        sayac[x-1]--;
    }
    if(sutun[t]==3){
     sutun[t]=10;
     sayac[x-1]--;
    }
    if(sutun[t]==4){
         sutun[t]=14;
         sayac[x-1]--;
    }
    if(merhaba[x-1][sira[t]-1][sutun[t]]=='x'){
    printf("Bu koltuk alinamiyor.\n");
    printf("Lutfen bos bir koltuk seciniz.\n");
    adfalan();
    }
    merhaba[x-1][sira[t]-1][sutun[t]]='x';
    matris_yazdir(otobusbilgidizi[x-1][1],x-1);
    for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");
    goto musteridon;
    break;
case 3:
    printf("rezervasyon numaranizi giriniz.");
    scanf("%s",girilenrez);
    for(i=2;i<50;i=i+3){
        if(strcmp(girilenrez,ad_soyad[i]) == 0){
            printf("Adiniz %s Soyadiniz %s\n",ad_soyad[i-2] ,ad_soyad[i-1]);
        }
    }
    printf("Sefer bilgilerini gormek icin lutfen bir onceki menude Seferleri Listele secenegini seciniz.\n");
    printf("Iyi gunler dileriz.\n");
    for(i=0;i<24;i++){
    printf("-----");
    }
    printf("\n");
    goto musteridon;
    break;
case 4:
    anamenu();
    break;
default:
     printf("Var olmayan bir islem sectiniz.");
     printf("Lutfen var olan bir islem secmek icin tekrar giris yapiniz.=>\n");
    goto git;
    break;
    }
}
char seferno(void){
   const char *hex = "0123456789ABCDEF";
   int i;
   sefernodizi[0]='7';
   sefernodizi[1]='1';
   srand(time(0));
   for( i = 2 ; i < 6; i++ ) {
      sefernodizi[i] = hex[ ( rand() % 16 ) ];
   }
   for(i=0;i<6;i++){
    sefernono[hadibakali][i]=sefernodizi[i];
   }
   hadibakali++;
   return sefernodizi;
}
int otobus_no(void){
int otobusno;
otobusno=numara+1;
numara++;
return otobusno;
}

int otobus_kapasite(void){
int otobuskapasite;
printf("Lutfen otobus icin bir kapasite giriniz.(Girilen sayi 4 e bolunuyor olmalidir.)");
scanf("%d",&otobuskapasite);
return otobuskapasite;
}

int sefer_baslangic_saat(void){
int sef_bas_saat;
int yeni_sef_bas_saat;
git:
printf("Lutfen sefer baslangic saatini giriniz.");
scanf("%d",&sef_bas_saat);
if(sef_bas_saat/100>24){
    printf("Boyle bir saat dilimi bulunmamaktadir\n");
    goto git;
}
if (sef_bas_saat%100==11){
    return sef_bas_saat;
}
else{
    sef_bas_saat=sef_bas_saat/100;
    yeni_sef_bas_saat=(sef_bas_saat*100)+11;
    printf("Maalesef sefer bu saatte baslayamaz.Sefer saati %d ile degistirildi.\n",yeni_sef_bas_saat);
    return yeni_sef_bas_saat;

}

int toplam_hasilat(void){
int toplamhasilat;
printf("Toplam istenilen hasilati giriniz.");
scanf("%d",&toplamhasilat);
return toplamhasilat;
}
}









