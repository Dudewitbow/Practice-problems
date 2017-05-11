#include <iostream>
using namespace std;



struct floorValues{
	int safeFloor;
	int dangerFloor;
	int numCheck;
};

floorValues findMaxFloor(int);

int main(){
	int worstCase;
	floorValues arrWC[100];
	int worstAll = 0; //holds the overall worst value

	for(int i = 1; i < 101; i++){ //test all floor values. i represents the breaking floor
		arrWC[i-1] = findMaxFloor(i);
		worstCase = arrWC[i-1].numCheck;
		if(worstCase > worstAll) worstAll = worstCase;
	}

	cout << "The overall worst case for number of checks is " << worstAll << "\n\n";
	cout << "Printing values of the entire process for manual checking:\nSafe Floor should always be danger floor -1, else there is an error\nValues of all -1 means floor was improperly checked\n\n";

	for(int i = 0; i < 100; i++){
		cout << "Floor " << i+1 << ": Safe Floor: " << arrWC[i].safeFloor << "    Danger Floor: " << arrWC[i].dangerFloor << "    Number of checks: " << arrWC[i].numCheck << endl;
	}

	return 0;
}

floorValues findMaxFloor(int a){
	int eggCount = 2;
	int floorCheckBase = 0;//to hold last check major floor
	int checkCount = 0;
	int floorCheck;
	floorValues correct;
	correct.safeFloor = -1;
	correct.dangerFloor = -1;
	correct.numCheck = -1;


	for(int i = 14; i > 3; i--){//14 to 3 checks 1-99 with Worst Case 14
		floorCheck = floorCheckBase + i;
		checkCount++;
		if(floorCheck >= a){
			eggCount--;
			if(eggCount == 0) {//theoretically should not happen
				cout << "You broke both eggs you dimwit";
				return correct;
			}
			//case breaking floor is < floorCheck
			for(int j = 1; j < i; j++){//value is inbetween floorCheckBase and floorCheck. incrementally checks 1 by one to find the problematic floor
				floorCheck = floorCheckBase + j;
				checkCount++;
				if(floorCheck == a) {
					correct.safeFloor = floorCheck - 1;
					correct.dangerFloor = a;
					correct.numCheck = checkCount;
					return correct;
				}
			}
			//case breaking floor is floorCheckBase + i; (== a)
			correct.safeFloor = floorCheck;
			correct.dangerFloor = a;
			correct.numCheck = checkCount;
			return correct;
		}
		else{
			floorCheckBase += i;
			continue;
		}
	}

	if(a == 100){// checked floor 99, then you know 100 is the problematic floor
		checkCount++;
		correct.safeFloor = floorCheck;
		correct.dangerFloor = a;
		correct.numCheck = checkCount;
	}

	return correct; //returns all -1 values
}
