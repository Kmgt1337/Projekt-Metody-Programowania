#ifndef MYEXCEPTIONS_HPP
#define MYEXCEPTIONS_HPP

#include <stdexcept>
#include <string>

namespace myexceptions
{
    class out_of_range : public std::exception
    {
    public:
        out_of_range(const char* msg) : _msg{msg}
        {}

        const char* what() const noexcept override
        {
            return _msg.c_str();
        }

    private:
        std::string _msg;
    };

    class bad_bitmap_size : public std::exception
    {
    public:
        bad_bitmap_size(const char* msg) : _msg{msg}
        {}

        const char* what() const noexcept override
        {
            return _msg.c_str();
        }

    private:
        std::string _msg;
    };
}

#endif