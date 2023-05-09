#include <iostream>
using namespace std;

class Score{
private:
	int mid_exam;
	int fin_exam;
	static int count;     //静态数据成员，用于统计学生人数
	static float sum;     //静态数据成员，用于统计期末累加成绩
	static float ave;     //静态数据成员，用于统计期末平均成绩
public:
	Score(int m, int f);
	~Score();
	static void show_count_sum_ave();   //静态成员函数
};

Score::Score(int m, int f)
{
	mid_exam = m;
	fin_exam = f;
	++count;
	sum += fin_exam;
	ave = sum / count;
}

Score::~Score()
{

}

/*** 静态成员初始化 ***/
int Score::count = 0;
float Score::sum = 0.0;
float Score::ave = 0.0;

void Score::show_count_sum_ave()
{
	cout << "学生人数: " << count << endl;
	cout << "期末累加成绩: " << sum << endl;
	cout << "期末平均成绩: " << ave << endl;
}

int main()
{
	Score sco[3] = {Score(90, 89), Score(78, 99), Score(89, 88)};
	sco[1].show_count_sum_ave();
	Score::show_count_sum_ave();

	return 0;
}
