// sharing information among threads, wainting for some operation to complete
// std::async, promise, future.
// would have been a complicated dance of globals and synchronisation otherwise
// futures and promises can't be copied, only moved. Just like threads.

#include <iostream>
#include <future>

int func(int i)
{
    return 2 * i;
}

int func_2(std::future<int>& ff)
{
    int x = ff.get();
    return 3 * x;
}

int main()
{
    // thread is a class. async is a function that returns an std::future,
    // that may or may not create a thread.
    std::future<int> fu = std::async(func, 4);
    // force thread by doing std::async(std::launch::async, func, 4); 
    // default setting is async | deferred. Whether a thread will be created will be determined by the implementation

    // get data from the child thread by:
    int x = fu.get();   // fu.get() can be called only once. call it again to crash the program
    std::cout << x << std::endl;

    // data in the opposite way?
    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::future<int> res = std::async(std::launch::async, func_2, std::ref(f));

    // some other code for our main thread
    p.set_value(4); // forgetting this i.e. breaking a promise will throw a broken promise exception
    x = res.get();

    std::cout << x << std::endl;

    return 0;
}

// for something like a broadcast by the parent thread to a lot of child threads, use 
// std::shared_future<int> sf = f.share();
// std::future<int> result_1 = std::async(func, sf);    // sahred_futures can be passed by value - copying allowed
// std::future<int> result_2 = std::async(func, sf);