#include "student.h"


Student::Student(string n,int a)
{
    name=n;
    age=a;
}

string Student::getName()
{
    return name;
}

int Student::getAge()
{
    return age;
}

void Student::printStudentInfo()
{
    cout<<"Student "<<name<<" Age "<<age<<endl;
}


