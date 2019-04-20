#ifndef RESOURCE_H
#define RESOURCE_H
#include <iostream>
#include <unordered_set>

namespace {
    using namespace std;
    long long unsigned p_id_t;
    static const decltype (p_id_t) resource_not_exsists = 10;
};

typedef decltype (p_id_t) ResourceKey;

struct Resource
{
    Resource();

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
        cout << __FUNCTION__ << ":" << rk << endl;
        p_id = rk;
    }
};

#endif // RESOURCE_H
