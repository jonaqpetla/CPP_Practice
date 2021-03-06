#include <iostream>

class Linked
{
	float data;
	Linked* next;
	Linked* prev;

	void insertHelper(Linked* pt)
	{
		pt->next = next;
		pt->prev = this;
		next->setPrev(pt);
	}

public:
	Linked()
	{
		data = 0;
		next = nullptr;
		prev = nullptr;
	}

	void setPrev(Linked* p)
	{
		prev = p;
	}

	bool set(int loc, float d)
	{
		bool res = false;
		if (loc == 0)
		{
			data = d;
			res = true;
		}
		else if (loc > 0)
		{
			res = (*next).set(loc - 1, d);
		}
		return res;
	}

	float get(int loc)
	{
		if (loc == 0)
			return data;
		else if (loc > 0)
			return (*next).get(loc - 1);
		else return 0;
	}

	bool link(Linked* first, Linked* second)
	{
		(*first).next = second;
		(*second).prev = first;
		return true;
	}

	int length()
	{
		if (next != nullptr)
			return (*next).length() + 1;
		else return 1;
	}

	bool insert(int i, Linked* pt)		//will be called using the first member. insert after ith element
	{
		if (i == 0)
		{
			insertHelper(pt);
			next = pt;
		}
		else if (next != nullptr)
			(*next).insert(i - 1, pt);

		return true;
	}
};

int main()
{
    std::cout << "Linked list implememntation. Nothing to see on console; look at the code.\n";

	Linked oneOfThem;
	Linked secondOfThem;
	Linked thirdOfThem;

	oneOfThem.link(&oneOfThem, &secondOfThem);
	secondOfThem.link(&secondOfThem, &thirdOfThem);

	Linked* list = &oneOfThem;

	(*list).set(0, 12);
	(*list).set(1, 45);
	(*list).set(2, 31);

	for (int i = 0; i < 3; i++)
	{
		std::cout << list->get(i) << " ";
	}
	std::cout << list->length();

	Linked rogue;
	rogue.set(0, 78);

	list->insert(1, &rogue);

	std::cout << "\nModified list: ";
	for (int i = 0; i < list->length(); i++)
	{
		std::cout << list->get(i) << " ";
	}

	//we're setting the prev properly. Just a few modifications will get us a doubly linked list.
	//we're choosing to keep the damn thing linear. linking up to make circular is not difficult.
	//sorting a linked list in another try

	return 0;
}