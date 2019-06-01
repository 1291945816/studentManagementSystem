// 学生成绩管理系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"pch.h"

//学生信息
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

int M_year = 0;
extern int deleteStudent(struct Student * list, char * m, int t);
extern void printStudntInfo(struct Student * list,int t,struct Student * q);
extern	void saveStudentInfo(struct Student * list,int m);
extern	void readStudentInfo(struct Student * list);
extern	void inputStudentInfo(struct Student * list);
extern	void insertList(struct Student * list, struct Student * student);
extern	int changStudentInfo(struct Student * list, char * m, int t);
extern	void classSearch(struct Student * list, char * Class);
extern	void personSearch(struct Student * list, char * person, int t);
extern	void courseSearch(struct Student * list, char * course, int year);
extern	void add(struct Student * list, char * course, struct Student * q, int year, int t, int n);
extern	void closeMC(struct Student * list);
extern	void stuGradeSortSin(struct Student *, int, int, char *, char *);
extern	void GradeSort(struct Student * list, struct Student * q, int year);
extern	void totalGradeSort(struct Student * list, int t, int year, char * Class);

extern	void changeInfo(struct Student * list, char * person, int t2);
extern	void changeCourse(struct Student * list, char * person, int t, char * course);

int main()
{
	//直接声明头结点  将原有数据进行链接
	struct Student head;
	char op = 0,op_2 = 0,op_3 = 0,op_4 = 0,op_5 = 0,op_6 = 0;
	int d1,d2,d3;


	//该文件已经接上数据
	//读取上次文件的数据
	readStudentInfo(&head);
	printf("/**\n*创作时间:2019/5/25\n*程序名：学生成绩管理系统\n*作者：1800300916 黄丕松\n*/\n");
	printf("···················(^_^)Hello,欢迎您进入桂林xx科技大学学生成绩管理系统(^_^)···················\n");
	
	
	while (op != 'Q' && op != 'q') 
	{
		
		printf("主页:\n");
		printf("\n\t\t\t\t\t\t\tMENU\t\t\t\t\t\t\n");
		printf("\t\t\t\t\t\t 【1】学生信息修改\n");
		printf("\t\t\t\t\t\t 【2】学生信息录入\n");
		printf("\t\t\t\t\t\t 【3】学生信息删除\n");
		printf("\t\t\t\t\t\t 【4】学生信息查询\n");
		printf("\t\t\t\t\t\t 【5】学生成绩排名\n\n");
		printf("【输入功能前的序号继续您的操作，退出系统则输入Q/q】");

		scanf("%c",&op);


		switch (op)
		{
			
		case '1':
		{
			system("cls");
			char op_7;

			while (true)
			{
				printf("\n学生信息修改页面:\n");
				printf("\t\t\t\t\t\t 【1】按ID\n");
				printf("\t\t\t\t\t\t 【2】按姓名\n");
				printf("【输入功能前的序号继续您的操作，退出页面则输入Q/q】\n");
				scanf("%*c%c",&op_3);
				switch (op_3)
				{
				case '1':
				{

					char ID[64];
					printf("**学生信息:");
					printStudntInfo(&head, 2, 0);
					printf("请输入ID：");
					scanf("%s", ID);
					while (1)
					{
						system("cls");
						printf("类型选择修改页面:\n");
						printf("\t\t\t\t\t\t 【1】个人信息修改\n");
						printf("\t\t\t\t\t\t 【2】课程信息修改\n");
						printf("\t\t\t\t\t\t 【3】全部信息修改\n");
						printf("【输入功能前的序号继续您的操作，退出页面则输入Q/q】\n");
						scanf("%*c%c", &op_7);
						switch (op_7)
						{
						case '3':
						{
							d2 = changStudentInfo(&head, ID, 1);
							if (d2 == 0)
							{
								printf("\n........................无学生信息可更改.......................\n");
								system("pause");
							}
							else if (d2 == -1)
							{
								printf("\n........................信息更改取消......................................\n");
								system("pause");
							}
							else if (d2 == -2)
							{
								printf("\n.............................................你输入的学生不存在........................................\n");
								system("pause");
							}
							system("pause");
							break;
						}
						case '1':
						{
							changeInfo(&head,ID,1);
							system("pause");
							break;
						}
						case '2': 
						{
							char course[64];
							printf("请您输入课程名:");
							scanf("%s",course);
							changeCourse(&head, ID, 1, course);
							system("pause");
							break;
						}
						}
						if (op_7 == 'Q' || op_7 == 'q') break;
						if (op_7 > '3' || op_7 < '1') 
						{
							printf("您输入序号不正确，请确定您的输入是否正确!\n");
							system("pause");
						}


					}
					break;
				}
				case '2':
				{
					char Name[64];
					printf("**学生信息:");
					printStudntInfo(&head, 2, 0);
					printf("请输入姓名：");
					scanf("%s", Name);
					while (1)
					{
						system("cls");
						printf("类型选择修改页面:\n");
						printf("\t\t\t\t\t\t 【1】个人信息修改\n");
						printf("\t\t\t\t\t\t 【2】课程信息修改\n");
						printf("\t\t\t\t\t\t 【3】全部信息修改\n");
						printf("【输入功能前的序号继续您的操作，退出页面则输入Q/q】\n");
						scanf("%*c%c", &op_7);
						switch (op_7)
						{
						case '3':
						{
							d2 = changStudentInfo(&head, Name, 2);
							if (d2 == 0)
							{
								printf("\n........................无学生信息可更改.......................\n");
								system("pause");
							}
							else if (d2 == -1)
							{
								printf("\n........................信息更改取消......................................\n");
								system("pause");
							}
							else if (d2 == -2)
							{
								printf("\n.............................................你输入的学生不存在........................................\n");
								system("pause");
							}
							system("pause");
							break;
						}
						case '1':
						{
							changeInfo(&head, Name, 2);
							system("pause");
							break;
						}
						case '2':
						{
							char course[64];
							printf("请您输入课程名:");
							scanf("%s", course);
							changeCourse(&head, Name, 2, course);
							system("pause");
							break;
						
						
						}

						}
						if (op_7 == 'Q' || op_7 == 'q') break;
 
						if (op_7 > '3' || op_7 < '1')
						{
							printf("您输入序号不正确，请确定您的输入是否正确!\n");
							system("pause");
						}


					}
					printf("类型修改页面退出成功...");
					system("pause");

					
				}

				}
				if (op_3 == 'Q' || op_3 == 'q')
				{
					printf("退出更改页面成功...\n");
					system("pause");
					break;

				}
				printf("\n");

			}




			break;
		}
		case '2':
		{
			inputStudentInfo(&head);
			break;


		}
		case '3':
		{

			while (true)
			{
				system("cls");
				printf("学生信息删除页面：\n");
				printf("\t\t\t\t\t\t 【1】按ID\n");
				printf("\t\t\t\t\t\t 【2】按姓名\n");
				printf("【输入功能前的序号继续您的操作，退出页面则输入Q/q】\n");
				getchar();
				op_2 = getchar();
				switch (op_2)
				{
				case '1':
				{
					char m[64];
					printf("**学生信息:");
					printStudntInfo(&head, 1, 0);
					printf("请输入ID:\n");
					scanf("%s", m);
					d1 = deleteStudent(&head, m, 1);
					if (d1 == 1)
					{
						printf("\n.....................删除成功.....................\n");
						saveStudentInfo(&head, 0);
						printf("剩下的学生信息:\n");
						printStudntInfo(&head, 1, 0);

					}
					else if (d1 == -1)
					{
						printf("\n....................你所删除的学生不存在.....\n");
					}
					else if (d1 == -2)
					{
						printf("...........................删除取消...................\n");
					}
					else
					{
						printf("..................无学生信息可删............................\n");
					}
					system("pause");
					break;



				}
				case '2':
					char m[64];
					printf("**学生信息:");
					printStudntInfo(&head, 1, 0);
					printf("请输入姓名:\n");
					scanf("%s", m);
					d1 = deleteStudent(&head, m, 2);
					if (d1 == 1)
					{
						printf("\n.......................删除成功.............................\n");
						saveStudentInfo(&head, 0);
						printf("剩下的学生信息:\n");
						printStudntInfo(&head, 1, 0);
					}
					else if (d1 == -1)
					{
						printf(".......................你所删除的学生不存在..................\n");
					}
					else if (d1 == -2)
					{
						printf("...................删除取消.....................................\n");
					}
					else
					{
						printf(".............无学生信息可删......................\n");
					}
					break;
				}
				if (op_2 == 'Q' || op_2 == 'q')
				{
					printf("学生信息页面退出成功...\n");
					system("pause");
					break;
				}



			}
			break;
		}
		case '4':
		{

			while (true)
			{
				system("cls");
				printf("学生信息查询页面：\n");
				printf("\t\t\t\t\t\t 【1】班级信息查询\n");
				printf("\t\t\t\t\t\t 【2】个人信息查询\n");
				printf("\t\t\t\t\t\t 【3】课程信息查询\n");
				printf("【输入功能前的序号继续您的操作，退出页面则输入Q/q】\n");
				scanf("%*c%c", &op_4);
				switch (op_4)
				{
				case '1':
				{
					char Class[64];
					printf("请输入您要查询的班级:");
					scanf("%s", Class);
					printf("%s班信息查询结果为:\n", Class);
					classSearch(&head, Class);
					system("pause");
					break;
				}
				case '2':
				{
					char person[64];

					while (true)
					{
						system("cls");
						printf("个人信息查询页面:\n");
						printf("\t\t\t\t\t\t 【1】按ID\n");
						printf("\t\t\t\t\t\t 【2】按姓名\n");
						printf("【输入功能前的序号(数字)继续您的操作，退出页面则输入 0 】\n");
						scanf("%d", &d3);
						switch (d3)
						{
						case 1:
							printf("请您输入ID：");
							scanf("%s", person);
							printf("%s的信息查询结果为:\n", person);
							personSearch(&head, person, 1);
							system("pause");
							break;
						case 2:
						{
							printf("请您输入姓名：");
							scanf("%s", person);
							printf("%s的信息查询结果为:\n", person);
							personSearch(&head, person, 2);
							system("pause");
							break;
						}

						}
						if (d3 == 0) break;
						if (d3 != 0 && d3 != 1 && d3 != 2)
						{
							printf("您输入的序号不存在，请确定您的输入是否正确！\n");
							system("pause");
						}
					}
					printf("个人查询信息页面退出成功...\n");
					system("pause");
					break;
				}
				case '3':
				{
					int year;
					char course[64];
					printf("请输入学期(1/2(1代表上学期/2代表下学期)):");
					scanf("%d", &year);
					printf("请输入课程名：");
					scanf("%s",course);
					courseSearch(&head, course, year);
					system("pause");
					break;
				}
				}
				if (op_4 == 'Q' || op_4 == 'q') break;
				if (op_4 > '3' || op_4 < '1')
				{
					printf("您输入序号不正确，请确定您的输入是否正确!\n");
					system("pause");
				}

			}
			printf("学生信息查询页面退出成功...\n");
			system("pause");
			break;

		}
		case '5': 
		{
			int year;
			int d4;
			char course[64], Class[64];
			while (1) 
			{
				
				system("cls");
				printf("学生成绩排名页面:\n");
				printf("\t\t\t\t\t\t 【1】单科成绩排名\n");
				printf("\t\t\t\t\t\t 【2】总成绩排名\n");
				printf("【输入功能前的序号继续您的操作，退出页面则输入Q/q】\n");
				scanf("%*c%c",&op_5);

				switch (op_5)
				{
				case '1': 
				{
					printf("请您输入学期(1/2(1代表的是上学期/2代表的是下学期)):");
					scanf("%d", &year);
					while (1)
					{
						system("cls");
						printf("类型选择页面：\n");
						printf("\t\t\t\t\t\t 【1】按班级\n");
						printf("\t\t\t\t\t\t 【2】按年级\n");
						printf("【输入功能前的序号继续您的操作，退出页面则输入Q/q】\n");
						scanf("%*c%c",&op_6);
						switch (op_6)
						{
						case '1':
						{
							printf("请输入课程名:");
							scanf("%s",course);
							printf("请输入班级:");
							scanf("%s",Class);
							stuGradeSortSin(&head, year, 1, course, Class);

							break;
						}
						case '2': 
						{

							printf("请输入课程名:");
							scanf("%s", course);
							stuGradeSortSin(&head, year, 2, course, 0);
						}


						}
						if (op_6 == 'Q' || op_6 == 'q') break;
						if (op_6 > '2' || op_6 < '1')
						{
							printf("您输入序号不正确，请确定您的输入是否正确!\n");
							system("pause");
						}
					}
					printf("类型选择页面退出成功...\n");
					system("pause");
					

					break;
				}
				case '2': 
				{
					printf("请您输入学期(1/2(1代表的是上学期/2代表的是下学期)):");
					scanf("%d", &year);
					while (1)
					{

						system("cls");
						printf("类型选择页面：\n");
						printf("\t\t\t\t\t\t 【1】按班级\n");
						printf("\t\t\t\t\t\t 【2】按年级\n");
						printf("【输入功能前的序号继续您的操作，退出页面则输入Q/q】\n");
						scanf("%*c%c", &op_6);
						switch (op_6)
						{
						case '1':
						{
							printf("请您输入班级:");
							scanf("%s",Class);
							totalGradeSort(&head, 1, year, Class);
							system("pause");
							break;
						}
						case '2':
						{
							totalGradeSort(&head, 2, year,0);
							system("pause");
							break;
						}

						}
						if (op_6 == 'Q' || op_6 == 'q') break;
						if (op_6 > '2' || op_6 < '1')
						{
							printf("您输入序号不正确，请确定您的输入是否正确!\n");
							system("pause");
						}
					}
					printf("类型选择页面退出成功...\n");
					system("pause");
					break;
				}

					
				}
				if (op_5 == 'Q' || op_5 == 'q') break;
				if (op_5 > '2' || op_5< '1')
				{
					printf("您输入序号不正确，请确定您的输入是否正确!\n");
					system("pause");
				}
			}
			printf("学生成绩排名页面退出成功...\n");
			system("pause");
			break;
		}
		}
		system("cls");
	}



	printf("系统退出成功...");
	return 0;
}


