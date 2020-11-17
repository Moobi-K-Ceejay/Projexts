#include <iostream>

class Enemy
{
	protected:
		int attackPower;
	public:
		void setAttackPower(int power)
		{
			attackPower = power;
		}
		virtual void attack() = 0;
			
};

class Ninja : public Enemy
{
	public:
		void attack()
		{
			std::cout << "Ninja -" << attackPower << std::endl;
		}
};

class Monster : public Enemy
{
	public:
		void attack()
		{
			std::cout << "Monster -" << attackPower << std::endl;
		}
};
int main(void)
{
	Ninja n;
	Monster m;
	
	Enemy *e1 = &n;
	Enemy *e2 = &m;

	e1->setAttackPower(36);
	e2->setAttackPower(3);

	e1->attack();
	e2->attack();
	
	return 0;
}
