#pragma once

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

constexpr char* helpstring = "FORMAT FOR BOILERLESS\n\t.\\boilerless (or) boilerless --help : generates help text\n\tboilerless [programming-language] generates a project of specified language in the current directory with default params and name\n\tboilerless [programming-language] [proj-name] : generates project of specified language with given proj-name\n\tboilerless [programming-language] [proj-name] [library-name] : generates project of specified language with given proj-name and also with the specified libraries setup\n\nCurrently supported Languages : C(use c) , C++(use cpp) , Javascript(use js)\nCurrently supported libraries : SFML (c++), OpenGL (C/C++)\n\n";

void generateSkeleton_C  (const char* projname, bool isCpp=false)
{
    std::string progname = (isCpp) ? "main.cpp" : "main.c";
    std::string projname_s(projname);

    fs::path cwd = fs::current_path();
    fs::create_directories(projname_s + "/" + "include");
    fs::create_directory  (projname_s + "/" + "src");
    fs::create_directory  (projname_s + "/" + "build");

    fs::current_path(cwd / projname_s);
    std::string cmakeText = "CMAKE_MINIMUM_REQUIRED(VERSION 3.22)\n\nproject(" + projname_s + ")\n\ninclude_directories(include)\n\nadd_executable(" + projname_s + "\n\tsrc/" + progname + "\n)";

    FILE* writer = fopen("CMakeLists.txt", "w");
    fwrite(cmakeText.c_str(), cmakeText.length(), 1, writer);
    fclose(writer);

    fs::current_path(fs::current_path() / "src");
    writer = fopen(progname.c_str(), "w");
    fclose(writer);
}

void generateSkeleton_JS (const char* projname)
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
    
    writer = fopen("app.js", "w");
    fclose(writer);
}