#ifndef RESOURCE_H
#define RESOURCE_H
#include <iostream>
#include <unordered_set>

namespace {
    using namespace std;
    long long unsigned p_id_t;
    static const decltype (p_id_t) resource_not_exsists = 10;
    long long unsigned int p_id;
};

typedef decltype (p_id_t) ResourceKey;

struct Resource
{
    Resource();

    bool operator==(Resource const& rhs) {
        return getId() == rhs.getId();
    }

    bool operator==(ResourceKey const& rhs) {
        return getId() == rhs;
    }

    // for set
    bool operator <(Resource const& b) const {
        return getId() < b.getId();
    }

    ResourceKey getId() const;

    // Resource(Resource const &) = delete;

    Resource(Resource const &&);

    Resource(Resource const &) = default;
    //private:

    Resource(ResourceKey rk);
};

#endif // RESOURCE_H
