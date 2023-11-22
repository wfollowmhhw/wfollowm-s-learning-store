#include <iostream>
#include <random>

using namespace std;

// ʹ�� std::random_device ����ȡ�������������
random_device rd;

// ���� Mersenne Twister α�����������
mt19937 gen(rd());

// ����3������ֲ����ֱ�����ȷ���Ӽ������֣��˳���������ѡ�����ģʽ
uniform_int_distribution<int> distribution100(1, 100);
uniform_int_distribution<int> distribution10(1, 10);
uniform_int_distribution<int> distribution3(1, 3);

int Plus()//�ӷ�ִ�к���
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

int Minus()//�ӷ�ִ�к���
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

int Multi()//�ӷ�ִ�к���
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
    int times = 0, corrects = 0;//��ʼ��������������ȷ��

    while (1)
    {
        int ans, userin;//������һ�εĴ𰸺��û�����ֵ
        // ���������,ѡ��ģʽ
        int mode_choose = distribution3(gen);
        if (mode_choose == 1)//�ӷ�ģʽ
        {
            ans = Plus();
        }
        else if (mode_choose == 2)//����ģʽ
        {
            ans = Minus();
        }
        else if (mode_choose == 3)//�˷�ģʽ
        {
            ans = Multi();
        }
        cin >> userin;//�����û���

        if (userin == -1)//����-1ʱ�˳�
            break;
        else if (userin > 100)//����100������
        {
            cout << "\x1B[37m\x1B[41m����̫���ˣ��Ҳ��ᣬ�������ѧϰ��\x1B[0m" << endl;
        }
        else if (userin < 0)//С��0������
        {
            cout << "\x1B[37m\x1B[41m����̫С�ˣ��Ҳ��ᣬ�������ѧϰ��\x1B[0m" << endl;
        }
        else if (userin == ans)//������ȷ�𰸣������û�������ȷ
        {
            ++corrects;
            cout << "\x1B[42m\x1B[30m������������ﲻֻװ��ˮ��\x1B[0m" << endl;
        }
        else//����𰸣������û��������
        {
            cout << "\x1B[37m\x1B[41m����û��������\x1B[0m" << endl;
        }
        ++times;
    }
    cout << "\x1B[34m��һ������" << times << "���⡣\n"
        << "�������" << corrects << "���⡣\x1B[0m" << endl;


    return 0;
}
