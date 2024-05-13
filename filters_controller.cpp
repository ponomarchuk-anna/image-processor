#include "bmp_image.h"
#include "filters_controller.h"
#include <iostream>

void FiltersController::ParseCmd(int argc, char* argv[]) {
    size_t i = 3;
    std::string filterName;
    std::vector<std::string> params;
    std::string value;

    while (i < argc) {
        value = argv[i];
        ++i;
        if (value.starts_with('-')) {
            if (!filterName.empty()) {
                if (filterName == "-crop") {
                    filters_.push_back(new Crop(atoi(params[0].c_str()), atoi(params[1].c_str())));
                    params.clear();
                } else if (filterName == "-grayscale") {
                    filters_.push_back(new Grayscale());
                } else {
                    throw 1;
                }
            }
            filterName = value;
        } else {
            params.push_back(value);
        }
    }

    if (!filterName.empty()) {
        if (filterName == "-crop") {
            filters_.push_back(new Crop(atoi(params[0].c_str()), atoi(params[1].c_str())));
            params.clear();
        } else if (filterName == "-grayscale") {
            filters_.push_back(new Grayscale());
        } else {
            throw 1;
        }
    }
}

void FiltersController::Apply(BMPImage &img) {
    for (auto filter : filters_) {
        filter->Apply(img);
        delete filter;
    }
}
