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
        cout <<char('a'+i) ;
    }cout << endl;
}
void print(vvi nums){
    for(auto &i:nums){
        print(i);
    }
}
bool flag = true;
vvi nxt(26);
vi ans;
vb used(26,false);
void con(str s1,str s2){
   int sz1 = s1.size();
    int sz2 = s2.size();
    
    for(int i = 0 ; i<min(sz1,sz2) ; i++){
        if(s1[i]==s2[i])continue;
        nxt[s2[i]-'a'].pb(s1[i]-'a');
        return;
    }
    if(sz1>sz2)flag = false;
}
void eli(int i){
    if(nxt[i].size()==0)return;
    sort(ALL(nxt[i]));
    vi temp;
    temp.pb(nxt[i][0]);
    for(int j =1;j<nxt[i].size();j++){
        if(nxt[i][j]!=nxt[i][j-1])temp.pb(nxt[i][j]);
    }
    nxt[i] = temp;
}
void dfs(int i){
    used[i] = true;
    for(int j = 0 ;j<nxt[i].size();j++){
        if(!used[nxt[i][j]])dfs(nxt[i][j]);
    }
    ans.pb(i);
}
void _solve(){
    int n;cin >> n;
    vs strs(n);
    for(int i =0;i<n;i++){
        cin >> strs[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            con(strs[i],strs[j]);
        }
    }
    for(int i = 0;i<26;i++){
        eli(i);
    }    
    for(int i = 0;i<26;i++){
        if(!used[i])dfs(i);
    }
    
    vi order(26);
    for(int i = 0;i<26;i++){
        order[ans[i]]=i;
    }
    // for(int i=0;i<26;i++){
    //     cout << char(i+'a')<<':';
    //     cout << order[i]<<endl;
    // }
    for(int i =0 ;i<26;i++){
        for(int j =0 ;j<nxt[i].size();j++){
            if(order[nxt[i][j]]>order[i])flag = false;
        }
    }
    if(!flag)cout <<"Impossible"<<endl;
    else{
        print(ans);
    }
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