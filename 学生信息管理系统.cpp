#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<Windows.h>
#include<limits>
#include<fstream>
#undef max
#pragma warning (disable:4996)
using namespace std;
class abstract//������
{
public:
	virtual void print() = 0;
};
class time :virtual abstract
{
public:
	time(int a, int b, int c);
	~time();
	int Getyear();
	int Getmonth();
	int Getdate();
	char* Getsemester();
	void Setyear(int a);
	void Setmonth(int a);
	void Setdate(int a);
	void reflect();
	virtual void print();
protected:
	int year;
	int month;
	int date;
	char semester[9];
};
time::time(int a, int b, int c) : year(a), month(b), date(c)
{
	reflect();
}
time::~time()
{
}
int time::Getyear()
{
	return year;
}
int time::Getmonth()
{
	return month;
}
int time::Getdate()
{
	return date;
}
char* time::Getsemester()
{
	return semester;
}
void time::Setyear(int a)
{
	year = a;
}
void time::Setmonth(int a)
{
	month = a;
	reflect();
}
void time::Setdate(int a)
{
	date = a;
}
void time::reflect()//���������Զ���Ӧѧ��
{
	if (month >= 3 && month <= 6)
		strcpy(semester, "����ѧ��");
	else if (month >= 7 && month <= 8)
		strcpy(semester, "�ļ�ѧ��");
	else if ((month >= 9 && month <= 12) || (month == 1))
		strcpy(semester, "�＾ѧ��");
	else
		strcpy(semester, "����ѧ��");
}
void time::print()
{
	cout << year << "-" << month << "-" << date << " (" << semester << ")  ";
}
class student :virtual public abstract
{
public:
	student(char*a, char* b, char* c, char* d);
	~student();
	char* Getstudentname();
	char* Getstudentnumber();
	char* Getstudentclass();
	char* Getstudentgrade();
	void Setstudentname(char* a);
	void Setstudentnumber(char* a);
	void Setstudentclass(char* a);
	void Setstudentgrade(char* a);
	void print();
protected:
	char* studentname;
	char* studentnumber;
	char* studentclass;
	char* studentgrade;
};
student::student(char*a, char*b, char*c, char* d)
{
	studentname = new char[strlen(a) + 1];
	strcpy(studentname, a);
	studentnumber = new char[strlen(b) + 1];
	strcpy(studentnumber, b);
	studentclass = new char[strlen(c) + 1];
	strcpy(studentclass, c);
	studentgrade = new char[strlen(d) + 1];
	strcpy(studentgrade, d);
}
student::~student()
{
	delete[] studentname;
	delete[] studentnumber;
	delete[] studentclass;
	delete[] studentgrade;
}
char* student::Getstudentname()
{
	return studentname;
}
char* student::Getstudentnumber()
{
	return studentnumber;
}
char* student::Getstudentclass()
{
	return studentclass;
}
char* student::Getstudentgrade()
{
	return studentgrade;
}
void student::Setstudentname(char* a)
{
	delete[] studentname;
	studentname = new char[strlen(a) + 1];
	strcpy(studentname, a);
}
void student::Setstudentnumber(char* a)
{
	delete[] studentnumber;
	studentnumber = new char[strlen(a) + 1];
	strcpy(studentnumber, a);
}
void student::Setstudentclass(char* a)
{
	delete[] studentclass;
	studentclass = new char[strlen(a) + 1];
	strcpy(studentclass, a);
}
void student::Setstudentgrade(char* a)
{
	delete[] studentgrade;
	studentgrade = new char[strlen(a) + 1];
	strcpy(studentgrade, a);
}
void student::print()
{
	cout << studentname << "  ";
	cout << studentnumber << "  ";
	cout << studentclass << "  ";
	cout << studentgrade << "  ";
}
class record_grade :virtual public abstract, public student
{
public:
	record_grade(char* a, char* b, char* c,char*d, char*a1, int b1, int c1);
	~record_grade();
	char* Getclassname();
	int Getclassmark();
	int Getmark();
	char* Getgrade();
	double Getpoint();
	void Setclassname(char* a);
	void Setclassmark(int a);
	void Setmark(int a);
	void reflect();
	virtual void print();
	double operator+(double a);
	int operator+(int a);
protected:
	char* classname;
	int classmark;
	int mark;
	char grade[3];
	double point;
};
record_grade::record_grade(char* a, char* b, char* c, char*d, char*a1, int b1, int c1) :student(a, b, c, d), classmark(b1), mark(c1)
{
	classname = new char[strlen(a1) + 1];
	strcpy(classname, a1);
	reflect();
}
record_grade::~record_grade()
{
	delete[] classname;
}
char* record_grade::Getclassname()
{
	return classname;
}
int record_grade::Getclassmark()
{
	return classmark;
}
int record_grade::Getmark()
{
	return mark;
}
char* record_grade::Getgrade()
{
	return grade;
}
double record_grade::Getpoint()
{
	return point;
}
void record_grade::Setclassname(char* a)
{
	delete[] classname;
	classname = new char[strlen(a) + 1];
	strcpy(classname, a);
}
void record_grade::Setclassmark(int a)
{
	classmark = a;
}
void record_grade::Setmark(int a)
{
	mark = a;
	reflect();
}
void record_grade::reflect()//���ݰٷ��Ƴɼ���Ӧ����
{
	if (mark >= 99) { point = 4.0; strcpy(grade, "A+"); }
	else if (mark >= 95) { point = 4.0; strcpy(grade, "A "); }
	else if (mark >= 90) { point = 4.0; strcpy(grade, "A-"); }
	else if (mark >= 85) { point = 3.6; strcpy(grade, "B+"); }
	else if (mark >= 80) { point = 3.3; strcpy(grade, "B "); }
	else if (mark >= 77) { point = 3.0; strcpy(grade, "B-"); }
	else if (mark >= 73) { point = 2.6; strcpy(grade, "C+"); }
	else if (mark >= 70) { point = 2.3; strcpy(grade, "C "); }
	else if (mark >= 67) { point = 2.0; strcpy(grade, "C-"); }
	else if (mark >= 63) { point = 1.6; strcpy(grade, "D+"); }
	else if (mark >= 60) { point = 1.3; strcpy(grade, "D "); }
	else { point = 0; strcpy(grade, "F "); }
}
void record_grade::print()
{
	student::print();
	cout << classname << "(" << classmark << "ѧ��)  ";
	cout << "�ٷ��Ƴɼ�:" << mark << "  ";
	cout << "�ȼ��Ƴɼ�:" << grade << "  ";
	cout << setiosflags(ios_base::fixed) << setprecision(1) << point << resetiosflags(ios_base::fixed);
	cout << endl;
}
double record_grade::operator+(double a)//����+�������ڼ���ƽ��ѧ�ּ�
{
	return this->classmark*this->point + a;
}
int record_grade::operator+(int a)
{
	return this->classmark + a;
}
class record_absent :virtual public abstract, public time, public student
{
public:
	record_absent(int a, int b, int c, char* a1, char* b1, char* c1, char*d1, int a2, char* c2,char* d2);
	~record_absent();
	int Getday();
	int Getclassnumber();
	char* Getclassname();
	char* Getform();
	void reflect_day();
	void Setclassnumber(int a);
	void Setclassname(char* a);
	void Setform(char* a);
	virtual void print();
protected:
	int day;
	int classnumber;
	char* classname;
	char form[5];
};
record_absent::record_absent(int a, int b, int c, char* a1, char* b1, char* c1, char*d1, int a2, char* c2, char* d2) :time(a, b, c), student(a1, b1, c1, d1), classnumber(a2)
{
	classname = new char[strlen(c2) + 1];
	strcpy(classname, c2);
	strcpy(form, d2);
	reflect_day();
}
record_absent::~record_absent()
{
	delete[] classname;
}
int record_absent::Getday()
{
	return day;
}
int record_absent::Getclassnumber()
{
	return classnumber;
}
char* record_absent::Getform()
{
	return form;
}
char* record_absent::Getclassname()
{
	return classname;
}
void record_absent::reflect_day()//���������Զ���Ӧ����
{
	int i, count = 0, t = 28;
	for (i = 1900; i < year; i++)
	{
		if (!(i % 4) && ((i % 100) || !(i % 400)))
			count = count + 366;
		else
			count = count + 365;
	}
	if (!(year % 4) && ((year % 100) || !(year % 400)))
		t = 29;
	for (i = 1; i < month; i++)
	{
		switch (i)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:count = count + 31; break;
		case 4:case 6:case 9:case 11:count = count + 30; break;
		case 2:count = count + t; break;
		}
	}
	count = count + date;
	day = count % 7;
	if (day == 0)
		day = 7;
}
void record_absent::Setclassnumber(int a)
{
	classnumber = a;
}
void record_absent::Setform(char* a)
{
	strcpy(form, a);
}
void record_absent::Setclassname(char* a)
{
	delete[] classname;
	classname = new char[strlen(a) + 1];
	strcpy(classname, a);
}
void record_absent::print()
{
	time::print();
	student::print();
	cout << classname;
	cout << " (" << day << "-" << classnumber << ")  ";
	cout << form;
	cout << endl;
}
//���ֽڵ�ֱ𴢴���������
struct grade
{
	record_grade data;
	grade* next;
};
struct absent
{
	record_absent data;
	absent* next;
};
grade* Grade;
absent* Absent;
//�����������
template <typename T>
void list_insert(T*&head, T*&p)
{
	if (head == NULL)
	{
		head = p;
		p->next = NULL;
	}
	else
	{
		T* helper = head;
		while (helper->next != NULL)
			helper = helper->next;
		helper->next = p;
		p->next = NULL;
	}
}
template <typename T>
void list_delete(T*&head, T*&p)
{
	if (p == head)
	{
		head = p->next;
		delete p;
	}
	else
	{
		T* helper = head;
		while (helper->next != p)
			helper = helper->next;
		helper->next = helper->next->next;
		delete p;
	}
}
//�ж������Ƿ�Ϸ�
bool judge_date(int a, int b, int c)
{
	int t = 28;
	bool mark = 0;
	if (a < 1900 || b <= 0 || c <= 0)
		mark = 1;
	else
	{
		if (!(a % 4) && ((a % 100) || !(a % 400)))
			t = 29;
		switch (b)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:if (c <= 0 || c > 31) mark = 1; break;
		case 4:case 6:case 9:case 11:if (c <= 0 || c > 30) mark = 1; break;
		case 2:if (c <= 0 || c > t) mark = 1; break;
		default:mark = 1;
		}
	}
	if (mark)cout << "�������ڲ��Ϸ�������������(�� �� ��)" << endl;
	return mark;
}
void input_date(int &a, int &b, int &c)
{
	cout << "(�� �� ��)" << endl;
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	do
	{
		cin >> a;
		if (cin.fail())
		{
			a = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), ' ');
			while (cin.peek() == ' ')
				getchar();
		}
		cin >> b;
		if (cin.fail())
		{
			b = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), ' ');
			while (cin.peek() == ' ')
				getchar();
		}
		cin >> c;
		if (cin.fail())
		{
			c = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (judge_date(a, b, c));
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
}
//����ѧ�Ų��ж��Ƿ�Ϻ�ѧ����ʽ
void input_studentnumber(char* a)
{
	int p = 0;
	char target[21];
	cout << "������ѧ��" << endl;
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	cin.getline(target, 21, '\n');
	while (true)
	{
		bool numbersign = false;
		while (target[p] != '\0')
		{
			if (target[p] > '9' || target[p] < '0')
			{
				numbersign = true;
				break;
			}
			p++;
		}
		if (numbersign == true)
		{
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			cout << "��������ȷ��ѧ��(������)" << endl;
			cin.getline(target, 21, '\n');
			p = 0;
		}
		if (numbersign == false)
			break;
	}
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	strcpy(a, target);
}
//���ݲ�ͬ�ؼ��ֵ���������
template<typename T>
T* list_search_studentname(T*start, bool mark)
{
	static char target[51];
	if (mark);
	else
	{
		cout << "������ѧ������" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	T* helper = start;
	while (helper != NULL && strcmp(helper->data.Getstudentname(), target) != 0)
		helper = helper->next;
	return helper;
}
template<typename T>
T* list_search_studentnumber(T*start, bool mark)
{
	static char target[21];
	if (mark);
	else
		input_studentnumber(target);
	T* helper = start;
	while (helper != NULL && strcmp(helper->data.Getstudentnumber(), target) != 0)
		helper = helper->next;
	return helper;
}
template<typename T>
T* list_search_studentclass(T*start, bool mark)
{
	static char target[21];
	if (mark);
	else
	{
		cout << "������ѧ���༶" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 21, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	T* helper = start;
	while (helper != NULL && strcmp(helper->data.Getstudentclass(), target) != 0)
		helper = helper->next;
	return helper;
}
template<typename T>
T* list_search_studentgrade(T*start, bool mark)
{
	static char target[21];
	if (mark);
	else
	{
		cout << "������ѧ���꼶" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 21, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	T* helper = start;
	while (helper != NULL && strcmp(helper->data.Getstudentgrade(), target) != 0)
		helper = helper->next;
	return helper;
}
template<typename T>
T* list_search_classname(T*start, bool mark)
{
	static char target[51];
	if (mark);
	else
	{
		cout << "������γ���" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	T* helper = start;
	while (helper != NULL && strcmp(helper->data.Getclassname(), target))
		helper = helper->next;
	return helper;
}
absent* list_search_absentform(absent* start, bool mark)
{
	static char target[5];
	if (mark);
	else
	{
		cout << "����������" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 5, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		while (strcmp(target, "����") && strcmp(target, "�ٵ�") && strcmp(target, "����") && strcmp(target, "���") && strcmp(target, "ȱ��"))
		{
			cout << "��������ȷ������(����/�ٵ�/����/���/ȱ��)" << endl;
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			cin.getline(target, 5, '\n');
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
	}
	absent* helper = start;
	while (helper != NULL && strcmp(helper->data.Getform(), target))
		helper = helper->next;
	return helper;
}
absent* list_search_absenttime(absent* start, bool mark)
{
	static int a, b, c;
	if (mark);
	else
	{
		cout << "����������" << endl;
		input_date(a, b, c);
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != a || helper->data.Getmonth() != b || helper->data.Getdate() != c))
		helper = helper->next;
	return helper;
}
absent* list_search_absentsemester(absent* start, bool mark)
{
	static char target[9];
	if (mark);
	else
	{
		cout << "������ѧ��" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 9, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		while (strcmp(target, "����ѧ��") && strcmp(target, "�ļ�ѧ��") && strcmp(target, "�＾ѧ��") && strcmp(target, "����ѧ��"))
		{
			cout << "��������ȷ��ѧ��(����ѧ��/�ļ�ѧ��/�＾ѧ��/����ѧ��)" << endl;
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			cin.getline(target, 9, '\n');
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
	}
	absent* helper = start;
	while (helper != NULL && strcmp(helper->data.Getsemester(), target))
		helper = helper->next;
	return helper;
}
absent * list_search_student_withtime1(absent*start, bool mark)
{
	static int year;
	static char target[51];
	if (mark);
	else
	{
		input_studentnumber(target);
		cout << "���������" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		while (cin.fail() || year < 1900)
		{
			cout << "��������ȷ�����" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> year;
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || strcmp(helper->data.Getstudentnumber(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_student_withtime2(absent*start, bool mark)
{
	static int year, month;
	static char target[51];
	if (mark);
	else
	{
		input_studentnumber(target);
		cout << "������ʱ��" << endl;
		cout << "(�� ��)" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		if (cin.fail() || year < 1900)
		{
			year = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), ' ');
			while (cin.peek() == ' ')
				getchar();
		}
		cin >> month;
		if (cin.fail() || month < 0 || month>12)
		{
			month = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		if (year == -1)
		{
			cout << "��������ȷ�����" << endl;
			cin >> year;
			while (cin.fail() || year < 0)
			{
				cout << "��������ȷ���" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> year;
			}
		}
		if (month == -1)
		{
			cout << "��������ȷ���·�" << endl;
			cin >> month;
			while (cin.fail() || month < 0 || month>100)
			{
				cout << "��������ȷ���·�" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> month;
			}
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || helper->data.Getmonth() != month || strcmp(helper->data.Getstudentnumber(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_student_withtime3(absent*start, bool mark)
{
	static int year, month, day;
	static char target[51];
	if (mark);
	else
	{
		input_studentnumber(target);
		cout << "����������" << endl;
		input_date(year, month, day);
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || helper->data.Getmonth() != month || helper->data.Getdate() != day || strcmp(helper->data.Getstudentnumber(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_student_withtime4(absent*start, bool mark)
{
	static int year;
	static char semester[9], target[51];
	if (mark);
	else
	{
		input_studentnumber(target);
		cout << "���������" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		while (cin.fail() || year < 1900)
		{
			cout << "��������ȷ�����" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> year;
		}
		cout << "������ѧ��" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(semester, 9, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		while (strcmp(semester, "����ѧ��") && strcmp(semester, "�ļ�ѧ��") && strcmp(semester, "�＾ѧ��") && strcmp(semester, "����ѧ��"))
		{
			cout << "��������ȷ��ѧ��(����ѧ��/�ļ�ѧ��/�＾ѧ��/����ѧ��)" << endl;
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			cin.getline(semester, 9, '\n');
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || strcmp(helper->data.Getstudentnumber(), target) || strcmp(helper->data.Getsemester(), semester)))
		helper = helper->next;
	return helper;
}
absent * list_search_class_withtime1(absent*start, bool mark)
{
	static int year;
	static char target[51];
	if (mark);
	else
	{
		cout << "������γ���" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cout << "���������" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		while (cin.fail() || year < 1900)
		{
			cout << "��������ȷ�����" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> year;
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || strcmp(helper->data.Getclassname(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_class_withtime2(absent*start, bool mark)
{
	static int year, month;
	static char target[51];
	if (mark);
	else
	{
		cout << "������γ���" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cout << "������ʱ��" << endl;
		cout << "(�� ��)" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		if (cin.fail() || year < 1900)
		{
			year = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), ' ');
			while (cin.peek() == ' ')
				getchar();
		}
		cin >> month;
		if (cin.fail() || month < 0 || month>12)
		{
			month = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		if (year == -1)
		{
			cout << "��������ȷ�����" << endl;
			cin >> year;
			while (cin.fail() || year < 0)
			{
				cout << "��������ȷ���" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> year;
			}
		}
		if (month == -1)
		{
			cout << "��������ȷ���·�" << endl;
			cin >> month;
			while (cin.fail() || month < 0 || month>100)
			{
				cout << "��������ȷ���·�" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> month;
			}
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || helper->data.Getmonth() != month || strcmp(helper->data.Getclassname(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_class_withtime3(absent*start, bool mark)
{
	static int year, month, day;
	static char target[51];
	if (mark);
	else
	{
		cout << "������γ���" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cout << "����������" << endl;
		input_date(year, month, day);
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || helper->data.Getmonth() != month || helper->data.Getdate() != day || strcmp(helper->data.Getclassname(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_class_withtime4(absent*start, bool mark)
{
	static int year;
	static char semester[9], target[51];
	if (mark);
	else
	{
		cout << "������γ���" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cout << "���������" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		while (cin.fail() || year < 1900)
		{
			cout << "��������ȷ�����" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> year;
		}
		cout << "������ѧ��" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(semester, 9, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		while (strcmp(semester, "����ѧ��") && strcmp(semester, "�ļ�ѧ��") && strcmp(semester, "�＾ѧ��") && strcmp(semester, "����ѧ��"))
		{
			cout << "��������ȷ��ѧ��(����ѧ��/�ļ�ѧ��/�＾ѧ��/����ѧ��)" << endl;
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			cin.getline(semester, 9, '\n');
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || strcmp(helper->data.Getclassname(), target) || strcmp(helper->data.Getsemester(), semester)))
		helper = helper->next;
	return helper;
}
//����ָ��������ڵ��ú���
template <typename P>
P*(*f[5])(P*, bool) = { list_search_classname,list_search_studentclass,list_search_studentgrade,list_search_studentname,list_search_studentnumber };
absent*(*h1[4])(absent*, bool) = { list_search_student_withtime1,list_search_student_withtime2, list_search_student_withtime3, list_search_student_withtime4 };
absent*(*h2[4])(absent*, bool) = { list_search_class_withtime1,list_search_class_withtime2, list_search_class_withtime3, list_search_class_withtime4 };
absent*(*g[3])(absent*, bool) = { list_search_absentform,list_search_absentsemester,list_search_absenttime };
template <typename P, typename T>
void search_makesure(P*(*f)(P*, bool), T* &helper)
{
	char k;
	bool a = false, b = false, mark = false;
	while (true)
	{
		helper = f(helper, mark);
		while (true)
		{
			system("cls");
			if (helper == NULL)
			{
				cout << "����ؼ�¼!" << endl;
				a = true; b = true;
				Sleep(700);
			}
			else
			{
				helper->data.print();
				cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
				cout << "     [1] ����������¼          [0]������һ����¼" << endl;
				while (cin.peek() == '\n')
					getchar();
				k = getchar();
				while (cin.rdbuf()->in_avail())
					getchar();
				cin.clear();
				switch (k)
				{
				case '1':a = true; b = true; break;
				case '0':a = true; mark = true; helper = helper->next; break;
				default:
					cout << "��ѡ���ܲ����ڣ�����������" << endl;
					Sleep(700); break;
				}
				if (a == true)
					break;
			}
			if (a == true)
				break;
		}
		if (b == true)
			break;
	}
}
grade* searchmenu_grade()
{
	char a;
	bool sign = false;
	grade* helper = Grade;
	while (true)
	{
		system("cls");
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "��            ���ҳɼ���¼            ��" << endl;
		cout << "��         ����ѡ��ؼ��֡���         ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��            [1]ѧ������             ��" << endl;
		cout << "��            [2]ѧ��                 ��" << endl;
		cout << "��            [3]ѧ���༶             ��" << endl;
		cout << "��            [4]ѧ���꼶             ��" << endl;
		cout << "��            [5]�γ���               ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':search_makesure(f<grade>[3], helper); sign = true; break;
		case '2':search_makesure(f<grade>[4], helper); sign = true; break;
		case '3':search_makesure(f<grade>[1], helper); sign = true; break;
		case '4':search_makesure(f<grade>[2], helper); sign = true; break;
		case '5':search_makesure(f<grade>[0], helper); sign = true; break;
		default:
			cout << "��ѡ���ܲ����ڣ�����������" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
	return helper;
}
absent* searchmenu_absent()
{
	char a;
	bool sign = false;
	absent* helper = Absent;
	while (true)
	{
		system("cls");
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "��            ���ҿ��ڼ�¼            ��" << endl;
		cout << "��         ����ѡ��ؼ��֡���         ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��            [1]ѧ������             ��" << endl;
		cout << "��            [2]ѧ��                 ��" << endl;
		cout << "��            [3]ѧ���༶             ��" << endl;
		cout << "��            [4]ѧ���꼶             ��" << endl;
		cout << "��            [5]�γ���               ��" << endl;
		cout << "��            [6]ʱ��                 ��" << endl;
		cout << "��            [7]ѧ��                 ��" << endl;
		cout << "��            [8]����                 ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':search_makesure(f<absent>[3], helper); sign = true; break;
		case '2':search_makesure(f<absent>[4], helper); sign = true; break;
		case '3':search_makesure(f<absent>[1], helper); sign = true; break;
		case '4':search_makesure(f<absent>[2], helper); sign = true; break;
		case '5':search_makesure(f<absent>[0], helper); sign = true; break;
		case '6':search_makesure(g[2], helper); sign = true; break;
		case '7':search_makesure(g[1], helper); sign = true; break;
		case '8':search_makesure(g[0], helper); sign = true; break;
		default:
			cout << "��ѡ���ܲ����ڣ�����������" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
	return helper;
}
//�ж����������Ƿ����������ݳ�ͻ
bool judge_studentnumber(char *a, char *b, grade* temp1, absent* temp2)
{
	bool mark1 = false;
	grade* helper11 = Grade;
	while (helper11 != NULL)
	{
		if (helper11 == temp1);
		else
		{
			if (!strcmp(helper11->data.Getstudentnumber(), b))
				if (strcmp(helper11->data.Getstudentname(), a))
				{
					cout << "��Ϣ�����м�¼��ͻ(��ͬ��������ѧ��)" << endl;
					cout << "������Ч����������" << endl;
					Sleep(1000);
					mark1 = true;
					break;
				}
		}
		helper11 = helper11->next;
	}
	if (!mark1)
	{
		absent* helper22 = Absent;
		while (helper22 != NULL)
		{
			if (helper22 == temp2);
			else
			{
				if (!strcmp(helper22->data.Getstudentnumber(), b))
					if (strcmp(helper22->data.Getstudentname(), a))
					{
						cout << "��Ϣ�����м�¼��ͻ(��ͬ��������ѧ��)" << endl;
						cout << "������Ч����������" << endl;
						Sleep(500);
						mark1 = true;
						break;
					}
			}
			helper22 = helper22->next;
		}
	}
	return mark1;
}
bool input_grade(char* a, char* b, char* c, char* d, char* a1, int &b1, int &c1)
{
	int p = 0;
	cout << "������ɼ���¼" << endl;
	cout << "(���� ѧ�� �༶ �꼶 �γ��� ѧ���� �ٷ��Ƴɼ�)" << endl;
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	cin.getline(a, 51, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(b, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(c, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(d, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(a1, 51, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin >> b1;
	if (cin.fail() || b1 < 0)
	{
		b1 = -1;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), ' ');
		while (cin.peek() == ' ')
			getchar();
	}
	cin >> c1;
	if (cin.fail() || c1 < 0 || c1>100)
	{
		c1 = -1;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	while (true)
	{
		bool numbersign = false;
		while (b[p] != '\0')
		{
			if (b[p] > '9' || b[p] < '0')
			{
				numbersign = true;
				break;
			}
			p++;
		}
		if (numbersign == true)
		{
			cout << "��������ȷ��ѧ��(������)" << endl;
			cin.getline(b, 21, '\n');
			p = 0;
		}
		if (numbersign == false)
			break;
	}
	if (b1 == -1)
	{
		cout << "��������ȷѧ����" << endl;
		cin >> b1;
		while (cin.fail() || b1 < 0)
		{
			cout << "��������ȷѧ����" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> b1;
		}
	}
	if (c1 == -1)
	{
		cout << "��������ȷ�İٷ��Ƴɼ�" << endl;
		cin >> c1;
		while (cin.fail() || c1 < 0 || c1>100)
		{
			cout << "��������ȷ�İٷ��Ƴɼ�" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> c1;
		}
	}
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	return judge_studentnumber(a, b, NULL, NULL);
}
bool input_absent(int &a, int &b, int &c, char*a1, char*b1, char*c1, char*d1, int &a2, char*c2, char*d2)
{
	int p = 0;
	cout << "�����뿼������" << endl;
	input_date(a, b, c);
	cout << "�����뿼�ڼ�¼" << endl;
	cout << "(���� ѧ�� �༶ �꼶 �ڴ� �γ��� ����)" << endl;
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	while (cin.peek() == ' ')
		getchar();
	cin.getline(a1, 51, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(b1, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(c1, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(d1, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin >> a2;
	if (cin.fail() || a2 < 0 || a2 > 5)
	{
		a2 = -1;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), ' ');
		while (cin.peek() == ' ')
			getchar();
	}
	while (cin.peek() == ' ')
		getchar();
	cin.getline(c2, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(d2, 5, '\n');
	while (true)
	{
		bool numbersign = false;
		while (b1[p] != '\0')
		{
			if (b1[p] > '9' || b1[p] < '0')
			{
				numbersign = true;
				break;
			}
			p++;
		}
		if (numbersign == true)
		{
			cout << "��������ȷ��ѧ��(������)" << endl;
			cin.getline(b1, 21, '\n');
			p = 0;
		}
		if (numbersign == false)
			break;
	}
	if (a2 == -1)
	{
		cout << "��������ȷ�ڴ�(1-5)" << endl;
		cin >> a2;
		while (cin.fail() || a2 < 0 || a2 > 5)
		{
			cout << "��������ȷ�ڴ�(1-5)" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> a2;
		}
	}
	while (strcmp(d2, "����") && strcmp(d2, "�ٵ�") && strcmp(d2, "����") && strcmp(d2, "���") && strcmp(d2, "ȱ��"))
	{
		cout << "��������ȷ������(����/�ٵ�/����/���/ȱ��)" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(d2, 5, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	return judge_studentnumber(a1, b1, NULL, NULL);
}
void establish_grade()
{
	char a[51], b[21], c[21], d[21], a1[51];
	int b1, c1;
	char k;
	bool sign = false, sign1 = false, sign2 = false;
	while (true)
	{
		system("cls");
		cout << "��������������������������������������������������������¼��ɼ���������������������������������������������������������" << endl;
		if (input_grade(a, b, c, d, a1, b1, c1))
			break;
		while (true)
		{
			sign = sign1 = false;
			system("cls");
			cout << "��������������������������������������������������������¼��ɹ���������������������������������������������������������" << endl;
			cout << a << "  " << b << "  " << c << "  " << d << "  " << a1 << "  " << b1 << "  " << c1 << endl;
			cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "        [1] ȷ��      [0]����¼��     [w]����¼�벢����" << endl;
			while (cin.peek() == '\n')
				getchar();
			k = getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			switch (k)
			{
			case '1':sign = true; sign1 = true; sign2 = true; break;
			case '0':sign = true; break;
			case 'w':sign = true; sign1 = true; break;
			default:
				cout << "��ѡ���ܲ����ڣ�����������" << endl;
				Sleep(700); break;
			}
			if (sign == true)
				break;
		}
		if (sign1 == true)
			break;
	}
	if (sign2)
	{
		grade* assistant_establish_grade = new grade{ record_grade(a,b,c,d,a1,b1,c1),NULL };
		list_insert(Grade, assistant_establish_grade);
	}
}
void establish_absent()
{
	int a, b, c;
	char a1[51], b1[21], c1[21], d1[21];
	int a2;
	char c2[51], d2[5];
	char k;
	bool sign = false, sign1 = false, sign2 = false;
	while (true)
	{
		sign = sign1 = false;
		system("cls");
		cout << "��������������������������������������������������������¼�뿼�ک�������������������������������������������������������" << endl;
		if (input_absent(a, b, c, a1, b1, c1, d1, a2, c2, d2))
			break;
		while (true)
		{
			system("cls");
			cout << "��������������������������������������������������������¼��ɹ���������������������������������������������������������" << endl;
			cout << a << "-" << b << "-" << c << "  " << a1 << "  " << b1 << "  " << c1 << "  " << d1 << "  " << "(��" << a2 << "��)  " << c2 << "  " << d2 << endl;
			cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "        [1] ȷ��      [0]����¼��     [w]����¼�벢����" << endl;
			while (cin.peek() == '\n')
				getchar();
			k = getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			switch (k)
			{
			case '1':sign = true; sign1 = true; sign2 = true; break;
			case '0':sign = true; break;
			case 'w':sign = true; sign1 = true; break;
			default:
				cout << "��ѡ���ܲ����ڣ�����������" << endl;
				Sleep(700); break;
			}
			if (sign == true)
				break;
		}
		if (sign1 == true)
			break;
	}
	if (sign2)
	{
		absent* assistant_establish_absent = new absent{ record_absent(a,b,c,a1,b1,c1,d1,a2,c2,d2),NULL };
		list_insert(Absent, assistant_establish_absent);
	}
}
void rewrite_grade()
{
	bool sign = false, sign1 = false, sign3 = true;
	grade* helper = Grade;
	char a[51], b[21], c[21], d[21], a1[51];
	int b1, c1;
	if (helper != NULL)
	{
		system("cls");
		cout << "���������������������������������������������������������޸ĳɼ���������������������������������������������������������" << endl;
		cout << "����ҳɼ���¼" << endl;
		helper = searchmenu_grade();
		if (helper != NULL)
		{
			strcpy(a, helper->data.Getstudentname());
			strcpy(b, helper->data.Getstudentnumber());
			strcpy(c, helper->data.Getstudentclass());
			strcpy(d, helper->data.Getstudentgrade());
			strcpy(a1, helper->data.Getclassname());
			b1 = helper->data.Getclassmark();
			c1 = helper->data.Getmark();
			system("cls");
			char p;
			while (true)
			{
				while (true)
				{
					system("cls");
					cout << "����������������������������������������������������������������������������" << endl;
					cout << "��         ��ѡ��Ҫ�޸ĵ���Ŀ         ��" << endl;
					cout << "��                                    ��" << endl;
					cout << "��            [1]ѧ������             ��" << endl;
					cout << "��            [2]ѧ��                 ��" << endl;
					cout << "��            [3]ѧ���༶             ��" << endl;
					cout << "��            [4]ѧ���꼶             ��" << endl;
					cout << "��            [5]�γ���               ��" << endl;
					cout << "��            [6]ѧ��                 ��" << endl;
					cout << "��            [7]�ɼ�                 ��" << endl;
					cout << "��            [8]ȫ����������         ��" << endl;
					cout << "��            [0]ȡ���޸�             ��" << endl;
					cout << "��                                    ��" << endl;
					cout << "����������������������������������������������������������������������������" << endl;
					while (cin.peek() == '\n')
						getchar();
					p = getchar();
					while (cin.rdbuf()->in_avail())
						getchar();
					cin.clear();
					switch (p)
					{
					case '1':
						cout << "������ѧ������" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(a, 51, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '2':
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						input_studentnumber(b);
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '3':
						cout << "������ѧ���༶" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(c, 21, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '4':
						cout << "������ѧ���꼶" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(d, 21, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '5':
						cout << "������γ���" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(a1, 51, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '6':
						cout << "������ѧ����" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin >> b1;
						while (cin.fail() || b1 < 0)
						{
							cout << "��������ȷ��ѧ����" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cin >> b1;
						}
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '7':
						cout << "������ٷ��Ƴɼ�" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin >> c1;
						while (cin.fail() || c1 < 0 || c1 > 100)
						{
							cout << "��������ȷ�İٷ��Ƴɼ�" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cin >> c1;
						}
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '8':
						input_grade(a, b, c, d, a1, b1, c1);
						sign = true; break;
					case '0':sign = sign1 = true; sign3 = false; break;
					default:
						cout << "��ѡ���ܲ����ڣ�����������" << endl;
						Sleep(700); break;
					}
					if (sign == true)
						break;
				}
				if (sign1 == true)
					break;
				if (p == '1' || p == '2')
					if (judge_studentnumber(a, b, helper, NULL))
					{
						sign3 = false;
						break;
					}
				while (true)
				{
					char k;
					sign = sign1 = false;
					system("cls");
					cout << "��������������������������������������������������������¼��ɹ���������������������������������������������������������" << endl;
					cout << a << "  " << b << "  " << c << "  " << d << "  " << a1 << "  " << b1 << "  " << c1 << endl;
					cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
					cout << "              [1]ȷ���޸�          [0]�����޸Ĳ�����" << endl;
					while (cin.peek() == '\n')
						getchar();
					k = getchar();
					while (cin.rdbuf()->in_avail())
						getchar();
					cin.clear();
					switch (k)
					{
					case '1':sign = true; sign1 = true; break;
					case '0':sign = true; sign3 = false; break;
					default:
						cout << "��ѡ���ܲ����ڣ�����������" << endl;
						Sleep(700); break;
					}
					if (sign == true)
						break;
				}
				if (sign1 == true)
					break;
			}
			if (sign3)
			{
				helper->data.Setstudentname(a);
				helper->data.Setstudentnumber(b);
				helper->data.Setstudentclass(c);
				helper->data.Setstudentgrade(d);
				helper->data.Setclassname(a1);
				helper->data.Setclassmark(b1);
				helper->data.Setmark(c1);
			}
		}
	}
	else
	{
		system("cls");
		cout << "�����ݣ�" << endl;
		Sleep(700);
	}
}
void rewrite_absent()
{
	bool sign = false, sign1 = false, sign3 = true;
	absent* helper = Absent;
	int a, b, c;
	char a1[51], b1[21], c1[21], d1[21];
	int a2;
	char c2[51], d2[5];
	if (helper != NULL)
	{
		system("cls");
		cout << "���������������������������������������������������������޸Ŀ��ک�������������������������������������������������������" << endl;
		cout << "����ҿ��ڼ�¼" << endl;
		helper = searchmenu_absent();
		if (helper != NULL)
		{
			a = helper->data.Getyear();
			b = helper->data.Getmonth();
			c = helper->data.Getdate();
			strcpy(a1, helper->data.Getstudentname());
			strcpy(b1, helper->data.Getstudentnumber());
			strcpy(c1, helper->data.Getstudentclass());
			strcpy(d1, helper->data.Getstudentgrade());
			a2 = helper->data.Getclassnumber();
			strcpy(c2, helper->data.Getclassname());
			strcpy(d2, helper->data.Getform());
			system("cls");
			char p;
			while (true)
			{
				while (true)
				{
					system("cls");
					cout << "����������������������������������������������������������������������������" << endl;
					cout << "��         ��ѡ��Ҫ�޸ĵ���Ŀ         ��" << endl;
					cout << "��                                    ��" << endl;
					cout << "��            [1]ѧ������             ��" << endl;
					cout << "��            [2]ѧ��                 ��" << endl;
					cout << "��            [3]ѧ���༶             ��" << endl;
					cout << "��            [4]ѧ���꼶             ��" << endl;
					cout << "��            [5]ʱ��                 ��" << endl;
					cout << "��            [6]�γ���               ��" << endl;
					cout << "��            [7]����                 ��" << endl;
					cout << "��            [8]�ڴ�                 ��" << endl;
					cout << "��            [9]ȫ����������         ��" << endl;
					cout << "��            [0]ȡ���޸�             ��" << endl;
					cout << "��                                    ��" << endl;
					cout << "����������������������������������������������������������������������������" << endl;
					while (cin.peek() == '\n')
						getchar();
					p = getchar();
					while (cin.rdbuf()->in_avail())
						getchar();
					cin.clear();
					switch (p)
					{
					case '1':
						cout << "������ѧ������" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(a1, 51, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '2':
						input_studentnumber(b1);
						sign = true; break;
					case '3':
						cout << "������ѧ���༶" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(c1, 21, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '4':
						cout << "������ѧ���꼶" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(d1, 21, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '5':
						cout << "������ʱ��" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						input_date(a, b, c);
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '6':
						cout << "������γ���" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(c2, 51, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '7':
						cout << "����������" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(d2, 5, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						while (strcmp(d2, "����") && strcmp(d2, "�ٵ�") && strcmp(d2, "����") && strcmp(d2, "���") && strcmp(d2, "ȱ��"))
						{
							cout << "��������ȷ������(����/�ٵ�/����/���/ȱ��)" << endl;
							while (cin.rdbuf()->in_avail())
								getchar();
							cin.clear();
							cin.getline(d2, 5, '\n');
							while (cin.rdbuf()->in_avail())
								getchar();
							cin.clear();
						}
						sign = true; break;
					case '8':
						cout << "������ڴ�" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin >> a2;
						while (cin.fail() || a2 < 0 || a2 > 5)
						{
							cout << "��������ȷ�ڴ�(1-5)" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cin >> a2;
						}
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '9':
						input_absent(a, b, c, a1, b1, c1, d1, a2, c2, d2);
						sign = true; break;
					case '0':sign = sign1 = true; sign3 = false; break;
					default:
						cout << "��ѡ���ܲ����ڣ�����������" << endl;
						Sleep(700); break;
					}
					if (sign == true)
						break;
				}
				if (sign1 == true)
					break;
				if (p == '1' || p == '2')
					if (judge_studentnumber(a1, b1, NULL, helper))
					{
						sign3 = false;
						break;
					}
				while (true)
				{
					char k;
					sign = sign1 = false;
					system("cls");
					cout << "��������������������������������������������������������¼��ɹ���������������������������������������������������������" << endl;
					cout << a << "-" << b << "-" << c << "  " << a1 << "  " << b1 << "  " << c1 << "  " << d1 << "  " << "(��" << a2 << "��)  " << c2 << "  " << d2 << endl;
					cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
					cout << "              [1]ȷ���޸�          [0]�����޸Ĳ�����" << endl;
					while (cin.peek() == '\n')
						getchar();
					k = getchar();
					while (cin.rdbuf()->in_avail())
						getchar();
					cin.clear();
					switch (k)
					{
					case '1':sign = true; sign1 = true; break;
					case '0':sign = true; sign3 = false; break;
					default:
						cout << "��ѡ���ܲ����ڣ�����������" << endl;
						Sleep(700); break;
					}
					if (sign == true)
						break;
				}
				if (sign1 == true)
					break;
			}
			if (sign3)
			{
				helper->data.Setyear(a);
				helper->data.Setmonth(b);
				helper->data.Setdate(c);
				helper->data.reflect_day();
				helper->data.Setstudentname(a1);
				helper->data.Setstudentnumber(b1);
				helper->data.Setstudentclass(c1);
				helper->data.Setstudentgrade(d1);
				helper->data.Setclassnumber(a2);
				helper->data.Setclassname(c2);
				helper->data.Setform(d2);
			}
		}
	}
	else
	{
		system("cls");
		cout << "�����ݣ�" << endl;
		Sleep(700);
	}
}
void delete_grade()
{
	bool sign = false, mark = false;
	grade* helper = Grade;
	char a[51], b[21], c[21], d[21], a1[51];
	int b1, c1;
	if (helper != NULL)
	{
		system("cls");
		cout << "��������������������������������������������������������ɾ���ɼ���������������������������������������������������������" << endl;
		cout << "����ҳɼ���¼" << endl;
		helper = searchmenu_grade();
		if (helper != NULL)
		{
			strcpy(a, helper->data.Getstudentname());
			strcpy(b, helper->data.Getstudentnumber());
			strcpy(c, helper->data.Getstudentclass());
			strcpy(d, helper->data.Getstudentgrade());
			strcpy(a1, helper->data.Getclassname());
			b1 = helper->data.Getclassmark();
			c1 = helper->data.Getmark();
			while (true)
			{
				char k;
				sign = false;
				system("cls");
				cout << a << "  " << b << "  " << c << "  " << d << "  " << a1 << "  " << b1 << "  " << c1 << endl;
				cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
				cout << "              [1]ȷ��ɾ��          [0]����ɾ��������" << endl;
				while (cin.peek() == '\n')
					getchar();
				k = getchar();
				while (cin.rdbuf()->in_avail())
					getchar();
				cin.clear();
				switch (k)
				{
				case '1':sign = true; mark = true; break;
				case '0':sign = true; break;
				default:
					cout << "��ѡ���ܲ����ڣ�����������" << endl;
					Sleep(700); break;
				}
				if (sign == true)
					break;
			}
			if (mark)
				list_delete(Grade, helper);
		}
	}
	else
	{
		system("cls");
		cout << "�����ݣ�" << endl;
		Sleep(700);
	}

}
void delete_absent()
{
	bool sign = false, mark = false;
	absent* helper = Absent;
	int a, b, c;
	char a1[51], b1[21], c1[21], d1[21];
	int a2, b2;
	char c2[51], d2[5];
	if (helper != NULL)
	{
		system("cls");
		cout << "��������������������������������������������������������ɾ�����ک�������������������������������������������������������" << endl;
		cout << "����ҳɼ���¼" << endl;
		helper = searchmenu_absent();
		if (helper != NULL)
		{
			a = helper->data.Getyear();
			b = helper->data.Getmonth();
			c = helper->data.Getdate();
			strcpy(a1, helper->data.Getstudentname());
			strcpy(b1, helper->data.Getstudentnumber());
			strcpy(c1, helper->data.Getstudentclass());
			strcpy(d1, helper->data.Getstudentgrade());
			a2 = helper->data.Getday();
			b2 = helper->data.Getclassnumber();
			strcpy(c2, helper->data.Getclassname());
			strcpy(d2, helper->data.Getform());
			while (true)
			{
				char k;
				sign = false;
				system("cls");
				cout << a << "-" << b << "-" << c << "  " << a1 << "  " << b1 << "  " << c1 << "  " << d1 << "  " << a2 << "-" << b2 << "  " << c2 << "  " << d2 << endl;
				cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
				cout << "              [1]ȷ��ɾ��          [0]����ɾ��������" << endl;
				while (cin.peek() == '\n')
					getchar();
				k = getchar();
				while (cin.rdbuf()->in_avail())
					getchar();
				cin.clear();
				switch (k)
				{
				case '1':sign = true; mark = true; break;
				case '0':sign = true; break;
				default:
					cout << "��ѡ���ܲ����ڣ�����������" << endl;
					Sleep(700); break;
				}
				if (sign == true)
					break;
			}
			if (mark)
				list_delete(Absent, helper);
		}
	}
	else
	{
		system("cls");
		cout << "�����ݣ�" << endl;
		Sleep(700);
	}
}
//ͳ��ѧ���ɼ�
void analyze_grade_student()
{
	grade* helper = Grade;
	if (helper != NULL)
	{
		bool mark = false;
		double sum_point = 0;
		int sum_classmark = 0, count = 1;
		system("cls");
		cout << "������������������������������������������������ͳ��ѧ���ɼ���������������������������������������������������������" << endl;
		helper = list_search_studentnumber(helper, mark);
		if (helper != NULL)
		{
			sum_classmark = helper->data + sum_classmark;
			sum_point = helper->data + sum_point;
			system("cls");
			cout << "������������������������������������������������ͳ��ѧ���ɼ���������������������������������������������������������" << endl;
			helper->data.student::print();
			cout << endl;
			cout << "(" << count << ") " << helper->data.Getclassname() << " (" << helper->data.Getclassmark() << "ѧ��)  " << helper->data.Getmark() << "  " << helper->data.Getgrade() << "  " << setiosflags(ios_base::fixed) << setprecision(1) << helper->data.Getpoint() << resetiosflags(ios_base::fixed) << endl;
			helper = helper->next;
			while (helper != NULL)
			{
				mark = true;
				helper = list_search_studentnumber(helper, mark);
				if (helper == NULL)
					break;
				sum_classmark = helper->data + sum_classmark;
				sum_point = helper->data + sum_point;
				count++;
				cout << "(" << count << ") " << helper->data.Getclassname() << " (" << helper->data.Getclassmark() << "ѧ��)  " << helper->data.Getmark() << "  " << helper->data.Getgrade() << "  " << setiosflags(ios_base::fixed) << setprecision(1) << helper->data.Getpoint() << resetiosflags(ios_base::fixed) << endl;
				helper = helper->next;
			}
			cout << "����������" << count << "����¼��������" << endl;
			cout << "���޿γ�ƽ������:" << setiosflags(ios_base::fixed) << setprecision(2) << sum_point / sum_classmark << resetiosflags(ios_base::fixed) << endl;
			cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "                       [���������ַ�����]" << endl;
			while (cin.peek() == '\n')
				getchar();
			getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
		else
		{
			system("cls");
			cout << "����ؼ�¼��" << endl;
			Sleep(700);
		}
	}
	else
	{
		system("cls");
		cout << "�����ݣ�" << endl;
		Sleep(700);
	}
}
//ͳ��ѧ������
void analyze_absent_student()
{
	absent* helper = Absent;
	if (helper != NULL)
	{
		bool mark = false;
		int count = 1;
		int count_[5] = { 0,0,0,0,0 };
		char a;
		system("cls");
		while (true)
		{
			bool sign = false;
			system("cls");
			cout << "����������������������������������������������������������������������������" << endl;
			cout << "��          ��ѡ��ͳ�Ʒ�ʽ            ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��          [1]ȫ����¼               ��" << endl;
			cout << "��          [2]ָ����                 ��" << endl;
			cout << "��          [3]ָ������               ��" << endl;
			cout << "��          [4]ָ������               ��" << endl;
			cout << "��          [5]ָ��ѧ��               ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "����������������������������������������������������������������������������" << endl;
			while (cin.peek() == '\n')
				getchar();
			a = getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			switch (a)
			{
			case '1':case '2':case '3':case '4':case '5':sign = true; break;
			default:
				cout << "��ѡ���ܲ����ڣ�����������" << endl;
				Sleep(700); break;
			}
			if (sign == true)
				break;
		}
		system("cls");
		cout << "������������������������������������������������ͳ��ѧ�����ک�������������������������������������������������������" << endl;
		switch (a)
		{
		case '1':helper = list_search_studentnumber(helper, mark); break;
		case '2':helper = h1[0](helper, mark); break;
		case '3':helper = h1[1](helper, mark); break;
		case '4':helper = h1[2](helper, mark); break;
		case '5':helper = h1[3](helper, mark); break;
		}
		if (helper != NULL)
		{
			if (!(strcmp(helper->data.Getform(), "����"))) count_[0]++;
			else if (!(strcmp(helper->data.Getform(), "�ٵ�"))) count_[1]++;
			else if (!(strcmp(helper->data.Getform(), "����"))) count_[2]++;
			else if (!(strcmp(helper->data.Getform(), "ȱ��"))) count_[3]++;
			else count_[4]++;
			system("cls");
			cout << "������������������������������������������������ͳ��ѧ�����ک�������������������������������������������������������" << endl;
			helper->data.student::print();
			cout << endl;
			switch (a)
			{
			case '2':cout << "ʱ��:" << helper->data.Getyear() << "��" << endl; break;
			case '3':cout << "ʱ��:" << helper->data.Getyear() << "��" << helper->data.Getmonth() << "��" << endl; break;
			case '4':cout << "ʱ��:" << helper->data.Getyear() << "��" << helper->data.Getmonth() << "��" << helper->data.Getdate() << "��" << endl; break;
			case '5':cout << "ʱ��:" << helper->data.Getyear() << "��" << helper->data.Getsemester() << endl; break;
			}
			cout << "(" << count << ") ";
			helper->data.time::print();
			cout << helper->data.Getclassname() << "  " << helper->data.Getday() << "-" << helper->data.Getclassnumber() << "  " << helper->data.Getform() << endl;
			helper = helper->next;
			while (helper != NULL)
			{
				mark = true;
				switch (a)
				{
				case '1':helper = list_search_studentnumber(helper, mark); break;
				case '2':helper = h1[0](helper, mark); break;
				case '3':helper = h1[1](helper, mark); break;
				case '4':helper = h1[2](helper, mark); break;
				case '5':helper = h1[3](helper, mark); break;
				}
				if (helper == NULL)
					break;
				if (!(strcmp(helper->data.Getform(), "����"))) count_[0]++;
				else if (!(strcmp(helper->data.Getform(), "�ٵ�"))) count_[1]++;
				else if (!(strcmp(helper->data.Getform(), "����"))) count_[2]++;
				else if (!(strcmp(helper->data.Getform(), "ȱ��"))) count_[3]++;
				else count_[4]++;
				count++;
				cout << "(" << count << ") ";
				helper->data.time::print();
				cout << helper->data.Getclassname() << "  " << helper->data.Getday() << "-" << helper->data.Getclassnumber() << "  " << helper->data.Getform() << endl;
				helper = helper->next;
			}
			cout << "����������" << count << "����¼��������" << endl;
			cout << "����" << count_[0] << "��  �ٵ�" << count_[1] << "��  ����" << count_[2] << "��  ȱ��" << count_[3] << "��  ���" << count_[4] << "��" << endl;
			cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "                       [���������ַ�����]" << endl;
			while (cin.peek() == '\n')
				getchar();
			getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
		else
		{
			system("cls");
			cout << "����ؼ�¼��" << endl;
			Sleep(700);
		}
	}
	else
	{
		system("cls");
		cout << "�����ݣ�" << endl;
		Sleep(700);
	}
}
//ͳ�ƿγ̳ɼ�
void analyze_grade_class()
{
	grade* helper = Grade;
	if (helper != NULL)
	{
		bool mark = false;
		double sum_point = 0;
		int count_student = 0, count = 1;
		system("cls");
		cout << "������������������������������������������������ͳ�ƿγ̳ɼ���������������������������������������������������������" << endl;
		helper = list_search_classname(helper, mark);
		if (helper != NULL)
		{
			count_student++;
			sum_point = helper->data.Getpoint() + sum_point;
			system("cls");
			cout << "������������������������������������������������ͳ�ƿγ̳ɼ���������������������������������������������������������" << endl;
			cout << helper->data.Getclassname() << " (" << helper->data.Getclassmark() << "ѧ��)" << endl;
			cout << "(" << count << ") ";
			helper->data.student::print();
			cout << helper->data.Getmark() << "  " << helper->data.Getgrade() << "  " << setiosflags(ios_base::fixed) << setprecision(1) << helper->data.Getpoint() << resetiosflags(ios_base::fixed) << endl;
			helper = helper->next;
			while (helper != NULL)
			{
				mark = true;
				helper = list_search_classname(helper, mark);
				if (helper == NULL)
					break;
				count_student++;
				sum_point = helper->data.Getpoint() + sum_point;
				count++;
				cout << "(" << count << ") ";
				helper->data.student::print();
				cout << helper->data.Getmark() << "  " << helper->data.Getgrade() << "  " << setiosflags(ios_base::fixed) << setprecision(1) << helper->data.Getpoint() << resetiosflags(ios_base::fixed) << endl;
				helper = helper->next;
			}
			cout << endl << "����������" << count << "����¼��������" << endl;
			cout << "ѡ��ѧ��ƽ������:" << setiosflags(ios_base::fixed) << setprecision(2) << sum_point / count_student << resetiosflags(ios_base::fixed) << endl;
			cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "                       [���������ַ�����]" << endl;
			while (cin.peek() == '\n')
				getchar();
			getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
		else
		{
			system("cls");
			cout << "����ؼ�¼��" << endl;
			Sleep(700);
		}
	}
	else
	{
		cout << "�����ݣ�" << endl;
		Sleep(700);
	}
}
//ͳ�ƿγ̿���
void analyze_absent_class()
{
	absent* helper = Absent;
	if (helper != NULL)
	{
		bool mark = false;
		int count = 1;
		int count_[5] = { 0,0,0,0,0 };
		char a;
		system("cls");
		while (true)
		{
			bool sign = false;
			system("cls");
			cout << "����������������������������������������������������������������������������" << endl;
			cout << "��          ��ѡ��ͳ�Ʒ�ʽ            ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��          [1]ȫ����¼               ��" << endl;
			cout << "��          [2]ָ����                 ��" << endl;
			cout << "��          [3]ָ������               ��" << endl;
			cout << "��          [4]ָ������               ��" << endl;
			cout << "��          [5]ָ��ѧ��               ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "����������������������������������������������������������������������������" << endl;
			while (cin.peek() == '\n')
				getchar();
			a = getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			switch (a)
			{
			case '1':case '2':case '3':case '4':case '5':sign = true; break;
			default:
				cout << "��ѡ���ܲ����ڣ�����������" << endl;
				Sleep(700); break;
			}
			if (sign == true)
				break;
		}
		system("cls");
		cout << "������������������������������������������������ͳ��ѧ�����ک�������������������������������������������������������" << endl;
		switch (a)
		{
		case '1':helper = list_search_classname(helper, mark); break;
		case '2':helper = h2[0](helper, mark); break;
		case '3':helper = h2[1](helper, mark); break;
		case '4':helper = h2[2](helper, mark); break;
		case '5':helper = h2[3](helper, mark); break;
		}
		if (helper != NULL)
		{
			if (!(strcmp(helper->data.Getform(), "����"))) count_[0]++;
			else if (!(strcmp(helper->data.Getform(), "�ٵ�"))) count_[1]++;
			else if (!(strcmp(helper->data.Getform(), "����"))) count_[2]++;
			else if (!(strcmp(helper->data.Getform(), "ȱ��"))) count_[3]++;
			else count_[4]++;
			system("cls");
			cout << "������������������������������������������������ͳ��ѧ�����ک�������������������������������������������������������" << endl;
			cout << helper->data.Getclassname() << endl;
			switch (a)
			{
			case '2':cout << "ʱ��:" << helper->data.Getyear() << "��" << endl; break;
			case '3':cout << "ʱ��:" << helper->data.Getyear() << "��" << helper->data.Getmonth() << "��" << endl; break;
			case '4':cout << "ʱ��:" << helper->data.Getyear() << "��" << helper->data.Getmonth() << "��" << helper->data.Getdate() << "��" << endl; break;
			case '5':cout << "ʱ��:" << helper->data.Getyear() << "��  " << helper->data.Getsemester() << endl; break;
			}
			cout << "(" << count << ") ";
			helper->data.print();
			helper = helper->next;
			while (helper != NULL)
			{
				mark = true;
				switch (a)
				{
				case '1':helper = list_search_studentnumber(helper, mark); break;
				case '2':helper = h2[0](helper, mark); break;
				case '3':helper = h2[1](helper, mark); break;
				case '4':helper = h2[2](helper, mark); break;
				case '5':helper = h2[3](helper, mark); break;
				}
				if (helper == NULL)
					break;
				if (!(strcmp(helper->data.Getform(), "����"))) count_[0]++;
				else if (!(strcmp(helper->data.Getform(), "�ٵ�"))) count_[1]++;
				else if (!(strcmp(helper->data.Getform(), "����"))) count_[2]++;
				else if (!(strcmp(helper->data.Getform(), "ȱ��"))) count_[3]++;
				else count_[4]++;
				count++;
				cout << "(" << count << ") ";
				helper->data.print();
				helper = helper->next;
			}
			cout << endl << "����������" << count << "����¼��������" << endl;
			cout << "����" << count_[0] << "�˴�  �ٵ�" << count_[1] << "�˴�  ����" << count_[2] << "�˴�  ȱ��" << count_[3] << "�˴�  ���" << count_[4] << "�˴�" << endl;
			cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "                       [���������ַ�����]" << endl;
			while (cin.peek() == '\n')
				getchar();
			getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
		else
		{
			system("cls");
			cout << "����ؼ�¼��" << endl;
			Sleep(700);
		}
	}
	else
	{
		cout << "�����ݣ�" << endl;
		Sleep(700);
	}
}
void rank_GPA()
{
	struct GPArecorder
	{
		char* name;
		char* number;
		char* Class;
		char* grade;
		int mark = 0;
		double pointsum = 0;
		double GPA = 0;
		GPArecorder* next;
	};
	grade* helper = Grade;
	GPArecorder* recorder = NULL, *helper1, *Operator, **ranker;
	int count = 1;
	bool sign = false;
	if (helper != NULL)
	{
		system("cls");
		cout << "����������..." << endl;
		helper1 = new GPArecorder;
		helper1->name = new char[strlen(helper->data.Getstudentname()) + 1];
		strcpy(helper1->name, helper->data.Getstudentname());
		helper1->number = new char[strlen(helper->data.Getstudentnumber()) + 1];
		strcpy(helper1->number, helper->data.Getstudentnumber());
		helper1->Class = new char[strlen(helper->data.Getstudentclass()) + 1];
		strcpy(helper1->Class, helper->data.Getstudentclass());
		helper1->grade = new char[strlen(helper->data.Getstudentgrade()) + 1];
		strcpy(helper1->grade, helper->data.Getstudentgrade());
		helper1->mark = helper->data + helper1->mark;
		helper1->pointsum = helper->data + helper1->pointsum;
		list_insert(recorder, helper1);
		helper = helper->next;
		while (helper != NULL)
		{
			sign = false;
			Operator = recorder;
			while (Operator != NULL)
			{
				if (!(strcmp(Operator->number, helper->data.Getstudentnumber())))
				{
					Operator->mark = helper->data + Operator->mark;
					Operator->pointsum = helper->data + Operator->pointsum;
					helper = helper->next;
					sign = true;
					break;
				}
				else
					Operator = Operator->next;
			}
			if (!sign)
			{
				helper1 = new GPArecorder;
				count++;
				helper1->name = new char[strlen(helper->data.Getstudentname()) + 1];
				strcpy(helper1->name, helper->data.Getstudentname());
				helper1->number = new char[strlen(helper->data.Getstudentnumber()) + 1];
				strcpy(helper1->number, helper->data.Getstudentnumber());
				helper1->Class = new char[strlen(helper->data.Getstudentclass()) + 1];
				strcpy(helper1->Class, helper->data.Getstudentclass());
				helper1->grade = new char[strlen(helper->data.Getstudentgrade()) + 1];
				strcpy(helper1->grade, helper->data.Getstudentgrade());
				helper1->mark = helper->data + helper1->mark;
				helper1->pointsum = helper->data + helper1->pointsum;
				list_insert(recorder, helper1);
				helper = helper->next;
			}
		}
		Operator = recorder;
		ranker = new GPArecorder*[count];
		for (int i = 0; i < count; i++)
		{
			Operator->GPA = Operator->pointsum / Operator->mark;
			ranker[i] = Operator;
			Operator = Operator->next;
		}
		int m, k, j, i;
		GPArecorder* d;
		k = 0; m = count - 1;
		while (k < m)
		{
			j = m - 1; m = 0;
			for (i = k; i <= j; i++)
				if (ranker[i]->GPA < ranker[i + 1]->GPA)
				{
					d = ranker[i]; ranker[i] = ranker[i + 1]; ranker[i + 1] = d; m = i;
				}
				else if (ranker[i]->GPA == ranker[i + 1]->GPA)
					if (strcmp(ranker[i]->number, ranker[i + 1]->number))
					{
						d = ranker[i]; ranker[i] = ranker[i + 1]; ranker[i + 1] = d; m = i;
					}
			j = k + 1; k = 0;
			for (i = m; i >= j; i--)
				if (ranker[i - 1]->GPA < ranker[i]->GPA)
				{
					d = ranker[i]; ranker[i] = ranker[i - 1]; ranker[i - 1] = d; m = i;
				}
				else if (ranker[i - 1]->GPA == ranker[i]->GPA)
					if (strcmp(ranker[i - 1]->number, ranker[i]->number))
					{
						d = ranker[i]; ranker[i] = ranker[i - 1]; ranker[i - 1] = d; m = i;
					}
		}
		system("cls");
		cout << "�������������������������������������������������鿴ѧ��������������������������������������������������������������" << endl;
		for (int j = 0; j < count; j++)
			cout << "(" << j + 1 << ") " << ranker[j]->number << "  " << ranker[j]->name << "  " << ranker[j]->Class << "  " << ranker[j]->grade << "  " << setiosflags(ios_base::fixed) << setprecision(2) << ranker[j]->GPA << resetiosflags(ios_base::fixed) << endl;
		cout << endl << "����������" << count << "����¼��������" << endl;
		cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
		cout << "                       [���������ַ�����]" << endl;
		while (cin.peek() == '\n')
			getchar();
		getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	else
	{
		cout << "�����ݣ�" << endl;
		Sleep(700);
	}
}
//���ļ��ж�ȡ����
void load_data()
{
	__int64 length, count;
	ifstream ip;
	grade* helper1;
	char a[51], b[21], c[21], d[21], e[51];
	int f, g;
	ip.open("grade", ios_base::binary | ios_base::in);
	ip.seekg(0, ios_base::end);
	length = (_int64)ip.tellg();
	ip.seekg(0, ios_base::beg);
	if (length != -1)
	{
		count = length / 173;
		system("cls");
		cout << "��������ɼ�����...";
		for (__int64 j = 0; j < count; j++)
		{
			ip.read(a, 51);
			ip.read(b, 21);
			ip.read(c, 21);
			ip.read(d, 21);
			ip.read(e, 51);
			ip.read((char*)&f, 4);
			ip.read((char*)&g, 4);
			helper1 = new grade{ record_grade(a,b,c,d,e,f,g),NULL };
			list_insert(Grade, helper1);
		}
		ip.close();
	}
	absent* helper1_;
	int h, i;
	char t[5];
	ip.open("absent", ios_base::binary | ios_base::in);
	ip.seekg(0, ios_base::end);
	length = (_int64)ip.tellg();
	ip.seekg(0, ios_base::beg);
	if (length != -1)
	{
		count = length / 186;
		system("cls");
		cout << "�������뿼������...";
		for (__int64 j = 0; j < count; j++)
		{
			ip.read((char*)&f, 4);
			ip.read((char*)&g, 4);
			ip.read((char*)&h, 4);
			ip.read(a, 51);
			ip.read(b, 21);
			ip.read(c, 21);
			ip.read(d, 21);
			ip.read((char*)&i, 4);
			ip.read(e, 51);
			ip.read(t, 5);
			helper1_ = new absent{ record_absent(f,g,h,a,b,c,d,i,e,t),NULL };
			list_insert(Absent, helper1_);
		}
		ip.close();
	}
}
//������д���ļ����ͷŶ�̬�ڴ�
bool clear()
{
	char a1;
	bool sign = false, sign1 = false, sign2 = false;
	grade* helper1 = Grade, *helper11;
	absent* helper2 = Absent, *helper22;
	while (true)
	{
		system("cls");
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "��     �Ƿ񱣴汾�����е����ݸ��ģ�   ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��          [1]����                   ��" << endl;
		cout << "��          [2]������                 ��" << endl;
		cout << "��          [0]ȡ�����������˵�       ��" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
		while (cin.peek() == '\n')
			getchar();
		a1 = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a1)
		{
		case '1':sign = true; sign1 = true; break;
		case '2':sign = true; break;
		case '0':sign = true; sign2 = true; break;
		default:
			cout << "��ѡ���ܲ����ڣ�����������" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
	if (sign2);
	else
	{
		if (sign1)
		{
			ofstream of;
			of.open("grade", ios_base::binary | ios_base::trunc);
			cout << "���ڱ���ɼ���Ϣ..." << endl;
			char a[51], b[21], c[21], d[21], e[51];
			int f, g;
			while (helper1 != NULL)
			{
				strcpy(a, helper1->data.Getstudentname());
				strcpy(b, helper1->data.Getstudentnumber());
				strcpy(c, helper1->data.Getstudentclass());
				strcpy(d, helper1->data.Getstudentgrade());
				strcpy(e, helper1->data.Getclassname());
				f = helper1->data.Getclassmark();
				g = helper1->data.Getmark();
				of.write(a, 51);
				of.write(b, 21);
				of.write(c, 21);
				of.write(d, 21);
				of.write(e, 51);
				of.write((char*)&f, 4);
				of.write((char*)&g, 4);
				helper1 = helper1->next;
			}
			of.close();
			of.open("absent", ios_base::binary | ios_base::trunc);
			system("cls");
			cout << "���ڱ��濼����Ϣ..." << endl;
			int h, i;
			char j[5];
			while (helper2 != NULL)
			{
				strcpy(a, helper2->data.Getstudentname());
				strcpy(b, helper2->data.Getstudentnumber());
				strcpy(c, helper2->data.Getstudentclass());
				strcpy(d, helper2->data.Getstudentgrade());
				strcpy(e, helper2->data.Getclassname());
				strcpy(j, helper2->data.Getform());
				f = helper2->data.Getyear();
				g = helper2->data.Getmonth();
				h = helper2->data.Getdate();
				i = helper2->data.Getclassnumber();
				of.write((char*)&f, 4);
				of.write((char*)&g, 4);
				of.write((char*)&h, 4);
				of.write(a, 51);
				of.write(b, 21);
				of.write(c, 21);
				of.write(d, 21);
				of.write((char*)&i, 4);
				of.write(e, 51);
				of.write(j, 5);
				helper2 = helper2->next;
			}
			of.close();
		}
		while (helper1 != NULL)
		{
			helper11 = helper1->next;
			delete helper1;
			helper1 = helper11;
		}
		while (helper2 != NULL)
		{
			helper22 = helper2->next;
			delete helper2;
			helper2 = helper22;
		}
		system("cls");
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "��             ����ɹ���             ��" << endl;
		cout << "��      ѧ����Ϣ����ϵͳ�����˳�...   ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��           ��ӭ�´�ʹ�ã�           ��" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
		Sleep(700);
	}
	return sign2;
}
//�˵����ܺ���
void return_(bool &a, char t)
{
	char a1;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "��             ����������             ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��           [1]����������            ��" << endl;
		cout << "��           [0]�������˵�            ��" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
		while (cin.peek() == '\n')
			getchar();
		a1 = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a1)
		{
		case '1':sign = true; cin.putback('\n'); cin.putback(t); break;
		case '0':sign = true; a = true; break;
		default:
			cout << "��ѡ���ܲ����ڣ�����������" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
}
void return_1(bool &a)
{
	system("cls");
	cout << "����������������������������������������������������������������������������" << endl;
	cout << "��             ����������             ��" << endl;
	cout << "��                                    ��" << endl;
	cout << "��          �����������˵�...         ��" << endl;
	cout << "����������������������������������������������������������������������������" << endl;
	a = true;
	Sleep(700);
}
void programmer()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "��            #��������Ϣ#            ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��              @��ǧԽ               ��" << endl;
		cout << "��             July,2019              ��" << endl;
		cout << "��        Tsinghua University         ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��           [1]�������˵�            ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':sign = true; break;
		default:
			cout << "��ѡ���ܲ����ڣ�����������" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
}
void grademenu()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "��              �ɼ�����              ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��            [1]¼��ɼ�             ��" << endl;
		cout << "��            [2]�޸ļ�¼             ��" << endl;
		cout << "��            [3]ɾ����¼             ��" << endl;
		cout << "��            [4]ͳ��ѧ���ɼ�         ��" << endl;
		cout << "��            [5]ͳ�ƿγ̳ɼ�         ��" << endl;
		cout << "��            [6]�鿴ѧ������         ��" << endl;
		cout << "��            [7]�������˵�           ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':establish_grade(); return_(sign, a); break;
		case '2':rewrite_grade(); return_(sign, a); break;
		case '3':delete_grade(); return_(sign, a); break;
		case '4':analyze_grade_student(); return_1(sign); break;
		case '5':analyze_grade_class(); return_1(sign); break;
		case '6':rank_GPA(); return_1(sign); break;
		case '7':sign = true; break;
		default:
			cout << "��ѡ���ܲ����ڣ�����������" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
}
void absentmenu()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "��              ���ڹ���              ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��          [1]¼�뿼�ڼ�¼           ��" << endl;
		cout << "��          [2]�޸Ŀ��ڼ�¼           ��" << endl;
		cout << "��          [3]ɾ�����ڼ�¼           ��" << endl;
		cout << "��          [4]ͳ��ѧ�����ڼ�¼       ��" << endl;
		cout << "��          [5]ͳ�ƿγ̿��ڼ�¼       ��" << endl;
		cout << "��          [6]�������˵�             ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':establish_absent(); return_(sign, a); break;
		case '2':rewrite_absent(); return_(sign, a); break;
		case '3':delete_absent(); return_(sign, a); break;
		case '4':analyze_absent_student(); return_1(sign); break;
		case '5':analyze_absent_class(); return_1(sign); break;
		case '6':sign = true; return_(sign, a); break;
		default:
			cout << "��ѡ���ܲ����ڣ�����������" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
}
void mainmenu()
{
	char a;
	while (true)
	{
		system("cls");
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "��     ��ӭʹ��ѧ����Ϣ����ϵͳ ��    ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��          [1]����ɼ�����           ��" << endl;
		cout << "��          [2]���뿼�ڹ���           ��" << endl;
		cout << "��          [3]��������Ϣ             ��" << endl;
		cout << "��          [0]�˳�ϵͳ               ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':grademenu(); break;
		case '2':absentmenu(); break;
		case '3':programmer(); break;
		case '0':if (clear());
				 else exit(0); break;
		default:
			cout << "��ѡ���ܲ����ڣ�����������" << endl;
			Sleep(700); break;
		}
	}
}
int main()
{
	Grade = NULL;
	Absent = NULL;
	load_data();
	mainmenu();
	return 0;
}