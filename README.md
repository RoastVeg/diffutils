# OpenBSD diffutils

This is a straight port of the `cmp` and `diff` commands from OpenBSD to Linux. It depends on [libbsd](https://libbsd.freedesktop.org/), and a libc with `vasprintf(3)`.

## Build and Install

Meson and ninja are required to build.

```bash
meson build
ninja -C build
```
