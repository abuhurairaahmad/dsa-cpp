#include <iostream>
using namespace std;

class MyClass {
private:
    int value;
public:
    MyClass() : value(0) {
        cout << "Default constructor called for the value " << value << endl;
    }
    MyClass(int value): value(value) {
        cout << "Constructor called for the value " << value << endl;
    }
    ~MyClass() {
        cout << "Destructor called for the value " << value << endl;
    }
    MyClass(const MyClass& other): value(other.value) {
        cout << "Copy constructor called for the value " << value << endl;
    }
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            value = other.value;
            cout << "Assignment operator called for the value " << value << endl;
        }
        return *this;
    }

    // Move constructor effeciently transfers ownership (no copying)
    MyClass(MyClass&& other) noexcept : value(move(other.value)) {
        other.value = -1;
        cout << "Move constructor called for the value " << value << endl;
    }

    // Move assignment operator efficiently transfers ownership (no copying)
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            value = move(other.value);
            other.value = -1;
            cout << "Move assignment operator called for the value " << value << endl;
        }
        return *this;
    }
    int getValue() const {
        return value;
    }
};


int main(){
    MyClass obj1(41);
    MyClass obj2(obj1); // Copy constructor is called
    MyClass obj3(move(obj1)); // Move constructor is called
    MyClass obj4(32);
    MyClass obj5;
    obj5 = move(obj4); // Move assignment operator is called

    cout << "Value of obj1: " << obj1.getValue() << endl; // obj1 is in a valid but unspecified state
    cout << "Value of obj2: " << obj2.getValue() << endl; // obj2 has the same value as obj1 had before the move
    cout << "Value of obj3: " << obj3.getValue() << endl; // obj3 has the value that obj1 had before the move
    cout << "Value of obj4: " << obj4.getValue() << endl; // obj4 is in a valid but unspecified state
    cout << "Value of obj5: " << obj5.getValue() << endl; // obj5 has the value that obj4 had before the move

    return 0;
}