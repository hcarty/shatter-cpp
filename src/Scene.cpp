#include <string>
#include "Scene.h"
#include "utils.h"

void Scene::OnCreate()
{
    // Enable our input set
    orxInput_EnableSet(orxConfig_GetCurrentSection(), orxTRUE);
}

void Scene::OnDelete()
{
    // Disable our input set
    orxInput_EnableSet(orxConfig_GetCurrentSection(), orxFALSE);
}

void Scene::Update(const orxCLOCK_INFO &_rstInfo)
{
    // Use object-specific config section
    PushConfigSection();

    // Use object-specific input set
    const orxSTRING input_set = orxInput_GetCurrentSet();
    orxInput_SelectSet(orxConfig_GetCurrentSection());

    // Check for active input with a matching command
    orxINPUT_TYPE input_type;
    orxENUM input_id;
    orxFLOAT value;
    orxINPUT_MODE mode = orxINPUT_MODE_FULL;
    if (orxInput_GetActiveBinding(&input_type, &input_id, &value))
    {
        const orxSTRING input_name = orxNULL;
        orxInput_GetBoundInput(input_type, input_id, mode, 0, &input_name, orxNULL);
        if (input_name && input_name != orxSTRING_EMPTY && orxInput_HasBeenActivated(input_name))
        {
            auto name = std::string(input_name) + "Command";
            auto command = utils::config::GetStringOpt(name);
            if (command)
            {
                utils::command::EvaluateWithGuid(command.value(), GetGUID());
            }
        }
    }

    // Reset input set
    orxInput_SelectSet(input_set);

    // Go back to the previously selected config section
    PopConfigSection();
}
