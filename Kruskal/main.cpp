#include <iostream>

using namespace std;
struct Edge
{
    int bgn;
    int end;
    int weight;
};
void Sort(Edge E[],int e);//EΪ�ߵļ��ϣ�eΪ�ߵ�����
int Father(int father[],int i);
void Kruskal(Edge E[],int e,int n);//eΪ�ߵ�������nΪ�������
int main()
{
    cout<<"������ͼ�Ľڵ���Ŀ�ͱ�����"<<endl;
    int n,e;
    cin>>n>>e;
    Edge E[e];
    cout<<"�밴���¸�ʽ����ͼ��Ϣ���ڵ��� �ڵ��� Ȩֵ��:"<<endl;//�ڵ��Ŵ��㿪ʼ
    for(int i=0;i<e;i++)
    {
        cin>>E[i].bgn>>E[i].end>>E[i].weight;
    }
    Sort(E,e);
    Kruskal(E,e,n);
    return 0;
}
void Sort(Edge E[],int e)
{
    for(int i=0;i<e;i++)
    {
        for(int j=e-1;j>i;j--)
        {
            if(E[j].weight<E[j-1].weight)
            {
                Edge temp;
                temp=E[j];
                E[j]=E[j-1];
                E[j-1]=temp;
            }
        }
    }
}
int Father(int fa[],int v)
{
    int f=v;
    while(fa[f]>=0&&f!=0)
    {
        f=fa[f];
    }
    return f;
}
void Kruskal(Edge E[],int e,int n)
{
    int fa[n];
    int bnf,edf,i;
    for(i=0;i<n;i++)
    {
        fa[i]=-i;
    }
    for(i=0;i<e;i++)
    {
        bnf=Father(fa,E[i].bgn);
        edf=Father(fa,E[i].end);
        if(bnf!=edf)
        {
            fa[E[i].end]=E[i].bgn;
        }
    }
    for(i=0;i<n;i++)
    {
        if(fa[i]>=0)
        cout<<"�ڵ�"<<i<<"�ĸ��ڵ㣺 "<<fa[i]<<endl;
    }
}
