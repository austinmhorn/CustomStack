#ifndef Stack_hpp
#define Stack_hpp

#define RED "\033[31m"
#define BOLD "\e[1m"
#define RESET "\e[0m\033[0m"

const int MAX_SIZE = 10;

#include <iostream>
using namespace std;

template <class T>
class MyStack {
public:
    MyStack();
    
    T getElement(int i) { return elements[i]; }
    
    void push(T x);
    void pop();
    T top();
    int size();
    bool isEmpty();
    
private:
    T input;
    T elements [MAX_SIZE];
    int topLoc;
};

template <class T>
MyStack<T>::MyStack() {
    topLoc = -1;
}

template <class T>
void MyStack<T>::push(T x) {
    try {
        if(this->topLoc == 9) {
            throw runtime_error("ERROR: Stack is full");
        }
        else {
            ++topLoc;
            elements[topLoc] = x;
        }
    } catch(const runtime_error &excpt) {
        cout << endl << excpt.what() << endl << endl;
    }
}

template <class T>
void MyStack<T>::pop() {
    cout << "\nElement being popped: " << elements[topLoc] << endl;
    --topLoc;
}

template <class T>
T MyStack<T>::top() {
    return elements[topLoc];
}

template <class T>
int MyStack<T>::size() {
    return(topLoc+1);
}

template <class T>
bool MyStack<T>::isEmpty() {
    return ( (topLoc==-1) ? true : false );
}

#endif /* Stack_hpp */
