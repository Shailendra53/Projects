#include "car.h"
#include <cstring>


using namespace  std;

CAR::CAR(){}

CAR :: CAR(ifstream &file)
{
	file>>name>>color>>mileage>>top_speed>>no_of_gears;
	booking_status=0;
}


void CAR :: display()
{
	cout<<"\n\nName         : "<<name<<"\nColor        : "<<color<<"\nMileage      : "<<mileage<<"\nTop Speed    : "<<top_speed<<"\nNo. Of Gears : "<<no_of_gears<<"\n";
}

void CAR :: add()
{
	cout<<"\nEnter details : (format : <string> <string> <int> <int> <int>)\n";
	cin>>name>>color;
	cin>>mileage>>top_speed>>no_of_gears;
	booking_status = 0;
}

char* CAR :: return_name()
{
	int x;
	x=sizeof(name);
	char *temp = new char[x];
	strcpy(temp,name);
	return name;
}

int CAR :: update_booking_status(int book)
{
	if(book==1 && booking_status==1)
	{
		cout<<"\n\nAlready Booked.....\nYou may go for other Car\n\n";
		return 0;
	}
	if(book==0 && booking_status==0)
	{
		cout<<"\n\nAlready Unbooked.....\nYou may have entered wrong name...\nTry again.\n\n";
		return 0;
	}
	booking_status = book;
	return 1;
}

int CAR :: return_booking_status()
{
	return booking_status;
}

int CAR :: operator=(char* obj)
{
	if(strcmp(this->return_name(),obj)==0)
		return 1;
	else
		return 0;
}
