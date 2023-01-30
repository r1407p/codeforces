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
    int nums[3];
    for(int i =0;i<3;i++){cin >>nums[i];}
    sort(nums,nums+3);
    int ans = 0 ;
    if(!nums[0]){
        cout << nums[1]/3+nums[2]/3;
    }else if (nums[0] ==1){
        int temp = nums[1]/3+nums[2]/3;
        int temp2 = 1+(nums[1]-1)/3+(nums[2]-1)/3;
        cout << max(temp,temp2)<<endl;
    }else{
        int temp1=nums[0]+(nums[1]-nums[0])/3+(nums[2]-nums[0])/3;
        int temp2=nums[0]-1+(nums[1]-nums[0]+1)/3+(nums[2]-nums[0]+1)/3;
        int temp3=nums[0]-2+(nums[1]-nums[0]+2)/3+(nums[2]-nums[0]+2)/3;
        ans=max(max(temp1,temp2),temp3);  
        cout <<ans;
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