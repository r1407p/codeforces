#include<bits/stdc++.h>
 
 
using namespace std;


#define int long long 
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define ALL(X) X.begin() , X.end()
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
int n;
int bin(vpii nums,int tar,int r){
    int l = 1;
    while(l<r){
        int mid = (l+r)/2;
        if(nums[mid].first<tar) l = mid+1;
        else r = mid;
    }
    return l-1;
}
void _solve(){
    cin>> n;vpii nums(n);
    for(int i =0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    sort(ALL(nums));
    vi ser(n,0);
    for(int i = 0;i<n;i++)ser[i] = nums[i].first;
    vi mx(n,0);
    mx[0] = 1;
    int light  = 1;
    for(int i = 1;i<n;i++){
        int temp = lower_bound(ser.begin(),ser.begin()+i+1,nums[i].first-nums[i].second)-ser.begin();
        if(!temp) mx[i] = 1;
        else mx[i] = mx[temp-1]+1;
        light = max(light,mx[i]);
    }
    //print(mx);
    cout <<n-light;

}
signed main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >>_;
    while(_--){
        _solve();   
    }

}