#include<stdio.h>
int control=1;                    //���ƽ����ı��� 
int order=1;                      //����˳��ı���
int confirmpassword[10];          //ȷ���õ�����    
int menu(int a);              //�˵� 
void authoring();                 //�����û�
void save_money();                //��Ǯ 
void get_money();                 //ȡǮ  
void inquire();                   //��ѯ  
void shift_money();               //ת�� 
void lose();                      //��ʧ
void undo();                      //���
void eliminate();                 //����
void change_password();           //����
void close();                     //�˳�
int judge_exist(int a);           //�ж��û�������  �����û����������ڷ����û�����ֵ���������������ʾ������0
int judge_status(int a);          //�ж��û�״̬    �����û���������������0������ʧ����1����ʾ�������᷵��2����ʾ
 
typedef struct
{
	int    account;            //�˺�
	char    username[10];           //�û���
	int    password;           //����
	double money;              //Ǯ
	int    status;             //״̬��0���� 1��ʧ 2����
}Account;
Account zh[10];       //����10���û�
 
int main()
{
	int j=1,a;
	for(j=1;j<=10;j++)
	{
		zh[j].money=0;
		zh[j].status=0;
	}
	printf("��ӭ�������в���ϵͳATM\n");	
	while(control==1)
	{
		printf("===============================================\n");
		printf("��ѡ����Ĳ���\n");
		printf("1������  2�����  3��ȡ��  4����ѯ  5��ת�� \n");
		printf("6����ʧ  7�����  8������  9������  10���˳�\n");
		printf("===============================================\n");
		printf("ѡ��Ĳ���Ϊ��");
		scanf("%d",&a);
		menu(a);
	}
	return 0; 
}
 
int menu(int a)
{
	switch(a)
	{
	case 1:authoring();;break;
	case 2:save_money();break;
	case 3:get_money();break;
	case 4:inquire();break;
	case 5:shift_money();break;
	case 6:lose();break;
	case 7:undo();break;
	case 8:eliminate();break;
	case 9:change_password();break;
	case 10:close();break;
	}
	return 0;
}
 
void authoring()
{
	zh[order].account=1000+order;
	printf("���ڿ���.....\n");
	printf("�˺�:%d\n",zh[order].account);
	printf("���뻧������:");
	scanf("%s",&zh[order].username);
	printf("����������:");
	scanf("%d",&zh[order].password);
	printf("���ٴ�ȷ������:");
	scanf("%d",&confirmpassword[order]);
	if(zh[order].password==confirmpassword[order])
	{
		printf("�����ɹ�!\n\n");
		order++;
	}
	else
	{
		printf("���벻һ�¿���ʧ��\n\n");
		zh[order].password=0;
		confirmpassword[order]=0;
	}
}
 
void save_money() 
{
	int exist2,status2,account2,password2,order2;
	double money2;
	printf("����������˺ţ�");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		status2=judge_status(zh[order2].status);
		if(status2==0)
		{
			printf("����������:");
			scanf("%d",&password2);
			if(password2==zh[order2].password)
			{
				printf("��������:%s\n",zh[order2].username);
				printf("���������");
				scanf("%lf",&money2);
				zh[order2].money=zh[order2].money+money2;
				printf("�㵱ǰ�����Ϊ:%lf\n\n",zh[order2].money);
			}
			else
			{
				printf("�������\n\n");
			}
 
		}
	}
}
 
void get_money()
{
	int exist2,status2,account2,password2,order2;
	double money2;
	printf("����������˺ţ�");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		status2=judge_status(zh[order2].status);
		if(status2==0)
		{
			printf("����������:");
			scanf("%d",&password2);
			if(password2==zh[order2].password)
			{
				printf("��������:%s\n",zh[order2].username);
				printf("������ȡ���");
				scanf("%lf",&money2);
				zh[order2].money=zh[order2].money-money2;
				if(zh[order2].money>=0)
				{
					printf("ȡ��ɹ�,�㵱ǰ�����Ϊ:%lf\n\n",zh[order2].money);
				}
				else
				{
					printf("����ȡ��ʧ��\n\n");
					zh[order2].money=zh[order2].money+money2;
				}
			}
			else
			{
				printf("�������\n\n");
			}
 
		}
	}
}
 
void inquire()
{
	int account2,exist2,order2,password2;
	printf("����������˺ţ�");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=exist2-1000;
		printf("����������:");
		scanf("%d",&password2);
		if(password2==zh[order2].password)
		{
			switch(zh[order2].status)
			{
			case 0:printf("�˺�:%d            ����:%s\n",account2,zh[order2].username);
				printf("״̬:����          ���:%lf\n\n",zh[order2].money);
				break;	
			case 1:printf("�˺�:%d            ����:%s\n",account2,zh[order2].username);
				printf("״̬:��ʧ          ���:%lf\n\n",zh[order2].money);
				break;	
			case 2:printf("�˺�:%d            ����:%s\n",account2,zh[order2].username);
				printf("״̬:����          ���:%lf\n\n",zh[order2].money);
				break;	
			}
		}
		else
		{
			printf("�������\n\n");
		}
	}
}
 
void shift_money()
{
	int exist2,status2,account2,password2,order2,account3,exist3,order3,status3;
	double money2;
	printf("����������˺ţ�");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		status2=judge_status(zh[order2].status);
		if(status2==0)
		{
			printf("����������:");
			scanf("%d",&password2);
			if(password2==zh[order2].password)
			{
				printf("��������:%s\n",zh[order2].username);
				printf("������ת���˺ţ�");
				scanf("%d",&account3);
				exist3=judge_exist(account3);
				if(exist3!=0)
				{
					order3=account3-1000;
					status3=judge_status(zh[order3].status);
					if(status3==0)
					{
						printf("��������Ҫת�˵Ľ��:");
						scanf("%lf",&money2);
						zh[order2].money=zh[order2].money-money2;
						zh[order3].money=zh[order3].money+money2;
						if(zh[order2].money>=0)
						{
							printf("ת�˳ɹ���������Ϊ%lf\n\n",zh[order2].money);
						}
						else
						{
						printf("����,ת��ʧ��\n\n");
						zh[order2].money=zh[order2].money+money2;
						zh[order3].money=zh[order3].money-money2;
						}
 					}
				}
			}
			else
			{
				printf("�������\n\n");
			}
 
 
		}
	}
}
 
void lose()
{
int exist2,account2,password2,order2;
	printf("����������˺ţ�");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		printf("����������:");
		scanf("%d",&password2);
		if(password2==zh[order2].password)
		{
		printf("��ʧ�ɹ�,�ÿ��ѹ�ʧ\n\n");
		zh[order2].status=1;
		}
		else
		{
		printf("�������\n\n");
		}
	}	
}
 
void undo()
{
int exist2,account2,password2,order2;
	printf("����������˺ţ�");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		printf("����������:");
		scanf("%d",&password2);
		if(password2==zh[order2].password)
		{
		printf("��ҳɹ�\n\n");
		zh[order2].status=0;
		}
		else
		{
		printf("�������\n\n");
		}
	}	
	
}
 
void eliminate()
{
int exist2,account2,password2,order2;
	printf("����������˺ţ�");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		printf("����������:");
		scanf("%d",&password2);
		if(password2==zh[order2].password)
		{
		printf("�����ɹ�\n\n");
		zh[order2].account=0;
		}
		else
		{
		printf("�������\n\n");
		}
	}	
	
}
 
void change_password()
{
 int exist2,account2,order2;
	printf("����������˺ţ�");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		printf("������֤���....\n");
		printf("��֤�ɹ�������������:");
		scanf("%d",&zh[order2].password);
        printf("���ܳɹ�\n\n");	
	}	
}
 
void close()
{
control=2;
}
 
int judge_exist(int a)
{
	int i,j=0;
	for(i=1;i<=10;i++)
	{
		if(a==zh[i].account)
		{
			j=1;
 
			break;
		}
	}
	if(j==0)
	{
		a=0;
		printf("�Բ�����û�������\n\n");
	}
 
	return a;
}
 
int judge_status(int a)
{
	if(a==0)
	{
		return 0;
	}
	if(a==1)
	{
		printf("���û��ѹ�ʧ\n\n");
		return 1;
	}
	if(a==2)
	{
		printf("���û��ѱ�����\n\n");
		return 2;
	}
 
	return 0;
}