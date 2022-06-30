#include <iostream>
#include <vector>
using namespace std;


// typedef long long ll;

bool seive[32000];
vector<int> primes;

void create_seive(){
	seive[0] = seive[1] = 1;
    for(int i = 2; i < 32000; i+=2) seive[i] = 1;
    seive[2] = 0;
	for(int i = 3; i < 32000; i+=2){
		if(seive[i] == 0){
			primes.push_back(i);
			for(int j = i*i; j < 32000; j+=i){
				seive[j] = 1;
			}
		}
	}
}

bool isprime(long long int n){
    if(n == 1 || n == 0) return false; 
	for(int k = 0; primes[k]*primes[k] <= n; k++) if(n % primes[k] == 0) return false;
	return true;
}

int main() {
	create_seive();
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		long long int m, n;
		cin >> m >> n;
		while(m <= n){
			if(isprime(m)) cout << m << endl;
			m++;
		}
	}
	
	return 0;
}