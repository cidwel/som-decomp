#include "som_c.h"

/* C20E6A reload_boss_graphics_cache_markers_through_wram_port   [class D, 49 bytes, 21 instructions]
 * Source: src/rom/reload_boss_graphics_cache_markers_through_wram_port.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: YV.
 */
static void reload_boss_graphics_cache_markers_through_wram_port(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const bool overflow = r->v;
    RAM8(0x0278) = 0xC1;
    BUS8_SET(c, 0x002183, 0);
    BUS16_SET(c, 0x002181, 0x0F55);
    uint16_t value = RAM16(0x02CB);
    RAM16_SET(0x0276, value);
    uint8_t a_hi1 = value >> 8;
    uint8_t y1 = 0;
    for (;;) {
        uint8_t value2 = BUS8(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + y1);
        BUS8_SET(c, 0x002180, value2);
        y1 = (uint8_t)(y1 + 1);
        if (!(y1 != 0x4D)) break;
    }
    RAM8(0x0FA8) = 0;
    RAM8(0x0FAA) = 0x30;
    r->y = y1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20E6A, SOM_RTS, "gen", reload_boss_graphics_cache_markers_through_wram_port, 0, L_Y | L_V, 1, 1, 0, 49, 21)
