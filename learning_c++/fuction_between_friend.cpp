/**
 *  一个函数同时定义为两个类的友元函数
*/

#include <iostream>
#include <string>
using namespace std;


class Score;        // 对Score类的提前引用说明
class Student{
private:
    string name;
    int number;
public:
    Student(string na, int nu) {
        name = na;
        number  = nu;
    }
    friend void show(Score &sc, Student &st);
};

class Score
{
private:
    int mid_exam;
    int fin_exam;
public:
    Score(int m, int f) {
        mid_exam = m;
        fin_exam = f;
    }
    friend void show(Score &sc, Student &st);
};

void show(Score &sc, Student &st) {
	cout << "姓名：" << st.name << "  学号：" << st.number << endl;
	cout << "期中成绩：" << sc.mid_exam << "  期末成绩：" << sc.fin_exam << endl;
}

int main()
{
    Score sc(90, 89);
    Student st("白", 123456);
    show(sc, st);
    return 0;
}