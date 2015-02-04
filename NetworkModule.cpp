#include "NetworkModule.hpp"

NetworkModule::NetworkModule() : Module("Network")
{

}

NetworkModule::~NetworkModule()
{

}

NetworkModule::NetworkModule(NetworkModule const &src) : Module(src)
{
}

NetworkModule &    NetworkModule::operator=(NetworkModule const & rhs){
    (void)rhs;
    return *this;
}

std::string     NetworkModule::getData(void) {
    FILE 						*input;
    char						buffer[512];
    std::stringstream			result;

    if(not (input = popen("netstat -bi | colrm 40", "r")))
        return "FUCK";
    while(fgets(buffer, sizeof(buffer), input))
        result << buffer;
    pclose(input);
    return result.str();
}

int         NetworkModule::typeData(void) {
    return 2;
}
