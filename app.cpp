#include "app.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;

#define LOCK(MUTEX) lock_guard<mutex> lock(MUTEX);

namespace p {
    mutex dataMutex;
    auto data = make_shared<set<Resource>>();
}

App::App()
{
}

void App::addResource(Resource r)
{
    LOCK(p::dataMutex)
    cout << "ThreadId:" << this_thread::get_id() << endl;
    p::data->insert(r);
}

void App::deleteResource(Resource r)
{
    LOCK(p::dataMutex)
    auto it = p::data->find(r);
    p::data->erase(it);
}

Resource App::getResource(ResourceKey k)
{
    LOCK(p::dataMutex)
    auto it = find_if(begin(*p::data), end(*p::data), [&k](auto const& j){
        cout << __FUNCTION__ << ":" << j.getId() << " == " << k << endl;
        return j.getId() == k;
    });

    if (it != p::data->end()) {
        cout << __FUNCTION__ << "found key" << endl;
        return *it;
    } else {
        return Resource{resource_not_exsists};
    }
}
