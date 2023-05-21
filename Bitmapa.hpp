#ifndef BITMAPA_HPP
#define BITMAPA_HPP

class Bitmapa
{
public:
    virtual unsigned length() const = 0;
    virtual unsigned width() const = 0;
    virtual bool& operator() (unsigned x, unsigned y) = 0;
    virtual bool operator() (unsigned x, unsigned y) const = 0;
    virtual ~Bitmapa() {}
};

#endif