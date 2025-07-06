#include <iostream>
#include <stack>  // In-built stack library
using namespace std;

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;  // 30

    s.pop();  // removes 30
    cout << "Top after pop: " << s.top() << endl;  // 20

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}