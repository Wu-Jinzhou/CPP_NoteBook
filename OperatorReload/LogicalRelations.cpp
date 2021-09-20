#include <iostream>
#include <string>

using namespace std;

//关系运算符重载
class Person {

public:
    Person(string name, int age) {

        m_name = name;
        m_age = age;
    }

    bool operator==(Person &p) { //operator!= / operator><

        if (this->m_name == p.m_name && this->m_age == p.m_age) {
            return true;
        }
        else {
            return false;
        }
    }

    string m_name;
    int m_age;
};

void test() {

    class Person p1("Regina", 15);
    class Person p2("Flash", 15);

    if (p1 == p2) {
        cout << p1.m_name << " is the same age as " << p2.m_name << " ." << endl;
    }
    else {
        cout << "false" << endl;
    }
}

int main() {

    test();

    system("pause");

    return 0;
}