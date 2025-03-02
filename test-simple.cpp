#include <memory>
#include <fstream>
#include "parser.h"
#include "log.h"

using namespace hexagon;

int main(int argc, char *argv[])
{
    const std::string file_name = "testdata/epa-http.txt";
    const std::string error_log = "test requires using either host, or resource argument";

    std::unique_ptr<Parser> pp;
    std::unique_ptr<Log> lp;

    if (argc != 2)
    {
        std::cout << error_log << "\n";
        return 1;
    }

    if (std::string{"host"} == argv[1]) {
        std::cout << "running host access test" << "\n";
        lp = std::make_unique<HostLog>();
        pp = std::make_unique<HostParser>();
    }
    else if (std::string{"resource"} == argv[1])
    {
        std::cout << "running resource access test" << "\n";
        lp = std::make_unique<ResourceLog>();
        pp = std::make_unique<ResourceParser>();
    }
    else
        std::cout << error_log << "\n";

    std::ifstream file(file_name);
    if (!file.is_open())
    {
        std::cout << "Can't open test file: " << file_name << "\n";
        return 1;
    }

    std::string line;
    while(std::getline(file, line))
    {
        lp->AddLog(pp->ParseLine(line));
    }
    std::cout << *lp << "\n";
}
