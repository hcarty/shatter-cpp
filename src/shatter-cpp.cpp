/**
 * @file shatter-cpp.cpp
 * @date 17-Jul-2026
 */

#define __SCROLL_IMPL__
#include "shatter-cpp.h"
#undef __SCROLL_IMPL__

#include "orxExtensions.h"

#include "Ball.h"
#include "Brick.h"
#include "GameScene.h"
#include "Paddle.h"
#include "Scene.h"
#include "Score.h"

#ifdef __orxMSVC__

/* Requesting high performance dedicated GPU on hybrid laptops */
__declspec(dllexport) unsigned long NvOptimusEnablement = 1;
__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;

#endif // __orxMSVC__

/** Update function, it has been registered to be called every tick of the core clock
 */
void shatter_cpp::Update(const orxCLOCK_INFO &_rstClockInfo)
{
    // Should quit?
    if (orxInput_HasBeenActivated("Quit"))
    {
        // Send close event
        orxEvent_SendShort(orxEVENT_TYPE_SYSTEM, orxSYSTEM_EVENT_CLOSE);
    }
}

/** Camera Update function, it has been registered to be called every tick of the core clock, after physics & objects have been updated
 */
void shatter_cpp::CameraUpdate(const orxCLOCK_INFO &_rstClockInfo)
{
    // Get MainCamera proxy object
    ScrollObject *poMainCamera = shatter_cpp::GetInstance().GetObject("MainCamera");
    if (poMainCamera)
    {
        // Update & move the camera here
        // [...]

        // Round its position
        orxVECTOR vPosition;
        poMainCamera->SetPosition(*orxVector_Round(&vPosition, &poMainCamera->GetPosition(vPosition)));
    }
}

/** BindObjects function, ScrollObject-derived classes are bound to config sections here
 */
void shatter_cpp::BindObjects()
{
    // Bind the classes to object config sections
    ScrollBindObject<Ball>("Ball");
    ScrollBindObject<Brick>("Brick");
    ScrollBindObject<GameScene>("GameScene");
    ScrollBindObject<Paddle>("Paddle");
    ScrollBindObject<Scene>("Scene");
    ScrollBindObject<Score>("Score");
}

/** Init function, it is called when all orx's modules have been initialized
 */
orxSTATUS shatter_cpp::Init()
{
    // Init extensions
    InitExtensions();

    // Push [Main] as the default config section
    orxConfig_PushSection("Main");

    // Create the viewports
    for (orxS32 i = 0, iCount = orxConfig_GetListCount("ViewportList"); i < iCount; i++)
    {
        orxViewport_CreateFromConfig(orxConfig_GetListString("ViewportList", i));
    }

    // Create the scene
    CreateObject("TitleScene");

    // Done!
    return orxSTATUS_SUCCESS;
}

/** Run function, it should not contain any game logic
 */
orxSTATUS shatter_cpp::Run()
{
    // Return orxSTATUS_FAILURE to instruct orx to quit
    return orxSTATUS_SUCCESS;
}

/** Exit function, it is called before exiting from orx
 */
void shatter_cpp::Exit()
{
    // Exit from extensions
    ExitExtensions();

    // Let orx clean all our mess automatically. :)
}

/** Bootstrap function, it is called before config is initialized, allowing for early resource storage definitions
 */
orxSTATUS shatter_cpp::Bootstrap() const
{
    // Bootstrap extensions
    BootstrapExtensions();

    // Return orxSTATUS_FAILURE to prevent orx from loading the default config file
    return orxSTATUS_SUCCESS;
}

/** Main function
 */
int main(int argc, char **argv)
{
    // Execute our game
    shatter_cpp::GetInstance().Execute(argc, argv);

    // Done!
    return EXIT_SUCCESS;
}
