#pragma once
#include <string>

template <typename T>
class ResourceManager
{
public:
    ResourceManager() {};
    virtual ~ResourceManager() {};
protected:
    virtual bool load(const std::string& path) = 0;
};