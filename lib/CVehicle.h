#ifndef TRAFFICLIGHTCONTROLLER_CVEHICLE_H
#define TRAFFICLIGHTCONTROLLER_CVEHICLE_H

#pragma once

#include "CJunction.h"

enum EJunctionCommand
{
    JUNCTION_COMMAND_GO = 0,
    JUNCTION_COMMAND_APPROACHING,
    JUNCTION_COMMAND_WAIT_FOR_LIGHTS,
    JUNCTION_COMMAND_WAIT_FOR_TRAFFIC,
    JUNCTION_COMMAND_NOT_ON_JUNCTION,
    JUNCTION_COMMAND_GIVE_WAY,
    JUNCTION_COMMAND_LAST
};

enum ETrafficLightCommand
{
    TRAFFICLIGHT_COMMAND_INVALID,
    TRAFFICLIGHT_COMMAND_STOP,
    TRAFFICLIGHT_COMMAND_AMBERLIGHT,
    TRAFFICLIGHT_COMMAND_GO,
    TRAFFICLIGHT_COMMAND_FILTER_LEFT,
    TRAFFICLIGHT_COMMAND_FILTER_RIGHT,
    TRAFFICLIGHT_COMMAND_FILTER_MIDDLE,
    TRAFFICLIGHT_COMMAND_PED_WALK,
    TRAFFICLIGHT_COMMAND_PED_DONTWALK
};

class CVehicleIntelligence
{
public:
    char pad_0x0000[0x8e0];
    CJunction* m_Junction; //0x8e0
    char pad_0x09A8[0xc0];
    ETrafficLightCommand m_TrafficLightCommand; //0x9a8
    EJunctionCommand m_JunctionCommand; //0x9ac
};

class CVehicle
{
public:
    CVehicleIntelligence* GetIntelligence();
};

class CVehiclePopulation
{
public:
    inline static CVehicle* ms_pInterestingVehicle;
    static void InitialisePatterns();
};

#endif //TRAFFICLIGHTCONTROLLER_CVEHICLE_H