#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <fstream>

using namespace std;

class CAR
{
	protected :   	char name[30];
					char color[10];
					int mileage;
					int top_speed;
					int no_of_gears;
					int booking_status;

	public  :	
				CAR();
				CAR(ifstream &file);
				~CAR(){}
				void add();
				virtual void display();
				char* return_name();
				int update_booking_status(int book);
				int return_booking_status();
				int operator=(char* obj);

};

#endif