#include <iostream>
// using namespace std;

int N, R;

int main()
{
    std::cin>>N>>R;
    int X[N], ans = 0;

    for (int i=0; i<N; i++)  std::cin>>X[i];


    int i = 0;
    while ( i < N )
    {
        int s = X[i];

        while ( i < N && X[i] <= s + R ) i++;
        
        int c = X[i];

        while ( i < N && X[i] <= c + R ) i++;

        ans ++;
    }

    std::cout<<ans<<std::endl;

    return 0;
}
