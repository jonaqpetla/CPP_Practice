// Dijkstra.cpp : Implements dijkstra in a weighted bidirectional graph
//we'll have to redo this later. This one's a mess.
// need a priority queue. The alogirthm ends when the destination is on top of the priority queue
// also, the queue memebers/nodes need to have their "came from" field populated
// 

#include "pch.h"
#include <iostream>
using namespace std;

class Node	//not graph node. just a barebones queue structure
{
	int nodeNumber;
	Node* next;
public:
	Node() = delete;
	Node(int n)
	{
		nodeNumber = n;
		next = nullptr;
	}

	int getValue()
	{
		return nodeNumber;
	}

	bool pushNode(Node* n)
	{
		if (next == nullptr)
			next = n;
		else
			(*next).pushNode(n);
	}

	Node* popNode()
	{
		return next;
	}
};

// class queue not even needed
int dijkstra(int , int , int , int* ); //defined after main()

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

	/*
	//print the captured data pls
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << connectionMap[n*i + j] << " ";
		}
		cout << endl;
	}
	*/

	cout << "Enter start and destination nodes: ";
	int start, end;
	cin >> start >> end;

	cout << "The shortest distance is: " << dijkstra(start, end, n, connectionMap);

	return 0;
}

int dijkstra(int start, int end, int n, int* connectionMap)
{
	int* distances = new int[n];
	distances[start] = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == start)
			distances[i] = 0;
		else distances[i] = 10000000000; // max int really
	}

	Node queue(start);	// starting the queue in stack
	//a list of all nodes. we'll link up as necessary
	Node vertices = new Node(0)[n];
	while (unfinished)	// ========================================= NEEDS RECHECKING ===========
	{
		// current node is:
		int nodeNow = queue.getValue();

		// find the places we can go from here
		for (int i = 0; i < n; i++)
		{
			if (connectionMap[n*nodeNow + i] != 0)
			{
				int distance = distances[start] + connectionMap[n*nodeNow + i];
				if (distance < distances[i])
				{
					distances[i] = distance;
					queue.pushNode();	//can't create node, it'll go out of scope
				}
			}
		}
		//update distances to that place, and add the place to the queue

	}
	// return the distance value on the end node
	return 1;
}