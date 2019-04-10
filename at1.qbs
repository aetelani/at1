import qbs

CppApplication {
    consoleApplication: true
    files: [
        "app.cpp",
        "app.h",
        "main.cpp",
    ]
    cpp.cxxLanguageVersion: "c++14"

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
