#pragma once

#include <map>
#include <vector>
#include <string>

#include "Browser.h"


class ImageCache
{
public:
    typedef std::vector<
            std::vector<
            std::tuple<unsigned char, unsigned char, unsigned char> > > ImageData;

    const ImageData& get_image(const std::string& url);

private:
    bool exists_in_cache(const std::string& url, const ImageData*& found) const;
    const ImageData& add_image(const std::string& url);
    ImageData download(const std::string& url);

private:
    static ImageData image_data_from_browser_image(const Browser::BrowserImage& bi);

private:
    std::map<std::string, ImageData> m_cache;
};
