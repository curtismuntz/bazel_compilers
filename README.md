# bazel_compilers

This repo hosts the bazel compiler defintions for my many cpp projects.

Requires bazel version >= 0.25.1.

# usage

In your `WORKSPACE` file:

```
http_archive(
    name = "murtis_bazel_compilers",
    urls = [
      "https://gitlab.com/murtis/bazel_compilers/-/archive/< commit hash >/bazel_compilers-< commit hash >.tar.gz",
    ],
    strip_prefix = "bazel_compilers-< commit hash >",
)

load("@murtis_bazel_compilers//compilers:dependencies.bzl", "cross_compiler_dependencies")

cross_compiler_dependencies()
```

In your `.bazelrc` file:

```
build --compiler=compiler

build:armv7hf --crosstool_top=@murtis_bazel_compilers//compilers/arm_compiler:toolchain
build:armv7hf --host_crosstool_top=@bazel_tools//tools/cpp:toolchain
build:armv7hf --cpu=armeabi-v7a --compiler=gcc
build:armv7hf --spawn_strategy=standalone
```


Build with:

`bazel build --config=armv7hf //example` or `bazel build //example`
