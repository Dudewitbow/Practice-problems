#include <iostream>
using namespace std;

//global array for memorization
int fibo[1024] = {0};

int Fib(int);

int main() {
	fibo[1] = 1;
	int choice = 1;
	while(choice > -1){
		cout << "Which nth place in the fibonacci sequence would you like to know(up to 1024. exit with any value < 0): ";
		cin >> choice;
		cin.ignore();
		cout << "\nThe number in the number " << choice << " index is " << Fib(choice) << "\n\n";
	}
	return 0;
}

int Fib(int a){
	int index = a;
	if(fibo[index] != 0) return fibo[index];
	while(index > 0){//find the last non 0 index
		if(fibo[index] == 0) index--;
		else break;
	}
	while(index < a){
		fibo[index+1] = fibo[index] + fibo[index-1];
		index++;
	}
	return fibo[a];
}
