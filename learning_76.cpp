#include <iostream>
using namespace std;

//抽象的CPU类
class CPU
{
public:
    virtual void calculator() = 0;

    // virtual ~CPU()
    // {
    //     cout << "CPU 虚析构函数" << endl;
    // }
};

//抽象的GPU类
class GPU
{
public:
    virtual void display() = 0;

    // virtual ~GPU()
    // {
    //     cout << "GPU 虚析构函数" << endl;
    // }
};

//抽象的Memory类
class Memory
{
public:
    virtual void storage() = 0;

    // virtual ~Memory()
    // {
    //     cout << "Memory 虚析构函数" << endl;
    // }
};

//CPU的子类1
class CPU_Intel : public CPU
{
public:
    virtual void calculator()
    {
        cout << "Intel的CPU正在计算！" << endl;
    }

    // ~CPU_Intel()
    // {
    //     cout << "CPU_Intel 析构函数" << endl;
    // }
};

//CPU的子类2
class CPU_AMD : public CPU
{
public:
    void calculator()
    {
        cout << "Intel的CPU正在计算！" << endl;
    }
};

//GPU的子类1
class GPU_Intel : public GPU
{
public:
    void display()
    {
        cout << "Intel的GPU正在计算！" << endl;
    }

    // ~GPU_Intel()
    // {
    //     cout << "GPU_Intel 析构函数" << endl;
    // }
};

//GPU的子类2
class GPU_AMD : public GPU
{
public:
    void display()
    {
        cout << "AMD的GPU正在计算！" << endl;
    }
};

//Memory的子类1
class Memory_Intel : public Memory
{
public:
    void storage()
    {
        cout << "Intel的Memory正在存储！" << endl;
    }

    // ~Memory_Intel()
    // {
    //     cout << "Memory_Intel 析构函数" << endl;
    // }
};

//Memory的子类2
class Memory_AMD : public Memory
{
public:
    void storage()
    {
        cout << "AMD的Memory正在存储！" << endl;
    }
};

//组成Computer类

//首先Computer类 不是 cpu，gpu，memory的子类，它是属于一个单独的类，只是包含了cpu，gpu，memory的属性
//所以Computer类的析构不会影响到其他类的析构，不需要构建cpu，gpu，memory的虚析构函数。
//（cpu，gpu，memory都是纯虚函数，不能直接创建对象，所以我们在Computer类中用指针的方式在堆区来创建新内存空间，
//那么我们可以在Computer的析构函数中释放堆区的内存空间）
//经试验，Computer的析构函数总是在最后执行，即保证了堆区内存空间的释放
class Computer
{
private:
    //抽象类不能实例化，但是可以定义一个指向该类的指针
    CPU* m_cpu;
    GPU* m_gpu;
    Memory* m_memory;
public:
    Computer(CPU* _cpu, GPU* _gpu, Memory* _memory)
    {
        m_cpu = _cpu;
        m_gpu = _gpu;
        m_memory = _memory;
    }
    
    void assemble_Computer()
    {
        m_cpu->calculator();
        m_gpu->display();
        m_memory->storage();
    }

    ~Computer()
    {
        //释放CPU零件
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }

        //释放显卡零件
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}

		//释放内存条零件
		if (m_memory != NULL)
		{
			delete m_memory;
			m_memory = NULL;
		}

        cout << "Computer 析构函数" << endl;
    }
};

void test()
{
    CPU *cpu_1 = new CPU_Intel;//定义父类的指针指向子类的对象
    GPU *gpu_1 = new GPU_Intel;
    Memory *memory_1 = new Memory_Intel;

    cout << "第一台电脑开始工作：" << endl;
	//创建第一台电脑

    Computer *pc_1 = new Computer(cpu_1, gpu_1, memory_1);
    pc_1->assemble_Computer();
    delete pc_1;//这里会在 delete时 直接执行 Computer的析构函数

    //1.此处Computer类可以直接实例化，因为Computer实例的建立和销毁都在同一函数下，所以存放在 栈区或堆区都可以
    
    CPU *cpu_2 = new CPU_AMD;
    GPU *gpu_2 = new GPU_AMD;
    Memory *memory_2 = new Memory_AMD;

    cout << "第二台电脑开始工作：" << endl;
    //创建第二台电脑
    Computer pc_2(cpu_2, gpu_2, memory_2);
    pc_2.assemble_Computer();
    //2.这里就不会出现Delete了，因为Computer类存放在栈区，test函数结束自动执行Computer析构函数，会自动释放内存
}

int main()
{
    test();

    system("pause");
    return 0;
}