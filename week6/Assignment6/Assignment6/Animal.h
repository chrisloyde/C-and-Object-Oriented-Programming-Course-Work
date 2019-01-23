#pragma once
class Animal {
public:
	enum types { hare, tortoise, und };
	Animal();
	void setPos(int p, int d);
	int getPos();
	void setType(types t);
	types getType();


	~Animal();
private:
	int pos;
	types type;
};

