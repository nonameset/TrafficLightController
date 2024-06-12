#ifndef TRAFFICLIGHTCONTROLLER_CPED_H
#define TRAFFICLIGHTCONTROLLER_CPED_H

#pragma once

#include "CVehicle.h"

class CPedIntelligence
{
public:
};

class CPed
{
public:
    inline static CVehicle* m_pMyVehicle;
    static void InitialisePatterns();
    CPedIntelligence* GetIntelligence();
};

#endif //TRAFFICLIGHTCONTROLLER_CPED_H