#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct node
{
    char data;//һ���ֽڵ�����
    int next;//��һ�����ݵ��±�
};
struct RAM
{
    node Memory[600];//600���ֽڵ����ڴ�ռ�
    int head;//���ÿռ���׵�ַ
    int tail;//���ÿռ��β��ַ
    int first;//����ռ���׵�ַ
    int last;//����ռ��β��ַ
    int Nuse;//δ�ÿռ��С
};
void Initialization(RAM &r);//��ʼ��������ڴ�
int Malloc(RAM &r,int size);//����һ����СΪsize���ڴ�ռ䣬�����ڴ��׵�ַ
void Del(RAM &r,int h,int size);//�ͷ��׵�ַΪh�Ĵ�СΪsize���ڴ�ռ�
int SizeOf(RAM r,int h);//���ش�h��ַ��ʼ����β���ܿռ��С
int main()
{
    RAM Ram;
    Initialization(Ram);
    do
    {
        system("cls");
        cout<<"1.�����ڴ�ռ䡣"<<endl;
        cout<<"2.�ͷ��ڴ�ռ䡣"<<endl;
        cout<<"3.�˳���"<<endl;
        cout<<"������ѡ��"<<endl;
        int i;
        int n,t;//�ڴ��С���ڴ��׵�ַ
        while(1)//����ֻ��Ӧ1-3�����ְ�������
        {
            if(kbhit())//kbhit����1�Ǳ�ʾ�м��̰�ť����
            {
                char ch;
                ch=getch();
                if(ch>48&&ch<52)//�жϰ��µ��ǲ���1-3�����ּ�
                {
                    i=ch-48;
                    break;
                }
                fflush(stdin);//��ռ��̻�����
            }
        }
        switch(i)
        {
            case 1:
            cout<<"������Ҫ������ڴ��С��";
            cin>>n;
            t=Malloc(Ram,n);
            if(t!=-1)
            cout<<"������Ŀռ��׵�ַΪ"<<t<<endl;
            cout<<"����������أ�";
            getch();
            break;
            case 2:
            cout<<"��Ҫ�ͷŵ��ڴ���׵�ַ�Լ��ռ��С��";
            cin>>t>>n;
            Del(Ram,t,n);
            cout<<"����������أ�";
            getch();
            break;
            case 3:
            exit(0);
            break;
        }
    }while(1);
    return 0;
}

void Initialization(RAM &r)
{
    r.head=r.tail=0;
    r.first=1;//��ʼ����һ����ַ�ڴ��ѱ�ʹ��
    r.last=599;
    r.Nuse=600;
    for(int i=0;i<600;i++)
    {
        if(i!=599)
        r.Memory[i].next=i+1;
        else
        r.Memory[i].next=-1;
    }
}

int Malloc(RAM &r,int size)
{
    if(r.Nuse>=size)
    {
        int n,m,result;
        n=r.tail;
        result=m=r.first;
        for(int i=0;i<size;i++)
        {
            r.Memory[n].next=m;
            n=m;
            m=r.Memory[m].next;
        }
        r.tail=n;
        r.first=m;
        r.Nuse=r.Nuse-size;
        return result;
    }
    else
    {
        cout<<"û���㹻��ʣ��ռ�ɷ��䣡"<<endl;
        return -1;
    }
}

void Del(RAM &r,int h,int size)
{
    int n,m;
    n=h;
    m=r.last;
    int i=0;
    if(SizeOf(r,h)<size)
    {
        cout<<"�ͷŵĿռ���࣡"<<endl;
    }
    else
    {
        r.Nuse=r.Nuse+size;
        for(int i=1;i<size;i++)
        {
            n=r.Memory[n].next;
        }
        r.Memory[r.last].next=h;
        r.last=n;
        int t=r.head;
        while(r.Memory[t].next!=h)
        {
            t=r.Memory[t].next;
        }
        if(n==r.tail)
        {
            r.tail=t;
        }
        else
        {
            r.Memory[t].next=r.Memory[n].next;
        }
    }
}
int SizeOf(RAM r,int h)
{
    int n,m;
    n=h;
    m=1;
    while(n!=r.tail)
    {
        n=r.Memory[n].next;
        m++;
    }
    return m;
}
