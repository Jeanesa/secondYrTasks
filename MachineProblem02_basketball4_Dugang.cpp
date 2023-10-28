//Created by: Jeanesa Dugang
//BSCS-2A
#include <iostream>
#include <string>
#define MAX 2

using namespace std;

typedef struct playerInfo {
    string name;
    int FGA, FGM;
    float FGP;
} playerInfo;

class PlayerRecord {
private:
    playerInfo player[MAX];

public:
    void getRecord(int i);
    void displayRecord(int i);
    float computeFGP(int FGA, int FGM);
};

void PlayerRecord::getRecord(int i) { 
    cout << "Enter player " << i + 1 << " name: ";
    cin >> player[i].name;
    cout << "Input Field Goal Attempts: ";
    cin >> player[i].FGA;
    cout << "Input Field Goal Made: ";
    cin >> player[i].FGM;
}


void PlayerRecord::displayRecord(int i) {
    float FGP = computeFGP(player[i].FGA, player[i].FGM);
    cout << i + 1 << ".) " << player[i].name << "\t" << player[i].FGA << "\t" << player[i].FGM << "\t" << FGP << "\t" << (FGP > 50.0 ? "HIGH" : "LOW") << endl;
}

float PlayerRecord::computeFGP(int FGA, int FGM) {
    if (FGA == 0) {
        return 0.0;
    }
    return ((float)FGM / FGA) * 100;
}

int main() {
    PlayerRecord player[MAX];

    for (int i = 0; i < MAX; i++) {
        player[i].getRecord(i);
    }

    cout << endl << "   PLAYER\tFGA\tFGM\tFGP\tREMARKS\n";
    for (int i = 0; i < MAX; i++) {
        player[i].displayRecord(i);
    }
    return 0;
}
