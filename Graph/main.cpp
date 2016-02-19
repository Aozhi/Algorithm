#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef struct node
{
    int adjvex;
    node *next;
}Edgenode;
typedef struct
{
    char data;
    Edgenode *firstedge;
}Vertexnode;
void CreateGraph(Vertexnode G[],int n,int e);//ͼ���ڽӱ�Ĺ���
void Dfs(Vertexnode G[],int i);//�����������
void Bfs(Vertexnode G[],int i);//�����������
void Make_visited_null();//��ʼ��visited����
bool visited[50];//visited�������ڴ洢�ڵ��Ƿ񱻷��ʹ�

int main()
{
    cout<<"�����붥�����ͱ�����";
    int n,e;
    cin>>n>>e;
    Vertexnode G[n];//����һ��ͼ���ڽӱ�
    CreateGraph(G,n,e);//����ͼ���ڽӱ�
    Make_visited_null();
    cout<<"�������������";
    for(int i=0;i<n;i++)
    {
        Dfs(G,i);
    }
    Make_visited_null();
    cout<<endl<<"�������������";
    for(int i=0;i<n;i++)
    {
        Bfs(G,i);
    }
}
void CreateGraph(Vertexnode G[],int n,int e)
{
    for(int i=0;i<n;i++)
    {
        cout<<"��"<<i+1<<"�����������";
        cin>>G[i].data;
        G[i].firstedge=NULL;
    }
    cout<<"������ߵ���Ϣ"<<endl;
    int head,tail;
    for(int i=0;i<e;i++)
    {
        cin>>head>>tail;//�ڵ�ı�Ŵ�1��ʼ
        head--;
        tail--;
        Edgenode *p=new Edgenode;
        p->adjvex=tail;
        p->next=G[head].firstedge;
        G[head].firstedge=p;
    }
}
void Dfs(Vertexnode G[],int i)
{
    if(!visited[i])
    {
        Edgenode *p;
        int w;
        stack<int> S;//ʹ��c++�Դ���ջ
        cout<<G[i].data<<" ";
        visited[i]=1;
        S.push(i);
        p=G[i].firstedge;
        while(!S.empty())
        {
            while(p!=NULL)
            {
                w=p->adjvex;
                if(!visited[w])
                {
                    cout<<G[w].data<<" ";
                    S.push(w);
                    visited[w]=1;
                    p=G[w].firstedge;
                }
                else
                {
                    p=p->next;
                }
            }
            if(!S.empty())
            {
                S.pop();
                if(!S.empty())
                {
                    int t=S.top();
                    p=G[t].firstedge;
                }
            }
        }
    }
}
void Bfs(Vertexnode G[],int i)
{
   if(!visited[i])
   {
       int t;
       Edgenode *p;
       queue<int> Q;//ʹ��C++�Դ��Ķ���
       Q.push(i);
       visited[i]=1;
       while(!Q.empty())
       {
           t=Q.front();
           Q.pop();
           cout<<G[t].data<<" ";
           p=G[t].firstedge;
           while(p!=NULL)
           {
               if(!visited[p->adjvex])
               {
                   Q.push(p->adjvex);
                   visited[p->adjvex]=1;
               }
               p=p->next;
           }
       }
   }
}
void Make_visited_null()
{
    for(int i=0;i<30;i++)
    {
        visited[i]=0;
    }
}
