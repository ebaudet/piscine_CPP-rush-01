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
};

#endif // HOSTMODULE_HPP
