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

HostModule::HostModule(HostModule const &hm) : Module(hm)
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

    result.append("HOSTNAME : ");
    result.append(data.nodename);
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
