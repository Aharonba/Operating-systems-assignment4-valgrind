#include <iostream>
#include <mutex>


class Guard {
public:
    explicit Guard(std::mutex& mtx) : mutex_(mtx) {
        mutex_.lock();  // Lock the mutex upon construction
    }

    ~Guard() {
        mutex_.unlock();  // Unlock the mutex upon destruction
    }

private:
    std::mutex& mutex_;  // Reference to the mutex being guarded
    // Prevent copying to ensure only one instance holds the lock
    Guard(const Guard&) = delete;
    Guard& operator=(const Guard&) = delete;
};
