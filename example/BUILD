cc_library(
    name = "example_lib",
    srcs = ["example_lib.cpp"],
    hdrs = ["example_lib.h"],
)

cc_binary(
    name = "example_lib.so",
    linkshared = True,
    deps = [":example_lib"],
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

load("@io_bazel_rules_docker//container:image.bzl", "container_image")
config_setting(
    name = "armeabi-v7a",
    values = {"cpu": "armeabi-v7a"},
)

config_setting(
    name = "aarch64-linux-gnu",
    values = {"cpu": "aarch64-linux-gnu"},
)
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar")

pkg_tar(
    name = "example_tar",
    strip_prefix = ".",
#    package_dir = "/usr/bin",
    srcs = [":example"],
    mode = "0755",
)


container_image(
  name = "cc_image",
  base = select( {
    "//conditions:default": None,
    ":aarch64-linux-gnu": "@distroless-cc-nonroot-arm64//image",
  }),
  architecture = "x86_64",
#  architecture = select({
#    ":aarch64-linux-gnu": "arm64",
#    "//conditions:default": "x86_64",
#  }),
  operating_system = "linux",
  tars = [":example_tar"],
  entrypoint = ["/example"],
)