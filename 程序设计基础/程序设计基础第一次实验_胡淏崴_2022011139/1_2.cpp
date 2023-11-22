#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    srand(0);
    for(int i=0;i<100;++i)//每次运行会输出相同的数列
    {
        cout<<rand()<<endl;
    }
}