/**
 * @file Paddle.cpp
 * @date 2-Jul-2022
 */

#include "Paddle.h"

void Paddle::OnCreate()
{
    // Enable our input set
    orxInput_EnableSet(orxConfig_GetCurrentSection(), orxTRUE);
}

void Paddle::OnDelete()
{
    // Disable our input set
    orxInput_EnableSet(orxConfig_GetCurrentSection(), orxFALSE);
}

void Paddle::Update(const orxCLOCK_INFO &_rstInfo)
{
    // Use our config section
    PushConfigSection();

    // Use object-specific input set
    const orxSTRING input_set = orxInput_GetCurrentSet();
    orxInput_SelectSet(orxConfig_GetCurrentSection());

    // Update status
    UpdateAngle(_rstInfo);
    UpdatePosition(_rstInfo);
    UpdateSpeed(_rstInfo);

    // Reset input set
    orxInput_SelectSet(input_set);

    // Go back to the previously selected config section
    PopConfigSection();
}

void Paddle::UpdateAngle(const orxCLOCK_INFO &_rstInfo)
{
    const orxFLOAT target_angle = 0.0;
    orxFLOAT angle = GetRotation();
    const orxFLOAT diff = target_angle - angle;
    angle += diff * _rstInfo.fDT * orxConfig_GetFloat("RotationFixFraction");
    SetRotation(angle);
}

void Paddle::UpdatePosition(const orxCLOCK_INFO &_rstInfo)
{
    orxVECTOR original_position = orxVECTOR_0;
    orxConfig_GetVector("Position", &original_position);
    orxVECTOR position = GetPosition(position);
    const orxFLOAT diff = original_position.fY - position.fY;
    position.fY += diff * _rstInfo.fDT * orxConfig_GetFloat("HeightFixFraction");
    SetPosition(position);
}

void Paddle::UpdateSpeed(const orxCLOCK_INFO &_rstInfo)
{
    // Calculate paddle speed based on user input and configured parameters
    const orxFLOAT max_speed = orxConfig_GetFloat("MaxSpeed");
    const orxFLOAT direction = orxInput_GetValue("Right") - orxInput_GetValue("Left");
    const orxVECTOR target_speed = {max_speed * direction, 0, 0};
    SetSpeed(target_speed);
}
