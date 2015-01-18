#ifndef MODULE_HPP
# define MODULE_HPP

# include "IMonitorModule.hpp"
# include <string>
# include <iostream>

class Module : public IMonitorModule
{
    public:
        Module(std::string const & name);
        Module(Module const &src, std::string const & name);
        Module & operator=(Module const & rhs);
        virtual ~Module();
        std::string     getName() const;
    protected:
        std::string const  _name;
};

#endif // MODULE_HPP
