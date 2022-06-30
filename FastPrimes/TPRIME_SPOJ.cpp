#include <iostream>
#include <vector>

#define MAX 100000000

using namespace std;

int seive[MAX];

void create_seive(){
	seive[0] = seive[1] = 1;
    for(long long int i = 2; i < MAX; i+=2) seive[i] = 1;
    seive[2] = 0;
	for(long long int i = 3; i < MAX; i+=2){
		if(seive[i] == 0){
			for(long long int j = i*i; j < MAX; j+=i){
				seive[j] = 1;
			}
		}
	}
}

int main()
{
    create_seive();
    int count = 1;
    for(int i = 0; i < MAX; i++){
        if(seive[i] == 0){
            if(count %100 == 1){
                cout << i << endl;
            }
            count++;
        }
    }

    return 0;
}