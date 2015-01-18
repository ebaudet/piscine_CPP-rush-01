#include "HostModule.hpp"
#include <iostream>
#include <string>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>

HostModule::HostModule() : Module("Hostname / Username")
{

}

HostModule::HostModule(HostModule const & src) : Module("Hostname / Username")
{

}

HostModule::~HostModule()
{

}

HostModule &    HostModule::operator=(HostModule const & rhs){
    (void)rhs;
    return *this;
}

std::string     HostModule::getData(void) {
    struct utsname  data;
    struct passwd *passwd;
    std::string     result;

    struct utsname test;

    result << "SYSNAME : " << data.sysname << std::endl;
    result << "NODEMANE : " << data.nodename << std::endl;
    result << "RELEASE : " << data.release << std::endl;
    result << "VERSION : " << data.version << std::endl;
    result << "MACHINE :" << data.machine << std::endl;

    passwd = getpwuid(getuid());
    result << "USERNAME : " << passwd->pw_name << std::endl;

    return result;
}

int         HostModule::typeData(void) {
    return 1;
}
