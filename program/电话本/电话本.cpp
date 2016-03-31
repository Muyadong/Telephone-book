// 练习.cpp : 定义控制台应用程序的入口点
#include "stdafx.h"


void updatemenu(int);
  //数据个数//文件是否保存//文件是否被访问
int date=0, savef=0, lock=0;//定义全局变量，解析上；
void dell(int k);
void onedate();         //显示单个数据
int searchname(char name[]);//按姓名查找
void showsearchdate();//显示所要查找的数据
typedef struct telephonebook
{
	char name[10];
	char telephone[20];
	char address[30];

}TELEPHONE;
TELEPHONE tele[200];
//主函数*****************
int main(void)
{
	loaddate();
	mainmenu();
	return 0;
}
//主菜单*****************
int a=0;
void mainmenu()
{
	system("cls");
	printf("\n\n\n\n\t\t******************************************\n");
	printf("\t\t****************电话本系统****************\n");
	printf("\t\t**                                      **\n");
	printf("\t\t**   1.查看所有数据       2.查找数据    **\n");
	printf("\t\t**   3.添加数据           4.修改数据    **\n");
	printf("\t\t**   5.删除数据           6.整理数据    **\n");
	printf("\t\t**   7.退出               8.显示单个数据**\n");
	printf("\t\t**                                      **\n");
	printf("\t\t******************************************\n");
	printf("\t\t******************************************\n");
	if(a==1)
	{
		printf("输入未知，请重新输入：");
		a=0;
	}
	else
	printf("\n\t请输入要执行的事项： ");
	
	int slt;
	//printf("\n\t请输入要执行的事项： ");
	scanf("%d",&slt);
	switch(slt)
	{
		case 1:searchAlldate();break;
		case 2:searchDate();break;
		case 3:addDate();break;
		case 4:update();break;
		case 5:deleteDate();break;
		case 6:sortdate();break;
		case 7:exitmenu();
		case 8:onedate();break;
		default:
			{
				a=1;
				system("cls");//清屏
				mainmenu();
			}
	}
}
//查看所有数据*************
void searchAlldate()
{
	int i;
	system("cls");
	printf("\n\n\n");
	for(i=0;i<date;i++)
	{
		printf("\t\t%s %s %s\n",tele[i].name,tele[i].telephone,tele[i].address);
	}
	getchar();
	printf("\n\t请按任意键返回.....");
	getchar();
	system("cls");//清屏
	mainmenu();
	return ;
}
//读入数据  进行显示********
void loaddate()
{
	int i;
	FILE *read;
	if((read = fopen("Date.txt","r"))==NULL)//判断是否能够读取文件？
	{
		printf("\t\t文件读取失败！！");
	}
	else
	{
		fscanf(read,"%d",&date);
		for(i=0;i<date;i++)
			fscanf(read," %s %s %s",&tele[i].name,&tele[i].telephone,&tele[i].address);
	}
	
	printf("\n\t文件载入成功!\n\t\t请按任意键返回......");
	return ;
}
//显示单个数据****************
void onedate()
{
	char  flag;
	int mm;
sb:	printf("\n\t请输入要显示信息的下标： ");
	scanf("%d",&mm);
	printf("\n\t输出的信息为： 姓名：%s 电话：%s 地址：%s\n", tele[mm].name,tele[mm].telephone,tele[mm].address);
	printf("\n\t是否继续？ 继续请按（Y） 否则按（N） ");
	printf("\n\t请填入你的选择： ");
	scanf("%s",&flag);
	flag = tolower(flag);
	if(flag == 'y')
		goto sb;
	else 	
	getchar();
	printf("\n\t请按任意键返回......");
	getchar();
	system("cls");
	mainmenu();
	/*int i;
	FILE *read;
	if((read = fopen("Date.txt","r"))==NULL)
	{
		printf("\n\t\t打开文件失败！\n");
		exit(0);
	}
	else
	{
		fscanf(read, "%d",&date);
		for(i=0;i<date;i++)
		{
			
		}
	}*/
}
//专门显示 查找数据  显示数据**********8
void showsearchdate(int mm)
{
	printf("\n\t信息为： 姓名：%s 电话：%s 地址：%s\n", tele[mm].name,tele[mm].telephone,tele[mm].address);
	//printf("\n\t按任意键返回主菜单....");
	//getchar();
	getchar();
	//mainmenu();
}
//查找数据******************
void searchDate()
{
	int fla,mm;
	char nam[20];
	system("cls");
	printf("\n\t请选择需要查找的方式： 1.按姓名查找， 2.返回\n");
	printf("\n\t请填入你的选择： ");
	scanf("%d",&fla);
	switch(fla)
	{
	case 1:
		printf("\n请输入姓名： ");
		scanf("%s",&nam);
		mm = searchname(nam);
		if(mm == -1)
			printf("\n\t未找到数据！");
		else
			showsearchdate(mm);
		break;
	case 2:
		system("cls");
		mainmenu();
	}

}
//添加数据*****************8
void addDate(void)
{
	int fla;
	char flag;
	system("cls");//清屏
	printf("\t*************添加数据*************\n");
	printf("\n\t请选择要执行的任务     1.添加    2.返回\n");
	printf("\t请选择： ");
	scanf("%d",&fla);
	switch(fla)
	{
	case 1:
	tt:	printf("请输入姓名： ");
		scanf("%s",&tele[date].name);
		printf("请输入电话： ");
		scanf("%s",&tele[date].telephone);
		printf("请输入地址： ");
		scanf("%s",&tele[date].address);
		
		date++;
		savef=1;//表示数据已经改变    但未保存；
		getchar();
		printf("\n\t\t是否继续添加？  继续请按Y，停止就按N....\n\n");
		printf("\t\t请选择： ");
		scanf("%s",&flag);
		flag = tolower(flag);
		if(flag == 'y')
			goto tt;
		else
			savedate();//执行保存数据；
		//getchar();
		//printf("按任意键返回......");
		//getchar();
		
		//break;
	case 2:
		system("cls");//清屏
		mainmenu();
	default :
		break;
		
	}
}
//保存数据****************
void savedate(void)
{
	int i;
	FILE *write;
	if((write = fopen("Date.txt","w"))==NULL)
	{
		printf("打开文件失败！\n"); exit(0);
	}
	fprintf(write,"%d\n",date);
	for(i=0;i<date;i++)
		fprintf(write,"%s %s %s\n",tele[i].name,tele[i].telephone,tele[i].address);
	if(fclose(write))
	{
		printf("关闭文件出错！\n");
		exit(0);
	}
	savef=0;
	printf("\n\n\t\t\t保存成功！\n");
	printf("\n\t\t请按任意键返回....");
	getchar();
	getchar();
	return ;
}
//修改数据*****************
void update()
{
	int fla,x;
	char flag;
	//FILE *write;
	char nam[10];
	system("cls");
AA:	printf("\n\t\t修改数据选择： 1.按姓名查找修改， 2.返回\n");
	printf("\n\t\t请输入你的选择： ");
	scanf("%d",&fla);
	switch(fla)
	{
	case 1:
		printf("\n\t\t请输入姓名： ");
		scanf("%s",&nam);
		x = searchname(nam);
		if(x == -1)
			printf("\n\t输入错误！ 或者 没有此信息！");
		else
		{
			updatemenu(x);
			break;
			
		}
		break;
	case 2:
		system("cls");
		mainmenu();
		break;
	default :
		{
			printf("\n\t选择错误  请重新选择.....");
			goto AA;
		}
	}
	getchar();
BB:	printf("\n\t是否重新选择？请按Y/N.... : ");
	scanf("%c",&flag);
	flag = tolower(flag);
	if(flag == 'y')
		goto AA;
	else if(flag == 'n')
	{
		savedate();
		system("cls");
		mainmenu();
	//	return ;
	}
	else
	{
		printf("\n\t输入错误 ，请重新选择.....");
		goto BB;
	}

}
//替换 数据函数********************8
void updatemenu(int x)
{
	int fla;
	char flag,num[20];
//	FILE *updatemenu;
	printf("\n\t你要修改的数据是：\n");
	showsearchdate(x);
//	updatemenu = fopen("updatemenu.txt","r");
CC:	printf("\n\t请输入要修改的选项：1.姓名  2.电话  3.地址  :");
	scanf("%d",&fla);
	switch(fla)
	{
	case 1:
		{
			printf("\n\t请输入修改姓名： ");
			scanf("%s",num);
			strcpy(tele[x].name,num);
		//	return ;
			break;
		}
	case 2:
		{
			printf("\n\t请输入修改电话： ");
			scanf("%s",num);
			strcpy(tele[x].telephone,num);
		//	return ;
			break;

		}
	case 3:
		{
			printf("\n\t请输入修改地址： ");
			scanf("%s",num);
			strcpy(tele[x].address,num);
		//	return ;
			break;
		}
	default:
		{
			printf("\n\t输入错误  请重新输入： ");
			goto CC;
			break;
		}
	
	}
	printf("\n\t是否继续修改： Y/N ？ 选择为： ");
	scanf("%c",&flag);
	flag = tolower(flag);
	if(flag == 'y')
		goto CC;
	else
	{
		return ;
		//system("cls");
	//	mainmenu();
	}

}
//数据排序*****************
void sortdate()
{

}
//按姓名查找***********
int searchname(char name[])
{
	int i;
	//printf("%d",date);
	for(i=0;i<date;i++)
	{
		if(strcmp(tele[i].name,name)==0)
			return i;
	}
		return -1;
}
//删除数据*********************
void deleteDate()
{
	//searchAlldate();
	int fla, a;
	char flag, nam[20];
	system("cls");
kk:	printf("\n\t请选择删除条件： 1.全部删除  2.按姓名删除  3.返回 \n");
	printf("\t请输入选择： ");
	scanf("%d",&fla);
	switch(fla)
	{
	case 1:
		printf("\n\n\t是否删除所有数据？   如果删除选择（Y） 否则（N）\n");
		printf("\t请输入选择： ");
		scanf("%s",&flag);
		flag = tolower(flag);
		if(flag == 'y')
		{
			date = 0;
		//	savef = 1;
			savedate();
			system("cls");//清屏
			mainmenu();
		}
		else
			goto kk;
			break;
	case 2:
		printf("\n\n\t是否按姓名删除？  如果删除选择（Y） 否则（N）\n");
		printf("\t请输入选择： ");
		//printf("%d",date);
		scanf("%s",&flag);
		flag = tolower(flag);
		if(flag == 'y')
		{
			printf("\t请输入姓名： ");
			scanf(" %s",&nam);
			a = searchname(nam);
			if(a == -1)
				printf("没有查到该数据！");
			else
				dell(a);
		}
			break;
	case 3:
		system("cls");//清屏
		mainmenu();
		break;
	default :
		printf("输入错误  请重新输入.....");
		goto kk;
	}
	
}
//删除函数
void dell(int k)
{
	int i;
	char flag;
	/*FILE *write;
	write = fopen("Date.txt","w");*/
	printf("\n\t要删除的数据为： ");
	showsearchdate(k);
	printf("\n\t确认要删除？ Y/N ?");
	scanf("%c",&flag);
	flag = tolower(flag);
	if(k<date-1)
	{
		if(flag == 'y')
		{
			printf("执行到删除函数：k=%d date=%d",k,date);
			//删除函数
			for(i=k;i<date-1;i++)
			{
				tele[i]=tele[i+1];
				
			}
			date--;
		}
	}
	else
	{
		if(flag == 'y')
		{
			date--;
		}
		
	}
		savef = 1;
		printf("执行到删除函数");
		savedate();
		system("cls");//清屏
		mainmenu();
}
//退出***********************
void exitmenu()
{
	exit(0);
}