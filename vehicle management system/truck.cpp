#include "truck.h"
#include "list.h"
#include <cstring>


using namespace  std;


TRUCK :: TRUCK(ifstream &file)
{
	file>>name>>color>>mileage>>top_speed>>no_of_gears>>loading_cap>>loading_vol;
	booking_status = 0;
}


void TRUCK :: display()
{
	cout<<"\n\nName             : "<<name<<"\nColor            : "<<color<<"\nMileage          : "<<mileage<<"\nTop Speed        : "<<top_speed<<"\nNo. Of Gears     : "<<no_of_gears<<"\nLoading Capacity : "<<loading_cap<<"\nLoading Volume   : "<<loading_vol<<"\n";
}

void TRUCK :: add()
{
	cout<<"\nEnter details : (format : <string> <string> <int> <int> <int> <int> <int>)\n";
	cin>>name>>color>>mileage>>top_speed>>no_of_gears>>loading_cap>>loading_vol;
	booking_status = 0;
}

char* TRUCK :: return_name()
{
	int x;
	x=sizeof(name);
	char *temp = new char[x];
	strcpy(temp,name);
	return name;
}

int TRUCK :: get_sort_check()
{
	return loading_vol;
}

int TRUCK :: update_booking_status(int book)
{
	if(book==1 && booking_status==1)
	{
		cout<<"\n\nAlready Booked.....\nYou may go for other Truck.\n";
		return 0;
	}
	if(book==0 && booking_status==0)
	{
		cout<<"\n\nAlready Unbooked.....\nYou may have entered wrong name...\nTry again.\n";
		return 0;
	}
	booking_status = book;
	return 1;
}

int TRUCK :: return_booking_status()
{
	return booking_status;
}

int TRUCK :: watermelon(Node <TRUCK> *&head)
{
	Node<TRUCK> *temp;
	temp = head;
	int no_of_watermelon;
	int sum = 0;
	cout<<"\nEnter the number of Watermelon : ";
	cin>>no_of_watermelon;
	no_of_watermelon = no_of_watermelon * 30;
	while(temp!=NULL)
	{
		sum = sum + temp->ret().get_sort_check();
		if(sum>no_of_watermelon)
		{

			temp->ret().display();
			return 0;
		}
		if(temp->ret().return_booking_status()==0)
			temp->ret().display();
		else
		{
			sum = sum - temp->ret().get_sort_check();
		}
		temp = temp->retu();
	}
	if(no_of_watermelon>sum)
	{
		cout<<"\n\nSORRY!!!!!! \nWe don't have enough Vehicles to accomodate given no. of Watermelons.\n";
		return 0;
	}
}

int TRUCK :: operator<(TRUCK obj)
{
	if(this->get_sort_check() < obj.get_sort_check())
		return 1;
	else
		return 0;
}

int TRUCK :: operator=(char* obj)
{
	if(strcmp(this->return_name(),obj)==0)
		return 1;
	else
		return 0;
}