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

vector<int> rabin_karp(string txt, string pat, int q){
    int n = txt.size();
    int m = pat.size();
    int d = 256;
    int h = 1;
    int t = 0;
    int p = 0;
    vector<int> ans;

    for(int i=0; i<m-1; i++){
        h = (d * h) % q;
    }

    for(int i=0; i<m; i++){
        t = (t*d + txt[i]) % q;
        p = (p*d + pat[i]) % q;
    }



    for(int i=0; i<=n-m; i++){

        if(p==t){
            int j;
            for(j=0; j<m; j++){
                if(txt[i+j] != pat[j]){
                    break;
                }
            }

            if(j==m){

                ans.pb(i);
            }
        }

        t = ((t - txt[i]*d)*h + txt[i+m])%q;

        if(t < 0) t += q;
    }

    return ans;

}

// rabin karp
void solve(){
    string txt, pat;
    int q = 13;
    cin>>txt>>pat;

    vector<int> pos = rabin_karp(txt, pat, q);

    for(int i=0; i<pos.size(); i++){
        cout<<"Found at: "<<pos[i]<<endl;
    }
}

/* ejegkjgfkjwgkrjewgkrwgewryeirywiuerilu4wrg iu */
