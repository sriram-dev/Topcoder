#include<map>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<numeric>
#include<vector>
#include<queue>
#define pb push_back
#define DEBUG1(a) cout<<a<<endl
#define DEBUG2(a, b) cout<<a<<"\t"<<b<<endl
#define DEBUG3(a, b, c) cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define FOR(i,c) for(i=0;i<c;i++)
#define FOR1E(i,c) for(i=1;i<=c;i++)
#define DISPVEC(i,vec) for(i=0;i<vec.size();i++) \
						cout<<i<<"\t"<<vec[i]<<"\n";

using namespace std;
int INF = 10000000;
class ArcadeManao{
public:
    int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
		// maintain a queue to push elements in it which are not accessed yet.
		// for each element u face, add all possibilities to the queue
		queue< pair<int, int> > q;
		vector< pair<int,int> > seen;
		// startint pt is N-1, 0
		int tl, tr, ttop, tbot, n, m, k;
		coinRow -= 1;
		coinColumn -= 1;
		n = level.size();
		m = level[0].size();
		int l;
		for (l=0;l<=n ; l++) {
			std::queue< pair<int, int> > empty;
			std::swap( q, empty);
			q.push(make_pair(n-1,0));
			seen.clear();
			DEBUG2("l", l);
			while(!q.empty()) {
				int curx, cury;
				pair<int, int> curpair;
				curpair = q.front();
				q.pop();
				curx = curpair.first;
				cury = curpair.second;
				DEBUG3("x, y: " , curx, cury);
				if((curx == coinRow) && (cury == coinColumn))
					return l;
				// left 
				if(cury != 0) {
					tl = cury - 1;
				}
				else {
					tl = m-1;
				}
				if( level[curx][tl] != '.') {
					if(find(seen.begin(), seen.end(), make_pair(curx, tl)) == seen.end()) 
						q.push(make_pair(curx, tl));
				}
				DEBUG1("left process over");
				// right 
				if(cury != m-1)
					tr = cury + 1 ;
				else
					tr = 0 ;
				if(level[curx][tr] != '.') {
					if(find(seen.begin(), seen.end(), make_pair(curx, tr)) == seen.end()) 
						q.push(make_pair(curx, tr));
				}
				DEBUG1("right process over");
				
				if ( l != 0) {	
					// top 
					// chk if the ladder can be placed there 
					if( curx - l >= 0){
						k = 1;
						while( k <= l) {
							ttop = curx - k;
							if(ttop >= 0) {
								if (level[ttop][cury] != '.') {
									if(find(seen.begin(), seen.end(), make_pair(ttop, cury)) == seen.end())
										q.push(make_pair(ttop, cury));
								}								
							}
							k++;
						}
					}
					DEBUG1("top process over ");
					// bot 
					if(curx + l <n) {
						k = 1;
						while(k <= l) {
							tbot = curx + k;
							if(tbot < n) {
								if(level[tbot][cury] != '.'){
									if(find(seen.begin(), seen.end(), make_pair(tbot, cury)) == seen.end())
										q.push(make_pair(tbot, cury));
								}
							}
							k++;							
						}						
					}
					DEBUG1("bot process over ");
				}	
				seen.pb(make_pair(curx, cury));
			}
		}
		return -1;		
    }
};

int main () {
	ArcadeManao am;
	string arr[] = {".X.X.XX.XX.XX", "XX..XX.X.X...", "XX.X.XX...XXX", "..X.X...X.XX.", 
		"X....X..XXXX.", ".XX....X....X", "X.XX....X..XX", "XXX.XX.X.XX.X", "XX.X..X..X..X", 
		"X...XX.X.X...", "XX..XXXXXX..X", "XXXX.XX.X.X.X", "..XXXXXXXX..X", ".X.XXXX.XXXXX", "....XX.X..X.X", 
		"X...XX.XXX..X", ".X..XX.....X.", "XXX..XXX.X..X", "XXX.XX.XXX..X", "X..X.X....XXX", 
		"XX.X.X.XXXXXX", ".X..XXX.XXX..", "X.....XXX.XX.", "..X.XXXXXXXXX", "X..XX...X.XX.",
		 ".X..XX.XX....", "XXXXXXXXXXXXX"};
	DEBUG2("arr size is " , sizeof(arr)/sizeof(arr[0]));	 
	vector<string> level(arr, arr + sizeof(arr)/sizeof(arr[0]));
	int i;
	DISPVEC(i,level);	
	cout<<am.shortestLadder(level, 22, 2);
}
// 1 case failed in sys test 
