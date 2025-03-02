#include <gtest/gtest.h>
#include <fstream>
#include "log.h"
#include "parser.h"

TEST(Hexagon, HostAccessParseWithLog) {
    using namespace hexagon;
    const std::string file_name = "testdata/epa-http.txt";
    std::unique_ptr<Parser> pp = std::make_unique<HostParser>();
    std::unique_ptr<Log> lp = std::make_unique<HostLog>();
    std::ifstream file(file_name);
    ASSERT_EQ(true, file.is_open());

    std::string line;
    while(std::getline(file, line))
    {
        lp->AddLog(pp->ParseLine(line));
    }
    std::cout << *lp;
}

TEST(Hexagon, ResourceAccessParseWithLog) {
    using namespace hexagon;
    const std::string file_name = "testdata/epa-http.txt";
    std::string line;
    std::unique_ptr<Parser> pp = std::make_unique<ResourceParser>();
    std::unique_ptr<Log> lp = std::make_unique<ResourceLog>();
    std::ifstream file(file_name);
    ASSERT_EQ(true, file.is_open());
    while(std::getline(file, line))
    {
        lp->AddLog(pp->ParseLine(line));
    }
    std::cout << *lp;
}

TEST(Hexagon, HostAccessParseNoLog) {
    using namespace hexagon;
    const std::string file_name = "testdata/epa-http.txt";
    std::unique_ptr<Parser> pp = std::make_unique<HostParser>();
    std::unique_ptr<Log> lp = std::make_unique<HostLog>();
    std::ifstream file(file_name);
    ASSERT_EQ(true, file.is_open());

    std::string line;
    while(std::getline(file, line))
    {
        lp->AddLog(pp->ParseLine(line));
    }
}

TEST(Hexagon, ResourceAccessParseNoLog) {
    using namespace hexagon;
    const std::string file_name = "testdata/epa-http.txt";
    std::string line;
    std::unique_ptr<Parser> pp = std::make_unique<ResourceParser>();
    std::unique_ptr<Log> lp = std::make_unique<ResourceLog>();
    std::ifstream file(file_name);
    ASSERT_EQ(true, file.is_open());
    while(std::getline(file, line))
    {
        lp->AddLog(pp->ParseLine(line));
    }
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
