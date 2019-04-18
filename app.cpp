#include "app.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;

#define LOCK(MUTEX) lock_guard<mutex> lock(MUTEX);

namespace P {
    mutex dataMutex;
    static auto data = make_shared<set<Resource>>();
}

App::App()
{
}

void App::addResource(Resource r)
{
    LOCK(P::dataMutex)
    cout << "ThreadId:" << this_thread::get_id() << endl;
    P::data->insert(r);
}

void App::deleteResource(Resource r)
{
    LOCK(P::dataMutex)
    auto it = P::data->find(r);
    P::data->erase(it);
}

Resource App::getResource(ResourceKey k)
{
    LOCK(P::dataMutex)
    auto it = find_if(begin(*P::data), end(*P::data), [&k](auto const& j){
        cout << __FUNCTION__ << ":" << j.getId() << " == " << k << endl;
        return j.getId() == k;
    });

    if (it != P::data->end()) {
        cout << __FUNCTION__ << "found key" << endl;
        return *it;
    } else {
        return Resource{resource_not_exsists};
    }
}
