#include "utils.h"

namespace utils
{
    namespace config
    {
        std::optional<std::string_view> GetStringOpt(std::string_view name)
        {
            auto c_name = name.data();
            if (orxConfig_HasValue(c_name))
            {
                return std::optional(orxConfig_GetString(c_name));
            }
            else
            {
                return std::nullopt;
            }
        }

        void PushRuntime()
        {
            orxConfig_PushSection("Runtime");
        }

        void PopRuntime()
        {
            orxConfig_PopSection();
        }

        orxU64 GetRuntimeGUID(std::string_view name)
        {
            PushRuntime();
            auto guid = orxConfig_GetU64(name.data());
            PopRuntime();
            return guid;
        }
    };

    namespace command
    {
        void Evaluate(std::string_view command)
        {
            orxCOMMAND_VAR _result;
            orxCommand_Evaluate(command.data(), &_result);
        }

        void EvaluateWithGuid(std::string_view command, const orxU64 guid)
        {
            orxCOMMAND_VAR _result;
            orxCommand_EvaluateWithGUID(command.data(), guid, &_result);
        }
    };
};
