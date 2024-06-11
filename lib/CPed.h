#ifndef TRAFFICLIGHTCONTROLLER_CPED_H
#define TRAFFICLIGHTCONTROLLER_CPED_H

#pragma once

class CPedIntelligence
{
public:
};

class CPed
{
public:
    CPedIntelligence* GetIntelligence();
    static void InitialisePatterns();
};

#endif //TRAFFICLIGHTCONTROLLER_CPED_H