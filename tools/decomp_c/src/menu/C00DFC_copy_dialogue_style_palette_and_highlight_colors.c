#include "som_c.h"

/* C00DFC copy_dialogue_style_palette_and_highlight_colors   [class B, 46 bytes, 24 instructions]
 * Source: src/rom/copy_dialogue_style_palette_and_highlight_colors.s
 * Documented in docs/event-dialogue-render-blend.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void copy_dialogue_style_palette_and_highlight_colors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    const uint16_t sp0 = r->sp;
    RAM8(sp0) = r->db; /* PHB: the copy below may overwrite it */
    uint8_t a1 = 6;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    for (;;) {
        uint8_t value;
        BUS8_OK(c, 0xD2DB80 + y1, value);
        BUS8_SET(c, 0x000602u + x1, value);
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    r->db = RAM8(sp0); /* PLB */
    uint16_t value2, value3;
    BUS16_OK(c, ((uint32_t)r->db << 16) + 0xA24Eu, value2);
    BUS16_OK(c, ((uint32_t)r->db << 16) + 0xA23Eu + ((value2 & 0xFF) << 1), value3);
    RAM16_SET(0x0604, value3);
    RAM16_SET(0x0614, value3);
    r->a = value3;
    r->x = (value2 & 0xFF) << 1;
    r->y = y1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00DFC, SOM_RTS, "hand", copy_dialogue_style_palette_and_highlight_colors, 0, L_B | L_X | L_Y | L_V, 2, 1, 0, 46, 24)
