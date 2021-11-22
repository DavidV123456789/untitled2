//
// Created by map on 9. 11. 2021.
//
#include "trojuholnik.h"
using namespace alpha;

float Bod::getDistance(const Bod &other) const {
//sqrt((x2-x1)upper2 + (y2-y1)upper2)

    return sqrt(((this->x-other.x)*(this->x-other.x))+((this->y-other.y)*(this->y-other.y)));
}

Bod Bod::getCenter(const Bod &other) const {
    Bod N;
    N.x=(this->x+other.x)/2;
    N.y=(this->y+other.y)/2;
    return N;
}

Bod Bod::operator+(const Bod &other) const {
    Bod N;
    N.x=this->x+other.x;
    N.y=this->y+other.y;

    return N;
}

Bod Bod::operator/(const Bod &other) const {
    Bod N;
    N.x=this->x+other.x;
    N.y=this->y+other.y;

    return N;
}

Bod operator*(int c, const Bod &other) {
    Bod N;
    N.x=other.x*c;
    N.y=other.y*c;

    return N;
}

Bod operator/(int c, const Bod &other) {
    Bod N;
    N.x=other.x/c;
    N.y=other.y/c;

    return N;
}

Bod Bod::operator*(const Bod &other) const {
    return Bod();
}

Bod Bod::operator-(const Bod &other) const {
    return Bod();
}

void Bod::generujPoleBodov(Bod *pole, int n) {
    std::srand(time(0));
    for(int i=0;i<n;i++)
    {
        (pole+i)->x=std::rand()% 99 + 1;
        (pole+i)->y=std::rand()% 99 + 1;
    }
}

void Bod::utriedPoleBodov(Bod *pole, int n) {
    qsort((Bod *)pole,n,sizeof(Bod),cmp);
}

int Bod::cmp(const void *a, const void *b) {
    Bod * A = (Bod *)prvy;
    Bod * B = (Bod *)druhy;
    return ((*A)<(*B))?-1:((*A)>(*B))?1:0;
}

Bod::operator float() const {

    return 0;
}

void Bod::vypisPoleBodov(int pocetBodov, Bod *poleBodov) {

}






























}

std::ostream &operator<<(std::ostream &os, const Priamka &other) {
    os<<"Priamka:  "<<other.X<<" "<<other.Y;
    return os;
}
