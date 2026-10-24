#include "som_c.h"

/* C07922 clear_native_first_two_ring_rows_and_hide_hero_markers   [class A, 27 bytes, 12 instructions]
 * Source: src/rom/clear_native_first_two_ring_rows_and_hide_hero_markers.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void clear_native_first_two_ring_rows_and_hide_hero_markers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        BUS16_SET(c, 0x0018C0 + x1, 0);
        uint8_t a_hi1_next = (uint16_t)(x1 + 0x10) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 0x10);
        bool carry1_next = (uint16_t)(x1 + 0x10) >= 0x1C;
        bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!(x1 < 0x1C)) break;
    }
    r->x = x1;
    r->y = y;
    r->c = carry1;
    r->v = overflow1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x793B, 0xC0793D); GUARD_JSL(c, sp_call, 0x793B); } /* hide_shop_hero_markers_before_price_selection */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07922, SOM_RTS, "gen", clear_native_first_two_ring_rows_and_hide_hero_markers, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 27, 12)
