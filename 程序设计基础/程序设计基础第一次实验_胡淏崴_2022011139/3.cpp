#include <iostream>
#include <random>

using namespace std;

// 使用 std::random_device 来获取真正的随机种子
random_device rd;

// 创建 Mersenne Twister 伪随机数生成器
mt19937 gen(rd());

// 创建3个随机分布，分别用于确定加减法数字，乘除法数字与选择计算模式
uniform_int_distribution<int> distribution100(1, 100);
uniform_int_distribution<int> distribution10(1, 10);
uniform_int_distribution<int> distribution3(1, 3);

int Plus()//加法执行函数
{
    while (1)
    {
        int a = distribution100(gen);
        int b = distribution100(gen);
        if (a + b <= 100)
        {
            cout << a << '+' << b << '=' << endl;
            return a + b;
        }
    }
}

int Minus()//加法执行函数
{
    while (1)
    {
        int a = distribution100(gen);
        int b = distribution100(gen);
        if (b > a)
        {
            int temp = b;
            b = a;
            a = temp;
        }
        if (a - b >= 0)
        {
            cout << a << '-' << b << '=' << endl;
            return a - b;
        }
    }
}

int Multi()//加法执行函数
{
    while (1)
    {
        int a = distribution10(gen);
        int b = distribution10(gen);
        if (a * b >= 0 && a * b <=100)
        {
            cout << a << '*' << b << '=' << endl;
            return a * b;
        }
    }
}

int main() {
    int times = 0, corrects = 0;//初始化数做题数和正确数

    while (1)
    {
        int ans, userin;//定义这一次的答案和用户输入值
        // 生成随机数,选择模式
        int mode_choose = distribution3(gen);
        if (mode_choose == 1)//加法模式
        {
            ans = Plus();
        }
        else if (mode_choose == 2)//减法模式
        {
            ans = Minus();
        }
        else if (mode_choose == 3)//乘法模式
        {
            ans = Multi();
        }
        cin >> userin;//输入用户答案

        if (userin == -1)//输入-1时退出
            break;
        else if (userin > 100)//大于100，报错
        {
            cout << "\x1B[37m\x1B[41m数字太大了，我不会，长大后再学习。\x1B[0m" << endl;
        }
        else if (userin < 0)//小于0，报错
        {
            cout << "\x1B[37m\x1B[41m数字太小了，我不会，长大后再学习。\x1B[0m" << endl;
        }
        else if (userin == ans)//输入正确答案，告诉用户输入正确
        {
            ++corrects;
            cout << "\x1B[42m\x1B[30m看来你的脑子里不只装了水。\x1B[0m" << endl;
        }
        else//错误答案，告诉用户输入错误
        {
            cout << "\x1B[37m\x1B[41m你是没有脑子吗？\x1B[0m" << endl;
        }
        ++times;
    }
    cout << "\x1B[34m您一共答了" << times << "道题。\n"
        << "共答对了" << corrects << "道题。\x1B[0m" << endl;


    return 0;
}
