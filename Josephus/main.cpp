#include <iostream>
using namespace std;

struct Queue
{
    int data[100];
    int front;//���е�ͷ
    int rear;//���е�β
};

void MakeNull(Queue &Q);//��ն���
bool IsEmpty(Queue Q);//�ж϶����Ƿ�Ϊ��
void InQueue(Queue &Q,int m);//���
void OutQueue(Queue &Q,int &n);//����
int LookQueue(Queue Q);//�鿴����Ԫ��

int main()
{
    cout << "������������N(N<100)��" ;
    int n;
    cin>>n;
    cout<<"�����뿪ʼ�ı��K(K<=N)��";
    int k;
    cin>>k;
    cout<<"�������������M��";
    int m;
    cin>>m;
    Queue q;
    int t=0;
    MakeNull(q);
    int Result[n];
    for(int i=1;i<=n;i++)//��������Ա������
    {
        InQueue(q,i);
    }
    for(int i=0;i<n;i++)
    {
        if(LookQueue(q)!=k)//���ұ��ΪK��Ԫ��
        {
            int data;
            OutQueue(q,data);
            InQueue(q,data);
        }
        else
        break;
    }
    while(!IsEmpty(q))
    {
        for(int i=0;i<m-1;i++)//ѭ���������������
        {
            int data;
            OutQueue(q,data);
            InQueue(q,data);
        }
        OutQueue(q,Result[t]);
        t++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<Result[i]<<"  ";
    }
    return 0;
}

/***********���в��������ľ���ʵ��***********/

void MakeNull(Queue &Q)
{
    Q.front=Q.rear=0;
}
bool IsEmpty(Queue Q)
{
    if(Q.front==Q.rear)
    return true;
    else
    return false;
}
void InQueue(Queue &Q,int m)
{
    Q.data[Q.rear%100]=m;
    Q.rear++;
}
void OutQueue(Queue &Q,int &n)
{
    n=Q.data[Q.front%100];
    Q.front++;
}
int LookQueue(Queue Q)
{
    return Q.data[Q.front];
}
