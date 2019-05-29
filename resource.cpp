#include "resource.h"
#include <iostream>

using namespace std;

static ResourceKey pp_id = 100;
ResourceKey pp_genId() {return ++pp_id; }

Resource::Resource()
{
    //cout << __FUNCTION__ << ":" << p_id << endl;
    p_id = pp_genId();
}

Resource::Resource(const Resource && r)
{
    pp_id = r.getId();
}

unsigned long long Resource::getId() const
{
    //cout << __FUNCTION__ << ":" << p_id << endl;
    return p_id;
}
