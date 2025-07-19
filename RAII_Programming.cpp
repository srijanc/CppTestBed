/*
RAII (Resource Acquisition Is Initialization) can be summarized as follows:

1. encapsulate each resource into a class, where
    a. the constructor acquires the resource and establishes all class invariants or throws an exception if that cannot be done,
    b. the destructor releases the resource and never throws exceptions;
2. always use the resource via an instance of a RAII-class that either
    a. has automatic storage duration or temporary lifetime itself, or
    b. has lifetime that is bounded by the lifetime of an automatic or temporary object.

Move semantics enable the transfer of resources and ownership between objects,
inside and outside containers, and across threads, while ensuring resource safety.
*/
#include <mutex>

std::mutex m;

bool everything_ok() {
    return false;
}

void f() {
    /* Something */
}

void bad() {
    m.lock();             // acquire the mutex
    f();                  // if f() throws an exception, the mutex is never released
    if (!everything_ok())
        return;           // early return, the mutex is never released
    m.unlock();           // if bad() reaches this statement, the mutex is released
}

void good() {
    std::lock_guard<std::mutex> lk(m); // RAII class: mutex acquisition is initialization
    f();                               // if f() throws an exception, the mutex is released
    if (!everything_ok())
        return;                        // early return, the mutex is released
}                                      // if good() returns normally, the mutex is released