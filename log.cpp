/****************************************

* File Name : Log.cpp

* Creation Date : 02-03-2025

* Last Modified : Sun 02 Mar 2025 01:13:54 PM

* Created By :  Andrey Andreev

*****************************************/
#include <algorithm>
#include <vector>
#include <ostream>

#include "log.h"

namespace hexagon {

    void Log::AddLog(const std::string& log)
    {
        if (!log.empty())
            requests[log] += 1;
    }

    std::ostream& operator<<(std::ostream& os, const Log& logger)
    {
        logger.Write(os);
        return os;
    }

    void HostLog::AddLog(const std::string& log)
    {
        Log::AddLog(log);
    }

    void HostLog::Write(std::ostream& os) const
    {
        std::vector<std::pair<std::string, int>> ordered(GetRequests().begin(), GetRequests().end());
        std::sort(ordered.begin(), ordered.end(),
                [](std::pair<std::string, int> a, std::pair<std::string, int> b) { return a.second > b.second; });
        for (const auto &pair: ordered)
            os << pair.first << " " << pair.second << "\n";
    }

    void ResourceLog::AddLog(const std::string& log)
    {
        Log::AddLog(log);
    }


    void ResourceLog::Write(std::ostream& os) const
    {
        for (const auto &pair: GetRequests())
            os << pair.first << " " << pair.second << "\n";
    }
}
