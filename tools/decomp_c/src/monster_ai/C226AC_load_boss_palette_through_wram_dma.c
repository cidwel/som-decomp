#include "som_c.h"

/* C226AC load_boss_palette_through_wram_dma   [class D, 77 bytes, 33 instructions]
 * Source: src/rom/load_boss_palette_through_wram_dma.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYV.
 */
static void load_boss_palette_through_wram_dma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM8(0x033F + x) = (uint8_t)a;
    BUS16_SET(c, 0x002181, ((((x & 0x0F) << 8) | 0) >> 3) + 0x0600);
    uint16_t value = BUS16(c, 0xD0BB24 + (uint16_t)(a << 1));
    BUS16_SET(c, 0x004372, value);
    BUS16_SET(c, 0x004375, 0x20);
    BUS8_SET(c, 0x002183, 0);
    BUS8_SET(c, 0x004370, 0);
    BUS8_SET(c, 0x004371, 0x80);
    BUS8_SET(c, 0x004374, 0xC2);
    BUS8_SET(c, 0x00420B, 0x80);
    r->a = 0x80;
    r->y = a;
    r->v = ((((((x & 0x0F) << 8) | 0) >> 3) ^ ((((x & 0x0F) << 8) | 0) >> 3) + 0x0600) & (((((x & 0x0F) << 8) | 0) >> 3) + 0x0600 ^ 0x0600) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC226AC, SOM_RTS, "gen", load_boss_palette_through_wram_dma, 0, L_B | L_Y | L_V, 1, 0, 0, 77, 33)
