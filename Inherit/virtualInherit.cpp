#include <iostream>

using namespace std;

class GrandFather {

    public:

    int pub;
};

class Father: virtual public GrandFather {};
class Mother: virtual public GrandFather {};
class Son: public Father, public Mother {};
//继承Father和Mother的vbptr(Virtual Base Pointer虚基类指针)，指向vbtable虚基类表，记录偏移量
//记录指针，通过偏移量找到pub的地址，pub只有一份

void test() {

    Son son;
    son.pub = 10;

    cout << son.pub << endl;
}

int main() {

    test();

    system("pause");

    return 0;
}