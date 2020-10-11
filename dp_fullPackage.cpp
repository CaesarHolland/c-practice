#include <bits/stdc++.h>
using namespace std;
int n, W;
int dp[110], w[110], v[110];

int main()
{
    memset(dp, 0, sizeof dp);
    cin >> n >> W;

    for (int i=0; i<n; i++)
        cin >> w[i] >>v[i];


/*
    Now we made some optimize -- solve the problem by just one array.
    The consideration of the array now is focused on every single item.
    Find the highest proportion of v/m for every single item.
    So we need to do the comparison in a domain that from w[i] up to W to test
    what is the minimum volume every item need. 
*/ 
    for (int i=0; i<n; i++) {
        
        for (int j=w[i]; j<=W; j++) {

            dp[j] = max (dp[j], dp[j-w[i]] + v[i]);
        }
    }

    cout<< dp[W] << endl;

    return 0;
}
