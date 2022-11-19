/**
 * @file Scene.h
 */

#ifndef __SCENE_H__
#define __SCENE_H__

#include "shatter-cpp.h"

class Scene : public ScrollObject
{
public:
protected:
    void OnCreate();
    void OnDelete();
    void Update(const orxCLOCK_INFO &_rstInfo);

private:
};

#endif // __SCENE_H__
