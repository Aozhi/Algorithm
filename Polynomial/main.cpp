#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct DLine
{
	//ϵ��
    int coef;
	//ָ��
    int exp;
	//ǰһ��
    DLine *pre;
	//��һ��
    DLine *next;
};




int main()
{
    char cTemp[1024];
    char *pChar;
    int flag=0;
	//������������ͷ
    DLine* phead1=new DLine();
    DLine* phead2=new DLine();
    phead1->pre=phead1->next=NULL;
    phead2->pre=phead2->next=NULL;
    DLine* phead3=NULL;
    cout<<"���������зֱ� ����ϵ����ָ����˳��������������ʽ��ÿһ�����ָ�����ɴ�С˳��"<<endl;
	//�����һ���ַ��������Կո���зָ�ŵ�ָ��ϵ����
    DLine* pTemp = phead1;
    cin.getline(cTemp,1024);

    pChar = strtok(cTemp," ,");
    phead1->coef = atoi(pChar);
    pChar = strtok(NULL," ,");
    phead1->exp = atoi(pChar);


    pChar =strtok(NULL," ,");
    while(pChar)
    {
        pTemp->next=new DLine();
        pTemp->next->pre = pTemp;
        pTemp = pTemp->next;
        pTemp->coef = atoi(pChar);
        pChar = strtok(NULL," ,");
        pTemp->exp = atoi(pChar);

        pChar =strtok(NULL," ,");
    }
	//����ڶ����ַ�������Ϊ����
    pTemp = phead2;
    cin.getline(cTemp,1024);

    pChar = strtok(cTemp," ,");
    phead2->coef = atoi(pChar);
    pChar = strtok(NULL," ,");
    phead2->exp = atoi(pChar);


    pChar =strtok(NULL," ,");
    while(pChar)
    {
        pTemp->next=new DLine();
        pTemp->next->pre = pTemp;
        pTemp = pTemp->next;
        pTemp->coef = atoi(pChar);
        pChar = strtok(NULL," ,");
        pTemp->exp = atoi(pChar);

        pChar =strtok(NULL," ,");
    }
    cout<<"1.����ʽ��ӡ�"<<endl<<"2.����ʽ�����"<<endl<<"��ѡ��";
    cin>>flag;
    flag=-flag+2;


	//��������ǰ��׼���������ָ��������Ϊͷ
    if(phead1->exp > phead2->exp)
    {
        phead3 = phead1;
        phead1 = phead1->next;
        phead3->next= NULL;
    }
    else if(phead1->exp < phead2->exp)
    {
        phead3= phead2;
        if(!flag)
        phead2->coef=-(phead2->coef);
        phead2 = phead2->next;
        phead3->next=NULL;
    }
    else
    {
        phead3=phead1;
        if(flag)
        phead3->coef = phead3->coef + phead2->coef;
        else
        phead3->coef = phead3->coef - phead2->coef;

        phead1 = phead1->next;
        phead2=phead2->next;
        phead3->next = NULL;
    }
    pTemp = phead3;
	//����ʽ���򷨽���������ϲ���������
    while(phead1&&phead2)
    {
        if(phead1->exp > phead2->exp)
        {
            pTemp->next=phead1;
            phead1=phead1->next;
            pTemp->next->pre=pTemp;
            pTemp = pTemp->next;
            pTemp->next = NULL;
        }
        else if (phead1->exp < phead2->exp)
        {
            pTemp->next=phead2;
            if(!flag)
            phead2->coef=-(phead2->coef);
            phead2=phead2->next;
            pTemp->next->pre=pTemp;
            pTemp = pTemp->next;
            pTemp->next = NULL;
        }
        else
        {
            pTemp->next=phead1;
            if(flag)
            pTemp->next->coef = pTemp->next->coef +phead2->coef;
            else
            pTemp->next->coef = pTemp->next->coef -phead2->coef;
            phead1= phead1->next;
            phead2 = phead2->next;
            pTemp->next->pre = pTemp;
            pTemp=pTemp ->next;
            pTemp->next=NULL;
        }
    }
    //��ʣ�������׷�ӵ�ĩβ
    if(!phead1)
    {
        pTemp->next=phead2;
        while(phead2&&!flag)
        {
            phead2->coef=-(phead2->coef);
            phead2=phead2->next;
        }
    }
    else if(!phead2)
    {
        pTemp->next=phead1;
    }

	//���������������Ϊ���
	cout<<endl<<"����ʽ������Ϊ��"<<endl;
    pTemp=phead3;
    while(pTemp)
    {
		if(pTemp->coef==0)
		{
			pTemp=pTemp->next;
			continue;
		}
		if(pTemp->exp==0)
		{
			cout<<pTemp->coef<<endl;
		}
		else
        cout<<pTemp->coef<<"x^"<<pTemp->exp<<" ";
        pTemp=pTemp->next;
    }
	getchar();
    return 0;
}

