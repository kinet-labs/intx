## Kinet Fork

This is a Kinet Industries fork of the canonical upstream:
- **Upstream**: https://github.com/chfast/intx
- **Pinned commit**: `dada8df`
- **Pinned tag**: `v0.15.0`
- **License**: Apache-2.0 (preserved from upstream — see `LICENSE`, modifications log in `NOTICE`)
- **LuKinetx extensions**: NONE (verbatim parity with upstream). Header-only extended-precision integer C++ library used by `kinet-labs/crypto` for Montgomery arithmetic in `bn254/`, `secp256r1/`, `modexp/`, `evm256/`, `kzg/`.
- **Tag policy**: track upstream semver verbatim. Divergence (if ever required) signaled by next-minor bump, NOT prerelease suffixes.

---

# intx

[![readme style: standard][readme style standard badge]][standard readme]
[![Conan Center](https://img.shields.io/conan/v/intx)](https://conan.io/center/recipes/intx)
[![GitPOAP Badge](https://public-api.gitpoap.io/v1/repo/chfast/intx/badge)](https://www.gitpoap.io/gh/chfast/intx)

High‑performance multiprecision integer library for C++

The intx header-only C++20 library provides allocation-free extended precision
integer types. They are implemented as arrays of `std::uint64_t` words
and closely match the behavior of built-in types.

## Usage

To build, test or benchmark.

```bash
git clone https://github.com/chfast/intx
cd intx


sudo apt -q update

sudo apt install -qy libgmp-dev


cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel

build/test/intx-unittests
build/test/intx-bench
```

## Maintainer

Paweł Bylica [@chfast]

## License

Licensed under the [Apache License, Version 2.0].


[@chfast]: https://github.com/chfast
[Apache License, Version 2.0]: LICENSE
[standard readme]: https://github.com/RichardLitt/standard-readme

[readme style standard badge]: https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square

