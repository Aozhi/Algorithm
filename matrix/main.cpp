#include <iostream>
using namespace std;

struct node
{
    int i;//����Ԫ�ص��к�
    int j;//����Ԫ�ص��к�
    int e;//����Ԫ�ص�ֵ
};

int main()
{
    cout<<"�����������";
    int row;
    cin>>row;
    cout<<"�����������";
    int rank;
    cin>>rank;
    cout<<"�������Ԫ�صĸ�����";
    int number;
    cin>>number;
    node matrix[number];
    for(int i=0;i<number;i++)
    {
        cout<<"������������Ԫ�ص��кţ��кţ��Լ���ֵ��";
        cin>>matrix[i].i>>matrix[i].j>>matrix[i].e;
    }

    /*******���´����Ǿ���ת�õ��Ż��㷨*******/

    node result_matrix[number];
    int list[rank];
    int position[rank];
    for(int i=0;i<rank;i++)
    {
        list[i]=position[i]=0;//���������ֵ����
    }
    for(int i=0;i<number;i++)
    {
        list[matrix[i].j-1]++;//ͳ��ÿһ�з���Ԫ�صĸ���
    }
    for(int i=1;i<rank;i++)
    {
        position[i]=position[i-1]+list[i-1];//ÿһ�е�һ������Ԫ�����µľ������Ԫ���е����
    }
    for(int i=0;i<number;i++)
    {
        int t=matrix[i].j-1;
        int n=position[t];
        result_matrix[n].i=matrix[i].j;
        result_matrix[n].j=matrix[i].i;
        result_matrix[n].e=matrix[i].e;
        position[t]++;
    }

    /**********������ת�ú�ľ������**********/

    int out[rank][row];//����һ���������
    for(int i=0;i<rank;i++)
    {
        for(int j=0;j<row;j++)
        out[i][j]=0;//��������
    }
    for(int t=0;t<number;t++)
    {
        out[result_matrix[t].i-1][result_matrix[t].j-1]=result_matrix[t].e;
    }
    cout<<"ת�ú�ľ���"<<endl;
    for(int i=0;i<rank;i++)
    {
        for(int j=0;j<row;j++)
        {
            cout<<out[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
