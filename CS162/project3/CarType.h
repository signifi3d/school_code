/* CS 162 Online Project 3
 * CarType.h
 * By: Blake Eakin
 * Date: 10/15/2018
 *
 * Defines the data structure model of a car entry into the database.
 */
#ifndef CARTYPE_H
#define CARTYPE_H

 enum Cat { US, Europe, Japan };

 class CarType {
	public:
	
	CarType();
	void setName(char*);
	void setMPG(double);
	void setCylinders(int);
	void setDisplacement(double);
	void setHorsepower(double);
	void setWeight(double);
	void setAcceleration(double);
	void setModel(int);
	void setOrigin(Cat);
	char* getName();
	double getMPG();
	int getCylinders();
	double getDisplacement();
	double getHorsepower();
	double getWeight();
	double getAcceleration();
	int getModel();
	Cat getOrigin();


	private:
	
	char carName[50];
	double mpg;
	int cylinders;
	double displacement;
	double horsepower;
	double weight;
	double acceleration;
	int model;
	Cat origin;
 };

 #endif
