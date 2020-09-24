/* CS 162 Online Project 5
 * CarType.h
 * By: Blake Eakin
 * Date: 12/1/2018
 *
 * Defines the data structure model of a car entry into the database.
 */

 #include <iostream> 

#ifndef CARTYPE_H
#define CARTYPE_H

 enum Cat { US, Europe, Japan };

 class CarType {
	public:
	
	CarType();
	~CarType();
	CarType(const CarType&);
	CarType& operator= (const CarType&);
	friend std::ostream & operator<<(std::ostream&, const CarType&);
	void setName(char*);
	void setMPG(double);
	void setCylinders(int);
	void setDisplacement(double);
	void setHorsepower(double);
	void setWeight(double);
	void setAcceleration(double);
	void setModel(int);
	void setOrigin(Cat);
	void setIndex(int);
	char* getName();
	double getMPG();
	int getCylinders();
	double getDisplacement();
	double getHorsepower();
	double getWeight();
	double getAcceleration();
	int getModel();
	Cat getOrigin();
	int getIndex();


	private:
	
	char* carName;
	double mpg;
	int cylinders;
	double displacement;
	double horsepower;
	double weight;
	double acceleration;
	int model;
	Cat origin;
	int index;
 };

 #endif
