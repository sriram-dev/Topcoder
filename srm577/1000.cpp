#include<map>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<numeric>
#include<vector>
#include<string>
#include<cstdio>
#include<cstdlib>
#define pb push_back
#define DEBUG1(a) cout<<a<<endl
#define DEBUG2(a, b) cout<<a<<"\t"<<b<<endl
#define DEBUG3(a, b, c) cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define FOR(i,c) for(i=0;i<c;i++)
#define FOR1E(i,c) for(i=1;i<=c;i++)
#define DISPVEC(i,vec) for(i=0;i<vec.size();i++) \
						cout<<vec[i]<<"\t"; \
						cout << "\n";
#define ll unsigned long long
using namespace std;

int gcd(int a, int b) {
	if(b ==0)
		return a;
	else 
		return gcd(b,a%b);
}

class EllysCoprimesDiv2{
public:
	int getCount(vector <int> numbers) {
		sort(numbers.begin(), numbers.end());
		int nadded = 0;
		int k;
		bool hasadded = false;
		DISPVEC(k, numbers);
		for(int i=0;i<numbers.size()-1;i++) {
			hasadded = false;
			if(gcd(numbers[i], numbers[i+1]) > 1) {
				for(int j= numbers[i]+1;j<numbers[i+1];j++) {
					if((gcd(numbers[i], j) == 1 ) && (gcd(j,numbers[i+1]) ==1)) {
						nadded++;
						hasadded = true;
						break;
					}
				}
				if(!hasadded)
					nadded+=2;
			}				
		}
		return nadded;
	}
};

int main() {
	EllysCoprimesDiv2 ec;
	int nums[] = {2200, 42, 2184, 17};
	vector<int> num(nums, nums+4);
	cout<<ec.getCount(num);
}