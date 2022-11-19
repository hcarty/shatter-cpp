#pragma once

#include <string_view>
#include "shatter-cpp.h"

namespace score
{
    static const orxSTRING runtimeName = "ScoreGUID";
};

class Score : public ScrollObject
{
public:
    void Increment();
    void Decrement();
    orxS32 Get();

protected:
    void OnCreate();
    void OnDelete();
    void Update(const orxCLOCK_INFO &_rstInfo);

private:
    void Zero();
    void EvaluateByName(std::string_view name);
};
