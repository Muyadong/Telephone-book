// ��ϰ.cpp : �������̨Ӧ�ó������ڵ�
#include "stdafx.h"


void updatemenu(int);
  //���ݸ���//�ļ��Ƿ񱣴�//�ļ��Ƿ񱻷���
int date=0, savef=0, lock=0;//����ȫ�ֱ����������ϣ�
void dell(int k);
void onedate();         //��ʾ��������
int searchname(char name[]);//����������
void showsearchdate();//��ʾ��Ҫ���ҵ�����
typedef struct telephonebook
{
	char name[10];
	char telephone[20];
	char address[30];

}TELEPHONE;
TELEPHONE tele[200];
//������*****************
int main(void)
{
	loaddate();
	mainmenu();
	return 0;
}
//���˵�*****************
int a=0;
void mainmenu()
{
	system("cls");
	printf("\n\n\n\n\t\t******************************************\n");
	printf("\t\t****************�绰��ϵͳ****************\n");
	printf("\t\t**                                      **\n");
	printf("\t\t**   1.�鿴��������       2.��������    **\n");
	printf("\t\t**   3.�������           4.�޸�����    **\n");
	printf("\t\t**   5.ɾ������           6.��������    **\n");
	printf("\t\t**   7.�˳�               8.��ʾ��������**\n");
	printf("\t\t**                                      **\n");
	printf("\t\t******************************************\n");
	printf("\t\t******************************************\n");
	if(a==1)
	{
		printf("����δ֪�����������룺");
		a=0;
	}
	else
	printf("\n\t������Ҫִ�е���� ");
	
	int slt;
	//printf("\n\t������Ҫִ�е���� ");
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
				system("cls");//����
				mainmenu();
			}
	}
}
//�鿴��������*************
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
	printf("\n\t�밴���������.....");
	getchar();
	system("cls");//����
	mainmenu();
	return ;
}
//��������  ������ʾ********
void loaddate()
{
	int i;
	FILE *read;
	if((read = fopen("Date.txt","r"))==NULL)//�ж��Ƿ��ܹ���ȡ�ļ���
	{
		printf("\t\t�ļ���ȡʧ�ܣ���");
	}
	else
	{
		fscanf(read,"%d",&date);
		for(i=0;i<date;i++)
			fscanf(read," %s %s %s",&tele[i].name,&tele[i].telephone,&tele[i].address);
	}
	
	printf("\n\t�ļ�����ɹ�!\n\t\t�밴���������......");
	return ;
}
//��ʾ��������****************
void onedate()
{
	char  flag;
	int mm;
sb:	printf("\n\t������Ҫ��ʾ��Ϣ���±꣺ ");
	scanf("%d",&mm);
	printf("\n\t�������ϢΪ�� ������%s �绰��%s ��ַ��%s\n", tele[mm].name,tele[mm].telephone,tele[mm].address);
	printf("\n\t�Ƿ������ �����밴��Y�� ���򰴣�N�� ");
	printf("\n\t���������ѡ�� ");
	scanf("%s",&flag);
	flag = tolower(flag);
	if(flag == 'y')
		goto sb;
	else 	
	getchar();
	printf("\n\t�밴���������......");
	getchar();
	system("cls");
	mainmenu();
	/*int i;
	FILE *read;
	if((read = fopen("Date.txt","r"))==NULL)
	{
		printf("\n\t\t���ļ�ʧ�ܣ�\n");
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
//ר����ʾ ��������  ��ʾ����**********8
void showsearchdate(int mm)
{
	printf("\n\t��ϢΪ�� ������%s �绰��%s ��ַ��%s\n", tele[mm].name,tele[mm].telephone,tele[mm].address);
	//printf("\n\t��������������˵�....");
	//getchar();
	getchar();
	//mainmenu();
}
//��������******************
void searchDate()
{
	int fla,mm;
	char nam[20];
	system("cls");
	printf("\n\t��ѡ����Ҫ���ҵķ�ʽ�� 1.���������ң� 2.����\n");
	printf("\n\t���������ѡ�� ");
	scanf("%d",&fla);
	switch(fla)
	{
	case 1:
		printf("\n������������ ");
		scanf("%s",&nam);
		mm = searchname(nam);
		if(mm == -1)
			printf("\n\tδ�ҵ����ݣ�");
		else
			showsearchdate(mm);
		break;
	case 2:
		system("cls");
		mainmenu();
	}

}
//�������*****************8
void addDate(void)
{
	int fla;
	char flag;
	system("cls");//����
	printf("\t*************�������*************\n");
	printf("\n\t��ѡ��Ҫִ�е�����     1.���    2.����\n");
	printf("\t��ѡ�� ");
	scanf("%d",&fla);
	switch(fla)
	{
	case 1:
	tt:	printf("������������ ");
		scanf("%s",&tele[date].name);
		printf("������绰�� ");
		scanf("%s",&tele[date].telephone);
		printf("�������ַ�� ");
		scanf("%s",&tele[date].address);
		
		date++;
		savef=1;//��ʾ�����Ѿ��ı�    ��δ���棻
		getchar();
		printf("\n\t\t�Ƿ������ӣ�  �����밴Y��ֹͣ�Ͱ�N....\n\n");
		printf("\t\t��ѡ�� ");
		scanf("%s",&flag);
		flag = tolower(flag);
		if(flag == 'y')
			goto tt;
		else
			savedate();//ִ�б������ݣ�
		//getchar();
		//printf("�����������......");
		//getchar();
		
		//break;
	case 2:
		system("cls");//����
		mainmenu();
	default :
		break;
		
	}
}
//��������****************
void savedate(void)
{
	int i;
	FILE *write;
	if((write = fopen("Date.txt","w"))==NULL)
	{
		printf("���ļ�ʧ�ܣ�\n"); exit(0);
	}
	fprintf(write,"%d\n",date);
	for(i=0;i<date;i++)
		fprintf(write,"%s %s %s\n",tele[i].name,tele[i].telephone,tele[i].address);
	if(fclose(write))
	{
		printf("�ر��ļ�����\n");
		exit(0);
	}
	savef=0;
	printf("\n\n\t\t\t����ɹ���\n");
	printf("\n\t\t�밴���������....");
	getchar();
	getchar();
	return ;
}
//�޸�����*****************
void update()
{
	int fla,x;
	char flag;
	//FILE *write;
	char nam[10];
	system("cls");
AA:	printf("\n\t\t�޸�����ѡ�� 1.�����������޸ģ� 2.����\n");
	printf("\n\t\t���������ѡ�� ");
	scanf("%d",&fla);
	switch(fla)
	{
	case 1:
		printf("\n\t\t������������ ");
		scanf("%s",&nam);
		x = searchname(nam);
		if(x == -1)
			printf("\n\t������� ���� û�д���Ϣ��");
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
			printf("\n\tѡ�����  ������ѡ��.....");
			goto AA;
		}
	}
	getchar();
BB:	printf("\n\t�Ƿ�����ѡ���밴Y/N.... : ");
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
		printf("\n\t������� ��������ѡ��.....");
		goto BB;
	}

}
//�滻 ���ݺ���********************8
void updatemenu(int x)
{
	int fla;
	char flag,num[20];
//	FILE *updatemenu;
	printf("\n\t��Ҫ�޸ĵ������ǣ�\n");
	showsearchdate(x);
//	updatemenu = fopen("updatemenu.txt","r");
CC:	printf("\n\t������Ҫ�޸ĵ�ѡ�1.����  2.�绰  3.��ַ  :");
	scanf("%d",&fla);
	switch(fla)
	{
	case 1:
		{
			printf("\n\t�������޸������� ");
			scanf("%s",num);
			strcpy(tele[x].name,num);
		//	return ;
			break;
		}
	case 2:
		{
			printf("\n\t�������޸ĵ绰�� ");
			scanf("%s",num);
			strcpy(tele[x].telephone,num);
		//	return ;
			break;

		}
	case 3:
		{
			printf("\n\t�������޸ĵ�ַ�� ");
			scanf("%s",num);
			strcpy(tele[x].address,num);
		//	return ;
			break;
		}
	default:
		{
			printf("\n\t�������  ���������룺 ");
			goto CC;
			break;
		}
	
	}
	printf("\n\t�Ƿ�����޸ģ� Y/N �� ѡ��Ϊ�� ");
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
//��������*****************
void sortdate()
{

}
//����������***********
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
//ɾ������*********************
void deleteDate()
{
	//searchAlldate();
	int fla, a;
	char flag, nam[20];
	system("cls");
kk:	printf("\n\t��ѡ��ɾ�������� 1.ȫ��ɾ��  2.������ɾ��  3.���� \n");
	printf("\t������ѡ�� ");
	scanf("%d",&fla);
	switch(fla)
	{
	case 1:
		printf("\n\n\t�Ƿ�ɾ���������ݣ�   ���ɾ��ѡ��Y�� ����N��\n");
		printf("\t������ѡ�� ");
		scanf("%s",&flag);
		flag = tolower(flag);
		if(flag == 'y')
		{
			date = 0;
		//	savef = 1;
			savedate();
			system("cls");//����
			mainmenu();
		}
		else
			goto kk;
			break;
	case 2:
		printf("\n\n\t�Ƿ�����ɾ����  ���ɾ��ѡ��Y�� ����N��\n");
		printf("\t������ѡ�� ");
		//printf("%d",date);
		scanf("%s",&flag);
		flag = tolower(flag);
		if(flag == 'y')
		{
			printf("\t������������ ");
			scanf(" %s",&nam);
			a = searchname(nam);
			if(a == -1)
				printf("û�в鵽�����ݣ�");
			else
				dell(a);
		}
			break;
	case 3:
		system("cls");//����
		mainmenu();
		break;
	default :
		printf("�������  ����������.....");
		goto kk;
	}
	
}
//ɾ������
void dell(int k)
{
	int i;
	char flag;
	/*FILE *write;
	write = fopen("Date.txt","w");*/
	printf("\n\tҪɾ��������Ϊ�� ");
	showsearchdate(k);
	printf("\n\tȷ��Ҫɾ���� Y/N ?");
	scanf("%c",&flag);
	flag = tolower(flag);
	if(k<date-1)
	{
		if(flag == 'y')
		{
			printf("ִ�е�ɾ��������k=%d date=%d",k,date);
			//ɾ������
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
		printf("ִ�е�ɾ������");
		savedate();
		system("cls");//����
		mainmenu();
}
//�˳�***********************
void exitmenu()
{
	exit(0);
}