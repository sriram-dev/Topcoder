#include<map>
#include<algorithm>
#include<iostream>
#include<cstring>
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
class TheExperimentDiv2{
public:
    vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd) {
        vector<int> humidity(leftEnd.size(),0);
        int i, l, r, j;
        int whose[intensity.size()+1];
        for(i=leftEnd.size()-1;i>=0;i++) {
            for(j=leftEnd[i];j<leftEnd[i]+L;j++){
                whose[j] = i;
            }
        }

        for(i=0;i<(intensity.size()+ 1);i++) {
            humidity[whose[i]] += intensity[i];
        }
        DISPVEC(i,humidity);
    }

};

int main() {

}
