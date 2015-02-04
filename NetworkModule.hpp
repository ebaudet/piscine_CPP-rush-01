#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include "Module.hpp"
# include <sstream>

class NetworkModule : public Module
{
    public:
        NetworkModule();
        NetworkModule(NetworkModule const & src);
        NetworkModule &    operator=(NetworkModule const & rhs);
        ~NetworkModule();

        std::string     getData(void);
        int             typeData(void);
};

#endif // NETWORKMODULE_HPP
