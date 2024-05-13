#pragma once

class BMPImage;

class ImageFilter {
public:
    virtual void Apply(BMPImage& img) = 0;
    /* здесь, возможно, будет виртуальная функция, отвечающая за количество параметров,
       передаваемых фильтру, для отслеживания ошибок */
};