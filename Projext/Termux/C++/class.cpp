#include <iostream>

class BankAccount
{
	public:
		BankAccount()
		{
			sayHi();
		}
		void sayHi()
		{
			std::cout << "Hi" << std::endl;
		}
		~BankAccount()
		{
			sayHi();
		}
};


int main(void)
{

	BankAccount *bank;

	bank->sayHi();
	
	return 0;
}