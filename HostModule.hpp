#ifndef HOSTMODULE_HPP
#define HOSTMODULE_HPP

# include "Module.hpp"
class HostModule : public Module
{
    public:
        HostModule();
        HostModule(HostModule const & src);
        HostModule &    operator=(HostModule const & rhs);
        ~HostModule();

        std::string     getData(void);
        int             typeData(void);
};

#endif // HOSTMODULE_HPP
