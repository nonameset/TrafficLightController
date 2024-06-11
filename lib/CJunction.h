#ifndef TRAFFICLIGHTCONTROLLER_CJUNCTION_H
#define TRAFFICLIGHTCONTROLLER_CJUNCTION_H

class CJunction
{
public:
    char pad_0x0000[0x804];
    int32_t m_iLightPhase;
    float m_fLightTimeRemaining;
};

#endif //TRAFFICLIGHTCONTROLLER_CJUNCTION_H