#pragma once

#include "crop.h"
#include "grayscale.h"
#include "image_filter.h"
#include <vector>

class FiltersController {
public:
    void ParseCmd(int argc, char* argv[]);
    void Apply(BMPImage& img);
private:
    std::vector<ImageFilter* > filters_;
};