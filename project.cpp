#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

class Student
{
 int id;
 char name[100];
 char mob[10];
 float marks;
 float per;
 
 public:
  void getData();
  void showData();
  int getAdmno(){return id;}
}s;



	void Student::getData()
{
 cout<<"           Enter Student Details     "<<endl;
 cout<<"Enter Student Id         : "; 
 cin>>id;
  cout<<"Enter  Name             : "; 
 cin>>name;
  cout<<"Enter Student Mobaile NO: "; 
 cin>>mob;

 cout<<"Enter Marks out of 500    : ";
 cin>>marks;
 
 per=marks*100/500;
}

void Student::showData()
{
 cout<<"        DATA      "<<endl;
 cout<<"Student Id               : "<<id<<endl;
 cout<<"Student Name             : "<<name<<endl;
 cout<<"Student Mobaile NO       : "<<mob<<endl;
 cout<<" Student Marks out of 500: "<<marks<<endl;
 cout<<"Student Percentage       : "<<per<<endl;
 cout<<endl;
}

void addData()
{
 ofstream fout;
 fout.open("Students.dat",ios::binary|ios::out|ios::app);
 s.getData();
 fout.write((char*)&s,sizeof(s));
 fout.close();
 cout<<"   Data Successfully Save    "<<endl;
}

void displayData()
{
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();

}



  void searchData()
{
 int n, flag=0;
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 cout<<"Enter Student Id : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
    s.showData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Stusents Id. "<<n<<" not found...."<<endl;
 
}




void deleteData()
{
 int n, flag=0;
 ifstream fin;
 ofstream fout,tout;

 fin.open("Students.dat",ios::in|ios::binary);
 fout.open("TempStud.dat",ios::out|ios::app|ios::binary);
 tout.open("TrashStud.dat",ios::out|ios::app|ios::binary);

 cout<<"   Enter Students Id NO:   ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {

   s.showData();
   tout.write((char*)&s,sizeof(s));
   flag++;
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
  cout<<"   Not found.."<<endl;
 remove("Students.dat");
 rename("tempStud.dat","Students.dat");
}


void UpdateData()
{
 int n, flag=0, pos;
 fstream fio;

 fio.open("Students.dat",ios::in|ios::out|ios::binary);
 
 cout<<"Enter Id No : ";
 cin>>n;
 
 while(fio.read((char*)&s,sizeof(s)))
 {
  pos=fio.tellg();
  if(n==s.getAdmno())
  {
   
   s.showData();
   cout<<"  Enter the New Details....\n";
   s.getData();
   fio.seekg(pos-sizeof(s));
   fio.write((char*)&s,sizeof(s));
   flag++;
  }
 }
 fio.close();
 
 if(flag==0)
  cout<<" Not found...."<<endl;
}

void project()
{
 int ch;
 do
 {
  system("cls");
  cout<<"      STUDENT MANAGEMENT SYSTEM         "<<endl;

 
  cout<<"1. ADD data"<<endl;
  cout<<"2. View Data "<<endl;
  cout<<"3. Search Data"<<endl;
    cout<<"4. Update Data "<<endl;
   cout<<"5. Delete Data "<<endl;
   cout<<"0. Exit "<<endl;
  cout<<"Enter your choice  : ";
  cin>>ch;
  system("cls");
  switch(ch)
  {
   case 1: addData(); break;
   case 2: displayData(); break;
   case 3: searchData(); break;
    case 4: UpdateData(); break;
   case 5: deleteData(); break;
  }
  system("pause");
 }while(ch);
}

int main()
{
 project();
}


