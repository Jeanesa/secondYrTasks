// Created by: Jeanesa Dugang
//BSCS-2A

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX 5

typedef struct playerInfo {
        string name;
        int FGA, FGM;
        float FGP;
    } player[MAX];

class Players {
private:
	playerInfo player [MAX];
    int last = -1;

public:
    void addRecord();
    void deleteRecord();
    void displayRecord();
    int isFull();
    int isEmpty();
    int findPos(int x);
};

int main() {
    Players player;
    int userChoice;

    do {
        cout << endl << "\t\tMENU" << endl;
        cout << "1.) ADD RECORD" << endl;
        cout << "2.) DELETE RECORD" << endl;
        cout << "3.) DISPLAY RECORD" << endl;
        cout << "4.) EXIT" << endl;
        cout << "Select (1-4): ";
        cin >> userChoice;
        cout << endl;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a numeric choice." << endl << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        switch (userChoice) {
            case 1:
                player.addRecord();
                break;
            case 2:
                player.deleteRecord();
                break;
            case 3:
                player.displayRecord();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (userChoice != 4);

    return 0;
}

void Players::addRecord() {
	int i;
    if (isFull()) {
        cout << "Array is FULL!" << endl;
    } else {
        last++;
		
        cout << "Enter player " << last + 1 << " name: ";
        cin >> player[last].name;
        cout << "Input Field Goal Attempts: ";
        cin >> player[last].FGA;
        cout << "Input Field Goal Made: ";
        cin >> player[last].FGM;

        if (player[last].FGA == 0) {
            player[last].FGP = 0.0;
        } else {
            player[last].FGP = ((float)(player[last].FGM) / (player[last].FGA)) * 100.0;
        }

        cout << "***Player successfully added!***" << endl;
    }
    cout << endl;
    system("pause");
}

void Players::deleteRecord() {
    int x;
    displayRecord();

    if (isEmpty()) {
        cout << endl << "Array is EMPTY. Please add a record." << endl;
    } else {
    	cout << "Enter player number to delete: ";
    	cin >> x;
        int p = findPos(x);
        if (p != -1) {
            for (int i = p; i < last; i++) {
                player[i] = player[i + 1];
            }
            last--;
            cout << "Successfully Deleted!" << endl;
        } else {
            cout << "Player not found" << endl;
        }
    }
    cout << endl;
    system("pause");
}

void Players::displayRecord() {
    system("cls");
    cout << "NO.)\tPLAYER\t\tFGA\tFGM\tFGP\tREMARKS" << endl;

    if (isEmpty()) {
        cout << "No Record to Display" << endl;
    } else {
    	cout << fixed << setprecision(2);
        for (int i = 0; i <= last; i++) {
            cout << i + 1 << ".)\t" << player[i].name << "\t\t" << player[i].FGA << "\t" << player[i].FGM << "\t" << player[i].FGP << "%\t" << (player[i].FGP > 50.0 ? "HIGH" : "LOW") << endl;
        }
    }
    cout << endl;
    system("pause");
}

int Players::isFull() {
    return (last == MAX - 1);
}

int Players::isEmpty() {
    return (last == -1);
}

int Players::findPos(int x) {
    for (int i = 0; i <= last; i++) {
        if (i + 1 == x) {
            return i;
        }
    }
    return -1;
}

