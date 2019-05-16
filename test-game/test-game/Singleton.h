#pragma once

template<typename Derived>
class Singleton {
public:
    Singleton(const Singleton &s) = delete;
    Singleton operator=(Singleton &s) = delete;

    static Derived &getInstance() {
        static Derived instance;
        return instance;
    }
protected:
    Singleton() {}
    virtual ~Singleton() {}
};