#include<map>
#include<algorithm>
#include<iostream>
#include<string>
#include<cmath>
#include<numeric>
#include<vector>
#define pb push_back
#define DEBUG1(a) cout<<a<<endl
#define DEBUG2(a, b) cout<<a<<"\t"<<b<<endl
#define DEBUG3(a, b, c) cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define FOR(i,c) for(i=0;i<c;i++)
#define FOR1E(i,c) for(i=1;i<=c;i++)
#define DISPVEC(i,vec) for(i=0;i<vec.size();i++) \
						cout<<vec[i]<<"\t";
						
using namespace std;
int INF = 10000000;
class TheNumberGameDivTwo{
public:
	/* Assumption --> optimal choice is the one which leads to a prime. Else choose the first divisor */
	string find(int n) {
		int itr = 0;
		int i;
		map<int, vector<int> > dp;
		
		// checking isprime func 
		vector<int> dp1(n,0);
		for(i=2;i<=n;i++){
			DEBUG2("n", i);
			vector<int> res = findDivisors(i, dp);						
			for(int j=0;j<res.size();j++) {
				if(isPrime(i-res[j])){
					// if u think u can get to a prime number, then the current owner is winner
					if(dp1[i-res[j]]
				}
			}
			if(i == res.size())
				n-=res[0];
			itr++;
		}
		if(itr%2 ==0)
			return "Brus";
		else
			return "John";
	}
	
	bool isPrime(int n) {
		int sq;
		sq = sqrt(n);	
		if(n<=2)
			return true;
		for(int i=2;i<sq;i++) {
			if(n%i==0) {
				return false;
			}	
		}
		return true;
	}

	vector<int> findDivisors(int n, map<int, vector<int> >& dp) {
		map<int, vector<int> >::iterator it;
		it = dp.find(n);
		if(it != dp.end())
			return it->second;
		
		// find the divisors 
		vector<int> res;		
		
		int k = 2;
		for(k=2;k<n;k++) {
			if(n%k == 0)
				res.pb(k);
		}
		dp[n] = res;
		return res;
	}	
};


int main() {
	TheNumberGameDivTwo tn;
	cout<<tn.find(747);

}