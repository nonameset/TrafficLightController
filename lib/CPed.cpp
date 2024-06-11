#include "CPed.h"
#include "Utils.h"

void CPed::InitialisePatterns()
{

}

CPedIntelligence *CPed::GetIntelligence()
{
    static uint32_t nIntelOffset =
            *hook::get_pattern<uint32_t>("4C 8B 81 ? ? ? ? 83 C8 FF", 3);

    return *(injector::raw_ptr(this) + nIntelOffset)
            .get<CPedIntelligence*>();
}