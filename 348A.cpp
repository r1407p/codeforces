#include<bits/stdc++.h>
 
 
using namespace std;


#define int long long 
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define ALL(X) X.begin(), X.end()
#define rALL(X) X.rbegin(), X.rend()
typedef long long loli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;
typedef pair<pll,pll> pllll;
typedef string str;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<loli> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<str> vs;
#define maxn 200005
//int a[maxn];
//ifstream fin("test.in");
//ofstream fout("test.out");
void print(vi nums){
    for(auto &i :nums){
        cout <<i <<" ";
    }cout << endl;
}
void print(vvi nums){
    for(auto &i:nums){
        print(i);
    }
}
void _solve(){
    
    int n;cin>> n;vi nums(n);
    loli sum =0;
    int mx = 0;
    for(int i  = 0;i<n;i++){
        cin >>nums[i];
        sum+=nums[i];
        mx = max(nums[i],mx);
    }
    loli ans =0;
    if(sum%(n-1)==0)ans = sum/(n-1);
    else ans = sum/(n-1)+1;
    ans = max(ans,mx);
    cout <<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >>_;
    while(_--){
        _solve();   
    }

}