#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class Student
{
private:
      string id;
      string name;
      float cgpa;

public:
      Student(string id, string name, float cgpa)
      {
            this->id = id;
            this->name = name;
            this->cgpa = cgpa;
      }
      bool operator<(const Student std)
      {
            return this->name < std.name;
      }
      friend ostream &operator<<(ostream &os, Student &s);
      string getName() const { return name; }
      string getId() const { return id; }
      float getCgpa() const { return cgpa; }
};

ostream &operator<<(ostream &os, Student &s)
{
      os << "Student ID: " << s.id << " " << "Student Name: " << s.name << " " << "Student Cgpa: " << s.cgpa << endl;
      return os;
}

void addStudent(vector<Student> &studentRecord)
{
      string name, id;
      float cgpa;
      cout << "Enter Student ID: ";
      cin >> id;
      cout << "Enter Student Name: ";
      cin >> name;
      cout << "Enter Student Cgpa: ";
      cin >> cgpa;
      studentRecord.push_back(Student(id, name, cgpa));
      cout << name << " Added Successfully\n"
           << endl;
           Sleep(1000);
}

void printAllStudent(vector<Student> &vs)
{
      cout << "*******************************\n\n";
      for (int i = 0; i < vs.size(); i++)
      {
            cout << vs[i];
      }
      cout << "*******************************\n\n";
}

void sortStudentsData(vector<Student> &vs)
{
      system("cls");
      bool exit = false;
      while (!exit)
      {
            int ch;
            cout << "******Sort Students Data******\n";
            cout << "1. Sort By Name" << endl;
            cout << "2. Sort By Id" << endl;
            cout << "0. Close This Menu" << endl;
            cout << "******************************\n\n\n"
                 << endl;
            cout << "Enter your choice: ";
            cin >> ch;
            switch (ch)
            {
            case 0:
            {
                  // system("cls");
                  exit = true;
                  cout << "\t Back To Main Menu!" << endl;
                  Sleep(1000);
                  break;
            }
            case 1: {
                  system("cls");
                  sort(vs.begin(), vs.end());
                  printAllStudent(vs);
                  break;
            }
            case 2: {
                  system("cls");
                  sort(vs.begin(), vs.end(), [](Student s1, Student s2){
                        return s1.getId() < s2.getId();
                  });
                  printAllStudent(vs);
                  break;
            }
            }
      }
}


int main()
{
      vector<Student> studentRecord;
      int ch;
      do
      {
            cout << "******Student Management System******" << endl;
            cout << "1. Add Student" << endl;
            cout << "2. Display Student" << endl;
            cout << "3. Sort Student Data" << endl;
            cout << "4. Search Student" << endl;
            cout << "0. Exit" << endl;
            cout << "*************************************\n\n\n"
                 << endl;
            cout << "Enter your choice: ";
            cin >> ch;
            switch (ch)
            {
            case 1:
            {

                  addStudent(studentRecord);
                  system("cls");
                  break;
            }
            case 2:
            {
                  printAllStudent(studentRecord);
                  break;
            }
            case 3:
            {     
                  sortStudentsData(studentRecord);
                  break;
            }
            case 4:{
                  
            }
            case 0:{
                  cout << "\t Exiting..." << endl;
                  Sleep(1000);
                  exit(0);
                  break;
            }
            }
      } while (ch != 0);

      return 0;
}
