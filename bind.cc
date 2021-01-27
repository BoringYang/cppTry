#include <functional>
#include <iostream>

using namespace std;

int f(int a, int b) { return a + b; }            //二元函数
int g(int a, int b, int c) { return a + b + c; } //三元函数
typedef int (*f_type)(int, int);                 //函数指针定义
typedef int (*g_type)(int, int, int);            //函数指针定义

int main()
{

    int x = 1;
    int y = 100;
    int z = 1000;
    cout << "bind(f, 1, 2)()=" << bind(f, 1, 2)() << endl;       //相当于cout<<f(1,2)<<endl;
    cout << "bind(g, 1, 2, 3)()=" << bind(g, 1, 2, 3)() << endl; //相当于cout<<g(1,2,3)<<endl;

    auto bindFirst=bind(f,placeholders::_1,9);
    cout<<"result of call bindFirst(1) is "<<bindFirst(1)<<endl;
    cout << bind(f, placeholders::_1, 9)(x) << endl;                                        //f(x,9)
    cout << bind(f, placeholders::_1, placeholders::_2)(x, y) << endl;                      //f(x,y)
    cout << bind(f, placeholders::_2, placeholders::_1)(x, y) << endl;                      //f(y,x)
    cout << bind(f, placeholders::_1, placeholders::_1)(x, y) << endl;                      //f(x,x),y参数被忽略
    cout << bind(g, placeholders::_1, 8, placeholders::_2)(x, y) << endl;                   //g(x,8,y)
    cout << bind(g, placeholders::_3, placeholders::_2, placeholders::_2)(x, y, z) << endl; //g(z,y,y),x参数被忽略

    return 0;
}
