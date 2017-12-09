#include "bus.h"
#include <cstring>

using namespace std;



BUS :: BUS(ifstream &file)
{
	file>>name>>color>>mileage>>top_speed>>no_of_gears>>seat_no;
	booking_status=0;
}


void BUS :: display()
{
	cout<<"\n\nName         : "<<name<<"\nColor        : "<<color<<"\nMileage      : "<<mileage<<"\nTop Speed    : "<<top_speed<<"\nNo. Of Gears : "<<no_of_gears<<"\nNo. of Seats : "<<seat_no<<"\n";
}

void BUS :: add()
{
	cout<<"\nEnter details : (format : <string> <string> <int> <int> <int> <int>)\n";
	cin>>name>>color>>mileage>>top_speed>>no_of_gears>>seat_no;
	booking_status = 0;
}

int BUS :: update_booking_status(int book)
{
	if(book==1 && booking_status==1)
	{
		cout<<"\n\nAlready Booked.....\nYou may go for other Bus.\n";
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

char* BUS :: return_name()
{
	int x;
	x=sizeof(name);
	char *temp = new char[x];
	strcpy(temp,name);
	return name;
}

int BUS :: get_sort_check()
{
	return seat_no;
}

int BUS :: return_booking_status()
{
	return booking_status;
}

int BUS :: passenger(Node<BUS> *&head, Node<CAR> *&car)
{
	Node<CAR> *car_temp;
	car_temp = car;
	Node<BUS> *temp;
	temp = head;
	int no_of_seats;
	int sum = 0;
	cout<<"\nEnter the number of seats : ";
	cin>>no_of_seats;

	//no_of_watermelon = no_of_watermelon * 30;
	while(temp!=NULL)
	{
		if(no_of_seats - sum <=5 && no_of_seats - sum >0)
		{
			while(car_temp!=NULL){
			if(car_temp->ret().return_booking_status()==0)
			{
				car_temp->ret().display();
				return 0;
			}
			car_temp = car_temp->retu();
			}
		}
		sum = sum + temp->ret().get_sort_check();
		if(sum == no_of_seats)
		{
			temp->ret().display();
			return 0;
		}
		else if(sum>no_of_seats)
		{
			temp->ret().display();
			return 0;
		}
		temp->ret().display();
		temp = temp->retu();
	}
	if(no_of_seats>sum)
	{
		cout<<"\n\nSORRY!!!!!! \nWe don't have enough Vehicles to accomodate given no. of passengers.\n\n";
		return 0;
	}
}

int BUS :: operator<(BUS obj)
{
	if(this->get_sort_check() < obj.get_sort_check())
		return 1;
	else
		return 0;
}

int BUS :: operator=(char* obj)
{
	if(strcmp(this->return_name(),obj)==0)
		return 1;
	else
		return 0;
}
