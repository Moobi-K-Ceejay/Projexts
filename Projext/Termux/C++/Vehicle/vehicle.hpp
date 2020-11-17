#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>


class Vehicle
{
	protected:
		static std::string made;
		std::string model;
		std::string color;
		int year;
		int wheelsNo;
		int speed;
	public:
		void setSpeed(int speed)
		{
			speed += speed;
		}
		virtual void startEngine() = 0;
		virtual void stopEngine() = 0;
		virtual void hitGas() = 0;
		virtual void hitBrackes() = 0;
		
	
};
class MotorBike : public Vehicle
{
	public:
		MotorBike(std::string made,std::string model, std::string color, int year,int wheels);
		~MotorBike();
		
};
class Car : public Vehicle
{
	public:
		Car();
		~Car();
			
};

#endif // VEHICLE_HPP