/**
 * @file shatter-cpp.cpp
 * @date 2-Jul-2022
 */

#define __SCROLL_IMPL__
#include "shatter-cpp.h"
#undef __SCROLL_IMPL__

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
void shatter_cpp::Update(const orxCLOCK_INFO &_rstInfo)
{
}

/** Init function, it is called when all orx's modules have been initialized
 */
orxSTATUS shatter_cpp::Init()
{
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
    // Let orx clean all our mess automatically. :)
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

/** Bootstrap function, it is called before config is initialized, allowing for early resource storage definitions
 */
orxSTATUS shatter_cpp::Bootstrap() const
{
    // Add config storage to find the initial config file
    orxResource_AddStorage(orxCONFIG_KZ_RESOURCE_GROUP, "../data/config", orxFALSE);

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
