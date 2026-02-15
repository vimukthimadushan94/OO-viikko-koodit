#include <algorithm>
#include <iostream>
#include <vector>
#include "student.h"
using namespace std;


int main ()
{
    int selection =0;
    string studentName;
    string givenName;
    int studentAge;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            cout<<"Student Name ?"<<endl;
            cin>>studentName;

            cout<<"Student Age"<<endl;
            cin>>studentAge;
            // Lisää uusi student StudentList vektoriin.
            studentList.emplace_back(studentName, studentAge);
            break;
        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            for(auto &student: studentList){
                student.printStudentInfo();
            }
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            sort(studentList.begin(),studentList.end(),[](Student &a,Student &b){
                return a.getName()<b.getName();
            });
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            for(auto &student: studentList){
                student.printStudentInfo();
            }
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            sort(studentList.begin(),studentList.end(),[](Student &a,Student &b){
                return a.getAge()<b.getAge();
            });

            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            for(auto &student: studentList){
                student.printStudentInfo();
            }
            break;
        case 4:
        {
            // Kysy käyttäjältä opiskelijan nimi

            cout<<"Student to be found name= ?"<<endl;
            cin>>givenName;
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            auto it = find_if(studentList.begin(),studentList.end(),[givenName](Student &sd){
                return sd.getName()==givenName;
            });

            if (it != studentList.end())
            {
                it->printStudentInfo();
            }
            else
            {
                cout << "Student not found." << endl;
            }
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            break;
        }
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    }while(selection < 5);

return 0;
}
