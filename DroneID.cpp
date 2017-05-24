#include <iostream>
#include <algorithm> //sort, shuffle

using namespace std;

int main() {
	//create the array
	int size = 100;
	int list[size];

	//fill the array
	for(int i = 0; i < size/2; i++)
	{
		list[i] = i;
		list[i+(size/2)]= i;
	}

	//shuffle the array
	random_shuffle(&list[0], &list[size]);

	//output list for testing purposes
	for(int i = 0; i < size; i++){
		cout << list[i] << " ";
	}
	cout << "\n\n";

	//removed last element of the list
	cout << "the element removed is " << list[size-1] << endl << endl;
	int removed = list[size-1];
	list[size-1] = 999; //putting an invalid value into the array, normally, should just remove the element from the array

	//sort the array nlogn
	//sort(list[0], list[size-1]);
	sort(list, list+size);

	//output list for testing purposes
	for(int i = 0; i < size; i++){
		cout << list[i] << " ";
	}
	cout << "\n\n";

	//modified binary search for missing element logn
	int smallestNonMatch; //holds the index for the smallest non matching pair
	int begin = 0;
	int end = size-1;
	while(begin < end){
		int middle = (begin+end)/2;
		int rem = middle%2;
		if(rem == 1){//check left for correct value as each pair starts with even number e.g 0&1 should  match, 2&3 should match
			if(list[middle] == list[middle-1]){
				begin = middle+1;
			}
			else{
				end = middle;
			}
		}
		else{//rem is 0
			if(list[middle] == list[middle+1]){
				begin = middle +2;
			}
			else{
				end = middle;
			}
		}
		if(list[middle] != list[middle-1] && list[middle] != list[middle+1]){//found the culprit
			smallestNonMatch = middle;
			break;
		}
	}

	cout << "\n\nIf this is correct, the next two values should be the same.\nRemoved Value: " << removed << "\nsmallestNonMatch: " << list[smallestNonMatch];

	return 0;
}
