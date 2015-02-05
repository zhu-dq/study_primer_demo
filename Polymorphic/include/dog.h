#ifndef DOG_H
#define DOG_H
#include "animal.h"
class dog:public animal
{
    public:
    dog();
    virtual void speak();
    virtual ~dog();
};
#endif 

