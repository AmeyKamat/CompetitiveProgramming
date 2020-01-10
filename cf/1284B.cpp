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

int search(ll A[], int n, ll low, ll high, ll val){

    ll mid = (low + high)/2;

    if(mid == 0 && A[mid] > val) return 0;
    else if(A[mid] > val && A[mid-1] <= val) return mid;
    else if(mid == n-1 && A[mid] <= val) return n;
    else if(A[mid] > val) return search(A, n, low, mid-1, val);
    else return search(A, n, mid+1, high, val);
}

void solve();

int main() {
	fastio;
	solve();
}

void solve(){
    ll n, m;

    cin>>n;
    ll first[n], last[n], curr, prev, f, l, count=0;
    bool ascent = false;
    for(int i=0; i<n; i++){
        cin>>m;
        ascent = false;
        for(int j=0; j<m; j++){
            cin>>curr;
            if(j==0) f = curr;
            if(j==m-1) l = curr;

            if(j !=0 && !ascent && prev<curr){
                ascent = true;
            }
            prev = curr;
        }

        if(!ascent){
            first[count] = f;
            last[count] = l;
            count++;
        }
    }

    sort(first, first+count);
    ll c=0;
    for(int i=0; i<count; i++){
        c+=search(first, count, 0, count-1, last[i]);
    }

    cout<<n*n-c<<endl;
}
