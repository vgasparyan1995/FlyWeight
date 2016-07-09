#include "ImageCache.h"

const ImageCache::ImageData& ImageCache::get_image(const std::string& url)
{
    const ImageData* in_cache_image = nullptr;
    if (exists_in_cache(url, in_cache_image)) {
        return *in_cache_image;
    }

    return add_image(url);
}

bool ImageCache::exists_in_cache(const std::string& url, const ImageData*& found) const
{
    auto it = m_cache.find(url);
    if (it == m_cache.end()) {
        return false;
    }

    found = &it->second;
    return true;
}

const ImageCache::ImageData& ImageCache::add_image(const std::string& url)
{
    ImageData tmp(download(url));
    auto it = m_cache.insert(std::make_pair(url, tmp));
    if (it.second == false) {
        throw "WTF?";
    } else {
        return it.first->second;
    }
}

ImageCache::ImageData ImageCache::download(const std::string& url)
{
    return image_data_from_browser_image(Browser::download(url));
}

ImageCache::ImageData ImageCache::image_data_from_browser_image(const Browser::BrowserImage& bi)
{
    ImageCache::ImageData tmp;
    tmp.resize(bi.m_height);
    for (int j = 0; j < bi.m_height; ++j) {
        for (int i = 0 ; i < bi.m_data.size() - 3; i += 3) {
            tmp[j].push_back(std::make_tuple(bi.m_data[i], 
                        bi.m_data[i + 1], 
                        bi.m_data[i + 2]));
        }
    }
    return tmp;
}
