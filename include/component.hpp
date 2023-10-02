#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Component {
  public:
    virtual void reset() = 0;
    virtual void powerOn() = 0;
};

#endif