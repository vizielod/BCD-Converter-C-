#include<iostream>
#include<cmath>
#include<stdexcept>
#include<string.h>
#include "BCD.h"
#define HOSSZ darab*4 //darab 4 szerese, mivel egy tagot 4 bitbe tarol

long long int BCD::bcd_to_dec(){
    long long int osszeg=0;
    long long int j=1;
    int szam=0;
    for(int i=HOSSZ-1;i>=0;i--){
        if(i%4==3)szam=szam+data[i]*1;
        if(i%4==2)szam=szam+data[i]*2;
        if(i%4==1)szam=szam+data[i]*4;
        if(i%4==0){
            szam=szam+data[i]*8;
            if(szam>9)
                throw std::invalid_argument("long long int BCD::bcd_to_dec(). Szamjegy nem lehet nagyobb mint 9!");
            osszeg=szam*j+osszeg;
            j=j*10;
            szam=0;
        }
    }
    return osszeg;
}


BCD& BCD::dec_to_bcd(long long int szam){
    if (szam>9999999999 || szam<0)
        throw std::invalid_argument("BCD& BCD::dec_to_bcd(long long int szam). Nagyobb mint 11 jegyu a BCD, ezek kezelesere nem alkalmas ez az osztaly");
    int *eredmeny;
    if(szam==0){
        if(data!=NULL) delete[] data;
        eredmeny=new int[4];
        for(int i=0;i<4;i++){
            eredmeny[i]=0;
        }
        darab=1;
        data=eredmeny;
        return (*this);
    }
    int db=0;
    long long int szam2=szam;
    while(szam2>0){
        db++;
        szam2=szam2/10;
    }
    int meret=4*db;
    eredmeny = new int[meret];
    int i=meret-1;
    while(szam>0 && i>=0){
        int szamjegy = szam % 10;
        for(int j=0;j<4;j++){
            eredmeny[i--]=(szamjegy & (int)pow(2, j)) >> j;
            //std::cout<<eredmeny[i+1]<<" ";
        }
        szam=szam/10;
    }
    if(data!=NULL) delete[] data;
    data=eredmeny;
    darab=meret/4;
    return *this;
}
/* konstruktor meret alapjan */
BCD::BCD(int darab):darab(darab){
    data=NULL;
    if(darab!=0){
        data=new int[HOSSZ];
        for(int i=0;i<HOSSZ;i++){
            data[i]=0;
        }
    }
}
/* konstruktor egy adattomb es meret alapjan */
BCD::BCD(int *data, int darab){
    this->darab = darab;
    this->data = new int[HOSSZ];
    for(int i=0 ;i<HOSSZ; i++){
        this->data[i] = data[i];
    }
};

/* copy/masolo konstruktor */
BCD::BCD(const BCD & rhs){
    darab=rhs.darab;
    if(rhs.data==NULL)
        data=NULL;
    else{
        data = new int[HOSSZ];
        for(size_t i=0;i<(HOSSZ);i++){
            data[i]=rhs.data[i];
        }
    }
}

/* Ertekadas: op= */
BCD& BCD::operator= (const BCD & rhs){
    if(this!=&rhs){
        delete[] data;
        darab=rhs.darab;
        data=new int[HOSSZ];
        for(size_t i=0;i<HOSSZ;i++){
            data[i]=rhs.data[i];
        }
    }
    return *this;
}


/*Operatorok megvalósítása*/
BCD BCD::operator+ (BCD& rhs) const{
    long long int a,b;
    BCD x = *this;
    a=x.bcd_to_dec();
    b=rhs.bcd_to_dec();
    //std::cout<<a<<" "<<b<<std::endl;
    BCD sum;
    if(a+b>99999999999)
        throw std::invalid_argument("BCD::operator+ (BCD& rhs) const, Nagyobb mint 11 jegyu a BCD, ezek kezelesere nem alkalmas ez az osztaly");
    return sum.dec_to_bcd(a+b);
}

BCD BCD::operator+ (long long int szam) const{
    BCD tmp;
    tmp.dec_to_bcd(szam);
    return BCD::operator+(tmp);
}

BCD operator+ (long long int szam, BCD& rhs){
    /*long long int a;
    a=rhs.bcd_to_dec();
    BCD sum;
    return sum.dec_to_bcd(szam+a);*/
    return rhs+szam; //felhasznaljuk az elozoleg megirt + operatort;
}

BCD BCD::operator- (BCD& rhs) const{
    //negativ szam kivetelkezelese!
    long long int a,b;
    BCD x = *this;
    a=x.bcd_to_dec();
    b=rhs.bcd_to_dec();
    BCD sum;
    if(a-b<0)
        throw std::invalid_argument("BCD::operator- (BCD& rhs) const. Negativ illetve lebegopontos szamokat nem kezel ez az osztaly");
    return sum.dec_to_bcd(a-b);
}

BCD BCD::operator- (long long int szam) const{
    BCD tmp;
    tmp.dec_to_bcd(szam);
    return BCD::operator-(tmp);
}

BCD operator- (long long int szam, BCD& rhs){
    long long int a;
    a=rhs.bcd_to_dec();
    BCD sum;
    if(szam-a<0)
        throw std::invalid_argument("BCD::operator- (long long int szam, BCD& rhs). Negativ illetve lebegopontos szamokat nem kezel ez az osztaly");
    return sum.dec_to_bcd(szam-a);
}

BCD& BCD::operator+= (BCD& rhs){
    *this=(*this)+rhs;
    return (*this);
}

BCD& BCD::operator+= (long long int szam){
    *this=(*this)+szam;
    return (*this);
}

BCD& BCD::operator-= (BCD& rhs){
    *this=(*this)-rhs;
    return *this;
}

BCD& BCD::operator-= (long long int szam){
    *this=(*this)-szam;
    return (*this);
}

long long int& operator+=(long long int& szam, BCD& rhs){
    BCD tmp;
    tmp=szam+rhs;
    szam=tmp.bcd_to_dec();
    if(szam>99999999999)
        throw std::invalid_argument("long long int& operator+=(long long int& szam, BCD& rhs). Nagyobb mint 11 jegyu a BCD, ezek kezelesere nem alkalmas ez az osztaly");
    return szam;
}

long long int& operator-=(long long int& szam, BCD& rhs){
    BCD tmp;
    tmp=szam-rhs;
    szam=tmp.bcd_to_dec();
    if(szam<0)
        throw std::invalid_argument("long long int& operator-=(long long int& szam, BCD& rhs). Negativ illetve lebegopontos szamokat nem kezel ez az osztaly");
    return szam;
}

/*Egyenloseg, egyenlotlensegek vizsgalata*/
bool BCD::operator==(BCD& rhs) const{
    long long int a,b;
    BCD tmp=(*this);
    a=tmp.bcd_to_dec();
    b=rhs.bcd_to_dec();
    if(a==b)return true;
    else return false;
}

bool BCD::operator != (BCD& rhs) const{
    return !(*this==rhs);
}

bool BCD::operator == (long long int szam) const{
    BCD tmp=(*this);
    long long int szam2;
    szam2=tmp.bcd_to_dec();
    if(szam==szam2)return true;
    else return false;
}

bool BCD::operator != (long long int szam) const{
    return !(*this==szam);
}

bool operator == (long long int szam, BCD& rhs){
    long long int szam2;
    szam2=rhs.bcd_to_dec();
    if(szam==szam2)return true;
    else return false;
}

bool operator != (long long int szam, BCD& rhs){
    return !(szam==rhs);
}

bool BCD::operator< (BCD& rhs)const{
    long long int a,b;
    BCD tmp=(*this);
    a=tmp.bcd_to_dec();
    b=rhs.bcd_to_dec();
    if(a<b)return true;
    else return false;
}

bool BCD::operator <  (long long int szam) const{
    long long int a;
    BCD tmp=(*this);
    a=tmp.bcd_to_dec();
    if(a<szam)return true;
    else return false;
}

bool operator <  (long long int szam, BCD& rhs){
    long long int szam2;
    szam2=rhs.bcd_to_dec();
    if(szam<szam2)return true;
    else return false;
}

bool BCD::operator >  (BCD& rhs) const{
    long long int a,b;
    BCD tmp=(*this);
    a=tmp.bcd_to_dec();
    b=rhs.bcd_to_dec();
    if(a>b)return true;
    else return false;
}

bool BCD::operator >  (long long int szam) const{
    long long int a;
    BCD tmp=(*this);
    a=tmp.bcd_to_dec();
    if(a>szam)return true;
    else return false;
}

bool operator >  (long long int szam, BCD& rhs){
    long long int szam2;
    szam2=rhs.bcd_to_dec();
    if(szam>szam2)return true;
    else return false;
}

bool BCD::operator <= (BCD& rhs) const{
    long long int a,b;
    BCD tmp=(*this);
    a=tmp.bcd_to_dec();
    b=rhs.bcd_to_dec();
    if(a<=b)return true;
    else return false;
}

bool BCD::operator <= (long long int szam) const{
    long long int a;
    BCD tmp=(*this);
    a=tmp.bcd_to_dec();
    if(a<=szam)return true;
    else return false;
}

bool operator <= (long long int szam, BCD& rhs){
    long long int szam2;
    szam2=rhs.bcd_to_dec();
    if(szam<=szam2)return true;
    else return false;
}

bool BCD::operator >= (BCD& rhs) const{
    long long int a,b;
    BCD tmp=(*this);
    a=tmp.bcd_to_dec();
    b=rhs.bcd_to_dec();
    if(a>=b)return true;
    else return false;
}

bool BCD::operator >= (long long int szam) const{
    long long int a;
    BCD tmp=(*this);
    a=tmp.bcd_to_dec();
    if(a>=szam)return true;
    else return false;
}

bool operator >= (long long int szam, BCD& rhs){
long long int szam2;
    szam2=rhs.bcd_to_dec();
    if(szam>=szam2)return true;
    else return false;
}

//++b, prefix//
BCD& BCD::operator++(){
    BCD tmp=(*this);
    long long int a=tmp.bcd_to_dec();
    a++;
    if(a>99999999999)
        throw std::invalid_argument("long long int& operator+=(long long int& szam, BCD& rhs). Nagyobb mint 11 jegyu a BCD, ezek kezelesere nem alkalmas ez az osztaly");
    (*this).dec_to_bcd(a);
    return (*this);
}

BCD& BCD::operator--(){
    BCD tmp=(*this);
    long long int a=tmp.bcd_to_dec();
    a--;
    if(a<0)
        throw std::invalid_argument("long long int& operator+=(long long int& szam, BCD& rhs). Negativ illetve lebegopontos szamokat nem kezel ez az osztaly");
    (*this).dec_to_bcd(a);
    return (*this);
}

//b++, postfix//
BCD& BCD::operator++(int){
    BCD *old = this;
    ++ (*this);
    return *old;
}

BCD& BCD::operator--(int){
    BCD *old = this;
    -- (*this);
    return *old;
}

BCD BCD::operator/ (BCD& rhs){
    long long int a,b;
    BCD tmp=(*this);
    a=tmp.bcd_to_dec();
    b=rhs.bcd_to_dec();
    BCD sum;
    return sum.dec_to_bcd((long long int)a/b);
}

BCD BCD::operator/ (int szam){
    BCD tmp=(*this);
    long long int a;
    a=tmp.bcd_to_dec();
    BCD sum;
    return sum.dec_to_bcd((long long int)a/szam);
}

BCD BCD::operator/ (long long int szam){
    BCD tmp=(*this);
    long long int a;
    a=tmp.bcd_to_dec();
    BCD sum;
    return sum.dec_to_bcd((long long int)a/szam);
}

BCD BCD::operator/ (double szam){
    BCD tmp=(*this);
    long long int a;
    a=tmp.bcd_to_dec();
    BCD sum;
    return sum.dec_to_bcd((long long int)a/szam);
}

long long int operator/ (long long int szam, BCD& rhs){
    long long int a;
    a=rhs.bcd_to_dec();
    return (long long int)szam/a;
}

BCD BCD::operator% (BCD& rhs){
    BCD tmp=(*this);
    long long int a, b;
    a=tmp.bcd_to_dec();
    b=rhs.bcd_to_dec();
    BCD sum;
    return sum.dec_to_bcd((long long int)a%b);

}

BCD BCD::operator% (int szam){
    BCD tmp=(*this);
    long long int a;
    a=tmp.bcd_to_dec();
    BCD sum;
    return sum.dec_to_bcd(a%(long long int)szam);
}

BCD BCD::operator% (long long int szam){
    BCD tmp=(*this);
    long long int a;
    a=tmp.bcd_to_dec();
    BCD sum;
    return sum.dec_to_bcd((long long int)a%szam);
}


long long int operator% (long long int szam, BCD& rhs){
    long long int a;
    a=rhs.bcd_to_dec();
    return (long long int)szam%a;
}

BCD& BCD::operator/= (BCD& rhs){
    *this=(*this)/rhs;
    return (*this);
}

BCD& BCD::operator/= (long long int szam){
    *this=(*this)/szam;
    return (*this);
}

long long int& operator/=(long long int& szam, BCD& rhs){
    szam=szam/rhs;
    return szam;
}

/*BCD BCD::operator* (BCD& rhs){
    BCD eredmeny;
    BCD tmp=(*this);
    size_t max=(tmp.darab>rhs.darab ? tmp.darab : rhs.darab);
    delete[] eredmeny.data;
    eredmeny.darab=max;
    eredmeny.data=new int[max];
    for(int i=HOSSZ-1;i>=0;i--){
        if(tmp.data[i]==rhs.data[i])eredmeny.data[i]=1;
        else eredmeny.data[i]=0;
    }
    long long int a;
    a=eredmeny.bcd_to_dec();
    BCD sum;
    return sum.dec_to_bcd(a);
}*/

std::ostream& operator<<(std::ostream & os,const BCD& rhs){
    for(size_t i=0;i<rhs.realsize();i++){
        os<<rhs.data[i];
        if((i+1)%4==0)os<<" ";
    }
    return os;
}

std::istream& operator>>(std::istream & is,BCD& rhs){
    int meret;
    is>>meret;
    delete[] rhs.data;
    rhs.darab=meret;
    rhs.data=new int[rhs.realsize()];
    std::string s;
    is>>s;
    int j=0;
    for(size_t i=0;i<s.size();i++){
        if(s[i]!=' ' && (s[i]=='1' || s[i]=='0')){
            rhs.data[j]=(int)(s[i]-'0');
            j++;
        }
    }
    /*long long int szam;
    szam=*/rhs.bcd_to_dec();
    std::cout<<std::endl;
    return is;
}



