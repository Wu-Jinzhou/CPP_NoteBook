#include <iostream>
#include <string>

using namespace std;

//函数调用运算符重载
class myPrint {

public:

    void operator()(string test) {
        cout << test << endl;
    }
};

class myAdd {

public:

    int operator()(int num1, int num2) {
        return num1 + num2;
    }
};

void test() {

    myPrint Print;

    Print("Hello, World"); //仿函数，非常灵活，无固定写法

    //匿名函数对象
    cout << myAdd()(1, 2) << endl; //class()创建一个匿名对象，执行完后立即被释放
}

int main () {

    test();

    system("pause");

    return 0;
}