#include <iostream>
#include <algorithm>
// using namespace std;

int N, R;

int main()
{
    std::cin>>N>>R;
    int X[N];

    for (int i=0; i<N; i++)  std::cin>>X[i];

    std::sort(X, X + N);

    int i = 0, ans = 0;
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
