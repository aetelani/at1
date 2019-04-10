#ifndef RESOURCE_H
#define RESOURCE_H

#include <unordered_set>

using namespace  std;

namespace {
    long long unsigned p_id_t;
    static const decltype (p_id_t) resource_not_exsists = 0;
};

typedef decltype (p_id_t) ResourceKey;

struct Resource
{
    Resource();

    // hash for unordered set
    inline size_t operator()() const {
        return hash<decltype (p_id)>{}(p_id);
    }

    bool operator==(Resource const& rhs) {
        return p_id == rhs.getId();
    }

    bool operator==(ResourceKey const& rhs) {
        return p_id == rhs;
    }

    // for set
    bool operator <(Resource const& b) const {
        return p_id < b.getId();
    }

    ResourceKey getId() const;

    //private:
    long long unsigned int p_id;

    Resource(ResourceKey rk) {
        p_id = rk;
    }
};

static const Resource ResourceNotExsists{resource_not_exsists};

#endif // RESOURCE_H
