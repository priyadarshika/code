#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int n, num;
    
    cout << "How many numbers to push into stack? ";
    cin >> n;

    cout << "Enter " << n << " numbers:\n";
    for(int i = 0; i < n; i++) {
        cin >> num;
        s.push(num);  // Push into stack
    }

    // Printing stack (top to bottom)
    cout << "\nStack elements (from top to bottom):\n";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
