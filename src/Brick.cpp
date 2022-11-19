/**
 * @file Brick.cpp
 */

#include "Brick.h"

void Brick::OnCreate()
{
}

void Brick::OnDelete()
{
}

void Brick::Update(const orxCLOCK_INFO &_rstInfo)
{
}

orxBOOL Brick::OnCollide(ScrollObject *_poCollider, orxBODY_PART *_pstPart, orxBODY_PART *_pstColliderPart, const orxVECTOR &_rvPosition, const orxVECTOR &_rvNormal)
{
    // Ball collision
    if (_poCollider && orxString_Compare(_poCollider->GetModelName(), "Ball") == 0)
    {
        // Turn off collisions for the affected body part of the brick
        orxBody_SetPartSelfFlags(_pstPart, 0);
        orxBody_SetPartCheckMask(_pstPart, 0);
        // Set the brick to be deleted
        SetLifeTime(0);
    }
    return orxTRUE;
}
