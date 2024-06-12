#include "Utils.h"
#include "CPed.h"
#include "CGameWorld.h"
#include "fwScriptGuid.h"

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
        CVehicle* pVehicle = CVehiclePopulation::ms_pInterestingVehicle;

        if (pPlayer != nullptr && pVehicle != nullptr)
        {
            // TODO: Get current ETrafficLightCommand and EJunctionCommand from CVehicleIntelligence.
            //     Apply new ETrafficLightCommand and EJunctionCommand to CVehicleIntelligence of vehicles waiting at traffic lights.
            //     Will possibly have to reset values to default after a certain amount of time if it doesn't reset itself? -> More testing needed.
            //     Find a better way to get the current vehicle of the player & if the player is in a vehicle without having to access natives through SHV...
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