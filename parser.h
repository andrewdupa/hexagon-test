#pragma once

#include <iostream>
namespace hexagon {
    struct Parser
    {
        virtual ~Parser() = default;
        virtual std::string ParseLine(const std::string &line) = 0;
    };

    struct HostParser : public Parser
    {
        std::string ParseLine(const std::string &line) override;
    private:
        static constexpr std::string_view BLANK = " ";
    };

    struct ResourceParser : public Parser
    {
        std::string ParseLine(const std::string &line) override;
    private:
        static constexpr std::string_view GET = "\"GET ";
        static constexpr std::string_view OK = "\" 200";
        static constexpr std::string_view FS = "/";
        static constexpr std::string_view HTTP = " HTTP";
    };
}
