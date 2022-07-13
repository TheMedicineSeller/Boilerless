#pragma once

#include <filesystem>
#include <string>
#include <stdio.h>

namespace fs = std::filesystem;

constexpr char* helpstring = "FORMAT FOR BOILERLESS\n\t.\\boilerless (or) boilerless --help : generates help text\n\tboilerless [programming-language] : generates a project of specified language in the current directory with default params and name\n\tboilerless [programming-language] [proj-name] : generates project of specified language with given proj-name\n\tboilerless [programming-language] [proj-name] [c/c++ standard version/ts enable] : generates project of specified language with given proj-name and specified c/cpp standard if c/c++ is desired languange and generates typescript proj if language desired is Js\n\tboilerless [programming-language] [proj-name] [library-name] : generates project of specified language with given proj-name and also with the specified libraries setup\n\nCurrently supported Languages : C(use c) , C++(use cpp) , Javascript(use js)\nCurrently supported libraries : SFML (c++), OpenGL (C/C++)\n\n";

void generateSkeleton_C  (const char* projname, int standard=90)
{
    std::string projname_s(projname);
    std::string standard_s = std::to_string(standard);

    fs::path cwd = fs::current_path();
    fs::create_directories(projname_s + "/" + "include");
    fs::create_directory  (projname_s + "/" + "src");
    fs::create_directory  (projname_s + "/" + "build");

    fs::current_path(cwd / projname_s);
    std::string cmakeText = "CMAKE_MINIMUM_REQUIRED(VERSION 3.22)\n\nproject(" + projname_s + ")\n\nset(CMAKE_C_STANDARD " + standard_s + ")\n\ninclude_directories(include)\n\nset(CMAKE_C_FLAGS \"-O2 -Wall\")\nadd_executable(" + projname_s + "\n\tsrc/main.c\n)";

    FILE* writer = fopen("CMakeLists.txt", "w");
    fwrite(cmakeText.c_str(), cmakeText.length(), 1, writer);
    fclose(writer);

    fs::current_path(fs::current_path() / "src");
    writer = fopen("main.c", "w");
    fclose(writer);
}

void generateSkeleton_CPP  (const char* projname, int standard=11)
{
    std::string projname_s(projname);
    std::string standard_s = std::to_string(standard);

    fs::path cwd = fs::current_path();
    fs::create_directories(projname_s + "/" + "include");
    fs::create_directory  (projname_s + "/" + "src");
    fs::create_directory  (projname_s + "/" + "build");

    fs::current_path(cwd / projname_s);
    std::string cmakeText = "CMAKE_MINIMUM_REQUIRED(VERSION 3.22)\n\nproject(" + projname_s + ")\n\nset(CMAKE_C_STANDARD " + standard_s + ")\n\ninclude_directories(include)\n\nset(CMAKE_CXX_FLAGS \"-O2 -Wall\")\nadd_executable(" + projname_s + "\n\tsrc/main.cpp\n)";

    FILE* writer = fopen("CMakeLists.txt", "w");
    fwrite(cmakeText.c_str(), cmakeText.length(), 1, writer);
    fclose(writer);

    fs::current_path(fs::current_path() / "src");
    writer = fopen("main.cpp", "w");
    fclose(writer);
}

void generateSkeleton_JS (const char* projname, bool typescript=false)
{
    std::string projname_s(projname);

    fs::path cwd = fs::current_path();
    fs::create_directories(projname_s + "/" + "Images");
    fs::create_directory  (projname_s + "/" + "Fonts");

    fs::current_path(cwd / projname_s);

    FILE* writer = fopen("index.html", "w");
    fclose(writer);

    writer = fopen("style.css", "w");
    fclose(writer);
    
    writer = (typescript) ? fopen("app.ts", "w") : fopen("app.js", "w");
    fclose(writer);
}