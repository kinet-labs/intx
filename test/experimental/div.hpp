
#pragma once
#include <intx/intx.hpp>

namespace intx
{
inline uint64_t reciprocal_native(uint64_t d) noexcept
{
#ifdef __x86_64__
    uint64_t _;    // NOLINT(*-init-variables)
    uint64_t v;    // NOLINT(*-init-variables)
    asm("divq %4"  // NOLINT(*-no-assembler)
        : "=d"(_), "=a"(v)
        : "d"(~d), "a"(~uint64_t{0}), "r"(d));
    return v;
#else
    // Fallback implementation.
    return (uint128{~uint64_t{0}, ~d} / d)[0];
#endif
}

inline uint64_t reciprocal_builtin_uint128(uint64_t d) noexcept
{
#if INTX_HAS_BUILTIN_INT128
    const auto u = (builtin_uint128{~d} << 64) | ~uint64_t{0};
    return static_cast<uint64_t>(u / d);
#else
    // Fallback implementation.
    return (uint128{~uint64_t{0}, ~d} / d)[0];
#endif
}

/// The copy of the GMP algorithm from "Improved division by invariant integers".
constexpr uint64_t reciprocal_gmp(uint64_t d) noexcept
{
    INTX_REQUIRE(d & 0x8000000000000000);  // Must be normalized.

    const uint64_t d9 = d >> 55;
    const uint32_t v0 = internal::reciprocal_table[static_cast<size_t>(d9 - 256)];

    const uint64_t d40 = (d >> 24) + 1;
    const uint64_t v1 = (v0 << 11) - uint32_t(uint32_t{v0 * v0} * d40 >> 40) - 1;

    const uint64_t v2 = (v1 << 13) + (v1 * (0x1000000000000000 - v1 * d40) >> 47);

    const uint64_t d0 = d & 1;
    const uint64_t d63 = (d >> 1) + d0;  // ceil(d/2)
    const uint64_t e = ((v2 >> 1) & (0 - d0)) - (v2 * d63);
    const uint64_t v3 = (umul(v2, e)[1] >> 1) + (v2 << 31);

    const uint64_t v4 = v3 - (umul(v3, d) + d)[1] - d;
    return v4;
}
}  // namespace intx
