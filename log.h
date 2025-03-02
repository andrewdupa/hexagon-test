#pragma once

#include <iostream>
#include <unordered_map>

namespace hexagon {
    struct Log
    {
        virtual ~Log() = default;
        virtual void Write(std::ostream& os) const = 0;
        virtual void AddLog(const std::string& log) = 0;

        inline auto GetRequests(void) const
        {
            return requests;
        }
    private:
        std::unordered_map<std::string, int> requests;
    };


    struct HostLog: public Log
    {
        void AddLog(const std::string& log) override;
        void Write(std::ostream& os) const override;
    };

    struct ResourceLog: public Log
    {
        void AddLog(const std::string& log) override;
        void Write(std::ostream& os) const override;
    };

    std::ostream& operator<<(std::ostream& os, const Log& logger);

}
