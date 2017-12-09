#include <iostream>

using namespace std;

#include <cstring>
#include <string>
#include <cstdio>
#include <fstream>
#include "car.h"
#include "truck.h"
#include "bus.h"
#include "list.h"
#include "list.cpp"



int main()
{
	List <CAR> object_car;
	Node <CAR> *head_car = NULL;
	List <BUS> object_bus;
	Node <BUS> *head_bus = NULL;
	List <TRUCK> object_truck;
	Node <TRUCK> *head_truck = NULL;
	char st[]="car.txt";	
	object_car.add(st,head_car);
	cout<<"\n\n\ncar";
	char stp[]="bus.txt";
	object_bus.add(stp,head_bus);
	cout<<"\n\n\nbus";
	char stpd[]="truck.txt";
	object_truck.add(stpd,head_truck);
	
		int ch;
		char c;
		do{
		cout<<"Available choices :\n1.Enter Car.\n2.Enter Bus.\n3.Enter Truck\nEnter choices : ";
		cin>>ch;	
		if(ch==1)	
					{	CAR temp;
						temp.add();
						ch=object_car.search(head_car,temp.return_name(),0,0);
						if(ch==0)
						{
							Node <CAR> *temp2 = new Node<CAR>(temp);
							temp2->nextuse(head_car);
							head_car = temp2;
							cout<<"Car added sucessfully.\n";
						}
						else
						{
							cout<<"Car with name exist.\n";
						}
					}//break;

		else if(ch==2)	
		{
						BUS temp1;
						temp1.add();
						ch=object_bus.search(head_bus,temp1.return_name(),0,0);
						if(ch==0)
						{
							Node <BUS> *temp2 = new Node<BUS>(temp1);
							temp2->nextuse(head_bus);
							head_bus = temp2;
							cout<<"Bus added sucessfully.\n";

						}
						else
						{
							cout<<"Bus with name exist.\n";
						}
		}			//	break;

		else if(ch==3)
		{
						TRUCK temp3;
						temp3.add();
						ch=object_truck.search(head_truck,temp3.return_name(),0,0);
						if(ch==0)
						{
							Node <TRUCK> *temp2 = new Node<TRUCK>(temp3);
							temp2->nextuse(head_truck);
							head_truck = temp2;
							cout<<"Truck added sucessfully.\n";
						}
						else
						{
							cout<<"Truck with name exist.\n";
						}
					//	break;

			///default : cout<<"wrong choice";

		}
		cout<<"Want to enter more : ";
		
		cin>>c;
	}while(c=='y');
	char *name = new char[50];
	do
	{
		cout<<"Available choices :\n1.Remove Car.\n2.Remove Bus.\n3.Remove Truck\nEnter choices : ";
		cin>>ch;
		if(ch==1 || ch==2 ||ch==3){
		cout<<"\nEnter name : ";
		cin>>name;}
		if(ch==1)
		{
			object_car.del_node(head_car,name);
		}
		else if(ch==2)
		{
			object_bus.del_node(head_bus,name);
		}
		else if(ch==3)
		{
			object_truck.del_node(head_truck,name);
		}
		cout<<"Want to delete more : ";
		
		cin>>c;
	}while(c=='y');

		object_bus.sort(head_bus);
		object_truck.sort(head_truck);
		object_bus.book_vehicle(head_bus,1);
		object_bus.book_vehicle(head_bus,0);
		object_bus.book_vehicle(head_bus,1);
		object_bus.book_vehicle(head_bus,0);
		cout<<"watermelon check";
		(head_truck->ret()).watermelon(head_truck);
		(head_bus->ret()).passenger(head_bus,head_car);
		cout<<"************************************************************\n";
		while(head_car != NULL)
		{
			(head_car->ret()).display();
			head_car= (head_car->retu());
		}
		cout<<"************************************************************\n";
		
		while(head_bus != NULL)
		{
			(head_bus->ret()).display();
			head_bus= (head_bus->retu());
		}
		cout<<"************************************************************\n";
		
		while(head_truck != NULL)
		{
			(head_truck->ret()).display();
			head_truck= (head_truck->retu());
		}
		cout<<"************************************************************\n";
		return 0;
}