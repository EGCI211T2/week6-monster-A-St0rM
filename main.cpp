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

     cout << "Monsters BEFORE snap:\n";
    for (int i = 0; i < n; i++) {
        cout << "Monster [" << i << "]\n";
        m[i].display();
        cout << "----\n";
    }
 
 /* Add some story*/
cout << "\nThanos arrives on the battlefield, searching for the Infinity Stones...\n";

++T;
cout << "Thanos found his first stone. Power surges through him.\n";
++T;
cout << "Thanos found another stone. The ground trembles.\n";
T.snap_finger(m,n);

cout << "\nThe monsters regroup, thinking they are safe for now...\n";

++T;
cout << "Thanos takes another stone from a fallen enemy.\n";
++T;
cout << "The sky darkens as Thanos grows stronger.\n";
T.snap_finger(m,n);

cout << "\nOnly a few stones remain. The monsters start to panic...\n";

++T;
cout << "Thanos smiles as he picks up the fifth stone.\n";
++T;
cout << "The final stone clicks into place on the gauntlet.\n";
T.snap_finger(m,n);

cout << "\nSilence falls over the battlefield.\n";

  cout << "\nMonsters AFTER snap:\n";
for (int i = 0; i < n; i++) {
    if (m[i].getHP() > 0) {
        cout << "Monster [" << i << "]\n";
        m[i].display();
        cout << "----\n";
    }
}


  delete [] m;

}
