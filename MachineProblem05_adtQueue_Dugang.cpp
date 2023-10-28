//Created by: Jeanesa Dugang
//BSCS 2A
#include <iostream>
using namespace std;

#define MAX 5

typedef struct queue {
	int data[MAX];
	int front;
	int rear;
	int count;
} QUEUE;

class Qclass {
	private:
		QUEUE Q;
		bool isFull();
		bool isEmpty();
		
	public:
		void makenull();
		void enqueue(int val);
		void dequeue();
		void display();
		int menu();
};

int menu();

int main() {
	Qclass qval;
	qval.makenull();
	
	while (true){
		switch (menu()) {
			case 1:
				int enteredVal;
				cout << "Enter value to enqueue: ";
				cin >> enteredVal;
				qval.enqueue(enteredVal);
				qval.display();
				break;
			case 2:
				qval.dequeue();
				qval.display();
				break;
			case 3:
				qval.display();
				break;
			case 4:
				exit(0);
			default:
                cout << "Invalid choice. Please select a valid option." << endl;
                system ("pause");
                break;
		}
	}
	
}

void Qclass::makenull(){
	Q.rear = -1;
	Q.front = 0;
	Q.count = 0;
}

bool Qclass::isFull(){
	return Q.count == MAX;
}

bool Qclass::isEmpty(){
	return Q.count == 0;
}

void Qclass::enqueue(int val){
	if (isFull()){
		cout << "Queue is full." << endl;
	} else {
		Q.rear = (Q.rear + 1) % MAX;
		Q.data[Q.rear] = val;
		Q.count++;
	}
}

void Qclass::dequeue(){
	if (isEmpty()){
		cout << "Queue is empty." << endl;
	} else {
		int val = Q.data[Q.front];
		Q.front = (Q.front + 1) % MAX;
		Q.count--;
		cout << "Dequeued value: " << val << endl;
	}
}

void Qclass::display(){
	if (!isEmpty()){
		cout << "Queue elements are: ";
		int i = Q.front;
		int count = Q.count;
		while (count > 0) {
			cout << Q.data[i] << " ";
			i = (i + 1) % MAX;
			count--;
		}
		cout << endl;
	} else {
		cout << "Queue is empty" << endl;
	}
	cout << endl;
	system ("pause");
}

int menu(){
	int userChoice;
	
	system ("cls");
	cout << "\tMENU" << endl;
	cout << "1.) ENQUEUE" << endl;
	cout << "2.) DEQUEUE" << endl;
	cout << "3.) DISPLAY" << endl;
	cout << "4.) EXIT" << endl;
	cout << endl;
	cout << "Select 1-4: ";
	cin >> userChoice;
	cout << endl;
	
	if (cin.fail()) {
        cout << "Invalid input. Please enter a numeric choice." << endl << endl;
        cin.clear();
        cin.ignore();
    }
    return userChoice;
}

