#include "Natives.h"
#include "Utils.h"

bool (*__IS_PED_IN_ANY_VEHICLE) (uint32_t, bool);
uint32_t (*__GET_VEHICLE_PED_IS_IN) (uint32_t, bool);

void InitialiseNatives()
{
    ConvertCall(
            hook::get_pattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 40 8A FA E8 ? ? ? ? 32 DB"),
                __IS_PED_IN_ANY_VEHICLE);

    ConvertCall(
            hook::get_pattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 40 8A F2 33 DB E8 ? ? ? ? 48 8B F8 48 85 C0 0F 84 ? ? ? ? 4C 8B 80 ? ? ? ? 40 84 F6"),
            __GET_VEHICLE_PED_IS_IN);
}

bool IS_PED_IN_ANY_VEHICLE(uint32_t ped, bool atGetIn)
{
    return __IS_PED_IN_ANY_VEHICLE(ped, atGetIn);
}

uint32_t GET_VEHICLE_PED_IS_IN(uint32_t ped, bool atGetIn)
{
    return __GET_VEHICLE_PED_IS_IN(ped, atGetIn);
}