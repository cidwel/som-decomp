#include "som_c.h"

/* C76FB7 restore_native_controller_bindings_and_copy_mirror_free_runtime_flags   [class A, 30 bytes, 14 instructions]
 * Source: src/rom/restore_native_controller_bindings_and_copy_mirror_free_runtime_flags.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void restore_native_controller_bindings_and_copy_mirror_free_runtime_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 3;
    for (;;) {
        BUS8_SET(c, (uint16_t)(x1 + 0xED), RAM8(0xA236 + x1));
        x1 = (uint16_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    uint8_t a1 = 0;
    uint8_t a_hi2 = a_hi1;
    uint16_t x2 = 3;
    bool zero1 = 0;
    for (;;) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(x2 + 0xED));
        RAM8(0xA22E + x2) = value2;
        RAM8(0xA236 + x2) = value2;
        BUS8_SET(c, (uint16_t)(x2 + 0xED), value2 & 3);
        uint8_t a1_next = value2 & 3;
        uint16_t x2_next = (uint16_t)(x2 - 1);
        bool zero1_next = (uint16_t)(x2 - 1) == 0;
        a1 = a1_next;
        x2 = x2_next;
        zero1 = zero1_next;
        if (!(x2 != 0)) break;
    }
    r->a = (a_hi2 << 8) | a1;
    r->x = x2;
    r->y = y;
    r->c = carry;
    r->z = zero1;
    r->v = overflow;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76FB7, SOM_RTL, "gen", restore_native_controller_bindings_and_copy_mirror_free_runtime_flags, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 30, 14)
