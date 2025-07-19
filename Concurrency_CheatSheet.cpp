// C++ Concurrency Cheat Sheet
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>

/*
std::mutex (mutual exclusion) is a synchronization primitive that allows multiple threads to access shared resources safely.
It prevents race conditions, where multiple threads try to modify the same data simultaneously,
leading to unpredictable and incorrect results.
*/

void threadFunc() { /* work */ }

void concurrencyCheatSheet() {
    // 1. Thread Creation and Joining
    std::thread t(threadFunc);
    t.join();  // wait for thread to finish

    /*
    4. Atomic Operations : Thread-safe operations on primitive types (and some STL types)
    Safer and faster than using mutexes for simple operations
    Use atomic operations for lock-free programming
    */
    std::atomic<int> counter{0};
    counter.fetch_add(1);  // thread-safe increment
    // counter.fetch_add(1, std::memory_order_relaxed);

    // 5. Deadlock Avoidance
    // Use
    std::mutex m1, m2;
    std::lock(m1, m2);
    // then
    // std::lock_guard;
    // with
    std::adopt_lock;
}

// 2. Mutex and Locking
std::mutex mtx;

void thread_safe() {
    std::lock_guard<std::mutex> lock(mtx);  // RAII-style mutex locking
    // critical section
}

// 3. Condition Variables   : Used for thread communication, via signaling
std::condition_variable cv;
bool ready = false;

void wait_thread() {
    std::unique_lock<std::mutex> lock(mtx); // Flexible locking
    cv.wait(lock, []{ return ready; });
    std::cout << "Worker thread activated!\n";
    // proceed when ready

    // You can lock/unlock std::unique_lock explicitly, useful for use with condition_variable
    lock.unlock();
    lock.lock();
}

void signal_thread() {
    std::thread t(wait_thread);
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
    t.join();
}

// 4. std::mutex and std::lock_guard   : Used to synchronize access to shared data
// std::mutex mtx;
int counter = 0;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);  // RAII-style mutex locking
        ++counter;
    }
}

// 5. Run functions asynchronously and get results
int compute() {
    return 42;
}

// 6. std::promise : Manually set the value for a future
void worker(std::promise<int>& p) {
    p.set_value(42);
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << "Counter: " << counter << "\n";

    /*
    std::future is a placeholder for a result, retrieve async results
    std::async can launch a function in a separate thread or defer execution, asynchronous function execution
    */
    std::future<int> result = std::async(std::launch::async, compute);
    std::cout << "Result: " << result.get() << "\n";

    std::promise<int> p;    // Set values to futures manually
    std::future<int> f = p.get_future();
    std::thread t(worker, std::ref(p));
    std::cout << "Result: " << f.get() << "\n";
    t.join();
}