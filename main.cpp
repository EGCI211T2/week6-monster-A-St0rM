#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>


#include "monster.h"
#include "thanos.h"

int main(int argc, char* argv[]) {

  Thanos T;
  int n;
  cout<<"How many monsters?";
  cin>>n;
  srand(time(nullptr));


  monster *m=new monster[n];
 
  /* Add some story*/
  ++T;
  ++T;
  T.snap_finger(m,n);
  ++T;
  ++T;
  T.snap_finger(m,n);
  ++T;
  ++T;
  T.snap_finger(m,n);

  int i;
  for(i=0;i<n;i++)
      m[i].display();
  

  delete [] m;

}
