#include "som_c.h"

/* C645A9 await_next_scene_vblank_through_long_port_read   [class D, 17 bytes, 7 instructions]
 * Source: src/rom/await_next_scene_vblank_through_long_port_read.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=8 bit X=16 bit DB=$C6 D=$0000.  Callers read: BCV.
 */
static void await_next_scene_vblank_through_long_port_read(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0xC6, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    for (;;) {
        uint8_t value = BUS8(c, 0x004212);
        if (!((value & 0x80) != 0)) break;
    }
    uint8_t a_hi2 = a_hi1;
    for (;;) {
        uint8_t value2 = BUS8(c, 0x004212);
        if (!((value2 & 0x80) == 0)) break;
    }
    r->a = (a_hi2 << 8) | a;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC645A9, SOM_RTS, "gen", await_next_scene_vblank_through_long_port_read, 0, L_B | L_C | L_V, 1, 1, 0, 17, 7)
