#include <iostream>
#include <queue>
using namespace std;
struct node
{
    struct node* lchild;
    struct node* rchild;
    char data;
};
typedef node* Btree;
void Create(Btree &t);
void PreOrder(Btree t);//�����ȸ�������������Ӧ��������ʾ��������������ͬ
void PostOrder(Btree t);//���ĺ��������������Ӧ��������ʾ��������������ͬ
void LevelOrder(Btree t);//���Ĳ������
int main()
{
    Btree tree;
    cout<<"�밴���ȸ���˳������������Ľڵ㣬Ϊ�յĶ����á�#����ʾ��"<<endl;
    Create(tree);
    cout<<"�����ȸ�˳�������";
    PreOrder(tree);
    cout<<endl;
    cout<<"���պ����˳�������";
    PostOrder(tree);
    cout<<endl;
    cout<<"���ղ������˳�������";
    LevelOrder(tree);
    cout<<endl;
    return 0;
}
void Create(Btree &t)//�����ȸ�˳�򴴽�������ʽ�ṹ�Ķ�����
{
    char ch;
    cin>>ch;
    if(ch=='#')//���롮#��ʱ��ʾ�ýڵ�Ϊ��
    t=NULL;
    else
    {
        if(!(t=new node))
        return ;
        t->data=ch;
        Create(t->lchild);//���������
        Create(t->rchild);//�����Ҷ���
    }
}
void PreOrder(Btree t)
{
    if(t!=NULL)
    {
        cout<<t->data<<"  ";
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}
void PostOrder(Btree t)
{
    if(t!=NULL)
    {
        PostOrder(t->lchild);
        cout<<t->data<<"  ";
        PostOrder(t->rchild);
    }
}
void LevelOrder(Btree t)
{
    queue<Btree> q;
    while(!q.empty())
    q.pop();
    Btree tem=t;
    while(tem!=NULL)
    {
        q.push(tem);
        tem=tem->rchild;
    }
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        cout<<tem->data<<"  ";
        tem=tem->lchild;
        while(tem!=NULL)
        {
            q.push(tem);
            tem=tem->rchild;
        }
    }
}
