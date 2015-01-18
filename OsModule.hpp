#ifndef OSMODULE_HPP
#define OSMODULE_HPP

# include "Module.hpp"
class OsModule : public Module
{
    public:
        OsModule();
        OsModule(OsModule const & src);
        OsModule &    operator=(OsModule const & rhs);
        ~OsModule();

        std::string     getData(void);
        int             typeData(void);
};

#endif // HOSTMODULE_HPP
