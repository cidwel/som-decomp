#include "som_c.h"

/* 7EB0D6 release_native_heap_suffix_through_bank_7f_api   [class A, 18 bytes, 13 instructions]
 * Source: src/boot/release_native_heap_suffix_through_bank_7f_api.s
 * Documented in docs/boot-native-heap-release-wrappers.md
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: BXYCZNV.
 */
static void release_native_heap_suffix_through_bank_7f_api(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 4;
    JSR(c, 0xB0E3, 0x7EB00F); /* release_128_byte_unit_suffix */
    r->sp += 4;
    r->c = carry;
    r->z = dp == 0;
    r->n = dp & 0x8000;
    r->v = overflow;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB0D6, SOM_RTS, "gen", release_native_heap_suffix_through_bank_7f_api, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 18, 13)
