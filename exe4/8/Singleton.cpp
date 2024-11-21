#include <iostream>
#include <mutex>

// Abstract Singleton Base Class
class Singleton {
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& getInstance() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!instance_) {
            instance_ = new DerivedSingleton();  
        }
        return *instance_;
    }

    virtual void someVirtualFunction() = 0; // Pure virtual function

protected:
    Singleton() = default;
    virtual ~Singleton() = default;

private:
    static Singleton* instance_;
    static std::mutex mutex_;
};

// Derived Singleton Class
class DerivedSingleton : public Singleton {
public:
    void someVirtualFunction() override {
        std::cout << "DerivedSingleton function running safely!" << std::endl;
    }
};

// Initialize static members
Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mutex_;

int main() {
    Singleton& instance = Singleton::getInstance();
    instance.someVirtualFunction();
    return 0;
}
