#ifndef EROZJA_HPP
#define EROZJA_HPP

#include "Przeksztalcenie.hpp"

class Erozja : public Przeksztalcenie
{
public:
    void przeksztalc(Bitmapa&) override;
};

#endif