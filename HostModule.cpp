#include "HostModule.hpp"

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

