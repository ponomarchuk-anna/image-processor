#pragma once

#include "simple_image_filter.h"

class Grayscale : public SimpleImageFilter {
public:
    void Apply(BMPImage& img) override;
};