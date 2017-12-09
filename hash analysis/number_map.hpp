#ifndef NUMBER_MAP_HPP
#define NUMBER_MAP_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

template <typename K,typename V>
class Node;

template <typename K, typename V>
  class Number_Map {					// map interface
  public:
    Number_Map(int capacity);			// constructor
    int size() const;				// number of entries in the map
    bool empty() const;				// is the map empty?
    V& find(const K& k);		// find entry with key k
    void put(const K& k, const V& v);	// insert/replace pair (k,v)
    void erase(const K& k);			// remove entry with key k
    unsigned int integercasting(const K& k); //function for integer casting
    unsigned int componentsum(const K& k);   //function for component sum
    unsigned int polynomialsum(const K& k);	//function for polynomial sum
    unsigned int cyclicshift(const K& k);	//function for cyclic shift
    void remove(Node<K,V>*& temp,int place);
    int division(unsigned int key);
    int mad(unsigned int key);
    int multiplication(unsigned int key);
    void add(int place, const K& k, const V& v, int hash, int method);
    void print();
    int sizeofelement(const K& k);
    void enter_component(const K& k, const V& v);
    void enter_polynomial(const K& k, const V& v);
    void enter_cyclicshift(const K& k, const V& v);
    void enter_integercasting(const K& k, const V& v);
    V& check_key(Node<K,V>* temp, const K& k);
    void find_hash();
    void removespaces(V& v);
    void filewrite(ofstream &fwrite);
    unsigned int get_key(const K& k);
    int get_place(unsigned int key);

   private : 
   	Node<K,V> **array[12];
   	float counter[4][3];
   	int size_hash;
   	int m;
   	int hash;
   	int key_change_method;
   	int index_method;
   	int find_hash_count;
 };

template <typename K,typename V>
 class Node
 {
 	private :
 	 K key;
 	 V value;
 	 Node<K,V>* next;

 	public : 
 	 friend class Number_Map<K,V>;
 };

template <typename K,typename V>
 void Number_Map <K,V> :: filewrite(ofstream &fwrite)
 {
  fwrite<<"4X3 MATRIX OF NUMBER MAP :-\n";
    for(int i=0;i<4;i++)
    {
      for(int j=0;j<3;j++)
        fwrite<<counter[i][j]*100/size_hash<<" ";
      fwrite<<"\n";
    }
 }

template <typename K,typename V>
 int Number_Map <K,V> :: size() const
 {
 	return size_hash;
 }

template <typename K,typename V>
 bool Number_Map <K,V> :: empty() const
 {
 	if(size_hash)
 		return false;
 	else
 		return true;
 }

template <typename K,typename V>
 unsigned int Number_Map <K,V> :: get_key(const K& k)
 {
 	switch(key_change_method)
 	{
 		case 0 : return componentsum(k);
 		case 1 : return polynomialsum(k);
 		case 2 : return cyclicshift(k);
 		case 3 : return integercasting(k);
 	}
 }

template <typename K,typename V>
 int Number_Map <K,V> :: get_place(unsigned int key)
 {
 	switch(index_method)
 	{
 		case 0 : return division(key);
 		case 1 : return mad(key);
 		case 2 : return multiplication(key);
 	}
 }

template <typename K,typename V>
 void Number_Map <K,V> :: erase(const K& k)
 {
 	if(find_hash_count==0)
 		find_hash();
 	//cout<<hash<<endl;
 	unsigned int key = get_key(k);
 	int place = get_place(key);
 	Node<K,V>* temp = array[hash][place];
 	while(temp!=NULL)
 	{
 		if(temp->key == k)
 		{
 			remove(temp,place);
 			size_hash--;
 			return;
 		}	
 		temp = temp->next;
 	}
  
 }

template <typename K,typename V>
 void Number_Map <K,V> :: remove(Node<K,V>*& temp, int place)
 {
 	Node<K,V>* check =array[hash][place];
 	if(check == temp)
 	{
 		check = check->next;
 		array[hash][place] = check;
 		cout<<"deleted\n";
 	}
 	else
 	{
 		while(check!=NULL)
 		{
 			if(check->next == temp)
 			{
 				check -> next = temp -> next;
 				delete temp;
 				cout<<"deleted";
 			}
 			check = check ->next;
 		}
 	}
 }

template <typename K,typename V>
 Number_Map <K,V>:: Number_Map(int capacity)
 {
 	for(int i=0;i<12;i++)
 	{	
 		
 		array[i] = new Node<K,V>* [capacity];
 		for(int j=0;j<capacity;j++)
 		{
 			array[i][j] = NULL;
 			//cout<<j<<" ";
 		}
 	}
 	for(int i=0;i<4;i++)
 		for(int j=0;j<3;j++)
 			counter[i][j]=0;//
 	size_hash = 0;
 	m = capacity;
 	hash = 0;
 	key_change_method = 0;
 	index_method = 0;
 	find_hash_count = 0;
 }

template <typename K,typename V>
 void Number_Map <K,V> :: find_hash()
 {
 	int min = counter[0][0];
 	for(int i=0;i<3;i++)
 	for(int j=0;j<3;j++)
 		if(counter[i][j]<min)
 		{
 			min = counter[i][j];
 			hash = i*3+j;
 			key_change_method=i;
 			index_method=j;
 		}
 }

template <typename K,typename V>
 V& Number_Map <K,V> :: find(const K& k) 
 {
 	if(find_hash_count==0)
 		find_hash();
 	//cout<<hash<<endl;;
	unsigned int key = get_key(k) ;
	int place = get_place(key);
 		Node<K,V> *temp = array[hash][place];
 		return check_key(temp,k);
 
 }

template <typename K,typename V>
 V& Number_Map <K,V> :: check_key(Node<K,V>* temp, const K& k)
 {
 
	while(temp!=NULL)
	{
		if(temp->key==k)
		{
			return temp -> value;
		}	
		temp = temp -> next;
	}
	cout<<"\nDOES NOT EXIST.......AS THE FUNCTION RETURNS A REFERENCE OF ELEMENT AND AS THE ELEMENT DOES NOT EXIST THEREFORE SEGMATATION FAULT MAY OCCUR \n\n";

 }

template <typename K,typename V>
 int Number_Map <K,V> :: sizeofelement(const K& k)
 {
 	int size;
 	for(size=0;k[size]!='\0';size++);
 		//cout<<size;
 	return size;
 }

template <typename K,typename V>
 void Number_Map <K,V> :: print()
 {

 	//for(int i=0;i<12;i++)
 	/*{
 		cout<<"\nvalues of hash function "<<hash+1<<endl;
 		for(int j=0;j<m;j++)
 		{
 			if(array[hash][j] != NULL)
 			{
 				//cout<<"\t";
 				//cout<<"collisions "<<counter[i][j];
 				Node<K,V> *temp = array[hash][j];
 				while(temp != NULL)
 				{
 					cout<<temp -> value<<" | ";
 					temp = temp->next;
 				}
 				cout<<"\n\n";
 			}
 		}
 	}*/
 	for(int i=0;i<4;i++)
 	{
 		for(int j=0;j<3;j++)
 			cout<<counter[i][j]*100/size_hash<<" ";
 		cout<<"\n";
 	}
 }

template <typename K,typename V>
 void Number_Map <K,V>:: put(const K& k, const V& v)
 {
  //cout<<"herer";
 	size_hash++;
 	enter_component(k,v);
 	enter_polynomial(k,v);
 	enter_cyclicshift(k,v);
 	enter_integercasting(k,v);
 	//find_hash();
 	//cout<<"////////////////"<<endl;
 }

template <typename K,typename V>
 void Number_Map <K,V> :: enter_component(const K& k, const V& v)
 {
 	
 	unsigned int key;
 	int place;
 	key = componentsum(k);
 	//cout<<key<<endl;
 	place = division(key);
 	add(place,k,v,0,0);
 	place = mad(key);
 	add(place,k,v,1,1);
 	place = multiplication(key);
 	add(place,k,v,2,2);
 	//cout<<"\ncomponent over\n";
 }

template <typename K,typename V>
 void Number_Map <K,V> :: enter_polynomial(const K& k, const V& v)
 {
 	
 	unsigned int key;
 	int place;
 	key = polynomialsum(k);
 	//cout<<key<<endl;
 	place = division(key);
 	add(place,k,v,3,0);
 	place = mad(key);
 	add(place,k,v,4,1);
 	place = multiplication(key);
 	add(place,k,v,5,2);
 	//cout<<"\npolynomial over\n";
 }

template <typename K,typename V>
 void Number_Map <K,V> :: enter_cyclicshift(const K& k, const V& v)
 {
 	unsigned int key;
 	int place;
 	key = cyclicshift(k);
 	//cout<<key<<endl;
 	//cout << "main key is "<<key << endl;
 	place = division(key);
 	//cout << "key1 is "<< place <<endl;
 	add(place,k,v,6,0);
 	place = mad(key);
 	//cout << "key2 is "<< place <<endl;
 	add(place,k,v,7,1);
 	place = multiplication(key);
 	//cout << "key3 is "<< place <<endl;
 	add(place,k,v,8,2);
 	//cout<<"\ncyclic over\n";
 }

template <typename K,typename V>
 void Number_Map <K,V> :: enter_integercasting(const K& k, const V& v)
 {
 	unsigned int key;
 	int place;
 	key = integercasting(k);
 	//cout<<key<<endl;
 	//cout << "main key is "<<key << endl;
 	place = division(key);
 	//cout << "key1 is "<< place <<endl;
 	add(place,k,v,9,0);
 	place = mad(key);
 	//cout << "key2 is "<< place <<endl;
 	add(place,k,v,10,1);
 	place = multiplication(key);
 	//cout << "key3 is "<< place <<endl;
 	add(place,k,v,11,2);
 	//cout<<"\ncyclic over\n";
 }



template <typename K,typename V>
 unsigned int Number_Map <K,V>:: integercasting(const K& k)
 {
  int temp = (unsigned int)k;
  temp = temp & 0x7fff;
 	return temp;
 }

template <typename K,typename V>
 unsigned int Number_Map <K,V>:: componentsum(const K& k)
 {
 	unsigned int temp = k;
  temp += (k>>32); 	
  return temp;
 }
 
template <typename K,typename V>
 unsigned int Number_Map <K,V>:: polynomialsum(const K& k)
 {
 	unsigned int temp = k;
  temp *= 33;
  temp = (temp + (k>>32))*33;
 	return abs(temp);
 }

template <typename K,typename V>
 unsigned int Number_Map <K,V>:: cyclicshift(const K& k)
 {
 	unsigned int temp = k;
  temp = (temp << 5) | (temp >> 27);
 	unsigned int t = (k>>31);
  temp = temp + ((t << 5) | (t >> 27));
 	
 	return temp;
 }

//template <typename K,typename V>


template <typename K,typename V>
 int Number_Map <K,V>:: division(unsigned int key)
 {
 	int place = key%m;
 	//cout<<"place->"<<place<<endl;
 	return place;
 }

template <typename K,typename V>
 int Number_Map <K,V>:: mad(unsigned int key)
 {
 	long long int a,b;
 	a = 500001113;
 	b = 500001153;
 	int place = ((a*key+b)%4000037)%m;
 	//cout<<"place->"<<place<<endl;
 	return place;
 }

template <typename K,typename V>
 int Number_Map <K,V>:: multiplication(unsigned int key)
 {
 	double x = ((double)key*(sqrt(5.0)-1)/2);
 	double num = x - (long long int)x;
 	//cout<<x<<" "<<num;
 	int place = floor(num*pow(2,10));
 	place = place %m;
 	//cout<<"place->"<<place<<endl;
 	return place;
 }

template <typename K,typename V>
 void Number_Map <K,V> :: add(int place, const K& k, const V& v, int hash, int method)
 {
  //cout<<"came";
 	Node<K,V>  *temp = new Node<K,V>;
 	temp -> key = k;
 	temp -> value = v;
 	temp -> next = NULL;
 	if(array[hash][place] == NULL)
 	{
 		//cout<<temp->next<<"<- node next"<<endl;
 		array[hash][place] = temp;
 		//node -> next = NULL;
 		array[hash][place] -> next = NULL;
 		//cout<<array[hash][place] -> next<<"<- initial node"<<endl;
 	}
 	else
 	{
 		counter[hash/3][method]++;
 		//cout<<hash/3<<" "<<method<<" "<<counter[hash/3][method]<<endl;
 		//cout<<array[hash][place] -> next<<"<- initial node"<<endl;
 		Node<K,V> *temp1 = array[hash][place];
 		//cout<<temp1->value<<" "<<temp1 -> next <<"<- printing nullllllllll"<<endl;
 		//cout<<temp->next<<"<- node next"<<endl;
 		while(temp1->next != NULL)
 		{
 			//cout<<"\n"<<temp->next;
 			temp1 = temp1 -> next;
 		}
 		//cout<<temp->next<<"<- node next"<<endl;
 		temp1 -> next = temp;
 		temp -> next = NULL;
 	}
 }

#endif