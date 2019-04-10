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
    ResourceKey k1 = 2;
    Resource res{42};
    cout << "AT says:" << res.getId() << endl;
    return 0;
}
