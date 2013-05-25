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
#include<queue>
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
int mod = 1000000007;
class UndoHistory{
public:
	int minPresses(vector <string> lines) {
		vector<string> undo;
		undo.pb("");
		string buf = "";
		int minp = 0, j, k;
		for(int i=0;i<lines.size();i++) {
			//find wht it takes using text buf elim
			int f1= mod, f2 = 2, nmat = 0, win = 0;
			nmat = nmatches(buf, lines[i]);
			if(nmat == buf.length())
				f1 = (buf.length() - nmat ) + (lines[i].length() - nmat); // no. of keypresses for backspace to get there 
			DEBUG2("f1", f1);
			// find wht it takes from finding in undo history
			for(j=lines[i].length();j>=0;j--) {
				if(find(undo.begin(), undo.end(), lines[i].substr(0,j)) != undo.end()) {
					//found in undo history
					DEBUG2("j: on f2 match" , j);
					f2 = 2 + lines[i].length() - (j);
					break;
				}
			}
			if(j==0)
				f2 = 2 + lines[i].length();
			DEBUG2("f2" , f2);
			DEBUG2("nmat " , nmat);
					
			//consider the best of the two 
			minp += min(f1, f2) + 1;
			
			DEBUG2("minp", minp);
			//add each char to undo history
			j =0 ;
			for(k = 1 ; k<= lines[i].length();k++) {
				if(find(undo.begin(), undo.end(), lines[i].substr(j,k)) == undo.end()) 
					undo.pb(lines[i].substr(j,k));
			}
			buf = lines[i];
		}
		return minp;
	}
	
	int nmatches(string buf, string line) {
		int v = 0;
		DEBUG1("--------inside nmat ------");
		for(int i=0;i<min(buf.length(), line.length());i++) {
			DEBUG2("buf[i]", buf[i]);
			DEBUG2("line[i]", line[i]);
			if(buf[i] == line[i]){
				DEBUG1("found a match");
				v++;
			}
			else 
				return v;
		}
		return v;
	}
};

int main() {
	string s[] = {"b", "a", "b"};
	vector<string> ss(s, s+3);
	UndoHistory uh ;
	cout<<uh.minPresses(ss);
}