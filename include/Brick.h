/**
 * @file Brick.h
 */

#ifndef __BRICK_H__
#define __BRICK_H__

#include "shatter-cpp.h"

/** Object Class
 */
class Brick : public ScrollObject
{
public:
protected:
    void OnCreate();
    void OnDelete();
    void Update(const orxCLOCK_INFO &_rstInfo);
    orxBOOL OnCollide(ScrollObject *_poCollider, orxBODY_PART *_pstPart, orxBODY_PART *_pstColliderPart, const orxVECTOR &_rvPosition, const orxVECTOR &_rvNormal);

private:
};

#endif // __BRICK_H__
