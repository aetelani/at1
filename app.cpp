#include "app.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;

#define LOCK(MUTEX) lock_guard<mutex> lock(MUTEX);

namespace  {
    mutex dataMutex;
    auto data = make_shared<set<Resource>>();
}

App::App()
{
}

void App::addResource(Resource r)
{
    LOCK(dataMutex)
    cout << "ThreadId:" << this_thread::get_id() << endl;
    data->insert(r);
}

void App::deleteResource(Resource r)
{
    LOCK(dataMutex)
    auto it = data->find(r);
    data->erase(it);
}

Resource App::getResource(ResourceKey k)
{
    LOCK(dataMutex)
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
