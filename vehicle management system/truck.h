#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include <fstream>
#include "list.h"
#include "car.h"

using namespace std;


class TRUCK : public CAR 
{
	private :   int loading_cap;
				int loading_vol;
	public 	:	
				TRUCK(){}
				~TRUCK(){}
				TRUCK(ifstream &file);
				void display();
				void add();
				char* return_name();
				int get_sort_check();
				int update_booking_status(int book);
				int watermelon(Node<TRUCK> *&head);
				int return_booking_status();
				int operator<(TRUCK obj);
				int operator=(char* obj);
};


#endif