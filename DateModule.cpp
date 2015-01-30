#include "DateModule.hpp"
#include <iostream>
#include <string>


DateModule::DateModule() : Module("Date")
{

}

DateModule::DateModule(DateModule const &dm) : Module(dm)
{

}

DateModule::~DateModule()
{

}

DateModule &    DateModule::operator=(DateModule const & rhs){
    (void)rhs;
    return *this;
}

std::string     DateModule::getData(void) {
    std::string         result;
    time_t              rawtime;
    struct tm          *timeinfo;
    char                buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "Now it's %e/%m/%Y %I:%M:%S%p.", timeinfo);

    result = std::string(buffer);
    return result;
}

int         DateModule::typeData(void) {
    return 2;
}
