/**
 * @file shatter-cpp.h
 * @date 2-Jul-2022
 */

#ifndef __shatter_cpp_H__
#define __shatter_cpp_H__

#define __NO_SCROLLED__
#include "Scroll.h"

/** Game Class
 */
class shatter_cpp : public Scroll<shatter_cpp>
{
public:


private:

                orxSTATUS       Bootstrap() const;

                void            Update(const orxCLOCK_INFO &_rstInfo);

                orxSTATUS       Init();
                orxSTATUS       Run();
                void            Exit();
                void            BindObjects();


private:
};

#endif // __shatter_cpp_H__
