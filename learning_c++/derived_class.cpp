#include <iostream>
#include <string>

using namespace std;

class Person{
private:
    string name;
    string id_number;
    int age;
public:
    Person(string name1, string id_number1, int age1) {
        name = name1;
        id_number = id_number1;
        age = age1;
    }
    ~Person() {
        
    }
    void show() {
        cout << "姓名: " << name << "  身份证号: " << id_number << " 年龄: " << age << endl;
    }
};

class Student:public Person {
private:
    int creadit;
public:
    Student(string name1, string id_number1, int age1, int creadit1):Person(name1, id_number1, age1) {
        creadit = creadit1;
    }
    ~Student() {

    }
    void show(){
        Person::show();
        cout << "学分： " << creadit << endl;
    }
};

int main(int argc, char ** argv)
{   
    Student stu("白", "1234564651", 12, 123);
    stu.show();

    return 0;
}