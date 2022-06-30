#include <iostream>
#include <vector>

#define MAX 100000000

using namespace std;

int seive[MAX];
int primes[MAX];

void create_seive(){
	int p = 1;
    seive[0] = seive[1] = 1;
    for(long long int i = 2; i < MAX; i+=2) seive[i] = 1;
    seive[2] = 0;
    primes[p++] = 2;
	for(long long int i = 3; i < MAX; i+=2){
		if(seive[i] == 0){
            primes[p++] = i;
			for(long long int j = i*i; j < MAX; j+=i){
				seive[j] = 1;
			}
		}
	}
}

int main()
{
    create_seive();
    cout << "DONE\n";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long int m;
        cin >> m;
        cout << primes[m] << endl;
        // cout << seive[1000000];
    }

    return 0;
}