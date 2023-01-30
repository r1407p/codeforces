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
    for(int i =0;i<n;i++)cin >> nums[i];
    vi hu(n,1);
    int ans = 1;
    for(int i =1;i<n;i++){
        if(nums[i]>nums[i-1]){
            hu[i] = hu[i-1]+1;
            ans = max(ans,hu[i]);
        }
    }
    int now =0,cha = -1;
    for(int i = n-1;i>=0;i--){
        if(now){
            now--;
            hu[i] = cha;
        }else if(hu[i]!=1){
            cha = hu[i];
            now = hu[i]-1;
        }
    }
    nums.pb(-1);
    hu.pb(1);
    for(int i = 1 ;i<n-1;i++){
       if(nums[i]>=nums[i+1]){
            if(nums[i-1]<nums[i+1]){
                ans = max(hu[i-1]+hu[i+1]-1,ans);
            }else if(nums[i]<nums[i+2]){
                ans = max(hu[i]+hu[i+2]-1,ans);
            }
       }
    }
    //print(hu);
    cout << ans<<endl;
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