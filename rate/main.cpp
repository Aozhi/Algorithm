#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 26
using namespace std;

struct Rate
{
    int time;
    float value;
};
struct Bank
{
    Rate rate[max];
    int last;
};

void Initialization(Bank &b);
void Insert(Bank &b);
void Change(Bank &b);
void Del(Bank &b);
void Find(Bank b);
void Display(Bank b);
void Save(Bank &b);

int main()
{
    Bank bank;
    bank.last=0;
    Initialization(bank);
    do
    {
        system("cls");
        cout<<"1.�������ʡ�"<<endl<<"2.�޸����ʡ�"<<endl;
        cout<<"3.ɾ�����ʡ�"<<endl<<"4.�������ʡ�"<<endl;
        cout<<"5.��ʾ�������ʡ�"<<endl<<"6.�˳���"<<endl;
        cout<<"��ѡ��";
        int i;
        while(1)//����ֻ��Ӧ1-6�����ְ�������
        {
            if(kbhit())//kbhit����1�Ǳ�ʾ�м��̰�ť����
            {
                char ch;
                ch=getch();
                if(ch>48&&ch<55)//�жϰ��µ��ǲ���1-6�����ּ�
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
            Insert(bank);
            cout<<endl<<"����������أ�";
            getch();
            break;
            case 2:
            Change(bank);
            cout<<endl<<"����������أ�";
            getch();
            break;
            case 3:
            Del(bank);
            cout<<endl<<"����������أ�";
            getch();
            break;
            case 4:
            Find(bank);
            cout<<endl<<"����������أ�";
            getch();
            break;
            case 5:
            Display(bank);
            cout<<endl<<"����������أ�";
            getch();
            break;
            case 6:
            Save(bank);
            exit(0);
            break;
        }
    }while(1);
    return 0;
}

void Initialization(Bank &b)
{
    fstream file;
    ifstream iFile("date");//�ж��ļ��Ƿ���ڣ��������򴴽�
    if(iFile.fail())
    {
        ofstream oFile("date");
        if(oFile.fail())
        throw("�ļ���ʧ�ܣ�");
        oFile.close();
    }
    else
    {
        iFile.close();
    }
    file.open("date",ios::in|ios::out|ios::binary);
    file.seekg(0);
    file.read((char*)&b,sizeof(Bank));
    file.close();
}
void Insert(Bank &b)
{
    char a;
    int time;
    cout << "������ʱ�䵥λ(m�����£�y������): ";
    cin >> a;
    cout << "������ʱ��: ";
    cin >> time;
    if(a=='y' || a=='Y')
        time *= 12;
    cout<<"���������ʣ�";
    float n;
    cin>>n;
    b.rate[b.last].time=time;
    b.rate[b.last].value=n;
    b.last++;
}
void Change(Bank &b)
{
    char a;
    int time;
    int i=0;
    cout << "Ҫ�޸����ݵ�ʱ�䵥λ(m�����£�y������): ";
    cin >> a;
    cout << "Ҫ�޸����ݵ�ʱ��: ";
    cin >> time;
    if(a=='y' || a=='Y')
        time *= 12;
    for(i=0;i<b.last;i++)
    {
        if(b.rate[i].time==time)
        break;
    }
    if(i==b.last)
    cout<<"û�и�ʱ���������Ϣ��";
    else
    {
        int n;
        cout<<"�������µ����ʣ�";
        cin>>n;
        b.rate[i].value=n;
    }
}
void Del(Bank &b)
{
    char a;
    int time;
    int i=0;
    cout << "Ҫɾ�����ݵ�ʱ�䵥λ(m�����£�y������): ";
    cin >> a;
    cout << "Ҫɾ�����ݵ�ʱ��: ";
    cin >> time;
    if(a=='y' || a=='Y')
        time *= 12;
    for(i=0;i<b.last;i++)
    {
        if(b.rate[i].time==time)
        break;
    }
    if(i==b.last)
    cout<<"û�и�ʱ���������Ϣ��";
    else
    {
        for(;i+1<b.last;i++)
        {
            b.rate[i]=b.rate[i+1];
        }
        b.last--;
    }
}
void Find(Bank b)
{
    char a;
    int time;
    int i=0;
    cout << "Ҫ�������ݵ�ʱ�䵥λ(m�����£�y������): ";
    cin >> a;
    cout << "Ҫ�������ݵ�ʱ��: ";
    cin >> time;
    if(a=='y' || a=='Y')
        time *= 12;
    for(i=0;i<b.last;i++)
    {
        if(b.rate[i].time==time)
        break;
    }
    if(i==b.last)
    cout<<"û�и�ʱ���������Ϣ��";
    else
    {
        cout<<"ʱ�䣺"<<b.rate[i].time<<endl;
        cout<<"���ʣ�"<<b.rate[i].value<<endl;
    }
}
void Display(Bank b)
{
    for(int i=0;i<b.last;i++)
    {
        cout<<"ʱ�䣺"<<b.rate[i].time<<endl;
        cout<<"���ʣ�"<<b.rate[i].value<<endl<<endl;
    }
}
void Save(Bank &b)
{
    fstream file;
    file.open("date",ios::in|ios::out|ios::binary);
    file.seekp(0,ios::beg);
    file.write((char*)&b,sizeof(Bank));
}
