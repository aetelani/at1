import qbs

CppApplication {
    files: [
        "app.cpp",
        "app.h",
        "main.cpp",
        "resource.cpp",
        "resource.h",
        "scripting/testing.py",
        "statecharts/flow.scxml",
        "adaptors/pyadaptor.h",
        "adaptors/pyadaptor.cpp",
    ]

    consoleApplication: true
    cpp.cxxLanguageVersion: "c++14"
    cpp.dynamicLibraries: "pthread"

    cpp.includePaths: [
        " /opt/opencv/release/include/",
        "/usr/include/python3.6m/"
    ]

    cpp.libraryPaths: [
        "/opt/opencv/release/lib/",
        "/opt/opencv/release/bin/"
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
