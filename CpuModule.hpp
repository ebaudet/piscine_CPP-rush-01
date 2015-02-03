#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

# include "Module.hpp"
# include <sstream>

class CpuModule : public Module
{
public:
    CpuModule();
    CpuModule(CpuModule const & src);
    CpuModule &    operator=(CpuModule const & rhs);
    ~CpuModule();

    std::string     getData(void);
    int             typeData(void);
};

#endif
