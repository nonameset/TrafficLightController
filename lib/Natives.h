#ifndef TRAFFICLIGHTCONTROLLER_NATIVES_H
#define TRAFFICLIGHTCONTROLLER_NATIVES_H

#pragma once

bool IS_PED_IN_ANY_VEHICLE(uint32_t ped, bool atGetIn);
uint32_t GET_VEHICLE_PED_IS_IN(uint32_t ped, bool atGetIn);

void InitialiseNatives();

#endif //TRAFFICLIGHTCONTROLLER_NATIVES_H