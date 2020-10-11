#include <stdio.h>
#include <stdlib.h>
#include <time.h>     //time , sleep komutu icin acilan kutuphane
#include <conio.h>    //rand , srand komutlarini calistirmak icin acilan kutuphane
#include <windows.h>   // sleep , system komutlarinin kullanilmasi icin acilan kutuphane
int anamenu();            // Prototip Fonksiyonlar
int sansoyunlarialtmenusu();
int cikis();
int sayisalloto();
int sanstopu();
int onnumara();
int superloto();
int istatistikler();
int sayisallotooyun=0,sanstopuoyun=0,onnumaraoyun=0,superlotooyun=0;
int sayisallotoIstatistik[49][2],sanstopuIstatistik[34][2],onnumaraIstatistik[80][2],superlotoIstatistik[54][2],sanstopuEkIstatistik[14][2];
int toplampuan=0;
unsigned seed;
int main()
{
    printf("Besleme/Cekirdek degeri giriniz :"); //Programin Calismasi icin Besleme Degeri Aliniyor.
    scanf("%u",&seed);
    system("cls");               //Programi Temizliyor.
    anamenu();            // Anamenu Fonksiyonunu Cagiriyor.
    return 0;
}

int anamenu()             //Anamenu Fonksiyon Blogu.
{
    int secim=0;
    do{
    printf("   --ANA MENU--   \n");
    printf("");
    printf("1.  Sans Oyunlari\n");
    printf("2.  Istatistikler\n");
    printf("3.  Cikis");
    printf("\n\n");
    printf("Seciminizi Yapiniz:");
    scanf("%d",&secim);
    system("cls");
    switch(secim)                 //Menuden Secim Yapiliyor.
    {
    case 1:
    {
        sansoyunlarialtmenusu();
        break;
    }
    case 2:
    {
       istatistikler();
       break;
    }
    case 3:
    {
        cikis();
        break;
    }


    }
}
    while(secim<1 || secim>3);            //Yapilan secim aralik disinda ise tekrar sorduruyor.
}

    int  cikis()                           //Cikis Fonksiyon blogu.
{
        char cikilsinmi;
        printf("Cikmak istediginize emin misiniz? \n");
        printf("Evet ise e/E, Hayir ise h/H \n");
                  do
                  {
                  scanf("%c",&cikilsinmi);
                  // Cikis secimi yapiliyor
                  if(cikilsinmi == 'e' || cikilsinmi == 'E')
                  {
                     printf("\n");
                     printf("Cikis Yapiliyor \n");
                     break;
                     return 0;
                  }
                  else if(cikilsinmi == 'h' || cikilsinmi == 'H')
                  {
                     printf("Ana Menuye Donuluyor\n");
                     printf("Lutfen Bekleyiniz...\n");
                     Sleep(2000);
                     system("cls");
                     anamenu();
                     break;
                  }
                  }
    while(cikilsinmi!='e' || cikilsinmi!='E' || cikilsinmi!='h' || cikilsinmi!='H'); //Eger yapilan secim aralik disinda ise tekrar sorduruyor.
    return 0;
}


int sansoyunlarialtmenusu()           //sansoyunlarialtmenusu fonksiyon blogu
{
    int secim;
    do
    {
    printf("1.  Sayisal Loto \n");
    printf("2.  Sans Topu \n");
    printf("3.  On Numara \n");
    printf("4.  Super Loto \n");
    printf("5.  Ana Menu\n");
    printf("\nToplam Puaniniz: %d \n",toplampuan);
    printf("\n");
    printf("Seciminizi Yapiniz : ");
    scanf("%d",&secim);
    system("cls");
    switch(secim)      //SansOyunlariAltMenusunde Secim Yapiliyor.
    {
    case 1:
    {
        sayisalloto();
        break;
    }
    case 2:
    {
        sanstopu();
        break;
    }
    case 3:
    {
        onnumara();
        break;
    }
    case 4:
    {
        superloto();
        break;
    }
    case 5:
    {
        anamenu();
        break;
    }
    default :
    printf("Hatali Secim Yaptiniz Tekrar Seciniz\n");
    break;

    }
    }
    while(secim<1||secim>5);  //Eger Yapilan Secim Aralik Disinda ise Tekrar Sorduruyor.
}




int onnumara()            //On numara fonksiyon blogu
{
    int i=0,j,temp=0,tahmindizi[10],randomdizi[22],kactuttu=0,puan=0;
    char yenioyun;
    srand(time(NULL));    //Rastgele sayi uretiyor.

    for(i=0;i<80;i++)
        {
        onnumaraIstatistik[i][0] = i+1;  // Cikabilecek Sayilarin satirlara eklenmesi.
        if(onnumaraoyun == 0) // Eger oyun hic oynanmadi ise.
           onnumaraIstatistik[i][1] = 0; // Cikma degerleri sifirlanir.
        }

    for(i=0;i<22;i++) // 1-80 araliginda 22 rastgele sayi uretiliyor.
    {
        randomdizi[i] = 1+rand()%80;
    }
    for(i=0;i<22;i++) // Uretilen Sayilarin Esitligi icin Dongu Baslatiliyor
    {

           for(j=i+1;j<21;j++)
           {
               do
               {
               if(randomdizi[i] == randomdizi[j]) // Uretilen Sayilarin esit olup olmadigina bakiliyor
               {
                   printf("  --CEKILIS HATASI--  \n");
                   printf("Cekilisteki Sayilarda Benzerlikler Var(Cekilisteki Sayilarin Farkli Olmasi Gerekmektedir)\n");
                   printf("Farkli Sayilar Gelene Kadar Bekleyiniz...\n");
                   printf("\n");
                   system("cls");
                   onnumara();
                   break;
                }
           }
           while(randomdizi[i] == randomdizi[j]); // Sayilar Esit ise farkli deger gelene kadar uretiliyor
       }
    }


    for(i=0;i<10;i++)            //Kullanicidan 10 adet sayi aliniyor
    {
        do
        {
           printf("[1-80] Araligindaki %d. Sayiyi Giriniz... \n",i+1);
           scanf("%d",&tahmindizi[i]);
           if(tahmindizi[i]<1 || tahmindizi[i]>80)       //Girilen sayinin 1-80 araliginda olup olmadigina bakiliyor.
           printf("Girdiginiz Sayi Aralik Disinda Lutfen Tekrar Giriniz... \n");
        }
        while(tahmindizi[i]<1 || tahmindizi[i]>80);      // Girilen sayi 1-80 araliginda degilse tekrar sayi isteniyor.
    }
    for(i=0;i<10;i++)         // Girilen sayilarin esit olup olmadigini belirlemek icin for dongusu
    {
        do
        {
           for(j=i+1;j<9;j++)
           {
               if(tahmindizi[i] == tahmindizi[j])      //Girilen sayilarin esit olup olmadigi kontrol ediliyor.
               {
                   printf("\n");
                   printf("Girdiginiz Sayilarin Birbirinden Farkli Olmasi Gerekmektedir !\n");
                   printf("Tahmin Girisi Yeniden Yapilacaktir...\n");
                   printf("Sayi Girisi Tekrar Yapilacak...\n");
                   printf("Lutfen 2 Saniye Bekleyiniz \n");
                   Sleep(2000);       //2 saniye bekleme
                   printf("\n");
                   system("cls");
                   onnumara();       //Girilen sayilar esit ise on numara fonk cagriliyor ve tekrar sayi girisi isteniyor.
                   break;
                }
           }
       }
       while(tahmindizi[i] == tahmindizi[j]);      //Girilen sayilar esit ise tekrar dongu calisiyor.
    }

    onnumaraoyun=1; //Oyunun oynanmis oldugunu ifade eder

    for(i=0;i<22;i++)
    {
        for(j=0;j<10;j++)
        {
            if(randomdizi[i] == tahmindizi[j])  //Rastgele gelen sayilar ile kullanicidan alinan sayilarin esit olup olmadigi kontrol ediliyor.
                kactuttu++;       //Her esit deger icin kactuttu degiskeni 1 artiyor.
        }
    }
    printf("\n");
    printf("  --Cekilisten Cikan Sayilar--  \n");
    printf("\n");
    for(i=0;i<22;i++)
    {
        for(j=i+1;j<22;j++)
        {
            if(randomdizi[i]>randomdizi[j])         //Rastgele gelen sayilarda kucukten buyuge siralama yapiliyor.
            {
                temp=randomdizi[i];      //Eger dizinin i degeri j degerinden buyuk ise dizinin i degeri gecici bir degiskene atiliyor.
                randomdizi[i]=randomdizi[j]; //Rastgele dizinin j degeri rastgele dizinin i degerine atiliyor.
                randomdizi[j]=temp;             // Rastgele dizinin j degerine gecici degiskende olan deger ataniyor.
            }
        }
    }
    for(i=0;i<22;i++)          //Rastgele gelen sayilar ekrana yazdirilmasi icin dongu olusturuluyor.
    printf("%4d",randomdizi[i]);       //rastgele sayilar ekrana yazdiriliyor.
    printf("\n");
    printf("  --Sizin Secimleriniz--  \n");
    printf("\n");
    for(i=0;i<10;i++)         //Kullanicidan alinan sayilarin kucukten buyuge siralamasi yapiliyor.
    {
        for(j=i+1;j<10;j++)
        {
            if(tahmindizi[i]>tahmindizi[j])
            {
                temp=tahmindizi[i];
                tahmindizi[i]=tahmindizi[j];
                tahmindizi[j]=temp;
            }
        }
    }
    for(i=0;i<10;i++)           //Kullanicidan alinan sayilar ekrana yazdiriliyor.
        printf("%4d",tahmindizi[i]);
    printf("\n");
    switch(kactuttu)       //Kac sayi tuttuguna gore puanlama yapiliyor.
    {
    case 0:
        puan+=8; break;
    case 6:
        puan+=16; break;
    case 7:
        puan+=32; break;
    case 8:
        puan+=64; break;
    case 9:
        puan+=128; break;
    case 10:
        puan+=256; break;
    default:
        break;
    }

         for(i=0;i<22;i++) //random sayilarin istatistiklerinin tutulmasi
        onnumaraIstatistik[randomdizi[i]-1][1]++; // random diziside solda 1den basladigi icin 1 cikarip diziyi 0inci indisten baslatir

    toplampuan+=puan;        //toplam puana bu oyundaki kazanilan puan eklenir.
    printf("\n");
    printf("Dogru Tahmin Sayisi = %d \n", kactuttu);
    printf("Bu Oyunda Kazandiginiz Puan = %d \n", puan);
    toplampuan += puan;
    printf("Toplam Puaniniz = %d \n",toplampuan);
    printf("\n");
    printf("Yeni Oyun Oynamak Ister Misiniz?\n");
    printf("Evet ise 'e/E', Hayir ise 'h/H' ... Lutfen Seciminizi Yapiniz \n");
    do
    {
       scanf("%c",&yenioyun);
       if(yenioyun=='e' || yenioyun=='E')          //Oyunu tekrar oynamak istedigi soruluyor
       {
            printf("\n");
            printf("Yeni Oyun Baslatiliyor \n");
            printf("Lutfen 2 Saniye Bekleyiniz \n");
            Sleep(2000);
            system("cls");
            onnumara();         //tekrar oynamak isterse on numara fonksiyonu cagiriliyor.
       }
       else if(yenioyun=='h' || yenioyun=='H')
       {
            printf("\n");
            printf("Sans Oyunlari Alt Menusune Geri Donuluyor \n");
            printf("Lutfen Bekleyiniz \n");
            Sleep(2000);
            system("cls");
            sansoyunlarialtmenusu();        //tekrar oynamak istemezse sansoyunlarialtmenusu cagriliyor.
       }
    }
   while(yenioyun!='e' || yenioyun!='E' || yenioyun!='h' || yenioyun!='H');       //e E h H disinda bir karakter girilirse tekrar soruluypr.
    return 0;
}






int sayisalloto()
{

    int i=0,j,temp=0,tahmindizi[6],randomdizi[6],kactuttu=0,puan=0;
    char yenioyun;
    srand(time(NULL));

    for(i=0;i<49;i++)
        {
        sayisallotoIstatistik[i][0] = i+1;  // Cikabilecek Sayilarin satirlara eklenmesi
        if(sayisallotooyun == 0) // Eger oyun hic oynanmadi ise
           sayisallotoIstatistik[i][1] = 0; // Cikma degerleri sifirlanir
        }

    for(i=0;i<6;i++)
    {
        randomdizi[i] = 1+rand()%49;        // 1-49 araliginda 6 adet sayi uretiliyor
    }

    for(i=0;i<6;i++)
    {

           for(j=i+1;j<5;j++)
           {
               do
               {
               if(randomdizi[i] == randomdizi[j])
               {
                   printf("  --CEKILIS HATASI--  \n");
                   printf("Cekilisteki Sayilarda Benzerlikler Var(Cekilisteki Sayilarin Farkli Olmasi Gerekmektedir)\n");
                   printf("Farkli Sayilar Gelene Kadar Bekleyiniz...\n");
                   printf("\n");
                   system("cls");
                   sayisalloto();
                   break;
                }
           }
           while(randomdizi[i] == randomdizi[j]);
       }
    }


    for(i=0;i<6;i++)
    {
        do
        {
           printf("[1-49] Araligindaki %d. Sayiyi Giriniz... \n",i+1);
           scanf("%d",&tahmindizi[i]);
           if(tahmindizi[i]<1 || tahmindizi[i]>49)
           printf("Girdiginiz Sayi Aralik Disinda Lutfen Tekrar Giriniz... \n");
        }
        while(tahmindizi[i]<1 || tahmindizi[i]>49);
    }
    for(i=0;i<6;i++)
    {
        do
        {
           for(j=i+1;j<5;j++)
           {
               if(tahmindizi[i] == tahmindizi[j])
               {
                   printf("\n");
                   printf("Girdiginiz Sayilarin Birbirinden Farkli Olmasi Gerekmektedir !\n");
                   printf("Tahmin Girisi Yeniden Yapilacaktir...\n");
                   printf("Sayi Girisi Tekrar Yapilacak...\n");
                   printf("Lutfen 2 Saniye Bekleyiniz \n");
                   Sleep(2000);
                   printf("\n");
                   system("cls");
                   sayisalloto();
                   break;
                }
           }
       }while(tahmindizi[i] == tahmindizi[j]);
    }

    sayisallotooyun=1; //Oyunun oynanmis oldugunu ifade eder

    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(randomdizi[i] == tahmindizi[j])
                kactuttu++;
        }
    }
    printf("\n");
    printf("  --Cekilisten Cikan Sayilar--  \n");
    printf("\n");
    for(i=0;i<6;i++)
    {
        for(j=i+1;j<6;j++)
        {
            if(randomdizi[i]>randomdizi[j])
            {
                temp=randomdizi[i];
                randomdizi[i]=randomdizi[j];
                randomdizi[j]=temp;
            }
        }
    }
    for(i=0;i<6;i++)
    printf("%4d",randomdizi[i]);
    printf("\n");
    printf("  --Sizin Secimleriniz--  \n");
    printf("\n");
    for(i=0;i<6;i++)
    {
        for(j=i+1;j<6;j++)
        {
            if(tahmindizi[i]>tahmindizi[j])
            {
                temp=tahmindizi[i];
                tahmindizi[i]=tahmindizi[j];
                tahmindizi[j]=temp;
            }
        }
    }

    for(i=0;i<6;i++)
        printf("%4d",tahmindizi[i]);
    printf("\n");
    switch(kactuttu)
    {
    case 3:
        puan+=32; break;
    case 4:
        puan+=64; break;
    case 5:
        puan+=128; break;
    case 6:
        puan+=256; break;
    default:
        break;

    }

    for(i=0;i<6;i++)
        sayisallotoIstatistik[randomdizi[i]-1][1]++;


    toplampuan +=puan;
    printf("\n");
    printf("Dogru Tahmin Sayisi = %d \n", kactuttu);
    printf("Bu Oyunda Kazandiginiz Puan = %d \n", puan);
    toplampuan += puan;
    printf("Toplam Puaniniz = %d \n",toplampuan);
    printf("\n");
    printf("Yeni Oyun Oynamak Ister Misiniz?\n");
    printf("Evet ise 'e/E', Hayir ise 'h/H' ... Lutfen Seciminizi Yapiniz \n");
    do
    {
       scanf("%c",&yenioyun);
       if(yenioyun=='e' || yenioyun=='E')
       {
            printf("\n");
            printf("Yeni Oyun Baslatiliyor \n");
            printf("Lutfen 2 Saniye Bekleyiniz \n");
            Sleep(2000);
            system("cls");
            sayisalloto();
       }
       else if(yenioyun=='h' || yenioyun=='H')
       {
            printf("\n");
            printf("Sans Oyunlari Alt Menusune Geri Donuluyor \n");
            printf("Lutfen Bekleyiniz \n");
            Sleep(2000);
            system("cls");
            sansoyunlarialtmenusu();
       }
    }
    while(yenioyun!='e' || yenioyun!='E' || yenioyun!='h' || yenioyun!='H');
    return 0;
}

int superloto() //superloto fonksiyon blogu
{

    int i=0,j,temp=0,tahmindizi[6],randomdizi[6],kactuttu=0,puan=0;
    char yenioyun;
    srand(time(NULL));

     for(i=0;i<54;i++)
        {
        superlotoIstatistik[i][0] = i+1;  // Cikabilecek Sayilarin satirlara eklenmesi
        if(superlotooyun == 0) // Eger oyun hic oynanmadi ise
           superlotoIstatistik[i][1] = 0; // Cikma degerleri sifirlanir
        }

    for(i=0;i<6;i++)
    {
        randomdizi[i] = 1+rand()%54;
    }

    for(i=0;i<6;i++)
    {

           for(j=i+1;j<5;j++)
           {
               do
               {
               if(randomdizi[i] == randomdizi[j])
               {
                   printf("  --CEKILIS HATASI--  \n");
                   printf("Cekilisteki Sayilarda Benzerlikler Var(Cekilisteki Sayilarin Farkli Olmasi Gerekmektedir)\n");
                   printf("Farkli Sayilar Gelene Kadar Bekleyiniz...\n");
                   printf("\n");
                   system("cls");
                   superloto();
                   break;
                }
           }
           while(randomdizi[i] == randomdizi[j]);
       }
    }


    for(i=0;i<6;i++)
    {
        do
        {
           printf("[1-54] Araligindaki %d. Sayiyi Giriniz... \n",i+1);
           scanf("%d",&tahmindizi[i]);
           if(tahmindizi[i]<1 || tahmindizi[i]>54)
           printf("Girdiginiz Sayi Aralik Disinda Lutfen Tekrar Giriniz... \n");
        }
        while(tahmindizi[i]<1 || tahmindizi[i]>54);
    }
    for(i=0;i<6;i++)
    {
        do
        {
           for(j=i+1;j<5;j++)
           {
               if(tahmindizi[i] == tahmindizi[j])
               {
                   printf("\n");
                   printf("Girdiginiz Sayilarin Birbirinden Farkli Olmasi Gerekmektedir !\n");
                   printf("Tahmin Girisi Yeniden Yapilacaktir...\n");
                   printf("Sayi Girisi Tekrar Yapilacak...\n");
                   printf("Lutfen 2 Saniye Bekleyiniz \n");
                   Sleep(2000);
                   printf("\n");
                   system("cls");
                   superloto();
                   break;
                }
           }
       }while(tahmindizi[i] == tahmindizi[j]);
    }

    superlotooyun=1; //Oyunun oynanmis oldugunu ifade eder

    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(randomdizi[i] == tahmindizi[j])
                kactuttu++;
        }
    }
    printf("\n");
    printf("  --Cekilisten Cikan Sayilar--  \n");
    printf("\n");
    for(i=0;i<6;i++)
    {
        for(j=i+1;j<6;j++)
        {
            if(randomdizi[i]>randomdizi[j])
            {
                temp=randomdizi[i];
                randomdizi[i]=randomdizi[j];
                randomdizi[j]=temp;
            }
        }
    }
    for(i=0;i<6;i++)
    printf("%4d",randomdizi[i]);
    printf("\n");
    printf("  --Sizin Secimleriniz--  \n");
    printf("\n");
    for(i=0;i<6;i++)
    {
        for(j=i+1;j<6;j++)
        {
            if(tahmindizi[i]>tahmindizi[j])
            {
                temp=tahmindizi[i];
                tahmindizi[i]=tahmindizi[j];
                tahmindizi[j]=temp;
            }
        }
    }

    for(i=0;i<6;i++)
        printf("%4d",tahmindizi[i]);
    printf("\n");
    switch(kactuttu)
    {
    case 3:
        puan+=32; break;
    case 4:
        puan+=64; break;
    case 5:
        puan+=128; break;
    case 6:
        puan+=256; break;
    default:
        break;
    }

    for(i=0;i<6;i++) //random sayilarin istatistiklerinin tutulmasi
        superlotoIstatistik[randomdizi[i]-1][1]++; // random dizisinde solda 1den basladigi icin 1 cikarip diziyi 0inci indisten baslatir

    toplampuan+=puan;

    printf("\n");
    printf("Dogru Tahmin Sayisi = %d \n", kactuttu);
    printf("Bu Oyunda Kazandiginiz Puan = %d \n", puan);
    toplampuan += puan;
    printf("Toplam Puaniniz = %d \n",toplampuan);
    printf("\n");
    printf("Yeni Oyun Oynamak Ister Misiniz?\n");
    printf("Evet ise 'e/E', Hayir ise 'h/H' ... Lutfen Seciminizi Yapiniz \n");
    do
    {
       scanf("%c",&yenioyun);
       if(yenioyun=='e' || yenioyun=='E')
       {
            printf("\n");
            printf("Yeni Oyun Baslatiliyor \n");
            printf("Lutfen 2 Saniye Bekleyiniz \n");
            Sleep(2000);
            system("cls");
            superloto();
       }
       else if(yenioyun=='h' || yenioyun=='H')
       {
            printf("\n");
            printf("Sans Oyunlari Alt Menusune Geri Donuluyor \n");
            printf("Lutfen Bekleyiniz \n");
            Sleep(2000);
            system("cls");
            sansoyunlarialtmenusu();
       }
    }
    while(yenioyun!='e' || yenioyun!='E' || yenioyun!='h' || yenioyun!='H');
    return 0;
}


int sanstopu()   //sanstopu fonksiyon blogu
{
    int i,j,temp=0,tahmindizi[5],randomdizi[5],kacttuttu=0,puan=0,tuttuek=0,tahminek=0,rastgeleek=0;
    char yenioyun;
    srand(time(NULL));

    for(i=0;i<34;i++)
    {
        sanstopuIstatistik[i][0] = i+1;
        if(sanstopuoyun == 0)
           sanstopuIstatistik[i][1] = 0;
    }

    for(i=0;i<14;i++)
    {
        sanstopuEkIstatistik[i][0] = i+1;
        if(sanstopuoyun == 0)
           sanstopuEkIstatistik[i][1] = 0;
    }


    for(i=0;i<5;i++)
    {
        randomdizi[i] = 1+rand()%34;        //1-34 sayi araliginda 5 sayi uretiliyor.
    }
    rastgeleek = 1 +rand()%14;                 //1-14 sayi araliginda +1 adet sayi uretiliyor.
    for(i=0;i<5;i++)
    {
           for(j=i+1;j<4;j++)
           {
               do
                {
               if(randomdizi[i] == randomdizi[j])
               {
                   printf("  --CEKILIS HATASI--  \n");
                   printf("Cekilisteki Sayilarda Benzerlikler Var(Cekilisteki Sayilarin Farkli Olmasi Gerekmektedir)\n");
                   printf("Farkli Sayilar Gelene Kadar Bekleyiniz...\n");
                   printf("\n");
                   system("cls");
                   sanstopu();
                   break;
                }
           }
           while(randomdizi[i] == randomdizi[j]);
       }
    }
    for(i=0;i<6;i++)
    {
        do
        {
            if(i==5)
            {
                do
                {
                    printf("1-14 Arasi Ek Sayiyi Giriniz... \n");
                    scanf("%d",&tahmindizi[i]);
                    if(tahmindizi[i]<1 || tahmindizi[i]>14)
                        printf("Girdiginiz Sayi Aralik Disinda Lutfen Tekrar Giriniz... \n");
                }
                while(tahmindizi[i]<1 || tahmindizi[i]>14);
                break;
            }
           printf("1-34 Arasi %d. Sayiyi Giriniz... \n",i+1);
           scanf("%d",&tahmindizi[i]);
           if(tahmindizi[i]<1 || tahmindizi[i]>34)
           printf("Girdiginiz Sayi Aralik Disinda Lutfen Tekrar Giriniz... \n");
        }
        while(tahmindizi[i]<1 || tahmindizi[i]>34);
    }
    for(i=0;i<6;i++)
    {
        do
        {
           for(j=i+1;j<5;j++)
           {
               if(tahmindizi[i] == tahmindizi[j])
               {
                   printf("\n");
                   printf("Girdiginiz Sayilarin Birbirinden Farkli Olmasi Gerekmektedir !\n");
                   printf("Tahmin Girisi Yeniden Yapilacaktir...\n");
                   printf("Sayi Girisi Tekrar Yapilacak...\n");
                   printf("Lutfen 2 Saniye Bekleyiniz \n");
                   Sleep(2000);
                   printf("\n");
                   system("cls");
                   sanstopu();
                   break;
               }
           }

       }
       while(tahmindizi[i] == tahmindizi[j]);
    }
       tahminek = tahmindizi[5];      //tahmin dizinin 5inci degeri tahminek adli degiskene ataniyor.
       sanstopuoyun=1;                 //oyunun oynandigini ifade eder.
    for(i=0;i<5;i++)                   //kullanicidan alinan 5 sayi ile rastgele gelen 5 sayinin esitligi kontrol edilmesi icin acilan for.
    {
        for(j=0;j<5;j++)
        {
            if(randomdizi[i] == tahmindizi[j])
                kacttuttu++;
        }
    }
    if(rastgeleek == tahminek)        //rastgele gelen +1 sayi ile kullanicidan alinan +1 sayinin esitligi kontrol ediliyor.
            tuttuek++;               //eger esit ise tuttuek degiskeni 1 arttiriliyor.
    printf("\n");
    printf("  --Cekilisten Cikan Sayilar--  \n");
    printf("\n");
    for(i=0;i<6;i++)                  //siralama
    {
        for(j=i+1;j<5;j++)
        {
            if(randomdizi[i]>randomdizi[j])
            {
                temp = randomdizi[i];
                randomdizi[i] = randomdizi[j];
                randomdizi[j] = temp;
            }
        }
    }
    for(i=0;i<5;i++)               //rastgele sayilar ekrana yazdirilmasi icin dongu aciliyor.
    {
            printf("%d \t",randomdizi[i]);        //rastgele sayilar ekrana yazdiriliyor.
            if(i==4)
                printf(" + %d \t",rastgeleek); //rastgele gelen +1 sayi ekrana yazdiriliyor.
            sanstopuIstatistik[randomdizi[i]-1][1]++;    //rastgele gelen +1 sayinin dizideki yeri 1 arttiriliyor.

        for(j=i+1;j<5;j++)
        {
            if(tahmindizi[i]>tahmindizi[j])
            {
                temp = tahmindizi[i];
                tahmindizi[i] = tahmindizi[j];
                tahmindizi[j] = temp;
            }
        }
    }
    printf("\n\n   --Sizin Secimleriniz--  \n");
    printf("\n");
    for(i=0;i<5;i++)             //kullanicidan alinan sayilar ekrana yazdirilmasi icin dongu aciliyor.
    {
        printf("%d \t",tahmindizi[i]);      //kullanicidan alinan sayilar ekrana yazdiriliyor.
        if(i==4)
            printf(" + %d \t", tahminek);     //kullanicidan alinan +1 sayi ekrana yazdiriliyor.
    }
    printf("\n");

    switch(kacttuttu)      //tutan sayi icin puan eklemesi yapiliyor ek sayiya gorede puan eklemesi yapiliyor.
    {
    case 1:
        if(tuttuek ==1)
        {
            puan+=2;
        }
         break;
    case 2:
        if(tuttuek ==1)
        {
            puan+=4;
        }
        break;
    case 3:
        if(tuttuek ==1)
        {
            puan+=16;
        }
        puan+=8;
        break;
    case 4:
        if(tuttuek ==1)
        {
            puan+=64;
        }
        puan+=32;
        break;
    case 5:
        if(tuttuek ==1)
        {
            puan+=256;
        }
        puan+=128;
        break;
    default:
        break;
    }
    toplampuan +=puan;
    printf("\n");
    printf("Dogru Tahmin Sayisi = %d \n", kacttuttu);
    printf("Bu Oyunda Kazandiginiz Puan = %d \n", puan);
    printf("Toplam Puaniniz  = %d \n",toplampuan);
    printf("Yeni Oyun Oynamak Ister Misiniz ? ... \n");
    printf("Evet ise 'e/E', Hayir ise 'h/H' ... Lutfen Seciminizi Yapiniz \n");

    do
    {
       scanf("%c",&yenioyun);
       if(yenioyun=='e' || yenioyun=='E')
       {
            printf("\n");
            printf("Yeni Oyun Baslatiliyor \n");
            printf("Lutfen 2 Saniye Bekleyiniz \n");
            Sleep(2000);
            system("cls");
            sanstopu();
       }
       else if(yenioyun=='h' || yenioyun=='H')
       {
            printf("\n");
            printf("Sans Oyunlari Alt Menusune Geri Donuluyor \n");
            printf("Lutfen Bekleyiniz \n");
            Sleep(2000);
            system("cls");
            sansoyunlarialtmenusu();
       }
    }
    while(yenioyun!='e' || yenioyun!='E' || yenioyun!='h' || yenioyun!='H');
    return 0;
}


istatistikler()         //istatistikler fonksiyon blogu
{

    printf("  --ISTATISTIKLER--  \n");
    printf("\n");

    int i,j;
    if(sayisallotooyun == 0) //sayisal loto oynanmadý ise
    {
        printf("\n");
        printf("-Sayisal Loto Oynanmamistir-\n");
        printf("\n");
    }
    else   //eger oynandi ise
    {
        printf("-Sayisal Lotoda En Cok Cikan 6 Sayi- \t  -Cikma Sayisi-\n");
        for(i=0;i<49;i++)  //1-49 sayi araliginda en con cikan sayilari ve cikma sayilarini ekrana yazdirmak icin olusturulan for.
        {
        for(j=0;j<48;j++)
        {
            if( sayisallotoIstatistik[j][1] <  sayisallotoIstatistik[j+1][1] ) //Eger sayisallotoistatistik dizinin [j][1]inci degeri ayni dizinin [j+1][1]inci degerinden kucuk ise
            {
                int gecici;
                gecici =  sayisallotoIstatistik[j][1]; //sayisallotoistatistik dizisinin [j][1] inci degeri gecici adli degiskene atiliyor.
                sayisallotoIstatistik[j][1] =  sayisallotoIstatistik[j+1][1]; //sayisallotoistatistik dizisinin [j][1]inci degerine ayni dizinin [j+1][1]inci degeri ataniyor
                sayisallotoIstatistik[j+1][1] =  gecici;  // sayisallotoistatistik dizisinin [j+][1] inci degerine gecici degiskenindeki deger ataniyor.
                gecici =  sayisallotoIstatistik[j][0];//sayisallotoistatistik dizisinin [j][0] inci degeri gecici adli degiskene atiliyor.
                sayisallotoIstatistik[j][0] =  sayisallotoIstatistik[j+1][0]; //sayisallotoistatistik dizisinin [j][0] inci degerine ayni dizinin [j+1][0] inci degeri ataniyor.
                sayisallotoIstatistik[j+1][0] = gecici;  //sayisallotoistatistik dizisinin [j+1][0] inci degerine gecici degiskenindeki deger ataniyor.
            }
        }
    }
    for(i=0;i<49;i++)
    {
         if( sayisallotoIstatistik[i][1] != 0) //eger sayisallotoistatistik dizisinin [i][1]inci degeri 0 dan farkli ise
    {
        printf("\t\t%d\t\t\t\t%d\n", sayisallotoIstatistik[i][0], sayisallotoIstatistik[i][1]); //sayisallotoistatistik [i][0] inci degeri ve ayni dizinin [i][1]inci degeri yan yana aralarinda bosluk olmak uzere ekrana yazdiriliyor.
    }
    }
            printf("\n");
    printf("\n");
    }
    if(sanstopuoyun == 0)
    {
        printf("\n");
        printf("-Sans Topu Oynanmamistir-\n");
        printf("\n");
    }
    else
    {
        printf("-Sans Topunda En Cok Cikan 5 Sayi- \t  -Cikma Sayisi-\n");
        for(i=0;i<34;i++)
        {
        for(j=0;j<33;j++)
        {
            if( sanstopuIstatistik[j][1] <  sanstopuIstatistik[j+1][1] )
            {
                int gecici;
                gecici =  sanstopuIstatistik[j][1];
                sanstopuIstatistik[j][1] =  sanstopuIstatistik[j+1][1];
                sanstopuIstatistik[j+1][1] =  gecici;
                gecici =  sanstopuIstatistik[j][0];
                sanstopuIstatistik[j][0] =  sanstopuIstatistik[j+1][0];
                sanstopuIstatistik[j+1][0] = gecici;
            }
        }
        }
    for(i=0;i<34;i++)
        if( sanstopuIstatistik[i][1] != 0)
        printf("\t\t%d\t\t\t\t%d\n", sanstopuIstatistik[i][0], sanstopuIstatistik[i][1]);
         printf("\n -Sans Topunda En Cok Cikan +1 Sayi- \t  -Cikma Sayisi-\n");
        for(i=0;i<14;i++)//Sanstopuekistatistik dizisi (oyunun +1 degeri icin acilmis dizi)icin acilmis dongu
        {
        for(j=0;j<13;j++)
        {
            if(sanstopuEkIstatistik[j][1] <  sanstopuEkIstatistik[j+1][1])  //sanstopuEkIstatistik dizisinin [j][1] inci degeri ayni dizinin [j+1][1] inci degerinden kucuk ise
            {
                int gecici;
                gecici =  sanstopuEkIstatistik[j][1]; //sanstopuEkIstatistik dizinin [j][1] inci degeri gecici degiskennine ataniyor
                sanstopuEkIstatistik[j][1] =  sanstopuEkIstatistik[j+1][1]; //sanstopuEkIstatistik dizisinin [j][1]inci degerşne ayni dizinin [j+1][1]inci degeri ataniyor.
                sanstopuEkIstatistik[j+1][1] =  gecici;//gecicideki deger sanstopuEkIstatistik dizisinin[j+1][1]inci degerine ataniyor
                gecici =  sanstopuEkIstatistik[j][0];//gecici degiskenine sanstopuEkIstatistik dizisinin [j][0] inci degeri ataniyor
                sanstopuEkIstatistik[j][0] =  sanstopuEkIstatistik[j+1][0];//sanstopuEkIstatistik[j+1][0] degeri sanstopuEkIstatistik[j][0] degerine ataniyot
                sanstopuEkIstatistik[j+1][0] = gecici; //gecici degiskenindeki deger sanstopuEkIstatistik[j+1][0] e ataniyor.
            }
         }
        }
    for(i=0;i<14;i++)
    {
        if(i>2)
        {
            if(sanstopuEkIstatistik[i][1] != sanstopuEkIstatistik[i+1][1])
            break;
        }
        if( sanstopuEkIstatistik[i][1] != 0) //Eksayi 0 a esit degil ise
                printf("\t\t%d\t\t\t\t%d\n", sanstopuEkIstatistik[i][0], sanstopuEkIstatistik[i][1]);//tahminedilen ek sayi ile rastgele gelen ek sayinin ekrana yazdirilmasi
    }
    printf("\n");

    printf("\n");
    }
     if(onnumaraoyun == 0)
    {
        printf("\n");
        printf("-On Numara Oynanmamistir-\n");
        printf("\n");
    }
    else
    {
        printf("-On Numarada En Cok Cikan 22 Sayi-\t  -Cikma Sayisi-\n");
        for(i=0;i<80;i++)
        {
        for(j=0;j<79;j++)
        {
            if( onnumaraIstatistik[j][1] <  onnumaraIstatistik[j+1][1] )
            {
                int gecici;
                gecici =  onnumaraIstatistik[j][1];
                onnumaraIstatistik[j][1] =  onnumaraIstatistik[j+1][1];
                onnumaraIstatistik[j+1][1] =  gecici;
                gecici =  onnumaraIstatistik[j][0];
                onnumaraIstatistik[j][0] =  onnumaraIstatistik[j+1][0];
                onnumaraIstatistik[j+1][0] = gecici;
            }
        }
    }
    for(i=0;i<80;i++)
    {
        if(i>22)
        if(onnumaraIstatistik[22][1] != onnumaraIstatistik[i][1])
            break;
        if( onnumaraIstatistik[i][1] != 0)
        printf("\t\t%d\t\t\t\t%d\n", onnumaraIstatistik[i][0], onnumaraIstatistik[i][1]);
    }
            printf("\n");
    printf("\n");
    }

    if(superlotooyun == 0)
    {
        printf("\n");
        printf("-Super Loto Oynanmamistir-\n");
        printf("\n");
    }
    else
    {
        printf("-Super Lotoda En Cok Cikan 6 Sayi- \t  -Cikma Sayisi-\n");
        for(i=0;i<54;i++)
        {
        for(j=0;j<53;j++)
        {
            if( superlotoIstatistik[j][1] <  superlotoIstatistik[j+1][1] )
            {
                int gecici;
                gecici =  superlotoIstatistik[j][1];
                superlotoIstatistik[j][1] =  superlotoIstatistik[j+1][1];
                superlotoIstatistik[j+1][1] =  gecici;
                gecici =  superlotoIstatistik[j][0];
                superlotoIstatistik[j][0] =  superlotoIstatistik[j+1][0];
               superlotoIstatistik[j+1][0] = gecici;
            }
        }
    }
    }
    for(i=0;i<54;i++)
    {
        if(i>22)
        if(superlotoIstatistik[22][1] != superlotoIstatistik[i][1])
            break;
                   if( superlotoIstatistik[i][1] != 0)
        printf("\t\t%d\t\t\t\t%d\n", superlotoIstatistik[i][0], superlotoIstatistik[i][1]);
    }

            printf("\n");
    printf("\n");

    if(sayisallotooyun == 0  && sanstopuoyun ==0 && onnumaraoyun ==0 && superlotooyun ==0)
    {
        printf("\n");
        printf("Oyunlardan Herhangi Biri Oynanmamis \n");
        printf("2 Saniye Icerisinde Ana Menuye Donuluyor \n");
        printf("\n");
        Sleep(2000);
        system("cls");
        anamenu();
        return 0;
    }
    anamenu();
    return 0;
}
