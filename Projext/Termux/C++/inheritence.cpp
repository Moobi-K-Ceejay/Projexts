#include <iostream>


class Vehicle
{
	private:

	protected:
		std::string model;
		std::string color;
		int wheels;
		int year;
	public:
		Vehicle()
		{
			std::cout << "Vehicle" << std::endl;
		}
		void startEngine()
		{
			std::cout << "Engine Started..." << std::endl;
		}
};

class Truck : public Vehicle
{
	private:

	protected:

	public:
		Truck()
		{
			std::cout << "Truck Class" << std::endl;
		}
		
};

int main(void)
{
	Truck t;
	t.startEngine();
	
	return 0;
}
