#include "som_c.h"

/* C0151A compose_first_dialogue_tile_bitplane_rows   [class A, 31 bytes, 17 instructions]
 * Source: src/rom/compose_first_dialogue_tile_bitplane_rows.s
 * Documented in docs/event-dialogue-render-blend.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void compose_first_dialogue_tile_bitplane_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t a1 = 0x0E;
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = 0;
    for (;;) {
        r->y = y1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        r->sp -= 1;
        JSR(c, 0x1529, 0xC01539); /* compose_dialogue_tile_mask_pair_rows */
        r->sp += 1;
        uint16_t y_ret = r->y;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = (uint16_t)(y_ret + 0x10) >> 8;
        y1 = (uint16_t)(y_ret + 0x10);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0151A, SOM_RTS, "gen", compose_first_dialogue_tile_bitplane_rows, 0, L_B, 1, 1, 0, 31, 17)
