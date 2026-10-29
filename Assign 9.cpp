#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Employee
{
public:
   Employee(int = 0, const string & = string(""), double = 0.0);

   void setId(int);
   int getId() const;

   void setName(const string &);
   string getName() const;

   void setSalary(double);
   double getSalary() const;

private:
   int id;
   string name;
   double salary;

};

Employee::Employee(int i, const string &n, double s)
   :id(i),name(n),salary(s){}

void Employee::setId(int id){
   this->id = id;
}

int Employee::getId() const{
   return id;
}

void Employee::setName(const string &name){
   this->name = name;
}

string Employee::getName() const{
   return name;
}

void Employee::setSalary(double salary){
   this->salary = salary;
}

double Employee::getSalary() const{
   return salary;
}

void writeToFile(const string &filename, Employee *e){
   ofstream fout(filename, ios::app);
   if(!fout){
      cerr<<"Cannot open file for writing"<<endl;
      exit(EXIT_FAILURE);
   }
   fout<<e->getId()<<""<<e->getName()<<""<<e->getSalary()<<endl;
   fout.close();
}

void readFromFile(const string &filename) {

   ifstream fin(filename, ios::in);
   if(!fin){
      cerr<<"Cannot open file for writing"<<endl;
      exit(EXIT_FAILURE);
   }
   int id = 0;
   string nm = "";
   double sal = 0.0;
   cout<<"------------------------------"<<endl;
   cout << left << setw( 10 ) << "ID" << setw( 13 )
   << "NAME" << "SALARY" << endl << fixed
      << showpoint;
   cout<<"------------------------------"<<endl;
   while(fin >> id >> nm >> sal){
      cout << left << setw(10) << id << setw(13)
            << nm << setw(7) << setprecision(2)
         << right << sal << endl;
   }
   cout<<"------------------------------"<<endl;
   fin.close();
}


int main()
{
   const string filename = "payroll.dat";

   writeToFile(filename,new Employee(101,"Mickey",5600.00));
   writeToFile(filename,new Employee(102,"Donald",2635.00));
   writeToFile(filename,new Employee(103,"Zairo",1200.00));

   readFromFile(filename);

   return 0;
}
