#include <iostream>
#define Max 100000
using namespace std;
void Floyd(int A[][30],int G[][30],int n);
int main()
{
    int n;
    cout<<"ͼ�Ľڵ���Ŀ��";
    cin>>n;
    int Graph[n][30];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            Graph[i][j]=Max;
        }
    }
    cout<<"�밴���¸�ʽ����ͼ��Ϣ���ڵ��� �ڵ��� Ȩֵ���������ͬ����"<<endl;
    while(1)
    {
        int num1,num2,weight;
        cin>>num1>>num2>>weight;
        if(num1==num2)
        break;
        Graph[num1][num2]=weight;
    }
    int result[n][30];
    Floyd(result,Graph,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(result[i][j]<Max)
            {
                cout<<"�ڵ�"<<i<<"���ڵ�"<<j<<"�ľ���Ϊ��"<<result[i][j]<<endl;
            }
        }
    }
    return 0;
}
void Floyd(int A[][30],int G[][30],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j]=G[i][j];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(A[i][k]+A[k][j]<A[i][j])
                A[i][j]=A[i][k]+A[k][j];
            }
        }
    }
}
