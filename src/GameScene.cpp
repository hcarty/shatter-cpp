#include "GameScene.h"
#include "utils.h"

void GameScene::OnCreate()
{
    Scene::OnCreate();
}

void GameScene::OnDelete()
{
    Scene::OnDelete();
}

void GameScene::Update(const orxCLOCK_INFO &_rstInfo)
{
    PushConfigSection();
    orxASSERT(orxInput_IsSetEnabled(orxConfig_GetCurrentSection()));
    const orxSTRING input_set = orxInput_GetCurrentSet();
    orxInput_SelectSet(orxConfig_GetCurrentSection());

    orxConfig_PushSection("Runtime");
    auto active = orxConfig_GetS32("ActiveBricks");
    orxConfig_PopSection();

    if (active == 0)
    {
        auto command = orxConfig_GetString("QuitCommand");
        utils::command::EvaluateWithGuid(command, GetGUID());
    }

    orxInput_SelectSet(input_set);
    PopConfigSection();

    Scene::Update(_rstInfo);
}
