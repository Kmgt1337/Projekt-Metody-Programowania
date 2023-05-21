#ifndef ZLOZENIEPRZEKSZTALCEN_HPP
#define ZLOZENIEPRZEKSZTALCEN_HPP

#include "Przeksztalcenie.hpp"
#include <vector>

class ZlozeniePrzeksztalcen : public Przeksztalcenie
{
public:
    void dodajPrzeksztalcenie(Przeksztalcenie* p);
    void przeksztalc(Bitmapa&) override;

private:
    std::vector<Przeksztalcenie*> _przeksztalcenia;
};

#endif