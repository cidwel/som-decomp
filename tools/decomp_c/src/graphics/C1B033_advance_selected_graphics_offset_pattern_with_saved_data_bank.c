#include "som_c.h"

/* C1B033 advance_selected_graphics_offset_pattern_with_saved_data_bank   [class A, 31 bytes, 20 instructions]
 * Source: src/rom/advance_selected_graphics_offset_pattern_with_saved_data_bank.s
 * Documented in docs/map-graphics-offset-sequencer.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_selected_graphics_offset_pattern_with_saved_data_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x0090);
    if (value & 0x40) {
        uint8_t value2 = RAM8(0x00F4);
        r->a = (a_hi << 8) | 0x7F;
        r->x = (uint8_t)((a_hi << 8) | ((value2 & 7) << 1 << 1 << 1));
        r->c = (value2 & 7) << 1 << 1 & 0x80;
        r->v = value & 0x40;
        r->db = 0x7F;
        r->sp -= 1;
        JSR(c, 0xB049, 0xC1B052); /* advance_native_graphics_offset_pattern_and_publish_source */
        r->sp += 1;
        RAM8(0x0090) = 0xC0;
        r->mf = 1;
        r->xf = 1;
        r->db = 0;
        RETURN_RTL(c);
    }
    r->v = value & 0x40;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1B033, SOM_RTL, "gen", advance_selected_graphics_offset_pattern_with_saved_data_bank, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 31, 20)
