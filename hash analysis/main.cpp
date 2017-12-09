#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include "number_map.hpp"
#include "name_map.hpp"

using namespace std;

int main()
{
	Number_Map <long long int,int> number(743);
	Name_Map <string,string> name(2531);
	ifstream fin,f;
	fin.open("numbers.txt");
	f.open("name.txt");
	long long int read_number, read_balance, search_number;
	string read_name, read_meaning, search_name;
	while(fin>>read_number)
	{
		fin>>read_balance;
		number.put(read_number,read_balance);
	
	}
	char i = '1';
	while(f>>read_name)
	{
		getline(f,read_meaning);
		name.put(read_name,read_meaning);
	}
	cout<<"\n4X3 MATRIX OF NUMBER MAP :-\n\n";
	number.print();
	cout<<"\n4X3 MATRIX OF NAME MAP :-\n\n";
	name.print();
	ofstream fwrite;
	fwrite.open("EntryNumOutput.txt",ios::app);
	number.filewrite(fwrite);
	fwrite<<"\n";
	name.filewrite(fwrite);
	while(i=='1' || i=='2')
	{
		cout<<"\n\n$Please​ ​enter​ ​1​ ​to​ ​know​ ​balance​ ​of​ ​a​ ​phone​ ​number​ ​and​ ​2​ ​to​ ​know​ ​meaning​ ​of​ ​a​ ​name​ (3 to exit) : ";
		cin>>i;
		switch(i)
		{
			case '1' : cout<<"$Please​ ​enter​ ​number : ";
						cin>>search_number;
						cout<<"$Number : "<<search_number<<" , Balance : "<<number.find(search_number)<<endl;
						break;
			case '2' : cout<<"$Please​ ​enter​ ​name : ";
						cin>>search_name;
						cout<<"$Name : "<<search_name<<" , Meaning : "<<name.find(search_name)<<endl;
		}
	}
	return 0;
}



///Acaryanandana	son of the teacher, another name for Asvatthaman