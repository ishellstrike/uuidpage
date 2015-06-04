#ifndef FIELSYSTEM_H
#define FIELSYSTEM_H
#include <vector>
#include <exception>

#ifdef _WIN32
    #include <windows.h>

    inline std::string wstring_to_string(const std::wstring &wstr)
    {
        std::string s(wstr.length(), ' ');
        std::copy(wstr.begin(), wstr.end(), s.begin());
        return s;
    }

    inline std::wstring string_to_wstring(const std::string &str)
    {
        std::wstring s(str.length(), L' ');
        std::copy(str.begin(), str.end(), s.begin());
        return s;
    }

    inline void get_files(const std::string &dir, std::vector<std::string> &files)
    {
        files.clear();
        WIN32_FIND_DATA f;


        std::wstring s = L"./" + string_to_wstring(dir) + L"*";
        HANDLE h = FindFirstFile(s.c_str(), &f);
        if(h != INVALID_HANDLE_VALUE)
        {
            do
            {
                std::string fn = wstring_to_string(f.cFileName);
                if(fn == "." || fn == "..")
                    continue;

                files.push_back(fn);
            } while(FindNextFile(h, &f));
        }
        else
        {
            throw "unable to open directory";
        }
    }
#endif

#ifdef __unix__
#include <sys/types.h>
#include <dirent.h>

    inline void getFiles(const std::string &dir, std::vector<std::string> &files)
    {
        files.clear();
        DIR *direct = opendir(("./"+dir).c_str());
        if(direct)
        {
            dirent *ent;
            while((ent = readdir(direct)) != nullptr)
            {
                std::string fn = ent->d_name;
                if(fn == "." || fn == "..")
                    continue;

                files.push_back(fn);
            }
        }
        else
        {
            throw "unable to open directory";
        }
    }
#endif

#endif // FIELSYSTEM_H
