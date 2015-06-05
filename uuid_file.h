#ifndef UUID_FILE_H
#define UUID_FILE_H
#include <stdio.h>
#include <string>

struct uuid_file
{
    FILE *text_file = nullptr;
    std::string last_readed;

    uuid_file(const std::string &file);
    ~uuid_file();
    bool next();


    uuid_file(const uuid_file &other) = delete;
    uuid_file &operator =(const uuid_file &other) = delete;
};

#endif // UUID_FILE_H
