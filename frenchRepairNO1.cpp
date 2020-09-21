#include <iostream>
#include <queue>
#include <vector>

class cmp
{
    public:
        bool operator()(const int a, const int b)const
        {
            return a>b;
        }
};

int main()
{
    int n;
    std::cin>>n;
    std::priority_queue<int, std::vector<int>, cmp> pq;

    for (int i=0; i<n; i++)
    {
        int x;
        std::cin>>x;
        pq.push(x);
    }

    int minFee = 0;

    while ( pq.size() > 1 )
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        pq.push(a+b);
        minFee += a+b;
    } 

    std::cout<<minFee<<std::endl;

    while( !pq.empty() )
    {
        pq.pop();
    }
    return 0;
}   
