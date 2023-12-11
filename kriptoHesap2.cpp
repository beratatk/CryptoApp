#include<iostream>
using namespace std;

class Hesap{
    public:
        
        float hesapBakiye; //hesapBakiye = hesabin tl bakiyesi
        float hesapKriptoBakiye; //hesapKriptoBakiye hesabin kripto bakiyesi
        string hesapId,hesapTur;

        float kriptoParaAl(float kriptoParaAlmaMiktari){
            hesapKriptoBakiye +=kriptoParaAlmaMiktari;
            cout<<"Hesabınıza "<<kriptoParaAlmaMiktari<<" adet kripto eklendi..."<<endl;
            return hesapKriptoBakiye;
        }

        float kriptoParaSat(float kriptoParaSatmaMiktari){
            hesapKriptoBakiye -=kriptoParaSatmaMiktari;
            cout<<"Hesabınızdan "<<kriptoParaSatmaMiktari<<" adet kripto eksildi..."<<endl;
            return hesapKriptoBakiye;
        }

        void bakiyeGoster(string hesapId,int hesapBakiye){
            cout<<"Hesap ID:"<<hesapId<<endl;
            cout<<"Anlık bakiye:"<<hesapBakiye<<endl;
        }
        void karGoster(int hesapToplamKar){
            cout<<"Hesabınızın toplam karı:"<<hesapToplamKar;
        }
};

int main(){
    srand(time(NULL));
    float kriptoGenelTlEder = 1; // 1kripto = 1tl
    float kriptoOzelTlEder = 1;
    int kullanici_girdi;
    float kullanici_yatirim_miktar;
    string kullanici_hesap_no;
    
    int gun=1,ay=1,yil=2000;
    int gun2,ay2,yil2;
    
    Hesap hesapList[1000];//hesap olusturma sinirimiz 1000 adettir burdan degistirebiliriz.
    Hesap hesap; 
    int i = 0;
    while (true)
{   
    
    cout<<endl;
    cout<<"1-Genel Hesap aç\n";//gunluk %1 artis, 15 gunde bir %5 dusus
    cout<<"2-Özel Hesap aç\n";//gunluk %5 artis, 1 ayda rastgele 3 gunde %10 dusus
    cout<<"3-Hesaba para ekle\n";
    cout<<"4-Hesaptan para çek\n";
    cout<<"5-Tarihi göster / düzenle\n";
    cout<<"6-Açılan tüm hesapları listele\n";
    cout<<"7-Kripto para satin al\n";
    cout<<"8-Kripto para sat\n";
    cout<<"9-Hesap bakiye sorgula\n";
    cout<<"10-Hesap karini goster\n";
    cout<<"11-Uygulamayı sonlandır.\n";
    cout<<"-------------------------------------"<<endl;
    cin >> kullanici_girdi;

    if (kullanici_girdi==1)
    {   
        
        cout<<"Genel hesap açmayı seçtiniz...\n";
        cout<<"Hesap no giriniz:";  
        cin>>kullanici_hesap_no;
        cout<<"Yatıracağınız miktari giriniz(TL):";
        cin>>kullanici_yatirim_miktar;
        hesapList[i].hesapId = kullanici_hesap_no;
        hesapList[i].hesapBakiye=kullanici_yatirim_miktar;
        hesapList[i].hesapTur="Genel hesap";

        i=i+1;
    }

    else if (kullanici_girdi==2)
    {
        cout<<"Ozel hesap açmayı seçtiniz...\n";
        cout<<"Hesap no giriniz:";  
        cin>>kullanici_hesap_no;
        cout<<"Yatıracağınız miktari giriniz(TL):";
        cin>>kullanici_yatirim_miktar;
        hesapList[i].hesapId = kullanici_hesap_no;
        hesapList[i].hesapBakiye=kullanici_yatirim_miktar;
        hesapList[i].hesapTur="Ozel hesap";
        i=i+1;
    }
    
    else if (kullanici_girdi==3)
    {   
       int hesapParaEklemeSecim;
       float hesapParaEklemeMiktar;
       cout<<"Hesaba para ekleme islemini sectiniz...\n";
        
        for (int z = 0; z < i; z++)
        {   
            cout<<z<<"-Hesap ID:"<<hesapList[z].hesapId<<" Bakiye:"<<hesapList[z].hesapBakiye<<endl;
        }
       cout<<"Hesap seciniz...";
       cin>>hesapParaEklemeSecim;
       cout<<"Eklenecek tutari girin(TL):";
       cin>>hesapParaEklemeMiktar;
       hesapList[hesapParaEklemeSecim].hesapBakiye+=hesapParaEklemeMiktar;
       cout<<"Isleminiz basarili bir sekilde gerceklestirilmistir";
    }
    
    else if (kullanici_girdi==4)
    {
       int hesapParaCekmeSecim;
       float hesapParaCekmeMiktar;
       cout<<"Hesaptan para cekme islemini sectiniz...\n";
        
        for (int z = 0; z < i; z++)
        {   
            cout<<z<<"-Hesap ID:"<<hesapList[z].hesapId<<" Bakiye:"<<hesapList[z].hesapBakiye<<endl;
        }
       cout<<"Hesap seciniz...";
       cin>>hesapParaCekmeSecim;
       cout<<"Cekilecek tutari girin(TL):";
       cin>>hesapParaCekmeMiktar;
       if (hesapParaCekmeMiktar>hesapList[hesapParaCekmeSecim].hesapBakiye)
       {
        cout<<"Yetersiz bakiye!...\n";
       }
       else
       hesapList[hesapParaCekmeSecim].hesapBakiye-=hesapParaCekmeMiktar;
       cout<<"Isleminiz basarili bir sekilde gerceklestirilmistir";
       
    }
    

    else if (kullanici_girdi==5)
    {   
        int totalGun=0;
        cout<<"Sistem tarihi:"<<gun<<"."<<ay<<"."<<yil<<endl;
        cout<<"Ana menü için herhangi bir tuşu , tarihi değiştirmek için 0'ı tuşlayın...."<<endl;
        cin>>kullanici_girdi;
        if (kullanici_girdi==0)
        {
           cout<<"Tarih değiştirmeyi seçtiniz, yeni tarihi giriniz...\nGün:";
           cin>>gun2;
           cout<<"Ay:";
           cin>>ay2;
           cout<<"Yıl:";
           cin>>yil2;
        
           totalGun = abs(gun2-gun)+abs((ay2-ay)*30)+abs((yil2-yil)*365);

           gun = gun2;
           ay = ay2;
           yil = yil2;

           int aylikPeriyod = totalGun/30, aylikPeriyod2=aylikPeriyod*3;//her aylik periyotta rastgele 3 gun olacagi icin 
           int randomGun,randomGun2,randomGun3;
           int randomList[aylikPeriyod2],z=0; //burdaki zyi listeye ekleme isleminde kullancagiz
           
           for (int i = 0; i < aylikPeriyod; i++)//her 30 gunluk periyotlar icin rastgele 3 gun sectik ve o gunleri bi listeye ekledik
           {
            randomGun = rand()%30;
            randomList[z]=randomGun;
            z++;
            randomGun2 = rand()%30;
            randomList[z]=randomGun2;
            z++;
            randomGun3 = rand()%30;
            randomList[z]=randomGun3;
            z++;
            cout<<randomGun<<endl;
            cout<<randomGun2<<endl;
            cout<<randomGun3<<endl;//test etmek icin yazdirdim, bazen ayni sayilar seciliyor bu yuzden 3 farkli gun olmayabiliyor bunu cozecek fonksyion dusunulmeli
           }

           for (int i = 0; i < totalGun ; i++)//gunluk artis dongusu
           {
            kriptoGenelTlEder += kriptoGenelTlEder*1/100;//genel hesap gunluk %1artis sagliyor,her kosulda artacagi icin en basa yaziyoruz
            for (int j = 0; j < aylikPeriyod2; j++)//o gun rastgele gun mu diye kontrol etmek icin bu donguyu kullanacagiz
            {
                if (i==randomList[j])
                {
                kriptoOzelTlEder -= kriptoOzelTlEder*10/100;
                cout<<"Rastgele gunler "<<i<<endl;//test etmek icin yazdirdim
                }
            }
            kriptoOzelTlEder += kriptoOzelTlEder*5/100;// her gun %5 artiyor fakat dusus gunlerinde de artiyor , projede her gun artacagi belirtilmis, eger dusus gunleri artmayacak ise duzeltilmeli
            cout<<"normal gun: "<<i<<endl;  
           }
           for (int i = 0; i < totalGun/15; i++)//her 15 gunde bir genel hesap %5 deger kaybediyor
           {
            kriptoGenelTlEder -= kriptoGenelTlEder*5/100;
           }
           cout<<"Genel hesap kripto eder:"<<kriptoGenelTlEder<<endl<<"Ozel hesap kripto eder:"<<kriptoOzelTlEder<<endl;
        }   
    }

    else if (kullanici_girdi==6)
    {
        cout<<"Mevcut hesaplar:\n";
        for (int z = 0; z < i; z++)
        {   
            
            cout<<z<<"-Hesap ID:"<<hesapList[z].hesapId<<" / Hesap turu:"<<hesapList[z].hesapTur<<" / Bakiye:"<<hesapList[z].hesapBakiye<<endl;
        }
        
    }
    
    else if (kullanici_girdi==7)
    {   
        int kullaniciKriptoAlGirdi;
        cout<<"Kripto para alma islemini sectiniz, lutfen listeden bir hesap seciniz...."<<endl;
        for (int z = 0; z < i; z++)
        {   
            cout<<z<<"-Hesap ID:"<<hesapList[z].hesapId<<" / Bakiye:"<<hesapList[z].hesapBakiye<<" / Kripto bakiye:"<<hesapList[z].hesapKriptoBakiye<<endl;
        }
        cin>>kullaniciKriptoAlGirdi;
        if (hesapList[kullaniciKriptoAlGirdi].hesapTur=="Genel hesap")
        {   
            float bakiyeKriptoDonusumu = hesapList[kullaniciKriptoAlGirdi].hesapBakiye/kriptoGenelTlEder; // mevcut bakiyenin kac kripto edecegi hesaplandi
            float KriptoBakiyeDonusumu = bakiyeKriptoDonusumu*kriptoGenelTlEder; // alinan kriptolarin tl karsiligi 

            hesapList[kullaniciKriptoAlGirdi].hesapKriptoBakiye = hesap.kriptoParaAl(bakiyeKriptoDonusumu);// alinan kriptolar eklendi
            hesapList[kullaniciKriptoAlGirdi].hesapBakiye -= KriptoBakiyeDonusumu;// alim sirasinda harcanan tl cikarildi

            cout<<"Hesabinizdaki bakiye kripto paraya cevrildi"<<endl; 
        }
        else if (hesapList[kullaniciKriptoAlGirdi].hesapTur=="Ozel hesap")
        {
            float bakiyeKriptoDonusumu = hesapList[kullaniciKriptoAlGirdi].hesapBakiye/kriptoOzelTlEder; // mevcut bakiyenin kac kripto edecegi hesaplandi
            float KriptoBakiyeDonusumu = bakiyeKriptoDonusumu*kriptoOzelTlEder; // alinan kriptolarin tl karsiligi 

            hesapList[kullaniciKriptoAlGirdi].hesapKriptoBakiye = hesap.kriptoParaAl(bakiyeKriptoDonusumu);// alinan kriptolar eklendi
            hesapList[kullaniciKriptoAlGirdi].hesapBakiye -= KriptoBakiyeDonusumu;// alim sirasinda harcanan tl cikarildi

            cout<<"Hesabinizdaki bakiye kripto paraya cevrildi"<<endl;             
        }

    }   
    
    else if (kullanici_girdi==8)
    {
        int kullaniciKriptoSatGirdi;
        float kullaniciKriptoSatMiktar;

        cout<<"Kripto para satma islemini sectiniz, lutfen listeden bir hesap seciniz...."<<endl;
        for (int z = 0; z < i; z++)
        {   
            cout<<z<<"-Hesap ID:"<<hesapList[z].hesapId<<" / Bakiye:"<<hesapList[z].hesapBakiye<<" / Kripto bakiye:"<<hesapList[z].hesapKriptoBakiye<<endl;
        }
        cin>>kullaniciKriptoSatGirdi;
        cout<<"Ne kadar kripto satmak istiyorsunuz:"<<endl;
        cin>>kullaniciKriptoSatMiktar;//kod asamsinda buradan itibaren 

        if (kullaniciKriptoSatMiktar>hesapList[kullaniciKriptoSatGirdi].hesapKriptoBakiye)
        {
            cout<<"Yetersiz bakiye!..."<<endl;
        }
        else
            if (hesapList[kullaniciKriptoSatGirdi].hesapTur=="Genel hesap"){

            float KriptoTLDonusumu = kullaniciKriptoSatMiktar*kriptoGenelTlEder; // satilacak olan kriptolarin tl karsiligi
            hesapList[kullaniciKriptoSatGirdi].hesapKriptoBakiye = hesap.kriptoParaSat(kullaniciKriptoSatMiktar);// satilan kriptolar cikarildi
            hesapList[kullaniciKriptoSatGirdi].hesapBakiye += KriptoTLDonusumu;// satilan kriptolarin tl cinsi bakiyeye eklendi

            cout<<kullaniciKriptoSatMiktar<<" adet kripto satildi ve bakiyeye cevrildi..."<<endl;
            }
   }
    

    else if (kullanici_girdi==11)
    {
        break;
    }


}
}
// tarihin geri alinmasini engelle toplam gun farki ile yaparsin ilk tarihin toplami yeni tarihten buyuk olamaz

// ozel hesap kripto ederinde sikinti var hep ayni deger geliyor!!
