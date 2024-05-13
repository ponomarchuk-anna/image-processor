#include "bmp_image.h"

std::istream& operator>> (std::istream& in, Color& Color) {
    in.read(reinterpret_cast<char *>(&Color), sizeof(Color));
    return in;
}

std::ostream& operator<< (std::ostream& out, const Color& Color) {
    out.write(reinterpret_cast<const char *>(&Color), sizeof(Color));
    return out;
}

BMPImage::BMPImage(const std::string &file_name) {
    Read(file_name);
}

BMPImage::BMPImage(size_t width, size_t height) : height_(height), width_(width) {
    Allocate(height_, width_);
}

BMPImage::BMPImage(const std::vector<std::vector<Color>> &Colors) : colors_(Colors) {
    height_ = colors_.size();
    width_ = 0;
    if (height_ > 0) {
        width_ = colors_[0].size();
    }
}

void BMPImage::Allocate(size_t height, size_t width) {
    height_ = height;
    width_ = width;
    colors_ = std::vector<std::vector<Color>>(height_, std::vector<Color>(width_, {0, 0, 0}));
};

void BMPImage::Read(const std::string& file_name) {
    std::ifstream file(file_name, std::ios::binary);
    file >> header_ >> headerInfo_;

    Allocate(headerInfo_.Height, headerInfo_.Width);

    for (size_t i = height_ - 1; i >= 0; --i) {
        for (size_t j = 0; j < width_; ++j) {
            Color color;
            file >> color;
            SetColor(i, j, color);
        }
    }
}

void BMPImage::Write(const std::string& file_name) {
    std::ofstream file(file_name, std::ios::binary);
    headerInfo_.Height = height_;
    headerInfo_.Width = width_;
    headerInfo_.SizeImage = width_ * height_ * 3;

    header_.Size = header_.Offset + headerInfo_.SizeImage;

    file << header_ << headerInfo_;

    for (size_t i = height_; i > 0; --i) {
        for (size_t j = 0; j < width_; ++j) {
            file << colors_[i - 1][j];
        }
    }
}

void BMPImage::SetColor(size_t y, size_t x, const Color& color) {
    colors_[y][x] = color;
};

std::vector<std::vector<Color>>& BMPImage::GetData() {
    return colors_;
}

size_t BMPImage::GetHeight() {
    return height_;
}

size_t BMPImage::GetWidth() {
    return width_;
}

std::istream& operator>> (std::istream& in, BMPImage::BMPHeader& header) {
    in.read(reinterpret_cast<char *>(&header), sizeof(header));
    return in;
}

std::istream& operator>> (std::istream& in, BMPImage::BMPHeaderInfo& header) {
    in.read(reinterpret_cast<char *>(&header), sizeof(header));
    return in;
}

std::ostream& operator<< (std::ostream& out, const BMPImage::BMPHeader& header) {
    out.write(reinterpret_cast<const char *>(&header), sizeof(header));
    return out;
}

std::ostream& operator<< (std::ostream& out, const BMPImage::BMPHeaderInfo& header) {
    out.write(reinterpret_cast<const char *>(&header), sizeof(header));
    return out;
}
