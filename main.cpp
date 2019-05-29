#include "app.h"
#include "adaptors/pyadaptor.h"

#include <iostream>
//#include <thread>

using namespace std;

int main()
{
    cout << "Hello AT1!" << endl;
    Resource r1, r2{}, r3{};
    Resource rarr[10] = {Resource(), Resource(), Resource()};
    App app;
    app.addResource(move(r1));
    app.addResource(move(r2));
    app.addResource(move(r3));
    ResourceKey k1 = 42;
    ResourceKey k2 = 102;
    Resource res{k1}; // it's private ctor for testing
    cout << "AT says:" << endl;
    Resource res1 = app.getResource(k1);
    Resource res2 = app.getResource(k2);
    cout << "result1 is :" << res1.getId() << endl;
    cout << "result2 is :" << res2.getId() << endl;

    app.run();



    PyAdaptor pa;

    return 0;
}
