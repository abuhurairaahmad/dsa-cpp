#include <iostream>
using namespace std;

class MyClass {
private:
    int value;
public:
    MyClass(int value): value(value) {
        cout << "Constructor called for the value" << endl;
    }

    ~MyClass() {
        cout << "Destructor called for the value" << endl;
    }

    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            value = other.value;
            cout << "Assignment operator called for the value" << endl;
        }
        return *this;
    }

    MyClass(const MyClass& other): value(other.value) {
        cout << "Copy constructor called for the value" << endl;
    }

    
};

int main(){
    MyClass obj1(10);
    MyClass obj2(obj1); // Copy constructor is called
    obj2 = obj1; // Assignment operator is called
    
    return 0;
}
