#include "bmp_image.h"
#include "grayscale.h"

#include <vector>

void Grayscale::Apply(BMPImage &img) {
    std::vector<std::vector<Color>>& colors = img.GetData();

    for (size_t i = 0; i < img.GetHeight(); ++i) {
        for (size_t j = 0; j < img.GetWidth(); ++j) {
            uint8_t c = (colors[i][j].red + colors[i][j].green + colors[i][j].blue) / 3;
            img.SetColor(i, j, {c, c, c});
        }
    }
}