#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct Tnode//�������Ľڵ�
{
    struct Tnode *lchild;
    struct Tnode *rchild;
    char data;
    bool lflag;//ΪfalseʱΪ������Ϊtrueʱ��ʵ�ʵĶ���
    bool rflag;
};
typedef Tnode* Ttree;
bool CreateT(Ttree &t);
void PreOrder(Ttree t);
void InOrder(Ttree t);
void PostOrder(Ttree t);
void PreCreateD(Ttree &dt);
void InCreateD(Ttree &dt);
void PostCreateD(Ttree &dt);
void VisitPre(Ttree dt);
void VisitIn(Ttree dt);
void VisitPost(Ttree dt);
Ttree CopyTree(Ttree t);
void MakeNull();
Ttree pData[30];//���ڴ�Žڵ�ָ�������
int index=0;
int main()
{
    Ttree Pre_dt=new Tnode;
    Ttree In_dt=new Tnode;
    Ttree Post_dt=new Tnode;
    Ttree T;
    cout<<"�밴���ȸ���˳������������Ľڵ㣬Ϊ�յĶ����á�#����ʾ��"<<endl;
    CreateT(T);
    Pre_dt->lchild=T;
    In_dt->lchild=CopyTree(T);
    Post_dt->lchild=CopyTree(T);
    PreCreateD(Pre_dt);
    InCreateD(In_dt);
    PostCreateD(Post_dt);
    cout<<"����ǰ�������"<<endl;
    VisitPre(Pre_dt);
    cout<<endl;
    cout<<"�������������"<<endl;
    VisitIn(In_dt);
    cout<<endl;
    cout<<"�������������"<<endl;
    VisitPost(Post_dt);
    cout<<endl;
    return 0;
}

bool CreateT(Ttree &t)
{
    char ch;
    cin>>ch;
    if(ch=='#')//���롮#��ʱ��ʾ�ýڵ�Ϊ��
    {
        t=NULL;
        return false;
    }
    else
    {
        if(!(t=new Tnode))
        exit(1);
        t->data=ch;
        //CreateT(t->lchild);
        //CreateT(t->rchild);
        t->lflag=CreateT(t->lchild);//���������
        t->rflag=CreateT(t->rchild);//�����Ҷ���
        return true;
    }
}
void PreOrder(Ttree t)
{
    if(t!=NULL)
    {
        pData[index]=t;
        index++;
        //cout<<t->data<<"  ";
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}
void InOrder(Ttree t)
{
    if(t!=NULL)
    {
        InOrder(t->lchild);
        pData[index]=t;
        index++;
        InOrder(t->rchild);
    }
}
void PostOrder(Ttree t)
{
    if(t!=NULL)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        pData[index]=t;
        index++;
    }
}
void PreCreateD(Ttree &dt)
{
    MakeNull();
    PreOrder(dt->lchild);
    int i=0;
    for(i=0;pData[i+1]!=NULL;i++)
    {
        if(pData[i]->lflag==0&&i==0)
        {
            pData[i]->lchild=dt;
        }
        if(pData[i]->lflag==0&&i!=0)
        {
            pData[i]->lchild=pData[i-1];
        }
        if(pData[i]->rflag==0)
        {
            pData[i]->rchild=pData[i+1];
        }
    }
    if(pData[i]->rflag==0)
    {
        pData[i]->rchild=dt;
    }
    if(pData[i]->lflag==0&&i==0)
    {
        pData[i]->lchild=dt;
    }
}
void InCreateD(Ttree &dt)
{
    MakeNull();
    InOrder(dt->lchild);
    int i=0;
    for(i=0;pData[i+1]!=NULL;i++)
    {
        if(pData[i]->lflag==0&&i==0)
        {
            pData[i]->lchild=dt;
        }
        if(pData[i]->lflag==0&&i!=0)
        {
            pData[i]->lchild=pData[i-1];
        }
        if(pData[i]->rflag==0)
        {
            pData[i]->rchild=pData[i+1];
        }
    }
    if(pData[i]->rflag==0)
    {
        pData[i]->rchild=dt;
    }
    if(pData[i]->lflag==0&&i==0)
    {
        pData[i]->lchild=dt;
    }
}
void PostCreateD(Ttree &dt)
{
    MakeNull();
    PostOrder(dt->lchild);
    int i=0;
    for(i=0;pData[i+1]!=NULL;i++)
    {
        if(pData[i]->lflag==0&&i==0)
        {
            pData[i]->lchild=dt;
        }
        if(pData[i]->lflag==0&&i!=0)
        {
            pData[i]->lchild=pData[i-1];
        }
        if(pData[i]->rflag==0)
        {
            pData[i]->rchild=pData[i+1];
        }
    }
    if(pData[i]->rflag==0)
    {
        pData[i]->rchild=dt;
    }
    if(pData[i]->lflag==0&&i==0)
    {
        pData[i]->lchild=dt;
    }
}
void MakeNull()
{
    index=0;
    for(int i=0;i<30;i++)
    {
        pData[i]=NULL;
    }
}
void VisitPre(Ttree dt)
{
    Ttree t=dt->lchild;
    while(t!=NULL&&t!=dt)
    {
        cout<<t->data<<"  ";
        if(t->lflag!=0)
        t=t->lchild;
        else
        t=t->rchild;
    }
}
void VisitIn(Ttree dt)
{
    Ttree t=dt->lchild;
    Ttree pre=NULL;
    while(t!=dt)
    {
        while(t->lflag!=0&&t->lchild!=pre)
        {
            t=t->lchild;
        }
        cout<<t->data<<"  ";
        while(t->rflag==0&&t->rchild!=dt)
        {
            t=t->rchild;
            cout<<t->data<<"  ";
        }
        pre=t;
        t=t->rchild;
    }
}
void VisitPost(Ttree dt)
{
    stack<char> s;
    Ttree t=dt->lchild;
    while(t!=NULL&&t!=dt)
    {
        s.push(t->data);
        if(t->rflag!=0)
        t=t->rchild;
        else
        t=t->lchild;
    }
    while(!s.empty())
    {
        cout<<s.top()<<"  ";
        s.pop();
    }
}
Ttree CopyTree(Ttree t)
{
    Ttree temp;
    if(t!=NULL)
    {
        temp=new Tnode;
        temp->lchild=CopyTree(t->lchild);
        temp->rchild=CopyTree(t->rchild);
        temp->data=t->data;
        temp->lflag=t->lflag;
        temp->rflag=t->rflag;
        return temp;
    }
    else
    return NULL;
}
