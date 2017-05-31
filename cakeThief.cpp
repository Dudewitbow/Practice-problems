#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

class CakeType
{
public:
    int weight_;
    long long value_;

    CakeType(size_t weight = 0, long long value = 0) :
        weight_(weight),
        value_(value)
    {
    }
};

class CakeValue : public CakeType
{
public:
	double ratio;

	CakeValue(size_t weight = 0, long long value = 0){
		weight_ = weight;
		value_ = value;
		if(weight == 0) ratio = -1;
		else ratio = (double)value/(double)weight;
	}
};

int main() {
	srand (time(NULL)); //seed randomizer
	vector<CakeValue> list;
	int bagSize = rand()%200;
	double maxMonetary = 0;

	for(int i = 0; i < 10; i++){//10 cake types
		list.push_back(CakeValue(rand()%100, rand()%100));
	}

	for(int i = 0; i < 10; i++){//sort by weight
		for(int j = i+1; j < 10; j++){
			if(list[i].weight_ > list[j].weight_){
				swap(list[i], list[j]);
			}
		}
	}

	for(int i = 0; i < 10; i++){//output cake values
		cout << "Cake " << i+1 << "\nweight: " << list[i].weight_ << "\nValue: " << list[i].value_ << "\nRatio: " << list[i].ratio << "\n\n";
	}

	cout << "You walk into a vault of cakes with a bag size of " << bagSize << "\n\n";

	if(bagSize == 0){
		if(list[0].weight_ == 0) cout << "Can't hold anything, but one of the cakes is weightless, so you're rich bitch";
		else cout << "Can't hold anything, but none of the cakes are weightless, so you are shit out of luck";
	}

	else if(list[0].weight_ == 0) cout << "You can hold stuff, but one of the cakes is weightless, so you're rich bitch";

	else{
		while(bagSize > list[0].weight_){//fills bag untill the lightest cake cannot fit what's left of the bag
			double maxCakeRatio = 0;
			int index = 0;
			for(int i = 0; i < 10; i++){//find the best ratio cake to store
				if(list[i].weight_ > bagSize) break; //leaves when you're checking cakes too heavy for what's left of the bag to hold
				else if(list[i].ratio > maxCakeRatio){
					index = i;
					maxCakeRatio = list[i].ratio;
				}
			}
			while(bagSize > list[index].weight_){//fill'r up with the highest value ratio of cake
				bagSize -= list[index].weight_;
				maxMonetary += list[index].value_;
			}
		}
		cout << "You got away with " << maxMonetary << "$ worth of cakes from the vault";
	}

	return 0;
}
