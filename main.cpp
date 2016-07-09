#include <iostream>

#include "ImageCache.h"

struct Image
{
private:
    ImageCache *m_cache;
    std::string m_url;
    int m_xorigin;
    int m_yorigin;

public:
   Image(const std::string& str, int x, int y);
   ~Image();

   void draw() const;
};

Image::Image(const std::string& str, int x, int y)
    : m_url(str)
    , m_xorigin(x)
    , m_yorigin(y)
{
    m_cache = new ImageCache;
}

Image::~Image()
{
    delete m_cache;
}

void Image::draw()const
{
    m_cache->get_image(m_url);
    std::cout << "draw the image" <<std::endl;
}

int main()
{
    Image img("image", 0, 0);
    img.draw();
    
    return 0;
}
