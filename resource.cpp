#include "resource.h"
#include <iostream>
static ResourceKey pp_id = 100;
ResourceKey pp_genId() {return ++pp_id; }

Resource::Resource()
{
    p_id = pp_genId();
    std::cout << __PRETTY_FUNCTION__ << ":" << p_id << endl;
}

unsigned long long Resource::getId() const
{
    std::cout << __PRETTY_FUNCTION__ << ":" << p_id << endl;
    return p_id;
}
