#pragma once

#include "Resource.hpp"
#include <memory>

class ResourceManager {
private:
    std::unique_ptr<Resource> resource;

public:
    ResourceManager() : resource(std::make_unique<Resource>()) {}

    double get() {
        return resource->get();
    }

    ResourceManager(const ResourceManager& other) 
        : resource(std::make_unique<Resource>(*other.resource)) {}

    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = std::make_unique<Resource>(*other.resource);
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept 
        : resource(std::move(other.resource)) {}

    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            resource = std::move(other.resource);
        }
        return *this;
    }

    ~ResourceManager() = default;
};