#include "CVehicle.h"

CVehicleIntelligence* CVehicle::GetIntelligence()
{
    static uint32_t nIntelOffset =
            *hook::get_pattern<uint32_t>("48 8B 91 ? ? ? ? 48 8B F9 B9 ? ? ? ? 0F B7 82 ? ? ? ? 3B C1 74 73", 3);

    return *(injector::raw_ptr(this) + nIntelOffset)
            .get<CVehicleIntelligence*>();
}

void CVehiclePopulation::InitialisePatterns()
{
    ms_pInterestingVehicle = GetRelativeReference<CVehicle>(
            "48 8B 1D ? ? ? ? 48 8B F9 48 3B D9 74 2F 48 85 DB", 3, 7);
}