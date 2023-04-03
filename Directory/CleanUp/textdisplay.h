#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include "adaptor.h"

class TextDisplay : public Adaptor {
    public:
        TextDisplay(){};
        void init() override;
        void refresh(InternalData* id) override;
};

#endif
