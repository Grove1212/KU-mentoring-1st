#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int numOfLine = 0;
    int sum = 0;
    int enter = 0;
    stack<int>s;
    cin >> numOfLine;

    for (int i = 0; i < numOfLine; i++)
    {
        cin >> enter;
        if (enter == 0)
            s.pop();
        else
            s.push(enter);

    }
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }

    cout << sum;
}