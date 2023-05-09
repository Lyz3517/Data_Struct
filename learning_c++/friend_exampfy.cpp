// 友元函数既可以是不属于任何类的非成员函数，也可以是另一个类的成员函数。友元函数不是当前类的成员函数，但是
// 可以访问该类的所有成员，包括私有成员、保护成员和公有成员。

// 在类的声明友元函数时，需要在其函数名之前加上关键字friend。此声明可以放在公有部分，也可以放在保护部分
// 和私有部分。友元函数可以定义在类的内部，也可以定义在类的外部


/***
 * 将非成员函数声明为友元函数
*/
#include <iostream>
using namespace std;

class Score{
private:
	int mid_exam;
	int fin_exam;
public:
	Score(int m, int f);
	void showScore();
	friend int getScore(Score &ob);
};

Score::Score(int m, int f)
{
    mid_exam = m;
    fin_exam = f;
}

int getScore(Score &ob)
{
    return (int)(0.3 * ob.mid_exam + 0.7 * ob.fin_exam);
}

int main()
{
    Score score(98, 78);
    cout << "成绩为: " << getScore(score) << endl;
    return 0;
}
