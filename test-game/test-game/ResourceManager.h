#pragma once
#include <string>

template <typename Derived, typename T>
class ResourceManager
{
public:
    ResourceManager() {};
    virtual ~ResourceManager() {};
    ResourceManager(const ResourceManager& resourceManager) = delete;
    ResourceManager operator=(ResourceManager& resourceManager) = delete;

    static Derived& getInstance() {
        static Derived instance;
        return instance;
    }
protected:
    virtual bool load(const std::string& path) = 0;
private:

};