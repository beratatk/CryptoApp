#include<iostream>
using namespace std;

class Hesap{
    public:
        float hesapKriptoBakiye; //hesapKriptoBakiye hesabin kripto bakiyesi
        float hesapBakiye; //hesapBakiye = hesabin tl bakiyesi
        string hesapId,hesapTur;

        void kriptoParaAl(int kriptoParaAlmaMiktari){
            hesapKriptoBakiye +=kriptoParaAlmaMiktari;
            cout<<"Hesabınıza "<<kriptoParaAlmaMiktari<<" adet kripto eklendi..."<<endl;
        }

        void kriptoParaSat(int kriptoParaSatmaMiktari){
            hesapKriptoBakiye -=kriptoParaSatmaMiktari;
            cout<<"Hesabınızdan "<<kriptoParaSatmaMiktari<<" adet kripto eksildi..."<<endl;
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
    float kriptoGenelTlEder = 1; // 1kripto = 1tl
    float kriptoOzelTlEder = 1;
    int kullanici_girdi;
    float kullanici_yatirim_miktar;
    string kullanici_hesap_no;
    
    int gun=1,ay=1,yil=2000;
    int gun2,ay2,yil2;
    
    Hesap hesapList[1000];//hesap olusturma sinirimiz 1000 adettir burdan degistirebiliriz.
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

           for (int i = 0; i < totalGun ; i++)
           {
            kriptoGenelTlEder += kriptoGenelTlEder*1/100;
            kriptoOzelTlEder += kriptoOzelTlEder*5/100;
           }
           for (int i = 0; i < totalGun/15; i++)
           {
            kriptoGenelTlEder -= kriptoGenelTlEder*5/100;
           }
           for (int i = 0; i < totalGun/30; i++)//rastgele gunler seciliyor fakat hesaplama sirali oldugu icin hep ayni sonuc geliyor ozel hesap birlikte hesaplanmali ayni dongu icinde
           {                                    //her ay ayni rastgele gun oluyor, projede rastgele gunlerinde degismesi istenmis!
            srand(time(NULL));
            int randomGun1 = rand()%30+1;
            int randomGun2 = rand()%30+1;
            int randomGun3 = rand()%30+1; //1 ile 30 arasi bir sayi tut
            cout<<"Random sayilar:"<<randomGun1<<" "<<randomGun2<<" "<<randomGun3;
            for (int i = 0; i < 30; i++)
            {
                if (i == randomGun1||randomGun2||randomGun3)
                {
                    kriptoOzelTlEder -= kriptoOzelTlEder*10/100;
                }
            }
            
           
            
           }
           cout<<kriptoGenelTlEder<<endl<<kriptoOzelTlEder;
           
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
    
    else if (kullanici_girdi==11)
    {
        break;
    }


}
    


    //return 0;
}



