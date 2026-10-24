#include "som_c.h"

/* C76986 append_native_party_status_count_glyph_and_newline   [class A, 17 bytes, 9 instructions]
 * Source: src/rom/append_native_party_status_count_glyph_and_newline.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_party_status_count_glyph_and_newline(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    RAM8(0x9C01 + x) = (uint8_t)(a + 0xB5);
    RAM8(0x9C00 + x) = 0x80;
    r->a = (a_hi << 8) | 0x80;
    r->x = (uint16_t)(x + 2);
    r->c = a + 0xB5 > 0xFF;
    r->v = ((a ^ (uint8_t)(a + 0xB5)) & ((uint8_t)(a + 0xB5) ^ 0xB5) & 0x80) != 0;
    JSR(c, 0x6995, 0xC7538D); /* append_native_saved_slot_text_line_token */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76986, SOM_RTS, "gen", append_native_party_status_count_glyph_and_newline, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 17, 9)
