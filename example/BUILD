cc_library(
    name = "example_lib",
    srcs = ["example_lib.cpp"],
    hdrs = ["example_lib.h"],
)

cc_binary(
    name = "example",
    srcs = ["main.cpp"],
    deps = [":example_lib"],
)

cc_test(
    name = "example_test",
    srcs = ["example_test.cpp"],
    deps = [":example_lib"],
)
