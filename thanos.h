#ifndef thanos_h
#define thanos_h

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

//Thanos::Thanos(int s, int h) : stones(s), hp(h) {}

Thanos::~Thanos() {}

void Thanos::operator++() {
    if (stones < 6) stones++;
}

void Thanos::snap_finger(monster m[], int n) {
    cout << "\n--- Thanos snaps! ---\n";
    cout << "Stones: " << stones << " | Thanos HP: " << hp << "\n\n";

    cout << "Monsters BEFORE snap:\n";
    for (int i = 0; i < n; i++) {
        cout << "Monster [" << i << "]\n";
        m[i].display();
        cout << "----\n";
    }

    if (stones != 6) {
        cout << "Snap failed: need 6 stones.\n";
        return;
    }

    // Monster with 0 hp used for comparison
    monster zero("ZERO", 0, 0);

    int kills = n / 2;    
    int killed = 0;

    // kill random monsters 
    while (killed < kills) {
        int idx = rand() % n;

        // alive? (hp > 0)
        if (m[idx] > zero) {
            // kill by decrementing until hp becomes 0
            while (m[idx] > zero) {
                --m[idx];
            }
            killed++;
        }
    }

    cout << "\nSnap success! Killed " << kills << " monsters.\n";

    cout << "\nMonsters AFTER snap:\n";
    for (int i = 0; i < n; i++) {
        cout << "Monster [" << i << "]\n";
        m[i].display();
        cout << "----\n";
    }

#endif
