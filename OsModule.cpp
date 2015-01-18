#include "OsModule.hpp"
#include <iostream>
#include <string>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>

OsModule::OsModule() : Module("OS Info Module")
{

}

OsModule::OsModule(OsModule const &) : Module("OS Info module")
{

}

OsModule::~OsModule()
{

}

OsModule &    OsModule::operator=(OsModule const & rhs){
    (void)rhs;
    return *this;
}

std::string     OsModule::getData(void) {
    struct utsname  data;
    struct passwd   *passwd;
    std::string     result;

    uname(&data);

    result.append("SYSNAME : ");
    result.append(data.sysname);
    result.append("\n");

    result.append("RELEASE : ");
    result.append(data.release);
    result.append("\n");

    result.append("VERSION : ");
    result.append(data.version);
    result.append("\n");

    result.append("MACHINE :");
    result.append(data.machine);
    result.append("\n");



    return result;
}

int         OsModule::typeData(void) {
    return 1;
}
