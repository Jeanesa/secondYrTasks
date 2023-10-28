//Created by: Jeanesa Dugang
//BSCS 2A
//ADT List of players using array of structures
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define MAX 5
using namespace std;

typedef struct Player {
    string name;
    int FGA;
    int FGM;
    double FGP;
} REC;

//DATA STRUCTURE
typedef struct List {
    REC bp[MAX];
    int last;
} LIST;

//Class definition
class MyList {
private:
    LIST L;
    bool isFull();
    bool isEmpty();
    int locate(string n);
    int locatePos(string n);
    double computeFGP(int a, int m);

public:
    void makenull();
    void insertSort(REC r);
    void deleteRecord(string n);
    void displayRecord();
    void addRecord();
    void updateRecord(string n); //update the fga and/or fgm only given the name of the record
    void saveData();
    void retrieveData();
};

int menu();

int main() {
    REC pd;
    MyList pl;
    pl.makenull();

    while (true) {
        switch (menu()) {
        case 1:
            pl.addRecord();
            break;
        case 2:
			pl.displayRecord();
            cout << "Enter player name to update: ";
            cin >> pd.name;
            pl.updateRecord(pd.name);
            break;
        case 3:
        	pl.displayRecord();
            cout << "Enter player name to delete: ";
            cin >> pd.name;
            pl.deleteRecord(pd.name);
            break;
        case 4:
            pl.displayRecord();
            break;
        case 5:
            pl.saveData();
            break;
        case 6:
            pl.retrieveData();
            break;
        case 7:
            exit(0);
        default:
            cout << "1 to 7 only." << endl;
            system("pause");
        }
    }
}

void MyList::makenull(){
	L.last = -1;
}

void MyList::addRecord() {
    int i = L.last + 1;

    if (isFull()) {
        cout << "List is full." << endl;
    }
    else {
        cout << "Enter player " << i+1 << " name: ";
        cin >> L.bp[i].name;
        cout << "Input field goal attempts: ";
        cin >> L.bp[i].FGA;
        cout << "Input field goal made: ";
        cin >> L.bp[i].FGM;

        if (L.bp[i].FGA == 0) {
            L.bp[i].FGP = 0.0;
        }
        else {
            L.bp[i].FGP = ((double)(L.bp[i].FGM) / (L.bp[i].FGA)) * 100.0;
        }

        insertSort(L.bp[i]);
        L.last++;
    }
    cout << endl;
    system("pause");
}

bool MyList::isFull() {
    return (L.last == MAX - 1);
}

bool MyList::isEmpty() {
    return (L.last == -1);
}

int MyList::locatePos(string n) {
    int i;
    for (i = 0; i <= L.last; i++) {
        if (n < L.bp[i].name)
            return i;
    }
    return i;
}

int MyList::locate(string n) {
    for (int i = 0; i <= L.last; i++) {
        if (n == L.bp[i].name)
            return i;
    }
    return -1; // Not found
}

void MyList::insertSort(REC r) {
    int p, i;

    p = locatePos(r.name);
    for (i = L.last; i >= p; i--) {
        L.bp[i + 1] = L.bp[i];
    }
    L.bp[p] = r;
}

void MyList::displayRecord() {
    system("cls");

    cout << "NO.)\tPLAYER\t\tFGA\tFGM\tFGP\tREMARKS" << endl;
    if (isEmpty()) {
        cout << "No data to show. Add a record." << endl;
    }
    else {
        cout << fixed << setprecision(2);
        for (int i = 0; i <= L.last; i++) {
            cout << i + 1 << ".)\t" << L.bp[i].name << "\t\t" << L.bp[i].FGA << "\t" << L.bp[i].FGM << "\t" << L.bp[i].FGP << "%\t" << (L.bp[i].FGP > 50.0 ? "HIGH" : "LOW") << endl;
        }
    }

    cout << endl;
    system("pause");
}

void MyList::deleteRecord(string n) {
    int p;

    if (isEmpty()) {
        cout << "No data to show. Add a record." << endl;
    }
    else {
        p = locate(n);
        if (p != -1) {
            for (int i = p; i < L.last; i++) {
                L.bp[i] = L.bp[i + 1];
            }
            L.last--;
            cout << "Successfully Deleted!" << endl;
        }
        else {
            cout << "Player not found" << endl;
        }
    }
    cout << endl;
    system("pause");
}

void MyList::updateRecord(string n) {
    int p;
    string updateField;

    if (isEmpty()) {
        cout << "No data to show. Add a record." << endl;
    }
    else {
        p = locate(n);
        if (p == -1) {
            cout << "Record with name '" << n << "' not found." << endl;
        }
        else {
            cout << "Record found. Enter new FGA and/or FGM:" << endl;
            cout << "Input New FGA: ";
            cin >> L.bp[p].FGA;
            cout << "Input New FGM: ";
            cin >> L.bp[p].FGM;

            if (L.bp[p].FGA == 0) {
                L.bp[p].FGP = 0.0;
            }
            else {
                L.bp[p].FGP = ((double)(L.bp[p].FGM) / (L.bp[p].FGA)) * 100.0;
            }

            cout << "Record updated successfully." << endl;
        }
        system("pause");
    }
    cout << endl;
    system("pause");
}

void MyList::saveData() {
    ofstream file("player_data.txt");

    if (!file.is_open()) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i <= L.last; i++) {
        file << L.bp[i].name << " " << L.bp[i].FGA << " " << L.bp[i].FGM << " " << L.bp[i].FGP << endl;
    }
    
    cout << "Data saved successfully." << endl;
    system("pause");
    file.close();
}

void MyList::retrieveData() {
    ifstream file("player_data.txt");

    if (!file.is_open()) {
        cout << "Error opening file for reading." << endl;
        return;
    }

    L.last = -1;

    while (!file.eof() && L.last < MAX - 1) {
        L.last++;
        file >> L.bp[L.last].name >> L.bp[L.last].FGA >> L.bp[L.last].FGM >> L.bp[L.last].FGP;
    }

    cout << "Data retrieved successfully." << endl;
    system("pause");
    file.close();
}

int menu() {
    int userChoice;

    system("cls");
    cout << "\tMENU" << endl << endl;
    cout << "1.) Add a Record" << endl;
    cout << "2.) Update a Record" << endl;
    cout << "3.) Delete a Record" << endl;
    cout << "4.) Display Record" << endl;
    cout << "5.) Save Data" << endl;
    cout << "6.) Retrieve Data" << endl;
    cout << "7.) Exit" << endl;
    cout << endl << "Select (1-7): ";
    cin >> userChoice;
    cout << endl;

    if (cin.fail()) {
        cout << "Invalid input. Please enter a numeric choice." << endl << endl;
        cin.clear();
        cin.ignore();
    }
    return userChoice;
}

