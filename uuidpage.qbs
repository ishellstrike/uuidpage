import qbs

CppApplication {
    cpp.cppFlags: "-std=c++11"
    type: "application" // To suppress bundle generation on Mac
    consoleApplication: true
    files: [
        "filesystem.h",
        "main.cpp",
        "uuid_file.cpp",
        "uuid_file.h",
        "uuidgen.sh",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
}

