#include "som_c.h"
#include "som_hand_d.h"

/* C0044C draw_dialogue_window_fill_tile_pairs   [class B, 44 bytes, 21 instructions]
 * Source: src/rom/draw_dialogue_window_fill_tile_pairs.s
 * Documented in docs/event-dialogue-render-core.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void draw_dialogue_window_fill_tile_pairs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    for (;;) {
        i_rep(r, 0x20);
        a_lda(r, 0x0400);
        r->c = 0;
        a_adc(r, RAM16(0xA178));
        i_tax(r);
        i_sep(r, 0x20);
        JSR(c, 0x045A, 0xC004D0); /* dispatch_dialogue_window_tile_orientation */
        if (!r->mf) { c->fail = 3; return; } /* the immediate that follows is assembled for 8-bit A */
        a_lda(r, 0x00);
        i_xba(r);
        RAM8(0xA164)--;
        hand_nz8(r, RAM8(0xA164));
        if (r->z) break;
        i_rep(r, 0x20);
        a_lda(r, 0x0400);
        r->c = 0;
        a_adc(r, RAM16(0xA178));
        i_tax(r);
        i_sep(r, 0x20);
        JSR(c, 0x0471, 0xC004D0); /* dispatch_dialogue_window_tile_orientation */
        RAM8(0xA164)--;
        hand_nz8(r, RAM8(0xA164));
        if (r->z) break;
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0044C, SOM_RTS, "hand", draw_dialogue_window_fill_tile_pairs, 0, L_B | L_Y | L_V, 1, 1, 0, 44, 21)
