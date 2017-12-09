#ifndef BUS_H
#define BUS_H
#include <iostream>
#include <fstream>
#include "list.h"
#include "car.h"

using namespace std;


class BUS : public CAR
{
	private :   int seat_no;
	public 	:	
				//void add_vehicle();
				BUS(){}
				~BUS(){}
				BUS(ifstream &file);
				void remove();
				void display();
				void add();
				char* return_name();
				int get_sort_check();
				int update_booking_status(int book);
				int return_booking_status();
				int passenger(Node<BUS> *&head, Node<CAR> *&car);
				int operator<(BUS obj);
				int operator=(char* obj);
};

#endif