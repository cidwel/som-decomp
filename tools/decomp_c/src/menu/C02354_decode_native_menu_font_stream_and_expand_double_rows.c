#include "som_c.h"

/* C02354 decode_native_menu_font_stream_and_expand_double_rows   [class B, 18 bytes, 7 instructions]
 * Source: src/rom/decode_native_menu_font_stream_and_expand_double_rows.s
 * Documented in docs/event-menu-font-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void decode_native_menu_font_stream_and_expand_double_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA16A) = 0x20;
    r->a = (a_hi << 8) | 0x20;
    JSR(c, 0x235B, 0xC016B8); /* decode_dialogue_font_stream_and_all_insertion_commands */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x235E, 0xC01664); /* load_dialogue_glyph_rows_or_advance_empty_line */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x2361, 0xC01663); /* dialogue_glyph_phase_no_operation */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x2364, 0xC02366); /* assemble_thirty_two_native_menu_text_rows */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02354, SOM_RTS, "gen", decode_native_menu_font_stream_and_expand_double_rows, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 18, 7)
