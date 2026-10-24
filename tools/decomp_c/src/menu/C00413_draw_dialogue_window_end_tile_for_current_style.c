#include "som_c.h"
#include "som_hand_d.h"

/* C00413 draw_dialogue_window_end_tile_for_current_style   [class A, 34 bytes, 16 instructions]
 * Source: src/rom/draw_dialogue_window_end_tile_for_current_style.s
 * Documented in docs/event-dialogue-render-core.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void draw_dialogue_window_end_tile_for_current_style(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    i_rep(r, 0x20);
    a_lda(r, RAM16(0xA24E));
    a_and(r, 0x00FF);
    i_asla(r);
    i_asla(r);
    i_asla(r);
    r->c = 0;
    a_adc(r, 0x00F0);
    RAM16_SET(0xA1A0, r->a);
    i_sep(r, 0x20);
    a_lda(r, 0xFF);
    RAM8(0xA171) = r->a;
    a_lda(r, 0x01);
    RAM8(0xA164) = r->a;
    JSR(c, 0x0433, 0xC00478); /* draw_native_dialogue_window_rom_tile_sequence */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00413, SOM_RTS, "hand", draw_dialogue_window_end_tile_for_current_style, 0, L_B | L_Y | L_V, 1, 1, 0, 34, 16)
