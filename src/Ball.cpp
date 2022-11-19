#include <string>
#include "Ball.h"
#include "utils.h"
#include "Score.h"

namespace ballutils
{
    Score *GetScore()
    {
        auto scoreGUID = utils::config::GetRuntimeGUID(score::runtimeName);
        auto score = shatter_cpp::GetInstance().GetObject<Score>(scoreGUID);
        orxASSERT(score);
        return score;
    }
};

void Ball::OnCreate()
{
}

void Ball::OnDelete()
{
}

void Ball::Update(const orxCLOCK_INFO &_rstInfo)
{
    UpdateSpeed();
}

void Ball::UpdateSpeed()
{
    PushConfigSection();
    orxVECTOR pos = GetPosition(pos, true);
    orxVECTOR speed = GetSpeed(speed);

    // Keep the ball somewhat close to even vertical/horizontal movement
    if (orxMath_Abs(speed.fX) < orxMath_Abs(speed.fY / 2.0))
    {
        orxFLOAT sign = speed.fX > 0 ? 1 : -1;
        speed.fX = orxMath_Abs(speed.fY / 2.0) * sign;
    }
    if (orxMath_Abs(speed.fY) < orxMath_Abs(speed.fX / 2.0))
    {
        orxFLOAT sign = speed.fY > 0 ? 1 : -1;
        speed.fY = orxMath_Abs(speed.fX / 2.0) * sign;
    }

    // Linear speed should stay consistent
    orxVector_Normalize(&speed, &speed);
    orxVector_Mulf(&speed, &speed, orxConfig_GetFloat("LinearSpeed"));

    // Apply any speed changes we've made
    SetSpeed(speed);
    PopConfigSection();
}

orxBOOL Ball::OnCollide(ScrollObject *_poCollider, orxBODY_PART *_pstPart, orxBODY_PART *_pstColliderPart, const orxVECTOR &_rvPosition, const orxVECTOR &_rvNormal)
{
    // We should only be colliding with Scroll objects
    orxASSERT(_poCollider);

    auto modelName = _poCollider->GetModelName();
    if (orxString_Compare(modelName, "Brick") == 0)
    {
        OnBrickCollide(_rvPosition);
    }
    else if (orxString_Compare(modelName, "BottomWall") == 0)
    {
        OnBottomWallCollide();
    }
    return orxTRUE;
}

void Ball::OnBrickCollide(const orxVECTOR &position)
{
    auto impact = orxObject_CreateFromConfig("BallImpact");
    orxASSERT(impact);
    orxObject_SetWorldPosition(impact, &position);

    // Get Score object and update
    ballutils::GetScore()->Increment();
}

void Ball::OnBottomWallCollide()
{
    // Get Score object and update
    auto score = ballutils::GetScore();
    score->Decrement();

    if (score->Get() == 0)
    {
        DecrementHP();
    }
}

void Ball::DecrementHP()
{
    auto name = "BallHP";
    orxConfig_PushSection("Runtime");
    auto hp = orxConfig_GetS32(name);
    hp -= 1;
    orxConfig_SetS32(name, hp);
    orxConfig_PopSection();

    if (hp >= 0 && hp < 2)
    {
        orxCHAR name[64];
        orxString_NPrint(name, sizeof(name), "OnHP%d", hp);

        PushConfigSection();
        auto command = orxConfig_GetString(name);
        utils::command::EvaluateWithGuid(command, GetGUID());
        PopConfigSection();
    }
    else if (hp < 0)
    {
        auto sceneGUID = utils::config::GetRuntimeGUID("Scene");
        auto scene = shatter_cpp::GetInstance().GetObject(sceneGUID);
        orxASSERT(scene);
        scene->PushConfigSection();
        auto quitCommand = orxConfig_GetString("QuitCommand");
        scene->PopConfigSection();
        orxASSERT(quitCommand != orxSTRING_EMPTY);
        utils::command::EvaluateWithGuid(quitCommand, scene->GetGUID());
    }
}
