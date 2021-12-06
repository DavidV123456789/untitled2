//
// Created by map on 9. 11. 2021.
//

#ifndef UNTITLED2_TROJUHOLNIK_H
#define UNTITLED2_TROJUHOLNIK_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>

namespace alpha{
    using std::endl;
    using std::cin;
    using std::cout;
}
namespace beta{
    using std::setfill;
    using std::setw;
    using std::setprecision;
    using std::right;
    using std::left;
    using std::showpos;
    using std::noshowpos;
}

class Bod{
private:
    float x;
    float y;
public:
    Bod():x(0),y(0){};
    explicit Bod(float a):x(a),y(a){};
    Bod(float a,float b):x(a),y(b){};
    float getDistance(const Bod & other = Bod(0,0) ) const;

    float getX();
    float getY();

    Bod getCenter(const Bod & other) const;
    Bod operator+(const Bod & other) const;
    Bod operator-(const Bod & other) const;
    Bod operator/(float k) const;
    Bod operator*(float k) const;
    float operator*(const Bod & other) const;//skalarny sucin vektorov
    bool operator<(const Bod & other);
    bool operator>(const Bod & other);

    Bod operator^(const Bod & other) const; //pretazeny operator strieska na vypocet stredu usecky
    explicit operator float() const;  //pretazeny operator konverzie na float, ktory vrati vzdialenost od [0,0]
    //inicializacia generatorov cisel
    friend Bod operator*(float k, const Bod &other);
    friend std::ostream & operator<<(std::ostream & os,const Bod &other);
    //staticka metoda ktora vygeneruje pole bodov zadaneho poctu a utriedi ho podla vzdialenosti bodu od pociatku

    static Bod * generujPoleBodov(int pocetBodov);
    static void vypisPoleBodov(int pocetBodov,Bod *poleBodov);
    static int cmp(const void *prvy,const void *druhy);
    static int generujInt(int min, int max);
    static float generujFloat(float min, float max);
};
//alias
using Vektor = Bod; //aby sme mohli pouzivat vektor namiesto vtedy, ked to je vhodne a bolo vidiet presne co robime


class Priamka{
protected:
    Bod X;
    Bod Y;//aby jej dedicne triedy mohli pouzivat tuto vlastnost
public:
    //
    class Priesecnik
    {
    private:
        Bod P;
        char popis[11];
    public:
        Priesecnik():P({0,0}),popis(" "){};
        Priesecnik(const Bod &R, const char * msg);
        Bod getBodPriesecnika()const;
        char * getpopisPriesecnika() const;
        friend std::ostream  & operator<<(std::ostream & os, const Priesecnik &other);
        /*
         D= a1b2-a2b1
         D1= c1b2-c2b1
         D2= a1c2-a2c1
         x=D1/D
         y=D2/D
         */
    };
    //
    Priamka(){};//Priamka():X({0 , 0}),Y({0,0}){};-funguje bez toho
    explicit Priamka(Bod Z):X(Z),Y(Z){};
    Priamka(Bod Z, Bod W):X(Z),Y(W){};
    friend std::ostream &operator<<(std::ostream &os, const Priamka & other);
    Bod getStred() const;
    float  getDlzka() const;
    bool leziNaPriamke(const Bod & other) const;
    bool jeRovnobezna(const Priamka & other) const;
    bool operator==(const Priamka & other) const;
    virtual Vektor getsmerovy() const;
    virtual Vektor getNormalovy() const;//kolmý vektor na smerový
    Priamka getOsStrany() const;
    Priamka getOsUhla(const Priamka & other) const;
    float getUhol(const Priamka & other, char vrat='s') const;


};

class PR: public Priamka{
private:
    float koeficienty[4];//koeficienty a1,s1,a2,s2 v rovniciach: x = a1+s1*t;   y=a2+s2*t;
public:
    PR():koeficienty{0,0,0,0}{};//ak nezadame nic tak vsetky koeficienty budu 0
    PR(Bod A, Bod B);//parametrivka priamka urcena dvoma bodmi
    explicit PR(const Priamka & P);//vyrobi parametricku rovnicu z uz vytvorenej priamky
    float &operator [](int index) {return  koeficienty[index];};//musime vratit odkaz na float// pretazeny opertor [] pre nekonstantny pristup
    const float & operator [](int index) const{return koeficienty[index];};// pretazeny opertor [] pre konstantny pristup
    friend  std::ostream  & operator<<(std::ostream & os, const PR & other);
    float * getKoeficienty();//vrati pole koeficientov
    void setKoeficienty();//nastavi koeficienty v parametrckej rovnici na spravne hodnoty
    virtual Vektor getsmerovy() const;
};

//všeobecná rovnica
class VR: public Priamka{
private:
    float koeficienty[3];
public:
    VR():koeficienty{0,0,0}{};
    VR(Bod A, Bod B);
    //dorob...
};
#endif //UNTITLED2_TROJUHOLNIK_H
