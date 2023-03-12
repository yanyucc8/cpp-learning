### 智能指针unique_ptr

#### 一、unique_ptr类

- 头文件 `#include <memory>`
- 智能指针，是一个模板，创建智能指针对象时，必须要提供指针所指的类型

**与shared_ptr的不同之处**：
- shared_ptr所指对象可以有多个其他shared_ptr指针指向
- unique_ptr所指对象只能有一个unique_ptr指针。当unique_ptr被销毁时，它所指向的对象也被销毁

#### 二、创建unique_ptr指针

- unique_ptr指针需要绑定到一个 `new`返回的指针上，并且不能直接将`new`的返回的地址用赋值运算符 `=` 赋值给unique_ptr
- unique_ptrs所指向的对象只能有一个unique_ptr指针，因此unique_ptr不支持普通的拷贝复制和赋值操作

```c++
std::unique_ptr<int> p1;
std::unique_ptr<int> p2(new int(42));

// std::unique_ptr<int> p3(p2); //ERROR 不能拷贝复制
// std::unique_ptr<int> p4 = new int(42); //ERROR 不能直接赋地址
// std::unique_ptr<int> p5 = p2; //ERROR 不能直接赋值
```

在c++14以后还支持使用`make_unique`来给unique_ptr作初始化操作

```c++
std::unique_ptr<int> p3 = std::make_unique<int>(42);
// auto p3 = std::make_unique<int>(42);
```

**特殊情况**

虽然两个unique_ptr不可以同时指向同一个内存对象，但是可以将一个即将销毁的unqie_ptr指针拷贝或赋值给另一个unqie_ptr

函数的参数传递和返回值就是一个很好的例子

```c++
// 因为在函数内部的unique_ptr指针随着作用域的结束会自动销毁，因此可以将其作为返回值，然后将内存传递给另一个unique_ptr指针管理

//返回函数临时变量的形式
unique_ptr<int> fun1(int p_)
{
	unique_ptr<int> ret(new int(p_));
	return ret;//返回 unique_ptr
}

//也可以写成返回匿名变量的形式
unique_ptr<int> fun2(int p_)
{
    return unique_ptr<int> ret(new int(p_))
}

int main()
{
	unique_ptr<int> p = fun1(42);
	cout <<*p << endl; //打印42
	return 0;// 函数结束后自动释放内存
}
```

#### 三、unique_ptr指针的转移

虽然unique_ptr之间不能进行拷贝和赋值，但是可以通过`release`和`reset`函数来将指针的所有权从一个非const的unique_ptr转移给另外一个unique_ptr。

1、`release()`函数

- 将当前的unique_ptr指针所指的内存置为空，并且对这块内存的所有权消失
- 返回值：返回当前unique_ptr所指的内存

```c++
std::unique_ptr<std::string> p1(new std::string("Hello World"));
auto p2(p1.release());
```

以上代码中，p1将自己所指的内存空间置空，并且返回该内存空间。之后p1对该内存空间的操作权消失，从而p2得到该内存的权限。

2、`reset()`函数

- 用来重置当前unqie_ptr指针。
- 重置之后接手另一块内存或者一直处于空状态

以下两段代码展示了如何使用`reset`函数 和`release`函数
```c++
std::unique_ptr<std::string> p1(new std::string("Hello World"));
p1.reset();// p1置空，不指向内存对象
// p1.reset(nullptr);
```

```c++
std::unique_ptr<std::string> unp1(new std::string("apple"));
std::unique_ptr<std::string> unp2(new std::string("orange"));
//让 unp1接管unp2指向的内存空间，unp2置为空指针
unp1.reset(unp2.release());
```
3、右值转换

除了上述两种办法，我们还可以通过`std::move`函数来实现unique_ptr 的所有权。这个`move`函数会将左值转换为右值引用，从而将一个 unique_ptr 转移给另一个 unique_ptr。

```c++
std::unique_ptr<int> ptr1(new int(42));
std::unique_ptr<int> ptr2 = std::move(ptr1);
```

在上面的例子中，我们使用 `std::move` 函数来转移 `ptr1` 的所有权给 `ptr2`。转移完成后，`ptr1` 变为空指针，而 `ptr2` 现在指向原来 `ptr1` 所指向的内存。

#### 四、函数的形参传递

如果要把 `unique_ptr` 作为函数的形参传递，可以按==值传递==或者==按右值引用传递==。

1、值传递

按值传递会转移 `unique_ptr` 的所有权，这意味着在函数调用完成后，原来的 `unique_ptr` 变为空指针。例如：

```c++
void fun1(std::unique_ptr<int> ptr_)
{
    //在函数内部使用ptr
}

int main()
{
    std::unique_ptr<int> ptr1(new int(42));
    fun1(std::move(ptr1));//ptr1转移给ptr_
    //函数调用完成后，ptr1变成空指针
}
```



我们也可以通过传统指针值传递的方式，拷贝unique_ptr所指的对象，传入函数

```c++
//此种方式，不会转移unique_ptr的所有权
void fun2(int & value_)
{
    std::cout << "in func2 value is :" << value_ << std::endl;
}

int main()
{
    std::unique_ptr<int> ptr1 = std::make_unique<int>(42);
    fun2(*ptr1);
}
```

2、右值引用传递

通过右值引用传递，我们可以在不改变unique_ptr的所有权的基础上，在函数内使用unique_ptr

```c++
//此种方式，不会转移unique_ptr的所有权
void fun3(std::unique_ptr<int>&& ptr_)
{
    //在函数内部使用ptr_，即ptr3_
}

int main()
{
    std::unique_ptr<int> ptr3(new int(42));
    fun3(std::move(ptr3));//ptr3不转移所有权
    //函数调用完成后，ptr3依然有效
}
```

#### 五、重置unique_ptr类删除器

概念：与shared_ptr类相同，当unque_ptr终止自己时，默认情况下会调用默认析构函数来释放(delete)自己所指向的对象。但是我们也可以通过重载来指定unqie_ptr的删除器 

***语法格式***：

- 与shared_ptr重载删除器不同，unique_ptr重载删除器会影响到unique_ptr类型以及如何构造（或reset）该类型的对象
- unique_ptr的删除器是**函数模板**，我们必须在unique_ptr指向类型之后提供删除器
- 删除器的类型可以是重载了操作符()的类，普通函数，匿名函数

```c++
//p指向一个类型为objectT的对象，并使用一个类型为deleteT的对象释放objectT对象
//它会调用一个名为fcn的delT类型对象
std::unique_ptr<objectT,deleteT> p(new objectT,fcn);
```
1、Deleter是普通函数

```c++
#include <iostream>
#include <memory>

struct Foo {
    Foo() { std::cout << "Foo...\n"; }
    ~Foo() { std::cout << "~Foo...\n"; }
};

void myDeleter(Foo* p) {
    std::cout << "Calling delete for Foo object... \n";
    delete p;
}

int main() {
    std::unique_ptr<Foo, decltype(&myDeleter)> up(new Foo(), myDeleter);
    //&myDeleter 是函数指针，指向自定义的释放函数
    return 0;
}

```

`decltype`函数选择并返回操作数的数据类型，这里decltype(&myDeleter)返回的是函数指针，因此初始化的时候，我们把自定义的删除器函数名传进去就好了。

2、Deleter是重载了操作符()的类

```c++
#include <iostream>
#include <memory>

struct Foo {
    Foo() { std::cout << "Foo...\n"; }
    ~Foo() { std::cout << "~Foo...\n"; }
};

struct D {
    void operator()(Foo* p) const {
        std::cout << "Calling delete for Foo object... \n";
        delete p;
    }
};

int main() {
    std::unique_ptr<Foo, D> up(new Foo(), D());
    return 0;
}
```

在这个例子中，我们定义了一个自定义删除器 D，它是一个函数对象（一个带有重载运算符( )的结构体）。然后我们通过将其作为第二个模板参数，并将删除器的实例传递给 std::unique_ptr 的构造函数来创建一个带有此自定义删除器的 std::unique_ptr。

3、Deleter是lambda匿名函数

```c++
#include <iostream>
#include <memory>

struct Foo {
    Foo() { std::cout << "Foo...\n"; }
    ~Foo() { std::cout << "~Foo...\n"; }
};

int main() {
    auto myDeleter = [](Foo* p) {
        std::cout << "Calling delete for Foo object... \n";
        delete p;
    };
    std::unique_ptr<Foo, decltype(myDeleter)> up(new Foo(), myDeleter);
    return 0;
}
```

在这个例子中，我们定义了一个匿名函数删除器 D，它用于管理生成的Foo对象。然后我们通过将其作为第二个模板参数，并将匿名函数传递给 std::unique_ptr 的构造函数来创建一个带有此自定义删除器的 std::unique_ptr。









