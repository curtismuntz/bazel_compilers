# bazel_compilers

This repo hosts the bazel compiler defintions for my many cpp projects.

# usage

In your `workspace` file:

```
###############################
# Cross compiler
###############################
http_archive(
    name = 'murtis_bazel_compilers',
    urls = [
      'https://gitlab.com/murtis/bazel_compilers/-/archive/master/bazel_compilers-master.tar.gz',
    ],
    strip_prefix = 'bazel_compilers-master',
)

load("@murtis_bazel_compilers//compilers:dependencies.bzl", "linaro_5_3_1_arm_linux_gnueabihf_compiler_dependencies")

linaro_5_3_1_arm_linux_gnueabihf_compiler_dependencies()
```


Build with `bazel build --spawn_strategy=standalone --crosstool_top=@murtis_bazel_compilers//compilers/arm_compiler:toolchain --cpu=armeabi-v7a //example`

# Known issues:

* armeabi-v7a does not fully link without adding `--spawn_strategy=standalone` to bazel build options.
