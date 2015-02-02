#include "CpuModule.hpp"

CpuModule::CpuModule() : Module("CPU")
{

}

CpuModule::CpuModule(CpuModule const &src) : Module(src)
{
}

CpuModule::~CpuModule()
{

}

CpuModule &    CpuModule::operator=(CpuModule const & rhs){
    (void)rhs;
    return *this;
}

std::string     CpuModule::getData(void) {
    std::string         result;

    result = "YOLLOOO\n";
    return result;
}

int         CpuModule::typeData(void) {
    return 2;
}
