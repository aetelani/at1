#include "app.h"
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

set<Resource> data;

App::App()
{
}

void App::addResource(Resource r)
{
    data.insert(r);
}

void App::deleteResource(Resource r)
{
    auto it = data.find(r);
    data.erase(it);
}

Resource App::getResource(ResourceKey k)
{
    find_if(begin(data), end(data), [&k](auto const& j){
        return j.getId() == k;
    });
    Resource r{};
    r.p_id = 0;
    return r;
}
