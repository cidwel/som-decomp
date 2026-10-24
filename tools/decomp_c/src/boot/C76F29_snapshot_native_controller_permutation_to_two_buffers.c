#include "som_c.h"

/* C76F29 snapshot_native_controller_permutation_to_two_buffers   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/snapshot_native_controller_permutation_to_two_buffers.s
 * Documented in docs/ui-native-controller-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void snapshot_native_controller_permutation_to_two_buffers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 4;
    for (;;) {
        uint8_t value = RAM8(0x9BFF + x1);
        RAM8(0x9C03 + x1) = value;
        RAM8(0x9C07 + x1) = value;
        x1 = (uint16_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76F29, SOM_RTL, "gen", snapshot_native_controller_permutation_to_two_buffers, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 16, 7)
