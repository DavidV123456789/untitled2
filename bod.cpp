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

float Bod::getX() {
    return 0;
}

float Bod::getY() {
    return 0;
}

float Bod::operator*(const Bod &other) const {
    //nejsom si isty co presne tu ma byt
    //dorob...
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Priamka &other) {
    return 0;
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
    Vektor smerovy = getsmerovy();
    return { smerovy.getY()*(-1), smerovy.getX() };
    //getery?
}

Priamka Priamka::getOsStrany() const {
    Bod stred = getStred();
    return {stred, stred+getNormalovy()};
}

float Priamka::getUhol(const Priamka &other, char vrat) const {
    //dorob...

    return 0;
}

Priamka Priamka::getOsUhla(const Priamka &other) const {
    return Priamka();
}

bool Priamka::leziNaPriamke(const Bod &other) const {
    //p:AB  Ce(p:AB)
    //2x+3y+2=0 //ax+by+2=0 //ak a,b su nasobky 2 alebo 3 tak bude lineárne závislá, teda budu rovnobezne// n1=k*n2// k=n1/n2
    /*Bod other;
    if(other>=this->X && other<=this->Y)
    {
        return true;
    }
    if(other<=this->X && other>=this->Y)
    {
        return true;
    }
    return false;*///0 jhe vždy false, všetko ostatné true
    VR vPriamka(*this);
    return vPriamka[0] * other.getX() + vPriamka[1] *other.getY() + vPriamka[2] == 0;
}

bool Priamka::jeRovnobezna(const Priamka &other) const {
    //zistime tak či je normalovy vektor prvej a smerovy vektor druhej na seba kolme
    /*Bod K = getNormalovy(other);
    Bod J = getsmerovy(this);
    if(K=){
        return true;
    }
    return false;*/

    std::ostream  &operator<<(std::ostream &os, const PR &other)
    {
        os << "Parametricka rovnica:" <<std::endl <<"x = " << setw(4) ;//...
        return os;
    }
}

bool Priamka::operator==(const Priamka &other) const {
    //totoznost//1.ci su rovnobezne// 2 ci bod z druhej lezi na prvej
    if(this->Priamka= jeRovnobezna(other))
    {
        if(other= leziNaPriamke(this->X)){
            return true;
        }
    }
    return false;
}

//Je potrebné optimalozovať program tak aby sa funkcia vyvolávala čo najmenej krát
PR::PR(Bod A, Bod B) : Priamka(A, B) {
    setKoeficienty();
}

PR::PR(const Priamka &P):Priamka(P) {
    setKoeficienty();
}

void PR::setKoeficienty() {
    Vektor smerovy=Priamka::getsmerovy();//dôvod prečo Priamka:: pred tým getsmerovy je z dôvodu lebo je to virtualna v dedicovi premenena metoda
    koeficienty[0]=X.getX();
    koeficienty[1]=smerovy.getX();
    koeficienty[2]=X.getY();
    koeficienty[3]=smerovy.getY();
    //x=a1 + s1 * t     y= a2 + s2 * t
}

float *PR::getKoeficienty() {
    return koeficienty;
}

std::ostream &operator<<(std::ostream &os, const PR &other) {
    cout<<"Parametricka rovnica:"<<std::endl;
    cout<<std::showpos<<"x= "<<other.koeficienty[0]<<"+"<<other.koeficienty[2]<<"*t"<<std::noshowpos<<std::endl;
    cout<<std::showpos<<"y= "<<other.koeficienty[1]<<"+"<<other.koeficienty[3]<<"*t       ;t je z R"<<std::noshowpos<<std::endl;
    //showpos nám zapričinuje ukazovanie + pred kladnými cislami
}

Vektor PR::getsmerovy() const {
    return {koeficienty[1], koeficienty[3]};
}


VR::VR(Bod A, Bod B) : Priamka(A, B) {

}

std::ostream &operator<<(std::ostream &os, const Priamka::Priesecnik &other) {
    os<<"Priamky su"<<other.popis;
    if(std::strcmp(other.popis,"rovnobezne")==0)
    {
        os<<" a ich presecnik je"<<other.P;
    }
    return os;
}

char *Priamka::Priesecnik::getpopisPriesecnika() const {

}

Bod Priamka::Priesecnik::getBodPriesecnika() const {

    float D= * - * ;
    float D1= * - * ;
    float D2= * - * ;
    float a=D1/D;
    float b=D2/D;
    Bod P(a, b);
    return P;
}

Priamka::Priesecnik::Priesecnik(const Bod &R, const char *msg) {
    std::strncpy(popis, msg, 10);
    popis[10]='\0';
}
