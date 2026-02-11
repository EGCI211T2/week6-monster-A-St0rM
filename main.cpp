#include <iostream>
using namespace std;

#include "monster.h"

int main(int argc, char* argv[]) {

    monster A("Alissa", 100,10);

    //monster x[3] = {{"Jens"},{"Micheal", 20}, {"test"}};
    monster c;

    monster *p;
    p= &A;
    p -> display();
    p = &c;
    p -> display();
    p = new monster("Sarina", 20, 5000);
    p -> display();

    //Delete one
    delete p;

    //Delete all monsters
    p = new monster[3];
    delete [] p;
  /*
 
 monster *p,x;
  p=&x;
  p=new monster;
 delete p;

 p=new monster[3];
 delete []p;

*/

}
