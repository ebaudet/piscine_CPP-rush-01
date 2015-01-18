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

HostModule::HostModule(HostModule const &) : Module("Hostname / Username")
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

    uname(&data);

    result.append("SYSNAME : ");
    result.append(data.sysname);
    result.append("\n");

    result.append("NODENAME : ");
    result.append(data.nodename);
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

    passwd = getpwuid(getuid());
    result.append("USERNAME :");
    result.append(passwd->pw_name);
    result.append("\n");

    return result;
}

int         HostModule::typeData(void) {
    return 1;
}
