#include "trojuholnik.h"





int main() {
using namespace alpha;

Bod A(1, 5);
Bod B(2,8);
Priamka pAB(A,B);
cout<<pAB;
PR paAB(A,B);
cout<<paAB;
Priamka pCD({4,8},{7,9});
cout<<pCD;
PR paCD(pCD);// vytvara parametricku rovnicu z obycajnej priamky
cout<<paCD;
    return 0;
}
