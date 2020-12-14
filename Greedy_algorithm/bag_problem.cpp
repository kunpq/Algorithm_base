#include <iostream>
#include <vector>
using namespace std;

typedef struct tagObject
{
    int weight;
    int price;
    int status; //'0'为未选，‘1’为已选，‘2’为已不可选
} Object;

typedef struct bagProblem{
    vector<Object> objs;
    int totalCount;
} bagProblem;




int main(void)
{
    vector<int> a;
    a.push_back(389);
    a.push_back(23);
    cout << a.back() << endl;
    return 0;
}