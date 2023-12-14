#include<bits/stdc++.h>
#define ll long long
#define forn(i,n) for(int i=0;i<n;i++)
#define endl  "\n"
using namespace std;
void solve()
{
    int n,ssmallest = INT_MAX;
    cin >> n;
     vector<int> v(n);
     forn(i,n) cin >> v[i];
     int smallest = v[0];
     forn(i,n) {
        if(v[i] < smallest){
            ssmallest = smallest;
            smallest = v[i];
        }
        else if(v[i] > smallest && v[i] < ssmallest) {
            ssmallest = v[i];
        }
        cout << ssmallest << endl;
     }
 return ;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){

        solve();
    }


    return 0;
}