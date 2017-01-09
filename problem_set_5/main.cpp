#include <iostream>
#include "Stack"
#include "Graph.h"
using namespace std;



int main()
{
    cout << "Hello world!" << endl;
    Stack<int> stk_1, stk_2;
    stk_1.push(32);
    stk_2.push(64);
    Stack<int> stk_3 = stk_1 + stk_2;
    cout << stk_3.top() << endl;
    stk_3.pop();
    cout << stk_3.empty() << endl;
    cout << stk_3.top() << endl;

    vector<int> vt_1{1,1,1,5,5,4}, vt_2{2,3,4,4,2,2};
    Graph grp(vt_1, vt_2);
    cout << grp.nodes.size() << endl;
    return 0;
}
