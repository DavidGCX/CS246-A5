#ifndef _ADAPTOR_H_
#define _ADAPTOR_H_
#include "gameController.h"
class Adaptor {
    public:
        Adaptor(){};
        virtual void init() = 0;
        virtual void refresh(InternalData* id) = 0;
};

#endif
