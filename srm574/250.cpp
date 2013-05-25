#include<vector>
#include<iostream>
#include<string>
#include <sstream>
#include<cstdlib>
#include<cmath>
#include<map>
#include<algorithm>

#define NMAX 1e9
#define FOR(i,c) for(i=0;i<c;i++)
#define pb push_back
#define DEBUG(a) cout<<a<<endl
#define DEBUGS(str, a) cout<<str<<"\t"<<a<<endl
using namespace std;
class TheNumberGameDiv2 {
public:
	map<int,int> dp;
	
	int solve(int a, int b, bool has = false) {
		#ifdef PRINTD
		DEBUGS("a",a);
		DEBUGS("b", b);
		#endif
		if(dp.find(a) != dp.end())  {
			#ifdef PRINTD
			DEBUG("Found in dp ");
			DEBUGS("value is ", dp[a]);
			#endif
			return dp[a];
		}
		
		if(a == b)
			return 0;
			
		int ret;
		
		ret = a/10;
		if(ret < 1) { // means a single digit num
			ret = 1e9;
			dp[a] = ret;
			#ifdef PRINTD
			cout<<"A : " << a << "\t dp[a] :" << dp[a] <<endl;
			#endif
		}
		else {
			//DEBUG("not a single digit num");
			if((has == false) && (reverse(a) != a)) {
				//DEBUG("finding min of the two values");
				//DEBUGS("div10 val", ret);
				//DEBUGS("rev value", reverse(a));				
				dp[a] = min( 1+ solve(ret,b) , 1 + solve(reverse(a),b, true));
			}	
			else {
				//DEBUGS("only the res of div 10 value ", ret);
				dp[a] = 1 + solve(ret, b);
			}
			//DEBUGS("for a " , a);
			//DEBUGS("dp[a]", dp[a]);
		}
		//DEBUGS("reverse", reverse(123));
		//DEBUGS("a", a);
		//DEBUGS("solved dp[a] : ", dp[a]);
		return dp[a];
	}
	
	int Ndigits(int num) {
		int i;
		for(i=0;i<10;i++) {
			if( (num / (pow(10,i))) < 1)  {
				return i;
			}
		}
		return i;
	}
	
	int reverse(int num) {
		int res = 0, ndigits = 0;
		ndigits = Ndigits(num);		
		//DEBUGS("ndigits", ndigits);
		ndigits -= 1;
		while(num != 0) {
			res += (num %10) * pow(10, ndigits);
			num /= 10;
			ndigits --;
		}
		return res;
	}
	
	int minimumMoves(int A, int B) {
			// A to b 
			//cout<< rev1(123);
		int x =  solve(A, B);
		if(x >= 1e9) 
			return -1;
		else
			return x;
	}	
	
	

};


int main() {
	TheNumberGameDiv2 tn;
	cout<<tn.minimumMoves(9798147, 79817);
}