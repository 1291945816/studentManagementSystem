#include"pch.h"
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
int deleteStudent(struct Student * list, char * m, int t);
void printStudntInfo(struct Student * list, int t, struct Student * q);
void saveStudentInfo(struct Student * list, int m);
void readStudentInfo(struct Student * list);
void inputStudentInfo(struct Student * list);
void insertList(struct Student * list, struct Student * student);
int changStudentInfo(struct Student * list, char * m, int t);
void classSearch(struct Student * list, char * Class);
void personSearch(struct Student * list, char * person, int t);
void courseSearch(struct Student * list, char * course, int year);
void add(struct Student * list, char * course, struct Student * q, int year, int t, int n);
void closeMC(struct Student * list);
void stuGradeSortSin(struct Student *, int, int, char *, char *);
void GradeSort(struct Student * list, struct Student * q, int year);
void totalGradeSort(struct Student * list, int t, int year, char * Class);

void changeInfo(struct Student * list, char * person, int t2);
void changeCourse(struct Student * list, char * person, int t, char * course);
//输入信息
/*
*参数 1  表示要接的链表头
*/
void inputStudentInfo(struct Student * list)
{
	int t = 1, i, j;
	struct Student * p, *tail;
	//学生信息的录入
	p = list->next;
	//输入学生的信息并且进行插入
	//开始输入学生的信息
	if (p != NULL)
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		tail = p;

	}
	else
	{
		tail = list;
	}

	while (t)
	{
		system("cls");
		printf("\n学生信息输入页面:\n");
		//个人信息的录入
		p = (struct Student *)malloc(sizeof(struct Student));
		p->TotalGrade[0] = 0.0;
		p->TotalGrade[1] = 0.0;
		printf("请输入学生的班级：");
		scanf("%s", p->Class);
		printf("请您输入学生的学号:");
		scanf("%s", p->id);
		printf("请您输入学生的姓名:");
		scanf("%s", p->name);
		printf("请您输入 2018 上下两个学期的成绩：\n");
		for (i = 0; i < 2; i++)
		{
			printf("\n2018#0%d\n", i + 1);
			for (j = 0; j < 3; j++)
			{
				p->Acourse[i][j].year = i + 1;
				printf("请输入课程名：");
				scanf("%s", p->Acourse[i][j].A_course);
				printf("请输入平时成绩:");
				scanf("%lf", &(p->Acourse[i][j].dayGrade));
				printf("请输入考试成绩:");
				scanf("%lf", &(p->Acourse[i][j].examGrade));

				p->Acourse[i][j].totalGrade = (p->Acourse[i][j].dayGrade * 0.2) + (p->Acourse[i][j].examGrade * 0.8);
				printf("\n");
				p->TotalGrade[i] += p->Acourse[i][j].totalGrade;
			}
		}

		//插入学生的信息至链表的尾部
		tail->next = p;
		tail = p;


		//保存到上次的尾部
		saveStudentInfo(p, 1);
		tail->next = NULL;


		//信息的输出 确保用户确认

		system("cls");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~信息保存成功(^_^)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("您录入的数据为：\n");
		printStudntInfo(list, 3, p);

		printf("\n【是否继续输入？？？(0/1)】：");
		scanf("%d", &t);

	}
	printf("学生信息输入页面退出成功...\n");
	system("pause");
}

//插入学生的信息到链表中
/*
*参数 1  表示要操作的链表
*参数 2 表示要插入链表的信息
*/
void insertList(struct Student * list, struct Student * student)
{
	struct Student * p = list->next;
	if (list->next == NULL)
	{
		list->next = student;
		return;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = student;
		student->next = NULL;
	}
	//保存学生的信息
	saveStudentInfo(list, 0);

}

//删除学生信息
/*
*参数1 表示要操作的链表
*参数2 表示 学生的ID或者姓名
*参数3 表示哪种类型的删除
*/
int deleteStudent(struct Student * list, char * m, int t)
{
	struct Student * p = list->next, *q = list;
	int k = 1;

	if (list->next == NULL) return 0;
	switch (t)
	{
		//按id删除
	case 1:
		while (p)
		{
			if (strcmp(p->id, m) == 0)
			{
				printf("该名学生的信息为:\n");
				printf("班级\t\t学号\t\t名字\t\t2018上总成绩\t\t2018下总成绩\t\t\n");
				printf("%s\t%s\t%s\t\t%.2lf\t\t%.2lf\n", p->Class, p->id, p->name, p->TotalGrade[0], p->TotalGrade[1]);
				printf("是否确定?(按0取消，按其他数字继续...)：");
				scanf("%d", &k);
				if (k == 0) return -2;


				q->next = p->next;
				free(p);
				break;

			}
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			return -1;
		}
		break;
	case 2:
		//按名字删除
		while (p)
		{
			if (strcmp(p->name, m) == 0)
			{
				printf("该名学生的信息为:\n");
				printf("班级\t学号\t名字\t2018上总成绩\t2018下总成绩\t\n");
				printf("%s\t%s\t%s\t%.2lf\t%.2lf\n", p->Class, p->id, p->name, p->TotalGrade[0], p->TotalGrade[1]);
				printf("是否确定?(按0取消，按其他数字继续...)：");
				scanf("%d", &k);
				if (k == 0) return -2;
				q->next = p->next;
				free(p);
				break;

			}
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			return -1;
		}

		break;
	}
	return 1;
}

//更改学生信息
/*
*参数1  表示要操作的链表
*参数2 表示学生的ID或者姓名
*参数3  表示哪种类型
*/
int changStudentInfo(struct Student * list, char * m, int t)
{
	int i, j, d;
	struct Student * p = list->next;
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		if (t == 1)
		{
			while (p)
			{
				if (strcmp(p->id, m) == 0)
				{
					printStudntInfo(list, 3, p);
					printf("是否更改信息（此更改将会重新输入全部输入数据）【输入数字0取消，其他数字继续】：");
					scanf("%d", &d);
					//表示取消
					if (d == 0) return -1;


					p->TotalGrade[0] = 0.0;
					p->TotalGrade[1] = 0.0;
					printf("请输入学生的班级：");
					scanf("%s", p->Class);
					printf("请您输入学生的学号:");
					scanf("%s", p->id);
					printf("请您输入学生的姓名:");
					scanf("%s", p->name);
					printf("请您输入 2018 上下两个学期的成绩：\n");
					for (i = 0; i < 2; i++)
					{
						printf("\n2018#0%d\n", i + 1);
						for (j = 0; j < 3; j++)
						{
							p->Acourse[i][j].year = i + 1;
							printf("请输入课程名：");
							scanf("%s", p->Acourse[i][j].A_course);
							printf("请输入平时成绩:");
							scanf("%lf", &(p->Acourse[i][j].dayGrade));
							printf("请输入考试成绩:");
							scanf("%lf", &(p->Acourse[i][j].examGrade));

							p->Acourse[i][j].totalGrade = (p->Acourse[i][j].dayGrade * 0.2) + (p->Acourse[i][j].examGrade * 0.8);
							printf("\n");
							p->TotalGrade[i] += p->Acourse[i][j].totalGrade;
						}
					}
					printf("更改后的学生信息为:\n");
					printStudntInfo(list, 3, p);
					saveStudentInfo(list, 0);

					break;

				}
				p = p->next;
			}
			if (p == NULL) return -2;
		}
		else if (t == 2)
		{
			while (p)
			{
				if (strcmp(p->name, m) == 0)
				{
					printStudntInfo(list, 3, p);
					printf("是否更改信息（此更改将会重新输入全部输入数据）【输入数字0取消，其他数字继续】：");
					scanf("%d", &d);
					//表示取消
					if (d == 0) return -1;


					p->TotalGrade[0] = 0.0;
					p->TotalGrade[1] = 0.0;
					printf("请输入学生的班级：");
					scanf("%s", p->Class);
					printf("请您输入学生的学号:");
					scanf("%s", p->id);
					printf("请您输入学生的姓名:");
					scanf("%s", p->name);
					printf("请您输入 2018 上下两个学期的成绩：\n");
					for (i = 0; i < 2; i++)
					{
						printf("\n2018#0%d\n", i + 1);
						for (j = 0; j < 3; j++)
						{
							p->Acourse[i][j].year = i + 1;
							printf("请输入课程名：");
							scanf("%s", p->Acourse[i][j].A_course);
							printf("请输入平时成绩:");
							scanf("%lf", &(p->Acourse[i][j].dayGrade));
							printf("请输入考试成绩:");
							scanf("%lf", &(p->Acourse[i][j].examGrade));

							p->Acourse[i][j].totalGrade = (p->Acourse[i][j].dayGrade * 0.2) + (p->Acourse[i][j].examGrade * 0.8);
							printf("\n");
							p->TotalGrade[i] += p->Acourse[i][j].totalGrade;
						}
					}
					printf("更改后的学生信息为:\n");
					printStudntInfo(list, 3, p);
					saveStudentInfo(list, 0);
					break;

				}
				p = p->next;
			}
			if (p == NULL) return -2;

		}


	}


	return 1;




}

//保存学生信息 录入到系统中的
/*
*参数1  表示要操作的链表
*参数2  表示存数据的模式
*/
void saveStudentInfo(struct Student * list, int m)
{
	FILE * fp = NULL;

	if (m == 0)
	{
		struct Student * p = list->next;

		if ((fp = fopen("StudentInfomation.txt", "wb+")) == NULL)
		{
			printf("Error: Can not open the file !");
			exit(0);
		}
		while (p != NULL)
		{
			fwrite(p, sizeof(struct Student), 1, fp);
			p = p->next;
		}
		fclose(fp);
	}
	else
	{
		struct Student * p = list;
		if ((fp = fopen("StudentInfomation.txt", "ab")) == NULL)
		{
			printf("Error: Can not open the file !");
			exit(0);
		}
		if (p != NULL)
		{
			fwrite(p, sizeof(struct Student), 1, fp);
		}
		fclose(fp);
	}

}

//读取学生的信息
/*
参数1 表示读取到这个链表
*/
void readStudentInfo(struct Student * list)
{
	struct Student * p = list, *q = NULL;
	FILE * fp;
	if ((fp = fopen("StudentInfomation.txt", "r")) == NULL)
	{
		return;
	}
	q = (struct Student *) malloc(sizeof(struct Student));
	while ((fread(q, sizeof(struct Student), 1, fp)) != 0)
	{
		p->next = q;
		p = q;
		q = (struct Student *) malloc(sizeof(struct Student));
	}

	p->next = NULL;

	fclose(fp);



}

//扩展输出函数，打印学生信息
/*
*参数1 表示要操作的链表
*参数2 表示要输出数据的类型
*参数3（可选） 表示单独输出这个q指向的数据
*/
void printStudntInfo(struct Student * list, int t, struct Student * q)
{
	int i, j;
	struct Student * p = list->next;
	if (p != NULL)
	{
		if (t == 1)
		{

			printf("\n班级\t学号\t名字\t2018上总成绩\t2018下总成绩\t\n");
			while (p)
			{

				printf("%s\t%s\t%s\t%.2lf\t\t%.2lf\n", p->Class, p->id, p->name, p->TotalGrade[0], p->TotalGrade[1]);
				p = p->next;

			}
		}
		else if (t == 2)
		{
			while (p)
			{
				printf("\n.......................................................................................\n");
				printf("\n班级\t\t学生学号\t\t学生姓名\n");
				printf("%s\t%s\t%s\n", p->Class, p->id, p->name);
				printf("学期\t课程名\t平时成绩\t考试成绩\t总评成绩");
				printf("\n........................................................................................\n");
				for (i = 0; i < 2; i++)
				{

					for (j = 0; j < 3; j++)
					{
						printf("2018#0%d\t", i + 1);
						printf("%s\t%.2lf\t%.2lf\t%.2lf\n", p->Acourse[i][j].A_course, p->Acourse[i][j].dayGrade, p->Acourse[i][j].examGrade, p->Acourse[i][j].totalGrade);
					}


				}
				printf("2018年度上总成绩为:%.2lf\t2018年度下总成绩为:%.2lf\n", p->TotalGrade[0], p->TotalGrade[1]);
				printf(".....................................................................................\n");
				p = p->next;
			}


		}
		else if (t == 3)
		{

			printf("\n班级\t\t学生学号\t\t学生姓名\n");
			printf("%s\t%s\t%s\n", q->Class, q->id, q->name);
			printf("学期\t课程名\t平时成绩\t考试成绩\t总评成绩");
			printf("\n.....................................................................................\n");
			for (i = 0; i < 2; i++)
			{

				for (j = 0; j < 3; j++)
				{
					printf("2018#0%d\t", i + 1);
					printf("%s\t%.2lf\t%.2lf\t%.2lf\n", q->Acourse[i][j].A_course, q->Acourse[i][j].dayGrade, q->Acourse[i][j].examGrade, q->Acourse[i][j].totalGrade);
				}

			}
			printf("2018年度上总成绩为:%.2lf\t2018年度下总成绩为:%.2lf\n", q->TotalGrade[0], q->TotalGrade[1]);

		}
	}
}

//班级学生信息查询
/*
*参数1  表示操作的链表
*参数2  表示匹配的班级（或查询的班级）
*/
void classSearch(struct Student * list, char * Class)
{
	struct Student * p = list->next;
	int k = 0;
	int i;
	int numbers = 0, T_num1 = 0, T_num2 = 0, T_num3 = 0, T_num4 = 0;
	if (p == NULL)
	{
		printf("学生信息库中无学生信息可查询，请确定学生信息是否存在?\n");
		return;
	}
	//遍历全部
	while (p)
	{

		if (strcmp(p->Class, Class) == 0)
		{
			printStudntInfo(list, 3, p);
			if (p->TotalGrade[0] >= 250) T_num1++;
			if (p->TotalGrade[1] >= 250) T_num2++;
			for (i = 0; i < 3; i++)
			{
				if (p->Acourse[0][i].totalGrade < 60)
				{
					T_num3++;
					break;
				}
			}
			for (i = 0; i < 3; i++)
			{
				if (p->Acourse[1][i].totalGrade < 60)
				{
					T_num4++;
					break;
				}
			}
			numbers++;
			k = 1;

		}
		p = p->next;
	}
	//检验班级是否存在
	if (k == 0)
	{
		printf("您输入的班级不存在，请确保您的输入是否正确！\n");
		return;

	}
	printf("\n...................................................................\n");
	printf("班级总人数为：%d\n", numbers);
	printf("2018年度上学期总评优秀（>=250）的人数: %d\n", T_num1);
	printf("2018年度下学期总评优秀（>=250）的人数: %d\n", T_num2);
	printf("2018年度上学期挂科(单科总评<60)的人数: %d\n", T_num3);
	printf("2018年度下学期挂科(单科总评<60)的人数: %d\n", T_num4);

}
//个人信息查询
/*
*参数1 表示操作的链表
*参数2 表示学生的姓名或学生的ID
*参数3 表示查询类型
*/
void personSearch(struct Student * list, char * person, int t)
{
	struct Student * p = list->next;
	int k = 0;
	if (p == NULL)
	{
		printf("学生信息库中无学生信息可查询，请确定学生信息是否存在?\n");
		return;
	}
	if (t == 1)
	{

		while (p)
		{
			//学号是唯一的
			if (strcmp(p->id, person) == 0)
			{
				printStudntInfo(list, 3, p);
				k = 1;
				break;

			}
			p = p->next;
		}
	}
	else
	{
		while (p)
		{
			//姓名不是唯一的
			if (strcmp(p->name, person) == 0)
			{
				printf("%s的详细信息为:\n", person);
				printStudntInfo(list, 3, p);
				k = 1;

			}
			p = p->next;
		}
	}
	if (k == 0)
	{
		printf("您输入的学生不存在，请重新查看一下您的输入是否正确！\n");
	}
}

//课程信息查询
/*
*参数1  表示要操作的链表
*参数2  表示查询的课程
*参数3  表示查询的学期
*/
void courseSearch(struct Student * list, char * course, int year)
{
	struct Student * p = list->next;
	//由于分数是位于 0-100内

	double max = -1, min = 120.0, sum = 0, len = 0, gK = 0;
	int k = 0;
	int i, j;

	if (p == NULL)
	{
		printf("学生信息库中无学生信息可查询，请确定学生信息是否存在?\n");
		return;
	}
	//检验course是否存在

	if (year == 1)
	{
		printf("2018年度上学期：\n");
		printf("班级\t学生学号\t学生姓名\t课程名称\t平时成绩\t考试成绩\t总评成绩\n");
		printf(".............................................................................\n");
		while (p)
		{
			for (j = 0; j < 3; j++)
			{
				if (strcmp(course, p->Acourse[0][j].A_course) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", p->Class, p->id, p->name, p->Acourse[0][j].A_course, p->Acourse[0][j].dayGrade, p->Acourse[0][j].examGrade, p->Acourse[0][j].totalGrade);
					if (p->Acourse[0][j].totalGrade > max) max = p->Acourse[0][j].totalGrade;
					if (p->Acourse[0][j].totalGrade < min) min = p->Acourse[0][j].totalGrade;
					if (p->Acourse[0][j].totalGrade < 60) gK++;
					sum += p->Acourse[0][j].totalGrade;
					len++;
					k = 1;
					break;

				}
			}
			p = p->next;

		}
		if (k == 0)
		{
			printf("错误,无该课程的信息！\n");
			return;
		}
		printf(".......................................................................\n");
		printf("最高分为:%.2lf\t最低分为:%.2lf\n", max, min);
		printf("人数为:%.0lf\t平均分为:%.2lf\n", len, sum / len);
		printf("挂科(成绩< 60 )人数为:%.0lf\n", gK);
	}
	else if (year == 2)
	{
		printf("2018年度下学期：\n");
		printf("班级\t学生学号\t学生姓名\t课程名称\t\t平时成绩\t考试成绩\t总评成绩\n");
		printf(".............................................................................\n");
		while (p)
		{
			for (j = 0; j < 3; j++)
			{
				if (strcmp(course, p->Acourse[1][j].A_course) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", p->Class, p->id, p->name, p->Acourse[1][j].A_course, p->Acourse[1][j].dayGrade, p->Acourse[1][j].examGrade, p->Acourse[1][j].totalGrade);
					if (p->Acourse[1][j].totalGrade > max) max = p->Acourse[1][j].totalGrade;
					if (p->Acourse[1][j].totalGrade < min) min = p->Acourse[1][j].totalGrade;
					if (p->Acourse[1][j].totalGrade < 60) gK++;
					sum += p->Acourse[1][j].totalGrade;
					len++;
					k = 1;
					break;


				}


			}
			p = p->next;
		}
		if (k == 0)
		{
			printf("错误,无该课程的信息！\n");
			return;
		}
		printf(".......................................................................\n");
		printf("最高分为:%.2lf\t最低分为:%.2lf\n", max, min);
		printf("人数为:%.0lf\t平均分为:%.2lf\n", len, sum / len);
		printf("挂科(成绩< 60 )人数为:%.0lf\n", gK);

	}
	else
	{
		printf("抱歉，其他年份的选择查询暂未开放！\n");
	}

}

//单科成绩排名
/*
参数1  表示操作的链表
参数2 表示学期
参数3 表示排序的类型
参数4 表示排序的课程
参数5  表示排序的班级
*/
void stuGradeSortSin(struct Student * list, int year, int t, char * course, char * Class)
{
	struct Student * p = list->next;
	struct Student * r = NULL;
	struct Student * q = NULL, head1;
	int i, j, k = 0;
	head1.next = NULL;
	if (!p)
	{
		printf("学生信息库中无学生信息可操作！");
		return;
	}
	if (year > 2 || year < 1)
	{
		printf("抱歉，其它年份的操作暂未开放，敬请期待！\n");
		return;
	}
	//班级的排序
	if (t == 1)
	{
		q = (struct Student *)malloc(sizeof(struct Student));

		while (p)
		{
			//负责复制同一班级的学生信息
			if (strcmp(Class, p->Class) == 0)
			{
				strcpy(q->Class, p->Class);
				strcpy(q->id, p->id);
				strcpy(q->name, p->name);
				q->TotalGrade[0] = p->TotalGrade[0];
				q->TotalGrade[1] = p->TotalGrade[1];
				for (i = 0; i < 2; i++)
				{
					for (j = 0; j < 3; j++)
					{
						strcpy(q->Acourse[i][j].A_course, p->Acourse[i][j].A_course);
						q->Acourse[i][j].dayGrade = p->Acourse[i][j].dayGrade;
						q->Acourse[i][j].examGrade = p->Acourse[i][j].examGrade;
						q->Acourse[i][j].totalGrade = p->Acourse[i][j].totalGrade;
					}
				}
				q->next = NULL;
				add(&head1, course, q, 0, 1, 0);
				q = (struct Student *)malloc(sizeof(struct Student));
			}
			p = p->next;
		}
		p = head1.next;
		if (head1.next == NULL)
		{
			printf("抱歉，无该班级的排名信息!\n");
			system("pause");
			return;

		}
		i = 1;
		if (year == 1)
		{
			printf("2018年上学期:\n");
		}
		else
		{
			printf("2018年下学期:\n");
		}
		printf("班级\t学生学号\t学生姓名\t课程名称\t\t平时成绩\t考试成绩\t总评成绩\t序号\n");
		printf(".............................................................................\n");
		while (p)
		{
			for (j = 0; j < 3; j++)
			{

				if (strcmp(p->Acourse[year - 1][j].A_course, course) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\t%d\n", p->Class, p->id, p->name, p->Acourse[year - 1][j].A_course, p->Acourse[year - 1][j].dayGrade, p->Acourse[year - 1][j].examGrade, p->Acourse[year - 1][j].totalGrade, i++);
					break;
				}
			}
			p = p->next;
		}
		system("pause");
		closeMC(&head1);
	}
	else
	{


		int n;
		q = (struct Student *)malloc(sizeof(struct Student));
		while (p)
		{
			for (i = 0; i < 3; i++)
			{
				//将课程信息相同的同学转移到另一个链表，并排好xu

				if (strcmp(course, p->Acourse[year - 1][i].A_course) == 0)
				{
					n = i;
					strcpy(q->Class, p->Class);
					strcpy(q->id, p->id);
					strcpy(q->name, p->name);
					q->TotalGrade[0] = p->TotalGrade[0];
					q->TotalGrade[1] = p->TotalGrade[1];
					for (i = 0; i < 2; i++)
					{
						for (j = 0; j < 3; j++)
						{
							strcpy(q->Acourse[i][j].A_course, p->Acourse[i][j].A_course);
							q->Acourse[i][j].dayGrade = p->Acourse[i][j].dayGrade;
							q->Acourse[i][j].examGrade = p->Acourse[i][j].examGrade;
							q->Acourse[i][j].totalGrade = p->Acourse[i][j].totalGrade;
						}
					}
					q->next = NULL;
					add(&head1, course, q, year - 1, 2, n);
					q = (struct Student *)malloc(sizeof(struct Student));
					break;
				}
			}
			p = p->next;
		}
		p = head1.next;
		if (head1.next == NULL)
		{
			printf("抱歉，无排名信息!\n");
			system("pause");
			return;

		}
		i = 1;
		if (year == 1)
		{

			printf("2018年上学期:\n");
		}
		else
		{
			printf("2018年下学期:\n");
		}
		printf("班级\t学生学号\t学生姓名\t课程名称\t\t平时成绩\t考试成绩\t总评成绩\t序号\n");
		printf(".............................................................................\n");
		while (p)
		{
			for (j = 0; j < 3; j++)
			{

				if (strcmp(p->Acourse[year - 1][j].A_course, course) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\t%d\n", p->Class, p->id, p->name, p->Acourse[year - 1][j].A_course, p->Acourse[year - 1][j].dayGrade, p->Acourse[year - 1][j].examGrade, p->Acourse[year - 1][j].totalGrade, i++);
					break;
				}
			}
			p = p->next;
		}
		system("pause");
		closeMC(&head1);
	}
}

//重建链表  并按从大到小排序
/*
参数1 表示操作的链表
参数2 表示排序的课程
参数3 表示添加的学生
参数4  表示学期
参数5  表示类型
参数6  表示课程的位置

*/
void add(struct Student * list, char * course, struct Student * q, int year, int t, int n)
{
	struct Student * p = list->next, *r = list;
	int  j, i, k = 0;
	if (t == 1)
	{
		if (!p)
		{
			for (j = 0; j < 3; j++)
			{
				if (strcmp(q->Acourse[year][j].A_course, course) == 0)
				{
					list->next = q;
					break;
				}
			}
			if (j == 3) return;
		}
		while (p)
		{

			//这个文字上就是  比较两个课程相同的成绩大小
			for (j = 0; j < 3; j++)
			{
				if (strcmp(p->Acourse[year][j].A_course, course) == 0)
				{
					for (i = 0; i < 3; i++)
					{
						if (strcmp(q->Acourse[year][i].A_course, course) == 0)
						{
							//标签 用来标志 p与q的课程一样  但是 成绩低于p的
							k = 1;
							if (q->Acourse[year][i].totalGrade > p->Acourse[year][j].totalGrade)
							{
								k = 0;
								goto lable1;
							}
							break;

						}
					}
					//能进入到这条语句  则说明 p已经找到要求的课程名  能走到这一句  则说明成绩已经比较完（或课程不相同）  继续退出
					break;
				}

			}

			r = p;
			p = p->next;


		}
	lable1:
		r->next = q;
		q->next = p;

		if (k == 1)
		{
			r->next = q;

		}
	}
	else                                    //这块是按年级的单科排名
	{
		if (!p)
		{
			list->next = q;
		}
		while (p)
		{
			for (j = 0; j < 3; j++)
			{
				if (strcmp(p->Acourse[year][j].A_course, course) == 0)
				{
					k = 1;
					if (q->Acourse[year][n].totalGrade > p->Acourse[year][j].totalGrade)
					{
						r->next = q;
						q->next = p;
						k = 0;
						break;

					}

				}

			}
			if (k == 0) return;

			r = p;
			p = p->next;

		}
		if (k == 1) r->next = q;
	}

}
//释放节点空间
void closeMC(struct Student * list)
{
	struct Student * p = list->next, *r = NULL;
	while (p)
	{
		r = p->next;
		free(p);
		p = r;


	}
}

//显示总成绩排名
/*
参数1  表示要操作的链表
参数2  表示类型
参数3  表示学期
参数4（可选） 表示 班级

*/
void totalGradeSort(struct Student * list, int t, int year, char * Class)
{
	struct Student * p = list->next, *q = NULL;
	struct Student head1;
	int i, j;

	head1.next = NULL;
	if (list->next == 0)
	{
		printf("学生信息库中暂无学生信息可操作！\n");
		return;
	}
	if (year > 2 || year < 1)
	{
		printf("抱歉，其他学期的操作暂无开放，敬请期待！\n");
		return;
	}

	if (t == 2)
	{
		q = (struct Student *)malloc(sizeof(struct Student));
		while (p)
		{
			strcpy(q->Class, p->Class);
			strcpy(q->id, p->id);
			strcpy(q->name, p->name);
			q->TotalGrade[0] = p->TotalGrade[0];
			q->TotalGrade[1] = p->TotalGrade[1];
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 3; j++)
				{
					strcpy(q->Acourse[i][j].A_course, p->Acourse[i][j].A_course);
					q->Acourse[i][j].dayGrade = p->Acourse[i][j].dayGrade;
					q->Acourse[i][j].examGrade = p->Acourse[i][j].examGrade;
					q->Acourse[i][j].totalGrade = p->Acourse[i][j].totalGrade;
				}
			}
			q->next = NULL;
			GradeSort(&head1, q, year);
			q = (struct Student *)malloc(sizeof(struct Student));

			p = p->next;
		}

	}
	else if (t == 1)
	{
		q = (struct Student *)malloc(sizeof(struct Student));
		while (p)
		{
			//班级总成绩排名
			if (strcmp(Class, p->Class) == 0)
			{
				strcpy(q->Class, p->Class);
				strcpy(q->id, p->id);
				strcpy(q->name, p->name);
				q->TotalGrade[0] = p->TotalGrade[0];
				q->TotalGrade[1] = p->TotalGrade[1];
				for (i = 0; i < 2; i++)
				{
					for (j = 0; j < 3; j++)
					{
						strcpy(q->Acourse[i][j].A_course, p->Acourse[i][j].A_course);
						q->Acourse[i][j].dayGrade = p->Acourse[i][j].dayGrade;
						q->Acourse[i][j].examGrade = p->Acourse[i][j].examGrade;
						q->Acourse[i][j].totalGrade = p->Acourse[i][j].totalGrade;
					}
				}
				q->next = NULL;
				GradeSort(&head1, q, year);
				q = (struct Student *)malloc(sizeof(struct Student));
			}

			p = p->next;
		}



	}
	p = head1.next;
	i = 1;
	if (p == NULL)
	{
		printf("暂无排名信息!\n");
		return;
	}
	if (year == 1)
	{
		printf("2018年上学期总成绩排名:\n");
	}
	else
	{
		printf("2018年下学期总成绩排名:\n");
	}
	printf("班级\t学生学号\t学生姓名\t总成绩\t序号\n");
	while (p)
	{
		printf("%s\t%s\t%s\t%.2lf\t%d\n", p->Class, p->id, p->name, p->TotalGrade[year - 1], i++);
		p = p->next;
	}
	closeMC(&head1);
}

//总成绩排序（核心排序）
/*
参数1 操作的链表
参数2  将要添加进链表的学生信息
参数3  表示学期
*/
void GradeSort(struct Student * list, struct Student * q, int year)
{
	struct Student * p = list->next, *r = list;
	if (!p)
	{
		list->next = q;
		return;
	}
	while (p)
	{
		if (p->TotalGrade[year - 1] < q->TotalGrade[year - 1])
		{
			r->next = q;
			q->next = p;
			return;
		}
		r = p;
		p = p->next;
	}
	r->next = q;
}

//更改学生的个人信息
/*
参数1  表示操作的链表
参数2  表示学生的姓名或者ID
参数3  表示类型
*/
void changeInfo(struct Student * list, char * person, int t2)
{
	int t;
	int i, j;
	struct Student * p = list->next;
	if (!p)
	{
		printf("学生信息库中无学生信息可操作!\n");
		return;
	}
	while (p)
	{
		//判断是按ID还是按名字
		if (t2 == 1)
		{

			if (strcmp(p->id, person) == 0)
			{
				printf("您要修改的信息为:\n");
				printf("班级\t学生姓名\t学生ID\n");
				printf("%s\t%s\t%s\n", p->Class, p->name, p->id);
				printf("输入0取消修改,其他数字继续:\n");
				scanf("%d", &t);
				if (t == 0)
				{
					printf("更改取消...");
					return;
				}
				printf("请输入您的ID：");
				scanf("%s", p->id);
				printf("请输入您的班级:");
				scanf("%s", p->Class);
				printf("请输入您的姓名:");
				scanf("%s", p->name);
				break;
			}
		}
		else
		{
			if (strcmp(p->name, person) == 0)
			{
				printf("您要修改的信息为:\n");
				printf("班级\t学生姓名\t学生ID\n");
				printf("%s\t%s\t%s\n", p->Class, p->name, p->id);
				printf("输入0取消修改,其他数字继续:\n");
				scanf("%d", &t);
				if (t == 0)
				{
					printf("更改取消...");
					return;
				}
				printf("请输入您的ID：");
				scanf("%s", p->id);
				printf("请输入您的班级:");
				scanf("%s", p->Class);
				printf("请输入您的姓名:");
				scanf("%s", p->name);
				break;
			}
		}
		p = p->next;
	}

	if (p == NULL)
	{
		printf("您输入的学生不存在，请检查您的输入...");
		return;
	}
	saveStudentInfo(list, 0);
	printf("(^^)信息保存成功！\n");
	printf("您修改的信息为:\n");
	printf("班级\t学生姓名\t学生ID\n");
	printf("%s\t%s\t%s\n", p->Class, p->name, p->id);
}
//更改学生的课程信息
/*
参数1  表示操作的链表
参数2 表示学生的姓名和id
参数3 表示更改格式
参数4 表示更改的课程

*/
void changeCourse(struct Student * list, char * person, int t, char * course)
{
	int i, k;
	int year;
	struct Student * p = list->next;
	if (!p)
	{
		printf("学生信息库中无学生信息可操作!\n");
		return;
	}
	printf("请您输入学期(1为上学期,2为下学期):");
	scanf("%d", &year);

	while (p)
	{
		if (t == 1)
		{
			if (strcmp(p->id, person) == 0)
			{
				for (i = 0; i < 3; i++)
				{
					if (strcmp(p->Acourse[year - 1][i].A_course, course) == 0)
					{
						printf("您要修改的信息为:\n");
						printf("学期\t课程名\t平时成绩\t考试成绩\t总评成绩\n");
						printf("%d\t%s\t%.2lf\t%.2lf\t%.2lf\n", p->Acourse[year - 1][i].year, p->Acourse[year - 1][i].A_course, p->Acourse[year - 1][i].dayGrade, p->Acourse[year - 1][i].examGrade, p->Acourse[year - 1][i].totalGrade);
						printf("输入0取消修改,其他数字继续:\n");
						scanf("%d", &k);
						if (k == 0)
						{
							printf("取消修改成功...");
							return;
						}
						printf("请输入您的课程名:");
						scanf("%s", p->Acourse[year - 1][i].A_course);
						printf("请输入您的平时成绩:");
						scanf("%lf", &p->Acourse[year - 1][i].dayGrade);
						printf("请输入您的考试成绩:");
						scanf("%lf", &p->Acourse[year - 1][i].examGrade);
						p->TotalGrade[year - 1] -= p->Acourse[year - 1][i].totalGrade;
						p->Acourse[year - 1][i].totalGrade = (p->Acourse[year - 1][i].dayGrade * 0.2) + (p->Acourse[year - 1][i].examGrade * 0.8);
						p->TotalGrade[year - 1] += p->Acourse[year - 1][i].totalGrade;

						goto lable1;
					}
				}
			}
		}
		else
		{
			if (strcmp(p->name, person) == 0)
			{
				for (i = 0; i < 3; i++)
				{
					if (strcmp(p->Acourse[year - 1][i].A_course, course) == 0)
					{
						printf("您要修改的信息为:\n");
						printf("学期\t课程名\t平时成绩\t考试成绩\t总评成绩\n");
						printf("%d\t%s\t%.2lf\t%.2lf\t%.2lf\n", p->Acourse[year - 1][i].year, p->Acourse[year - 1][i].A_course, p->Acourse[year - 1][i].dayGrade, p->Acourse[year - 1][i].examGrade, p->Acourse[year - 1][i].totalGrade);
						printf("输入0取消修改,其他数字继续:\n");
						scanf("%d", &k);
						if (k == 0)
						{
							printf("取消修改成功...");
							return;
						}
						printf("请输入您的课程名:");
						scanf("%s", p->Acourse[year - 1][i].A_course);
						printf("请输入您的平时成绩:");
						scanf("%lf", &p->Acourse[year - 1][i].dayGrade);
						printf("请输入您的考试成绩:");
						scanf("%lf", &p->Acourse[year - 1][i].examGrade);
						p->TotalGrade[year - 1] -= p->Acourse[year - 1][i].totalGrade;
						p->Acourse[year - 1][i].totalGrade = (p->Acourse[year - 1][i].dayGrade * 0.2) + (p->Acourse[year - 1][i].examGrade * 0.8);
						p->TotalGrade[year - 1] += p->Acourse[year - 1][i].totalGrade;


						goto lable1;
					}
				}
			}

		}
		p = p->next;
	}
lable1:
	if (p == NULL)
	{
		printf("您输入的学生不存在，请检查您的输入...\n");
		return;
	}
	saveStudentInfo(list, 0);
	printf("(^^)信息保存成功！\n");
	printf("您修改的信息为:\n");
	printf("学期\t课程名\t平时成绩\t考试成绩\t总评成绩\n");
	printf("%d\t%s\t%.2lf\t%.2lf\t%.2lf\n", p->Acourse[year - 1][i].year, p->Acourse[year - 1][i].A_course, p->Acourse[year - 1][i].dayGrade, p->Acourse[year - 1][i].examGrade, p->Acourse[year - 1][i].totalGrade);
}


