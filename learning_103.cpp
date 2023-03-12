#include <iostream>
#include <list>


/*
3.7.8 排序案例
案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高

排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
*/

class Person
{
private:
    std::string usr_name;
    int usr_age;
    int usr_height;

public:
    Person(const std::string &name_, const int &age_, const int &height_) : usr_name(name_), usr_age(age_), usr_height(height_){}
    std::string get_name() const
    {
        return this->usr_name;
    }

    int get_age() const
    {
        return this->usr_age;
    }

    int get_height() const
    {
        return this->usr_height;
    }
};

inline void print_person_list(const std::list<Person> & p_list)
{
    for (std::list<Person>::const_iterator ptr = p_list.begin(); ptr != p_list.end(); ptr++)
    {
        std::cout << ptr->get_name() << "\t" << ptr->get_age() << "\t" << ptr->get_height() << std::endl;
    }
}

bool person_sort(const Person & p1_, const Person & p2_)
{
    if (p1_.get_age() == p2_.get_age())
    {
        return p1_.get_height() > p2_.get_height();
    }
    else
    {
        return p1_.get_age() < p2_.get_age();
    }        
}

void test()
{
    std::list<Person> L;

	Person p1("刘备", 35 , 175);
	Person p2("曹操", 45 , 180);
	Person p3("孙权", 40 , 170);
	Person p4("赵云", 25 , 190);
	Person p5("张飞", 35 , 160);
	Person p6("关羽", 35 , 200);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    std::cout << "before sort the list of person is " << std::endl;
    print_person_list(L);

    std::cout << "after sort the list of person is " << std::endl;
    L.sort(person_sort);
    print_person_list(L);
}

int main()
{
    test();
    return 0;
}