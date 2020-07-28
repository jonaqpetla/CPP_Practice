// Dijkstra.cpp : Implements dijkstra in a weighted bidirectional graph
// need a priority queue. The alogirthm ends when the destination is on top of the priority queue
// also, the queue memebers/nodes need to have their "came from" field populated if we are to find the way back

// dijkstra takes in arguments:
// start node, end node, number of nodes, array* of nodes, array** connection map
// returns int min dist and also edits the array* nodes if you want the path info

#include <iostream>
using namespace std;

class Node	//not graph node. just a barebones queue structure
{
	int nodeName;
	int cameFrom;
	int distance;
	Node* next;	// next in queue, when in queue
public:
	Node()
	{
		nodeName = cameFrom = -1;
		distance = 2147483647; // infinity basically. some implementations use <limits.h> for this number
		next = nullptr;
	}

	void setName(int n) { nodeName = n; }
	void setFrom(int from) { cameFrom = from; }
	void setDist(int d) { distance = d; }
	void setNext(Node* n) { next = n; }

	int getName() { return nodeName; }
	int getFrom() { return cameFrom; }
	int getDist() { return distance; }
	// getNext is unnecessary

	Node* insert(Node* vertex)	// complete the priority queue pls
	{
		if (vertex->distance < distance) // new guy in front of me
		{
			vertex->next = this;
			return vertex;
		}
		else if (vertex->distance >= distance && (next == nullptr || next->distance > vertex->distance)) // sht ckt
		{
			vertex->next = next;
			next = vertex;
			return this;
		}
		else // new goes further down the line. not my problem
		{
			next->insert(vertex);
			return this;
		}
	}

	Node* pop() { return next; }
};

// queue is basically a Node*. 

int dijkstra(int , int , int , int* , Node* ); //defined after main()

int main()
{
	//capture the data
    cout << "Number of nodes: ";
	int n = 0;
	cin >> n;

	cout << "Enter number of edges: ";
	int e = 0;
	cin >> e;

	int* connectionMap = new int[n*n];
	for (int i = 0; i < n*n; i++)
		connectionMap[i] = 0;
	cout << "Enter the edges and weights (Nodes are 0 to " << n-1 << "): ";
	for (int i = 0; i < e; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;

		//input sanitization lol
		if (start >= n || end >= n)
		{
			cout << "Fuk u bich";
			return 0;
		}

		connectionMap[n*start + end] = weight;
		connectionMap[n*end + start] = weight;	//connection[start][end] is flipped on
	}

	cout << "Enter start and destination nodes: ";
	int start, end;
	cin >> start >> end;

	// This is the start of the algorithm
	Node* nodes = new Node[n];
	for (int i = 0; i < n; i++)
		nodes[i].setName(i);

	cout << "The shortest distance is: " << dijkstra(start, end, n, connectionMap, nodes) << endl;
	
	//messy stuff
	int tracker = end;
	while(tracker != start)
	{
		cout << tracker << " ";
		tracker = nodes[tracker].getFrom();
	}

	delete[] nodes;
	// clean up and end the alogorithm

	return 0;
}

int dijkstra(int start, int end, int n, int* connectionMap, Node* nodes)
{
	nodes[start].setDist(0);
	Node* queue = &nodes[start];

	bool doneFlag = false;
	while (!doneFlag)
	{
		// check the member on top of the queue. pop.
		int now = 0;
		if (queue != nullptr)
		{
			now = queue->getName();
		}
		else
		{
			doneFlag = true;
			break;
		}

		if (now == end)
		{
			return nodes[end].getDist();
		}

		// set its neighbours' distances and cameFrom. push into the queue
		for (int i = 0; i < n; i++)
		{
			if (i != now && connectionMap[n*now + i] != 0 
				&& nodes[i].getDist() > nodes[now].getDist()+connectionMap[n*now + i])
			{
				nodes[i].setDist(nodes[now].getDist() + connectionMap[n*now + i]);
				nodes[i].setFrom(now);
				queue = queue->insert(&nodes[i]);
			}
		}
		queue = queue->pop();
		//break when the top is the destination
	}


	return 0; // we couldn't find a path
}