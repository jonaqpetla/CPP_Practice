// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//not using namespace std because that obscures some stuff
//the threads communicate using a shared memory here

#include "pch.h"
#include <iostream>
#include <thread>

bool release = false;

void functionA()
{
	using namespace std::literals::chrono_literals;
	
	std::cout << "Started thred id = " << std::this_thread::get_id() << std::endl;
	
	while (!release)
	{
		std::cout << "Working...\n";
		std::this_thread::sleep_for(500ms);	//won't understand 1s without chrono literals
	}
}

int main()
{
	//make a thread, run a function
	std::thread worker(functionA);	//that's a function pointer we passed right here

	std::cin.get();					//press enter to proceed
	release = true;					//now the worker will go to the end of function

	//wait for the worker thread to join the main
	worker.join();
	std::cout << "Worker has joined the main thread = " << std::this_thread::get_id() << std::endl;
	return 0;
}

//optionally we could have used worker.detach() to let the worker thread run freely
//it is then called a daemon
//there is a chance that the main thread will finish executing before worker finishes,
//and that will  end our program. but worker thread will keep runing. probably till we shut our PC down
//join or detach can only happen once

//you can pass values to the thread as thread worker(function, value);
//the value will always be passes by value, and never by reference. pointers work tho.

//we shouldn't have more threads than cores in our CPU. That's called oversubscription.
//oversubscription causes performance detriments
// std::thread::hardware_concurrency(); //indicates the number of cores I have

//Avoid Data Race (thwo threads racing for cout for example)
//use std::mutex to protect shared resources while being used