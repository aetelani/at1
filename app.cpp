#include "app.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

#include "statecharts/flow.h"

#define LOCK(MUTEX) lock_guard<mutex> lock(MUTEX);

namespace  {
    using  sc = sc_flow;
}

struct sc::user_model {
    int counter;
};

template<> void sc::state_actions<sc::state_Init>::enter(sc::data_model & m) {
    cout << "SC:" << __FUNCTION__ << endl;
}

template<> void sc::state_actions<sc::state_Running>::enter(sc::data_model & m) {
    cout << "SC Running:" << __FUNCTION__ << endl;
}


template<> void sc::state_actions<sc::state_Finalize>::enter(sc::data_model & m) {
    cout << "SC Finalize:" << __FUNCTION__ << endl;
}

template<> bool sc::transition_actions<&sc::state::event_Initiliazed, sc::state_Init, sc::state_Running>::condition(sc::data_model &m)
{
    cout << "SC Transition Init->Running:" << __FUNCTION__ << endl;
    return true;
}

template<> bool sc::transition_actions<&sc::state::event_Exiting, sc::state_Running, sc::state_Finalize>::condition(sc::data_model &m)
{
    cout << "SC Transition Running->Finalize:" << __FUNCTION__ << endl;
    return true;
}


template<> bool sc::transition_actions<&sc::state::unconditional, sc::state_Running>::condition(sc::data_model &m)
{
    m.user->counter++;
    cout << "SC Transition unconditial -> Running:" << __FUNCTION__ << m.user->counter << endl;
    return m.user->counter < 5;
}

namespace p {
    inline namespace sc {
        ::sc::user_model userModel;
    };
    mutex dataMutex;
    auto data = make_shared<set<Resource>>();
}

App::App()
{ 
    sc sc0(&p::userModel);
    sc0.init();
    sc::event
            e1{&sc::state::event_Initiliazed},
            e2{&sc::state::event_Exiting};
        sc0.dispatch(e1);
            do {
        sc0.dispatch(); // internal uncoditional transition blocks the external until returns true.
        sc0.dispatch(e2); // need to test if transition from Running is possible on every iteration OR push it to event queue beforehand
        // meaning queue isnt flushed. unconditional behaves likes uml a => b: event [condition] : actions
        // Considering something else than scxmlcc. like scxml cat.
    } while(sc0.model.In<sc::state_Running>());
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
