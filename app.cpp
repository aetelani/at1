#include "app.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <memory>

using namespace std;

namespace  {
    auto data = make_shared<set<Resource>>();
}

App::App()
{
}

void App::addResource(Resource r)
{
    data->insert(r);
}

void App::deleteResource(Resource r)
{
    auto it = data->find(r);
    data->erase(it);
}

Resource App::getResource(ResourceKey k)
{
    auto it = find_if(begin(*data), end(*data), [&k](auto const& j){
        cout << __FUNCTION__ << ":" << j.getId() << " == " << k << endl;
        return j.getId() == k;
    });

    if (it != data->end()) {
        cout << __FUNCTION__ << "found key" << endl;
        return *it;
    } else {
        return Resource{resource_not_exsists};
    }
}
