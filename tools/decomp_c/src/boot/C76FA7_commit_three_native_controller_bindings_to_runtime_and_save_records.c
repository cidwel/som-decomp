#include "som_c.h"

/* C76FA7 commit_three_native_controller_bindings_to_runtime_and_save_records   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/commit_three_native_controller_bindings_to_runtime_and_save_records.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYZV.
 */
static void commit_three_native_controller_bindings_to_runtime_and_save_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 3;
    bool zero1 = 0;
    for (;;) {
        uint8_t value = RAM8(0xA22E + x1);
        BUS8_SET(c, (uint16_t)(x1 + 0xED), value);
        RAM8(0xCC6C + x1) = value;
        uint16_t x1_next = (uint16_t)(x1 - 1);
        bool zero1_next = (uint16_t)(x1 - 1) == 0;
        x1 = x1_next;
        zero1 = zero1_next;
        if (!(x1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->y = y;
    r->z = zero1;
    r->v = overflow;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76FA7, SOM_RTL, "gen", commit_three_native_controller_bindings_to_runtime_and_save_records, 0, L_B | L_Y | L_Z | L_V, 1, 1, 0, 16, 7)
