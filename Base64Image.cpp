#include <iostream>
#include <vector>
#include <cpprest/http_listener.h>
#include <fstream>

using namespace web;

int main() {

    std::ifstream jsonFile("Base64Image.json", std::ifstream::binary);
    json::value jsonValue;
    jsonFile >> jsonValue;

    std::ofstream tempImageFile;
    auto tempImgEncod = utility::conversions::from_base64(jsonValue.at("image").as_string());
    auto tempImgEncod_char = reinterpret_cast<char*>(tempImgEncod.data());
    tempImageFile.open("./received_images/imageFile.png", std::ofstream::out & std::ios::binary);
    // tempImageFile.open("./received_images/imageFile.png", std::ofstream::binary);
    tempImageFile.write(tempImgEncod_char, tempImgEncod.size());

    std::cout << jsonValue.at("image_id").as_string() << std::endl;
}



/*
auto bytes = from_base64(jsonValue.at("image"));
std::basic_ofstream<unsigned char> file{"img.jpg"};
file.write(bytes.data(), bytes.size());
*/