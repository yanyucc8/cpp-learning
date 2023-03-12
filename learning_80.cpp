#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test()
{
	ifstream ifs("test_1.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	Person p;
	ifs.read((char *)&p, sizeof(p));

	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}

int main() {

	test();

	system("pause");

	return 0;
}