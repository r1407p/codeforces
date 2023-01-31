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
vi grade(1025,INT_MAX);
void _solve(){
    int n,k;
    cin >> n>>k;
    k = min(n*13,k);
    vi nums(n),points(n);
    for(int i =0;i<n;i++){
        cin >> nums[i];
        nums[i] = grade[nums[i]];
    }
    for(int i =0;i<n;i++){
        cin >> points[i];
    }
    vi dp(k+1,0);
    //print(nums);
    //print(points);
    for(int i =0;i<n;i++){
        //cout << "dsf\n";
        for(int j = k;j>=nums[i];j--){
            //    print(dp);
            dp[j] = max(dp[j],dp[j-nums[i]]+points[i]);
        }
    }
    cout << dp[k]<<endl;;
}
signed main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >>_;
    grade[1] = 0;
    for(int i = 1;i<1025;i++){
        for(int j = 1;j<=i;j++){
            int now = i +i/j;
            if(now<1025){
                grade[now] = min(grade[now],grade[i]+1);
            }
        }
    }
    while(_--){
        _solve();   
    }
    

}