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
int ans = 0;
int n ,m;
vi nums;
vb visited;
vvi nxt;
void dfs(int at,int now){
    //cout <<at <<" "<<now<<endl;
    if(now>m)return;
    int sz = nxt[at].size();
    bool flag = true;
    for(int i =0 ;i<sz ;i++){
        if(visited[nxt[at][i]])continue;
        visited[nxt[at][i]] = true;
        flag = false;
        if(nums[nxt[at][i]]){
            dfs(nxt[at][i],now+1);
        }else{
            dfs(nxt[at][i],0);
        }
    }
    if(flag)ans++;
}
void _solve(){
    cin>> n;
    cin>> m;
    nums.resize(n+1);
    nxt.resize(n+1);
    visited.resize(n+1,false);
    for(int i =1;i<=n;i++)cin >> nums[i];
    for(int i =1;i<n;i++){
        int a,b;cin>>a>>b;
        nxt[a].pb(b);
        nxt[b].pb(a);
    }
    visited[1] = true;
    dfs(1,nums[1]);
    cout << ans;
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