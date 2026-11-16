#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class Stack {
    vector<T> items;

public:
    void push(const T& value) {
        items.push_back(value);
    }

    bool empty() const {
        return items.empty();
    }

    bool pop(T& value) {
        if (empty()) return false;
        value = items.back();
        items.pop_back();
        return true;
    }

    bool peek(T& value) const {
        if (empty()) return false;
        value = items.back();
        return true;
    }
};

template <class T>
void testStack(const string& type, T first, T second) {
    Stack<T> stack;
    T value{};
    cout << "\n" << type << " stack\n";
    cout << "Initially empty: " << stack.empty() << '\n';

    stack.push(first);
    stack.push(second);
    cout << "Pushed: " << first << ", " << second << '\n';
    if (stack.peek(value)) cout << "Top: " << value << '\n';
    while (stack.pop(value)) cout << "Popped: " << value << '\n';

    cout << "Empty after popping: " << stack.empty() << '\n';
    if (!stack.peek(value)) cout << "Peek failed: stack is empty.\n";
    if (!stack.pop(value)) cout << "Pop failed: stack is empty.\n";
}

int main() {
    cout << "Name: Yash Sharma\n";
    cout << "Roll Number: E25B000411\n";
    cout << boolalpha;
    testStack<int>("Integer", 10, 20);
    testStack<float>("Float", 1.5f, 2.5f);
    testStack<string>("String", "Hello", "World");
    return 0;
}
