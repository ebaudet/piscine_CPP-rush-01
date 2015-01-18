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
        int             getSizeX();
        int             getSizeY();
        int             getX();
        int             getY();
        void            setSizeX(int);
        void            setSizeY(int);
        void            setX(int);
        void            setY(int);
        virtual std::string     getData(void);
        virtual int             typeData(void);
    protected:
        std::string const  _name;
        int                _size_x;
        int                _size_y;
        int                _x;
        int                _y;
};

#endif // MODULE_HPP
