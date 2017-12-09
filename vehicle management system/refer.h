#ifndef REFER_H_
#define REFER_H_

#include <iostream>
#include <cstring>
#include "car.h"
#include "truck.h"
#include "bus.h"
#include "list.h"
#include "list.cpp"
using namespace std;


class REFER
{
	private : 
				List <CAR> object_car;
				Node <CAR> *head_car;
				List <BUS> object_bus;
				Node <BUS> *head_bus;
				List <TRUCK> object_truck;
				Node <TRUCK> *head_truck;
				char car_file[20];
				char bus_file[20];
				char truck_file[20];

	public  :  	
				REFER()
				{
					head_car = NULL;
					head_bus = NULL;
					head_truck = NULL;
					strcpy(car_file,"car.txt");
					strcpy(bus_file,"bus.txt");
					strcpy(truck_file,"truck.txt");
				}
				List<CAR> return_car_object()
				{
					return object_car;
				}
				List<BUS> return_bus_object()
				{
					return object_bus;
				}
				List<TRUCK> return_truck_object()
				{
					return object_truck;
				}
				Node<CAR>* return_car_node()
				{
					return head_car;
				}
				Node<BUS>* return_bus_node()
				{
					return head_bus;
				}
				Node<TRUCK>* return_truck_node()
				{
					return head_truck;
				}
				void update_list();
				void ADD();
				void REMOVE();
				void BOOK_VEHICLE(int book);
				void DISPLAY();
				void CHECK_REQUIREMENTS();
				void CHECK_REQUIREMENTS(bool val);
				//void WATERMELON();
				//void PASSENGER();

};


#endif