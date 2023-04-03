#ifndef _ADAPTOR_H_
#define _ADAPTOR_H_

class Adaptor {
    public:
        virtual void init() = 0;
        virtual void refresh(InternalData id) = 0;
};

#endif
