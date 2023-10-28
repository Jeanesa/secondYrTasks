//Created by: Jeanesa Dugang
//BSCS 2A

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

typedef struct Player {
    string name;
    int FGA;
    int FGM;
    float FGP;
    Player* next;
}REC;

class MyList{
	private:
		Player* head;
	public:
		MyList() : head(NULL) {}
        ~MyList(){
            while (head != NULL){
                Player* temp = head;
                head = head -> next;
                delete temp;
        }
    }
    
    void addRecord();
    void deleteRecord();
    void updateRecord();
    void displayRecord();
    float computeFGP (int FGA, int FGM);
    
};

int menu();

int main(){
	MyList pl;
	
	while (true){
	switch(menu()){
            case 1:
                pl.addRecord();
                break;
            case 2:
                pl.updateRecord();
                break;
            case 3:
            	pl.displayRecord();
                pl.deleteRecord();
                break;
            case 4:
                pl.displayRecord();
                break;
            case 5:
            	exit(0);
                break;
            default:
                cout << "Invalid Choice. Try Again" << endl;
        }
	}
	return 0;
}

void MyList::addRecord(){
    Player* newRecord = new Player;
    
    cout << "Enter player name: ";
	cin.ignore();
    getline(cin, newRecord->name);
    cout << "Input field goals attempt: ";
    cin >> newRecord->FGA;
    cout << "Input field goals made: ";
    cin >> newRecord->FGM;
    
    newRecord -> next = head;
    head = newRecord;
    
    cout << endl;
    cout << "Player Record Added!" << endl;
    system("pause");
}

void MyList::deleteRecord(){
	int p;
    string n;
    if(head == NULL){
        cout << "No Current Record! " << endl;
    }
    else{
        cout << "Enter player name to delete: ";
        cin >> n;

        if(head->name == n){
            Player* temp = head;
            head = head->next;
            delete temp;
            cout << "Sucessfully Deleted!" << endl;
            system("pause");
            return;
        }

        Player* p = head;
        Player* q = head;
        while (p!=NULL) {
            if (p->name == n) {
                q->next = p->next;
                delete p;
                cout << "Sucessfully Deleted!" << endl;
                system("pause");
                return;
            }
            q=p;
            p=p->next;
        }
    }
    cout << "Player not found! " << endl;
    system("pause");
}

void MyList::updateRecord(){
	Player* p;
    p = head;
    string n;

    cout << "Enter player name: ";
    cin >> n;

    while(p != NULL){
        if(p->name == n){
            cout << "Enter player's new field goals attempt: ";
            cin >> p->FGA;
            cout << "Enter player's new field goals made: ";
            cin >> p->FGM;
            cout << "Player Successfully Updated!" << endl;
            system("pause");
            return;
        }
        p = p->next;
    }
    cout << "Player Doesn't Exist" << endl;
    system("pause");
}

void MyList::displayRecord() {
    system("cls");
    
    cout << "NO.)\tPLAYER\t\t\tFGA\tFGM\tFGP\tREMARKS" << endl;
    
    if (head == NULL) {
        cout << "No Current Record!" << endl;
    } else {
        Player* p = head;
        int i = 0;
        while (p != NULL) {
            float FGP = computeFGP(p->FGA, p->FGM);
            string result = FGP > 50.00 ? "HIGH" : "LOW";
            cout << i + 1 << ".)\t" << p->name << "\t\t" << p->FGA << "\t" << p->FGM 
                << "\t" << fixed << setprecision(2) << FGP << "%\t" << result << endl;
            p = p->next;
            i++;
        }
    }
    
    cout << endl;
    system("pause");
}

float MyList::computeFGP(int FGA, int FGM){
    if (FGA == 0) {
    	return 0.0;
	} else {
		float FGP = (FGM/(float)FGA) * 100;
    return FGP;
	}
}

int menu() {
    int userChoice;

    system("cls");
    cout << "\tMENU" << endl << endl;
    cout << "(1) Add a Record" << endl;
    cout << "(2) Update a Record" << endl;
    cout << "(3) Delete a Record" << endl;
    cout << "(4) Display Record" << endl;
    cout << "(5) Exit" << endl;
    cout << endl << "Select (1-5): ";
    cin >> userChoice;
    cout << endl;

    if (cin.fail()) {
        cout << "Invalid input. Please enter a numeric choice." << endl << endl;
        cin.clear();
        cin.ignore();
        system("pause");
    }
    return userChoice;
}
