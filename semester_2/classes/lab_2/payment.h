class payment
{
	string fullName;
	double salary;
	int bonus;
public:
	payment()
	{
		fullName = "None";
		salary = 0;
		bonus = 0;
	}
	payment(string fullName, double salary, int bonus)
	{
		this->fullName = fullName;
		this->salary = salary;
		this->bonus = bonus;
	}
	payment(const payment& p)
	{
		fullName = p.fullName;
		salary = p.salary;
		bonus = p.bonus;
	}
	~payment(){}
	//selectors(getters)
	string getName()
	{
		return this->fullName;
	}
	double getSalary()
	{
		return this->salary;
	}
	int getBonus()
	{
		return this->bonus;
	}
	//modifiers(setters)
	void setName(string fullName)
	{
		this->fullName = fullName;
	}
	void setSalary(double salary)
	{
		this->salary = salary;
	}
	void setBonus(int bonus)
	{
		this->bonus = bonus;
	}
};
