#pragma once

#include "color.h"
#include "image_filter.h"

#include <fstream>
#include <string>
#include <vector>

class BMPImage {
public:
    BMPImage() = default;
    explicit BMPImage(const std::string& file_name);
    BMPImage(size_t width, size_t height);
    explicit BMPImage(const std::vector<std::vector<Color>>& colors);
    void Allocate(size_t height, size_t width);
    void Read(const std::string& file_name);
    void Write(const std::string& file_name);
    void SetColor(size_t y, size_t x, const Color& color);
    std::vector<std::vector<Color>>& GetData();
    size_t GetHeight();
    size_t GetWidth();

private:
#pragma pack(push)
#pragma pack(1)
    typedef struct BMPHeader {
        uint8_t  Header[2];
        uint32_t Size;
        uint16_t Reserved[2];
        uint32_t Offset;
    } BMPHeader;

    typedef struct BMPHeaderInfo {
        uint32_t Size;
        uint32_t Width;
        uint32_t Height;
        uint32_t Middle[2];
        uint32_t SizeImage;
        uint32_t Tail[4];
    } BMPHeaderInfo;

#pragma pack(pop)
    size_t height_ = 0;
    size_t width_ = 0;

    BMPHeader header_;
    BMPHeaderInfo headerInfo_;

    std::vector<std::vector<Color>> colors_;
    friend std::istream& operator>> (std::istream& in, BMPImage::BMPHeader& header);
    friend std::istream& operator>> (std::istream& in, BMPImage::BMPHeaderInfo& header);
    friend std::ostream& operator<< (std::ostream& out, const BMPImage::BMPHeader& header);
    friend std::ostream& operator<< (std::ostream& out, const BMPImage::BMPHeaderInfo& header);
};
