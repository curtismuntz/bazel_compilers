[![Actions Status](https://github.com/curtismuntz/bazel_compilers/workflows/ci/badge.svg)](https://github.com/curtismuntz/bazel_compilers/actions)

# bazel_compilers

This repo hosts the bazel compiler defintions for my many cpp projects. I'm not a compiler expert, so use with caution. I'm trying to maintain a Raspberry Pi / Nvidia Jetson suite of compiler definitions in one repository, effectively mirroring the bazel crosstool [here](https://github.com/bazelbuild/bazel/tree/master/src/test/shell/bazel/testdata/bazel_toolchain_test_data)

Requires bazel version >= 0.25.1. It is assumed that bazel is running on an x86_64(amd64) host.

Supported compilers:

* armv7hf: processor architecture used in the Raspberry Pi family of embedded products.
* aarch64: processor architecture used in Jetson TX1 TX2 Xavier and Nano products.

# usage

In your `WORKSPACE` file:

```
http_archive(
    name = "murtis_bazel_compilers",
    urls = [
      "https://github.com/curtismuntz/bazel_compilers/archive/<commit hash>.tar.gz",
    ],
    strip_prefix = "bazel_compilers-< commit hash >",
)

load("@murtis_bazel_compilers//compilers:dependencies.bzl", "cross_compiler_dependencies")

cross_compiler_dependencies()
```

In your `.bazelrc` file:

```
build:amd64 --platforms=@local_config_platform//:host

build:arm_crosstool --crosstool_top=@murtis_bazel_compilers//compilers/arm_compiler:toolchain
build:arm_crosstool --host_crosstool_top=@bazel_tools//tools/cpp:toolchain
build:arm_crosstool --spawn_strategy=standalone

build:armv7hf --config=arm_crosstool
build:armv7hf --cpu=armeabi-v7a --compiler=gcc

build:aarch64 --config=arm_crosstool
build:aarch64 --cpu=aarch64-linux-gnu --compiler=gcc
```


Build with:

```
# amd64 executable:
bazel build --config=amd64 //example # Note, `--config=amd64` can be omitted here.

# Raspberry Pi:
bazel build --config=armv7hf //example

# Nvidia Jetson Products:
bazel build --config=aarch64 //example
```
