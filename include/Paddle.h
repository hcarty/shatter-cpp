/**
 * @file Paddle.h
 * @date 2-Jul-2022
 */

#ifndef __PADDLE_H__
#define __PADDLE_H__

#include "shatter-cpp.h"

/** Object Class
 */
class Paddle : public ScrollObject
{
public:
protected:
    void OnCreate();
    void OnDelete();
    void Update(const orxCLOCK_INFO &_rstInfo);

private:
    void UpdateAngle(const orxCLOCK_INFO &_rstInfo);
    void UpdatePosition(const orxCLOCK_INFO &_rstInfo);
    void UpdateSpeed(const orxCLOCK_INFO &_rstInfo);
};

#endif // __PADDLE_H__
