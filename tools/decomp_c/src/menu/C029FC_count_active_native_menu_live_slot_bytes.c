#include "som_c.h"

/* C029FC count_active_native_menu_live_slot_bytes   [class A, 24 bytes, 13 instructions]
 * Source: src/rom/count_active_native_menu_live_slot_bytes.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void count_active_native_menu_live_slot_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    bool carry1 = carry;
    for (;;) {
        uint8_t value = RAM8(0xCF90 + x1);
        uint16_t y2;
        if (value != 1) {
            y2 = y1;
        } else {
            y2 = (uint16_t)(y1 + 1);
        }
        uint16_t x1_next = (uint16_t)(x1 + 1);
        uint16_t y1_next = y2;
        bool carry1_next = (uint16_t)(x1 + 1) >= 8;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        if (!(x1 != 8)) break;
    }
    r->a = (a_hi1 << 8) | (uint8_t)y1;
    r->x = x;
    r->y = y1;
    r->c = carry1;
    r->v = overflow;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC029FC, SOM_RTL, "gen", count_active_native_menu_live_slot_bytes, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 24, 13)
