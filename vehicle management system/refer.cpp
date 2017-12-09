#include "refer.h"

void REFER :: update_list()
{
	cout<<"-----------Updating-----------";
	object_car.add(car_file,head_car);
	object_bus.add(bus_file,head_bus);
	object_truck.add(truck_file,head_truck);
	system("cls");
	//gotoxy(10,10);
	cout<<"\n             ************* LIST UPDATED *************\n";
}

void REFER :: ADD()
{
		int ch;
		char c;
		do{
		cout<<"\nAvailable choices :\n1.Enter Car.\n2.Enter Bus.\n3.Enter Truck\nEnter your choice : ";
		cin>>ch;	
		if(ch==1)	
		{	
						CAR temp;
						temp.add();
						ch=object_car.search(head_car,temp.return_name(),0,0);
						if(ch==0)
						{
							Node <CAR> *temp2 = new Node<CAR>(temp);
							temp2->nextuse(head_car);
							head_car = temp2;
							cout<<"\nCar added sucessfully.\n";
						}
						else
						{
							cout<<"\nCar with name exist.\n";
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
							cout<<"\nBus added sucessfully.\n";

						}
						else
						{
							cout<<"\nBus with name exist.\n";
						}
						object_bus.sort(head_bus);
		
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
							cout<<"\nTruck added sucessfully.\n";
						}
						else
						{
							cout<<"\nTruck with name exist.\n";
						}
					//	break;
						object_truck.sort(head_truck);
			///default : cout<<"wrong choice";

		}
		else {
			cout<<"WRONG CHOICE ENTERED......";
		}
		cout<<"\n\nWant to add more : ";
		cin>>c;
	}while(c=='y');
}

void REFER :: REMOVE()
{
	int ch;
	char c;
	char *name = new char[50];
	do
	{
		cout<<"\nAvailable choices :\n1.Remove Car.\n2.Remove Bus.\n3.Remove Truck\nEnter choices : ";
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
		else
		{
			cout<<"WRONG CHOICE ENTERED.....";
		}
		cout<<"\n\nWant to Remove more (y/n): ";
		cin>>c;
	}while(c=='y');

}

void REFER :: BOOK_VEHICLE(int book)
{
	int ch;
	char c;
	char *name = new char[50];
	//do
	//{
		if(book==1)
		cout<<"\nAvailable choices :\n1.Book Car.\n2.Book Bus.\n3.Book Truck\nEnter choices : ";
		else
			cout<<"\nAvailable choices :\n1.Unbook Car.\n2.Unbook Bus.\n3.Unbook Truck\nEnter choices : ";
		
		cin>>ch;
		if(ch==1)
		{
			object_car.book_vehicle(head_car,book);
		}
		else if(ch==2)
		{
			object_bus.book_vehicle(head_bus,book);
		}
		else if(ch==3)
		{
			object_truck.book_vehicle(head_truck,book);
		}
		else
		{
			cout<<"WRONG CHOICE ENTERED.....";
		}
	
}

void REFER :: DISPLAY()
{
	int ch;
	char *name = new char[10];
	cout<<"\n1.Car.\n2.Bus.\n3.Truck.\nEnter type of vehicle : ";
	cin>>ch;
	BUS *b;
	if(ch==1)
		{
			cout<<"Enter name : ";
			cin>>name;
			ch=object_car.search(head_car,name,0,0);
			if(ch==0)
				cout<<"\n\nSorry no such car here.....\n";
		}
		else if(ch==2)
		{
			cout<<"Enter name : ";
			cin>>name;
			ch=object_bus.search(head_bus,name,0,0);
			if(ch==0)
				cout<<"\n\nSorry no such bus here.....\n";
		}
		else if(ch==3)
		{
			cout<<"Enter name : ";
			cin>>name;
			ch=object_truck.search(head_truck,name,0,0);
			if(ch==0)
				cout<<"\n\nSorry no such truck here.....\n";
		}
		else
		{
			cout<<"WRONG CHOICE ENTERED.....";
		}
}

void REFER :: CHECK_REQUIREMENTS()
{
	object_truck.sort(head_truck);
	(head_truck->ret()).watermelon(head_truck);
}

void REFER :: CHECK_REQUIREMENTS(bool val)
{
	object_bus.sort(head_bus);
	(head_bus->ret()).passenger(head_bus,head_car);
}
