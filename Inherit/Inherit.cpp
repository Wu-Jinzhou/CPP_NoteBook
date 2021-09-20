#include <iostream>

using namespace std;

class BasePerson {
    
    public:
    
    string name;
    int age;
    string gender; //同名元素
    static int pub; //同名静态元素

    void setLover(bool inLove, string lover) { 

        this->inLove = inLove;
        this->loverName = lover;
    }

    protected:

    string PC;
    string company;

    private:

    bool inLove;
    string loverName;
};

int BasePerson::pub = 0;

/*class 子类/派生类: 继承方式 父类/基类
继承方式：公共继承/保护继承/私有继承
公共继承：private无法访问，public在public中继承，protected在protected中继承
保护继承：private无法访问，public和protected在protected中继承
私有继承：private无法访问，public和protected在privated中继承*/
class Male: public BasePerson {

    public:

    int height;
    int length;
    string gender; //同名元素
    static int pub; //同名静态元素

    Male(string name, int age, int height, int length) {

        this->name = name;
        this->age = age;
        this->height = height;
        this->length = length;
    }

    // void visitPrivateTest(bool inLove, string lover) {

    //     this->inLove = inLove;
    //     this->loverName = lover;
    // } X 私有成员不可访问

    void visitPrivate(bool inLove, string lover) {

        this->setLover(inLove, lover); //但可以通过这种方式访问
    }
};

int Male::pub = 1;

class Base {};
class Son: public BasePerson, public Base2 {}; //多继承，不建议使用

void test() {

    Male Flash("Flash", 15, 175, 15); //先调用父类的构造函数，再构造子类的构造函数
    //释放时先调用子类的析构函数，再调用父类的析构函数

    //Flash.PC = "None"; 保护在类外不可访问

    Flash.visitPrivate(1, "Regina");

    cout << Flash.name << "\t" << Flash.age << "\t" << Flash.height << "\t" << Flash.length << endl;

    cout << sizeof(BasePerson) << endl; //144
    cout << sizeof(Male) << endl; //152 父类所有非静态成员全部继承，私有成员虽继承但访问不到

    Flash.gender = "male"; //访问子类同名元素
    Flash.BasePerson::gender = "male"; //访问父类同名元素：加作用域
    //同名成员函数调用方法类似，
    //但若子类中出现和父类同名的成员函数，子类的同名函数会隐藏掉父类中所有同名成员函数
    //即便父类中两个同名函数发生重载，也需要再加作用域
    //静态成员访问方法类似
    cout << Flash.pub << " " << Flash.BasePerson::pub << endl; //通过对象访问
    cout << Male::pub << " " << BasePerson::pub << endl; //通过类名访问, 直接通过父类
    cout << Male::BasePerson::pub << endl; //Male::代表通过类名访问，BasePerson::访问父类作用于下
    //同名静态成员函数调用类似

    cout << sizeof(Boy) << endl; //访问数据加作用域，容易出现同名数据
    //若有同父类，元素继承两份，需加作用域->资源浪费
}

int main() {

    test();

    system("pause");

    return 0;
}