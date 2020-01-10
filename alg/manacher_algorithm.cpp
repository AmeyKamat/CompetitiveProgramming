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

void solve(){
    string A;
    cin>>A;
    int n = 2*A.size()+1;
    int palLen[n];
    palLen[0] = 0;
    palLen[1] = 1;
    int C = 1;
    int R = C + palLen[C];
    int L = C - palLen[C];
    bool expand = false;

    for(int pRight=2; pRight<n; pRight++){
        int pLeft = 2*C - pRight;
        int distToEdge = R - pRight;

        expand = false;

        if(distToEdge > 0){
            // case 1
            if(palLen[pLeft] < distToEdge){
                palLen[pRight] = palLen[pLeft];
            }
            // case 3
            else if(palLen[pLeft] == distToEdge && pRight == n-1){
                palLen[pRight] = palLen[pLeft];
            }
            // case 3
            else if(palLen[pLeft] == distToEdge){
                palLen[pRight] = palLen[pLeft];
                expand = true;
            }
            // case 2
            else {
                palLen[pRight] = distToEdge;
                expand = true;
            }
        }
        else{
            palLen[pRight] = 0;
            expand = true;
        }

        if(expand){
            // if even position, simply increment. It is not character
            // else check


            while ((pRight+palLen[pRight]<n && pRight-palLen[pRight]>0) &&
                ((pRight+palLen[pRight]+1) % 2 == 0) ||
                (A[(pRight+palLen[pRight]+1)/2] == A[(pRight-palLen[pRight]-1)/2]))
            {
                palLen[pRight]++;
            }
        }

        if(pRight + palLen[pRight] > R){
            C = pRight;
            R = pRight + palLen[pRight];
            L = pRight - palLen[pRight];

        }

    }

    int maxPos=0;
    int maxLen = palLen[0];

    for(int i=0; i<n; i++){
        if(maxLen<palLen[i]){
            maxLen = palLen[i];
            maxPos = i;
        }
    }

    int start=0, end=0;
    if(maxPos%2 == 0){
        start = maxPos/2 - maxLen/2;

    }
    else{
        start = (maxPos-1)/2 - (maxLen-1)/2;

    }

    cout<<A.substr(start, maxLen)<<endl;
}

/* babcbabcbaccba */
