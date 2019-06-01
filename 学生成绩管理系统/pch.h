// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#ifndef PCH_H
#define PCH_H
struct Course
{
	int year; // 该课的年份
	char A_course[64];//课程
	double dayGrade;//平时
	double examGrade;//考试
	double totalGrade;//总评
};
struct Student
{
	char id[64];//id
	char name[64];//名字
	char Class[64];//班级
	struct Course Acourse[2][3]; //代表两个学期的三门课 
	double TotalGrade[2];

	struct Student * next;
};
// TODO: 添加要在此处预编译的标头

#endif //PCH_H
