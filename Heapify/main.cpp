
/******������ʵ���ö������㷨����int������******/
#include <iostream>
#include <stdlib.h>
using namespace std;

void Min_heapify(int cr[],int i);//������С������
void Build_heap(int cr[]);//������С��
int Heap_min(int cr[]);//������СԪ��
void Heap_insert(int cr[],int key);//��С�Ѳ���Ԫ��
int heap_size;//�ѵĴ�С
int main()
{
    cout << "����Ԫ�صĸ�����" ;
    int n;
    cin>>n;
    heap_size=n-1;
    int Data[n+10];//����һ����΢��һ����ڴ�ռ�
    cout<<"������ÿһ�����ݣ�"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>Data[i];
    }
    Build_heap(Data);
    int result[n];
    for(int i=0;i<n;i++)
    {
        result[i]=Heap_min(Data);
    }
    cout<<"������Ľ��Ϊ��"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}

void Min_heapify(int cr[],int i)
{
    int l=2*i;
    int r=2*i+1;
    int min;
    if(l<=heap_size&&cr[l]<cr[i])
        min=l;
    else
        min=i;
    if(r<=heap_size&&cr[r]<cr[min])
        min=r;
    if(min!=i)
    {
        int temp=cr[i];
        cr[i]=cr[min];
        cr[min]=temp;
        Min_heapify(cr,min);
    }

}
void Build_heap(int cr[])
{
    int t=heap_size;
    for(int i=t/2;i>=0;i--)
    {
        Min_heapify(cr,i);
    }
}
int Heap_min(int cr[])
{
    if(heap_size<0)
        exit(0);
    int min=cr[0];
    cr[0]=cr[heap_size];
    heap_size--;
    Min_heapify(cr,0);
    return min;
}
void Heap_insert(int cr[],int key)
{
    heap_size++;
    cr[heap_size]=key;
    int i=heap_size;
    while(i>0&&cr[i/2]>cr[i])
    {
        int temp=cr[i/2];
        cr[i/2]=cr[i];
        cr[i]=temp;
        i=i/2;
    }
}
