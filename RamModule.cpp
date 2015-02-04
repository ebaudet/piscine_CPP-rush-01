#include "RamModule.hpp"

RamModule::RamModule() : Module("RAM")
{

}

RamModule::~RamModule()
{

}

RamModule::RamModule(RamModule const &src) : Module(src)
{
}

RamModule &    RamModule::operator=(RamModule const & rhs){
    (void)rhs;
    return *this;
}

std::string     RamModule::getData(void) {
    FILE 						*input;
    char						buffer[512];
    std::stringstream			result;

    if(not (input = popen("top -l 1 | head -n 10 | grep PhysMem", "r")))
        return "FUCK";
    while(fgets(buffer, sizeof(buffer), input))
        result << buffer;
    pclose(input);
    return result.str();
}

int         RamModule::typeData(void) {
    return 2;
}
