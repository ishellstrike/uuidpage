#include "uuid_file.h"

uuid_file::uuid_file(const std::string &file)
{
    text_file = fopen(file.c_str(), "r");
    last_readed.resize(36);

    fscanf(text_file, "%s\n", &last_readed[0]);
}

uuid_file::~uuid_file()
{
    if(text_file)
    {
        fclose(text_file);
        text_file = nullptr;
    }
}

bool uuid_file::next()
{
    fscanf(text_file, "%s\n", &last_readed[0]);
    return !feof(text_file);
}

