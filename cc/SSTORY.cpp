/* KEEP THE GOOD WORK TODAY AND ONE DAY YOU WILL SHINE THE WORLD */

#include<bits/stdc++.h>

#define umap                                            unordered_map
#define uset                                            unordered_set
#define fastio                                          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp                                              make_pair
#define pb                                              push_back
#define T                                               ull t; cin>>t; while(t--)
#define MIN_DIFF                                        1e-9

#define EXISTS(m, a)                                    (m.find(a) != m.end())
#define SET_SAFE(m, condition, key, value, default)     m[key] = ((condition) ? (value) : (default))
#define SET_IF_NOT_EXISTS(m, key, value, default)       m[key] = SET_SAFE(m, EXISTS(m, key),  key, value, default)
#define GET_IF_EXISTS(m, a)                             (EXISTS(m, a) ? m[(a)] : -1)

#define PRINT_ARR(A, i, m, n)                           for(ull i=(m); i<=(n); i++){ cout<<A[i]<<" "; } cout<<endl
#define SET_ARR(A, i, m, n)                             for(ull i=(m); i<=(n); i++){ cin>>A[i]; }
#define PRINT_MAP(m, i)                                 for(auto i: m){cout<<i.first<<": "<<i.second<<" ";} cout<<endl
#define PRINT_SET(m, i)                                 for(auto i: m){cout<<i<<" ";} cout<<endl
#define EQ(a, b)                                        abs((a)-(b))<MIN_DIFF

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
string alpha = "abcdefghijklmnopqrstuvwxyz";

void solve();

int main() {
	fastio;
	solve();
}

int d = 256;
int q = 97;
void solve(){
    string A, B;
    cin>>A>>B;
    string &small = A.size()<B.size()?A:B;
    string &large = A.size()<B.size()?B:A;

    int p = 0;
    int t_org = 0;
    for(int i=0; i<small.size(); i++){
        p = d*(p + small[i]) % q;
        t = d*(t + large[i]) % q;
    }


    for(int i=small.size(); i>0; i++){


    }

}
