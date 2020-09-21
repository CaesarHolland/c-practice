/*
Question:
    Cutting the wood under the lowest cost
*/
#include <iostream>
#include <queue>
#include <vector>

/*
Idea:
    This is a problem that involved with many kinds of possibility, So we comes
    up with "Tree". Binary tree is that one which can store many branches , the
    most suitable Data-Structure. 

    Every subnode is the result that parent-node(uncutted wood) cutted.

Important conclusion:
    Lower cost = Sum of every leaves-node.

Data Structure:
    - priority_queue -
    We store "Every piece of wood needed" in an increasing order.
    So what we need to do is take out two numbers out of the queue at a time.
    Then make a tree whose head-node is the sub-node's sum out of them.
    Then new subtree is queued again. 
    Then repeat.   
*/

int main()
{
    int n;
    std::cin>>n;
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

    for (int i=0; i<n; i++)
    {
        int x;
        std::cin >> x;
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

    std::cout << minFee << std::endl;

    while( !pq.empty() )    pq.pop();

    return 0;
}   
