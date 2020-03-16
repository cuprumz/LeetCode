#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        cout << "constructor" << endl;
    }

    Person(const Person &person) {
        cout << "copy constructor" << endl;
    }

    Person &operator=(const Person &person) {
        cout << "assign" << endl;
    }

    ~Person() {
        cout << "~Person()" << endl;
    }

private:
    int age;
    string name;
};

void f(Person p) {
}

Person f1() {
    Person p;
    return p;
}

int main(int argc, char **argv) {

    Person p; // constructor
    Person p1 = p; // copy constructor
    Person p2; // constructor
    p2 = p1; // assign
    f(p2); // copy constructor

    // ~Person()

    p2 = f1(); // constructor assign
    // ~Person()
    Person p3 = f1(); // constructor
    // ~Person()
    // ~Person()
    // ~Person()
    // ~Person()


    return 0;
}

/**
 * Person p;构造函数
 * Person p = exist;拷贝构造函数
 * exist1 = exist0;赋值构造函数
 * 参数传递（值） 调用拷贝构造函数
 * exist = f1(); 先构造函数后调用赋值构造函数
 * Person p = f1(); 构造函数，只有一个对象
 */
