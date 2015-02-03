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
    FILE 						*input;
    char						buffer[512];
    std::stringstream			result;

    if(not (input = popen("system_profiler SPHardwareDataType", "r")))
        return "FUCK";
    while(fgets(buffer, sizeof(buffer), input))
        result << buffer;
    pclose(input);
    return result.str();
}

int         CpuModule::typeData(void) {
    return 2;
}
