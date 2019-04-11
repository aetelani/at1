#ifndef APP_H
#define APP_H
#include "resource.h"

class App
{
public:
    App();
    static void addResource(Resource r);
    void deleteResource(Resource r);
    Resource getResource(ResourceKey k);
};

#endif // APP_H
