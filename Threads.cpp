#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>

int getRandom(int max)
{
    srand(time(NULL));
    return rand() % max;
}

void sleeperThread(int id)
{
    // commented lines worked fine on Ubuntu. Gotta fix later maybe
    auto nowTime = std::chrono::system_clock::now();
    //std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);    
    auto sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    //tm localTime = *localtime(&sleepTime);

    //std::cout << "Thread: " << id << ". Sleep time: " << std::ctime(&sleepTime); 

    std::this_thread::sleep_for(std::chrono::seconds(getRandom(3)));

    nowTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    //localTime = *localtime(&sleepTime);

    //std::cout << "Thread: " << id << ". Awake time: " << std::ctime(&sleepTime);
}

int accountBalance = 100;
std::mutex accLock;

void drainMoney(int id, double withdrawal)
{
    // not exception safe, so we don't use this:
    // accLock.lock();
    // our code here
    // accLock.unlock();
    // 'our code' section cannot be accessed by other threads while lock is on
    // way to make sure other threads don't access shared resources while the operation is ongoing

    std::lock_guard<std::mutex> lock(accLock);  // unlocked as soon as this goes out of scope/destroyed
    // use unique_lock instead for finer grained control

    std::cout << "Hacker " << id << " trying to withdraw $" << withdrawal << std::endl;
    if (accountBalance - withdrawal >= 0)
        accountBalance -= withdrawal;
    std::cout << "Current account balance is " << accountBalance << std::endl;

    // we protected cout (ostream) and accountbalance from 
    // getting accessed simultaneously by multiple threads

    // cout is a global resource though, and others may use it from other functions etc.
    // safer code would be to create a dedicated fstream and protect it
    // other programmers are unlikely to mess with your plan that way
}


int main()
{
    std::cout << "Your system supports " << std::thread::hardware_concurrency() << " threads." << std::endl;
    // just some lazy threads
    std::thread th1(sleeperThread, 1);
    std::thread th2(sleeperThread, 2);
    // race condition for cout - likely ugly output
    th1.join();
    th2.join();

    std::cout << "Main thread's id is " << std::this_thread::get_id() << std::endl;
    // th1.get_id() to get th1's id

    // 10 hackers try to drain a bank account:
    // these aren't going to execute sequentially. it can be 5 then 1 then 10 then 2 etc

    std::thread pool[10];
    for (int i = 0; i < 10; i++)
        pool[i] = std::thread(drainMoney, i, 15);

    // let's wait till they are done looting
    for (int i = 0; i < 10; i++)
        pool[i].join();

    return 0;
}


// parameters to a thread constructor are always passed by value, even if you try to pass as references
// can cheat this by using a reference wrapper: std::ref(object we want to pass), or just pointers
// a more efficient way to share resource is to use std::move(object)
// threads themselves can only be moved, and not copied:
// std::thread th3 = th1; doesn't compile. std::thread th4 = std::move(th1); does 
// If main doesn't need the stuff, move it - safe & efficient

// th1.detach(); // to make th1 independednt from main thread. it becomes a daemon process,
// detached threads cannot be joined later. no changing of mind.
// daemon process might keep running till your system us shut down
// if (th1.joinable()) ... th1.join();  // checking is possible

// if your don't join or detach a thread and it goes out of scope, it will be destroyed

// don't create more threads than your hardware can support. It's called uversubscription.
// int best = std::thread::hardware_concurrency();
// too much thread switching = context switching - degrades performance

// multiple mutexes can cause deadlock situations:
// e.g. both threads waiting for the other thread to release a mutex to lock the other mutex
// solution: manually make sure the locks are in the same order. Or a better solution:
// std::lock(mu1, mu2); // locking done by C++, avoiding certain deadlock situations
// std::lock_guard<mutex> locker(mu1, std::adopt_lock); // lock already exists, adopt it
// std::lock_guard<mutex> locker(mu2, std::adopt_lock);

// std::unique_lock<mutex> locker(mu);
// code
// locker.unlock(); // for finer grained control
// std::unique_lock<mutex> locker(mu, std::defer_lock); // to make a lock without locking it now
// then an arbirary number of locker.lock() and locker.unlock() calls - unlike lock_guard
// wrapper cast of mutexes cannot be copied, but unique_locks can be moved
// if unique_lock is so much better, why not use it in all use cases?
// because unique_lock is heavy - more bookkeeping. 
// If you don't need the fleibility, lock_guard is better, for performance's sake

// sometimes we want to call a function only once (e.g. open a file once)
// a good way to do that is by using once_flag:
// std::once_flag _flag;
// std::call_once(_flag, function);

// sometimes we want to wait till one thread is done processing some data, before we consume it
// instead of checking if empty again and again, or hard coding delays after a fail
// use std::condition_variable
// std::condition_variable cond;
// cond.notify_one();   // wake up one waiting thread, if there is one
// cond.wait(lock);     // wait, why pass a lock_guard to the wait()??
// bad to sleep while keeping a mutex locked
// wait() will unlock the mutex while waiting, and lock it back once the flag comes in
// we still have to unlock the mutex at the end of our code execution
// because we are locking anf unlocking many times, we have to use unique_lock in this use case
// can also do cond.wait(lock, perdicate); // to make sure we don't wake ourselved up
// norify_all() to wake up all threads instead

// threads, mutex locks, waits can be time constrained using <chrono> stuff. 
// sleep_for, wait_for, wait_until etc.
// thread_1.sleep_for(chrono::milliseconds(50));
// chrono::steady_clock::time_point tp = chrono::steady_clock::now() + chrono::microseconds(4);
// std::this_thread.sleep_until(tp);

// related topics: std::bind & std::function, packaged_task 