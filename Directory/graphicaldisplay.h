#ifndef _GRAPHICALDISPLAY_H_
#define _GRAPHICALDISPLAY_H_
#include "adaptor.h"

class GraphicalDisplay : public Adaptor {
    public:
        void init() override;
        void refresh(InternalData id) override;
};

#endif