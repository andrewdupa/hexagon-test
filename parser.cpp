/****************************************

* File Name : parcer.cpp

* Creation Date : 02-03-2025

* Last Modified : Tue 04 Mar 2025 05:11:53 PM

* Created By :  Andrey Andreev

*****************************************/
#include "parser.h"

namespace hexagon {
    std::string HostParser::ParseLine(const std::string &line)
    {
        size_t blank = line.find(BLANK);
        if (blank != std::string::npos)
            return line.substr(0, blank);
        return {};
    }

    std::string ResourceParser::ParseLine(const std::string &line)
    {
        size_t sz_get = line.find(GET);

        if (sz_get != std::string::npos) {
            size_t sz_ok =  line.find(OK, sz_get);

            if(sz_ok != std::string::npos)
            {
                size_t sz_root = line.find(FS, sz_get);

                if(sz_root != std::string::npos)
                {
                    size_t sz_http = line.find(HTTP, sz_root);
                    if(sz_http != std::string::npos)
                    {
                        return line.substr(sz_root, sz_http-sz_root);
                    }
                    else
                        return line.substr(sz_root, sz_ok-sz_root);
                }
            }
        }
        return {};
    }
}
