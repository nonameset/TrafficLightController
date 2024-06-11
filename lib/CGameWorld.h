#ifndef TRAFFICLIGHTCONTROLLER_CGAMEWORLD_H
#define TRAFFICLIGHTCONTROLLER_CGAMEWORLD_H

#include "CPed.h"

class CGameWorld
{
public:
    static CPed* FindPlayer();
    static void InitialisePatterns();
};

#endif //TRAFFICLIGHTCONTROLLER_CGAMEWORLD_H