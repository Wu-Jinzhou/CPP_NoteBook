#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec1;
vector<int> vec2;
vector<int> vec;
vector<int> vecc[100]; //定行不定列的二维数组

void Initialize() {

    vec1.push_back(7); //从尾部添加元素
    vec1.push_back(3);
    vec1.push_back(2);
    vec1.push_back(5);
    vec1.push_back(1); //7, 3, 2, 5, 1

    vec1.push_back(2);
    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(0);
    vec1.push_back(9); //2, 4, 5, 0, 9
}

void printVec1(vector<int> &vec) { //迭代器

    for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++) {

        cout << *itr << " ";
    }

    cout << endl;
}

void printVec2(vector<int> &vec) {

    for (int i = 0; i < vec.size(); i++) {

        cout << vec[i] << " ";
    }

    cout << endl;
}

void functionsOfVec() { //vector的自带函数

    vec1.insert(vec1.begin() + 2, 9); //7, 3, 9, 2, 5, 1
    vec1.erase(vec1.begin() + 2); //7, 3, 2, 5, 1
    vec1.pop_back(); //删除尾部元素

    //vec[i] = *vec.begin() + i

    sort(vec1.begin(), vec.end()); //从小到大排序
    reverse(vec1.begin(), vec1.end()); //反转

    vector<int> copyVec1(vec1); //定义copyVec1, 将vec拷贝为copyVec1

    cout << *(max_element(vec.begin(), vec.end())) << endl; //最大值
    cout << *(min_element(vec.begin(), vec.end())) << endl; //最小值
}

vector<int>& Intersection(vector<int> &vec1, vector<int> &vec2) {

    vector<int> resultVec;

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end()); //交集、并集前必先排序

    set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(resultVec)); //将交集拷贝至resultVec

    return resultVec;
}

vector<int>& Union(vector<int> &vec1, vector<int> &vec2) {

    vector<int> resultVec;

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(resultVec));

    return resultVec; //问题：并集中会把重复数据输出
}

//vector去重
vector<int>& vectorUnique(vector<int>& vec) {

    vector<int>::iterator itr;
    sort(vec.begin(), vec.end());
    itr = unique(vec.begin(), vec.end()); //将重复元素放到itr的位置

    if (itr != vec.end()) { //如果itr不是末尾
        vec.erase(itr, vec.end()); //删掉所有重复元素
    }

    return vec;
}

//某元素是否存在
bool find(vector<int> &vec, int target) {

    if (find(vec.begin(), vec.end(), target) != vec.end()) { //find()指向target的地址，不能找到时地址为end()
        return true;
    }
    else {
        return false;
    }
}

//Similarly:
void search(vector<int> &vec, int target) {

    vector<int>::iterator itr = find(vec.begin(), vec.end(), target);

    if (itr == vec.end()) {
        cout << "Not found" << endl;
    }
    else {
        cout << "Find " << *itr << " is the " << itr - vec.begin() + 1 << " th element." << endl;
    }
}

int main() {

    Initialize();

    vec1 = vectorUnique(vec1);


    return 0;
}