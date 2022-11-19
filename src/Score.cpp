#include "Score.h"
#include "utils.h"

void Score::OnCreate()
{
    orxConfig_PushSection("Runtime");
    orxConfig_SetU64(score::runtimeName, GetGUID());
    orxConfig_PopSection();
}

void Score::OnDelete()
{
}

void Score::Update(const orxCLOCK_INFO &_rstInfo)
{
}

void Score::EvaluateByName(std::string_view name)
{
    PushConfigSection();
    auto command = orxConfig_GetString(name.data());
    utils::command::Evaluate(command);
    PopConfigSection();
}

void Score::Increment()
{
    EvaluateByName("Increment");
}

void Score::Decrement()
{
    EvaluateByName("Decrement");
    auto current = Get();
    if (current < 0)
    {
        Zero();
    }
}

void Score::Zero()
{
    EvaluateByName("Zero");
}

orxS32 Score::Get()
{
    orxConfig_PushSection("Runtime");
    orxS32 currentScore = orxConfig_GetS32("Score");
    orxConfig_PopSection();
    return currentScore;
}
