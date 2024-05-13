#include "bmp_image.h"
#include "filters_controller.h"

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "Usage ..." << std::endl;
        return 0;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    BMPImage img(inputFile);

    FiltersController controller;
    controller.ParseCmd(argc, argv);
    controller.Apply(img);

    img.Write(outputFile);

    return 0;
}
