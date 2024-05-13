#pragma once

#include <cstddef>
#include "simple_image_filter.h"

class Crop : public SimpleImageFilter {
public:
    Crop(size_t width, size_t height);
    void Apply(BMPImage& img) override;
private:
    size_t width_;
    size_t height_;
};
