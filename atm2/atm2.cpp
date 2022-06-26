#include<stdio.h>
int control=1;                    //控制结束的变量 
int order=1;                      //控制顺序的变量
int confirmpassword[10];          //确认用的密码    
int menu(int a);              //菜单 
void authoring();                 //创建用户
void save_money();                //存钱 
void get_money();                 //取钱  
void inquire();                   //查询  
void shift_money();               //转账 
void lose();                      //挂失
void undo();                      //解挂
void eliminate();                 //销户
void change_password();           //改密
void close();                     //退出
int judge_exist(int a);           //判断用户名存在  输入用户名，若存在返回用户名的值，若不存在输出提示并返回0
int judge_status(int a);          //判断用户状态    输入用户名，若正常返回0，若挂失返回1并提示，若冻结返回2并提示
 
typedef struct
{
	int    account;            //账号
	char    username[10];           //用户名
	int    password;           //密码
	double money;              //钱
	int    status;             //状态：0正常 1挂失 2销户
}Account;
Account zh[10];       //创建10个用户
 
int main()
{
	int j=1,a;
	for(j=1;j<=10;j++)
	{
		zh[j].money=0;
		zh[j].status=0;
	}
	printf("欢迎来到银行操作系统ATM\n");	
	while(control==1)
	{
		printf("===============================================\n");
		printf("请选择你的操作\n");
		printf("1，开户  2，存款  3，取款  4，查询  5，转账 \n");
		printf("6，挂失  7，解挂  8，销户  9，改密  10，退出\n");
		printf("===============================================\n");
		printf("选择的操作为：");
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
	printf("正在开户.....\n");
	printf("账号:%d\n",zh[order].account);
	printf("输入户主姓名:");
	scanf("%s",&zh[order].username);
	printf("请输入密码:");
	scanf("%d",&zh[order].password);
	printf("请再次确认密码:");
	scanf("%d",&confirmpassword[order]);
	if(zh[order].password==confirmpassword[order])
	{
		printf("开户成功!\n\n");
		order++;
	}
	else
	{
		printf("密码不一致开户失败\n\n");
		zh[order].password=0;
		confirmpassword[order]=0;
	}
}
 
void save_money() 
{
	int exist2,status2,account2,password2,order2;
	double money2;
	printf("请输入你的账号：");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		status2=judge_status(zh[order2].status);
		if(status2==0)
		{
			printf("请输入密码:");
			scanf("%d",&password2);
			if(password2==zh[order2].password)
			{
				printf("户主姓名:%s\n",zh[order2].username);
				printf("请输入存款金额：");
				scanf("%lf",&money2);
				zh[order2].money=zh[order2].money+money2;
				printf("你当前的余额为:%lf\n\n",zh[order2].money);
			}
			else
			{
				printf("密码错误\n\n");
			}
 
		}
	}
}
 
void get_money()
{
	int exist2,status2,account2,password2,order2;
	double money2;
	printf("请输入你的账号：");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		status2=judge_status(zh[order2].status);
		if(status2==0)
		{
			printf("请输入密码:");
			scanf("%d",&password2);
			if(password2==zh[order2].password)
			{
				printf("户主姓名:%s\n",zh[order2].username);
				printf("请输入取款金额：");
				scanf("%lf",&money2);
				zh[order2].money=zh[order2].money-money2;
				if(zh[order2].money>=0)
				{
					printf("取款成功,你当前的余额为:%lf\n\n",zh[order2].money);
				}
				else
				{
					printf("余额不足取款失败\n\n");
					zh[order2].money=zh[order2].money+money2;
				}
			}
			else
			{
				printf("密码错误\n\n");
			}
 
		}
	}
}
 
void inquire()
{
	int account2,exist2,order2,password2;
	printf("请输入你的账号：");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=exist2-1000;
		printf("请输入密码:");
		scanf("%d",&password2);
		if(password2==zh[order2].password)
		{
			switch(zh[order2].status)
			{
			case 0:printf("账号:%d            姓名:%s\n",account2,zh[order2].username);
				printf("状态:正常          余额:%lf\n\n",zh[order2].money);
				break;	
			case 1:printf("账号:%d            姓名:%s\n",account2,zh[order2].username);
				printf("状态:挂失          余额:%lf\n\n",zh[order2].money);
				break;	
			case 2:printf("账号:%d            姓名:%s\n",account2,zh[order2].username);
				printf("状态:销户          余额:%lf\n\n",zh[order2].money);
				break;	
			}
		}
		else
		{
			printf("密码错误\n\n");
		}
	}
}
 
void shift_money()
{
	int exist2,status2,account2,password2,order2,account3,exist3,order3,status3;
	double money2;
	printf("请输入你的账号：");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		status2=judge_status(zh[order2].status);
		if(status2==0)
		{
			printf("请输入密码:");
			scanf("%d",&password2);
			if(password2==zh[order2].password)
			{
				printf("户主姓名:%s\n",zh[order2].username);
				printf("请输入转账账号：");
				scanf("%d",&account3);
				exist3=judge_exist(account3);
				if(exist3!=0)
				{
					order3=account3-1000;
					status3=judge_status(zh[order3].status);
					if(status3==0)
					{
						printf("请输入你要转账的金额:");
						scanf("%lf",&money2);
						zh[order2].money=zh[order2].money-money2;
						zh[order3].money=zh[order3].money+money2;
						if(zh[order2].money>=0)
						{
							printf("转账成功，你的余额为%lf\n\n",zh[order2].money);
						}
						else
						{
						printf("余额不足,转账失败\n\n");
						zh[order2].money=zh[order2].money+money2;
						zh[order3].money=zh[order3].money-money2;
						}
 					}
				}
			}
			else
			{
				printf("密码错误\n\n");
			}
 
 
		}
	}
}
 
void lose()
{
int exist2,account2,password2,order2;
	printf("请输入你的账号：");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		printf("请输入密码:");
		scanf("%d",&password2);
		if(password2==zh[order2].password)
		{
		printf("挂失成功,该卡已挂失\n\n");
		zh[order2].status=1;
		}
		else
		{
		printf("密码错误\n\n");
		}
	}	
}
 
void undo()
{
int exist2,account2,password2,order2;
	printf("请输入你的账号：");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		printf("请输入密码:");
		scanf("%d",&password2);
		if(password2==zh[order2].password)
		{
		printf("解挂成功\n\n");
		zh[order2].status=0;
		}
		else
		{
		printf("密码错误\n\n");
		}
	}	
	
}
 
void eliminate()
{
int exist2,account2,password2,order2;
	printf("请输入你的账号：");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		printf("请输入密码:");
		scanf("%d",&password2);
		if(password2==zh[order2].password)
		{
		printf("销户成功\n\n");
		zh[order2].account=0;
		}
		else
		{
		printf("密码错误\n\n");
		}
	}	
	
}
 
void change_password()
{
 int exist2,account2,order2;
	printf("请输入你的账号：");
	scanf("%d",&account2);
	exist2=judge_exist(account2);
	if(exist2!=0)
	{
		order2=account2-1000;
		printf("正在验证身份....\n");
		printf("验证成功请输入新密码:");
		scanf("%d",&zh[order2].password);
        printf("改密成功\n\n");	
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
		printf("对不起该用户不存在\n\n");
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
		printf("该用户已挂失\n\n");
		return 1;
	}
	if(a==2)
	{
		printf("该用户已被冻结\n\n");
		return 2;
	}
 
	return 0;
}