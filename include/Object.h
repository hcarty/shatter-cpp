/**
 * @file Object.h
 * @date 17-Jul-2026
 */

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "shatter-cpp.h"

/** Object Class
 */
MakeScrollObject(Object)
{
public:


protected:

                void            OnCreate();
                void            OnDelete();
                void            Update(const orxCLOCK_INFO &_rstInfo);


private:
};

#endif // __OBJECT_H__
