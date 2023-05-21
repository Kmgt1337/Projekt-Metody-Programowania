#ifndef DYLATACJA_HPP
#define DYLATACJA_HPP

#include "Przeksztalcenie.hpp"

class Dylatacja : public Przeksztalcenie
{
public:
    void przeksztalc(Bitmapa&) override;
};

#endif