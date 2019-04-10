#include "app.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello AT1!" << endl;
    Resource r1{}, r2{}, r3{};
    App app;
    app.addResource(r1);
    app.addResource(r2);
    app.addResource(r3);
    ResourceKey k1 = 42;
    Resource res{k1};
    cout << "AT says:" << endl;
    Resource res1 = app.getResource(k1);
    cout << "result is :" << res1.p_id << endl;
    return 0;
}
