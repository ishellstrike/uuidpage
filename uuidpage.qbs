import qbs

CppApplication {
    cpp.cxxLanguageVersion: "c++11"
    type: "application" // To suppress bundle generation on Mac
    consoleApplication: true
    files: [
        "filesystem.h",
        "main.cpp",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
}

