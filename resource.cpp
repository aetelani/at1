#include "resource.h"

namespace p {
    #include <iostream>
    using std::cout;
    static ResourceKey id = 100;
    ResourceKey genId() { return ++id; }
    void setId(ResourceKey k) { id = k; }
}

using namespace p;

Resource::Resource()
{
    //cout << __FUNCTION__ << ":" << p_id << endl;
    ResourceKey t = genId();
    setId(t);
}

Resource::Resource(const Resource && r)
{
    ResourceKey t = r.getId();
    setId(t);
}

unsigned long long Resource::getId() const
{
    cout << __FUNCTION__ << ":" << p_id << endl;
    return id;
}

Resource::Resource(ResourceKey rk) {
    cout << __FUNCTION__ << ":" << rk << endl;
    setId(rk);
}

namespace test {

}
