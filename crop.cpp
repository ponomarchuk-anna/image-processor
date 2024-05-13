#include "bmp_image.h"
#include "crop.h"
#include <vector>

Crop::Crop(size_t width, size_t height) : width_(width), height_(height) {
}

void Crop::Apply(BMPImage &img) {
    std::vector<std::vector<Color>> colors;
    colors = img.GetData();
    img.Allocate(height_, width_);

    for (size_t i = 0; i < height_; ++i) {
        for (size_t j = 0; j < width_; ++j) {
            size_t x = j;
            size_t y = img.GetHeight() - height_ + i;
            img.SetColor(i, j, colors[y][x]);
        }
    }
}

