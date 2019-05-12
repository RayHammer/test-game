#pragma once
#include <string>

#include "Singleton.h"

template <typename Derived, typename T>
class ResourceManager : public Singleton<Derived>
{
public:
    
protected:
    virtual bool load(const std::string& path) { return false; }
private:
    ResourceManager() {};
    virtual ~ResourceManager() {};
};