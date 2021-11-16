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
    Bod():x(0),y(0){}; //vypyta x,y
    explicit Bod(float a):x(a),y(a){}; //"a" inicializuje x aj y suradnicu
    Bod(float a, float  b):x(a),y(b){}; // inicializuje x a y

    float getDistance(const Bod & other = Bod(0, 0)) const; // nech pocita vzdialenostod pociatku [0,0] aj od druheho bodu pouzi impliccitny parameter
    Bod getCenter(const Bod&other) const;   //najde stred medzi dovma bodmi

    //konstrukcie: vypis bodu [x,y];    sucet bodov;    rozdiel bodov;  bod*cislo;  bod / ciuslo
    Bod operator+(const Bod &other) const;
    Bod operator-(const Bod &other) const;
    Bod operator/(const Bod &other) const;
    Bod operator*(const Bod &other) const;
    friend Bod operator*(int c, const Bod &other);
    friend Bod operator/(int c, const Bod &other);
    explicit operator float() const; //pretypuje na float [x,y]

        //staticka metoda ktora vygeneruje pole n bodov, ktoré potom utrriedi podla vzdialenosti bodu od pociatku
   static void generujPoleBodov(Bod *pole, int n);
   //musis dynamicky alokovat pole
   static void utriedPoleBodov(Bod *pole, int n);
   static void vypisPoleBodov(int pocetBodov, Bod *poleBodov);
   static int cmp(const void * a, const void * b);
};




#endif //UNTITLED2_TROJUHOLNIK_H
