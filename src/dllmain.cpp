#include "Utils.h"
#include "CPed.h"
#include "CGameWorld.h"
#include "CVehicle.h"
#include "fwScriptGuid.h"
#include "Natives.h"

void OnScriptInit()
{
    using namespace tlc;

    InitialiseAllComponents();

    g_Logger = std::make_unique<Logger>();
    g_Logger->Info("Revenant has been initialised.");

    // Wait for the game to finish loading before we continue.
    while (DLC::GET_IS_LOADING_SCREEN_ACTIVE())
        WAIT(500);

    while (g_Running)
    {
        WAIT(0);

        CPed* pPlayer = (CPed*)CGameWorld::FindPlayer();

        if (pPlayer == nullptr)
            continue;

        uint32_t playerHandle = fwScriptGuid::CreateGuid(reinterpret_cast<uint64_t*>(pPlayer));

        if (IS_PED_IN_ANY_VEHICLE(playerHandle, false))
        {
            CVehicle* pVehicle = (CVehicle*)fwScriptGuid::GetBaseFromGuid(GET_VEHICLE_PED_IS_IN(playerHandle, false));

            if (pVehicle == nullptr)
                continue;

            g_Logger->Info("pVehicle: %p", pVehicle);

            CVehicleIntelligence* pVehIntel = pVehicle->GetIntelligence();

            if (pVehIntel == nullptr)
                continue;

            g_Logger->Info("pVehIntel: %p", pVehicle);

            CJunction* pJunction = pVehIntel->m_Junction;

            if (pJunction == nullptr)
                continue;

            g_Logger->Info("Junction address is: %p", pJunction);

            g_Logger->Info("m_fLightTimeRemaining: %f\n m_iLightPhase: %d\nm_TrafficLightCommand: %d\nm_JunctionCommand: %d", pJunction->m_fLightTimeRemaining, pJunction->m_iLightPhase, static_cast<int>(pVehIntel->m_TrafficLightCommand), static_cast<int>(pVehIntel->m_JunctionCommand));

            // TODO: Implement the logic for the traffic light controller.
        }
    }
}

void OnScriptAbort()
{
    using namespace tlc;

    g_Logger->Info("Revenant has been terminated.");
    g_Logger.reset();
}

bool __stdcall DllMain(HINSTANCE hInstance, DWORD reason, LPVOID reserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        scriptRegister(hInstance, OnScriptInit);
        break;
    case DLL_PROCESS_DETACH:
        OnScriptAbort();
        scriptUnregister(hInstance);
        break;
    }
    return true;
}