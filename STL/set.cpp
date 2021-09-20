#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

/*set:集合
1.元素自动唯一
2.元素是默认从小到大排序 ->无索引值[]*/

set<int> st;

void Insert() {

    st.insert(1);
    st.insert(2);
    st.insert(5);
    st.insert(2);
    st.insert(7);
    st.insert(4);
    st.insert(6);
    st.insert(1);
}

void printSet(set<int> &st) {

    for (set<int>::iterator itr = st.begin(); itr != st.end(); itr++)
        cout << *itr;

    cout << endl;
}

void Erase() {

    //st.erase(st.begin() + 2); X 只有vector和string可以对迭代器加减
    st.erase(5); //删掉元素5
    st.erase(++st.begin()); //可以用前置后置运算符
    //或可以先find再删

    set<int>::iterator itr = st.find(6);
    st.erase(itr); //erase(值或地址)
}

int main () {

    Insert();
    printSet(st);

    Erase();
    printSet(st);

    system("pause");

    return 0;
}