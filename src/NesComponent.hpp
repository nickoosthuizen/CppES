#ifndef NES_COMPONENT_HPP
#define NES_COMPONENT_HPP

class NesComponent {
  public:
    virtual void reset() = 0;
    virtual void powerOn() = 0;
};

#endif