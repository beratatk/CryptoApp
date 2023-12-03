#include<iostream>
using namespace std;

class Hesap{
    public:
        int hesapKriptoBakiye,hesapBakiye;
        string hesapId;

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
    int kriptoTlEder = 1; // 1kripto = 1tl
    int kullanici_girdi,kullanici_yatirim_miktar;
    string kullanici_hesap_no;
    
    int gun=1,ay=1,yil=2000;

    
    Hesap hesapList[100];
    int i = 0;
    while (true)
{   
    
    cout<<endl;
    cout<<"1-Genel Hesap aç\n";
    cout<<"2-Özel Hesap aç\n";
    cout<<"3-Hesaba para ekle\n";
    cout<<"4-Hesaptan para çek\n";
    cout<<"5-Tarihi göster / düzenle\n";
    cout<<"6-Açılan tüm hesapları listele\n";
    cout<<"7-Uygulamayı sonlandır.\n";
    cout<<"-------------------------------------"<<endl;
    cin >> kullanici_girdi;

    if (kullanici_girdi==1)
    {   
        
        cout<<"Genel hesap açmayı seçtiniz...\n";
        cout<<"Hesap no giriniz:";  
        cin>>kullanici_hesap_no;
        cout<<"Yatıracağınız miktari giriniz:";
        cin>>kullanici_yatirim_miktar;
        hesapList[i].hesapId = kullanici_hesap_no;
        hesapList[i].hesapBakiye=kullanici_yatirim_miktar;
        i=i+1;
    }
    else if (kullanici_girdi==5)
    {
        cout<<"Sistem tarihi:"<<gun<<"."<<ay<<"."<<yil<<endl;
        cout<<"Ana menü için herhangi bir tuşu , tarihi değiştirmek için 0'ı tuşlayın...."<<endl;
        cin>>kullanici_girdi;
        if (kullanici_girdi==0)
        {
           cout<<"Tarih değiştirmeyi seçtiniz, yeni tarihi giriniz...\nGün:";
           cin>>gun;
           cout<<"Ay:";
           cin>>ay;
           cout<<"Yıl:";
           cin>>yil;
        }
        
    }
    else if (kullanici_girdi==6)
    {
        cout<<"Mevcut hesaplar:\n";
        for (int z = 0; z < i; z++)
        {   
            
            cout<<"Hesap ID:"<<hesapList[z].hesapId<<" Bakiye:"<<hesapList[z].hesapBakiye<<endl;
        }
        
    }
    
    else if (kullanici_girdi==7)
    {
        break;
    }


}
    


    //return 0;
}



