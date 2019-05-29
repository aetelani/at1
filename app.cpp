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
    using sc = class sc_flow;
}
struct sc::user_model {
    int counter;
    Resource resource;
};

template<> void sc::state_actions<sc::state_Running>::enter(sc::data_model & m) {
    cout << "SC::Running::" << __FUNCTION__ << endl;
}


template<> void sc::state_actions<sc::state_Stopped>::enter(sc::data_model & m) {
    cout << "SC::Stopped:::" << __FUNCTION__ << endl;
}

template<> bool sc::transition_actions<&sc::state::unconditional, sc::state_Running>::condition(sc::data_model &m)
{
    m.user->counter++;
    cout << "SC Transition unconditial -> Running:" << __FUNCTION__ << m.user->counter << endl;
    return m.user->counter < 5;
}

namespace p {
    namespace {
        ::sc::user_model userModel;
        mutex dataMutex;
        auto data = make_shared<set<Resource>>();
    };
    sc sc0(&p::userModel);
}

App::App()
{ 
    p::sc0.init();
    sc::event exit{&sc::state::event_exit};
}

void App::run()  {
    //do {
        p::sc0.dispatch(); // internal uncoditional transition blocks the external until returns true.
        // need to test if transition from Running is possible on every iteration OR push it to event queue beforehand
        // meaning queue isnt flushed. unconditional behaves likes uml a => b: event [condition] : actions
        // Considering something else than scxmlcc. like scxml cat.;
    //} while(!p::sc0.model.In<sc::state_Stopped>());

   if (p::sc0.model.In<sc::state_Stopped>()) throw new exception();
}
void App::addResource(Resource r)
{
    LOCK(p::dataMutex)
    cout << "ThreadId:" << this_thread::get_id() << endl;
    p::data->insert(move(r));
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
        return move(Resource{resource_not_exsists});
    }
}
