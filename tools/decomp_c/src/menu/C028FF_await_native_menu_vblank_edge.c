#include "som_c.h"

/* C028FF await_native_menu_vblank_edge   [class D, 17 bytes, 7 instructions]
 * Source: src/rom/await_native_menu_vblank_edge.s
 * Documented in docs/event-menu-frames.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void await_native_menu_vblank_edge(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    for (;;) {
        uint8_t value = BUS8(c, 0x004212);
        if (!((value & 0x80) != 0)) break;
    }
    uint8_t a1 = 0;
    uint8_t a_hi2 = a_hi1;
    bool zero1 = 0;
    for (;;) {
        uint8_t value2 = BUS8(c, 0x004212);
        a1 = value2 & 0x80;
        zero1 = (value2 & 0x80) == 0;
        if (!(zero1)) break;
    }
    r->a = (a_hi2 << 8) | a1;
    r->x = x;
    r->y = y;
    r->c = carry;
    r->z = zero1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC028FF, SOM_RTS, "gen", await_native_menu_vblank_edge, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 17, 7)
