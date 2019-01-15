# bazel_compilers

This repo hosts the bazel compiler defintions for my many cpp projects.

# usage

In your `WORKSPACE` file:

```
http_archive(
    name = 'murtis_bazel_compilers',
    urls = [
      'https://gitlab.com/murtis/bazel_compilers/-/archive/master/bazel_compilers-master.tar.gz',
    ],
    strip_prefix = 'bazel_compilers-master',
)

load("@murtis_bazel_compilers//compilers:dependencies.bzl", "cross_compiler_dependencies")

cross_compiler_dependencies()
```

In your `.bazelrc` file:

```
build --compiler=compiler

build:rpi --crosstool_top=//compilers/arm_compiler:toolchain
build:rpi --host_crosstool_top=@bazel_tools//tools/cpp:toolchain
build:rpi --cpu=armeabi-v7a --compiler=gcc
build:rpi --spawn_strategy=standalone
```


Build with:

`bazel build --config=rpi //example` or `bazel build //example`
