#include <iostream>
#include <filesystem>

#include <png.h>

void simple_png(std::string beforeFileName, std::string afterFileName) {    
    png_image image;

    memset(&image, 0, sizeof(image));
    image.version = PNG_IMAGE_VERSION;

    if (png_image_begin_read_from_file(&image, beforeFileName.data()) != 0) {
        png_bytep buffer;
        image.format = PNG_FORMAT_RGBA;
        buffer = (png_bytep)malloc(PNG_IMAGE_SIZE(image));

        if (buffer != NULL && png_image_finish_read(&image, NULL, buffer, 0, NULL) != 0) {
            if (png_image_write_to_file(&image, afterFileName.data(), 0, buffer, 0, NULL) != 0) {
                exit(0);
            }
        }
        else {
            if (buffer == NULL) {
                //png_free_image(&image)
            }
            else {
                free(buffer);
            }
        }
        fprintf(stderr, "pngtopng: error: %s\n", image.message);
        exit(1);
    }
    fprintf(stderr, "pngtopng: usage: pngtopng input-file output-file\n");
    exit(1);
}


int main(void)
{
    simple_png("before.png", "after.png");
}