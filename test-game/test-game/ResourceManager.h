#pragma once
#include <string>

#include "Singleton.h"

template <typename Derived, typename T>
class ResourceManager : public Singleton<Derived>
{
public:
    ResourceManager() {};
    virtual ~ResourceManager() {};
protected:
    virtual bool load(const std::string& path) { return false; }
private:

};