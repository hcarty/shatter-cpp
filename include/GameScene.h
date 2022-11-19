#pragma once

#include "Scene.h"

class GameScene : public Scene
{
public:
protected:
    void OnCreate();
    void OnDelete();
    void Update(const orxCLOCK_INFO &_rstInfo);

private:
};
