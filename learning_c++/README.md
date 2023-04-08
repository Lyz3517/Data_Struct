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

一般说，公有成员是类的对外接口，而私有成员是类的内部数据和内部实现，i不希望外界访问。将类的数据成员划分为不同的访问级别有两个好处：一是信息隐蔽，实现封装，将类的内部数据与内部实现和外部接口分开，这样使该类的外部程序不需要了解类的详细实现；二是保护数据，即将类的重要信息保护起来，以避免其他程序进行不恰当的修改。

**对象赋值语句**

```cpp {.line-numbers}
Score op1, op2;
op1.setScore(99, 100);
op2 = op1;
op2.showScore();
```

### 3.4 构造函数与析构函数

**构造函数**:构造函数时一种特殊的成员函数，它主要用于为对象分配空间，进行初始化。构造函数的名字必须与类名相同 ，而不能由用户任意命名。它可以有任意类型的参数，但不能具有返回值。它不需要用户来调用，而是在建立对象时自动执行。

