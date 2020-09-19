/*
Calculate what and how many kinds of coins you need to build an integer.
*/
#include <iostream>
using namespace std;

const int coins[6] = {1, 5, 10, 50, 100, 500};
int c[6] = {1, 2, 5, 3, 6, 4};// Number of coins of each type

int main()
{
    int ans = 0; //Ultimate number of coins
    int k; //Destination integer
    cin>>k;
    for(int i=5; i>=0;i--){
        //this step is really wonderful, taste it:
        int t = min( k/coins[i], c[i]);
        k -= t * coins[i];
        c[i] -= t;
        ans += t;
    }

    cout<<ans<<endl;
    
    return 0;
}
