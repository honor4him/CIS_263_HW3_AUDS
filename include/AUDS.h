#include <iostream>
#include <cstdlib>
/********************************************************************
 * This is a generic data structure from the use of a template.
 * AUDS stands for almost useless data structure. When there isn't
 * enough space for data in the array, it resizes by adding 50% of
 * it's current size.
 *
 * @author Zachary Thomas
 * @version 1.0
 *******************************************************************/

template <typename T>

class AUDS{

public:

	/******************************************************************
	 * No parameter constructor to create the generic array.
	 *****************************************************************/
	AUDS(){
		data = new T[initialSize];
	}
	
	/******************************************************************
	 * Destructor deletes the generic array.
	 *****************************************************************/
	~AUDS(){
		delete[] data;
	}
	
	/******************************************************************
	 * Copy constructor copies another AUDS object to itself.
	 * @param other AUDS object.
	 *****************************************************************/
	AUDS(const AUDS &other){
		sizeNow = other.sizeNow;
		fullSize = other.fullSize;
		data = new T[fullSize];
		for(int i=0; i<sizeNow; i++){
 			data[i] = other.data[i];
 		}
	}

	/******************************************************************
	 * Copy operator creates another AUDS object the same as itself.
	 * @param other AUDS object.
	 *****************************************************************/
	AUDS& operator=(AUDS other){
		std::swap(sizeNow, other.sizeNow);
		std::swap(fullSize, other.fullSize);
		std::swap(data, other.data);
		return *this;
	}

	/******************************************************************
	 * Size function returns the size of the array.
	 * @return sizeNow The current size of the array.
	 *****************************************************************/
	int size(){
		return sizeNow;
	}

	/******************************************************************
	 * Push function. Adds data to structure and resizes if there is
	 * no more room for data.
	 * @param x A generic object to add to the data array.
	 *****************************************************************/
	void push(T x){
		if((sizeNow + 1) == fullSize){
			expandArray();
			data[sizeNow] = x;
			sizeNow++;
		}
		else{
			data[sizeNow] = x;
			sizeNow++;
		}	
	}
	
	/******************************************************************
	 * Pop function. Removes a random item from the list and moves the
	 * last item in the array to the spot where the element was 
	 * removed. Resizes by minus 1.
	 * Help from http://www.math.uaa.alaska.edu/~afkjm/csce211/
	 * handouts/RandomFunctions.pdf
	 * @return T A generic object.
	 *****************************************************************/
	T pop(){
		T temp;
		int random = (rand() % sizeNow) + 1;
		temp = data[random];
		data[random] = data[sizeNow];
		sizeNow--;
		return temp;
	}


private:
	
	/** The first size of the array*/
	int initialSize = 100;
	
	/** Holds the current size of the array*/
	int sizeNow = 0;
	
	/** Holds the full capacity of the array*/
	int fullSize = 100;
	
	/** Generic pointer for array*/
	T* data;

	/******************************************************************
	 * Expand array function is a helper function to expand the
	 * generic data array.
	 *****************************************************************/
	void expandArray(){
		fullSize = (int)(fullSize * 1.5);
		T* temp = new T[fullSize];
		for(int i=0; i<sizeNow; i++){
 			temp[i] = data[i];
 		}
		delete[] data;
		data = temp;
	}
	
};
