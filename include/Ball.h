#pragma once

#include "shatter-cpp.h"

/** Object Class
 */
class Ball : public ScrollObject
{
public:
protected:
    void OnCreate();
    void OnDelete();
    void Update(const orxCLOCK_INFO &_rstInfo);
    orxBOOL OnCollide(ScrollObject *_poCollider, orxBODY_PART *_pstPart, orxBODY_PART *_pstColliderPart, const orxVECTOR &_rvPosition, const orxVECTOR &_rvNormal);

private:
    void UpdateSpeed();
    void OnBrickCollide(const orxVECTOR &position);
    void OnBottomWallCollide();
    void DecrementHP();
    void GetHP();
};
