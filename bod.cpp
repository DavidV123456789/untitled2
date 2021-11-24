//
// Created by map on 9. 11. 2021.
//
#include "trojuholnik.h"
using namespace alpha;

/*
Bod::Bod() {
    float x;
    float y;
    std::cout<<"Zadaj x: ";
    std::cin>>x;
    std::cout<<"Zadaj y: ";
    std::cin>>y;
    this->x=x;
    this->y=y;
}
Bod::Bod(float a) {
    this->x=a;
    this->y=a;
}
Bod::Bod(float a, float b) {
    this->x=a;
    this->y=b;
}
*/
/*
float Bod::getDistance(const Bod &other) const {
//sqrt((x2-x1)upper2 + (y2-y1)upper2)
    return sqrt(other.x*other.x+other.y*other.y);
}
Bod Bod::getCenter(const Bod &other) const {
    Bod N;
    N.x=(this->x+other.x)/2;
    N.y=(this->y+other.y)/2;
    return N;
}
float Bod::getBod() const {
    std::cout<<(x,y);
    return 0;
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
    qsort((Bod *)pole,n,sizeof(getDistance),cmp);
}
*/
#include <cmath>
#include <random>

float Bod::getDistance(const Bod &other) const
{
    return std::sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
}

Bod Bod::getCenter(const Bod &other) const
{
    return ((*this)+other)/2.f;
}

Bod Bod::operator+(const Bod &other) const
{
    return {x+other.x,y+other.y};
}

Bod Bod::operator-(const Bod &other) const
{
    return {x-other.x,y-other.y};
}

Bod Bod::operator/(float k) const
{
    return {x/k,y/k};
}

Bod Bod::operator*(float k) const
{
    return {x*k,y*k};
}

Bod operator*(float k, const Bod &other)
{
    return other*k;
}

std::ostream &operator<<(std::ostream &os, const Bod &other)
{
    os<<"[ "<<std::setprecision(4)<<other.x<<","<<other.y<<" ]"<<(float)other<<std::endl;
    return os;
}

Bod Bod::operator^(const Bod &other) const
{
    return this->getCenter(other);
}

Bod::operator float() const
{
    return this->getDistance(Bod(0,0));
}

Bod *Bod::generujPoleBodov(int pocetBodov)
{
    srand(time(nullptr));
    Bod *poleBodov;
    try
    {
        poleBodov= new Bod[pocetBodov];
        for(int i=0;i<pocetBodov;++i)
        {
            (poleBodov+i)->x=(float)(rand()%50);
            (poleBodov+i)->y=(float)(rand()%50);
        }
    }
    catch (const std::bad_alloc & ex)
    {
        std::cout<<"Chybna alokacia pamate";
        return nullptr;
    }
    return poleBodov;
}

void Bod::vypisPoleBodov(int pocetBodov, Bod *poleBodov)
{
    for(int i=0;i<pocetBodov;++i)
    {
        std::cout<<*(poleBodov+i)<<" ";
    }
}

int Bod::cmp(const void *prvy, const void *druhy)
{
    Bod * A = (Bod *)prvy;
    Bod * B = (Bod *)druhy;
    //return ((float)(*A)<(float)(*B))?1:((float)(*A)>(float)(*B))?-1:0;
    return ((*A)<(*B))?-1:((*A)>(*B))?1:0;
}

bool Bod::operator<(const Bod &other)
{
    return (float)(*this)<(float)(other);
}

bool Bod::operator>(const Bod &other)
{
    return (float)(*this)>(float)(other);
}
int Bod::generujInt(int min, int max)
{
    std::random_device rd; // ziska trandom cislo z hardveru pocitaca
    std::mt19937 eng(rd()); // "osoli" generator
    std::uniform_int_distribution<> distr(min, max); // definuje interval z ktoreho sa generuju cisla
    return distr(eng); //generuje cislo
}

float Bod::generujFloat(float min, float max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min,max);
    return dis(gen) ;
}

std::ostream &operator<<(std::ostream &os, const Priamka &other) {
    return ;
}

Bod Priamka::getStred() const {//refaktorovanie, pri zmene názvu funkcie zmení názov danej funkcie v celom kóde
    return X.getCenter(Y);
    //return X^Y;
}

float Priamka::getDlzka() const {
    return X.getDistance(Y);
}

Vektor Priamka::getsmerovy() const {

    return Y-X;
}

Vektor Priamka::getNormalovy() const {
    Vektor smerovy = getsmerovy()
    return { smerovy.getY()*(-1),smerovy.getX };
    //getery?
}

Priamka Priamka::getOsStrany() const {
    Bod stred = getStred();
    return {stred, stred+getNormalovy()};
}
//Je potrebné optimalozovať program tak aby sa funkcia vyvolávala čo najmenej krát
PR::PR(Bod A, Bod B) : Priamka(A, B) {

}

PR::PR(const Priamka &P) {

}

void PR::setKoeficienty() {

}

float *PR::getKoeficienty() {
    return koeficienty;
}

std::ostream &operator<<(std::ostream &os, const PR &other) {
    cout<<"Parametricka rovnica:"<<std::endl;
    cout<<"x= "<<other.koeficienty[0]<<"+"<<koeficienty[2]<<"*t"<<std::endl;
    cout<<"x= "<<koeficienty[1]<<"+"<<koeficienty[3]<<"*t"<<std::endl;
}
