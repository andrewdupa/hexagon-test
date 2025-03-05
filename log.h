#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include "parser.h"

namespace hexagon {
    struct Log
    {
        Log(std::unique_ptr<Parser> pp):
            parser{std::move(pp)} {}
        virtual ~Log() = default;
        virtual void Write(std::ostream& os) const = 0;
        virtual void AddLog(const std::string& log) = 0;

        inline auto GetRequests(void) const
        {
            return requests;
        }
    private:
        std::unique_ptr<Parser> parser;
        std::unordered_map<std::string, int> requests;
    };


    struct HostLog: public Log
    {
        HostLog(): Log(std::make_unique<HostParser>()) {}
        void AddLog(const std::string& log) override;
        void Write(std::ostream& os) const override;
    };

    struct ResourceLog: public Log
    {
        ResourceLog(): Log(std::make_unique<ResourceParser>()) {}
        void AddLog(const std::string& log) override;
        void Write(std::ostream& os) const override;
    };

    std::ostream& operator<<(std::ostream& os, const Log& logger);

}
