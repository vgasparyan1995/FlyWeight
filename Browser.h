#pragma once

#include <string>

class Browser
{
public:
    struct BrowserImage
    {
        std::vector<unsigned char> m_data;
        unsigned m_width;
        unsigned m_height;
    };

    static BrowserImage download(const std::string& url)
    {
        BrowserImage tmp;
        tmp.m_width = 30;
        tmp.m_height = 10;
        tmp.m_data = std::vector<unsigned char>(tmp.m_width * tmp.m_height, 0);
        return tmp;
    }
};
