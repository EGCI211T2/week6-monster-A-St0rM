#ifndef thanos_h
#define thanos_h
using namespace std;
#include <iostream>
#include <cstdlib>
#include "monster.h"

class Thanos {
private:
	int stones;
	int hp; 
public:
 	Thanos(int = 0, int = 1000);
    ~Thanos();
    void snap_finger(monster[], int);
    void operator++();
};

Thanos::Thanos(int s, int h) : stones(s), hp(h) {}

Thanos::~Thanos() {}

void Thanos::operator++() {
    if (stones < 6) stones++;
}

void Thanos::snap_finger(monster m[], int n) {
    cout << "\n--- Thanos snaps! ---\n";
    cout << "Stones: " << stones << " | Thanos HP: " << hp << "\n\n";

    if (stones != 6) {
        cout << "Snap failed: need 6 stones.\n";
        return;
    }

    monster zero("ZERO", 0, 0);

    int kills = n / 2;
    int killed = 0;

    while (killed < kills) {
        int idx = rand() % n;

        if (m[idx] > zero) {          // alive
            while (m[idx] > zero) {   // kill it
                --m[idx];
            }
            killed++;
        }
    }

    cout << "\nSnap success! Killed " << kills << " monsters.\n";
}

#endif
