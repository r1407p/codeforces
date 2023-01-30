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
void print(vector<char> nums){
    for(auto &i :nums){
        cout <<i;
    }cout << endl;
}
void print(vector<vector<char>> nums){
    for(auto &i:nums){
        print(i);
    }
}
int k;
vvb visited(1000,vb(1000,false));
void dfs(vector<vector<char>> &maze,int i,int j){
    if(!k)return;
    if(visited[i][j])return;
    if(maze[i][j]=='#'||maze[i][j]=='X')return;
    visited[i][j] = true;
    dfs(maze,i-1,j);
    dfs(maze,i,j-1);
    dfs(maze,i+1,j);
    dfs(maze,i,j+1);
    if(k){
        maze[i][j] = 'X';
        k--;
    }
}
void _solve(){
    int n,m;
    cin >> n >> m >> k;
    vector<vector<char>> maze(n+2,vector<char>(m+2,'#'));
    for(int i = 1; i <=n; i++){
        for(int j = 1;j<=m;j++){
            cin >> maze[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(maze[i][j]=='.'){
                dfs(maze,i,j);
                break;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout <<maze[i][j];
        }cout <<endl;
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