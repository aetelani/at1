#include "resource.h"
#include <iostream>
#include <memory>
#include <functional>
#include <typeinfo>
#include <list>
#include <algorithm>
#include <iterator>

namespace p {
    using
        std::cout,
        std::shared_ptr,
        std::unique_ptr,
        std::make_unique,
        std::make_shared,
        std::mem_fn,
        std::begin,
        std::end,
        std::copy,
        std::ostream_iterator
        ;

struct Re {
    int i;
    int j;
    string shoo;
};

template<typename ... T>
struct R
{
    vector<int> resvec;
    template<typename S>
    auto getVec(T ... args) {
        return vector<S>{args...};
    }
    R() = default;
    R(T ... args) {
        const int size = sizeof...(args) + 2;
        std::cout << "Size is: " << size << endl;
        int res[size] = {1,args...,2};
        resvec = getVec<int>(args...);
        cout << "RESVEC size: " << resvec.size() << endl;
    }
    R(R&) = default;
    R(R&&) = default;
};

//template<typename T>
//Sharedd<T>::Sharedd() {};

    static ResourceKey id = 100;

    ResourceKey genId() { return ++id; }
    void setId(ResourceKey k) { id = k; }
#define D(x) do { cout << __FUNCTION__ << ":" << x << endl; } while (0);
}

using namespace p;
void bar() {
    D("here")
};
Resource::Resource()
{
    //cout << __FUNCTION__ << ":" << p_id << endl;
    auto op = make_optional<vector<int>>(4,42);
    auto foo = make_unique<R<int>>(10);
    auto f = R{1, 2, 3, 4};
    auto li = list<int>{5, 6, 7};
    auto ve = vector<int>{11,22,33};
    auto se = unordered_set<int>{2,3};
    //op->emplace(begin(se), end(se)); // For in pleace move ctor
    copy(op->begin(), op->end(), ostream_iterator<int>(cout, ";"));
    for (auto i : ve) {
        cout << "VII: " << i << endl;
        li.push_back(i);
    }
    cout << "Type: " << typeid(foo).name() << endl;

    // Shared
    auto sh = make_shared<Re>();
    function<int(int)> fuu = [&](auto i) -> int { return i +1 ; };
    cout << "FUU:" << fuu(100) << endl;
    weak_ptr wk = sh;
    cout << "sh USE_COUNT before: " << sh.use_count() << endl;
    cout << "WK_USE_COUNT before lock: " << wk.use_count() << endl;
    cout << "WK_USE_COUNT after lock: " << wk.lock().use_count() << endl;
    cout << "sh USE_COUNT after WK lock: " << sh.use_count() << endl;
    wk.reset();
    cout << "SH_USE_COUNT after WK reset: " << sh.use_count() << endl;
    sh.reset();
    cout << "sh USE_COUNT after SH reset: " << sh.use_count() << endl;
    cout << "wk USE_COUNT after SH reset: " << wk.use_count() << endl;
    ResourceKey t = genId();
    setId(t);

    Re re = Re{1,2, ", poo"};
    cout << "RE initializer list:" << re.i << "," << re.j << re.shoo << endl;
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
