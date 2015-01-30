#ifndef DATEMODULE_HPP
#define DATEMODULE_HPP

# include "Module.hpp"
class DateModule : public Module
{
    public:
        DateModule();
        DateModule(DateModule const & src);
        DateModule &    operator=(DateModule const & rhs);
        ~DateModule();

        std::string     getData(void);
        int             typeData(void);
};

#endif // DATEMODULE_HPP
