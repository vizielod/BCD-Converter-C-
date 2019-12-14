#ifndef BCD_H_INCLUDED
#define BCD_H_INCLUDED
#define HOSSZ darab*4 //darab 4 szerese, mivel egy tagot 4 bitbe tarol
#include "memtrace.h"

/// BCD osztály
class BCD{
protected:
    ///BCD-ként tárolt szám számjegyeinek a száma
    size_t darab;
    ///Az adott számot binárisan (BCD-ként) tároló tömb
    int *data;
public:
    ///Konstruktor - méret alapján
    /// @param darab - számjegyek száma (tömb méretének negyede)
    BCD(int darab=0);

    ///Konstruktor - 0, 1 számokat tartalmazó tömbből
    /// @param darab - számjegyek száma (tömb méretének negyede)
    /// @param *data - integer tömb
    BCD(int *data, int darab);

    ///Copy/Másoló konstruktor
    /// @param rhs - jobb oldali operandus(BCD)
    BCD(const BCD & rhs);

    ///Értekadó operator(operator=)
    /// @param rhs - jobb oldali operandus(BCD)
    BCD & operator= (const BCD & rhs);

    ///Index operator - konstans
    /// @param idx - index
    /// @return indexedik elem
    int operator[] (size_t idx)const{
        return data[idx];
    }

    ///Index operator - nem konstans, módosítható esetben
    /// @param idx - index
    /// @return indexedik elem
    int & operator[] (size_t idx){
        return data[idx];
    }

    ///Méret lekérdezése
    /// @return - számjegyek száma
    size_t size()const{
        return darab;
    }

    ///Tárolt data-tömb konkrét méretének lekérdezése
    /// @return - data tömb mérete
    size_t realsize()const{
        return darab*4;
    }

    /**
    BCD tipus atkasztolasa egész számá (hossza miatt, 11 jegyû is lehet akár) long long int
    Az egesz szam (long long int) atkasztolasa BCD be
    */
    /*long long int BCD_to_llint(const BCD& rhs);
    BCD llint_to_BCD(long long int num);*/
    long long int bcd_to_dec();
    BCD& dec_to_bcd(long long int szam);

    //Összeadás, a + nem módosítja önmagát ezért konstans fgv.
    /// BCD + BCD
    /// @param rhs - jobb oldali operandus (BCD), a bal oldali a (*this)
    /// @return egy új BCD szám - a két BCD összege
    BCD operator+ (BCD&) const;

    /// BCD + long long int
    /// @param szam - jobb oldali operandus (long long int)
    /// @return egy új BCD adat - a két adat összege
    BCD operator+ (long long int) const;

    //Kivonás, a - nem módosítja önmagát ezért konstans fgv.
    /// BCD - BCD
    /// @param rhs - jobb oldali operandus (BCD), a bal oldali a (*this)
    /// @return egy új BCD szám - a két BCD különbsége
    BCD operator- (BCD&) const;

    /// BCD - long long int
    /// @param szam - jobb oldali operandus (long long int)
    /// @return egy új BCD adat - a két adat különbsége
    BCD operator- (long long int) const;

    //  a += művelet viszont módosítja önmagát! Ezért nem lehet konstans fgv.,
    // hasonlóképp a -= sem lehet konstans
    /// BCD + BCD
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhs-t
    BCD& operator+= (BCD&);

    /// BCD + long long int
    /// @param szam - jobb oldali operandus (long long int)
    /// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk a szam-ot
    BCD& operator+= (long long int);

    /// BCD - BCD
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return eredeti (bal oldali) objektum ref., amiből kivontuk rhs-t
    BCD& operator-= (BCD&);

    /// BCD - long long int
    /// @param szam - jobb oldali operandus (long long int)
    /// @return eredeti (bal oldali) objektum ref., amiből kivontuk a szam-ot
    BCD& operator-= (long long int);

    /*
    //Ezek nem lesznek megvalosithatoak, ugyan is, ha ket darab 11 jegyu BCD t akarok osszeszorozni, akkor olyan nagy szamot is kaphatunk, hogy a vilagbol is kifut...
    friend BCD operator* (const BCD&, long long int);
    friend BCD operator* (long long int, const BCD&);
    // BCD * BCD is NOT VALID, vagyis ez a muvelet nem ertelmezett
    */
    /*
    /**
    Össze XNOR-ol két BCD-t bitenként
    */
    //BCD operator* (BCD&);
    /**
    Bitenként ÉS-eli a két BCD-t
    */

    //friend BCD operator& (const BCD&, const BCD&){};
    /**
    Bitenként VAGY-olja a két BCD-t (megengedő vagy)
    */
    //friend BCD operator| (const BCD&, const BCD&){};
    /**
    Bitenkénti kizáró VAGY két BCD között (XOR)
    */
    //friend BCD operator^ (const BCD&, const BCD&){};

    /**
    Ezek a függvények csak akkor végzik el a mûveletet, ha a bal oldali érték nagyobb mint a jobb oldali érték
    Lebegõpontos számokat nem kezelek, szóval a visszatérési érték az eredmény kerekített értéke lesz BCD alakban
    */

    /// BCD / BCD, BCD egész osztás BCD-vel
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return egy új BCD szám, a két BCD egész hányadosa
    BCD operator/ (BCD&);

    /// BCD / int, BCD egész osztás integerrel
    /// @param szam - jobb oldali operandus (int)
    /// @return egy új BCD szám, a két adat egész hányadosa
    BCD operator/ (int);

    /// BCD / long long int, BCD egész osztás long long int-tel
    /// @param szam - jobb oldali operandus (long long int)
    /// @return egy új BCD szám, a két adat egész hányadosa
    BCD operator/ (long long int);

    /// BCD / double, BCD egész osztás double-el
    /// @param szam - jobb oldali operandus (double)
    /// @return egy új BCD szám, a két adat egész hányadosa
    BCD operator/ (double);

    /// BCD % BCD, BCD maradékos osztás BCD-vel
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return egy új BCD szám, a két BCD osztási maradéka
    BCD operator% (BCD&);

    /// BCD % int, BCD maradékos osztás integerrel
    /// @param szam - jobb oldali operandus (int)
    /// @return egy új BCD szám, a két adat osztási maradéka
    BCD operator% (int);

    /// BCD % long long int, BCD maradékos osztás long long int-tel
    /// @param szam - jobb oldali operandus (long long int)
    /// @return egy új BCD szám, a két adat osztási maradéka
    BCD operator% (long long int);
    //A double-el való maradékos osztás nem értelmezett!!!


    /// BCD / BCD
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return eredeti (bal oldali) objektum ref., amit elosztottunk rhs-el
    BCD& operator/= (BCD&);

    /// BCD / BCD
    /// @param szam - jobb oldali operandus (long long int)
    /// @return eredeti (bal oldali) objektum ref., amit elosztottunk a szam-al
    BCD& operator/= (long long int);
    //Világos, hogy a %= operátor nem értelmezett ezen esetben!

    /**
    Egyenlõségek és egyenlõtlenségek eldöntése
    BCD és BCD között
    illetve BCD és egy longlong int között is
    */

    // összehasonlítás

    /// Egyenlőség vizsgálat
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return true - ha a két BCD egyenlő, egyébként false
    bool operator == (BCD&) const;

    /// Egyenlőtlenség vizsgálat
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return true - ha a két BCD nem egyenlő, egyébként false
    bool operator != (BCD&) const;

    /// < vizsgálat
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return true - ha a bal oldali BCD kisebb mint a jobb oldali, egyébként false
    bool operator <  (BCD&) const;

    /// > vizsgálat
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return true - ha a jobb oldali BCD kisebb mint a bal oldali, egyébként false
    bool operator >  (BCD&) const;

    /// <= vizsgálat
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return true - ha a bal oldali BCD kisebb vagy egyenlő mint a jobb oldali, egyébként false
    bool operator <= (BCD&) const;

    /// >= vizsgálat
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return true - ha a jobb oldali BCD kisebb vagy egyenlő mint a bal oldali, egyébként false
    bool operator >= (BCD&) const;

    /// Egyenlőség vizsgálat
    /// @param szam - jobb oldali operandus (long long int)
    /// @return true - ha a két adat egyenlő, egyébként false
    bool operator == (long long int) const;

    /// Egyenlőtlenség vizsgálat
    /// @param szam - jobb oldali operandus (long long int)
    /// @return true - ha a két adat nem egyenlő, egyébként false
    bool operator != (long long int) const;

    /// < vizsgálat
    /// @param szam - jobb oldali operandus (long long int)
    /// @return true - ha a bal oldali adat kisebb mint a jobb oldali, egyébként false
    bool operator <  (long long int) const;

    /// > vizsgálat
    /// @param szam - jobb oldali operandus (long long int)
    /// @return true - ha a jobb oldali adat kisebb mint a bal oldali, egyébként false
    bool operator >  (long long int) const;

    /// <= vizsgálat
    /// @param szam - jobb oldali operandus (long long int)
    /// @return true - ha a bal oldali adat kisebb vagy egyenlő mint a jobb oldali, egyébként false
    bool operator <= (long long int) const;

    /// >= vizsgálat
    /// @param szam - jobb oldali operandus (long long int)
    /// @return true - ha a jobb oldali adat kisebb vagy egyenlő mint a bal oldali, egyébként false
    bool operator >= (long long int) const;


    /// ++BCD, először növel egyel, majd visszatér a növelt értékkel
    /// @return a megnövelt BCD referencia
    BCD& operator++();     // prefix, ++b
    /// --BCD, először csökkent egyel, majd visszatér a csökkentett értékkel
    /// @return a csökkentett BCD referencia
    BCD& operator--();
    /// BCD++, megnöveli egyel a BCD-t, de a növelés előtti értékkel tér vissza
    /// @return az átvett BCD referencia (növelés nélkül)
    BCD& operator++(int);  // postfix b++
    /// BCD--, csökkenti egyel a BCD-t, de a csökkentés előtti értékkel tér vissza
    /// @return az átvett BCD referencia (csökkentés nélkül)
    BCD& operator--(int);

    ///Destruktor
    ///Mivel egy dinamikus tömböt tárolunk, ezért gondoskodni kell a felszabadításáról is.
    ~BCD(){ delete[] data; }

    // cout << Komplex is csak globális függvénnyel lenne megvalósítható, mivel
    // a baloldali osztály (ostream) nincs a kezünkben, nem módosítható,
    // de friend tagfüggvényként elérjük a privát adatokat is
    /// Kiíáras egy ostream-re
    /// @param os - bal oldali operandus (ostream)
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return ostream&, hogy fűzhető legyen
    friend std::ostream& operator<<(std::ostream & os,const BCD& rhs);

    /// Beolvasás egy istream-ről
    /// @param is - bal oldali operandus (istream)
    /// @param rhs - jobb oldali operandus (BCD)
    /// @return istream&, hogy fűzhető legyen
    friend std::istream& operator>>(std::istream & is,BCD& rhs);
};

// long long int + BCD csak globális függvénnyel valósítható meg,
// mivel a bal oldal nem osztály, ugyan így a kivonás is.
/// long long int + BCD
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return egy új BCD adat - a két adat összege
BCD operator+ (long long int, BCD&);

/// long long int - BCD
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return egy új BCD adat - a két adat különbsége
BCD operator- (long long int, BCD&);


//Csak globális függvények lehetnek, mert a bal oldal nem osztály
/// long long int + BCD
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhs-t
long long int& operator+=(long long int&, BCD&);

/// long long int - BCD
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return eredeti (bal oldali) objektum ref., amiből kivontunk rhs-t
long long int& operator-=(long long int&, BCD&);

//Összehasonlítás
/// Egyenlőség vizsgálat
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return true - ha a két adat egyenlő, egyébként false
bool operator == (long long int, BCD&);
/// Egyenlőtlenség vizsgálat
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return true - ha a két adat nem egyenlő, egyébként false
bool operator != (long long int, BCD&);
/// < vizsgálat
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return true - ha a bal oldali adat kisebb mint a jobb oldali, egyébként false
bool operator <  (long long int, BCD&);
/// > vizsgálat
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return true - ha a bal oldali adat nagyobb mint a jobb oldali, egyébként false
bool operator >  (long long int, BCD&);
/// <= vizsgálat
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return true - ha a bal oldali adat kisebb vagy egyenlő mint a jobb oldali, egyébként false
bool operator <= (long long int, BCD&);
/// >= vizsgálat
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return true - ha a bal oldali adat nagyobb vagy egyenlő mint a jobb oldali, egyébként false
bool operator >= (long long int, BCD&);

// long long int / BCD csak globális függvénnyel valósítható meg,
// mivel a bal oldal nem osztály, ugyan így a maradékos osztás(%) is.
/// long long int / BCD
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return egy új long long int adat - a két adat hányadosa
long long int operator/ (long long int, BCD&);

/// long long int % BCD
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return egy új long long int adat - a két adat osztási maradéka
long long int operator% (long long int, BCD&);

/// long long int / BCD
/// @param szam - bal oldali operandus (long long int)
/// @param rhs - jobb oldali operandus (BCD)
/// @return eredeti (bal oldali) objektum ref., amit elosztottunk rhs-el
long long int& operator/=(long long int&, BCD&);

#endif // BCD_H_INCLUDED
