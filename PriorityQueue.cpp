// Need priority queue for Dijkstra. Thought I'd complete it here.
// Each node could be an object with a public value. It enters the linked list in a sorted manner.
// Queue is another object. It has Nodes as members. Here the nodes are just ints.

#include <iostream>

class Queue
{
	int n;
	Queue* next;
public:
	Queue()
	{
		n = 0;
		next = nullptr;
	}
	Queue(int num)
	{
		n = num;
		next = NULL;
	}

	void set(int num)
	{
		n = num;
	}

	int get(int i)
	{
		if (i == 0)
			return n;
		else return (*next).get(i - 1);
	}

	Queue* insert(Queue* entry)
	{
		if (entry->n < n) // I'll scoot over and return this guy's address
		{
			entry->next = this;
			return entry;
		}
		else if (entry->n >= n && entry->n < (*next).n)	// insert right after me and take my adress
		{
			entry->next = next;
			next = entry;
			return this;
		}
		else
		{
			(*next).insert(entry); // not my problem. kick the can down the road
			return this;
		}
	}

	Queue* pop()
	{
		return next;
	}
};

int main()
{
	std::cout << "Enter the number of values, less than 1000 pls: ";
	int n;
	std::cin >> n;

	Queue entries[1000];	// hard coded cuz we want to keep stuff in the stack

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		std::cin >> temp;
		entries[i].set(temp);
	}

	// Make a queue.
	Queue* queue = &entries[0];

	for (int i = 1; i < n; i++)
	{
		queue = (*queue).insert(&entries[i]);
	}

	// print the current queue:
	for (int i = 0; i < n; i++)
	{
		std::cout << (*queue).get(i) << " ";
	}

	return 0;
}