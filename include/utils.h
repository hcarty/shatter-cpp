#include <string_view>
#include <optional>
#include <orx.h>
#include "shatter-cpp.h"

namespace utils
{
    namespace config
    {
        std::optional<std::string_view> GetStringOpt(std::string_view name);
        orxU64 GetRuntimeGUID(std::string_view name);
    };

    namespace command
    {
        void Evaluate(std::string_view command);
        void EvaluateWithGuid(std::string_view command, const orxU64 guid);
    };
};
