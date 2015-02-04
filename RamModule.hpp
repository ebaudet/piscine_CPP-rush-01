#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include "Module.hpp"
# include <sstream>


class RamModule : public Module
{
    public:
        RamModule();
        ~RamModule();
        RamModule(RamModule const & src);
        RamModule & operator=(RamModule const & rhs);
        std::string     getData(void);
        int             typeData(void);
};

#endif // RAMMODULE_HPP
