#include <iostream>     //std::cout, std::cerr
#include <stdexcept>    //std::invalid_argument
#include <string>
#include "BCD.h"
using namespace std;

int main()
{
    /*BCD b1(3);
    BCD b2;
    b2.dec_to_bcd(97297297297);
    BCD b7;
    b7.dec_to_bcd(10000097296);
    cout<<b7<<endl;
    long long int szam=b2.bcd_to_dec();
    cout<<b2<<endl;
    cout<<szam<<endl;
    for(int i=0;i<4;i++)b1[i]=1;
    cout<<b1<<endl;
    int t[8]={0, 1, 1, 0, 1, 0, 0, 0};
    BCD b3(t, 2);
    cout<<b3<<endl;
    cout<<b3.bcd_to_dec()<<endl;
    BCD b4;
    b4.dec_to_bcd(973);
    cout<<b4<<endl;         //dec// 973  BCD:1001 0111 0011
    BCD b5;
    b5.dec_to_bcd(27);
    cout<<b5<<endl;         //dec:  27   BCD:0010 0111
    BCD b6;
    b6.dec_to_bcd(73);      //dec:  73   BCD:0111 0011
    cout<<b6<<endl;
    cout<<b4+b5<<endl;      //dec:1000   BCD:0001 0000 0000 0000
    cout<<b4+27<<endl;      //dec:1000   BCD:0001 0000 0000 0000
    cout<<127+b4<<endl;     //dec:1100   BCD:0001 0001 0000 0000
    cout<<b4-b6<<endl;      //dec: 900   BCD:1001 0000 0000
    cout<<b4-73<<endl;      //dec: 900   BCD:1001 0000 0000
    cout<<1127-b5<<endl;    //dec:1100   BCD:0001 0001 0000 0000
    BCD b8=b4;
    cout<<endl<<b8<<endl;   //dec: 973   BCD:1001 0111 0011
    b8+=27;
    cout<<b8<<endl;         //dec:1000   BCD:0001 0000 0000 0000
    b8+=b5;
    cout<<b8<<endl;         //dec:1027   BCD:0001 0000 0010 0111
    b8-=b5;
    cout<<b8<<endl;         //dec:1000   BCD:0001 0000 0000 0000
    b8-=27;
    cout<<b8<<endl;         //dec: 973   BCD:1001 0111 0011
    long long int valami=29;
    valami+=b8;
    cout<<valami<<endl;     //dec:1002
    valami-=b8;
    cout<<valami<<endl;     //dec:  29
    cout<<endl;
    cout<<"b8: "<<b8.bcd_to_dec()<<", b5: "<<b5.bcd_to_dec()<<endl;
    if(b5==b8)cout<<"b8 es b5 egyenlok!"<<endl;
    else cout<<"b8 es b5 nem egyenlok!"<<endl; //b8 nem egyenlo b5 -> jol mukodik az operator;
    if(b5==27)cout<<"b5 egyenlo 27-tel!"<<endl; //b5 egyenlo 27 -> jol mukodik az operator;
    else cout<<"b5 nem egyenlo 27-tel!"<<endl;
    if(26==b5)cout<<"b5 egyenlo 26-tel!"<<endl;
    else cout<<"b5 nem egyenlo 26-tal!"<<endl;  //b5 egyenlo 27 -> jol mukodik az operator;
    if(b5!=b8)cout<<"Rendben van, a ketto lathatoan nem egyenlo"<<endl;
    else cout<<"Hibas az operator!"<<endl;
    if(b5!=28)cout<<"b5 valoban nem egyenlo 28-cal"<<endl;
    else cout<<"b5 rendben van!"<<endl;
    if(27!=b5)cout<<"b5!=27"<<endl;
    else cout<<"b5==27"<<endl;
    if(b8>=1000)cout<<"Kiralysag"<<endl;
    else cout<<"Szopacs"<<endl;
    cout<<endl;
    cout<<"DEC: "<<b8.bcd_to_dec()<<"   BCD: "<<b8<<endl;      //dec: 973   BCD:1001 0111 0011
    ++b8;
    cout<<"DEC: "<<b8.bcd_to_dec()<<"   BCD: "<<b8<<endl;      //dec: 974   BCD:1001 0111 0100
    --b8;
    cout<<"DEC: "<<b8.bcd_to_dec()<<"   BCD: "<<b8<<endl;      //dec: 973   BCD:1001 0111 0011
    b8++;
    cout<<"DEC: "<<b8.bcd_to_dec()<<"   BCD: "<<b8<<endl;      //dec: 974   BCD:1001 0111 0100
    b8--;
    cout<<"DEC: "<<b8.bcd_to_dec()<<"   BCD: "<<b8<<endl;      //dec: 973   BCD:1001 0111 0011
    cout<<endl;
    cout<<b8/b5<<endl;      //dec: 36   BCD:0011 0110
    cout<<b5/3<<endl;
    cout<<b2/97297297297<<endl;
    cout<<b5/4.5<<endl;
    cout<<97297297297/b2<<endl;
    cout<<b8%b5<<endl;
    cout<<b5%4<<endl;
    cout<<endl;
    b8/=b5;
    cout<<b8<<endl;
    b8.dec_to_bcd(973191919);
    long long int valami2=270;
    cout<<valami2<<endl;
    valami2/=b5;
    cout<<valami2<<endl;*/
    /*BCD b9, b10;
    b9.dec_to_bcd(198919191);
    b10=b8*b9;
    cout<<b10<<endl;*/

    cout<< "Udvozollek a programomban!"<<endl;
    cout<< "Ez a program nem masra valo, minthogy elvegezzen bizonyos muveleteket a BCD szamok halmazan!"<<endl;
    cout<< "Tehat lenyegeben egy szamologepet szimulal."<<endl;

    cout<< "Most pedig adja meg, hogy milyen formaban akarja beírni a bal oldali BCD szamot:"<<endl;
    cout<< "1. Egesz szamkent"<<endl;
    cout<< "2. BCD-kent"<<endl;

    BCD b1, b2;
    char valasz;
    cin>>valasz;
    try{
    switch(valasz){
    case '1':
        cout<<"Kerem a szamot: ";
        long long int szam;
        cin>>szam;
        b1.dec_to_bcd(szam);
        break;
    case '2':
        cout<<"Adja meg a szamjegyek szamat, majd a szamot BCD formaban: ";
        cin>>b1;
        break;
    }
    cout<<b1<<endl;

    cout<< "Most pedig adja meg, hogy milyen formaban akarja beírni a jobb oldali BCD szamot:"<<endl;
    cout<< "1. Egesz szamkent"<<endl;
    cout<< "2. BCD-kent"<<endl;

    cin>>valasz;
    switch(valasz){
    case '1':
        cout<<"Kerem a szamot: ";
        long long int szam;
        cin>>szam;
        b2.dec_to_bcd(szam);
        break;
    case '2':
        cout<<"Adja meg a szamjegyek szamat, majd a szamot BCD formaban: ";
        cin>>b2;
        break;
    }
    cout<<b2<<endl;

    cout<<"Valassza ki, hogy milyen muveletet szeretne megvalositani a ket adat kozott: "<<endl;
    cout<<"1. Osszeadas: +"<<endl;
    cout<<"2. Kivonas: -"<<endl;
    cout<<"3. Egyenloseg vizsgalata: =="<<endl;
    cout<<"4. Egyenlotlenseg vizsgalata: !="<<endl;
    cout<<"5. Adatok kozotti relacia vizsgalata: <"<<endl;
    cout<<"6. Adatok kozotti relacia vizsgalata: >"<<endl;
    cout<<"7. Adatok kozotti relacia vizsgalata: <="<<endl;
    cout<<"8. Adatok kozotti relacia vizsgalata: >="<<endl;
    cout<<"9. ++, mint prefix: ++BCD"<<endl;
    cout<<"10. ++, mint postfix: BCD++"<<endl;
    cout<<"11. --, mint prefix: --BCD"<<endl;
    cout<<"12. --, mint postfix: BCD--"<<endl;
    cout<<"13. Egesz osztas: /"<<endl;
    cout<<"14. Maradekos osztas: %"<<endl;
    int valasz2;
    cin>>valasz2;
    while(valasz2!=-1){
    switch(valasz2){
        case 1:
            cout<<"A ket adat osszege!"<<endl;
            cout<<"DEC: "<<(b1+b2).bcd_to_dec()<<" BCD: "<<b1+b2<<endl;
            break;
        case 2:
            cout<<"A ket adat kulonbsege!"<<endl;
            cout<<"DEC: "<<(b1-b2).bcd_to_dec()<<" BCD: "<<b1-b2<<endl;
            break;
        case 3:
            if(b1==b2)cout<<"A ket adat egyenlo!"<<endl;
            else cout<<"A ket adat nem egyenlo!"<<endl;
            break;
        case 4:
            if(b1!=b2)cout<<"A ket adat nem egyenlo!"<<endl;
            else cout<<"A ket adat egyenlo!"<<endl;
            break;
        case 5:
            if(b1<b2)cout<<"Az elso adat kisebb mint a masodik!"<<endl;
            else if(b1==b2)cout<<"A ket adat egyenlo!"<<endl;
            else cout<<"A masodik adat a kisebb!"<<endl;
            break;
        case 6:
            if(b1>b2)cout<<"Az elso adat nagyobb mint a masodik!"<<endl;
            else if(b1==b2)cout<<"A ket adat egyenlo!"<<endl;
            else cout<<"A masodik adat a nagyobb!"<<endl;
            break;
        case 7:
            if(b1<=b2)cout<<"Az elso adat kisebb-egyenlo mint a masodik!"<<endl;
            else cout<<"A masodik adat a kisebb!"<<endl;
            break;
        case 8:
            if(b1>=b2)cout<<"Az elso adat nagyobb-egyenlo mint a masodik!"<<endl;
            else cout<<"A masodik adat a nagyobb!"<<endl;
            break;
        case 9:
            cout<<"A kapott eredmeny! Mindket adatra elvegezve"<<endl;
            ++b1; ++b2;
            cout<<"DEC: "<<b1.bcd_to_dec()<<" BCD: "<<b1<<endl;
            cout<<"DEC: "<<b2.bcd_to_dec()<<" BCD: "<<b2<<endl;
            --b1; --b2;//hogy visszakapjuk az eredeti ertekeiket
            break;
        case 10:
            cout<<"A kapott eredmeny! Mindket adatra elvegezve"<<endl;
            b1++; b2++;
            cout<<"DEC: "<<b1.bcd_to_dec()<<" BCD: "<<b1<<endl;
            cout<<"DEC: "<<b2.bcd_to_dec()<<" BCD: "<<b2<<endl;
            --b1; --b2;//hogy visszakapjuk az eredeti ertekeiket
            break;
        case 11:
            cout<<"A kapott eredmeny! Mindket adatra elvegezve"<<endl;
            --b1; --b2;
            cout<<"DEC: "<<b1.bcd_to_dec()<<" BCD: "<<b1<<endl;
            cout<<"DEC: "<<b2.bcd_to_dec()<<" BCD: "<<b2<<endl;
            ++b1; ++b2;//hogy visszakapjuk az eredeti ertekeiket
            break;
        case 12:
            cout<<"A kapott eredmeny! Mindket adatra elvegezve"<<endl;
            b1--; b2--;
            cout<<"DEC: "<<b1.bcd_to_dec()<<" BCD: "<<b1<<endl;
            cout<<"DEC: "<<b2.bcd_to_dec()<<" BCD: "<<b2<<endl;
            ++b1; ++b2;//hogy visszakapjuk az eredeti ertekeiket
            break;
        case 13:
            cout<<"A kapott eredmeny!"<<endl;
            cout<<"DEC: "<<(b1/b2).bcd_to_dec()<<" BCD: "<<b1/b2<<endl;
            break;
        case 14:
            cout<<"A kapott eredmeny!"<<endl;
            cout<<"DEC: "<<(b1%b2).bcd_to_dec()<<" BCD: "<<b1%b2<<endl;
            break;
        }
        cin>>valasz2;
    }
    }
    catch(const std::invalid_argument& ia){
            cerr << " Invalid argument: "<<ia.what()<<endl;
    }

    return 0;
}
