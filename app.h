#ifndef APP_H
#define APP_H
#include "resource.h"

class App
{
public:
    App();
    void addResource(Resource r);
    void deleteResource(Resource r);
    Resource getResource(ResourceKey k);
    void run();
};

#endif // APP_H
