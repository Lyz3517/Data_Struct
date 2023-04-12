# C++语法

<img src = "assert/C++.png" width = %>

## 三、类和对象

### 3.1 类的构成

> 类声明中的内容包括数据和函数，分别称为数据成员和成员函数。按访问权限划分，数据成员和成员函数可分为共有、保护和私有三种。

```cpp {.line-numbers}
class 类名{
    public:
        公有数据成员；
        公有成员函数；

    protected:
        保护数据成员；
        保护成员函数；

    private:
        私有数据成员；
        私有成员函数；

}；
```

**成绩类**
```cpp {.line-numbers}
class Score{
    public:
        void setScore(int m, int f);
        void showScore();

    private:
        int mid_exam;
        int fin_exam;
};
```

**解释**:

- 对于一个具体的类来讲，类声明格式中三个部分并非一定要全有，但至少要有其中的一个部分。一般情况下，一个类的数据成员应该声明为私有成员，成员函数声明为公有成员。这样，内部的数据整个隐蔽在类中，在类的外部根本无法看到，使数据得到有效的保护，也不会对该类以外的其余部分造成影响，程序之间的相互作用就被降低到最小。
- 类的声明中的关键字private、protected、public可以任意出现。
- 若私有部分处于类的第一部分时，关键字private可以省略。这样，如果一个类体中没有一个访问权限的关键字，则其中的数据成员和成员函数都默认为私有。
- 不能在类声明中给数据成员赋值。


### 3.2 成员函数的定义

**普通成员函数的定义**

> 在类的声明中只给出成员函数的原型，而成员函数的定义写在类的外部。这种成员函数定义的一般形式是:

```cpp {.line-numbers}
返回值类型 类名::成员函数(参数表){函数体}
```

例如：表示分数的类Score可声明如下:

```cpp {.line-numbers}
class Score{
public:
    void setScore(int m, int f);
    void showScore();

private:
    int mid_exam;
    int fin_exam;
};

void Score::setScore(int m, int n){
    mid_exam = m;
    fin_exam = n;
}

void Score::showScore(){
    cout << "期中成绩: " << mid_exam << endl;
	cout << "期末成绩：" << fin_exam << endl;
}
```

**内联成员函数的定义**

- 隐式声明：将成员函数直接定义在类的内部

```cpp {.line-numbers}
class Score{
public:
	inline void setScore(int m, int f) {
        mid_exam = m;
	    fin_exam = f;
    }
	inline void showScore() {
        cout << "期中成绩: " << mid_exam << endl;
	    cout << "期末成绩：" << fin_exam << endl;
    }
private:
	int mid_exam;
	int fin_exam;
};

```

- 显示声明：在类声明只给出函数成员的原型，而将成员函数的定义放在类的外部。

```cpp {.line-numbers}
class Score{
public:
	inline void setScore(int m, int f);
	inline void showScore();
private:
	int mid_exam;
	int fin_exam;
};

inline void Score::setScore(int m, int f) 
{
	mid_exam = m;
	fin_exam = f;
}

inline void Score::showScore()
{
	cout << "期中成绩: " << mid_exam << endl;
	cout << "期末成绩：" << fin_exam << endl;
}

```

**注意**：在类中，使用inline定义内联函数时，必须将类的声明，和内联n成员函数的定义都放在同一个文件(或同一个头文件中)，否则编译时无法进行代码置换。

### 3.3 对象的定义和使用

通常把具有共同属性的行为的事务所构成的集合称为类

类的对象可以看做该类类型的一个实例，定义一个对象和定义一个一般变量相似。

**对象的定义**

- 在声明类的同时，直接定义对象

```cpp {.line-numbers}
class Score{
    public:
        void setScore(int m, int f);
        void showScore();

    private:
        int mid_exam;
        int fin_exam;
}op1, op2;
```

- 声明了类以后，再使用时再定义对象

```cpp {.line-numbers}
Score op1, op2;
```

**对象中成员的访问**

```cpp {.line-numbers}
对象名.数据成员名               op1.showScore();
对象名.成员函数名[参数列表]      op1.setScore(80, 90);
``` 

**说明**：
- 在类的内部所有成员之间都可以通过成员函数直接访问，但类的外部不能访问对象的私有成员。
- 在定义对象时，若定义的是指向此对象的指针变量，则访问此对象的成员时，不能用"."操作符，而应该使用"->"操作符，如下：

```cpp {.line-numbers}
Score op, *sc;
sc = &op;
sc->setScore(90, 90);
op.showScore();
```

**类的作用域和类成员的访问属性**

私有成员只能被类中的成员函数访问，不能在类的外部，通过累的对象进行访问。

一般说，公有成员是类的对外接口，而私有成员是类的内部数据和内部实现，i不希望外界访问。将类的数据成
员划分为不同的访问级别有两个好处：一是信息隐蔽，实现封装，将类的内部数据与内部实现和外部接口分开，这样使该类的外部程序不需要了解类的详细实现；二是保护数据，即将类的重要信息保护起来，以避免其他程序进行不恰当的修改。

**对象赋值语句**

```cpp {.line-numbers}
Score op1, op2;
op1.setScore(99, 100);
op2 = op1;
op2.showScore();
```

### 3.4 构造函数与析构函数

**构造函数**:构造函数时一种特殊的成员函数，它主要用于为对象分配空间，进行初始化。构造函数的名字必须与类名相同 ，而不能由用户任意命名。它可以有任意类型的参数，但不能具有返回值。它不需要用户来调用，而是在建立对象时自动执行。

```cpp {.line-numbers}
class Score{
public:
	Score(int m, int f);  //构造函数
	void setScore(int m, int f);
	void showScore();
private:
	int mid_exam;
	int fin_exam;
};

Score::Score(int m, int f)
{
	mid_exam = m;
	fin_exam = f;
}
```

在建立对象时，采用构造函数给数据成员赋值，通常由以下两种方式
```cpp {.line-numbers}
类名 对象名[{实参表}]
Score op1(99, 100);
op1.showScore();

类名 *指针变量名 = new 类名[{参数表}]
Score *p;
p = new Score(90, 100);
p->showScore();
---------------------------------------
Score *p = new Score(90, 100);
p->showScore();
```
**说明**：
- 构造函数的名字必须与类名相同，否则编译程序将把它当做一般的成员函数来处理
- 构造函数没有返回值类型，在定义构造函数时，是不能说明它的类型的。
- 与普通的成员函数一样，构造函数的函数体可以写在类体内也可以写在类体外。
- 构造函数一般声明为公有成员，但它不需要也不能像其他成员函数那样被显示调用，它是在定义对象的同时被自动调用，而且只执行一次。
- 构造函数不可以带参。

**初始化成员列表**
在声明类时，对数据成员的初始化工作一般在构造函数中用赋值语句进行。此外还可以用成员初始化列表实现对数据成员的初始化。

```cpp {.line-numbers}
类名::构造函数名([参数表])[:{成员初始化列表}] {
    // 构造函数体
}
```
```cpp {.line-numbers}
class A{
private:
    int x;
    int& rx;
    const double pi;

public:
    A(int v) : x(v) , rx(x), pi(3.14){      // 成员初始化列表

    }
    void print()
    {
        cout << "x = " << x << " rx = " << rx << " pi = " << pi << endl;
    }
    
};

/*说明*/
/***
 * 类成员是按照它们在类里被声明的顺序进行初始化的，与它们在成员初始化列表中的顺序无关。
 * 
 * 
 * 
 * 
 * **/
```


**带默认参数的构造函数**
```cpp {.line-numbers}
#include <iostream>
using namespace std;

class Score{
public:
	Score(int m = 0, int f = 0);    //带默认参数的构造函数
	void setScore(int m, int f);
	void showScore();
private:
	int mid_exam;
	int fin_exam;
};

Score::Score(int m, int f) : mid_exam(m), fin_exam(f)
{
	cout << "构造函数使用中..." << endl;
}

void Score::setScore(int m, int f) 
{
	mid_exam = m;
	fin_exam = f;
}

void Score::showScore()
{
	cout << "期中成绩: " << mid_exam << endl;
	cout << "期末成绩：" << fin_exam << endl;
}

int main() 
{
	Score op1(99, 100);
	Score op2(88);
	Score op3;
	op1.showScore();
	op2.showScore();
	op3.showScore();

	return 0;
}

```
**析构函数**

析构函数也是一种特殊的成员函数。它执行与构造函数相反的操作；通常用于撤销对象时的一些清理n任务，如释放分配给对象的i内存空间等。析构函数有以下一些特点：

1. 析构函数与构造函数名字相同，但是他前面必须加一个波浪号(~);
2. 析构函数没有参数和返回值，也不能被重载，因此只有一个。
3. 当撤销对象时，编译系统会自动调用析构函数。

```cpp {.line-numbers}
class Score{
public:

private:

};

/*
**/
```


**默认的构造函数和析构函数**

**构造函数的重载**

**拷贝构造**

**浅拷贝**
浅拷贝，就是由默认的构造函数所实现的数据成员逐一赋值。通常的默认i拷贝构造u函数是能够胜任此工作的，但若类中含有n指针类型的数据，则这种按数据成员逐一赋值的方法会产生错误。
```cpp {.line-numbers}
class Student {
public:

private:
};
```
**深拷贝**

### 3.5 自引用指针this

### 3.6 对象数组与对象指针

### 3.7 string类

### 3.8 向函数传递对象

### 3.9 静态成员

### 3.10 友元

### 3.11 类的组合

### 3.12 共享数据的保护

## 4. 继承与派生