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
#include <cstring>
#include <cmath>
#include <random>

int VR::p = -10;

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



float Bod::operator*(const Bod &other) const {
    return x * other.x + y * other.y;
}

Bod Bod::getJednotkovy() const {
    //std::cout<<this->getDistance()<<std::endl;
    return {this->x / this->getDistance(), this->y / this->getDistance()};
}

bool Bod::operator==(const Bod &other) {
    return (x==other.x && y==other.y);
}


std::ostream &operator<<(std::ostream &os, const Priamka &other) {
    os<<"Bod_A["<<other.X<<"];Bod_B["<<other.Y<<"]"<<std::endl;
    return os;
}

Bod Priamka::getStred() const {//refaktorovanie, pri zmene názvu funkcie zmení názov danej funkcie v celom kóde
    return X.getCenter(Y);
    //return X^Y;
}

float Priamka::getDlzka() const {
    return X.getDistance(Y);
}

Vektor Priamka::getSmerovy() const {

    return Y-X;
}

Vektor Priamka::getNormalovy() const {
    Vektor smerovy = getSmerovy();
    return { smerovy.getY()*(-1), smerovy.getX() };
    //getery?
}

Priamka Priamka::getOsStrany() const {
    Bod stred = getStred();
    return {stred, stred+getNormalovy()};
}

float Priamka::getUhol(const Priamka &other, char vrat) const {
    Vektor smerovy1= getSmerovy();
    Vektor smerovy2 = other.getSmerovy();

    if(this->jeRovnobezna(other))
    {
        return 0;
    }
    float uhol =std::acos((smerovy1*smerovy2)/(smerovy1.getDistance()*smerovy2.getDistance()));
    return  vrat  == 'r' ? static_cast<float>(uhol) : static_cast<float>(180/3.14159265358)*uhol;//pretypovanie:(float) uhol;(float)// správne by malo byť:static_cast<float>(uhol);static_cast<float>
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
    return vPriamka[0] * other.getX() + vPriamka[1] * other.getY() + vPriamka[2] == 0;
}

bool Priamka::jeRovnobezna(const Priamka &other) const {
    //zistime tak či je normalovy vektor prvej a smerovy vektor druhej na seba kolme
    return getSmerovy() * other.getNormalovy() == 0;
}
std::ostream  &operator<<(std::ostream &os, const PR &other)
{
    using namespace beta;
    os << "Parametricka rovnica:" << std::endl << "x = " << setw(4) << std::noshowpos << other[0] << std::showpos
       << setw(4) << other[1] << "*t" << std::endl << "y = " << setw(4) << std::noshowpos << other[2] << std::showpos
       << setw(4) << other[3] << "*t" << "   t je z R" << std::noshowpos << std::endl;
    return os;
}

bool Priamka::operator==(const Priamka &other) const {
    return ((jeRovnobezna(other))&&(leziNaPriamke(other.Y)));
}

//Je potrebné optimalozovať program tak aby sa funkcia vyvolávala čo najmenej krát
PR::PR(Bod A, Bod B) : Priamka(A, B) {
    setKoeficienty();
}

PR::PR(const Priamka &P):Priamka(P) {
    setKoeficienty();
}

void PR::setKoeficienty() {
    Vektor smerovy=Priamka::getSmerovy();//dôvod prečo Priamka:: pred tým getsmerovy je z dôvodu lebo je to virtualna v dedicovi premenena metoda
    koeficienty[0]=X.getX();
    koeficienty[1]=smerovy.getX();
    koeficienty[2]=X.getY();
    koeficienty[3]=smerovy.getY();
    //x=a1 + s1 * t     y= a2 + s2 * t
}

float *PR::getKoeficienty() {
    return koeficienty;
}



Vektor PR::getSmerovy() const {
    return Vektor();
}




VR::VR(Bod A, Bod B) : Priamka(A, B) {
    setKoeficienty();
}

VR::VR() {
    setKoeficienty();
}

VR::VR(float a, float b, float c) {
    try
    {
        if (a == 0 && b==0)
        {
            throw ("Takato priamka neexistuje! Bola vytvorena implicitna priamka ktora je osou x");
        }
        X = vypocitajBod(a, b, c);
        Y = vypocitajBod(a, b, c);
        koeficienty[0] = a;
        koeficienty[1] = b;
        koeficienty[2] = c;
    }
    catch (const char * ex)
    {
        std::cout << ex;
        koeficienty[0] = 0;
        koeficienty[1] = 1;
        koeficienty[2] = 0;
    }
}

VR::VR(const Priamka &P) {
    setKoeficienty();
}

std::ostream &operator<<(std::ostream &os, const VR &other) {
    using namespace beta;
    os << "Vseobecna rovnica:" << setw(4) << setprecision(2) << other[0] << "x" << std::showpos << setw(4) << other[1]
       << "y" << std::showpos << setw(4) << other[2] << " = 0" << endl;
    return os;
}

float *VR::getKoeficienty() {
    return koeficienty;
}

Vektor VR::getNormalovy() const {
    return Priamka::getNormalovy();
}

void VR::setKoeficienty() {
    Vektor normalovy = Priamka::getNormalovy();
    koeficienty[0] = normalovy.getX();
    koeficienty[1] = normalovy.getY();
    koeficienty[2] = -(koeficienty[0] * X.getX() + koeficienty[1] * X.getY());
}

Bod VR::vypocitajBod(float a, float b, float c) const {
    return Bod();
}

std::ostream &operator<<(std::ostream &os, const Priamka::Priesecnik &other) {

    os<<"Priamky su"<<other.popis;
    if(std::strcmp(other.popis,"rovnobezne")==0)
    {
        os<<" a ich presecnik je"<<other.P;
    }
    return os;
}

Priamka::Priamka(Bod A) {
    std::cout<<"Jeden bod neurcuje priamku. Bola vytvorena implicitna priamka iduca tymto bodom rovnobezna s osou x\n";
    X=A;
    Y={A.getX()+1,A.getY()};
}

Priamka::Priamka(Bod A, Bod B) {
    try
    {
        if(A==B)
        {
            throw "Dva rovnake body neurcuju priamku! Vytvorila sa implicitna priamka.\n";
        }
        X=A;
        Y=B;
    }
    catch (const char * msg)
    {
        std::cout<<msg;
        X={0,0};
        Y={1,0};
    }
}

Priamka::Priesecnik Priamka::getPoloha(const Priamka &other) const {
    return Priamka::Priesecnik();
}

char *Priamka::Priesecnik::getpopisPriesecnika() const {
    cout<<"P["<<P.getX()<<";"<<P.getY()<<"]"<<std::endl;
}

/*Bod Priamka::Priesecnik::getBodPriesecnika() const {

         D->Determinanti
         I a1 b1 I c1 I
         I a2 b2 I c2 I
         //a2+b1 = -c2 // vzhľadom na všeobcnú rovnicu priamky

         D= a1b2-a2b1
         D1= c1b2-c2b1
         D2= a1c2-a2c1
         x=D1/D
         y=D2/D


    float D= * - * ;
    float D1= * - * ;
    float D2= * - * ;
    float a=D1/D;
    float b=D2/D;
    Bod P(a, b);
    return P;
    //dorob...
}*/

Priamka::Priesecnik::Priesecnik(const Bod &R, const char *msg) {
    std::strncpy(popis, msg, 10);
    popis[10]='\0';
}



Trojuholnik::Trojuholnik(Priamka a, Priamka b, Priamka c) {

}

Trojuholnik::Trojuholnik(Bod A1, Bod B1, Bod C1) {

}

bool Trojuholnik::exustuje() const {
    float v=A.getDistance(B);
    float w=B.getDistance(C);
    float z=A.getDistance(C);




    if(v>w+z)
    {
        MsgError("Nie je trojuholnik");
        return false;
    }
    else if(w>=v+z)
    {
        MsgError("Nie je trojuholnik");
        return false;
    }
    else if(z>=w+v)
    {
        MsgError("Nie je trojuholnik");
        return false;
    }
    else
    {
        std::cout<<"Je trojuholnik";
        return true;
    }
    /*if(v>=w)
    {
        if(w>=z)
        {
            if(v<=w+z)
            {
                return ;
            }
            else
            {
                MsgError("Nie je trojuholnik");
            }
        }
        else
        {

        }
    }
    else
    {
        if(v>=z)
        {

        }
        else
        {

        }
    }  */
}

float Trojuholnik::getVelkostStrany(char strana) const {

    if(strana=='a')
    {
        float a=B.getDistance(C);
        return a;
    }
    else if(strana=='b')
    {
        float b=A.getDistance(C);
        return b;
    }
    else if(strana=='c')
    {
        float c=A.getDistance(B);
        return c;
    }
    else
    {
        std::cout<<"Neznama strana";
    }

}

float Trojuholnik::getVelkostUhla(char uhol) const {
    if(uhol=='a')
    {
        Priamka b(A,C);
        Priamka c(A,B);
        float alpha=b.getUhol(c);
        return alpha;
    }
    else if(uhol=='b')
    {
        Priamka a(B,C);
        Priamka c(A,B);
        float beta=a.getUhol(c);
        return beta;
    }
    else if(uhol=='c')
    {
        Priamka a(B,C);
        Priamka b(A,C);
        float gama=a.getUhol(b);
        return gama;
    }
    else
    {
        std::cout<<"Neznamy uhol";
    }

}

float Trojuholnik::getObvod() const {
    float obvod= getVelkostStrany('a')+getVelkostStrany('b')+getVelkostStrany('c');
    return obvod;
}

float Trojuholnik::getObsah() const {
    float S= (getVelkostStrany('a')+getVelkostStrany('b')+getVelkostStrany('c'))/2;
    return S;
}

void Trojuholnik::vypisStrany() const {
    std::cout<<"Strana a= "<<getVelkostStrany('a')<<endl;
    std::cout<<"Strana b= "<<getVelkostStrany('b')<<endl;
    std::cout<<"Strana c= "<<getVelkostStrany('c')<<endl;
}

void Trojuholnik::vypisUhly() const {
    std::cout<<"Uhol alpha="<<getVelkostUhla('a')<<endl;
    std::cout<<"Uhol beta="<<getVelkostUhla('b')<<endl;
    std::cout<<"Uhol gama="<<getVelkostUhla('c')<<endl;


}

Bod Trojuholnik::getOrtocentrum() const {
    return getVyska('a').getPoloha(getVyska('b')).getBodPriesecnika();//zober jednu vysku, urč jej polohu s druhou vyskou a urč priesečník
}

Priamka Trojuholnik::getTeznica(char naStranu) const {
    Bod D;
    Bod E;
    if(naStranu=='a')
    {
        Priamka a(B,C);
        D=a.getStred();
        E=A;

    }
    else if(naStranu=='b')
    {
        Priamka b(A,C);
        D=b.getStred();
        E=B;
    }
    else if(naStranu=='c')
    {
        Priamka c(A,B);
        D=c.getStred();
        E=C;
    }
    else
    {
        std::cout<<"Neznama strana";

    }
    return {D,E};
}

Priamka Trojuholnik::getVyska(char naStranu) const {
    Bod Prvy;
    Bod Druhy;
    Bod normalovy;
    if (naStranu == 'a') {
        Bod normalovy = Priamka(B, C).getNormalovy();
        Bod Prvy = A;
        Bod Druhy = A + normalovy;
    } else if (naStranu == 'b') {
        Bod normalovy = Priamka(A, C).getNormalovy();
        Bod Prvy = B;
        Bod Druhy = B + normalovy;
    } else if (naStranu == 'c') {
        Bod normalovy = Priamka(A, B).getNormalovy();
        Bod Prvy = C;
        Bod Druhy = C + normalovy;
    } else {
        std::cout << "Neznama strana";
        Bod Prvy = Bod();
        Bod Druhy = Bod();
    }
    return {Prvy, Druhy};
}

void Trojuholnik::vypisOpisanaKruznica() const {
    Bod StredK= getOsStrany('a').getPoloha(getOsStrany('b')).getBodPriesecnika();
    float polomerK = StredK.getDistance(A);
    using namespace beta;
    cout<<"(x "<<showpos<<(-1)*StredK.getX()<<")^2 +"<<"(y"<<showpos<<(-1)*StredK.getY()<<")^2 ="<<noshowpos<<polomerK*polomerK;
}

Priamka Trojuholnik::getOsStrany(char naStranu) const {
    Bod Stred;

    Bod Druhy;// druhy bod na osi ako sucet stredu a smeroveho vektora osi
    if (naStranu == 'a') {
        Stred=Priamka(B,C).getStred();
        Druhy = Stred+Priamka (B,C).getNormalovy();

    }
    else if (naStranu == 'b') {
        Stred=Priamka(A,C).getStred();
        Druhy = Stred+Priamka (A,C).getNormalovy();
    }
    else if (naStranu == 'c') {
        Stred=Priamka(A,B).getStred();
        Druhy = Stred+Priamka (A,B).getNormalovy();
    }
    else {
        std::cout << "Neznama strana";

    }
    return Priamka{Stred,Druhy};
}




/*
 * eni
 * zwei
 * drei
 * vier
 * funf
 * sechst
 * sieben
 * acht
 * neun
 * zehn
 * elf
 * zwolf
 * DREIZEHN
 * VIERZEHN
 * funfzehn
 * sechszehn
 * siebzehn
 * achtzehn
 * neunzehn
 * zwanzig
 * einundzwanzig
 * zweiundzwanzig
 * dreiundzwanzig
 * vierundzwanzig
 * funfundzwanzig
 * sechsundzwanzig
 * siebundzwanzig
 * achtundzwanzig
 * neunundzwanzig
 * dreizig
 * einunddreizig
 * zweiunddreizig
 * dreiunddreizig
 * vierunddreizig
 * funfunddreizig
 * sechsunddreizig
 * siebunddreizig
 * achtunddreizig
 * neununddreizig
 * vierzig
 * eindundvierzig
 * zweiundvierzig
 * dreiundvierzig
 * vierundvierzig
 * funfundvierzig
 * sechsundviezig
 * siebundviezig
 * achtundvierzig
 * neunundvierzig
 * funfzig
 * einundfunfzig
 * zweiundfunfzig
 * dreiundfunfzig
 * vierundfunfzig
 * funfundfunfzig
 * sechsundfunfzig
 * siebundfunfzig
 * achtundfunfzig
 * neunundfunfzig
 * sechzig
 * einundsechzig
 * zweiundsechzig
 * dreiundsechzig
 * vierundsechzig
 * funfundsechzig
 * sechsundsechzig
 * siebundsechzig
 * achtundsechzig
 * neunundsechzig
 * siebzig
 * einundsiebzig
 * zweiundsiebzig
 * dreiundsiebzig
 * vierundsiebzig
 * funfundsiebzig
 * sechsundsiebzig
 * siebundsiebzig
 * achtundsiebzig
 * neunundsiebzig
 * achtzig
 * einundachtzig
 * zweiundachtzig
 * dreiundachtzig
 * vierundachtzig
 * funfundachtzig
 * sechsundachtzig
 * siebundachtzig
 * achtundachtzig
 * neunundachtzig
 * neunzig
 * einundneunzig
 * zweiundneunzig
 * dreiundneunzig
 * vierundneunzig
 * funfundneunzig
 * sechsundneunzig
 * siebundneunzig
 * achtundneunzig
 * neunundneunzig
 * ein hundert
 */