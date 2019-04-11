#include "app.h"

#include <iostream>
#include <thread>

using namespace std;

int main()
{
    cout << "Hello AT1!" << endl;
    Resource r1{}, r2{}, r3{};
    App app;
    thread t1(app.addResource, r1);
    thread t2(app.addResource, r2);
    thread t3(app.addResource, r3);
    t1.join();
    t2.join();
    t3.join();
    ResourceKey k1 = 42;
    ResourceKey k2 = 102;
    Resource res{k1}; // it's private ctor for testing
    cout << "AT says:" << endl;
    Resource res1 = app.getResource(k1);
    Resource res2 = app.getResource(k2);
    cout << "result1 is :" << res1.p_id << endl;
    cout << "result2 is :" << res2.p_id << endl;
    return 0;
}
