#include "UtilityFunctions.h"
#include <iostream>



int getJPEGWidth(int& width, int& height, const char* file_name) {

	FILE* image;
	int size, i = 0;
	errno_t err;
	unsigned char* data;
	err = fopen_s(&image, file_name, "rb");

	if (err!=0) {
		std::cout << "Unable to open image" << std::endl;
		return 0;
	}

	fseek(image, 0, SEEK_END);
	size = ftell(image);
	fseek(image, 0, SEEK_SET);
	data = (unsigned char*)malloc(size);
	fread(data, 1, size, image);
	/* verify valid JPEG header */
	if (data[i] == 0xFF && data[i + 1] == 0xD8 && data[i + 2] == 0xFF && data[i + 3] == 0xE0) {
		i += 4;
		/* Check for null terminated JFIF */
		if (data[i + 2] == 'J' && data[i + 3] == 'F' && data[i + 4] == 'I' && data[i + 5] == 'F' && data[i + 6] == 0x00) {
			while (i < size) {
				i++;
				if (data[i] == 0xFF) {
					if (data[i + 1] == 0xC0) {
						height = data[i + 5] * 256 + data[i + 6];
						width = data[i + 7] * 256 + data[i + 8];
						fclose(image);
						return 1;						
					}
				}
			}
		}
	}
	fclose(image);
	return 0;
}
